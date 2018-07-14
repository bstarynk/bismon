                              // file web_ONIONBM.c
/***
    BISMON 
    Copyright © 2018 Basile Starynkevitch (working at CEA, LIST, France)
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
#include <onion/onion.h>
#include "bismon.h"
#include "web_ONIONBM.const.h"
extern void run_onionweb_BM (int nbjobs);
static onion *myonion_BM;
// the command pipe contains bytes, each considered as a different message
static int cmdpipe_rd_BM = -1, cmdpipe_wr_BM = -1;

extern void add_defer_command_onion_BM (void);

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

// lock for the structures above
pthread_mutex_t onionrunpro_mtx_BM = PTHREAD_MUTEX_INITIALIZER;

// the lock above should be set when calling:
static void
fork_onion_process_at_slot_BM (int slotpos,
                               const stringval_tyBM * dirstrarg,
                               const node_tyBM * cmdnodarg,
                               const closure_tyBM * endclosarg,
                               struct stackframe_stBM *stkf);
static void lockonion_runpro_mtx_at_BM (int lineno);
static void unlockonion_runpro_mtx_at_BM (int lineno);

static void plain_event_loop_BM (void);

// handle signals thu signafd(2)
static void read_sigterm_BM (int sigfd);
static void read_sigquit_BM (int sigfd);
static void read_sigchld_BM (int sigfd);
// handle the command pipe
static void read_commandpipe_BM (void);

void
lockonion_runpro_mtx_at_BM (int lineno)
{
  DBGPRINTFAT_BM (__FILE__, lineno, "lockonion_runpro_mtx_BM thrid=%ld",
                  (long) gettid_BM ());
  pthread_mutex_lock (&onionrunpro_mtx_BM);
}                               /* end lockonion_runpro_mtx_at_BM */


void
unlockonion_runpro_mtx_at_BM (int lineno)
{
  DBGPRINTFAT_BM (__FILE__, lineno, "unlockonion_runpro_mtx_BM thrid=%ld",
                  (long) gettid_BM ());
  pthread_mutex_unlock (&onionrunpro_mtx_BM);
}                               /* end lockonion_runpro_mtx_at_BM */

void
log_begin_message_BM (void)
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
  strftime (nowtibuf, sizeof (nowtibuf), "%T", &nowtm);
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
  FATAL_BM ("log_begin_message_BM unimplemented in web_ONIONBM: %s", logmbuf);
#warning log_begin_message_BM unimplemented in web_ONIONBM
}                               /* end log_begin_message_BM */

void
log_end_message_BM (void)
{
  FATAL_BM ("log_end_message_BM unimplemented in web_ONIONBM");
#warning log_end_message_BM  unimplemented in web_ONIONBM
}                               /* end log_end_message_BM */

void
log_object_message_BM (const objectval_tyBM * obj)
{
  FATAL_BM ("log_object_message_BM unimplemented in web_ONIONBM obj %s",
            objectdbg_BM (obj));
#warning log_object_message_BM  unimplemented in web_ONIONBM
}                               /* end log_object_message_BM */

void
log_puts_message_BM (const char *msg)
{
  if (!msg || !msg[0])
    return;
  FATAL_BM ("log_puts_message_BM unimplemented in web_ONIONBM msg %s", msg);
#warning log_puts_message_BM  unimplemented in web_ONIONBM
}                               /* end log_puts_message_BM */

void
log_printf_message_BM (const char *fmt, ...)
{
  char smallbuf[64];
  memset (smallbuf, 0, sizeof (smallbuf));
  va_list args;
  char *buf = smallbuf;
  va_start (args, fmt);
  int ln = vsnprintf (smallbuf, sizeof (smallbuf), fmt, args);
  va_end (args);
  if (ln >= (int) sizeof (smallbuf) - 1)
    {
      buf = calloc ((prime_above_BM (ln + 2) | 7) + 1, 1);
      if (!buf)
        FATAL_BM ("failed to calloc for %d bytes (%m)", ln);
      va_start (args, fmt);
      vsnprintf (buf, ln + 1, fmt, args);
      va_end (args);
    }
  log_puts_message_BM (buf);
  if (buf != smallbuf)
    free (buf);
}                               /* end log_printf_message_BM */





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
  if (_.dirstrv && !isstring_BM (_.dirstrv))
    FAILHERE (makenode1_BM (BMP_string, (value_tyBM) _.dirstrv));
  if (_.dirstrv && isstring_BM (_.dirstrv))
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
  if (!isnode_BM (_.cmdnodv))
    FAILHERE (makenode1_BM (BMP_node, (value_tyBM) _.cmdnodv));
  if (!isclosure_BM (_.endclosv))
    FAILHERE (makenode1_BM (BMP_closure, (value_tyBM) _.cmdnodv));
  unsigned cmdlen = nodewidth_BM (_.cmdnodv);
  if (cmdlen == 0)
    FAILHERE (makenode1_BM (BMP_node, (value_tyBM) _.cmdnodv));
  for (unsigned aix = 0; aix < cmdlen; aix++)
    {
      _.curargv = nodenthson_BM (_.cmdnodv, aix);
      if (!isstring_BM (_.curargv))
        FAILHERE (makenode2_BM
                  (BMP_node, (value_tyBM) _.cmdnodv, taggedint_BM (aix)));
    }
  ASSERT_BM (nbworkjobs_BM >= MINNBWORKJOBS_BM
             && nbworkjobs_BM <= MAXNBWORKJOBS_BM);
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
    {                           // append to onionrunpro_list_BM
      if (!onionrunpro_list_BM)
        onionrunpro_list_BM = makelist_BM ();
      _.nodv = (value_tyBM)
        makenode3_BM (k_queue_process, _.dirstrv, _.cmdnodv, _.endclosv);
      listappend_BM (onionrunpro_list_BM, _.nodv);
    }
  ASSERT_BM (lockedproc);
  unlockonion_runpro_mtx_at_BM (__LINE__), lockedproc = false;
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
     debug_outstr_value_BM (_.endclosv, CURFRAME_BM, 0),
     debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    makenode4_BM (k_queue_process, _.dirstrv, _.cmdnodv, _.endclosv,
                  _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end queue_process_BM */

static void
fork_onion_process_at_slot_BM (int slotpos,
                               const stringval_tyBM * dirstrarg,
                               const node_tyBM * cmdnodarg,
                               const closure_tyBM * endclosarg,
                               struct stackframe_stBM *stkf)
{
  objectval_tyBM *k_queue_process = BMK_8DQ4VQ1FTfe_5oijDYr52Pb;
  objectval_tyBM *k_sbuf_object = BMK_77xbaw1emfK_1nhE4tp0bF3;
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
  int cmdlen = nodewidth_BM (_.cmdnodv);
  ASSERT_BM (cmdlen > 0);
  ASSERT_BM (slotpos >= 0 && slotpos < MAXNBWORKJOBS_BM);
  DBGPRINTF_BM ("fork_onion_process_at_slot_BM slotpos %d cmdnod %s",
                slotpos, debug_outstr_value_BM (_.cmdnodv, CURFRAME_BM, 0));
  /// should fork the process
  int pipfd[2] = { -1, -1 };
  char **args = calloc (cmdlen + 1, sizeof (char *));
  if (!args)
    FATAL_BM ("calloc args %d failed - %m", cmdlen);
  for (int aix = 0; aix < cmdlen; aix++)
    args[aix] = bytstring_BM (nodenthson_BM (_.cmdnodv, aix));
  if (pipe (pipfd))
    FATAL_BM ("pipe failed - %m");
  ASSERT_BM (pipfd[0] > 0 && pipfd[1] > 0);
  fflush (NULL);
  pid_t pid = fork ();
  if (pid < 0)
    FATAL_BM ("failed to fork %s - %m", args[0]);
  if (pid == 0)
    {
      // child process; in principle, most file descriptors should be
      //close-on-exec, but just in case we close some of them...
      for (int ix = 3; ix < 64; ix++)
        if (ix != pipfd[1])
          (void) close (ix);
      if (isstring_BM (_.dirstrv))
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
      execv (args[0], args);
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
void
run_onionweb_BM (int nbjobs)    // declared and used only in main_BM.c
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
  myonion_BM = onion_new (O_THREADED | O_NO_SIGTERM | O_SYSTEMD | O_DETACHED);
  if (!myonion_BM)
    FATAL_BM ("failed to create onion");
  onion_set_max_threads (myonion_BM, nbjobs);
  DBGPRINTF_BM ("run_onionweb webhost '%s' webport %d", webhost ? : "??",
                webport);
  if (webhost && webhost[0])
    onion_set_hostname (myonion_BM, webhost);
  char *lastcolon = strrchr (onion_web_base_BM, ':');
  if (lastcolon && isdigit (lastcolon[1]))
    onion_set_port (myonion_BM, lastcolon + 1);
  char *webrootpath = NULL;
  if (asprintf (&webrootpath, "%s/webroot/", bismon_directory) < 0
      || !webrootpath || !webrootpath[0] || access (webrootpath, R_OK | X_OK))
    FATAL_BM ("failed to get or access webroot/ path - %m");
  onion_handler *filehdl = onion_handler_export_local_new (webrootpath);
  if (!filehdl)
    FATAL_BM ("failed to get onion webroot handler for %s", webrootpath);
  onion_set_root_handler (myonion_BM, filehdl);
  DBGPRINTF_BM ("run_onionweb after set root handler filehdl@%p", filehdl);
  onion_handler *customhdl =
    onion_handler_new (custom_onion_handler_BM, NULL, NULL);
  onion_handler_add (filehdl, customhdl);
  ///
  /// create the command pipe
  {
    int piparr[2] = { -1, -1 };
    if (pipe2 (piparr, O_CLOEXEC | O_NONBLOCK))
      FATAL_BM ("run_onionweb pipe failure for the command pipe - %m");
    cmdpipe_rd_BM = piparr[0];
    cmdpipe_wr_BM = piparr[1];
    DBGPRINTF_BM ("run_onionweb before onion_listen cmdpiprd#%d cmdpipwr#%d",
                  cmdpipe_rd_BM, cmdpipe_wr_BM);
  }
  int err = onion_listen (myonion_BM);  // since detached, returns now
  DBGPRINTF_BM ("run_onionweb after onion_listen err=%d", err);
  if (err)
    FATAL_BM ("failed to do onion_listen (err#%d / %s)", err, strerror (err));
  ///
  /// should add our event loop, at least related to queued processes
  /// (and their output pipes), to SIGCHLD and SIGTERM + SIGQUIT
  /// see https://groups.google.com/a/coralbits.com/d/msg/onion-dev/m-wH-BY2MA0/QJqLNcHvAAAJ
  /// and https://groups.google.com/a/coralbits.com/d/msg/onion-dev/ImjNf1EIp68/R37DW3mZAAAJ
  plain_event_loop_BM ();
}                               /* end run_onionweb_BM */

////////////////////////////////////////////////////////////////

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
  if (ws->websess_userob)
    gcobjmark_BM (gc, ws->websess_userob);
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
        objclearpayload_BM (ownerob);
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
  if (wex->webx_ownobj)
    {
      objectval_tyBM *ownerob = wex->webx_ownobj;
      wex->webx_ownobj = NULL;
      objlock_BM (ownerob);
      if (objpayload_BM (ownerob) == (extendedval_tyBM) wex)
        objclearpayload_BM (ownerob);
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
websessiondelete_BM (objectval_tyBM * ownobj, struct websessiondata_stBM *ws)
{
#warning unimplemented websessiondelete_BM
  FATAL_BM ("unimplemented websessiondelete_BM ownobj %s ws@%p",
            objectdbg_BM (ownobj), (void *) ws);
}                               /* end websessiondelete_BM */

void
webexchangedelete_BM (objectval_tyBM * ownobj,
                      struct webexchangedata_stBM *wex)
{
#warning unimplemented webexchangedelete_BM
  FATAL_BM ("unimplemented webexchangedelete_BM ownobj %s wex@%p",
            objectdbg_BM (ownobj), (void *) wex);
}                               /* end webexchangedelete_BM */


onion_connection_status
custom_onion_handler_BM (void *_clientdata __attribute__ ((unused)),
                         onion_request * req, onion_response * resp)
{
  const char *reqpath = onion_request_get_path (req);
  unsigned reqflags = onion_request_get_flags (req);
  unsigned reqmeth = (reqflags & OR_METHODS);
  const char *bcookie = onion_request_get_cookie (req, "BISMONCOOKIE");
  char dbgmethbuf[16];
  DBGPRINTF_BM ("custom_onion_handler reqpath '%s' reqflags %#x:%s bcookie %s", //
                reqpath, reqflags,      //
                ((reqmeth == OR_GET) ? "GET"    //
                 : (reqmeth == OR_HEAD) ? "HEAD"        //
                 : (reqmeth == OR_POST) ? "POST"        //
                 : (reqmeth == OR_OPTIONS) ? "OPTIONS"  //
                 : (reqmeth == OR_PROPFIND) ? "PROPFIND"        //
                 : snprintf (dbgmethbuf, sizeof (dbgmethbuf),   ///
                             "meth#%d", reqmeth)),
                bcookie ? bcookie : "*none*");
#warning unimplemented custom_onion_handler_BM
  /// probably should return OCS_PROCESSED if handled, or OCS_NOT_PROCESSED, OCS_FORBIDDEN, OCS_INTERNAL_ERROR, etc...
  return OCS_NOT_PROCESSED;
}                               /* end custom_onion_handler_BM */

/// remember that only plain_event_loop_BM is allowed to *remove*
/// things from onionrunprocarr_BM or onionrunpro_list_BM
void
plain_event_loop_BM (void)
{
  bool running = true;
  int termsigfd = -1;
  int quitsigfd = -1;
  int chldsigfd = -1;
  {
    sigset_t termsigset = { };
    sigemptyset (&termsigset);
    sigaddset (&termsigset, SIGTERM);
    if (sigprocmask (SIG_BLOCK, &termsigset, NULL) == -1)
      FATAL_BM ("sigprocmask termsigset failure");
    termsigfd = signalfd (-1, &termsigset, NULL);
    if (termsigfd < 0)
      FATAL_BM ("signalfd failed for SIGTERM");
  }
  {
    sigset_t quitsigset = { };
    sigemptyset (&quitsigset);
    sigaddset (&quitsigset, SIGQUIT);
    if (sigprocmask (SIG_BLOCK, &quitsigset, NULL) == -1)
      FATAL_BM ("sigprocmask quitsigset failure");
    quitsigfd = signalfd (-1, &quitsigset, NULL);
    if (quitsigfd < 0)
      FATAL_BM ("signalfd failed for SIGQUIT");
  }
  {
    sigset_t chldsigset = { };
    sigemptyset (&chldsigset);
    sigaddset (&chldsigset, SIGCHLD);
    if (sigprocmask (SIG_BLOCK, &chldsigset, NULL) == -1)
      FATAL_BM ("sigprocmask chldsigset failure");
    chldsigfd = signalfd (-1, &chldsigset, NULL);
    if (chldsigfd < 0)
      FATAL_BM ("signalfd failed for SIGCHLD");
  }
  DBGPRINTF_BM ("plain_event_loop_BM before loop termsigfd=%d quitsigfd=%d chldsigfd=%d",       //
                termsigfd, quitsigfd, chldsigfd);
  long loopcnt = 0;
  while (running)
    {
      struct pollfd pollarr[MAXNBWORKJOBS_BM + 8];
      pid_t endedprocarr[MAXNBWORKJOBS_BM];
      memset (pollarr, 0, sizeof (pollarr));
      memset (endedprocarr, 0, sizeof (endedprocarr));
      int nbpoll = 0;
      enum
      { pollix_term, pollix_quit, pollix_chld,
        pollix_cmdp, pollix__lastsig
      };
      pollarr[pollix_term].fd = termsigfd;
      pollarr[pollix_term].events = POLL_IN;
      pollarr[pollix_quit].fd = quitsigfd;
      pollarr[pollix_quit].events = POLL_IN;
      pollarr[pollix_chld].fd = chldsigfd;
      pollarr[pollix_chld].events = POLL_IN;
      pollarr[pollix_cmdp].fd = cmdpipe_rd_BM;
      pollarr[pollix_cmdp].events = POLL_IN;
      nbpoll = pollix__lastsig;
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
#define POLL_DELAY_MILLISECS_BM 300
      int nbready = poll (&pollarr, nbpoll, POLL_DELAY_MILLISECS_BM);
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
        char pipbuf[1024];
        lockonion_runpro_mtx_at_BM (__LINE__);
        int runix = 0;
        for (int ix = pollix__lastsig; ix < nbpoll; ix++)
          {
            if (pollarr[ix].revents & POLL_IN)
              {
                int curfd = pollarr[ix].fd;
                while (runix < nbworkjobs_BM)
                  {
                    if (onionrunprocarr_BM[runix].rp_outpipe == curfd)
                      {
                        runix++;
                        int bytcnt = 0;
                        do
                          {
                            memset (pipbuf, 0, sizeof (pipbuf));
                            // we might do ioctl(curfd, FIONBIO, &cnt)
                            // but it is not worth doing since the pipe
                            // is non-blocking. See https://stackoverflow.com/a/1151077/841108
                            bytcnt = read (curfd, pipbuf, sizeof (pipbuf));
                            if (bytcnt < 0 && errno == EINTR)
                              continue;
                            if (bytcnt < 0 && errno == EWOULDBLOCK)
                              break;
                            if (bytcnt < 0)
                              {
                                // this probably should not happen
                                FATAL_BM
                                  ("unexpected error %m on output pipe fd#%d for pid %d",
                                   curfd,
                                   (int) onionrunprocarr_BM[runix].rp_pid);
                              }
                            if (bytcnt == 0)
                              { // end of file on pipe
                                // the forked process might close its stdout
                                // and still be running, even if this is
                                // unfriendly...
                                close (curfd);
                                onionrunprocarr_BM[runix].rp_outpipe = -1;
                                break;
                              }
			    ASSERT_BM(bytcnt > 0);
#warning incomplete, should append the pipbuf to the command strbuf object
                          }
                        while (bytcnt > 0);
                        break;
                      }
                  }
              }
          }
        unlockonion_runpro_mtx_at_BM (__LINE__);
      }
      if (pollarr[pollix_term].revents & POLL_IN)
        {
          read_sigterm_BM (termsigfd);
          running = false;
          break;
        }
      if (pollarr[pollix_quit].revents & POLL_IN)
        {
          read_sigquit_BM (quitsigfd);
          running = false;
          break;
        };
      if (pollarr[pollix_chld].revents & POLL_IN)
        read_sigchld_BM (chldsigfd);
      if (pollarr[pollix_cmdp].revents & POLL_IN)
        read_commandpipe_BM ();
      ///
#warning missing code in plain_event_loop_BM
      fprintf (stderr,
               "missing code in plain_event_loop_BM loop#%d\n", loopcnt);
      loopcnt++;
    }                           /* end while running */
  DBGPRINTF_BM ("plain_event_loop_BM ended loopcnt=%ld", loopcnt);
}                               /* end plain_event_loop_BM */

static void
read_sigterm_BM (int sigfd)
{
  struct signalfd_siginfo sigterminf;
  memset (&sigterminf, 0, sizeof (sigterminf));
  int nbr = read (sigfd, &sigterminf, sizeof (sigterminf));
  if (nbr != sizeof (sigterminf))       // very unlikely, probably impossible
    FATAL_BM ("read_sigterm_BM: read fail (%d.by read, want %d) - %m", nbr,
              (int) sizeof (sigterminf));
  DBGPRINTF_BM ("read_sigterm_BM");
}                               /* end read_sigterm_BM */


static void
read_sigquit_BM (int sigfd)
{
  struct signalfd_siginfo sigquitinf;
  memset (&sigquitinf, 0, sizeof (sigquitinf));
  int nbr = read (sigfd, &sigquitinf, sizeof (sigquitinf));
  if (nbr != sizeof (sigquitinf))       // very unlikely, probably impossible
    FATAL_BM ("read_sigquit_BM: read fail (%d.by read, want %d) - %m", nbr,
              (int) sizeof (sigquitinf));
  DBGPRINTF_BM ("read_sigquit_BM");
}                               /* end read_sigquit_BM */


static void
read_sigchld_BM (int sigfd)
{
  struct signalfd_siginfo sigchldinf;
  memset (&sigchldinf, 0, sizeof (sigchldinf));
  int nbr = read (sigfd, &sigchldinf, sizeof (sigchldinf));
  if (nbr != sizeof (sigchldinf))
    // very unlikely, probably impossible
    FATAL_BM
      ("read_sigchld_BM: read fail (%d.by read, want %d) - %m",
       nbr, (int) sizeof (sigchldinf));
  pid_t pid = sigchldinf.ssi_pid;
  int ws = 0;
  pid_t wpid = waitpid (pid, &ws, WNOHANG);
  if (wpid == pid)
    {
      DBGPRINTF_BM ("read_sigchld_BM pid %d", (int) pid);
    }
  else
    FATAL_BM ("read_sigchld_BM waitpid failure pid#%d", pid);
}                               /* end read_sigchld_BM */


static void
read_commandpipe_BM (void)
{
  char buf[4];
  memset (&buf, 0, sizeof (buf));
  int nbr = read (cmdpipe_rd_BM, buf, 1);
  if (nbr == 1)
    {
      DBGPRINTF_BM ("read_commandpipe_BM '%s' incomplete", buf);
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
