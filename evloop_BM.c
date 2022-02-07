// file evloop_BM.c     - event loop of BISMON
// SPDX-License-Identifier: GPL-3.0-or-later
/***
    BISMON 
    Copyright © 2018 - 2022 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
    contributed by Basile Starynkevitch (working at CEA, LIST, France)
    <basile@starynkevitch.net> or <basile.starynkevitch@cea.fr>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
***/
#define _GNU_SOURCE 1
#include <stdio.h>
#include <stdarg.h>
#include <syslog.h>
#include <sys/socket.h>
#include <sys/un.h>

#include "bismon.h"
#include "evloop_BM.const.h"

//////////////////////////////////////////////////////////////////////////
/// An array describing the currently running child processes (e.g. GCC
/// compilations, printing processes, etc...).  Stuff is removed from
/// that array only by plain_event_loop_BM which would also apply the
/// closures.  Related to the queue of pending commands,
/// pendingrunproc_list_BM and to our queue_process_BM function.
struct processdescr_stBM running_process_descr_arr_BM[MAXNBWORKJOBS_BM + 1];

/// queued process commands, of nodes (dir, cmd, clos); for processes
/// which are not yet in the array above... so they are not yet running.
struct listtop_stBM *pendingrunproc_list_BM;

// lock for the structures above (both running_process_descr_arr_BM & pendingrunproc_list_BM)
pthread_mutex_t pendingrunproc_mtx_BM = PTHREAD_MUTEX_INITIALIZER;

volatile atomic_bool eventlooprunning_BM;

static volatile atomic_int count_dump_sigusr1_BM;

pthread_mutex_t onionstack_mtx_BM = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t onionstack_condchange_BM = PTHREAD_COND_INITIALIZER;

struct onionstackinfo_stBM onionstackinfo_BM[MAXNBWORKJOBS_BM + 1];
thread_local struct onionstackinfo_stBM *curonionstackinfo_BM;



/// a mutex protecting the JSONRPC services...
pthread_mutex_t unix_json_mtx_BM = PTHREAD_MUTEX_INITIALIZER;
int master_unix_json_socket_fd_BM = -1;
volatile atomic_int nb_slave_json_sockets_BM;   /// actual number of slave JSON sockets
/// each active socket has an object of payload
/// jsonrpcservicedata_stBM.
objectval_tyBM *unix_json_procobarr[MAXNBWORKJOBS_BM + 2];

void handle_master_unix_json_connection_BM (struct stackframe_stBM *);

// the lock above should be set when calling:
void
fork_process_at_slot_BM (int slotpos,
                         const stringval_tyBM * dirstrarg,
                         const node_tyBM * cmdnodarg,
                         const closure_tyBM * endclosarg,
                         struct stackframe_stBM *stkf);
void lock_runproc_mtx_at_BM (int lineno);
void unlock_runproc_mtx_at_BM (int lineno);

void plain_event_loop_BM (void);

// Handle signals thu signalfd(2); return true to break
// plain_event_loop_BM and stop the loop there. To continue the
// event loop, it should return false.
bool read_sigfd_BM (void);
// handle SIGCHLD
void handle_sigchld_BM (pid_t pid);
// handle the command pipe
void read_commandpipe_BM (void);

// the command pipe contains bytes, each considered as a different message
int cmdpipe_rd_BM = -1, cmdpipe_wr_BM = -1;

#define MAXTIMER_SECONDS_BM 0.5
enum cmd_charcode_enBM
{
  cmdcod__none_bm = 0,
  cmdcod_execdefer_bm = 'X',
  cmdcod_rungc_bm = 'G',
  cmdcod_postponetimer_bm = 'T',
};


void
create_commandpipe_BM (void)
{
  int piparr[2] = { -1, -1 };
  if (pipe2 (piparr, O_CLOEXEC | O_NONBLOCK))
    FATAL_BM ("create_commandpipe_BM failure for the command pipe - %m");
  cmdpipe_rd_BM = piparr[0];
  cmdpipe_wr_BM = piparr[1];
  DBGPRINTF_BM
    ("create_commandpipe_BM before onion_listen cmdpiprd#%d cmdpipwr#%d",
     cmdpipe_rd_BM, cmdpipe_wr_BM);
}                               /* end create_commandpipe_BM */

void
read_commandpipe_BM (void)
{
#define NANOSECONDS_PER_SECOND_bm   (1000*1000*1000)
  extern bool did_deferred_BM (void);
  char buf[4];
  memset (&buf, 0, sizeof (buf));
  int nbr = read (cmdpipe_rd_BM, buf, 1);
  if (nbr == 1)
    {
      DBGPRINTF_BM ("read_commandpipe_BM '%s'", buf);
      switch (buf[0])
        {
          // if buf[0] is 'X', execute a deferred command
        case cmdcod_execdefer_bm:      // 'X'
          if (!did_deferred_BM ())
            WARNPRINTF_BM ("read_commandpipe_BM failed to do deferred");
          return;
        case cmdcod_rungc_bm:  // 'G'
          // if buf[0] is 'G', run the garbage collector. Not sure!
          garbage_collect_if_wanted_BM (NULL);
          return;
        case cmdcod_postponetimer_bm:  // 'T'
          // if buf[0] is 'T', something changed about postponed timers
          {
            struct itimerspec its;
            memset (&its, 0, sizeof (its));
            if (UNLIKELY_BM (oniontimerfd_BM < 0))
              {
                oniontimerfd_BM =
                  timerfd_create (CLOCK_MONOTONIC, TFD_CLOEXEC);
                if (oniontimerfd_BM < 0)
                  FATAL_BM
                    ("read_commandpipe_BM fail on timerfd_create - %m");
                DBGPRINTF_BM ("read_commandpipe_BM oniontimerfd_BM=%d",
                              oniontimerfd_BM);
              }
            double timestamp = timestamp_newest_postpone_BM ();
            double deltatime = timestamp - elapsedtime_BM ();
            if (deltatime > MAXTIMER_SECONDS_BM)
              deltatime = MAXTIMER_SECONDS_BM;
            DBGPRINTF_BM ("read_commandpipe_BM deltatime=%.5f", deltatime);
            if (deltatime > 0.0)
              {
                clock_gettime (CLOCK_MONOTONIC, &its.it_value);
                its.it_value.tv_sec += (long) (floor (deltatime));
                its.it_value.tv_nsec += (long) (deltatime * 1.0e9);
                while (its.it_value.tv_nsec > NANOSECONDS_PER_SECOND_bm)
                  {
                    its.it_value.tv_sec++;
                    its.it_value.tv_nsec -= NANOSECONDS_PER_SECOND_bm;
                  }
                if (timerfd_settime
                    (oniontimerfd_BM, TFD_TIMER_ABSTIME, &its, NULL))
                  FATAL_BM
                    ("read_commandpipe_BM timerfd_settime failure deltatime=%.4f / %m",
                     deltatime);
              }
          }
          break;
        default:
          /// this should not happen....
          WARNPRINTF_BM ("read_commandpipe_BM  '%s' unknown", buf);
          backtrace_print_BM ((struct backtrace_state *)
                              backtracestate_BM, 0, stdout);
          printf ("%s:%d: unexpected command %s\n", __FILE__, __LINE__, buf);
          fflush (stdout);
        }
      // should handle the command
    }
  else
    DBGPRINTF_BM ("read_commandpipe_BM nbr %d - %s", nbr,
                  (nbr < 0) ? strerror (errno) : "--");
}                               /* end read_commandpipe_BM */




/// this function should return true to continue the loop in plain_event_loop_BM
bool
read_sigfd_BM (void)            // called from plain_event_loop_BM
{
  struct signalfd_siginfo siginf;
  memset (&siginf, 0, sizeof (siginf));
  time_t nowt = 0;
  time (&nowt);
  char nowbuf[48];
  memset (nowbuf, 0, sizeof (nowbuf));
  const char *nowstr = ctime_r (&nowt, nowbuf);
  if (!nowstr)
    nowstr = "????";
  DBGPRINTF_BM ("read_sigfd_BM start sigfd_BM %d elapsed %3.f s at %s",
                sigfd_BM, elapsedtime_BM (), nowstr);
  int nbr = read (sigfd_BM, &siginf, sizeof (siginf));
  if (nbr != sizeof (siginf))   // very unlikely, probably impossible
    FATAL_BM ("read_sigfd_BM: read fail (%d bytes read, want %d) - %m",
              nbr, (int) sizeof (siginf));
  DBGPRINTF_BM ("read_sigfd_BM signo=%d at %s", siginf.ssi_signo, nowstr);
  // TODO: is this read_sigfd_BM incomplete?
  switch (siginf.ssi_signo)
    {
    case SIGUSR1:
      {
        if (!sigusr1_dump_prefix_BM)
          {
            WARNPRINTF_BM
              ("got SIGUSR1 at %s but without any --sigusr1-dump-prefix option",
               nowstr);
            goto terminating_dump;
          };
        ASSERT_BM (sigusr1_dump_prefix_BM != (const char *) 0);
        int dumpcnt = 1 + atomic_fetch_add (&count_dump_sigusr1_BM, 1);
        DBGPRINTF_BM ("read_sigfd_BM got SIGUSR1 at %s for dumping count %d",
                      nowstr, dumpcnt);
        char dirbufname[MAXLEN_SIGUSR1_DUMP_PREFIX_BM + 8];
        memset (dirbufname, 0, sizeof (dirbufname));
        snprintf (dirbufname, sizeof (dirbufname), "%s%03d",
                  sigusr1_dump_prefix_BM, dumpcnt);
        ASSERT_BM (strlen (dirbufname) < sizeof (dirbufname) - 2);
        if (mkdir (dirbufname, S_IRWXU /* u+rwx */ ))
          FATAL_BM ("failed to mkdir %s for SIGUSR1 dump - %m", dirbufname);
        agenda_suspend_for_gc_BM ();
        struct dumpinfo_stBM di = dump_BM (dirbufname, NULL);
        {
          char infopath[MAXLEN_SIGUSR1_DUMP_PREFIX_BM + 32];
          memset (infopath, 0, sizeof (infopath));
          snprintf (infopath, sizeof (infopath), "%s/BismonInfo", dirbufname);
          FILE *infofil = fopen (infopath, "w");
          if (infofil)
            {
              fprintf (infofil,
                       "# emitted %s Bismon intermediate dump file\n",
                       infopath);
              fprintf (infofil, "BISMON_PID=%d\n", (int) getpid ());
              fprintf (infofil, "BISMON_DIRDUMP='%s'\n", dirbufname);
              fprintf (infofil, "BISMON_DUMPCOUNT=%d\n", dumpcnt);
              fprintf (infofil, "BISMON_HOST='%s'\n", myhostname_BM);
              fprintf (infofil, "BISMON_CHECKSUM='%s'\n", bismon_checksum);
              fprintf (infofil, "BISMON_SHORTGITID='%s'\n",
                       bismon_shortgitid);
              fprintf (infofil, "BISMON_TIMESTAMP='%s'\n", bismon_timestamp);
              fprintf (infofil, "BISMON_TIMELONG=%ld\n", bismon_timelong);
              fprintf (infofil, "BISMON_DIRECTORY='%s'\n", bismon_directory);
              fclose (infofil);
            }
        }
        INFOPRINTF_BM
          ("after dumping intermediate state into %s for SIGUSR1: scanned %ld, emitted %ld objects\n"
           "did %ld todos, wrote %ld files\n"
           "in %.3f elapsed, %.4f cpu seconds.\n", dirbufname,
           di.dumpinfo_scanedobjectcount, di.dumpinfo_emittedobjectcount,
           di.dumpinfo_todocount, di.dumpinfo_wrotefilecount,
           di.dumpinfo_elapsedtime, di.dumpinfo_cputime);
        backtrace_print_BM ((struct backtrace_state *)
                            backtracestate_BM, 0, stdout);
        agenda_continue_after_gc_BM ();
      };
      return false;
    case SIGUSR2:              /* toggle debug */
      if (showdebugmsg_BM)
        {
          DBGPRINTF_BM
            ("debugging output suspended by SIGUSR2 at %s; send again the same signal to reenable it",
             nowstr);
          showdebugmsg_BM = false;
          INFOPRINTF_BM
            ("no more debugging output at %s (bismon pid %d on %s) since SIGUSR2 signal recieved",
             nowstr, (int) getpid (), myhostname_BM);
        }
      else
        {
          INFOPRINTF_BM
            ("enabling debugging output at %s (bismon pid %d on %s) since SIGUSR2 signal recieved",
             nowstr, (int) getpid (), myhostname_BM);
          showdebugmsg_BM = true;
          DBGPRINTF_BM
            ("debugging output enabled by SIGUSR2 at %s (bismon pid %d on %s); send again the same signal to disable it",
             nowstr, (int) getpid (), myhostname_BM);
        }
      return true;
    case SIGTERM:
    case SIGINT:
    terminating_dump:
      {
        DBGPRINTF_BM ("read_sigfd_BM got %s at %s",
                      strsignal (siginf.ssi_signo), nowstr);
        stop_agenda_work_threads_BM ();
        /// forcibly remove the payload of the_web_sessions. Its payload
        /// should not be dumped, because of its class, but anyway...
        {
          objlock_BM (BMP_the_web_sessions);
          objclearpayload_BM (BMP_the_web_sessions);
          objunlock_BM (BMP_the_web_sessions);
        }
        char *rp = realpath (dump_dir_BM ? : ".", NULL);
        INFOPRINTF_BM
          ("before dumping final state into %s (really %s) after signal %s to process %d, elapsed %.3f s",
           dump_dir_BM, rp,
           strsignal (siginf.ssi_signo), (int) getpid (), elapsedtime_BM ());
        free (rp), rp = NULL;
        backtrace_print_BM ((struct backtrace_state *)
                            backtracestate_BM, 0, stdout);
        struct dumpinfo_stBM di = dump_BM (dump_dir_BM, NULL);
        INFOPRINTF_BM
          ("after dumping final state into %s for SIGTERM: scanned %ld, emitted %ld objects\n"
           "did %ld todos, wrote %ld files\n"
           "in %.3f elapsed, %.4f cpu seconds.\n", dump_dir_BM,
           di.dumpinfo_scanedobjectcount, di.dumpinfo_emittedobjectcount,
           di.dumpinfo_todocount, di.dumpinfo_wrotefilecount,
           di.dumpinfo_elapsedtime, di.dumpinfo_cputime);
      }
      return true;
    case SIGQUIT:
      INFOPRINTF_BM
        ("terminating without dump after SIGQUIT to process %d, elapsed %.3f s",
         (int) getpid (), elapsedtime_BM ());
      return true;
    case SIGCHLD:
      {
        pid_t pid = siginf.ssi_pid;
        if (showdebugmsg_BM)
          {
            char exebuf[64];
            char pathbuf[64];
            memset (exebuf, 0, sizeof (exebuf));
            memset (pathbuf, 0, sizeof (pathbuf));
            snprintf (pathbuf, sizeof (pathbuf), "/proc/%d/exe", pid);
            if (readlink (pathbuf, exebuf, sizeof (exebuf) - 1) < 0)
              FATAL_BM ("readlink %s failed (%m)", pathbuf);
            DBGPRINTF_BM ("read_sigfd_BM got SIGCHLD pid=%d (%s)", (int) pid,
                          exebuf);
          }
        handle_sigchld_BM (pid);
        return false;
      }
    default:
      FATAL_BM ("read_sigfd_BM unexpected signo %d", siginf.ssi_signo);
    };
  DBGPRINTF_BM ("read_sigfd_BM ending");
  return false;
}                               /* end read_sigfd_BM */


void
handle_sigchld_BM (pid_t pid)
{
  objectval_tyBM *k_queue_process = BMK_8DQ4VQ1FTfe_5oijDYr52Pb;
  bool didfork = false;
  LOCALFRAME_BM ( /*prev: */ NULL, /*descr: */ NULL,
                 /// for the terminating child process
                 value_tyBM chdirstrv;  //
                 value_tyBM chcmdnodv;  //
                 value_tyBM chclosv;    //
                 objectval_tyBM * chbufob;      //
                 value_tyBM choutstrv;  //
                 // for queued commands
                 value_tyBM qnodv;      //
                 value_tyBM newdirstrv; //
                 value_tyBM newcmdnodv; //
                 value_tyBM newendclosv;        //
    );
  DBGPRINTF_BM ("handle_sigchld_BM start pid=%d", (int) pid);
  int wstatus = 0;
  pid_t wpid = waitpid (pid, &wstatus, WNOHANG);
  if (wpid == pid)
    {
      DBGPRINTF_BM ("handle_sigchld_BM pid %d", (int) pid);
      {
        int chix = -1;
        int nbruncmds = 0;
        lock_runproc_mtx_at_BM (__LINE__);
        for (int oix = 0; oix < MAXNBWORKJOBS_BM; oix++)
          {
            struct processdescr_stBM *runproc =
              running_process_descr_arr_BM + oix;
            if (!runproc->rp_pid)
              continue;
            nbruncmds++;
            if (runproc->rp_pid == pid)
              {
                ASSERT_BM (chix < 0);
                chix = oix;
                _.chdirstrv = (value_tyBM) runproc->rp_dirstrv;
                _.chcmdnodv = (value_tyBM) runproc->rp_cmdnodv;
                _.chclosv = (value_tyBM) runproc->rp_closv;
                _.chbufob = (value_tyBM) runproc->rp_bufob;
                memset ((void *) runproc, 0,
                        sizeof (struct processdescr_stBM));
              }
          }
        _.qnodv =
          (value_tyBM) nodecast_BM (listfirst_BM (pendingrunproc_list_BM));
        if (_.qnodv)
          {
            ASSERT_BM (nodeconn_BM (_.qnodv) == k_queue_process);
            if (nbruncmds <= nbworkjobs_BM)
              {
                listpopfirst_BM (pendingrunproc_list_BM);
                _.newdirstrv = (value_tyBM)
                  stringcast_BM ((value_tyBM) nodenthson_BM (_.qnodv, 0));
                _.newcmdnodv = (value_tyBM)
                  nodecast_BM ((value_tyBM) nodenthson_BM (_.qnodv, 1));
                _.newendclosv = (value_tyBM)
                  nodecast_BM ((value_tyBM) nodenthson_BM (_.qnodv, 2));
                ASSERT_BM (isnode_BM (_.newcmdnodv));
                ASSERT_BM (isclosure_BM (_.newendclosv));
                DBGPRINTF_BM
                  ("handle_sigchld_BM chix#%d newdirstrv %s newcmdnodv %s newendclosv %s beforefork",
                   chix, debug_outstr_value_BM (_.newdirstrv, CURFRAME_BM,
                                                0),
                   debug_outstr_value_BM (_.newcmdnodv, CURFRAME_BM, 0),
                   debug_outstr_value_BM (_.newendclosv, CURFRAME_BM, 0));
                fork_process_at_slot_BM (chix, _.newdirstrv,
                                         _.newcmdnodv, _.newendclosv,
                                         CURFRAME_BM);
                didfork = true;
              }
          }
        unlock_runproc_mtx_at_BM (__LINE__);
        if (chix >= 0)
          {
            _.choutstrv =
              (value_tyBM)
              makestring_BM (objstrbufferbytespayl_BM (_.chbufob));
            DBGPRINTF_BM
              ("handle_sigchld_BM defer-apply chclosv %s choutstrv %s wstatus %#x=%d",
               debug_outstr_value_BM (_.chclosv, CURFRAME_BM, 0),
               debug_outstr_value_BM (_.choutstrv, CURFRAME_BM, 0), wstatus,
               wstatus);
            do_main_defer_apply3_BM (_.chclosv, _.choutstrv,
                                     taggedint_BM (wstatus), NULL,
                                     CURFRAME_BM);
          }
      }
    }
  else
    {
      DBGPRINTF_BM ("handle_sigchld_BM pid%d wpid%d", (int) pid, (int) wpid);
      char pidbuf[128];
      memset (pidbuf, 0, sizeof (pidbuf));
      snprintf (pidbuf, sizeof (pidbuf), "/proc/%d/cmdline", (int) pid);
      FILE *pf = fopen (pidbuf, "r");
      if (pf)
        {
          size_t ln = fread (pidbuf, sizeof (pidbuf) - 1, 1, pf);
          if (ln > 0)
            {
              pidbuf[ln] = (char) 0;
              for (int ix = 0; ix < (int) ln; ix++)
                if (pidbuf[ix] == 0)
                  pidbuf[ix] = ' ';
            }
          else
            strcpy (pidbuf, "??");
          fclose (pf);
        }
      else
        {
          char exepidbuf[64];
          memset (pidbuf, 0, sizeof (pidbuf));
          memset (exepidbuf, 0, sizeof (exepidbuf));
          snprintf (exepidbuf, sizeof (exepidbuf), "/proc/%u/exe",
                    (unsigned) pid);
          if (readlink (exepidbuf, pidbuf, sizeof (pidbuf) - 1) < 0)
            FATAL_BM ("readlink %s failed (%m)", exepidbuf);
        }
      WARNPRINTF_BM
        ("handle_sigchld_BM waitpid failure pid#%d '%s' status#%d", pid,
         pidbuf, wstatus);
      WEAKASSERTWARN_BM ("handle_sigchld_BM failed" && false);
    }
  if (didfork)
    usleep (1000);              // sleep a little bit, to let the child process start
}                               /* end handle_sigchld_BM */



void
lock_runproc_mtx_at_BM (int lineno __attribute__((unused)))
{
#if 0
  // too verbose, so not needed
  DBGPRINTFAT_BM (__FILE__, lineno, "lock_runproc_mtx_BM thrid=%ld",
                  (long) gettid_BM ());
#endif
  pthread_mutex_lock (&pendingrunproc_mtx_BM);
}                               /* end lock_runproc_mtx_at_BM */


void
unlock_runproc_mtx_at_BM (int lineno __attribute__((unused)))
{
#if 0
  // too verbose, so not needed
  DBGPRINTFAT_BM (__FILE__, lineno, "unlock_runproc_mtx_BM thrid=%ld",
                  (long) gettid_BM ());
#endif
  pthread_mutex_unlock (&pendingrunproc_mtx_BM);
}                               /* end unlock_runproc_mtx_at_BM */





void
add_defer_command_BM (void)
{
  char buf[4];
  memset (&buf, 0, sizeof (buf));
  buf[0] = cmdcod_execdefer_bm /* 'X' */ ;
  int count = 0;
  while (count < 256)
    {                           /* this loop usually runs once */
      int nbw = write (cmdpipe_wr_BM, buf, 1);
      if (nbw < 0 && errno == EINTR)
        continue;
      if (nbw < 0 && errno == EWOULDBLOCK)
        {
          usleep (2000);
          continue;
        };
      if (nbw == 1)
        return;
      FATAL_BM ("add_defer_command_BM nbw %d - %s", nbw,
                (nbw < 0) ? strerror (errno) : "--");
    }
  FATAL_BM ("add_defer_command_BM failed");
}                               /* end add_defer_command_BM */


void
add_rungarbcoll_command_BM (void)
{
  char buf[4];
  memset (&buf, 0, sizeof (buf));
  DBGBACKTRACEPRINTF_BM ("add_rungarbcoll_command_BM");
  buf[0] = cmdcod_rungc_bm;     /* 'G' */
  int count = 0;
  while (count < 256)
    {                           /* this loop usually runs once */
      int nbw = write (cmdpipe_wr_BM, buf, 1);
      if (nbw < 0 && errno == EINTR)
        continue;
      if (nbw < 0 && errno == EWOULDBLOCK)
        {
          usleep (2000);
          continue;
        };
      if (nbw == 1)
        return;
      FATAL_BM ("add_rungarbcoll_command_BM nbw %d - %s", nbw,
                (nbw < 0) ? strerror (errno) : "--");
    }
  FATAL_BM ("add_rungarbcoll_command_BM failed");
}                               /* end add_rungarbcoll_command_BM */


void
add_postponetimer_command_onion_BM (void)
{
  char buf[4];
  memset (&buf, 0, sizeof (buf));
  DBGBACKTRACEPRINTF_BM ("add_postponetimer_command_onion_BM");
  buf[0] = cmdcod_postponetimer_bm;     /* 'T' */
  int count = 0;
  while (count < 256)
    {                           /* this loop usually runs once */
      int nbw = write (cmdpipe_wr_BM, buf, 1);
      if (nbw < 0 && errno == EINTR)
        continue;
      if (nbw < 0 && errno == EWOULDBLOCK)
        {
          usleep (2000);
          continue;
        };
      if (nbw == 1)
        return;
      FATAL_BM ("add_postponetimer_command_onion_BM nbw %d - %s", nbw,
                (nbw < 0) ? strerror (errno) : "--");
    }
  FATAL_BM ("add_postponetimer_command_onion_BM failed");
}                               /* end add_postponetimer_command_onion_BM */




// queue some external process; its stdin is /dev/null; both stdout &
// stderr are merged & captured; final string is given to the closure.
// dirstrv is the string of the directory to run it in (if NULL, use
// cwd) cmdnodv is a node with all sons being strings, for the command
// to run endclosv is the closure getting the status
// stringoutput, could fail
void
queue_process_BM (const stringval_tyBM * dirstrarg,
                  const node_tyBM * cmdnodarg,
                  const closure_tyBM * endclosarg,
                  struct stackframe_stBM *stkf)
{
  objectval_tyBM *k_queue_process = BMK_8DQ4VQ1FTfe_5oijDYr52Pb;
  //objectval_tyBM *k_sbuf_object = BMK_77xbaw1emfK_1nhE4tp0bF3;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ k_queue_process, //
                 const stringval_tyBM * dirstrv;        //
                 const node_tyBM * cmdnodv;     //
                 const closure_tyBM * endclosv; //
                 value_tyBM curargv;    //
                 value_tyBM errorv;     //
                 value_tyBM causev;     //
                 objectval_tyBM * bufob;        //
                 value_tyBM nodv;       //
    );
  _.dirstrv = dirstrarg;
  _.cmdnodv = cmdnodarg;
  _.endclosv = endclosarg;
  bool lockedproc = false;
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ;  _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  if (_.dirstrv && !isstring_BM ((value_tyBM) _.dirstrv))
    FAILHERE (makenode1_BM (BMP_string, (value_tyBM) _.dirstrv));
  if (_.dirstrv && isstring_BM ((value_tyBM) _.dirstrv))
    {
      struct stat dirstat;
      int olderrno = errno;
      errno = 0;
      memset (&dirstat, 0, sizeof (dirstat));
      if (!stat (bytstring_BM (_.dirstrv), &dirstat)
          && (dirstat.st_mode & S_IFMT) != S_IFDIR)
        errno = ENOTDIR;
      int newerrno = errno;
      errno = olderrno;
      if (newerrno)
        FAILHERE (makenode2_BM
                  (BMP_node, (value_tyBM) _.dirstrv,
                   taggedint_BM (newerrno)));
    }
  if (!isnode_BM ((value_tyBM) _.cmdnodv))
    FAILHERE (makenode1_BM (BMP_node, (value_tyBM) _.cmdnodv));
  if (!isclosure_BM ((value_tyBM) _.endclosv))
    FAILHERE (makenode1_BM (BMP_closure, (value_tyBM) _.cmdnodv));
  unsigned cmdlen = nodewidth_BM ((value_tyBM) _.cmdnodv);
  if (cmdlen == 0)
    FAILHERE (makenode1_BM (BMP_node, (value_tyBM) _.cmdnodv));
  for (unsigned aix = 0; aix < cmdlen; aix++)
    {
      _.curargv = nodenthson_BM ((value_tyBM) _.cmdnodv, aix);
      if (!isstring_BM (_.curargv))
        FAILHERE (makenode2_BM
                  (BMP_node, (value_tyBM) _.cmdnodv, taggedint_BM (aix)));
    }
  ASSERT_BM (nbworkjobs_BM >= MINNBWORKJOBS_BM
             && nbworkjobs_BM <= MAXNBWORKJOBS_BM);
  {
    lock_runproc_mtx_at_BM (__LINE__);
    lockedproc = true;
    int slotpos = -1;
    for (int ix = 0; ix < nbworkjobs_BM; ix++)
      {
        if (running_process_descr_arr_BM[ix].rp_pid == 0)
          {
            slotpos = ix;
            break;
          };
      }
    if (slotpos >= 0 && !pendingrunproc_list_BM)
      {
        fork_process_at_slot_BM (slotpos, _.dirstrv, _.cmdnodv,
                                 _.endclosv, CURFRAME_BM);
      }
    else
      {                         // append to pendingrunproc_list_BM
        if (!pendingrunproc_list_BM)
          pendingrunproc_list_BM = makelist_BM ();
        _.nodv = (value_tyBM)
          makenode3_BM (k_queue_process, (value_tyBM) _.dirstrv,
                        (value_tyBM) _.cmdnodv, (value_tyBM) _.endclosv);
        listappend_BM (pendingrunproc_list_BM, _.nodv);
      }
    ASSERT_BM (lockedproc);
    unlock_runproc_mtx_at_BM (__LINE__), lockedproc = false;
  }
  LOCALJUSTRETURN_BM ();
failure:
#undef FAILHERE
  if (lockedproc)
    unlock_runproc_mtx_at_BM (__LINE__), lockedproc = false;
  DBGPRINTF_BM
    ("queue_process failure failin %d dirstr %s, cmdnod %s endclos %s, cause %s",
     failin,
     bytstring_BM (_.dirstrv), debug_outstr_value_BM ((value_tyBM) _.cmdnodv,
                                                      CURFRAME_BM, 0),
     debug_outstr_value_BM ((value_tyBM) _.endclosv, CURFRAME_BM, 0),
     debug_outstr_value_BM ((value_tyBM) _.causev, CURFRAME_BM, 0));
  _.errorv = (value_tyBM) makenode4_BM (k_queue_process, (value_tyBM) _.dirstrv, (value_tyBM) _.cmdnodv,        //
                                        (value_tyBM) _.endclosv,
                                        (value_tyBM) _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end queue_process_BM */



////////////////
void
fork_process_at_slot_BM (int slotpos,
                         const stringval_tyBM * dirstrarg,
                         const node_tyBM * cmdnodarg,
                         const closure_tyBM * endclosarg,
                         struct stackframe_stBM *stkf)
{
  //objectval_tyBM *k_queue_process = BMK_8DQ4VQ1FTfe_5oijDYr52Pb;
  //objectval_tyBM *k_sbuf_object = BMK_77xbaw1emfK_1nhE4tp0bF3;
  LOCALFRAME_BM ( /*prev: */ stkf,
                 /*descr: */ NULL,
                 const stringval_tyBM * dirstrv;        //
                 const node_tyBM * cmdnodv;     //
                 const closure_tyBM * endclosv; //
                 value_tyBM curargv;    //
                 objectval_tyBM * bufob;        //
    );
  _.dirstrv = dirstrarg;
  _.cmdnodv = cmdnodarg;
  _.endclosv = endclosarg;
  int cmdlen = nodewidth_BM ((value_tyBM) _.cmdnodv);
  ASSERT_BM (cmdlen > 0);
  ASSERT_BM (slotpos >= 0 && slotpos < MAXNBWORKJOBS_BM);
  DBGPRINTF_BM ("fork_process_at_slot_BM slotpos %d cmdnod %s",
                slotpos,
                debug_outstr_value_BM ((value_tyBM) _.cmdnodv, CURFRAME_BM,
                                       0));
  /// should fork the process
  int pipfd[2] = { -1, -1 };
  const char **args = calloc (cmdlen + 1, sizeof (char *));
  if (!args)
    FATAL_BM ("calloc args %d failed - %m", cmdlen);
  for (int aix = 0; aix < cmdlen; aix++)
    args[aix] = bytstring_BM (nodenthson_BM ((value_tyBM) _.cmdnodv, aix));
  if (pipe (pipfd))
    FATAL_BM ("pipe failed - %m");
  ASSERT_BM (pipfd[0] > 0 && pipfd[1] > 0);
  fflush (NULL);
  pid_t pid = fork ();
  if (pid < 0)
    FATAL_BM ("failed to fork %s - %m", args[0]);
  if (pid == 0)
    {
      {
        // child process; 
        sigset_t sigset = { };
        sigemptyset (&sigset);
        // restore default SIGTERM & SIGQUIT behavior
        signal (SIGTERM, SIG_DFL);
        signal (SIGQUIT, SIG_DFL);
        signal (SIGCHLD, SIG_DFL);
        sigaddset (&sigset, SIGTERM);
        sigaddset (&sigset, SIGQUIT);
        sigaddset (&sigset, SIGCHLD);
        sigprocmask (SIG_UNBLOCK, &sigset, NULL);
        sigfd_BM = -2;
      }
      //in principle, most file descriptors should be
      //close-on-exec, but just in case we close some of them...
      for (int ix = 3; ix < 64; ix++)
        if (ix != pipfd[1])
          (void) close (ix);
      if (isstring_BM ((value_tyBM) _.dirstrv))
        {
          if (chdir (bytstring_BM (_.dirstrv)))
            {
              perror (bytstring_BM (_.dirstrv));
              exit (126);
            }
        }
      int fd = open ("/dev/null", O_RDONLY);
      dup2 (fd, STDIN_FILENO);
      close (fd), fd = -1;
      dup2 (pipfd[1], STDOUT_FILENO);
      dup2 (pipfd[1], STDERR_FILENO);
      execv (args[0], (char *const *) args);
      perror (args[0]);
      _exit (127);
    }
  else
    {                           // parent process
      struct processdescr_stBM *onproc =
        running_process_descr_arr_BM + slotpos;
      ASSERT_BM (onproc->rp_pid <= 0 && onproc->rp_outpipe <= 0);
      onproc->rp_pid = pid;
      onproc->rp_outpipe = pipfd[0];
      fcntl (pipfd[0], F_SETFL, O_NONBLOCK);
      onproc->rp_cmdnodv = _.cmdnodv;
      onproc->rp_closv = _.endclosv;
      onproc->rp_dirstrv = _.dirstrv;
      _.bufob = makeobj_BM ();
      onproc->rp_bufob = _.bufob;
    }
}                               /* end fork_process_at_slot_BM */


/// remember that only plain_event_loop_BM is allowed to *remove*
/// things from running_process_descr_arr_BM or pendingrunproc_list_BM
void
plain_event_loop_BM (void)      /// called from run_onionweb_BM (which is called from main)
//// or directly from main
{
  //  objectval_tyBM *k_plain_event_loop = BMK_74VNUG6Vqq4_700i8h0o8EI;
  LOCALFRAME_BM ( /*prev: */ NULL, /*descr: */ NULL,
                 objectval_tyBM * bufob;
                 objectval_tyBM * curjsob;);
  atomic_init (&eventlooprunning_BM, true);

  DBGBACKTRACEPRINTF_BM ("plain_event_loop_BM before loop sigfd_BM=%d tid#%ld elapsed %.3f s",  //
                         sigfd_BM, (long) gettid_BM (), elapsedtime_BM ());
  long loopcnt = 0;
  int masterixjs = -1;
  INFOPRINTF_BM ("start loop of plain_event_loop_BM for %s",
                 onion_web_base_BM);
  while (atomic_load (&eventlooprunning_BM))
    {
      loopcnt++;
      struct pollfd pollarr[MAXNBWORKJOBS_BM + 10];
      pid_t endedprocarr[MAXNBWORKJOBS_BM + 2];
      memset (pollarr, 0, sizeof (pollarr));
      memset (endedprocarr, 0, sizeof (endedprocarr));
      int nbpoll = 0;
      enum
      { pollix_sigfd,           // got a signalfd
        pollix_cmdp,            // the command pipe
        pollix__last
      };
      pollarr[pollix_sigfd].fd = sigfd_BM;
      pollarr[pollix_sigfd].events = POLL_IN;
      pollarr[pollix_cmdp].fd = cmdpipe_rd_BM;
      pollarr[pollix_cmdp].events = POLL_IN;
      nbpoll = pollix__last;
      {
        lock_runproc_mtx_at_BM (__LINE__);
        for (int j = 0; j < nbworkjobs_BM; j++)
          if (running_process_descr_arr_BM[j].rp_pid > 0
              && running_process_descr_arr_BM[j].rp_outpipe > 0)
            {
              pollarr[nbpoll].fd = running_process_descr_arr_BM[j].rp_outpipe;
              pollarr[nbpoll].events = POLL_IN;
              nbpoll++;
            }
        unlock_runproc_mtx_at_BM (__LINE__);
      }
      if (master_unix_json_socket_fd_BM > 0)
        {
          pollarr[nbpoll].fd = master_unix_json_socket_fd_BM;
          pollarr[nbpoll].events = POLL_IN;
          masterixjs = nbpoll;
          nbpoll++;
        };
#warning accepted unix json sockets should be polled
      {
        pthread_mutex_lock (&unix_json_mtx_BM);
        int nbjs = atomic_load (&nb_slave_json_sockets_BM);
        if (nbjs > 0)
          {
            ASSERT_BM (nbjs <= MAXNBWORKJOBS_BM);
            for (int jsix = 0; jsix < nbjs; jsix++)
              {
                _.curjsob = unix_json_procobarr[jsix];
                ASSERT_BM (_.curjsob != NULL);
#warning should use the payload of curjsob, it should be a valid struct jsonrpcservicedata_stBM
                FATAL_BM ("unimplemented accepted unix json sockets nbjs=%d",
                          nbjs);
              }
          };
        pthread_mutex_unlock (&unix_json_mtx_BM);
      }
      //////////// POLLING BELOW
#define POLL_DELAY_MILLISECS_BM 3750
      if (loopcnt % 4 == 0)
        DBGPRINTF_BM
          ("plain_event_loop_BM before poll nbpoll=%d loop#%ld delay %d ms",
           nbpoll, loopcnt, POLL_DELAY_MILLISECS_BM);
      int nbready = poll (pollarr, nbpoll, POLL_DELAY_MILLISECS_BM);
      if (loopcnt % 4 == 0)
        DBGPRINTF_BM ("plain_event_loop_BM nbready %d loop#%ld", nbready,
                      loopcnt);
      if (nbready == 0)         // no file descriptor read, timed out
        continue;
      if (nbready < 0)
        {
          if (errno != EINTR)
            FATAL_BM ("plain_event_loop_BM poll failure");
          continue;
        }
      {
        char pipbuf[1024 + 4];
        lock_runproc_mtx_at_BM (__LINE__);
        int runix = 0;
        for (int ix = pollix__last; ix < nbpoll; ix++)
          {
            if (pollarr[ix].revents & POLL_IN)
              {
                int curfd = pollarr[ix].fd;
                while (runix < nbworkjobs_BM)
                  {
                    if (running_process_descr_arr_BM[runix].rp_outpipe ==
                        curfd)
                      {
                        struct processdescr_stBM *onproc =
                          running_process_descr_arr_BM + runix;
                        runix++;
                        int bytcnt = 0;
                        do
                          {
                            memset (pipbuf, 0, sizeof (pipbuf));
                            // we might do ioctl(curfd, FIONBIO, &cnt)
                            // but it is not worth doing since the pipe
                            // is non-blocking. See https://stackoverflow.com/a/1151077/841108
                            bytcnt =
                              read (curfd, pipbuf, sizeof (pipbuf) - 4);
                            if (bytcnt < 0 && errno == EINTR)
                              continue;
                            if (bytcnt < 0 && errno == EWOULDBLOCK)
                              break;
                            if (bytcnt < 0)
                              {
                                // this probably should not happen
                                FATAL_BM
                                  ("unexpected error %m on output pipe fd#%d for pid %d",
                                   curfd, (int) onproc->rp_pid);
                              }
                            if (bytcnt == 0)
                              { // end of file on pipe
                                // the forked process might close its stdout
                                // and still be running, even if this is
                                // unfriendly...
                                close (curfd);
                                onproc->rp_outpipe = -1;
                                break;
                              }
                            ASSERT_BM (bytcnt > 0);
                            pipbuf[bytcnt] = (char) 0;
                            if ((int) strlen (pipbuf) < (int) bytcnt)
                              {
                                WARNPRINTF_BM
                                  ("unexpected null byte from process pid#%d command node %s in %s",
                                   (int)
                                   running_process_descr_arr_BM[runix].rp_pid,
                                   OUTSTRVALUE_BM ((value_tyBM)
                                                   onproc->rp_cmdnodv),
                                   bytstring_BM (onproc->rp_dirstrv) ? :
                                   "./");
                                if (kill (onproc->rp_pid, SIGTERM) == 0)
                                  WARNPRINTF_BM ("sent SIGTERM to pid#%d",
                                                 onproc->rp_pid);
                                close (curfd);
                                onproc->rp_outpipe = -1;
                                usleep (1000);

                              }
                            _.bufob = onproc->rp_bufob;
                            ASSERT_BM (isobject_BM (_.bufob));
                            ASSERT_BM (objhasstrbufferpayl_BM (_.bufob));
                            objstrbufferappendcstrpayl_BM (_.bufob, pipbuf);
                            _.bufob = NULL;
                            pipbuf[0] = (char) 0;
                          }
                        while (bytcnt > 0);
                        break;
                      }
                  }
              }
            _.bufob = NULL;
          }
        unlock_runproc_mtx_at_BM (__LINE__);
      }
      if (pollarr[pollix_sigfd].revents & POLL_IN)
        {
          DBGPRINTF_BM ("plain_event_loop sigfd readable");
          bool stop = read_sigfd_BM ();
          if (stop)
            {
              atomic_store (&eventlooprunning_BM, false);
              DBGPRINTF_BM ("plain_event_loop sigfd stopping after sigfd");
              break;
            }
          else
            DBGPRINTF_BM ("plain_event_loop sigfd continuing after sigfd");
        }
      if (pollarr[pollix_cmdp].revents & POLL_IN)
        read_commandpipe_BM ();
      if (masterixjs > 0 && pollarr[masterixjs].revents & POLL_IN)
        {
          ASSERT_BM (pollarr[masterixjs].fd == master_unix_json_socket_fd_BM);
          handle_master_unix_json_connection_BM ((struct stackframe_stBM *)
                                                 &_);
        };
    }                           /* end while eventlooprunning */
  INFOPRINTF_BM ("plain_event_loop_BM ended loopcnt=%ld", loopcnt);
}                               /* end plain_event_loop_BM */



void
handle_master_unix_json_connection_BM (struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM val);
  union
  {
    struct sockaddr_un un_sockaddr;
    char xtraspace[256];
  } us;
  ASSERT_BM (master_unix_json_socket_fd_BM > 0);
  memset (&us, 0, sizeof (us));
  socklen_t sa_len = sizeof (us) - sizeof (int);
  int acceptedfd =
    accept (master_unix_json_socket_fd_BM, &us.un_sockaddr, &sa_len);
  DBGPRINTF_BM ("master unixjsonfd#%d acceptedfd#%d sockaddr '%s'",
                master_unix_json_socket_fd_BM,
                acceptedfd, us.un_sockaddr.sun_path);
  if (acceptedfd > 0)
    {
      int nbs = atomic_fetch_add (&nb_slave_json_sockets_BM, 1);
      if (nbs >= MAXNBWORKJOBS_BM || nbs >= nbworkjobs_BM + 1)
        {
          atomic_fetch_add (&nbworkjobs_BM, -1);
          WARNPRINTF_BM
            ("too many %d slave JSON connections on masterfd#%d %s (Bismon pid %d on %s)",
             nbs, master_unix_json_socket_fd_BM, us.un_sockaddr.sun_path,
             (int) getpid (), myhostname_BM);
          close (acceptedfd);
          fflush (NULL);
          usleep (1000);
          return;
        }
    /***
     * TODO: we need to maintain a small array of accepted unix json
     * sockets.... and in each of them, some object with a string
     * buffer, and a closure to process each JSON, etc...
     ***/
#warning handle_master_unix_json_connection_BM incomplete with acceptedfd
      FATAL_BM
        ("incomplete handle_master_unix_json_connection_BM for acceptedfd#%d sockaddr '%s'",
         acceptedfd, us.un_sockaddr.sun_path);
      pthread_mutex_lock(&unix_json_mtx_BM);
      /***
       * TODO: create a transient object $JSOB of class
       * €_68YhfMdHd5l_39sNW1u6duy, the predefined json_rps_service.
       * That $JSOB object should have a payload of
       * typayl_jsonrpcservice_BM with a struct
       * jsonrpcservicedata_stBM whose buffer should be initialized,
       * and whose jsonrpcserv_sockfd should be the acceptedfd ....
       * That $JSOB should be added to unix_json_procobarr
       ****/
      pthread_mutex_unlock(&unix_json_mtx_BM);
    }
}                               /* end handle_master_unix_json_connection_BM */

void
gcmarkevloop_BM (struct garbcoll_stBM *gc)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  lock_runproc_mtx_at_BM (__LINE__);
  VALUEGCPROC_BM (gc, pendingrunproc_list_BM, 0);
  for (int oix = 0; oix < MAXNBWORKJOBS_BM; oix++)
    {
      struct processdescr_stBM *runproc = running_process_descr_arr_BM + oix;
      VALUEGCPROC_BM (gc, runproc->rp_dirstrv, 0);
      VALUEGCPROC_BM (gc, runproc->rp_cmdnodv, 0);
      VALUEGCPROC_BM (gc, runproc->rp_bufob, 0);
    };
  unlock_runproc_mtx_at_BM (__LINE__);
}                               /* end gcmarkevloop_BM */

void
stop_unix_json_socket_processing_BM (void)
{
  ASSERT_BM (master_unix_json_socket_fd_BM > 0);
  close (master_unix_json_socket_fd_BM);
  master_unix_json_socket_fd_BM = -1;
#warning stop_unix_json_socket_processing_BM incomplete
}                               /* end stop_unix_json_socket_processing_BM */


void
initialize_unix_json_socket_processing_BM (const char *ujsname)
{
  ASSERT_BM (ujsname == unix_json_socket_BM);
  master_unix_json_socket_fd_BM = socket (AF_UNIX, SOCK_STREAM, 0);
  if (master_unix_json_socket_fd_BM < 0)
    FATAL_BM ("failed to make master_unix_json_socket_BM (%m)");
  {
    struct sockaddr_un sa_ujs;
    memset (&sa_ujs, 0, sizeof (sa_ujs));
    sa_ujs.sun_family = AF_UNIX;
    strncpy (sa_ujs.sun_path, ujsname, sizeof (sa_ujs.sun_path) - 1);
    if (bind (master_unix_json_socket_fd_BM, &sa_ujs, sizeof (sa_ujs)) < 0)
      FATAL_BM ("failed to bind master json socket#%d to Unix name %s",
                master_unix_json_socket_fd_BM, sa_ujs.sun_path);
  }
  struct stat stat_ujs = { 0 };
  if (stat (ujsname, &stat_ujs) == 0)
    {
      ASSERT_BM (stat_ujs.st_ino > 0);
      if ((S_IFMT & stat_ujs.st_mode) != S_IFSOCK)
        FATAL_BM ("unix JSON socket %s is not a genuine socket", ujsname);
    }
  atexit (stop_unix_json_socket_processing_BM);
  if (listen (master_unix_json_socket_fd_BM, MAXNBWORKJOBS_BM) < 0)
    FATAL_BM ("failed to listen unix json socket fd#%d %s (%m)",
              master_unix_json_socket_fd_BM, ujsname);
  ASSERT_BM (master_unix_json_socket_fd_BM > 0);
}                               /* end initialize_unix_json_socket_processing_BM */



///////// end of file evloop_BM.c 
