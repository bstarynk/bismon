// file web_ONIONBM.c
/***
    BISMON 
    Copyright © 2018, 2019 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
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
#include <onion/onion.h>
#include "bismon.h"
#include "web_ONIONBM.const.h"
#include "_login_ONIONBM.h"

// expiration delay for user session, in seconds (more than an hour,
// but increased on every web interaction)
#define USER_WEBSESSION_EXPIRATION_DELAY 4000.0
// expiration delay for the anonymous session, in seconds (more than ten years)
#define ANON_WEBSESSION_EXPIRATION_DELAY 333.0e6
extern void run_onionweb_BM (int nbjobs);
static onion *myonion_BM;
// the command pipe contains bytes, each considered as a different message
static int cmdpipe_rd_BM = -1, cmdpipe_wr_BM = -1;

static int sigfd_BM = -1;
extern void add_defer_command_onion_BM (void);

extern void
onion_queue_process_BM (const stringval_tyBM * dirstrarg,
                        const node_tyBM * cmdnodarg,
                        const closure_tyBM * endclosarg,
                        struct stackframe_stBM *stkf);

extern void onion_log_puts_message_BM (const char *msg);
extern void onion_log_begin_message_BM (void);
extern void onion_log_end_message_BM (void);
extern void onion_log_object_message_BM (const objectval_tyBM * obj);

//////////////////////////////////////////////////////////////////////////
/// For process queue running processes; similar to gtkrunprocarr_BM
/// in newgui_GTKBM.c stuff is added into onionrunprocarr_BM &
/// onionrunpro_list_BM by any thread doing queue_process_BM. Stuff is
/// removed from them only by plain_event_loop_BM which would also
/// apply the closures.
struct onionproc_stBM
{
  pid_t rp_pid;
  int rp_outpipe;
  const stringval_tyBM *rp_dirstrv;
  const node_tyBM *rp_cmdnodv;
  const closure_tyBM *rp_closv;
  objectval_tyBM *rp_bufob;
} onionrunprocarr_BM[MAXNBWORKJOBS_BM];

/// queued process commands, of nodes (dir, cmd, clos); for processes
/// which are not yet in the array above...
struct listtop_stBM *onionrunpro_list_BM;

// lock for the structures above (both onionrunprocarr_BM & onionrunpro_list_BM)
pthread_mutex_t onionrunpro_mtx_BM = PTHREAD_MUTEX_INITIALIZER;

static volatile atomic_bool onionlooprunning_BM;

static pthread_mutex_t onionstack_mtx_bm = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t onionstack_condchange_bm = PTHREAD_COND_INITIALIZER;
struct onionstackinfo_stBM
{
  pthread_t ost_thread;
  struct stackframe_stBM *ost_stkf;
  atomic_bool ost_suspended;
};
static struct onionstackinfo_stBM onionstackinfo_bm[MAXNBWORKJOBS_BM + 1];
static thread_local struct onionstackinfo_stBM *curonionstackinfo_BM;

// return a malloced percent-encoded string for all the query arguments
static char *percent_encode_onion_query_args_BM (onion_request * req);

/// create the anonymous web session and write it into a file
static void create_anonymous_web_session_BM (void);

// the lock above should be set when calling:
static void
fork_onion_process_at_slot_BM (int slotpos,
                               const stringval_tyBM * dirstrarg,
                               const node_tyBM * cmdnodarg,
                               const closure_tyBM * endclosarg,
                               struct stackframe_stBM *stkf);
static void lockonion_runpro_mtx_at_BM (int lineno);
static void unlockonion_runpro_mtx_at_BM (int lineno);

static void web_plain_event_loop_BM (void);

// handle signals thu signafd(2); return true to break web_plain_event_loop_BM
static bool read_sigfd_BM (void);
// handle SIGCHLD
static void handle_sigchld_BM (pid_t pid);
// handle the command pipe
static void read_commandpipe_BM (void);

static void register_onion_thread_stack_BM (struct stackframe_stBM *);
static void unregister_onion_thread_stack_BM (struct stackframe_stBM *);
static void perhaps_suspend_for_gc_onion_thread_stack_BM (struct
                                                          stackframe_stBM *);

/*** Our websession cookies are something like
     n<rank>r<rand1>t<rand2>o<oid> where <rank> is the websess_rank,
     <rand1> and <rand2> are random integers, <oid> is the websession
     object id
 ***/

#define BISMONION_WEBSESS_SUFLEN 40


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
  DBGPRINTFAT_BM (__FILE__, lineno, "unlockonion_runpro_mtx_BM thrid=%ld",
                  (long) gettid_BM ());
#endif
  pthread_mutex_unlock (&onionrunpro_mtx_BM);
}                               /* end lockonion_runpro_mtx_at_BM */

void
onion_log_begin_message_BM (void)
{
  static long logcnt;
  logcnt++;
  double now = clocktime_BM (CLOCK_REALTIME);
  time_t nowt = (time_t) floor (now);
  double nowfrac = now - (double) nowt;
  ASSERT_BM (nowfrac >= 0.0 && nowfrac < 1.0);
  struct tm nowtm = {
  };
  localtime_r (&nowt, &nowtm);
  char nowtibuf[40];
  memset (nowtibuf, 0, sizeof (nowtibuf));
  strftime (nowtibuf, sizeof (nowtibuf), "%T %Z", &nowtm);
  char nowfracbuf[8];
  memset (nowfracbuf, 0, sizeof (nowfracbuf));
  snprintf (nowfracbuf, sizeof (nowfracbuf), "%.2f", nowfrac);
  char nowcntbuf[16];
  memset (nowcntbuf, 0, sizeof (nowcntbuf));
  snprintf (nowcntbuf, sizeof (nowcntbuf), " #%ld", logcnt);
  char logmbuf[80];
  memset (logmbuf, 0, sizeof (logmbuf));
  snprintf (logmbuf, sizeof (logmbuf), "%s%s%s", nowtibuf,
            nowfracbuf + 1, nowcntbuf);
  DBGBACKTRACEPRINTF_BM ("web log_begin_message_BM logmbuf %s", logmbuf);
  FATAL_BM ("log_begin_message_BM unimplemented in web_ONIONBM: %s", logmbuf);
#warning onion_log_begin_message_BM unimplemented in web_ONIONBM
}                               /* end onion_log_begin_message_BM */

void
onion_log_end_message_BM (void)
{
  FATAL_BM ("log_end_message_BM unimplemented in web_ONIONBM");
#warning onion_log_end_message_BM  unimplemented in web_ONIONBM
}                               /* end onion_log_end_message_BM */

void
onion_log_object_message_BM (const objectval_tyBM * obj)
{
  FATAL_BM ("log_object_message_BM unimplemented in web_ONIONBM obj %s",
            objectdbg_BM (obj));
#warning onion_log_object_message_BM  unimplemented in web_ONIONBM
}                               /* end onion_log_object_message_BM */

void
onion_log_puts_message_BM (const char *msg)
{
  if (!msg || !msg[0])
    return;
  FATAL_BM ("onion_log_puts_message_BM unimplemented in web_ONIONBM msg %s",
            msg);
#warning onion_log_puts_message_BM  unimplemented in web_ONIONBM
}                               /* end onion_log_puts_message_BM */


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
  objectval_tyBM *k_sbuf_object = BMK_77xbaw1emfK_1nhE4tp0bF3;
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
        fork_onion_process_at_slot_BM (slotpos, _.dirstrv, _.cmdnodv,
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
static void
fork_onion_process_at_slot_BM (int slotpos,
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
  DBGPRINTF_BM ("fork_onion_process_at_slot_BM slotpos %d cmdnod %s",
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
}                               /* end fork_onion_process_at_slot_BM */


////////////////////////////////////////////////////////////////
static onion_connection_status
custom_onion_handler_BM (void *clientdata,
                         onion_request * req, onion_response * resp);
static onion_connection_status
websocket_onion_handler_BM (void *clientdata,
                            onion_websocket * ws, ssize_t data_ready_len);
static onion_connection_status
login_onion_handler_BM (void *clientdata,
                        onion_request * req, onion_response * resp);
static onion_connection_status
do_forgot_onion_BM (const char *username,
                    onion_request * req, onion_response * resp);

static onion_connection_status
do_login_redirect_onion_BM (objectval_tyBM * contribobarg,
                            const char *location, onion_request * req,
                            onion_response * resp,
                            struct stackframe_stBM *stkf);


static onion_connection_status
do_dynamic_onion_BM (objectval_tyBM * sessionobarg, const char *reqpath,
                     bool postrequest,
                     onion_request * req,
                     onion_response * resp, struct stackframe_stBM *stkf);

////////////////
void
run_onionweb_BM (int nbjobs)    // declared and used only in
                                // main_BM.c, called from main
                                // function
{
  char *webhost = NULL;
  int webport = 0;
  int pos = -1;
  int colonpos = -1;
  if (nbjobs < MINNBWORKJOBS_BM)
    nbjobs = MINNBWORKJOBS_BM;
  else if (nbjobs > MAXNBWORKJOBS_BM)
    nbjobs = MAXNBWORKJOBS_BM;
  if (!onion_web_base_BM)
    onion_web_base_BM = "localhost:8086";
  if (sscanf
      (onion_web_base_BM, "%m[.a-zA-Z0-9+-]%n:%d%n", &webhost, &colonpos,
       &webport, &pos) < 2 || pos < 0 || onion_web_base_BM[pos])
    FATAL_BM ("bad web base %s -host %s port %d", onion_web_base_BM,
              webhost ? : "??", webport);
  /// clear and initialize the dictionnary of web sessions, whose keys are cookies
  objputdictpayl_BM (BMP_the_web_sessions);
  myonion_BM =
    onion_new (O_THREADED | O_NO_SIGTERM | O_SYSTEMD | O_DETACH_LISTEN);
  if (!myonion_BM)
    FATAL_BM ("failed to create onion");
  onion_set_max_threads (myonion_BM, nbjobs);
  DBGPRINTF_BM ("run_onionweb webhost '%s' webport %d tid#%ld elapsed %.3f s",
                webhost ? : "??", webport, (long) gettid_BM (),
                elapsedtime_BM ());
  if (webhost && webhost[0])
    {
      onion_set_hostname (myonion_BM, webhost);
      char *lastcolon = strrchr (onion_web_base_BM, ':');
      if (lastcolon && isdigit (lastcolon[1]))
        onion_set_port (myonion_BM, lastcolon + 1);
      char *webrootpath = NULL;
      if (asprintf (&webrootpath, "%s/webroot/", bismon_directory) < 0
          || !webrootpath || !webrootpath[0]
          || access (webrootpath, R_OK | X_OK))
        FATAL_BM ("failed to get or access webroot/ path - %m");
      onion_handler *filehdl = onion_handler_export_local_new (webrootpath);
      onion_handler *customhdl =
        onion_handler_new (custom_onion_handler_BM, NULL, NULL);
      if (!filehdl)
        FATAL_BM ("failed to get onion webroot handler for %s", webrootpath);
      onion_set_root_handler (myonion_BM, customhdl);
      DBGPRINTF_BM ("run_onionweb after set root handler filehdl@%p",
                    filehdl);
      onion_handler_add (customhdl, filehdl);
      ///
      /// create the command pipe
      {
        int piparr[2] = { -1, -1 };
        if (pipe2 (piparr, O_CLOEXEC | O_NONBLOCK))
          FATAL_BM ("run_onionweb pipe failure for the command pipe - %m");
        cmdpipe_rd_BM = piparr[0];
        cmdpipe_wr_BM = piparr[1];
        DBGPRINTF_BM
          ("run_onionweb before onion_listen cmdpiprd#%d cmdpipwr#%d",
           cmdpipe_rd_BM, cmdpipe_wr_BM);
      }
      ///
      if (onion_anon_web_session_BM && *onion_anon_web_session_BM)
        create_anonymous_web_session_BM ();
      /// listen to HTTP, in other threads
      int err = onion_listen (myonion_BM);      // since detached, returns now
      DBGPRINTF_BM ("run_onionweb after onion_listen err=%d", err);
      if (err)
        FATAL_BM ("failed to do onion_listen (err#%d / %s)", err,
                  strerror (err));
      ///
      /// should add our event loop, at least related to queued processes
      /// (and their output pipes), to SIGCHLD and SIGTERM + SIGQUIT
      /// see https://groups.google.com/a/coralbits.com/d/msg/onion-dev/m-wH-BY2MA0/QJqLNcHvAAAJ
      /// and https://groups.google.com/a/coralbits.com/d/msg/onion-dev/ImjNf1EIp68/R37DW3mZAAAJ
      if (bismon_has_gui_BM ())
        {
          INFOPRINTF_BM
            ("run_onionweb dont run web_plain_event_loop because we have GTK GUI");
        }
      else
        {
          INFOPRINTF_BM ("run_onionweb runs web_plain_event_loop");
          web_is_running_BM = true;
          web_plain_event_loop_BM ();
          web_is_running_BM = false;
          INFOPRINTF_BM ("run_onionweb ended web_plain_event_loop");
        }
    }
}                               /* end run_onionweb_BM */

////////////////////////////////////////////////////////////////
static void dict_query_visitor_bm (void *data, const char *key,
                                   const void *value, int flags);

char *
percent_encode_onion_query_args_BM (onion_request * req)
{
  char *res = NULL;
  if (!req)
    return NULL;
  onion_dict *odic = onion_request_get_query_dict (req);
  if (!odic)
    return NULL;
  size_t bufsiz = 128;
  char *buf = calloc (bufsiz, 1);
  if (!buf)
    FATAL_BM ("percent_encode_onion_query_args_BM failed to calloc %zd",
              bufsiz);
  FILE *fil = open_memstream (&buf, &bufsiz);
  if (!fil)
    FATAL_BM ("percent_encode_onion_query_args_BM failed to open_memstream");
  onion_dict_lock_read (odic);
  onion_dict_preorder (odic, dict_query_visitor_bm, fil);
  onion_dict_unlock (odic);
  fflush (fil);
  long ln = ftell (fil);
  fclose (fil);
  res = strndup (buf, ln);
  free (buf), buf = NULL;
  return res;
}                               /* end percent_encode_onion_query_args_BM */

void
dict_query_visitor_bm (void *data, const char *key, const void *value,
                       int flags)
{
  FILE *fil = (FILE *) data;
  ASSERT_BM (flags == 0);
  ASSERT_BM (fil != NULL);
  if (ftell (fil) > 0)
    fputc ('&', fil);
  for (const char *pc = key; *pc; pc++)
    {
      if (isalnum (*pc) || *pc == '-' || *pc == '_' || *pc == '.'
          || *pc == '~')
        fputc (*pc, fil);
      else
        fprintf (fil, "%%%02x", ((unsigned) (*pc)) & 0xff);
    }
  fputc ('=', fil);
  for (const char *pc = (const char *)value; *pc; pc++)
    {
      if (isalnum (*pc) || *pc == '-' || *pc == '_' || *pc == '.'
          || *pc == '~')
        fputc (*pc, fil);
      else
        fprintf (fil, "%%%02x", ((unsigned) (*pc)) & 0xff);
    }
}                               /* end dict_query_visitor_bm */

////////////////
// GC support for websessiondata
void
websessiondatagcmark_BM (struct garbcoll_stBM *gc,
                         struct websessiondata_stBM *ws,
                         objectval_tyBM * fromob, int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (valtype_BM ((value_tyBM) ws) == typayl_websession_BM);
  ASSERT_BM (!fromob || isobject_BM (fromob));
  ASSERT_BM (ws->websess_magic == BISMONION_WEBSESS_MAGIC);
  ASSERT_BM (depth >= 0);
  ASSERT_BM (!fromob || !ws->websess_ownobj || ws->websess_ownobj == fromob);
  uint8_t oldmark = ((typedhead_tyBM *) ws)->hgc;
  if (oldmark)
    return;
  ((typedhead_tyBM *) ws)->hgc = MARKGC_BM;
  if (ws->websess_ownobj)
    gcobjmark_BM (gc, ws->websess_ownobj);
  if (ws->websess_contribob)
    gcobjmark_BM (gc, ws->websess_contribob);
  if (ws->websess_datav)
    EXTENDEDGCPROC_BM (gc, ws->websess_datav, fromob, depth + 1);
  gc->gc_nbmarks++;
}                               /* end websessiondatagcmark_BM */


void
websessiondatagcdestroy_BM (struct garbcoll_stBM *gc,
                            struct websessiondata_stBM *ws)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (valtype_BM ((value_tyBM) ws) == typayl_websession_BM);
  ASSERT_BM (ws->websess_magic == BISMONION_WEBSESS_MAGIC);
  if (ws->websess_ownobj)
    {
      objectval_tyBM *ownerob = ws->websess_ownobj;
      ws->websess_ownobj = NULL;
      objlock_BM (ownerob);
      if (objpayload_BM (ownerob) == (extendedval_tyBM) ws)
        objclearpayload_BM (ownerob);   /// this calls websessiondelete_BM...
      objunlock_BM (ownerob);
    };
  if (ws->websess_websocket)
    {
      onion_websocket *websock = ws->websess_websocket;
      ws->websess_websocket = NULL;
      onion_websocket_free (websock);
    };
  memset ((void *) ws, 0, sizeof (*ws));
  free (ws);
  gc->gc_freedbytes += sizeof (*ws);
}                               /* end  websessiondatagcdestroy_BM */


void
websessiondatagckeep_BM (struct garbcoll_stBM *gc,
                         struct websessiondata_stBM *ws)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (valtype_BM ((value_tyBM) ws) == typayl_websession_BM);
  ASSERT_BM (ws->websess_magic == BISMONION_WEBSESS_MAGIC);
  gc->gc_keptbytes += sizeof (*ws);
}                               /* end websessiondatagckeep_BM */



////////////////
// GC support for webexchangedata

void
webexchangedatagcmark_BM (struct garbcoll_stBM *gc,
                          struct webexchangedata_stBM *wex,
                          objectval_tyBM * fromob, int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (valtype_BM ((value_tyBM) wex) == typayl_webexchange_BM);
  ASSERT_BM (wex->webx_magic == BISMONION_WEBX_MAGIC);
  ASSERT_BM (!fromob || isobject_BM (fromob));
  ASSERT_BM (depth >= 0);
  ASSERT_BM (!fromob || !wex->webx_ownobj || wex->webx_ownobj == fromob);
  if (wex->webx_ownobj)
    gcobjmark_BM (gc, wex->webx_ownobj);
  if (wex->webx_sessobj)
    gcobjmark_BM (gc, wex->webx_sessobj);
  if (wex->webx_datav)
    EXTENDEDGCPROC_BM (gc, wex->webx_datav, fromob, depth + 1);
}                               /* end webexchangedatagcmark_BM */


void
webexchangedatagcdestroy_BM (struct garbcoll_stBM *gc,
                             struct webexchangedata_stBM *wex)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (valtype_BM ((value_tyBM) wex) == typayl_webexchange_BM);
  ASSERT_BM (wex->webx_magic == BISMONION_WEBX_MAGIC);
  if (wex->webx_requ && wex->webx_resp && wex->webx_ownobj)
    {
      DBGPRINTF_BM ("webexchangedatagcdestroy_BM for owner %s",
                    objectdbg_BM (wex->webx_ownobj));
      onion_response_flush (wex->webx_resp);
    }
  if (wex->webx_ownobj)
    {
      objectval_tyBM *ownerob = wex->webx_ownobj;
      wex->webx_ownobj = NULL;
      objlock_BM (ownerob);
      if (objpayload_BM (ownerob) == (extendedval_tyBM) wex)
        objclearpayload_BM (ownerob);   /// this calls webexchangedelete_BM
      objunlock_BM (ownerob);
    };
  if (wex->webx_requ)
    {
      onion_request *oreq = wex->webx_requ;
      wex->webx_requ = NULL;
      onion_request_free (oreq);
    };
  if (wex->webx_resp)
    {
      onion_response *oresp = wex->webx_resp;
      wex->webx_resp = NULL;
      onion_response_free (oresp);
    }
  memset ((void *) wex, 0, sizeof (*wex));
  free (wex);
  gc->gc_freedbytes += sizeof (*wex);
}                               /* end webexchangedatagcdestroy_BM */


void
webexchangedatagckeep_BM (struct garbcoll_stBM *gc,
                          struct webexchangedata_stBM *wex)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (valtype_BM ((value_tyBM) wex) == typayl_webexchange_BM);
  ASSERT_BM (wex->webx_magic == BISMONION_WEBX_MAGIC);
  gc->gc_keptbytes += sizeof (*wex);
}                               /* end webexchangedatagckeep_BM */


/* delete functions are called by deleteobjectpayload_BM for
   objclearpayload_BM & objputpayload_BM */
void
websessiondelete_BM (objectval_tyBM * ownobj, struct websessiondata_stBM *wsd)
{
  objectval_tyBM *k_websession_object = BMK_56KY6TzyCU5_12De0mHE48M;
  objectval_tyBM *k_websession_dict_object = BMK_2HGGdFqLH2E_8HktHZxdBd8;
  if (wsd->websess_magic != BISMONION_WEBSESS_MAGIC)
    {
      // this should not happen, unless the same object is deleted twice...
      WARNPRINTF_BM ("deleting websession object %s with invalid magic %u",
                     objectdbg_BM (ownobj), wsd->websess_magic);
      DBGBACKTRACEPRINTF_BM
        ("websession object %s with invalid magic %u deletion",
         objectdbg_BM (ownobj), wsd->websess_magic);
      return;
    }
  WEAKASSERT_BM (wsd->websess_ownobj == ownobj);
  // websessions are rare enough, so we can inform about their deletion
  INFOPRINTF_BM ("deleting websession %s", objectdbg_BM (ownobj));
  {
    char cookiebuf[64];
    memset (cookiebuf, 0, sizeof (cookiebuf));
    char sessidbuf[32];
    memset (sessidbuf, 0, sizeof (sessidbuf));
    idtocbuf32_BM (objid_BM (ownobj), sessidbuf);
    snprintf (cookiebuf, sizeof (cookiebuf), "n%06dR%dt%do%s",
              wsd->websess_rank, wsd->websess_rand1,
              wsd->websess_rand2, sessidbuf);
    unsigned cookielen = strlen (cookiebuf);
    ASSERT_BM (cookielen < sizeof (cookiebuf) - 4);
    DBGPRINTF_BM ("websessiondelete: ownobj %s cookiebuf %s",
                  objectdbg_BM (ownobj), cookiebuf);
    /** Tricky abstraction violation: 

	Since websessiondelete_BM could be called from inside the
	garbage collector, we cannot allocate here any string value
	for the key. But for `the_web_sessions` we know that the key
	are cookies.  So we allocate a string-like value on the stack,
	only for the purpose of removing it from that
	`the_web_sessions` object.

	When we change our garbage collector, this code should be
	updated accordingly.
     **/
    struct
    {
      stringval_tyBM sv;
      char space[sizeof (cookiebuf) + 16];
    }
    stringlike;
    memset (&stringlike, 0, sizeof (stringlike));
    hash_tyBM h = stringhash_BM (cookiebuf);
    ((typedhead_tyBM *) (&stringlike.sv))->htyp = tyString_BM;
    ((typedhead_tyBM *) (&stringlike.sv))->hash = h;
    ((typedsize_tyBM *) (&stringlike.sv))->size = cookielen;
    /// the copy below "overflows" on purpose into stringlike.space
    strcpy (stringlike.sv.strv_bytes, cookiebuf);
    ASSERT_BM (stringlike.space[0] != (char) 0);
    ASSERT_BM (strlen (stringlike.space) < sizeof (stringlike.space) - 4);
    objlock_BM (BMP_the_web_sessions);
    if (objclass_BM (BMP_the_web_sessions) != k_websession_dict_object)
      FATAL_BM ("websessiondelete: the_web_sessions is broken,"
                " should be of websession_dict_object class but is of %s",
                objectdbg_BM (objclass_BM (BMP_the_web_sessions)));
    if (!objhasdictpayl_BM (BMP_the_web_sessions))
      FATAL_BM ("websessiondelete: the_web_sessions is broken,"
                " it has no dictionnary payload - for web BISMONCOOKIE-s");
    objdictremovepayl_BM (BMP_the_web_sessions,
                          ((const stringval_tyBM *) &stringlike));
    objunlock_BM (BMP_the_web_sessions);
  }
  wsd->websess_magic = 0;
  onion_websocket *wsock = wsd->websess_websocket;
  wsd->websess_websocket = NULL;
  if (wsock)
    {
      // see also https://tools.ietf.org/html/rfc6455
      onion_websocket_close (wsock, "BISMONCLOSE");     // not sure
      onion_websocket_free (wsock);
    }
}                               /* end websessiondelete_BM */



void
webexchangedelete_BM (objectval_tyBM * ownobj,
                      struct webexchangedata_stBM *wex)
{
  if (wex->webx_magic != BISMONION_WEBX_MAGIC)
    {
      // this should not happen, unless the same object is deleted twice...
      WARNPRINTF_BM ("deleting webexchange object %s with invalid magic %u",
                     objectdbg_BM (ownobj), wex->webx_magic);
      DBGBACKTRACEPRINTF_BM
        ("webexchange object %s with invalid magic %u deletion",
         objectdbg_BM (ownobj), wex->webx_magic);
      return;
    }
  WEAKASSERT_BM (wex->webx_ownobj == ownobj);
  DBGPRINTF_BM ("webexchangedelete ownobj %s", objectdbg_BM (ownobj));
  {
    objlock_BM (ownobj);
    if (wex->webx_requ && wex->webx_resp && wex->webx_ownobj)
      {
        DBGPRINTF_BM ("webexchangedelete flush for owner %s",
                      objectdbg_BM (wex->webx_ownobj));
        onion_response_flush (wex->webx_resp);
      }
    if (ownobj->ob_payl == wex)
      ownobj->ob_payl = NULL;
    wex->webx_ownobj = NULL;
    if (wex->webx_sbuf.sbuf_size > 0)
      {
        wex->webx_sbuf.sbuf_curp = NULL;
        wex->webx_sbuf.sbuf_lastnl = NULL;
        wex->webx_sbuf.sbuf_size = 0;
        wex->webx_sbuf.sbuf_indent = 0;
        free (wex->webx_sbuf.sbuf_dbuf), wex->webx_sbuf.sbuf_dbuf = NULL;
      }
    if (wex->webx_requ)
      {
        onion_request *oreq = wex->webx_requ;
        wex->webx_requ = NULL;
        onion_request_free (oreq);
      };
    if (wex->webx_resp)
      {
        onion_response *oresp = wex->webx_resp;
        wex->webx_resp = NULL;
        onion_response_free (oresp);
      }
    wex->webx_magic = 0;
    objunlock_BM (ownobj);
  }
}                               /* end webexchangedelete_BM */




onion_connection_status
custom_onion_handler_BM (void *clientdata,
                         onion_request * req, onion_response * resp)
{
  onion_connection_status result = OCS_NOT_PROCESSED;
  objectval_tyBM *k_custom_onion_handler = BMK_5C5Dfd8eVkR_3306NWk09Bn;
  objectval_tyBM *k_websession_dict_object = BMK_2HGGdFqLH2E_8HktHZxdBd8;
  LOCALFRAME_BM ( /*prev: */ NULL, /*descr: */ k_custom_onion_handler,
                 objectval_tyBM * sessionob;
    );
  while (agenda_need_gc_BM ())
    {
      DBGPRINTF_BM ("custom_onion_handler need GC");
      agenda_wait_gc_BM ();
    }
  const char *reqpath = onion_request_get_path (req);
  unsigned reqflags = onion_request_get_flags (req);
  unsigned reqmeth = (reqflags & OR_METHODS);
  const char *bcookie = onion_request_get_cookie (req, "BISMONCOOKIE");
  char dbgmethbuf[16];
  DBGPRINTF_BM ("custom_onion_handler reqpath '%s' reqflags %#x:%s bcookie %s", //
                reqpath, reqflags,      //
                onion_request_methods[reqmeth], bcookie ? bcookie : "*none*");
  if (!strcmp (reqpath, "_login") || !strcmp (reqpath, "/_login"))
    {
      DBGPRINTF_BM ("custom_onion_handler login page reqpath %s", reqpath);
      return login_onion_handler_BM (clientdata, req, resp);
    }
  // for some reason, I can't make the webroot/ work reliably with this.
  // so I special-case when the request corresponds to an existing file path
  // but for safety I don't do that for any URL containing /. or ..
  if (strlen (reqpath) > 2
      && !strstr (reqpath, "/.") && !strstr (reqpath, ".."))
    {
      char *fipath = NULL;
      if (asprintf (&fipath, "%s/webroot/%s", bismon_directory, reqpath) > 0
          && fipath && !access (fipath, R_OK))
        {
          DBGPRINTF_BM ("custom_onion_handler found fipath %s", fipath);
          free (fipath), fipath = NULL;
          return OCS_NOT_PROCESSED;

        }
    }
  register_onion_thread_stack_BM (CURFRAME_BM);
  bool goodcookie = false;
  {
    unsigned cookrank = 0;
    uint32_t cookrand1 = 0, cookrand2 = 0;
    int cookposoid = -1;
    rawid_tyBM cookoid = { 0, 0 };
    const char *endcookie = NULL;
    int blencookie = bcookie ? strlen (bcookie) : 0;
    char oidbuf[32];
    if (blencookie > BISMONION_WEBSESS_SUFLEN / 2
        && sscanf (bcookie, "n%uR%ut%uo%n", &cookrank, &cookrand1,
                   &cookrand2, &cookposoid) >= 3 && cookposoid > 4
        && bcookie[cookposoid] == '_' && isdigit (bcookie[cookposoid + 1])
        && ((cookoid = parse_rawid_BM (bcookie + cookposoid, &endcookie)),
            validid_BM (cookoid)) && endcookie && *endcookie == (char) 0)
      {
        memset (oidbuf, 0, sizeof (oidbuf));
        idtocbuf32_BM (cookoid, oidbuf);
        DBGPRINTF_BM
          ("custom_onion_handler reqpath '%s' good cookie %s oid %s", reqpath,
           bcookie, oidbuf);
        goodcookie = true;
      }
    else if (bcookie)
      DBGPRINTF_BM ("custom_onion_handler reqpath '%s' bad cookie %s",
                    reqpath, bcookie);
    else
      DBGPRINTF_BM ("custom_onion_handler reqpath '%s' no cookie", reqpath);

    objlock_BM (BMP_the_web_sessions);
    if (objclass_BM (BMP_the_web_sessions) != k_websession_dict_object)
      FATAL_BM
        ("the_web_sessions is broken, should be of websession_dict_object class but is of %s",
         objectdbg_BM (objclass_BM (BMP_the_web_sessions)));
    if (!objhasdictpayl_BM (BMP_the_web_sessions))
      FATAL_BM
        ("the_web_sessions is broken, it has no dictionnary payload - for web BISMONCOOKIE-s");
    DBGPRINTF_BM ("custom_onion_handler the_web_sessions keys are %s",
                  debug_outstr_value_BM ((value_tyBM) objdictnodeofkeyspayl_BM
                                         (BMP_the_web_sessions,
                                          BMP_the_web_sessions), CURFRAME_BM,
                                         0));
    if (goodcookie)
      {
        int nbsess = objdictsizepayl_BM (BMP_the_web_sessions);
        _.sessionob =
          objdictgetpayl_BM (BMP_the_web_sessions, makestring_BM (bcookie));
        DBGPRINTF_BM
          ("custom_onion_handler reqpath '%s' nbsess %d sessionob %s",
           reqpath, nbsess, objectdbg_BM (_.sessionob));
      }
    else
      _.sessionob = NULL;
    objunlock_BM (BMP_the_web_sessions);
    perhaps_suspend_for_gc_onion_thread_stack_BM (CURFRAME_BM);
    DBGPRINTF_BM ("custom_onion_handler reqpath '%s' sessionob %s",
                  reqpath, objectdbg_BM (_.sessionob));
    if (!_.sessionob)
      goodcookie = false;
    else if (!equalid_BM (cookoid, objid_BM (_.sessionob)))
      {
        char cookoidbuf[32];
        memset (cookoidbuf, 0, sizeof (cookoidbuf));
        idtocbuf32_BM (cookoid, cookoidbuf);
        DBGPRINTF_BM ("custom_onion_handler bad cookoid %s want sessionob %s",
                      cookoidbuf, objectdbg_BM (_.sessionob));
        goodcookie = false;
      }
    if (goodcookie)
      {
        DBGPRINTF_BM ("custom_onion_handle good cookie %s sessionob %s",
                      bcookie, objectdbg_BM (_.sessionob));
        objlock_BM (_.sessionob);
        if (valtype_BM (objpayload_BM (_.sessionob)) != typayl_websession_BM)
          {
            DBGPRINTF_BM
              ("custom_onion_handle bad sessionob %s of payload@%p of type#%d %s",
               objectdbg_BM (_.sessionob), objpayload_BM (_.sessionob),
               valtype_BM (objpayload_BM (_.sessionob)),
               typestring_BM (valtype_BM (objpayload_BM (_.sessionob))));
            goodcookie = false;
          }
        else
          {
            struct websessiondata_stBM *ws =
              (struct websessiondata_stBM *) objpayload_BM (_.sessionob);
            ASSERT_BM (ws != NULL
                       && ws->websess_magic == BISMONION_WEBSESS_MAGIC);
            if (ws->websess_ownobj != _.sessionob)
              goodcookie = false;
            else
              {
                if (ws->websess_rank != cookrank)
                  goodcookie = false;
                else if (ws->websess_rand1 != cookrand1)
                  goodcookie = false;
                else if (ws->websess_rand2 != cookrand2)
                  goodcookie = false;
              }
            objunlock_BM (_.sessionob);
          }
      }
    DBGPRINTF_BM ("custom_onion_handle goodcookie %s",
                  goodcookie ? "true" : "false");
    if (!goodcookie)
      _.sessionob = false;
  }
  DBGPRINTF_BM ("custom_onion_handle sessionob %s reqpath '%s'",
                objectdbg_BM (_.sessionob), reqpath);
  if (!_.sessionob)
    {
      if (reqmeth == OR_GET || reqmeth == OR_HEAD)
        {                       // no session for a GET or HEAD request
          char pidbuf[16];
          snprintf (pidbuf, sizeof (pidbuf), "%d", (int) getpid ());
          time_t nowt = 0;
          time (&nowt);
          struct tm nowtm;
          char nowbuf[64];
          memset (nowbuf, 0, sizeof (nowbuf));
          memset (&nowtm, 0, sizeof (nowtm));
          localtime_r (&nowt, &nowtm);
          strftime (nowbuf, sizeof (nowbuf), "%c %Z", &nowtm);
          // send a fresh login form, using login_ONIONBM_thtml(onion_dict *context, onion_response *res)
          onion_dict *ctxdic = onion_dict_new ();
          if (onion_request_get_query_dict (req) != NULL)
            {
              char *locstr = NULL;
              char *querystr = percent_encode_onion_query_args_BM (req);
              if (querystr && querystr[0])
                asprintf (&locstr, "%s?%s",
                          (reqpath && reqpath[0]) ? reqpath : "/", querystr);
              else
                locstr = strdup ((reqpath && reqpath[0]) ? reqpath : "/");
              DBGPRINTF_BM ("custom_onion_handle locstr=%s", locstr);
              free (querystr), querystr = NULL;
              if (!locstr)
                FATAL_BM ("custom_onion_handle asprintf querydict failed");
              onion_dict_add (ctxdic, "origpath", locstr, OD_DUP_VALUE);
              DBGPRINTF_BM ("custom_onion_handle locstr=%s", locstr);
              free (locstr), locstr = NULL;
            }
          else
            {
              onion_dict_add (ctxdic, "origpath",
                              (reqpath
                               && reqpath[0]) ? reqpath : "/", OD_DUP_VALUE);
            }
          onion_dict_add (ctxdic, "host", myhostname_BM, OD_DUP_VALUE);
          onion_dict_add (ctxdic, "pid", pidbuf, OD_DUP_VALUE);
          onion_dict_add (ctxdic, "extra", "initial login", OD_DUP_VALUE);
          onion_dict_add (ctxdic, "buildtime", bismon_timestamp,
                          OD_DUP_VALUE);
          onion_dict_add (ctxdic, "lastgitcommit", bismon_lastgitcommit,
                          OD_DUP_VALUE);
          onion_dict_add (ctxdic, "checksum", bismon_checksum, OD_DUP_VALUE);
          onion_dict_add (ctxdic, "gentime", nowbuf, OD_DUP_VALUE);
          login_ONIONBM_thtml (ctxdic, resp);
          onion_dict_free (ctxdic);
          result = OCS_PROCESSED;
          unregister_onion_thread_stack_BM (CURFRAME_BM);
          return result;
        }
      else                      // no session for a POST or other (non-GET, non-HEAD) request
        {
          // deny the request so return OCS_FORBIDDEN; we could use
          // onion_server_set_internal_error_handler to make the error
          // HTML page sexier
          DBGPRINTF_BM
            ("onion request to '%s' which is not GET or HEAD without valid cookie",
             reqpath);
          result = OCS_FORBIDDEN;
          unregister_onion_thread_stack_BM (CURFRAME_BM);
          return result;
        }
    }                           /* end if !_.sessionob */
  else
    {
      // got sessionob, should process the request by making some webexchange
      bool posthttp = false;
      if ((reqmeth == OR_GET) || (reqmeth == OR_HEAD))
        posthttp = false;
      else if (reqmeth == OR_POST)
        posthttp = true;
      else
        {
          WARNPRINTF_BM ("custom_onion_handler unexpected method "      //
                         " reqpath '%s' reqflags %#x:%s sessionob %s",  //
                         reqpath, reqflags,     //
                         ((reqmeth == OR_GET) ? "GET"   //
                          : (reqmeth == OR_HEAD) ? "HEAD"       //
                          : (reqmeth == OR_POST) ? "POST"       //
                          : (reqmeth == OR_OPTIONS) ? "OPTIONS" //
                          : (reqmeth == OR_PROPFIND) ? "PROPFIND"       //
                          : (snprintf (dbgmethbuf, sizeof (dbgmethbuf), ///
                                       "meth#%d", reqmeth), dbgmethbuf)),
                         objectdbg_BM (_.sessionob));
          result = OCS_NOT_IMPLEMENTED;
          unregister_onion_thread_stack_BM (CURFRAME_BM);
          return result;
        }
      if ((!strcmp (reqpath, "/_websocket")
           || !strcmp (reqpath, "_websocket")) && !posthttp)
        {
          struct websessiondata_stBM *wsess = NULL;
          onion_websocket *wsock = NULL;
          DBGPRINTF_BM
            ("custom_onion_handler sesswebsocket '%s' for sessionob %s",
             reqpath, objectdbg_BM (_.sessionob));

          objlock_BM (_.sessionob);
          wsess = objgetwebsessionpayl_BM (_.sessionob);
          if (wsess)
            {
              wsock = wsess->websess_websocket;
              if (!wsock)
                {
                  wsock = onion_websocket_new (req, resp);
                  wsess->websess_websocket = wsock;
                  onion_websocket_set_userdata (wsock, wsess,   /*no freeing: */
                                                NULL);
                  DBGPRINTF_BM
                    ("custom_onion_handler sesswebsocket '%s' for sessionob %s new wsock @%p",
                     reqpath, objectdbg_BM (_.sessionob), wsock);
                  onion_websocket_set_callback (wsock,
                                                websocket_onion_handler_BM);
                }
              else
                DBGPRINTF_BM
                  ("custom_onion_handler sesswebsocket '%s' for sessionob %s already has wsock@%p",
                   reqpath, objectdbg_BM (_.sessionob), wsock);
            }
          objunlock_BM (_.sessionob);
          if (wsock)
            {
              result = OCS_WEBSOCKET;
              unregister_onion_thread_stack_BM (CURFRAME_BM);
              return result;
            }
          else
            {
              DBGPRINTF_BM ("onion no websocket for '%s'", reqpath);
              result = OCS_FORBIDDEN;
              unregister_onion_thread_stack_BM (CURFRAME_BM);
              return result;
            }
        }                       /* end if _websocket */
      if (strstr (reqpath, "/.") || strstr (reqpath, ".."))
        {
          DBGPRINTF_BM ("onion request to invalid '%s'", reqpath);
          result = OCS_FORBIDDEN;
          unregister_onion_thread_stack_BM (CURFRAME_BM);
          return result;
        }
      result = do_dynamic_onion_BM (_.sessionob, reqpath, posthttp, req, resp,
                                    CURFRAME_BM);
      unregister_onion_thread_stack_BM (CURFRAME_BM);
      return result;
    }
  DBGPRINTF_BM ("end custom_onion_handler reqpath '%s' reqflags %#x:%s bcookie %s",     //
                reqpath, reqflags,      //
                onion_request_methods[reqmeth], bcookie ? bcookie : "*none*");
  result = OCS_NOT_PROCESSED;
  unregister_onion_thread_stack_BM (CURFRAME_BM);
  return result;
}                               /* end custom_onion_handler_BM */



onion_connection_status
login_onion_handler_BM (void *_clientdata __attribute__((unused)),
                        onion_request * req, onion_response * resp)
{
  objectval_tyBM *k_login_onion_handler = BMK_8qHowkDvzRL_03sltCgsDN2;
  LOCALFRAME_BM ( /*prev: */ NULL, /*descr: */ k_login_onion_handler,
                 objectval_tyBM * contribob;
    );
  const char *reqpath = onion_request_get_path (req);
  unsigned reqflags = onion_request_get_flags (req);
  unsigned reqmeth = (reqflags & OR_METHODS);
  const char *bcookie = onion_request_get_cookie (req, "BISMONCOOKIE");
  char dbgmethbuf[16];
  DBGPRINTF_BM ("login_onion_handler reqpath '%s' fullpath '%s' reqflags %#x:%s bcookie %s",    //
                reqpath, onion_request_get_fullpath (req), reqflags,    //
                onion_request_methods[reqmeth], bcookie ? bcookie : "*none*");
  if (reqmeth == OR_POST)
    {
      // see the login form in login_ONIONBM.thtml template
      const char *formorigpath = onion_request_get_post (req, "origpath");
      const char *formuser = onion_request_get_post (req, "user");
      const char *formpassword = onion_request_get_post (req, "password");
      const char *formdologin = onion_request_get_post (req, "dologin");
      const char *formdoforgot = onion_request_get_post (req, "doforgot");
      bool good = false;
      DBGPRINTF_BM ("login_onion_handler POST form origpath %s,"
                    " user %s, password %s, dologin %s, doforgot %s",
                    formorigpath ? : "*no-origpath*",
                    formuser ? : "*no-user*",
                    formpassword ? : "*no-password*",
                    formdologin ? : "*no-dologin*",
                    formdoforgot ? : "*no-doforgot*");
      if (formuser && formpassword && formdologin && formorigpath)
        {
          _.contribob = find_contributor_BM (formuser, CURFRAME_BM);
          DBGPRINTF_BM ("login_onion_handler POST contribob %s",
                        objectdbg_BM (_.contribob));
          if (_.contribob)
            {
              good =
                check_contributor_password_BM (_.contribob, formpassword,
                                               CURFRAME_BM);
              DBGPRINTF_BM ("login_onion_handler POST contribob %s "
                            "password '%s' is %s",
                            objectdbg_BM (_.contribob), formpassword,
                            good ? "good" : "bad");
            }
          else
            {
              DBGPRINTF_BM
                ("login_onion_handler POST no contributor '%s' found",
                 formuser);
              good = false;
            }
          if (good)
            {
              DBGPRINTF_BM ("login_onion_handler POST good");
              return
                do_login_redirect_onion_BM (_.contribob,
                                            formorigpath ? : "/",
                                            req, resp, CURFRAME_BM);
            }
          else
            {
              time_t nowt = 0;
              time (&nowt);
              struct tm nowtm;
              char nowbuf[64];
              char pidbuf[16];
              memset (nowbuf, 0, sizeof (nowbuf));
              memset (pidbuf, 0, sizeof (pidbuf));
              memset (&nowtm, 0, sizeof (nowtm));
              snprintf (pidbuf, sizeof (pidbuf), "%d", (int) getpid ());
              localtime_r (&nowt, &nowtm);
              strftime (nowbuf, sizeof (nowbuf), "%c %Z", &nowtm);
              onion_dict *ctxdic = onion_dict_new ();
              {
                const char *origpath = (reqpath
                                        && reqpath[0]) ? reqpath : "/";
                if (reqpath && !strcmp (reqpath, "_login"))
                  {
                    if (formorigpath)
                      origpath = formorigpath;
                  }
                onion_dict_add (ctxdic, "origpath", origpath, OD_DUP_VALUE);
              }
              onion_dict_add (ctxdic, "host", myhostname_BM, OD_DUP_VALUE);
              onion_dict_add (ctxdic, "pid", pidbuf, OD_DUP_VALUE);
              onion_dict_add (ctxdic, "extra", "Invalid user or password.",
                              OD_DUP_VALUE);
              onion_dict_add (ctxdic, "buildtime", bismon_timestamp,
                              OD_DUP_VALUE);
              onion_dict_add (ctxdic, "lastgitcommit", bismon_lastgitcommit,
                              OD_DUP_VALUE);
              onion_dict_add (ctxdic, "gentime", nowbuf, OD_DUP_VALUE);
              onion_dict_add (ctxdic, "checksum", bismon_checksum,
                              OD_DUP_VALUE);
              onion_response_set_code (resp, HTTP_UNAUTHORIZED);
              DBGPRINTF_BM ("login_onion_handler POST unauthorized");
              login_ONIONBM_thtml (ctxdic, resp);
              onion_dict_free (ctxdic);
              return OCS_PROCESSED;
            }
        }
      else if (formuser && formdoforgot)
        {
          DBGPRINTF_BM
            ("login_ONIONBM_thtml doforgot %s user '%s' unimplemented",
             formdoforgot, formuser);
          return do_forgot_onion_BM (formuser, req, resp);
        }
    }
  /// temporary
  WARNPRINTF_BM ("login_onion_handler incomplete");
#warning login_onion_handler_BM incomplete
  return OCS_FORBIDDEN;
}                               /* end login_onion_handler_BM */


static onion_connection_status
do_forgot_onion_BM (const char *formuser,
                    onion_request * req, onion_response * resp)
{
  WARNPRINTF_BM ("do_forgot_onion_BM %s unimplemented", formuser);

  char *respbuf = NULL;
  size_t respsiz = 0;
  FILE *fresp = open_memstream (&respbuf, &respsiz);
  if (!fresp)
    FATAL_BM ("login_onion_handler open_memstream failure %m");
  fprintf (fresp, "<!DOCTYPE html>\n");
  fprintf (fresp,
           "<html><head><title>Bismon forgot password unimplemented</title></head>\n");
  fprintf (fresp,
           "<body><h1>Bismon <i>forgot password</i> feature unimplemented</h1>\n");
  fprintf (fresp,
           "<p>The <i>forgot password</i> feature (for user <tt>%s</tt>)"
           " is <b>not implemented</b> yet.\n", formuser);
  fprintf (fresp,
           "Sorry about that. So temporarily, use the <tt>--add-passwords</tt>"
           " program option on the Bismon server to change your password.<br/>\n"
           "See our <a href='https://github.com/bstarynk/bismon/blob/master/README.md'>"
           "README.md</a> file for more.</p>\n");
  fprintf (fresp, "<hr/>\n");
  time_t nowt = 0;
  time (&nowt);
  struct tm nowtm;
  char nowbuf[64];
  memset (nowbuf, 0, sizeof (nowbuf));
  memset (&nowtm, 0, sizeof (nowtm));
  localtime_r (&nowt, &nowtm);
  strftime (nowbuf, sizeof (nowbuf), "%c %Z", &nowtm);
  fprintf (fresp, "<p><small>generated on <i>%s</i></small></p>\n", nowbuf);
  fprintf (fresp, "</body></html>\n");
  fflush (fresp);
  long ln = ftell (fresp);
  fclose (fresp), fresp = NULL;
  onion_response_set_length (resp, ln);
  onion_response_set_code (resp, HTTP_NOT_IMPLEMENTED);
  onion_response_write (resp, respbuf, ln);
  onion_response_flush (resp);
  free (respbuf), respbuf = NULL;
  return OCS_PROCESSED;
}                               /* end do_forgot_onion_BM */



static long sessioncounter_bm;

onion_connection_status
do_login_redirect_onion_BM (objectval_tyBM * contribobarg,
                            const char *location, onion_request * req,
                            onion_response * resp,
                            struct stackframe_stBM *stkf)
{
  objectval_tyBM *k_websession_object = BMK_56KY6TzyCU5_12De0mHE48M;
  objectval_tyBM *k_websession_dict_object = BMK_2HGGdFqLH2E_8HktHZxdBd8;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * contribob;    //
                 objectval_tyBM * sessionob;    //
                 value_tyBM cookiestrv;);
  ASSERT_BM (isobject_BM (contribobarg));
  _.contribob = contribobarg;
  DBGPRINTF_BM ("do_login_redirect_onion_BM start contribob %s location '%s'",
                objectdbg_BM (_.contribob), location);
  /// create the session
  char sessidbuf[32];
  memset (sessidbuf, 0, sizeof (sessidbuf));
  _.sessionob = makeobj_BM ();
  idtocbuf32_BM (objid_BM (_.sessionob), sessidbuf);
  struct websessiondata_stBM *wsess =
    allocgcty_BM (typayl_websession_BM, sizeof (*wsess));
  wsess->websess_magic = 1;
  wsess->websess_rank = 0;
  wsess->websess_rand1 = 100 + (g_random_int () % (INT_MAX / 2));
  wsess->websess_rand2 = 105 + (g_random_int () % (INT_MAX / 2));
  wsess->websess_ownobj = _.sessionob;
  wsess->websess_contribob = _.contribob;
  wsess->websess_createtime = clocktime_BM (CLOCK_REALTIME);
  wsess->websess_expiretime =
    wsess->websess_createtime + USER_WEBSESSION_EXPIRATION_DELAY;
  objputpayload_BM (_.sessionob, wsess);
  objputclass_BM (_.sessionob, k_websession_object);
  wsess->websess_magic = BISMONION_WEBSESS_MAGIC;
  objtouchnow_BM (_.sessionob);
  /// add the session to the_web_sessions; its lock also serializes
  /// access to our sessioncounter_bm...
  {
    objlock_BM (BMP_the_web_sessions);
    // this should never happen, but it is better to check
    if (!objhasdictpayl_BM (BMP_the_web_sessions)
        || objclass_BM (BMP_the_web_sessions) != k_websession_dict_object)
      FATAL_BM ("corrupted `the_web_sessions` (of class %s)",
                objectdbg_BM (objclass_BM (BMP_the_web_sessions)));
    sessioncounter_bm++;
    wsess->websess_rank = sessioncounter_bm;
    _.cookiestrv =
      sprintfstring_BM ("n%06dR%dt%do%s", wsess->websess_rank,
                        wsess->websess_rand1, wsess->websess_rand2,
                        sessidbuf);
    DBGPRINTF_BM ("do_login_redirect_onion_BM for contribob %s,\n"
                  "... adding sessionob %s of cookie '%s'",
                  objectdbg_BM (_.contribob), objectdbg1_BM (_.sessionob),
                  bytstring_BM (_.cookiestrv));
    objdictputpayl_BM (BMP_the_web_sessions, _.cookiestrv, _.sessionob);
    objunlock_BM (BMP_the_web_sessions);
  }
  bool addedcookie =            //
    onion_response_add_cookie   //
    (resp, "BISMONCOOKIE",
     bytstring_BM (_.cookiestrv),
     (time_t) (wsess->websess_expiretime - clocktime_BM (CLOCK_REALTIME)),
     "/",
     NULL,                      /// domain
     0);
  onion_response_set_code (resp, HTTP_REDIRECT);
  onion_response_set_header (resp, "Location", location);
  DBGPRINTF_BM ("do_login_redirect_onion_BM sessionob %s addedcookie %s"
                " location %s",
                objectdbg_BM (_.sessionob),
                addedcookie ? "true" : "false", location);
  char *respbuf = NULL;
  size_t respsiz = 0;
  FILE *fresp = open_memstream (&respbuf, &respsiz);
  if (!fresp)
    FATAL_BM ("do_login_redirect_onion open_memstream failure %m");
  fprintf (fresp, "<!DOCTYPE html>\n");
  fprintf (fresp, "<html><head><title>Bismon login redirect</title>\n"
           "<meta http-equiv='refresh' content='2; URL=http://%s/%s'/>\n",
           onion_web_base_BM, location);
  fprintf (fresp, "</head>\n<body>\n");
  fprintf (fresp,
           "<h1>Bismon login redirection to <a href='http://%s/%s'>%s</a></h1>\n",
           onion_web_base_BM, location, location);
  fprintf (fresp, "<hr/>\n");
  time_t nowt = 0;
  time (&nowt);
  struct tm nowtm;
  char nowbuf[64];
  memset (nowbuf, 0, sizeof (nowbuf));
  memset (&nowtm, 0, sizeof (nowtm));
  localtime_r (&nowt, &nowtm);
  strftime (nowbuf, sizeof (nowbuf), "%c %Z", &nowtm);
  fprintf (fresp, "<p><small>generated on <i>%s</i></small></p>\n", nowbuf);
  fprintf (fresp, "</body>\n</html>\n");
  fflush (fresp);
  long ln = ftell (fresp);
  fclose (fresp), fresp = NULL;
  onion_response_set_length (resp, ln);
  onion_response_write (resp, respbuf, ln);
  onion_response_flush (resp);
  DBGPRINTF_BM ("do_login_redirect_onion_BM sessionob %s"
                " redirection to %s:\n%s\n",
                objectdbg_BM (_.sessionob), location, respbuf);
  free (respbuf), respbuf = NULL;
  DBGPRINTF_BM ("do_login_redirect_onion  sessionob %s done",
                objectdbg_BM (_.sessionob));
  return OCS_PROCESSED;
}                               /* end do_login_redirect_onion_BM */


/// The websocket messages are conventionally JSON (arbitrary JSON
/// data).  And by convention, no data flows asynchronously from
/// browser to bismon server. The websockets are only used with
/// asynchronous JSON messages from bismon to browser. For messages
/// from browser to bismon, we use AJAX techniques by convention.
/// So our WebSocket handler should just care about closing websockets.

onion_connection_status
websocket_onion_handler_BM (void *clientdata,
                            onion_websocket * ws, ssize_t data_ready_len)
{
  struct websessiondata_stBM *wsess =
    (struct websessiondata_stBM *) clientdata;
  WEAKASSERT_BM (!wsess
                 || (valtype_BM ((value_tyBM) wsess) == typayl_websession_BM
                     && wsess->websess_magic == BISMONION_WEBSESS_MAGIC));
  objectval_tyBM *ownob = wsess ? wsess->websess_ownobj : NULL;
  WEAKASSERT_BM (ws != NULL);
  DBGPRINTF_BM
    ("websocket_onion_handler_BM  start ws@%p data_ready_len=%d wsess@%p ownob %s",
     (void *) ws, (int) data_ready_len, wsess,
     wsess ? objectdbg_BM (ownob) : "?*none*?");
  if (data_ready_len > 0)
    {
      /* the websocket should not recieve data from browser; so this should never happen */
      FATAL_BM
        ("websocket_onion_handler_BM getting unexpected asynchronous data (%d bytes) from browser of session %s",
         (int) data_ready_len,
         wsess ? objectdbg_BM (wsess->websess_ownobj) : "?*none*?");
    }
  else if (data_ready_len < 0)
    {
      /* the websocket is closing, so we clear it in the session */
      DBGPRINTF_BM
        ("websocket_onion_handler_BM closing websocket ws@%p in session ownob %s",
         ws, wsess ? objectdbg_BM (ownob) : "?*none*?");
      if (ownob)
        {
          objlock_BM (ownob);
          ASSERT_BM (objpayload_BM (ownob) == wsess);
          wsess->websess_websocket = NULL;
          objunlock_BM (ownob);
        }
      /* It seems that
         https://github.com/davidmoreno/onion/blob/master/src/onion/websocket.c
         don't even use, in start of 2019, the return value of our
         websocket_onion_handler_BM */
      return OCS_CLOSE_CONNECTION;
    }
  FATAL_BM
    ("unimplemented websocket_onion_handler_BM, data_ready_len=%d, wsess own %s",
     (int) data_ready_len,
     wsess ? objectdbg_BM (wsess->websess_ownobj) : "?*none*?");
}                               /* end websocket_onion_handler_BM */



void
create_anonymous_web_session_BM (void)
{
  objectval_tyBM *k_websession_object = BMK_56KY6TzyCU5_12De0mHE48M;
  objectval_tyBM *k_websession_dict_object = BMK_2HGGdFqLH2E_8HktHZxdBd8;
  LOCALFRAME_BM ( /*prev: */ NULL, /*descr: */ NULL,
                 objectval_tyBM * sessionob;    //
                 value_tyBM cookiestrv;);
  DBGPRINTF_BM ("create_anonymous_web_session start onionanonwebsession '%s'",
                onion_anon_web_session_BM);
  // backup cookie file, if it exists
  if (!access (onion_anon_web_session_BM, R_OK))
    {
      char *backupath = NULL;
      asprintf (&backupath, "%s~", onion_anon_web_session_BM);
      if (backupath)
        {
          if (!rename (onion_anon_web_session_BM, backupath))
            INFOPRINTF_BM
              ("back-up anonymous web session cookie file: %s -> %s",
               onion_anon_web_session_BM, backupath);
          free (backupath), backupath = NULL;
        }
    }
  FILE *fil = fopen (onion_anon_web_session_BM, "w");
  if (!fil)
    FATAL_BM ("failed to fopen anonymous web session cookie file '%s' - %m",
              onion_anon_web_session_BM);
  /// create the session
  char sessidbuf[32];
  memset (sessidbuf, 0, sizeof (sessidbuf));
  _.sessionob = makeobj_BM ();
  idtocbuf32_BM (objid_BM (_.sessionob), sessidbuf);
  struct websessiondata_stBM *wsess =
    allocgcty_BM (typayl_websession_BM, sizeof (*wsess));
  wsess->websess_magic = 1;
  wsess->websess_rank = 0;
  wsess->websess_rand1 = 500 + (g_random_int () % (INT_MAX / 2));
  wsess->websess_rand2 = 305 + (g_random_int () % (INT_MAX / 2));
  wsess->websess_ownobj = _.sessionob;
  wsess->websess_contribob = NULL;
  wsess->websess_createtime = clocktime_BM (CLOCK_REALTIME);
  wsess->websess_expiretime =
    wsess->websess_createtime + ANON_WEBSESSION_EXPIRATION_DELAY;
  objputpayload_BM (_.sessionob, wsess);
  objputclass_BM (_.sessionob, k_websession_object);
  wsess->websess_magic = BISMONION_WEBSESS_MAGIC;
  objtouchnow_BM (_.sessionob);
  /// add the session to the_web_sessions; its lock also serializes
  /// access to our sessioncounter_bm...
  {
    objlock_BM (BMP_the_web_sessions);
    // this should never happen, but it is better to check
    if (!objhasdictpayl_BM (BMP_the_web_sessions)
        || objclass_BM (BMP_the_web_sessions) != k_websession_dict_object)
      FATAL_BM ("corrupted `the_web_sessions` (of class %s)",
                objectdbg_BM (objclass_BM (BMP_the_web_sessions)));
    sessioncounter_bm++;
    wsess->websess_rank = sessioncounter_bm;
    _.cookiestrv =
      sprintfstring_BM ("n%06dR%dt%do%s", wsess->websess_rank,
                        wsess->websess_rand1, wsess->websess_rand2,
                        sessidbuf);
    DBGPRINTF_BM
      ("create_anonymous_web_session adding sessionob %s of cookie '%s'",
       objectdbg_BM (_.sessionob), bytstring_BM (_.cookiestrv));
    objdictputpayl_BM (BMP_the_web_sessions, _.cookiestrv, _.sessionob);
    objunlock_BM (BMP_the_web_sessions);
  }
  fprintf (fil, "BISMONCOOKIE=%s\n", bytstring_BM (_.cookiestrv));
  fclose (fil), fil = NULL;
  INFOPRINTF_BM
    ("generated web cookie for anonymous web session in file %s for sessionob %s",
     onion_anon_web_session_BM, objectdbg_BM (_.sessionob));
}                               /* end create_anonymous_web_session_BM */



void
objwebsessionsendjsonwebsocketpayl_BM (objectval_tyBM * objarg,
                                       value_tyBM jsonarg, value_tyBM ctxtarg,
                                       struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * websessob;
                 value_tyBM jsonv; value_tyBM ctxv;);
  _.websessob = objarg;
  _.jsonv = jsonarg;
  _.ctxv = ctxtarg;
  DBGPRINTF_BM
    ("objwebsessionsendjsonwebsocketpayl start websessob %s jsonv %s ctxv %s",
     objectdbg_BM (_.websessob), OUTSTRVALUE_BM (_.jsonv),
     OUTSTRVALUE_BM (_.ctxv));
  WEAKASSERTRET_BM (objislocked_BM (_.websessob));
  struct websessiondata_stBM *wsess = objgetwebsessionpayl_BM (_.websessob);
  if (!wsess)
    {
      WARNPRINTF_BM ("bad websession object %s to send JSON on websocket",
                     objectdbg_BM (_.websessob));
      return;
    }
  WEAKASSERTRET_BM (wsess->websess_ownobj == _.websessob);
  WEAKASSERTRET_BM (wsess->websess_magic == BISMONION_WEBSESS_MAGIC);
  if (!wsess->websess_websocket)
    {
      WARNPRINTF_BM ("websession object %s without websocket",
                     objectdbg_BM (_.websessob));
      return;
    }
  json_t *js =
    jansjsonfromvalue_BM (_.jsonv, _.jsonv, _.ctxv, 0, CURFRAME_BM);
  if (!js)
    {
      WARNPRINTF_BM
        ("no JSON from value %s, context %s for websession object %s",
         OUTSTRVALUE_BM (_.jsonv), OUTSTRVALUE_BM (_.ctxv),
         objectdbg_BM (_.websessob));
      return;
    }
  char *jsonbuf = NULL;
  size_t jsonsiz = 0;
  FILE *fjson = open_memstream (&jsonbuf, &jsonsiz);
  if (!fjson)
    FATAL_BM
      ("objwebsessionsendjsonwebsocketpayl_BM websession object %s open_memstream failure %m",
       objectdbg_BM (_.websessob));
  if (json_dumpf (js, fjson, JSON_COMPACT | JSON_SORT_KEYS | JSON_ENCODE_ANY))
    FATAL_BM
      ("objwebsessionsendjsonwebsocketpayl_BM json_dumpf failure websession object %s",
       objectdbg_BM (_.websessob));
  fputc ('\n', fjson);
  fflush (fjson);
  long ln = ftell (fjson);
  DBGPRINTF_BM ("objwebsessionsendjsonwebsocketpayl_BM websessob=%s; JSON:\n"
                "%s\n//// end (%ld bytes)\n",
                objectdbg_BM (_.websessob), jsonbuf, ln);
  onion_websocket_set_opcode (wsess->websess_websocket, OWS_TEXT);
  const char *partbuf = jsonbuf;
  ssize_t remlen = ln;
  do
    {
      int wln =
        onion_websocket_write (wsess->websess_websocket, partbuf, remlen);
      if (wln < 0)
        FATAL_BM
          ("objwebsessionsendjsonwebsocketpayl_BM websocket_write failure (%m) websession object %s",
           objectdbg_BM (_.websessob));
      remlen -= wln;
      partbuf += wln;
    }
  while (remlen > 0);
}                               /* end of objwebsessionsendjsonwebsocketpayl_BM */


//////////////////////////////////////////////////////////////////////////
// lock for the web exchange count
static pthread_mutex_t webexonion_mtx_BM = PTHREAD_MUTEX_INITIALIZER;
static long webexonion_count_BM;
////////////////

static value_tyBM find_web_handler_BM (objectval_tyBM * sessionobarg,
                                       objectval_tyBM * dictobarg,
                                       onion_request * req,
                                       int depth,
                                       int *poffset,
                                       struct stackframe_stBM *stkf);


////////////////
#define WEBEXCHANGE_DELAY_BM   (debugmsg_BM?21.0:2.4)
onion_connection_status
do_dynamic_onion_BM (objectval_tyBM * sessionobarg, const char *reqpath,
                     bool postrequest,
                     onion_request * req,
                     onion_response * resp, struct stackframe_stBM *stkf)
{
  objectval_tyBM *k_no_value = BMK_7SYPOwPm7jc_2PeGiJ8uQiX;
  objectval_tyBM *k_webexchange_object = BMK_8keZiP7vbFw_1ovBXqd6a0d;
  objectval_tyBM *k_failure_bad_closure = BMK_373gFe8m21E_47xzvCGxpI9;
  objectval_tyBM *k_web_timeout = BMK_4vI7wCaySrU_0QhNU3wiwt2;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * sessionob;
                 objectval_tyBM * webexob; value_tyBM failreasonv;      //
                 value_tyBM failplacev; //
                 value_tyBM webhandlerv;        //
                 value_tyBM restpathv;  //
                 value_tyBM appresv;    //
                 value_tyBM errorv;     //
    );
  unsigned reqflags = onion_request_get_flags (req);
  unsigned reqmeth = (reqflags & OR_METHODS);
  ASSERT_BM (isobject_BM (sessionobarg));
  _.sessionob = sessionobarg;
  DBGPRINTF_BM
    ("do_dynamic_onion start sessionob %s reqpath '%s' fullreq '%s' post %s",
     objectdbg_BM (_.sessionob), reqpath, onion_request_get_fullpath (req),
     postrequest ? "true" : "false");
  _.webexob = makeobj_BM ();
  objputclass_BM (_.webexob, k_webexchange_object);
  struct webexchangedata_stBM *wexda =
    allocgcty_BM (typayl_webexchange_BM, sizeof (*wexda));
  unsigned inisizew = 8192;
  char *dbuf = malloc (inisizew * sizeof (void *));
  if (!dbuf)
    FATAL_BM ("malloc %zu bytes failed (%m)", inisizew * sizeof (void *));
  memset (dbuf, 0, inisizew * sizeof (void *));
  wexda->webx_sbuf.sbuf_indent = 0;
  wexda->webx_sbuf.sbuf_dbuf = dbuf;
  wexda->webx_sbuf.sbuf_size = inisizew * sizeof (void *);
  wexda->webx_sbuf.sbuf_curp = dbuf;
  wexda->webx_sbuf.sbuf_lastnl = NULL;
  {
    pthread_mutex_lock (&webexonion_mtx_BM);
    webexonion_count_BM++;
    wexda->webx_num = webexonion_count_BM;
    pthread_mutex_unlock (&webexonion_mtx_BM);
  }
  register_onion_thread_stack_BM (CURFRAME_BM);
  wexda->webx_ownobj = _.webexob;
  wexda->webx_sessobj = _.sessionob;
  wexda->webx_datav = NULL;
  wexda->webx_time = clocktime_BM (CLOCK_REALTIME);
  wexda->webx_requ = req;
  wexda->webx_resp = resp;
  pthread_cond_init (&wexda->webx_cond_ready, NULL);
  objputpayload_BM (_.webexob, wexda);
  objtouchnow_BM (_.webexob);
  wexda->webx_magic = BISMONION_WEBX_MAGIC;
  atomic_init (&wexda->webx_respcode, 0);
  DBGPRINTF_BM
    ("do_dynamic_onion sessionob %s reqpath '%s' post %s wexnum %d webexob %s",
     objectdbg_BM (_.sessionob), reqpath, postrequest ? "true" : "false",
     wexda->webx_num, objectdbg1_BM (_.webexob));
  int failcod = 0;
  _.failreasonv = NULL;
  _.failplacev = NULL;
  struct failurehandler_stBM *prevfailureh = curfailurehandle_BM;
  {
    struct failurelockset_stBM flockset = { };
    initialize_failurelockset_BM (&flockset, sizeof (flockset));
    LOCAL_FAILURE_HANDLE_BM (&flockset, lab_failureweb, failcod,
                             _.failreasonv, _.failplacev);
    if (failcod)
    lab_failureweb:
      {
        WARNPRINTF_BM ("do_dynamic_onion failure reqpath '%s' failcod=%d\n" ".. failreasonv %s\n" ".. failplacev %s\n", reqpath, failcod,       //
                       OUTSTRVALUE_BM (_.failreasonv),
                       OUTSTRVALUE_BM (_.failplacev));
        destroy_failurelockset_BM (&flockset);
        curfailurehandle_BM = prevfailureh;
        char *respbuf = NULL;
        size_t respsiz = 0;
        FILE *fresp = open_memstream (&respbuf, &respsiz);
        if (!fresp)
          FATAL_BM
            ("do_dynamic_onion (failure case failcode %d) open_memstream failure %m",
             failcod);
        fprintf (fresp, "<!DOCTYPE html>\n");
        fprintf (fresp, "<html><head><title>Bismon failure</title>\n");
        fprintf (fresp, "</head>\n<body>\n");
        fprintf (fresp, "<h1>Bismon failure <i>internal error</i></h1>\n");
        fprintf (fresp, "<p>Request <i>%s</i> of path '<tt>%s</tt>' <small>(full path <tt>%s</tt>...)</small>"  //
                 " <b>failed</b> <small>(webexchange <tt>%s</tt>, session <tt>%s</tt>)</small>.<br/>\n",        //
                 onion_request_methods[reqmeth], reqpath,
                 onion_request_get_fullpath (req),
                 objectdbg_BM (_.webexob), objectdbg1_BM (_.sessionob));
        fprintf (fresp, "Failure code %d<br/>Fail reason: <tt>\n", failcod);
        writefencodedhtml_BM (fresp, OUTSTRVALUE_BM (_.failreasonv), -1);
        fputs ("</tt><br/>Fail place: <tt>\n", fresp);
        writefencodedhtml_BM (fresp, OUTSTRVALUE_BM (_.failplacev), -1);
        fputs ("</tt></p>", fresp);
        time_t nowt = 0;
        time (&nowt);
        struct tm nowtm;
        char nowbuf[64];
        memset (nowbuf, 0, sizeof (nowbuf));
        memset (&nowtm, 0, sizeof (nowtm));
        localtime_r (&nowt, &nowtm);
        strftime (nowbuf, sizeof (nowbuf), "%c", &nowtm);
        fprintf (fresp,
                 "<p><small>generated at <i>%s</i> on <tt>%s</tt> pid %d</small><br/>"
                 "<small>timestamp: <tt>%s</tt>; gitcommit: <tt>%ss</tt></p>\n",
                 nowbuf, myhostname_BM, (int) getpid (),
                 bismon_timestamp, bismon_lastgitcommit);
        fprintf (fresp, "<!-- generated from %s:%d -->\n",
                 basename_BM (__FILE__), __LINE__);
        fprintf (fresp, "</body>\n</html>\n");
        fflush (fresp);
        long ln = ftell (fresp);
        fclose (fresp), fresp = NULL;
        onion_response_set_code (resp, HTTP_INTERNAL_ERROR);
        onion_response_set_length (resp, ln);
        onion_response_write (resp, respbuf, ln);
        onion_response_flush (resp);
        {
          objlock_BM (_.webexob);
          wexda->webx_resp = NULL;
          wexda->webx_requ = NULL;
          if (objgetwebexchangepayl_BM (_.webexob) == wexda)
            {
              wexda->webx_ownobj = NULL;
              // we dont clear the payload, since the old sbuf could be browsed
              //objclearpayload_BM (_.webexob);
            }
          objunlock_BM (_.webexob);
        }
        return OCS_PROCESSED;
      }
    else
      {
        int off = 0;
        int reqlen = strlen (reqpath);
        // normal case, should find the web processing closure then apply it
        DBGPRINTF_BM
          ("do_dynamic_onion normal sessionob %s reqpath '%s' post %s wexnum %d webexob %s",
           objectdbg_BM (_.sessionob), reqpath,
           postrequest ? "true" : "false", wexda->webx_num,
           objectdbg1_BM (_.webexob));
        _.webhandlerv =
          find_web_handler_BM (_.sessionob, BMP_webdict_root, req, 0, &off,
                               CURFRAME_BM);
        DBGPRINTF_BM
          ("do_dynamic_onion normal sessionob %s reqpath '%s' fullpath '%s' method %s webhandler %s",
           objectdbg_BM (_.sessionob), reqpath,
           onion_request_get_fullpath (req),
           onion_request_methods[onion_request_get_flags (req) & 0xf],
           debug_outstr_value_BM (_.webhandlerv, CURFRAME_BM, 0));

        if (!_.webhandlerv)
          PLAINFAILURE_BM (__LINE__, k_no_value, CURFRAME_BM);
        else if (!isclosure_BM (_.webhandlerv))
          {
            _.errorv =
              (value_tyBM) makenode1_BM (k_failure_bad_closure,
                                         _.webhandlerv);
            PLAINFAILURE_BM (__LINE__, _.errorv, CURFRAME_BM);
          }
        if (off < 0)
          off = 0;
        else if (off > reqlen)
          off = reqlen;
        _.restpathv = (value_tyBM) makestring_BM (reqpath + off);
        DBGPRINTF_BM ("do_dynamic_onion before apply webhandler %s restpath %s webexob %s",     //
                      debug_outstr_value_BM (_.webhandlerv, CURFRAME_BM, 0),    //
                      debug_outstr_value_BM (_.restpathv, CURFRAME_BM, 0),      //
                      objectdbg_BM (_.webexob));
        _.appresv =
          apply2_BM (_.webhandlerv, CURFRAME_BM, _.restpathv, _.webexob);
        DBGPRINTF_BM ("do_dynamic_onion after apply webhandler %s restpath %s webexob %s appres %s",    //
                      debug_outstr_value_BM (_.webhandlerv, CURFRAME_BM, 0),    //
                      debug_outstr_value_BM (_.restpathv, CURFRAME_BM, 0),      //
                      objectdbg_BM (_.webexob), //
                      debug_outstr_value_BM (_.appresv, CURFRAME_BM, 0));
        destroy_failurelockset_BM (&flockset);
        curfailurehandle_BM = prevfailureh;
      }
  }
  bool timedout = false;
  bool completed = false;
  int respcode = 0;
  const char *bytes = NULL;
  unsigned len = 0;
  char mimetype[BISMONION_MIMETYPE_SIZE];
  memset (mimetype, 0, sizeof (mimetype));
  for (;;)
    {
      ASSERT_BM (wexda->webx_magic == BISMONION_WEBX_MAGIC);
      perhaps_suspend_for_gc_onion_thread_stack_BM (CURFRAME_BM);
      objlock_BM (_.webexob);
      ASSERT_BM (objhaswebexchangepayl_BM (_.webexob));
      ASSERT_BM (objgetwebexchangepayl_BM (_.webexob) == wexda);
      struct timespec ts = { 0, 0 };
      get_realtimespec_delayedms_BM (&ts, 200);
      pthread_cond_timedwait (&wexda->webx_cond_ready, &_.webexob->ob_mutex,
                              &ts);
      respcode = atomic_load (&wexda->webx_respcode);
      timedout =
        clocktime_BM (CLOCK_REALTIME) >
        wexda->webx_time + WEBEXCHANGE_DELAY_BM;
      completed = respcode > 0;
      if (completed)
        {
          bytes = objstrbufferbytespayl_BM (_.webexob);
          len = objstrbufferlengthpayl_BM (_.webexob);
          strncpy (mimetype, wexda->webx_mimetype,
                   BISMONION_MIMETYPE_SIZE - 1);
        }
      objunlock_BM (_.webexob);
      if (completed)
        break;
      if (timedout)
        {
          DBGPRINTF_BM ("do_dynamic_onion webexob %s timedout",
                        objectdbg_BM (_.webexob));
          break;
        }
    }
  if (timedout)
    {
      char *respbuf = NULL;
      size_t respsiz = 0;
      FILE *fresp = open_memstream (&respbuf, &respsiz);
      if (!fresp)
        FATAL_BM ("do_dynamic_onion (timedout) open_memstream failure %m");
      fprintf (fresp, "<!DOCTYPE html>\n");
      fprintf (fresp, "<html><head><title>Bismon timeout</title>\n");
      fprintf (fresp, "</head>\n<body>\n");
      fprintf (fresp, "<h1>Bismon timeout <i>internal error</i></h1>\n");
      fprintf (fresp, "<p>Request <i>%s</i> of path '<tt>%s</tt>' <small>(full path <tt>%s</tt> ...)</small>"   //
               " <b>timed out</b>" " <small>(webexchange <tt>%s</tt>, session <tt>%s</tt>, delay %.3f s)</small>.<br/>\n",      //
               onion_request_methods[reqmeth],
               reqpath, onion_request_get_fullpath (req),
               objectdbg_BM (_.webexob), objectdbg1_BM (_.sessionob),
               clocktime_BM (CLOCK_REALTIME) - wexda->webx_time);
      fputs ("</p>\n", fresp);
      time_t nowt = 0;
      time (&nowt);
      struct tm nowtm;
      char nowbuf[64];
      memset (nowbuf, 0, sizeof (nowbuf));
      memset (&nowtm, 0, sizeof (nowtm));
      localtime_r (&nowt, &nowtm);
      strftime (nowbuf, sizeof (nowbuf), "%c", &nowtm);
      fprintf (fresp,
               "<p><small>generated at <i>%s</i> on <tt>%s</tt> pid %d</small><br/>"
               "<small>timestamp: <tt>%s</tt>, git commit: <tt>%s</tt></small>"
               "</p>\n",
               nowbuf, myhostname_BM, (int) getpid (),
               bismon_timestamp, bismon_lastgitcommit);
      fprintf (fresp, "<!-- generated from %s:%d -->\n",
               basename_BM (__FILE__), __LINE__);
      fprintf (fresp, "</body>\n</html>\n");
      fflush (fresp);
      long ln = ftell (fresp);
      fclose (fresp), fresp = NULL;
      onion_response_set_code (resp, HTTP_INTERNAL_ERROR);
      onion_response_set_length (resp, ln);
      onion_response_write (resp, respbuf, ln);
      onion_response_flush (resp);
      {
        objlock_BM (_.webexob);
        wexda->webx_resp = NULL;
        wexda->webx_requ = NULL;
        if (objgetwebexchangepayl_BM (_.webexob) == wexda)
          {
            wexda->webx_ownobj = NULL;
            // we dont clear the payload, since the old sbuf could be browsed
            //objclearpayload_BM (_.webexob);
          }
        objunlock_BM (_.webexob);
      }
      return OCS_PROCESSED;
    }
  ASSERT_BM (resp != NULL);
  ASSERT_BM (respcode > 0);
  ASSERT_BM (bytes != NULL);
  char cookiebuf[64];
  memset (cookiebuf, 0, sizeof (cookiebuf));
  char sessidbuf[32];
  memset (sessidbuf, 0, sizeof (sessidbuf));
  bool shouldputcookie = false;
  objlock_BM (_.sessionob);
  struct websessiondata_stBM *wsess = objpayload_BM (_.sessionob);
  if (valtype_BM (wsess) != typayl_websession_BM)
    wsess = NULL;
  idtocbuf32_BM (objid_BM (_.sessionob), sessidbuf);
  ASSERT_BM (wsess && wsess->websess_magic == BISMONION_WEBSESS_MAGIC);
  if (wsess->websess_expiretime > 0.0)
    {
      wsess->websess_expiretime =
        clocktime_BM (CLOCK_REALTIME) + USER_WEBSESSION_EXPIRATION_DELAY;
      shouldputcookie = true;
      snprintf (cookiebuf, sizeof (cookiebuf), "n%06dR%dt%do%s",
                wsess->websess_rank, wsess->websess_rand1,
                wsess->websess_rand2, sessidbuf);
      WEAKASSERT_BM (strlen (cookiebuf) < sizeof (cookiebuf) - 3);
    }
  objunlock_BM (_.sessionob);
  DBGPRINTF_BM
    ("do_dynamic_onion sessionob %s webexob %s mimetype '%s' cookiebuf '%s' shouldputcookie %s expiretime %.2f",
     objectdbg_BM (_.sessionob), objectdbg1_BM (_.webexob), mimetype,
     cookiebuf, shouldputcookie ? "true" : "false",
     wsess->websess_expiretime);
  if (mimetype[0])
    onion_response_set_header (resp, "Content-Type", mimetype);
  if (shouldputcookie)
    onion_response_add_cookie   //
      (resp, "BISMONCOOKIE", cookiebuf, (time_t) (wsess->websess_expiretime - clocktime_BM (CLOCK_REALTIME)), "/", NULL,        /// domain
       0);
  else
    onion_response_add_cookie   //
      (resp, "BISMONCOOKIE", "", (time_t) 0, "/", NULL, 0);
  DBGPRINTF_BM ("do_dynamic_onion sessionob %s webexob %s respcode %d len %d",
                objectdbg_BM (_.sessionob), objectdbg1_BM (_.webexob),
                respcode, len);
  onion_response_set_code (resp, respcode);
  DBGPRINTF_BM
    ("do_dynamic_onion sessionob %s webexob %s did set resp@%p respcode %d, len %d",
     objectdbg_BM (_.sessionob), objectdbg1_BM (_.webexob), resp, respcode,
     len);
  onion_response_set_length (resp, len);
  DBGPRINTF_BM
    ("do_dynamic_onion sessionob %s webexob %s before onion_response_write len %d bytes@%p=\n%s\n",
     objectdbg_BM (_.sessionob), objectdbg1_BM (_.webexob), len, bytes,
     bytes);
  onion_response_write (resp, bytes, len);
  {
    objlock_BM (_.webexob);
    wexda = objgetwebexchangepayl_BM (_.webexob);
    if (wexda && wexda->webx_ownobj == _.webexob)
      {
        DBGPRINTF_BM ("do_dynamic_onion clear payload wexda@%p of webexob %s",
                      wexda, objectdbg_BM (_.webexob));
        ASSERT_BM (wexda->webx_magic == BISMONION_WEBX_MAGIC);
        wexda->webx_requ = NULL;
        wexda->webx_resp = NULL;
        wexda->webx_ownobj = NULL;
        objclearpayload_BM (_.webexob);
      }
    objunlock_BM (_.webexob);
  }
  DBGPRINTF_BM
    ("do_dynamic_onion sessionob %s webexob %s after onion_response_write reqpath '%s' post %s mimetype %s",
     objectdbg_BM (_.sessionob), objectdbg1_BM (_.webexob), reqpath,
     postrequest ? "true" : "false", mimetype);
  DBGPRINTF_BM
    ("do_dynamic_onion end sessionob %s webexob %s reqpath '%s' respcode %d (%s) len=%d bytes:\n%s",
     objectdbg_BM (_.sessionob), objectdbg1_BM (_.webexob), reqpath, respcode,
     onion_response_code_description (respcode), len, bytes);
  return OCS_PROCESSED;
}                               /* end do_dynamic_onion_BM */




#define MAX_WEB_HANDLER_DEPTH_BM 40
value_tyBM
find_web_handler_BM (objectval_tyBM * sessionobarg,
                     objectval_tyBM * dictobarg,
                     onion_request * req,
                     int depth, int *poffset, struct stackframe_stBM *stkf)
{
  objectval_tyBM *k_depth = BMK_17YdW6dWrBA_2mn4QmBjMNs;
  objectval_tyBM *k_web_empty_handler = BMK_8Rwc7G3hQ0G_230O74aoi1w;
  objectval_tyBM *k_webhandler_dict_object = BMK_23YbAS1S796_1ZeW8OZfp1J;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * sessionob;    //
                 objectval_tyBM * dictob;       //
                 objectval_tyBM * valob;        //
                 objectval_tyBM * nextdictob;   //
                 value_tyBM wordv;      //
                 value_tyBM valv;       //
    );
  _.sessionob = sessionobarg;
  _.dictob = dictobarg;
  ASSERT_BM (isobject_BM (_.dictob));
  ASSERT_BM (isobject_BM (_.sessionob));
  const char *path = onion_request_get_path (req);
  int pathlen = strlen (path);
  int off = *poffset;
  if (off > pathlen)
    off = pathlen;
  DBGPRINTF_BM
    ("find_web_handler start sessionob %s dictob %s depth %d path '%s' off#%d",
     objectdbg_BM (_.sessionob), objectdbg1_BM (_.dictob), depth, path, off);
  if (depth > MAX_WEB_HANDLER_DEPTH_BM)
    {
      WARNPRINTF_BM ("find_web_handler path '%s' too deep %d", path, depth);
      PLAINFAILURE_BM (__LINE__, k_depth, CURFRAME_BM);
    }
  const char *subpath = path + off;
  const char *slash = strchr (subpath, '/');
  if (!slash)
    slash = subpath + strlen (subpath);
  int wordlen = slash - subpath;
  const char *word = NULL;
  char wordbuf[64];
  memset (wordbuf, 0, sizeof (wordbuf));
  if (wordlen < (int) sizeof (wordbuf))
    {
      if (wordlen > 0)
        strncpy (wordbuf, subpath, wordlen);
      word = wordbuf;
    }
  else
    {
      word = strndup (subpath, wordlen);
      if (!word)
        FATAL_BM ("strndup failure (wordlen=%d)", wordlen);
    }
  DBGPRINTF_BM ("find_web_handler path='%s' dictob %s off=%d word='%s'",
                path, objectdbg_BM (_.dictob), off, word);
  {
    objlock_BM (_.dictob);
    if (word && word[0])
      {
        _.wordv = (value_tyBM) makestring_BM (word);
        _.valv = objdictgetpayl_BM (_.dictob, _.wordv);
        *poffset = off + wordlen;
      }
    else
      _.valv = objgetattr_BM (_.dictob, k_web_empty_handler);
    objunlock_BM (_.dictob);
  }
  DBGPRINTF_BM ("find_web_handler word '%s' path '%s' dictob %s valv %s",
                word, path, objectdbg_BM (_.dictob),
                debug_outstr_value_BM (_.valv, CURFRAME_BM, 0));
  if (isclosure_BM (_.valv))
    LOCALRETURN_BM (_.valv);
  else if (isobject_BM (_.valv))
    {
      _.nextdictob = NULL;
      _.valob = objectcast_BM (_.valv);
      objlock_BM (_.valob);
      if (objectisinstance_BM (_.valob, k_webhandler_dict_object))
        _.nextdictob = _.valob;
      objunlock_BM (_.valob);
      DBGPRINTF_BM ("find_web_handler word '%s' path '%s' nextdictob %s",
                    word, path, objectdbg_BM (_.nextdictob));
      _.valv = NULL;
      if (_.nextdictob)
        _.valv = find_web_handler_BM (_.sessionob, _.nextdictob,
                                      req, depth + 1, poffset, CURFRAME_BM);
      DBGPRINTF_BM
        ("find_web_handler word '%s' path '%s' nextdictob %s depth %d gives valv %s",
         word, path, objectdbg_BM (_.nextdictob), depth,
         debug_outstr_value_BM (_.valv, CURFRAME_BM, 0));

      LOCALRETURN_BM (_.valv);
    }
  DBGPRINTF_BM ("find_web_handler word '%s' path '%s' not found in dictob %s",
                word, path, objectdbg_BM (_.dictob));
  LOCALRETURN_BM (NULL);
}                               /* end find_web_handler_BM */

void
objwebexchangeputdatapayl_BM (const objectval_tyBM * obj, value_tyBM val)
{
  struct webexchangedata_stBM *wxda = objgetwebexchangepayl_BM (obj);
  if (!wxda)
    return;
  ASSERT_BM (wxda->webx_magic == BISMONION_WEBX_MAGIC);
  wxda->webx_datav = val;
}                               /* end  objwebexchangeputdatapayl_BM */

void
objwebexchangecompletepayl_BM (const objectval_tyBM * obj, int httpstatus,
                               const char *mimetype)
{
  struct webexchangedata_stBM *wxda = objgetwebexchangepayl_BM (obj);
  if (!wxda)
    return;
  ASSERT_BM (wxda->webx_magic == BISMONION_WEBX_MAGIC);
  if (mimetype)
    {
      memset (wxda->webx_mimetype, 0, sizeof (wxda->webx_mimetype));
      strncpy (wxda->webx_mimetype, mimetype,
               sizeof (wxda->webx_mimetype) - 1);
    }
  ASSERT_BM (wxda->webx_resp != NULL);
  atomic_store (&wxda->webx_respcode, httpstatus);
  pthread_cond_broadcast (&wxda->webx_cond_ready);
}                               /* end objwebexchangecompletepayl_BM */

/******************************************************************/

void
stop_onion_event_loop_BM (void)
{
  DBGPRINTF_BM ("stop_onion_event_loop_BM");
  atomic_store (&onionlooprunning_BM, false);
  if (myonion_BM)
    onion_listen_stop (myonion_BM);
}                               /* end stop_onion_event_loop_BM */



void
webonion_suspend_before_gc_BM (void)
{
  int nbonionthreads = 0;
  int nbonionsuspended = 0;
  DBGPRINTF_BM ("webonion_suspend_before_gc start tid#%ld elapsed %.3f s",
                (long) gettid_BM (), elapsedtime_BM ());
  do
    {
      pthread_mutex_lock (&onionstack_mtx_bm);
      for (int ix = 0; ix < MAXNBWORKJOBS_BM; ix++)
        {
          if (onionstackinfo_bm[ix].ost_thread != (pthread_t) 0
              && onionstackinfo_bm[ix].ost_stkf)
            {
              nbonionthreads++;
              if (atomic_load (&onionstackinfo_bm[ix].ost_suspended))
                nbonionsuspended++;
            }
        }
      struct timespec ts = { 0, 0 };
      get_realtimespec_delayedms_BM (&ts, 200);
      DBGPRINTF_BM
        ("webonion_suspend_before_gc nbonionthreads=%d nbonionsuspended=%d tid#%ld elapsed %.3f s",
         nbonionthreads, nbonionsuspended, (long) gettid_BM (),
         elapsedtime_BM ());
      if (nbonionthreads > 0 && nbonionsuspended < nbonionthreads)
        pthread_cond_timedwait (&onionstack_mtx_bm, &onionstack_mtx_bm, &ts);
      pthread_mutex_unlock (&onionstack_mtx_bm);
    }
  while (nbonionthreads > 0 && nbonionsuspended < nbonionthreads);
  DBGPRINTF_BM ("webonion_suspend_before_gc end tid#%ld elapsed %.3f s",
                (long) gettid_BM (), elapsedtime_BM ());
}                               /* end webonion_suspend_before_gc_BM */

void
webonion_continue_after_gc_BM (void)
{
  DBGPRINTF_BM ("webonion_continue_after_gc_BM start tid#%ld elapsed %.3f s",
                (long) gettid_BM (), elapsedtime_BM ());
  // probably nothing to do...
}                               /* end webonion_continue_after_gc_BM */


void
initialize_webonion_BM (void)
{
  DBGPRINTF_BM ("initialize_webonion_BM start pid %d tid#%ld elapsed %.3f s",
                (int) getpid (), (long) gettid_BM (), elapsedtime_BM ());
  // see also https://ldpreload.com/blog/signalfd-is-useless
  sigset_t mysigset = { };
  sigemptyset (&mysigset);
  sigaddset (&mysigset, SIGTERM);
  sigaddset (&mysigset, SIGQUIT);
  sigaddset (&mysigset, SIGCHLD);
  if (sigprocmask (SIG_BLOCK, &mysigset, NULL) == -1)
    FATAL_BM ("initialize_webonion: sigprocmask mysigset failure");
  sigfd_BM = signalfd (-1, &mysigset, SFD_NONBLOCK | SFD_CLOEXEC);
  DBGPRINTF_BM ("initialize_webonion_BM sigfd_BM=%d", sigfd_BM);
  if (sigfd_BM < 0)
    FATAL_BM ("signalfd failed in initialize_webonion");
}                               /* end initialize_webonion_BM */


/// remember that only web_plain_event_loop_BM is allowed to *remove*
/// things from onionrunprocarr_BM or onionrunpro_list_BM
void
web_plain_event_loop_BM (void)
{
  LOCALFRAME_BM ( /*prev: */ NULL, /*descr: */ NULL,
                 objectval_tyBM * bufob;);
  atomic_init (&onionlooprunning_BM, true);

  DBGPRINTF_BM ("web_plain_event_loop_BM before loop sigfd_BM=%d tid#%ld elapsed %.3f s",       //
                sigfd_BM, (long) gettid_BM (), elapsedtime_BM ());
  long loopcnt = 0;
  INFOPRINTF_BM ("start loop of web_plain_event_loop_BM");
  while (atomic_load (&onionlooprunning_BM))
    {
      loopcnt++;
      struct pollfd pollarr[MAXNBWORKJOBS_BM + 8];
      pid_t endedprocarr[MAXNBWORKJOBS_BM];
      memset (pollarr, 0, sizeof (pollarr));
      memset (endedprocarr, 0, sizeof (endedprocarr));
      int nbpoll = 0;
      enum
      { pollix_sigfd,
        pollix_cmdp, pollix__last
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
#define POLL_DELAY_MILLISECS_BM 750
      if (loopcnt % 4 == 0)
        DBGPRINTF_BM
          ("web_plain_event_loop_BM before poll nbpoll=%d loop#%ld", nbpoll,
           loopcnt);
      int nbready = poll (&pollarr, nbpoll, POLL_DELAY_MILLISECS_BM);
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
                                   debug_outstr_value_BM
                                   (onproc->rp_cmdnodv, CURFRAME_BM, 0),
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



static bool
read_sigfd_BM (void)            // called from web_plain_event_loop_BM
{
  struct signalfd_siginfo siginf;
  memset (&siginf, 0, sizeof (siginf));
  DBGPRINTF_BM ("read_sigfd_BM start sigfd_BM %d elapsed %3.f s", sigfd_BM,
                elapsedtime_BM ());
  int nbr = read (sigfd_BM, &siginf, sizeof (siginf));
  if (nbr != sizeof (siginf))   // very unlikely, probably impossible
    FATAL_BM ("read_sigfd_BM: read fail (%d bytes read, want %d) - %m",
              nbr, (int) sizeof (siginf));
  DBGPRINTF_BM ("read_sigfd_BM signo=%d", siginf.ssi_signo);
#warning incomplete read_sigfd_BM
  switch (siginf.ssi_signo)
    {
    case SIGTERM:
      {
        DBGPRINTF_BM ("read_sigfd_BM got SIGTERM");
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
          ("before dumping final state into %s (really %s) after SIGTERM to process %d, elapsed %.3f s",
           dump_dir_BM, rp, (int) getpid (), elapsedtime_BM ());
        free (rp), rp = NULL;
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
        DBGPRINTF_BM ("read_sigfd_BM got SIGCHLD pid=%d", (int) pid);
        handle_sigchld_BM (pid);
        return false;
      }
    default:
      FATAL_BM ("read_sigfd_BM unexpected signo %d", siginf.ssi_signo);
    };
  DBGPRINTF_BM ("read_sigfd_BM ending");
  return false;
}                               /* end read_sigfd_BM */


static void
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
        lockonion_runpro_mtx_at_BM (__LINE__);
        for (int oix = 0; oix < MAXNBWORKJOBS_BM; oix++)
          {
            struct onionproc_stBM *onproc = onionrunprocarr_BM + oix;
            if (!onproc->rp_pid)
              continue;
            nbruncmds++;
            if (onproc->rp_pid == pid)
              {
                ASSERT_BM (chix < 0);
                chix = oix;
                _.chdirstrv = onproc->rp_dirstrv;
                _.chcmdnodv = onproc->rp_cmdnodv;
                _.chclosv = onproc->rp_closv;
                _.chbufob = onproc->rp_bufob;
                memset ((void *) onproc, 0, sizeof (struct onionproc_stBM));
              }
          }
        _.qnodv = nodecast_BM (listfirst_BM (onionrunpro_list_BM));
        if (_.qnodv)
          {
            ASSERT_BM (nodeconn_BM (_.qnodv) == k_queue_process);
            if (nbruncmds <= nbworkjobs_BM)
              {
                listpopfirst_BM (onionrunpro_list_BM);
                _.newdirstrv =
                  stringcast_BM ((value_tyBM) nodenthson_BM (_.qnodv, 0));
                _.newcmdnodv =
                  nodecast_BM ((value_tyBM) nodenthson_BM (_.qnodv, 1));
                _.newendclosv =
                  nodecast_BM ((value_tyBM) nodenthson_BM (_.qnodv, 2));
                ASSERT_BM (isnode_BM (_.newcmdnodv));
                ASSERT_BM (isclosure_BM (_.newendclosv));
                DBGPRINTF_BM
                  ("handle_sigchld_BM chix#%d newdirstrv %s newcmdnodv %s newendclosv %s beforefork",
                   chix, debug_outstr_value_BM (_.newdirstrv, CURFRAME_BM,
                                                0),
                   debug_outstr_value_BM (_.newcmdnodv, CURFRAME_BM, 0),
                   debug_outstr_value_BM (_.newendclosv, CURFRAME_BM, 0));
                fork_onion_process_at_slot_BM (chix, _.newdirstrv,
                                               _.newcmdnodv, _.newendclosv,
                                               CURFRAME_BM);
                didfork = true;
              }
          }
        unlockonion_runpro_mtx_at_BM (__LINE__);
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
    FATAL_BM ("handle_sigchld_BM waitpid failure pid#%d", pid);
  if (didfork)
    usleep (1000);              // sleep a little bit, to let the child process start
}                               /* end handle_sigchld_BM */


static void
read_commandpipe_BM (void)
{
  char buf[4];
  memset (&buf, 0, sizeof (buf));
  int nbr = read (cmdpipe_rd_BM, buf, 1);
  if (nbr == 1)
    {
      DBGPRINTF_BM ("read_commandpipe_BM '%s' incomplete", buf);
      WARNPRINTF_BM ("read_commandpipe_BM unimplemented");
      // if buf[0] is 'X', execute a deferred command
      // if buf[0] is 'G', run the garbage collector. Not sure!
#warning read_commandpipe_BM incomplete
      // should handle the command
    }
  else
    DBGPRINTF_BM ("read_commandpipe_BM nbr %d - %s", nbr,
                  (nbr < 0) ? strerror (errno) : "--");
}                               /* end read_commandpipe_BM */

void
add_defer_command_onion_BM (void)
{
  char buf[4];
  memset (&buf, 0, sizeof (buf));
  buf[0] = 'X';
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
      FATAL_BM ("add_defer_command_onion_BM nbw %d - %s", nbw,
                (nbw < 0) ? strerror (errno) : "--");
    }
  FATAL_BM ("add_defer_command_onion_BM failed");
}                               /* end add_defer_command_onion_BM */

////////////////////////////////////////////////////////////////




void
register_onion_thread_stack_BM (struct stackframe_stBM *stkf)
{
  ASSERT_BM (stkf != NULL);
  ASSERT_BM (stkf->stkfram_pA.htyp == typayl_StackFrame_BM);
  pthread_mutex_lock (&onionstack_mtx_bm);
  if (!curonionstackinfo_BM)
    {
      for (int ix = 0; ix < MAXNBWORKJOBS_BM; ix++)
        {
          if (onionstackinfo_bm[ix].ost_stkf == NULL
              && onionstackinfo_bm[ix].ost_thread == (pthread_t) 0)
            {
              curonionstackinfo_BM = onionstackinfo_bm + ix;
              onionstackinfo_bm[ix].ost_thread = pthread_self ();
              atomic_init (&onionstackinfo_bm[ix].ost_suspended, false);
              break;
            };
        }
    }
  ASSERT_BM (curonionstackinfo_BM
             && curonionstackinfo_BM->ost_thread == pthread_self ());
  curonionstackinfo_BM->ost_stkf = stkf;
  pthread_mutex_unlock (&onionstack_mtx_bm);
}                               /* end register_onion_thread_stack_BM */


void
unregister_onion_thread_stack_BM (struct stackframe_stBM *stkf)
{
  ASSERT_BM (stkf != NULL);
  ASSERT_BM (stkf->stkfram_pA.htyp == typayl_StackFrame_BM);
  pthread_mutex_lock (&onionstack_mtx_bm);
  ASSERT_BM (curonionstackinfo_BM != NULL);
  ASSERT_BM (curonionstackinfo_BM->ost_thread == pthread_self ());
  curonionstackinfo_BM->ost_thread = (pthread_t) 0;
  curonionstackinfo_BM->ost_stkf = NULL;
  atomic_store (&curonionstackinfo_BM->ost_suspended, false);
  curonionstackinfo_BM = NULL;
  pthread_mutex_unlock (&onionstack_mtx_bm);
}                               /* end unregister_onion_thread_stack_BM */


void
perhaps_suspend_for_gc_onion_thread_stack_BM (struct stackframe_stBM *stkf)
{
  ASSERT_BM (stkf != NULL);
  ASSERT_BM (stkf->stkfram_pA.htyp == typayl_StackFrame_BM);
  NONPRINTF_BM
    ("perhaps_suspend_for_gc_onion_thread_stack_BM start tid#%ld elapsed %.3f s",
     (long) gettid_BM (), elapsedtime_BM ());
  pthread_mutex_lock (&onionstack_mtx_bm);
  ASSERT_BM (curonionstackinfo_BM != NULL);
  ASSERT_BM (curonionstackinfo_BM->ost_thread == pthread_self ());
  curonionstackinfo_BM->ost_stkf = stkf;
  atomic_store (&curonionstackinfo_BM->ost_suspended, true);
  pthread_mutex_unlock (&onionstack_mtx_bm);
  pthread_cond_broadcast (&onionstack_condchange_bm);
  long nbloops = 0;
  for (;;)
    {
      if (!agenda_need_gc_BM ())
        break;
      nbloops++;
      if (nbloops % 16 == 0)
        DBGPRINTF_BM
          ("perhaps_suspend_for_gc_onion_thread_stack need GC tid#%ld  elapsed %.3f s loop#%ld",
           (long) gettid_BM (), elapsedtime_BM (), nbloops);
      agenda_wait_gc_BM ();
    }
  pthread_mutex_lock (&onionstack_mtx_bm);
  ASSERT_BM (curonionstackinfo_BM != NULL);
  atomic_store (&curonionstackinfo_BM->ost_suspended, false);
  pthread_mutex_unlock (&onionstack_mtx_bm);
  pthread_cond_broadcast (&onionstack_condchange_bm);
  if (nbloops > 0)
    DBGPRINTF_BM
      ("perhaps_suspend_for_gc_onion_thread_stack_BM end tid#%ld  elapsed %.3f s loops#%ld",
       (long) gettid_BM (), elapsedtime_BM (), nbloops);
}                               /* end perhaps_suspend_for_gc_onion_thread_stack_BM */


// mark the stack of every webonion pthread; they all should be "inactive"
void
gcmarkwebonion_BM (struct garbcoll_stBM *gc)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  pthread_mutex_lock (&onionstack_mtx_bm);
  for (int ix = 0; ix < MAXNBWORKJOBS_BM; ix++)
    {
      if (onionstackinfo_bm[ix].ost_stkf != NULL
          && onionstackinfo_bm[ix].ost_thread != (pthread_t) 0)
        gcframemark_BM (gc, onionstackinfo_bm[ix].ost_stkf, 0);
    }
  pthread_mutex_unlock (&onionstack_mtx_bm);
}                               /* end gcmarkwebonion_BM */

//// end of file web_ONIONBM.c 
