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
#include "bismon.h"
#include "evloop_BM.const.h"

//////////////////////////////////////////////////////////////////////////
/// For process queue running processes; similar to gtkrunprocarr_BM
/// in newgui_GTKBM.c stuff is added into onionrunprocarr_BM &
/// onionrunpro_list_BM by any thread doing queue_process_BM. Stuff is
/// removed from them only by plain_event_loop_BM which would also
/// apply the closures.
struct onionproc_stBM onionrunprocarr_BM[MAXNBWORKJOBS_BM];

/// queued process commands, of nodes (dir, cmd, clos); for processes
/// which are not yet in the array above...
struct listtop_stBM *onionrunpro_list_BM;

// lock for the structures above (both onionrunprocarr_BM & onionrunpro_list_BM)
pthread_mutex_t onionrunpro_mtx_BM = PTHREAD_MUTEX_INITIALIZER;

volatile atomic_bool onionlooprunning_BM;

pthread_mutex_t onionstack_mtx_BM = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t onionstack_condchange_BM = PTHREAD_COND_INITIALIZER;

struct onionstackinfo_stBM onionstackinfo_BM[MAXNBWORKJOBS_BM + 1];
thread_local struct onionstackinfo_stBM *curonionstackinfo_BM;


// the lock above should be set when calling:
void
fork_process_at_slot_BM (int slotpos,
                         const stringval_tyBM * dirstrarg,
                         const node_tyBM * cmdnodarg,
                         const closure_tyBM * endclosarg,
                         struct stackframe_stBM *stkf);
void lockonion_runpro_mtx_at_BM (int lineno);
void unlockonion_runpro_mtx_at_BM (int lineno);

void web_plain_event_loop_BM (void);

// Handle signals thu signalfd(2); return true to break
// web_plain_event_loop_BM and stop the loop there. To continue the
// event loop, it should return false.
bool read_sigfd_BM (void);
// handle SIGCHLD
void handle_sigchld_BM (pid_t pid);
// handle the command pipe
void read_commandpipe_BM (void);

void
lockonion_runpro_mtx_at_BM (int lineno __attribute__((unused)))
{
#if 0
  // too verbose, so not needed
  DBGPRINTFAT_BM (__FILE__, lineno, "lockonion_runpro_mtx_BM thrid=%ld",
                  (long) gettid_BM ());
#endif
  pthread_mutex_lock (&onionrunpro_mtx_BM);
}                               /* end lockonion_runpro_mtx_at_BM */


void
unlockonion_runpro_mtx_at_BM (int lineno __attribute__((unused)))
{
#if 0
  // too verbose, so not needed
  DBGPRINTFAT_BM (__FILE__, lineno, "unlockonion_runpro_mtx_BM thrid=%ld",
                  (long) gettid_BM ());
#endif
  pthread_mutex_unlock (&onionrunpro_mtx_BM);
}                               /* end lockonion_runpro_mtx_at_BM */

// queue some external process; its stdin is /dev/null; both stdout &
// stderr are merged & captured; final string is given to the closure.
// dirstrv is the string of the directory to run it in (if NULL, use
// cwd) cmdnodv is a node with all sons being strings, for the command
// to run endclosv is the closure getting the status
// stringoutput, could fail
void
onion_queue_process_BM (const stringval_tyBM * dirstrarg,
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
    lockonion_runpro_mtx_at_BM (__LINE__);
    lockedproc = true;
    int slotpos = -1;
    for (int ix = 0; ix < nbworkjobs_BM; ix++)
      {
        if (onionrunprocarr_BM[ix].rp_pid == 0)
          {
            slotpos = ix;
            break;
          };
      }
    if (slotpos >= 0 && !onionrunpro_list_BM)
      {
        fork_process_at_slot_BM (slotpos, _.dirstrv, _.cmdnodv,
                                 _.endclosv, CURFRAME_BM);
      }
    else
      {                         // append to onionrunpro_list_BM
        if (!onionrunpro_list_BM)
          onionrunpro_list_BM = makelist_BM ();
        _.nodv = (value_tyBM)
          makenode3_BM (k_queue_process, (value_tyBM) _.dirstrv,
                        (value_tyBM) _.cmdnodv, (value_tyBM) _.endclosv);
        listappend_BM (onionrunpro_list_BM, _.nodv);
      }
    ASSERT_BM (lockedproc);
    unlockonion_runpro_mtx_at_BM (__LINE__), lockedproc = false;
  }
  LOCALJUSTRETURN_BM ();
failure:
#undef FAILHERE
  if (lockedproc)
    unlockonion_runpro_mtx_at_BM (__LINE__), lockedproc = false;
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
      struct onionproc_stBM *onproc = onionrunprocarr_BM + slotpos;
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


/// remember that only web_plain_event_loop_BM is allowed to *remove*
/// things from onionrunprocarr_BM or onionrunpro_list_BM
void
web_plain_event_loop_BM (void)  /// called from run_onionweb_BM
{
  //  objectval_tyBM *k_web_plain_event_loop = BMK_74VNUG6Vqq4_700i8h0o8EI;
  LOCALFRAME_BM ( /*prev: */ NULL, /*descr: */ NULL,
                 objectval_tyBM * bufob;);
  atomic_init (&onionlooprunning_BM, true);

  DBGBACKTRACEPRINTF_BM ("web_plain_event_loop_BM before loop sigfd_BM=%d tid#%ld elapsed %.3f s",      //
                         sigfd_BM, (long) gettid_BM (), elapsedtime_BM ());
  long loopcnt = 0;
  INFOPRINTF_BM ("start loop of web_plain_event_loop_BM for %s",
                 onion_web_base_BM);
  while (atomic_load (&onionlooprunning_BM))
    {
      loopcnt++;
      struct pollfd pollarr[MAXNBWORKJOBS_BM + 8];
      pid_t endedprocarr[MAXNBWORKJOBS_BM];
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
        lockonion_runpro_mtx_at_BM (__LINE__);
        for (int j = 0; j < nbworkjobs_BM; j++)
          if (onionrunprocarr_BM[j].rp_pid > 0
              && onionrunprocarr_BM[j].rp_outpipe > 0)
            {
              pollarr[nbpoll].fd = onionrunprocarr_BM[j].rp_outpipe;
              pollarr[nbpoll].events = POLL_IN;
              nbpoll++;
            }
        unlockonion_runpro_mtx_at_BM (__LINE__);
      }
#define POLL_DELAY_MILLISECS_BM 3750
      if (loopcnt % 4 == 0)
        DBGPRINTF_BM
          ("web_plain_event_loop_BM before poll nbpoll=%d loop#%ld delay %d ms",
           nbpoll, loopcnt, POLL_DELAY_MILLISECS_BM);
      int nbready = poll (pollarr, nbpoll, POLL_DELAY_MILLISECS_BM);
      if (loopcnt % 4 == 0)
        DBGPRINTF_BM ("web_plain_event_loop_BM nbready %d loop#%ld", nbready,
                      loopcnt);
      if (nbready == 0)         // no file descriptor read, timed out
        continue;
      if (nbready < 0)
        {
          if (errno != EINTR)
            FATAL_BM ("web_plain_event_loop_BM poll failure");
          continue;
        }
      {
        char pipbuf[1024 + 4];
        lockonion_runpro_mtx_at_BM (__LINE__);
        int runix = 0;
        for (int ix = pollix__last; ix < nbpoll; ix++)
          {
            if (pollarr[ix].revents & POLL_IN)
              {
                int curfd = pollarr[ix].fd;
                while (runix < nbworkjobs_BM)
                  {
                    if (onionrunprocarr_BM[runix].rp_outpipe == curfd)
                      {
                        struct onionproc_stBM *onproc =
                          onionrunprocarr_BM + runix;
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
                                   (int) onionrunprocarr_BM[runix].rp_pid,
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
        unlockonion_runpro_mtx_at_BM (__LINE__);
      }
      if (pollarr[pollix_sigfd].revents & POLL_IN)
        {
          DBGPRINTF_BM ("plain_event_loop sigfd readable");
          bool stop = read_sigfd_BM ();
          if (stop)
            {
              atomic_store (&onionlooprunning_BM, false);
              DBGPRINTF_BM ("plain_event_loop sigfd stopping after sigfd");
              break;
            }
          else
            DBGPRINTF_BM ("plain_event_loop sigfd continuing after sigfd");
        }
      if (pollarr[pollix_cmdp].revents & POLL_IN)
        read_commandpipe_BM ();
    }                           /* end while onionlooprunning */
  INFOPRINTF_BM ("web_plain_event_loop_BM ended loopcnt=%ld", loopcnt);
}                               /* end web_plain_event_loop_BM */
