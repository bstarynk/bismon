// file main_BM.c

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

----
    Contact me (Basile Starynkevitch) by email
    basile@starynkevitch.net and/or basile.starynkevitch@cea.fr
***/
#include "bismon.h"
#include <gtk/gtk.h>
#include <glib.h>
#include <glib/giochannel.h>

struct timespec startrealtimespec_BM;
void *dlprog_BM;
bool gui_is_running_BM;
static int nbworkjobs_BM;
const char myhostname_BM[80];
thread_local struct threadinfo_stBM *curthreadinfo_BM;
thread_local volatile struct failurehandler_stBM *curfailurehandle_BM;

GIOChannel *defer_gtk_readpipechan_BM;
int defer_gtk_readpipefd_BM = -1;
int defer_gtk_writepipefd_BM = -1;

extern void weakfailure_BM (void);

// consider putting a gdb breakpoint here 
void
weakfailure_BM (void)
{
  fflush (NULL);
}                               /* end weakfailure_BM */

void
weakassertfailureat_BM (const char *condmsg, const char *fil, int lin)
{
  fprintf (stderr, "weakassertfailureat_BM (%s:%d) %s\n", fil, lin, condmsg);
  fflush (stderr);
  void *backbuf[50];
  memset (backbuf, 0, sizeof (backbuf));
  int nb = backtrace (backbuf, sizeof (backbuf) / sizeof (void *));
  backtrace_symbols_fd (backbuf, nb, STDERR_FILENO);
  weakfailure_BM ();
}                               /* end weakassertfailureat_BM */

value_tyBM
objrout_placeholder_BM (struct stackframe_stBM *stkf __attribute__ ((unused)),  //
                        const value_tyBM arg1 __attribute__ ((unused)), //
                        const value_tyBM arg2 __attribute__ ((unused)), //
                        const value_tyBM arg3 __attribute__ ((unused)), //
                        const value_tyBM arg4 __attribute__ ((unused)), //
                        const quasinode_tyBM * restargs
                        __attribute__ ((unused)))
{
  weakassertfailureat_BM ("objrout_placeholder_BM", __FILE__, __LINE__);
  return NULL;
}                               /* end objrout_placeholder_BM */


void
abort_BM (void)
{
  weakfailure_BM ();
  abort ();
}                               /* end abort_BM */


////////////////////////////////////////////////////////////////
char *load_dir_bm;
char *dump_dir_bm;
char *dump_after_load_dir_bm;
char *builder_file_bm = "bismon.ui";
char *css_file_bm = "bismon.css";
char *gui_log_name_bm = "_bismon.log";  /* default log file */

char *comment_bm;
int count_emit_has_predef_bm;
int nb_added_predef_bm;
#define MAXADDEDPREDEF_BM 16
struct
{
  const char *pr_comment;
  const char *pr_name;
} added_predef_bm[MAXADDEDPREDEF_BM];

bool batch_bm;
bool oldgui_BM;
bool give_version_bm;


void
failure_at_BM (int failcode, const char *fil, int lineno,
               const value_tyBM reasonv, struct stackframe_stBM *stkf)
{
  if (curfailurehandle_BM)
    {
      if (curfailurehandle_BM->failh_magic != FAILUREHANDLEMAGIC_BM)
        FATAL_AT_BM (fil, lineno,
                     "corrupted curfailurehandle_BM@%p for failcode %d",
                     curfailurehandle_BM, failcode);
      curfailurehandle_BM->failh_reason = reasonv;
      longjmp (((struct failurehandler_stBM *)
                curfailurehandle_BM)->failh_jmpbuf, failcode);
    }
  else
    {
      FATAL_AT_BM (fil, lineno,
                   "unhandled failure code#%d reason %s",
                   failcode, debug_outstr_value_BM (reasonv, stkf, 0));
    }
}                               /* end failure_at_BM */

void
failure_BM (int failcode, const value_tyBM reasonv,
            struct stackframe_stBM *stkf)
{
  failure_at_BM (failcode, "??", 0, reasonv, stkf);
}                               /* end failure_BM */

static void add_new_predefined_bm (void);

static bool
run_command_bm (const gchar * optname
                __attribute__ ((unused)), const gchar * val, gpointer data
                __attribute__ ((unused)), GError ** perr)
{
  ASSERT_BM (val != NULL);
  fprintf (stderr, "running command: %s\n", val);
  int ok = system (val);
  if (ok == 0)
    return TRUE;
  g_set_error (perr, 0, ok, "command %s failed with status %d", val, ok);
  return FALSE;
}                               /* end run_command_bm */

static bool
add_predef_bm (const gchar * optname __attribute__ ((unused)),
               const gchar * val,
               gpointer data __attribute__ ((unused)),
               GError ** perr __attribute__ ((unused)))
{
  ASSERT_BM (val != NULL);
  if (!validname_BM (val))
    FATAL_BM ("invalid predef name %s", val);
  if (nb_added_predef_bm >= MAXADDEDPREDEF_BM)
    FATAL_BM ("too many added predefined %i", nb_added_predef_bm);
  if (comment_bm)
    added_predef_bm[nb_added_predef_bm].pr_comment = strdup (comment_bm);
  added_predef_bm[nb_added_predef_bm].pr_name = strdup (val);
  nb_added_predef_bm++;
  comment_bm = NULL;
  return true;
}                               /* end add_predef_bm */


const GOptionEntry optab[] = {
  //
  {.long_name = "load",.short_name = 'l',
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_FILENAME,
   .arg_data = &load_dir_bm,
   .description = "load directory DIR (default is .)",
   .arg_description = "DIR"},
  //
  {.long_name = "dump",.short_name = 'd',
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_FILENAME,
   .arg_data = &dump_dir_bm,
   .description = "dump directory DIR",
   .arg_description = "DIR"},
  //
  {.long_name = "dump-after-load",.short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_FILENAME,
   .arg_data = &dump_after_load_dir_bm,
   .description = "dump after load directory DIR",
   .arg_description = "DIR"},
  //
  {.long_name = "gui-builder",.short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_FILENAME,
   .arg_data = &builder_file_bm,
   .description = "with GTK builder file FILE (default: bismon.ui)",
   .arg_description = "FILE"},
  //
  {.long_name = "gui-style",.short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_FILENAME,
   .arg_data = &css_file_bm,
   .description = "with GTK style CSS file FILE (default: bismon.css)",
   .arg_description = "FILE"},
  //
  //
  {.long_name = "gui-log",.short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_FILENAME,
   .arg_data = &gui_log_name_bm,
   .description =
   "GUI log file name (none if empty, - is stdout, default is _bismon.log)",
   .arg_description = "FILE"},
  //
  {.long_name = "emit-has-predef",.short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_INT,
   .arg_data = &count_emit_has_predef_bm,
   .description = "emit NB 'HAS_PREDEF_BM'",
   .arg_description = "NB"},
  //
  {.long_name = "job",.short_name = (char) 'j',
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_INT,
   .arg_data = &nbworkjobs_BM,
   .description = "number of worker threads NBJOBS (>=2, <16)",
   .arg_description = "NBJOBS"},
  //
  {.long_name = "run-command",.short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_CALLBACK,
   .arg_data = &run_command_bm,
   .description = "run the command CMD",
   .arg_description = "CMD"},

  //
  {.long_name = "comment-predef",.short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_STRING,
   .arg_data = &comment_bm,
   .description = "set comment of next predefined to COMM",
   .arg_description = "COMM"},

  //
  {.long_name = "add-predef",.short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_CALLBACK,
   .arg_data = &add_predef_bm,
   .description = "add new predefined named PREDEFNAME",
   .arg_description = "PREDEFNAME"},

  //
  {.long_name = "batch",.short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_NONE,
   .arg_data = &batch_bm,
   .description = "run in batch mode without GUI",
   .arg_description = NULL},
  //
  {.long_name = "old-gui",.short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_NONE,
   .arg_data = &oldgui_BM,
   .description = "run the old GUI",
   .arg_description = NULL},
  //
  //
  {.long_name = "version",.short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_NONE,
   .arg_data = &give_version_bm,
   .description = "gives version information",
   .arg_description = NULL},
  //
  {}
};

static void
check_delims_BM (void)
{
  int delimcnt = 0;
  char *prevdelim = "";
#define HAS_DELIM_BM(Str,Name) do {			\
    delimcnt++;						\
    if (strcmp(Str,prevdelim)<=0)			\
      FATAL_BM("unsorted delimiter#%d '%s' and '%s'",	\
	       delimcnt, Str, prevdelim);		\
    prevdelim = Str;					\
  } while(0);
#include "_bm_delim.h"
  if (delimcnt != BM_NB_DELIM)
    FATAL_BM ("expected %d delimiters, got %d", BM_NB_DELIM, delimcnt);
}                               /* end check_delims_BM */

void
add_new_predefined_bm (void)
{
  for (int pix = 0; pix < nb_added_predef_bm; pix++)
    {
      const char *predname = added_predef_bm[pix].pr_name;
      const char *predcomm = added_predef_bm[pix].pr_comment;
      if (!validname_BM (predname))
        FATAL_BM ("predefined name '%s' invalid", predname);
      const objectval_tyBM *predobj = findnamedobj_BM (predname);
      if (!predobj)
        {
          predobj = makeobj_BM ();
          registername_BM (predobj, predname);
        }
      else
        {
          char idpred[32];
          memset (idpred, 0, sizeof (idpred));
          idtocbuf32_BM (objid_BM (predobj), idpred);
          printf ("existing %s becomes predefined %s\n", idpred, predname);
        };
      objtouchnow_BM ((objectval_tyBM *) predobj);
      if (predcomm)
        objputattr_BM ((objectval_tyBM *) predobj, BMP_comment,
                       (value_tyBM) makestring_BM (predcomm));
      objputspacenum_BM ((objectval_tyBM *) predobj, PredefSp_BM);
      char idpred[32];
      memset (idpred, 0, sizeof (idpred));
      idtocbuf32_BM (objid_BM (predobj), idpred);
      if (predcomm)
        printf ("made predefined %s (%s) - %s\n", predname, idpred, predcomm);
      else
        printf ("made predefined %s (%s)\n", predname, idpred);
    }
}                               /* end add_new_predefined_bm */

static int
idqcmp_BM (const void *p1, const void *p2)
{
  return cmpid_BM (*(rawid_tyBM *) p1, *(rawid_tyBM *) p2);
}                               /* end idqcmp_BM */


static void rungui_BM (bool newgui, int nbjobs);

static void give_prog_version_BM (const char *progname);


//// see also https://github.com/dtrebbien/GNOME.supp and
//// https://stackoverflow.com/q/16659781/841108 to use valgrind with
//// GTK appplications
int
main (int argc, char **argv)
{
  clock_gettime (CLOCK_MONOTONIC, &startrealtimespec_BM);
  dlprog_BM = dlopen (NULL, RTLD_NOW | RTLD_GLOBAL);
  char *progname = argv[0];
  if (!dlprog_BM)
    {
      fprintf (stderr, "%s: dlopen for whole program fails %s\n",
               argv[0], dlerror ());
      exit (EXIT_FAILURE);
    }
  memset ((char *) myhostname_BM, 0, sizeof (myhostname_BM));
  if (gethostname ((char *) myhostname_BM, sizeof (myhostname_BM) - 1))
    FATAL_BM ("gethostname failure %m");
  initialize_garbage_collector_BM ();
  check_delims_BM ();
  initialize_globals_BM ();
  initialize_predefined_objects_BM ();
  initialize_predefined_names_BM ();
  initialize_agenda_BM ();
  /// should actually use gtk_init_with_args so define some
  /// GOptionEntry array
  GError *err = NULL;
  bool guiok = gtk_init_with_args (&argc, &argv, " - The bismon program",
                                   optab, NULL, &err);
  if (give_version_bm)
    give_prog_version_BM (progname);
  if (nbworkjobs_BM < MINNBWORKJOBS_BM)
    nbworkjobs_BM = MINNBWORKJOBS_BM;
  else if (nbworkjobs_BM > MAXNBWORKJOBS_BM)
    nbworkjobs_BM = MAXNBWORKJOBS_BM;
  DBGPRINTF_BM ("main begin tid#%ld pid %d",
                (long) gettid_BM (), (int) getpid ());
  if (count_emit_has_predef_bm > 0)
    {
      rawid_tyBM *idarr =
        calloc (count_emit_has_predef_bm, sizeof (rawid_tyBM));
      if (!idarr)
        FATAL_BM ("failed to calloc idarr for %d", count_emit_has_predef_bm);
      for (int ix = 0; ix < count_emit_has_predef_bm; ix++)
        idarr[ix] = randomid_BM ();
      qsort (idarr, count_emit_has_predef_bm, sizeof (rawid_tyBM), idqcmp_BM);
      printf ("\n\n" "/// %d extra predefs\n", count_emit_has_predef_bm);
      printf ("// !@ %.2f\n", clocktime_BM (CLOCK_REALTIME));
      for (int ix = 0; ix < count_emit_has_predef_bm; ix++)
        {
          rawid_tyBM id = idarr[ix];
          char idbuf[32];
          memset (idbuf, 0, sizeof (idbuf));
          idtocbuf32_BM (id, idbuf);
          printf ("HAS_PREDEF_BM(%s,%lld,%lld,%u)\n",
                  idbuf, (long long) id.id_hi, (long long) id.id_lo,
                  hashid_BM (id));
        }
      printf ("\n\n/***\n");
      for (int ix = 0; ix < count_emit_has_predef_bm; ix++)
        {
          rawid_tyBM id = idarr[ix];
          char idbuf[32];
          memset (idbuf, 0, sizeof (idbuf));
          idtocbuf32_BM (id, idbuf);
          printf (" ROUTINEOBJNAME_BM (%s)\n", idbuf);
        }
      printf ("***/\n\n\n");
    }
  if (!guiok && !batch_bm)
    FATAL_BM ("gtk_init_with_args failed");
  if (!batch_bm)
    {
      if (!oldgui_BM)
        initialize_newgui_BM (builder_file_bm, css_file_bm);
      else
        initialize_gui_BM (builder_file_bm, css_file_bm);
    }
  if (!load_dir_bm)
    load_dir_bm = ".";
  if (!dump_dir_bm)
    dump_dir_bm = load_dir_bm;
  load_initial_BM (load_dir_bm);
  if (nb_added_predef_bm > 0)
    add_new_predefined_bm ();
  if (dump_after_load_dir_bm)
    {
      struct dumpinfo_stBM di = dump_BM (dump_after_load_dir_bm, NULL);
      printf ("dump after load into %s directory", dump_after_load_dir_bm);
      char *rd = realpath (dump_after_load_dir_bm, NULL);
      if (rd)
        {
          printf (" (%s)", rd);
          free (rd), rd = NULL;
        };
      putchar ('\n');
      printf ("dump: scanned %ld, emitted %ld objects\n",
              di.dumpinfo_scanedobjectcount, di.dumpinfo_emittedobjectcount);
      printf ("... did %ld todos, wrote %ld files\n",
              di.dumpinfo_todocount, di.dumpinfo_wrotefilecount);
      printf
        ("... in %.3f elapsed, %.4f cpu seconds\n (%.1f elapsed, %.1f cpu µs/obj)\n",
         di.dumpinfo_elapsedtime, di.dumpinfo_cputime,
         di.dumpinfo_elapsedtime * 1.0e6 / di.dumpinfo_emittedobjectcount,
         di.dumpinfo_cputime * 1.0e6 / di.dumpinfo_emittedobjectcount);
    }
  if (batch_bm)
    {
      nbworkjobs_BM = 0;
      printf ("no GUI in batch mode\n");
    }
  else
    rungui_BM (!oldgui_BM, nbworkjobs_BM);
  fflush (NULL);
}                               /* end main */

extern bool did_deferredgtk_BM (void);

static gboolean
deferpipereadhandler_BM (GIOChannel * source,
                         GIOCondition condition __attribute__ ((unused)),
                         gpointer data __attribute__ ((unused)))
{
  NONPRINTF_BM ("deferpipereadhandler_BM start tid#%ld", (long) gettid_BM ());
  if (!source)
    return false;
  gchar buf[8] = "";
  for (;;)
    {
      memset (buf, 0, sizeof (buf));
      gsize nbrd = 0;
      // reading more than one byte each time can block the program
      GIOStatus st = g_io_channel_read_chars (source, buf, 1,
                                              &nbrd, NULL);
      NONPRINTF_BM ("deferpipereadhandler_BM nbrd=%d buf '%s' st#%d tid#%ld",
                    (int) nbrd, buf, (int) st, (long) gettid_BM ());
      if (st == G_IO_STATUS_EOF)
        return FALSE;
      if (!did_deferredgtk_BM ())
        return TRUE;
      if (st == G_IO_STATUS_NORMAL && nbrd > 0)
        return TRUE;
    }
  return TRUE;                  // to keep watching
}                               /* end deferpipereadhandler_BM */


extern void do_internal_deferred_apply3_gtk_BM (value_tyBM funv,
                                                value_tyBM arg1,
                                                value_tyBM arg2,
                                                value_tyBM arg3);
extern void do_internal_deferred_send3_gtk_BM (value_tyBM recv,
                                               objectval_tyBM * obsel,
                                               value_tyBM arg1,
                                               value_tyBM arg2,
                                               value_tyBM arg3);

// called from did_deferredgtk_BM
void
do_internal_deferred_apply3_gtk_BM (value_tyBM fun,
                                    value_tyBM arg1, value_tyBM arg2,
                                    value_tyBM arg3)
{
  LOCALFRAME_BM ( /*prev stackf: */ NULL, /*descr: */ NULL,
                 value_tyBM funv; value_tyBM arg1v, arg2v, arg3v;
                 value_tyBM failres;
    );
  _.funv = fun;
  _.arg1v = arg1;
  _.arg2v = arg2;
  _.arg3v = arg3;
  int failcod = 0;
  LOCAL_FAILURE_HANDLE_BM (failcod, _.failres);
  if (failcod)
    {
      fprintf (stderr, "deffered_apply3_gtk failure, failcod#%d\n", failcod);
      curfailurehandle_BM = NULL;
      return;
    }
  NONPRINTF_BM ("internaldeferapply funv %s arg1 %s arg2 %s arg3 %s",   //
                debug_outstr_value_BM (_.funv,  //
                                       (struct stackframe_stBM *) &_, 0),       //
                debug_outstr_value_BM (_.arg1v, //
                                       (struct stackframe_stBM *) &_, 0),       //
                debug_outstr_value_BM (_.arg2v, //
                                       (struct stackframe_stBM *) &_, 0),       //
                debug_outstr_value_BM (_.arg3v, //
                                       (struct stackframe_stBM *) &_, 0));
  (void) apply3_BM (_.funv, (struct stackframe_stBM *) &_, _.arg1v, _.arg2v,
                    _.arg3v);
  NONPRINTF_BM ("internaldeferapply applied funv %s",   //
                debug_outstr_value_BM (_.funv,  //
                                       (struct stackframe_stBM *) &_, 0));
  curfailurehandle_BM = NULL;
}                               /* end do_internal_defer_apply3_BM */


// called from did_deferredgtk_BM
void
do_internal_deferred_send3_gtk_BM (value_tyBM recv, objectval_tyBM * obsel,
                                   value_tyBM arg1, value_tyBM arg2,
                                   value_tyBM arg3)
{
  LOCALFRAME_BM ( /*prev stackf: */ NULL, /*descr: */ NULL,
                 objectval_tyBM * obsel;
                 value_tyBM recva, arg1v, arg2v, arg3v;
                 value_tyBM failres;
    );
  _.recva = recv;
  _.obsel = obsel;
  _.arg1v = arg1;
  _.arg2v = arg2;
  _.arg3v = arg3;
  int failcod = 0;
  LOCAL_FAILURE_HANDLE_BM (failcod, _.failres);
  if (failcod)
    {
      fprintf (stderr, "deffered_send3_gtk failure, failcod#%d\n", failcod);
      curfailurehandle_BM = NULL;
      return;
    }
  DBGPRINTF_BM ("internaldefersend recv %s obsel %s arg1 %s arg2 %s arg3 %s",   //
                debug_outstr_value_BM (_.recva, //
                                       (struct stackframe_stBM *) &_, 0),       //
                objectdbg_BM (_.obsel), //
                debug_outstr_value_BM (_.arg1v, //
                                       (struct stackframe_stBM *) &_, 0),       //
                debug_outstr_value_BM (_.arg2v, //
                                       (struct stackframe_stBM *) &_, 0),       //
                debug_outstr_value_BM (_.arg3v, //
                                       (struct stackframe_stBM *) &_, 0));
  (void) send3_BM (recv, obsel, (struct stackframe_stBM *) &_, arg1, arg2,
                   arg3);
  DBGPRINTF_BM ("internaldefersend did send recv %s obsel %s",  //
                debug_outstr_value_BM (_.recva, //
                                       (struct stackframe_stBM *) &_, 0),       //
                objectdbg_BM (_.obsel));
  curfailurehandle_BM = NULL;
}                               /* end do_internal_defer_send3_BM */


static void startguilog_BM (bool newgui);
static void endguilog_BM (void);


////////////////////////////////////////////////////////////////
void
rungui_BM (bool newgui, int nbjobs)
{
  NONPRINTF_BM ("rungui %s nbjobs %d start tid#%ld", newgui ? "new" : "old",
                nbjobs, (long) gettid_BM ());
  int deferpipes[2] = { -1, -1 };
  if (pipe (deferpipes) < 0)
    FATAL_BM ("failed to pipe GTK deferpipe");
  defer_gtk_readpipefd_BM = deferpipes[0];
  defer_gtk_writepipefd_BM = deferpipes[1];
  NONPRINTF_BM ("rungui defer_gtk_readpipefd=%d defer_gtk_writepipefd_BM=%d",
                defer_gtk_readpipefd_BM, defer_gtk_writepipefd_BM);
  defer_gtk_readpipechan_BM = g_io_channel_unix_new (defer_gtk_readpipefd_BM);
  g_io_add_watch (defer_gtk_readpipechan_BM, G_IO_IN, deferpipereadhandler_BM,
                  NULL);
  gui_is_running_BM = true;
  startguilog_BM (newgui);
  start_agenda_work_threads_BM (nbjobs);
  NONPRINTF_BM ("rungui %s nbjobs %d before gtkmain", newgui ? "new" : "old",
                nbjobs);
  gtk_main ();
  NONPRINTF_BM
    ("rungui %s nbjobs %d after gtkmain before stopagendawork tid#%ld elapsed %.3f s",
     newgui ? "new" : "old", nbjobs, (long) gettid_BM (), elapsedtime_BM ());
  stop_agenda_work_threads_BM ();
  NONPRINTF_BM ("rungui %s nbjobs %d after stopagendawork elapsed %.3f s",
                newgui ? "new" : "old", nbjobs, elapsedtime_BM ());
  g_io_channel_shutdown (defer_gtk_readpipechan_BM, false, NULL);
  g_io_channel_unref (defer_gtk_readpipechan_BM), defer_gtk_readpipechan_BM =
    NULL;
  close (defer_gtk_readpipefd_BM), defer_gtk_readpipefd_BM = -1;
  close (defer_gtk_writepipefd_BM), defer_gtk_writepipefd_BM = -1;
  gui_is_running_BM = false;
  if (gui_command_log_file_BM)
    endguilog_BM ();
  NONPRINTF_BM ("rungui %s nbjobs %d ending tid#%ld elapsed %.3f s",
                newgui ? "new" : "old", nbjobs, (long) gettid_BM (),
                elapsedtime_BM ());
}                               /* end rungui_BM */


void
startguilog_BM (bool newgui)
{
  if (!gui_log_name_bm || !gui_log_name_bm[0])
    {
      gui_command_log_file_BM = NULL;
      printf ("no %s GUI log\n", newgui ? "new" : "old");
    }
  else if (!strcmp (gui_log_name_bm, "-"))
    {
      gui_command_log_file_BM = stdout;
      printf ("%s GUI log to stdout\n", newgui ? "new" : "old");
    }
  else
    {
      if (!access (gui_log_name_bm, R_OK))
        {
          char *backupath = NULL;
          asprintf (&backupath, "%s~", gui_log_name_bm);
          if (!backupath)
            FATAL_BM ("asprintf fail for backupath %s (%m)", gui_log_name_bm);
          (void) rename (gui_log_name_bm, backupath);
          free (backupath), backupath = NULL;
        };
      gui_command_log_file_BM = fopen (gui_log_name_bm, "w");
      if (!gui_command_log_file_BM)
        FATAL_BM ("fopen GUI log %s failure (%m)", gui_log_name_bm);
      fprintf (stderr, "%s GUI log to %s\n", newgui ? "new" : "old",
               gui_log_name_bm);
      fprintf (gui_command_log_file_BM, "// %s GUI command log file %s\n",
               newgui ? "new" : "old", basename (gui_log_name_bm));
    }
  if (gui_command_log_file_BM)
    {
      {
        time_t nowtim = time (NULL);
        struct tm nowtm = { };
        localtime_r (&nowtim, &nowtm);
        char nowbuf[64];
        memset (nowbuf, 0, sizeof (nowbuf));
        strftime (nowbuf, sizeof (nowbuf), "%c", &nowtm);
        fprintf (gui_command_log_file_BM,
                 "// bismon GUI log at %s on %s pid %d\n",
                 nowbuf, myhostname_BM, (int) getpid ());
      }
      fprintf (gui_command_log_file_BM,
               "// bismon checksum %s lastgitcommit %s\n", bismon_checksum,
               bismon_lastgitcommit);
      fprintf (gui_command_log_file_BM,
               "// bismon timestamp %s directory %s\n", bismon_timestamp,
               bismon_directory);
      {
        char curdirpath[128];
        memset (curdirpath, 0, sizeof (curdirpath));
        if (getcwd (curdirpath, sizeof (curdirpath) - 1))
          fprintf (gui_command_log_file_BM,
                   "// bismon current directory %s\n", curdirpath);
        else
          FATAL_BM ("getcwd failure %m");
      }
      fflush (gui_command_log_file_BM);
    }
}                               /* end startguilog_BM */

void
endguilog_BM (void)
{
  time_t nowtim = time (NULL);
  struct tm nowtm = { };
  localtime_r (&nowtim, &nowtm);
  char nowbuf[64];
  memset (nowbuf, 0, sizeof (nowbuf));
  strftime (nowbuf, sizeof (nowbuf), "%c", &nowtm);
  fprintf (gui_command_log_file_BM,
           "\n\f/// end of bismon GUI command log file %s at %s\n",
           gui_log_name_bm, nowbuf);
  if (gui_command_log_file_BM != stdout && gui_command_log_file_BM != stderr)
    fclose (gui_command_log_file_BM);
  gui_command_log_file_BM = NULL;
  fflush (NULL);
}                               /* end endguilog_BM */


void
give_prog_version_BM (const char *progname)
{
  printf ("%s: version information\n", progname);
  printf ("\t timestamp: %s\n", bismon_timestamp);
  printf ("\t last git commit: %s\n", bismon_lastgitcommit);
  printf ("\t last git tag: %s\n", bismon_lastgittag);
  printf ("\t source checksum: %s\n", bismon_checksum);
  printf ("\t source dir: %s\n", bismon_directory);
  printf ("\t makefile: %s\n", bismon_makefile);
  printf ("########\n");
  printf ("run\n" "\t   %s --help\n" "to get help.\n", progname);
  exit (EXIT_SUCCESS);
}                               /* end give_prog_version_BM */
