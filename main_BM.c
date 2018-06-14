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

#if defined(BISMONGTK) && defined(BISMONION)
#error cannot have both BISMONGTK and BISMONION
#endif /*defined(BISMONGTK) && defined(BISMONION) */

#ifdef BISMONGTK
#include <glib/giochannel.h>
#endif

struct timespec startrealtimespec_BM;
void *dlprog_BM;
bool gui_is_running_BM;
bool debugmsg_BM;
int nbworkjobs_BM;
const char myhostname_BM[80];
thread_local struct threadinfo_stBM *curthreadinfo_BM;
thread_local volatile struct failurehandler_stBM *curfailurehandle_BM;

static volatile struct backstrace_state *backtracestate_BM;
static void backtracerrorcb_BM (void *data, const char *msg, int errnum);

#ifdef BISMONGTK
GIOChannel *defer_gtk_readpipechan_BM;
int defer_gtk_readpipefd_BM = -1;
int defer_gtk_writepipefd_BM = -1;
#endif /*BISMONGTK*/
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
  char thnambuf[16];
  memset (thnambuf, 0, sizeof (thnambuf));
  pthread_getname_np (pthread_self (), thnambuf, sizeof (thnambuf));
  fprintf (stderr, "**** weakassertfailureat_BM (%s:%d) %s (tid#%d/%s)\n",
           fil, lin, condmsg, (int) gettid_BM (), thnambuf);
  fflush (stderr);
  void *backbuf[50];
  memset (backbuf, 0, sizeof (backbuf));
  int nb = backtrace (backbuf, sizeof (backbuf) / sizeof (void *));
  backtrace_symbols_fd (backbuf, nb, STDERR_FILENO);
  if (backtracestate_BM)
    {
      fprintf (stderr, "\n\n\n** full backtrace **\n");
      fflush (stderr);
      backtrace_print_BM ((struct backtrace_state *) backtracestate_BM, 1,
                          stderr);
      fprintf (stderr, "\n----- end full backtrace ------\n\n");
      fflush (stderr);
    }
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
char *module_to_emit_bm;
int count_emit_has_predef_bm;
int nb_added_predef_bm;
#define MAXADDEDPREDEF_BM 16
struct
{
  const char *pr_comment;
  const char *pr_name;
} added_predef_bm[MAXADDEDPREDEF_BM];

#define MAXPARSED_VALUES_AFTER_LOAD_BM 10
char *parsed_values_after_loadarr_bm[MAXPARSED_VALUES_AFTER_LOAD_BM];
int nb_parsed_values_after_load_bm;


bool batch_bm;
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
      if (!curfailurehandle_BM->failh_silent)
        {
          char thnambuf[16];
          memset (thnambuf, 0, sizeof (thnambuf));
          pthread_getname_np (pthread_self (), thnambuf, sizeof (thnambuf));
          fprintf (stderr, "\n\n*** failure code#%d %s:%d (tid#%d/%s) ***\n",
                   failcode, fil ? fil : "???", lineno, (int) gettid_BM (),
                   thnambuf);
          if (backtracestate_BM)
            {
              backtrace_print_BM ((struct backtrace_state *)
                                  backtracestate_BM, 1, stderr);
              fprintf (stderr, "\n----- end failure backtrace ------\n\n");
            }
          fflush (stderr);
        }
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

void
fatal_stop_at_BM (const char *fil, int lineno)
{
  char thnambuf[16];
  memset (thnambuf, 0, sizeof (thnambuf));
  pthread_getname_np (pthread_self (), thnambuf, sizeof (thnambuf));
  fprintf (stderr, "** FATAL STOP %s:%d (tid#%d/%s)\n",
           fil ? fil : "???", lineno, (int) gettid_BM (), thnambuf);
  fflush (stderr);
  void *backarr[2 * TINYSIZE_BM];
  memset (backarr, 0, sizeof (backarr));
  int backdepth = backtrace (backarr, sizeof (backarr) / sizeof (void *));
  backtrace_symbols_fd (backarr, backdepth, STDERR_FILENO);
  if (backtracestate_BM)
    {
      fprintf (stderr, "\n\n\n** full fatal backtrace **\n");
      fflush (stderr);
      backtrace_print_BM ((struct backtrace_state *) backtracestate_BM, 1,
                          stderr);
      fprintf (stderr, "\n----- end full fatal backtrace ------\n\n");
    }
  fflush (stderr);
  abort_BM ();
}                               /* end fatal_stop_at_BM */


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

static void
get_parse_value_after_load_bm (const gchar * optname __attribute__ ((unused)),
                               const gchar * val,
                               gpointer data __attribute__ ((unused)),
                               GError ** perr __attribute__ ((unused)))
{
  if (nb_parsed_values_after_load_bm >= MAXPARSED_VALUES_AFTER_LOAD_BM)
    FATAL_BM ("too many %d parsed values after load with --parse-value",
              nb_parsed_values_after_load_bm);
  NONPRINTF_BM ("get_parse_value_after_load #%d.. valen=%d:\n%s",
                nb_parsed_values_after_load_bm, (int) strlen (val), val);
  parsed_values_after_loadarr_bm[nb_parsed_values_after_load_bm++] =
    strdup (val);
}                               /* end get_parse_value_after_load_bm */


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
  {.long_name = "parse-value",.short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_CALLBACK,
   .arg_data = &get_parse_value_after_load_bm,
   .description = "parse (after loading) the value EXPR",
   .arg_description = "EXPR"},

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
  {.long_name = "debug",.short_name = (char) 'D',
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_NONE,
   .arg_data = &debugmsg_BM,
   .description = "gives lots of debug messages",
   .arg_description = NULL},
  //
  {.long_name = "emit-module",.short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_STRING,
   .arg_data = &module_to_emit_bm,
   .description = "emit module MODULEOBJ",
   .arg_description = "MODULEOBJ"},
  //
  //
  {.long_name = "version",.short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_NONE,
   .arg_data = &give_version_bm,
   .description = "gives version information",
   .arg_description = NULL},
  //
#ifdef BISMONGTK
  //////////////////
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
  {.long_name = "gui-log",.short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_FILENAME,
   .arg_data = &gui_log_name_bm,
   .description =
   "GUI log file name (none if empty, - is stdout, default is _bismon.log)",
   .arg_description = "FILE"},
#endif /*BISMONGTK*/
    //////////////////
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


static void rungui_BM (int nbjobs);

static void parse_values_after_load_bm (void);

static void give_prog_version_BM (const char *progname);

static void do_emit_module_from_main_BM (void);

void
do_emit_module_from_main_BM (void)
{
  WEAKASSERT_BM (module_to_emit_bm != NULL);
  LOCALFRAME_BM (NULL, /*descr: */ BMP_emit_module,
                 objectval_tyBM * modulob;
                 objectval_tyBM * parsob; value_tyBM resultv;
                 value_tyBM failres;
    );
  _.failres = NULL;
  int failcod = 0;
  struct failurelockset_stBM flockset = { };
  struct failurehandler_stBM *prevfailurehandle =
    (struct failurehandler_stBM *) curfailurehandle_BM;
  initialize_failurelockset_BM (&flockset, sizeof (flockset));
  LOCAL_FAILURE_HANDLE_BM (&flockset, lab_failureemit, failcod, _.failres);
  if (failcod > 0)
  lab_failureemit:{
      destroy_failurelockset_BM (&flockset);
      curfailurehandle_BM = prevfailurehandle;
      {
        fprintf (stderr,
                 "Failed to emit module from main %s, with failcode#%d, failres %s\n",
                 objectdbg_BM (_.modulob), failcod,
                 debug_outstr_value_BM (_.failres, CURFRAME_BM, 0));
        return;
      };
    };
  fprintf (stderr, "begin emit module from main: %s\n", module_to_emit_bm);
  _.parsob = makeobj_BM ();
  bool gotobj = false;
  struct parser_stBM *pars =
    makeparser_memopen_BM (module_to_emit_bm, strlen (module_to_emit_bm),
                           _.parsob);
  _.modulob = parsergetobject_BM (pars, CURFRAME_BM, 0, &gotobj);
  DBGPRINTF_BM ("do_emit_module_from_main_BM modulob=%s parsob=%s",
                objectdbg_BM (_.modulob), objectdbg1_BM (_.parsob));
  objlock_BM (_.modulob);
  _.resultv = send0_BM (_.modulob, BMP_emit_module, CURFRAME_BM);
  objunlock_BM (_.modulob);
  objclearpayload_BM (_.parsob);
  destroy_failurelockset_BM (&flockset);
  curfailurehandle_BM = prevfailurehandle;
  DBGPRINTF_BM ("do_emit_module_from_main_bm end modulob=%s result %s", //
                objectdbg_BM (_.modulob),       //
                debug_outstr_value_BM (_.resultv, CURFRAME_BM, 0));
  if (_.resultv)
    fprintf (stderr, "\nsuccessful emit module from main: %s\n",
             module_to_emit_bm);
  else
    FATAL_BM ("failed emit module from main: %s", module_to_emit_bm);
  char modulidbuf[32];
  memset (modulidbuf, 0, sizeof (modulidbuf));
  idtocbuf32_BM (objid_BM (_.modulob), modulidbuf);
  char makemodulecmd[128];
  memset (makemodulecmd, 0, sizeof (makemodulecmd));
  snprintf (makemodulecmd, sizeof (makemodulecmd),
            "%s/build-bismon-module.sh %s", bismon_directory, modulidbuf);
  DBGPRINTF_BM ("do_emit_module_from_main_bm makemodulecmd=%s",
                makemodulecmd);
  fflush (NULL);
  int cmdcod = system (makemodulecmd);
  if (cmdcod)
    FATAL_BM ("failed module making %s (%d)", makemodulecmd, cmdcod);
  fprintf (stderr,
           "\n" "successfully compiled emitted module %s (%s) from main\n",
           module_to_emit_bm, modulidbuf);
  fflush (NULL);
  return;
}                               /* end do_emit_module_from_main_BM */


static void parse_values_after_load_BM (void);

//// see also https://github.com/dtrebbien/GNOME.supp and
//// https://stackoverflow.com/q/16659781/841108 to use valgrind with
//// GTK appplications
int
main (int argc, char **argv)
{
  clock_gettime (CLOCK_MONOTONIC, &startrealtimespec_BM);
  if (argc <= 0)
    {                           // this should never happen in practice, but see
      // https://stackoverflow.com/q/49817316/841108
      fprintf (stderr, "[bismon] requires at least one argument\n");
      exit (EXIT_FAILURE);
    }
  if (argc > 1 && !strcmp (argv[1], "-D") || !strcmp (argv[1], "--debug"))
    debugmsg_BM = true;
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
  {
    double nwt = clocktime_BM (CLOCK_REALTIME);
    intptr_t y2kwt = timetoY2Kmillisec_BM (nwt);
    NONPRINTF_BM ("nwt=%.4f y2kwt=%lld=%#llx as time=%.4f", nwt,
                  (long long) y2kwt, (long long) y2kwt,
                  Y2Kmillisectotime_BM (y2kwt));
    ASSERT_BM (abs (Y2Kmillisectotime_BM (y2kwt) - nwt) < 0.5);
  }
  backtracestate_BM             //
    = backtrace_create_state ( /*filename: */ NULL,
                              /*threaded: */ true,
                              /*errorcb: */
                              backtracerrorcb_BM,
                              /*data: */ NULL);
  initialize_garbage_collector_BM ();
  check_delims_BM ();
  initialize_globals_BM ();
  initialize_predefined_objects_BM ();
  initialize_predefined_names_BM ();
  initialize_agenda_BM ();
  GError *opterr = NULL;
#ifdef BISMONGTK
  /// should actually use gtk_init_with_args so define some
  /// GOptionEntry array
  bool guiok = gtk_init_with_args (&argc, &argv,
                                   " - The bismongtk program (with GTK GUI)",
                                   optab, NULL, &opterr);
#endif /*BISMONGTK*/
#ifdef BISMONION
  {
    GOptionContext *weboptctx =
      g_option_context_new ("- The bismonion program (with web interface)");
    if (!weboptctx)
      FATAL_BM ("no option context");
    g_option_context_add_main_entries (weboptctx, optab, NULL);
    if (!g_option_context_parse (weboptctx, &argc, &argv, &opterr))
      FATAL_BM ("bismonion failed to parse options - %s",
                opterr ? opterr->message : "??");
    g_option_context_free (weboptctx);
  }
#endif /*BISMONION*/
    if (give_version_bm)
    give_prog_version_BM (progname);
  if (nbworkjobs_BM < MINNBWORKJOBS_BM)
    nbworkjobs_BM = MINNBWORKJOBS_BM;
  else if (nbworkjobs_BM > MAXNBWORKJOBS_BM)
    nbworkjobs_BM = MAXNBWORKJOBS_BM;
  NONPRINTF_BM ("main begin tid#%ld pid %d",
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
      printf ("// !@ %.3f\n", clocktime_BM (CLOCK_REALTIME));
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
#ifdef BISMONGTK
  if (!guiok && !batch_bm)
    FATAL_BM ("gtk_init_with_args failed : %s",
              opterr ? opterr->message : "???");
  if (!batch_bm)
    {
      initialize_newgui_BM (builder_file_bm, css_file_bm);
    }
#endif /*BISMONGTK*/
    if (!load_dir_bm)
    load_dir_bm = ".";
  if (!dump_dir_bm)
    dump_dir_bm = load_dir_bm;
  load_initial_BM (load_dir_bm);
  if (nb_added_predef_bm > 0)
    add_new_predefined_bm ();
  if (nb_parsed_values_after_load_bm > 0)
    parse_values_after_load_BM ();
  if (module_to_emit_bm != NULL)
    do_emit_module_from_main_BM ();
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
#ifdef BISMONGTK
  if (batch_bm)
    {
      nbworkjobs_BM = 0;
      printf ("no GUI in batch mode\n");
    }
  else
    rungui_BM (nbworkjobs_BM);
#endif /*BISMONGTK*/
    fflush (NULL);
}                               /* end main */



void
parse_values_after_load_BM (void)
{
  LOCALFRAME_BM ( /*prev stackf: */ NULL, /*descr: */ NULL,
                 objectval_tyBM * parsob;
                 value_tyBM parsedval;
    );
  _.parsob = makeobj_BM ();
  fprintf (stderr, "parsing %d values after load %s using parsob %s\n",
           nb_parsed_values_after_load_bm, load_dir_bm,
           objectdbg_BM (_.parsob));
  for (int ix = 0; ix < nb_parsed_values_after_load_bm; ix++)
    {
      const char *curvalstr = parsed_values_after_loadarr_bm[ix];
      fprintf (stderr, "parsing value#%d:::\n%s\n///----\n", ix, curvalstr);
      struct parser_stBM *pars =
        makeparser_memopen_BM (curvalstr, strlen (curvalstr), _.parsob);
      ASSERT_BM (pars != NULL);
      bool gotval = false;
      _.parsedval = parsergetvalue_BM (pars, CURFRAME_BM, 0, &gotval);
      if (!gotval)
        FATAL_BM ("failed to parse value#%d", ix);
      fprintf (stderr, "parsed value#%d is:\n%s\n", ix,
               debug_outstr_value_BM (_.parsedval, CURFRAME_BM, 0));
      fflush (NULL);
      objclearpayload_BM (_.parsob);
    }
  for (int ix = 0; ix < nb_parsed_values_after_load_bm; ix++)
    {
      free (parsed_values_after_loadarr_bm[ix]),
        parsed_values_after_loadarr_bm[ix] = NULL;
    }
  fprintf (stderr, "done parsing %d values after load\n",
           nb_parsed_values_after_load_bm);
}                               /* end parse_values_after_load_bm */

#ifdef BISMONGTK
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
  _.failres = NULL;
  struct failurelockset_stBM flockset = { };
  initialize_failurelockset_BM (&flockset, sizeof (flockset));
  LOCAL_FAILURE_HANDLE_BM (&flockset, lab_failureapply, failcod, _.failres);
  if (failcod)
  lab_failureapply:
    {
      destroy_failurelockset_BM (&flockset);
      curfailurehandle_BM = NULL;
      fprintf (stderr, "deffered_apply3_gtk failure, failcod#%d failreason: %s\n", failcod,     //
               debug_outstr_value_BM (_.failres,        //
                                      CURFRAME_BM, 0));
      return;
    }
  NONPRINTF_BM ("internaldeferapply funv %s arg1 %s arg2 %s arg3 %s",   //
                debug_outstr_value_BM (_.funv,  //
                                       CURFRAME_BM, 0), //
                debug_outstr_value_BM (_.arg1v, //
                                       CURFRAME_BM, 0), //
                debug_outstr_value_BM (_.arg2v, //
                                       CURFRAME_BM, 0), //
                debug_outstr_value_BM (_.arg3v, //
                                       CURFRAME_BM, 0));
  (void) apply3_BM (_.funv, CURFRAME_BM, _.arg1v, _.arg2v, _.arg3v);
  NONPRINTF_BM ("internaldeferapply applied funv %s",   //
                debug_outstr_value_BM (_.funv,  //
                                       CURFRAME_BM, 0));
  destroy_failurelockset_BM (&flockset);
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
  _.failres = NULL;
  struct failurelockset_stBM flockset = { };
  initialize_failurelockset_BM (&flockset, sizeof (flockset));
  LOCAL_FAILURE_HANDLE_BM (&flockset, lab_failuresend, failcod, _.failres);
  if (failcod)
  lab_failuresend:
    {
      destroy_failurelockset_BM (&flockset);
      curfailurehandle_BM = NULL;
      fprintf (stderr, "deffered_send3_gtk failure, failcod#%d failreason: %s\n",       //
               failcod, debug_outstr_value_BM (_.failres, CURFRAME_BM, 0));
      return;
    }
  DBGPRINTF_BM ("internaldefersend recv %s obsel %s arg1 %s arg2 %s arg3 %s",   //
                debug_outstr_value_BM (_.recva, //
                                       CURFRAME_BM, 0), //
                objectdbg_BM (_.obsel), //
                debug_outstr_value_BM (_.arg1v, //
                                       CURFRAME_BM, 0), //
                debug_outstr_value_BM (_.arg2v, //
                                       CURFRAME_BM, 0), //
                debug_outstr_value_BM (_.arg3v, //
                                       CURFRAME_BM, 0));
  (void) send3_BM (recv, obsel, CURFRAME_BM, arg1, arg2, arg3);
  DBGPRINTF_BM ("internaldefersend did send recv %s obsel %s",  //
                debug_outstr_value_BM (_.recva, //
                                       CURFRAME_BM, 0), //
                objectdbg_BM (_.obsel));
  destroy_failurelockset_BM (&flockset);
  curfailurehandle_BM = NULL;
}                               /* end do_internal_defer_send3_BM */


static void startguilog_BM (void);
static void endguilog_BM (void);


////////////////////////////////////////////////////////////////
void
rungui_BM (int nbjobs)
{
  NONPRINTF_BM ("rungui nbjobs %d start tid#%ld",
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
  startguilog_BM ();
  start_agenda_work_threads_BM (nbjobs);
  NONPRINTF_BM ("rungui nbjobs %d before gtkmain", nbjobs);
  gtk_main ();
  NONPRINTF_BM
    ("rungui nbjobs %d after gtkmain before stopagendawork tid#%ld elapsed %.3f s",
     nbjobs, (long) gettid_BM (), elapsedtime_BM ());
  stop_agenda_work_threads_BM ();
  NONPRINTF_BM ("rungui nbjobs %d after stopagendawork elapsed %.3f s",
                nbjobs, elapsedtime_BM ());
  g_io_channel_shutdown (defer_gtk_readpipechan_BM, false, NULL);
  g_io_channel_unref (defer_gtk_readpipechan_BM), defer_gtk_readpipechan_BM =
    NULL;
  close (defer_gtk_readpipefd_BM), defer_gtk_readpipefd_BM = -1;
  close (defer_gtk_writepipefd_BM), defer_gtk_writepipefd_BM = -1;
  gui_is_running_BM = false;
  if (gui_command_log_file_BM)
    endguilog_BM ();
  NONPRINTF_BM ("rungui nbjobs %d ending tid#%ld elapsed %.3f s",
                nbjobs, (long) gettid_BM (), elapsedtime_BM ());
}                               /* end rungui_BM */


void
startguilog_BM (void)
{
  if (!gui_log_name_bm || !gui_log_name_bm[0])
    {
      gui_command_log_file_BM = NULL;
      printf ("no GUI log\n");
    }
  else if (!strcmp (gui_log_name_bm, "-"))
    {
      gui_command_log_file_BM = stdout;
      printf ("GUI log to stdout\n");
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
      fprintf (stderr, "GUI log to %s\n", gui_log_name_bm);
      fprintf (gui_command_log_file_BM, "// GUI command log file %s\n",
               basename (gui_log_name_bm));
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
#endif /*BISMONGTK*/
////////////////////////////////////////////////////////////////
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

void
backtracerrorcb_BM (void *data __attribute__ ((unused)),
                    const char *msg, int errnum)
{
  backtracestate_BM = NULL;
  FATAL_BM ("backtrace error: %s #%d", msg, errnum);
}                               /* end backtracerrorcb_BM */


////////////////////////////////////////////////////////////////

/// nearly copied from Ian Taylor's libbacktrace/print.c
struct print_data_BM
{
  struct backtrace_state *state;
  FILE *f;
};
/* Print one level of a backtrace.  */

static int
printbt_callback_BM (void *data, uintptr_t pc, const char *filename,
                     int lineno, const char *function)
{
  struct print_data_BM *pdata = (struct print_data_BM *) data;

  const char *funame = function;
  char nambuf[80];
  memset (nambuf, 0, sizeof (nambuf));
  if (!funame)
    {
      Dl_info di;
      memset (&di, 0, sizeof (di));
      if (dladdr ((void *) pc, &di))
        {
          if (di.dli_sname)
            {
              fprintf (pdata->f, "0x%lx @%s+%#lx\n",
                       (unsigned long) pc, di.dli_sname,
                       (char *) pc - (char *) di.dli_saddr);
            }
          else if (di.dli_fname)
            {
              fprintf (pdata->f, "0x%lx @@%s+%#lx\n",
                       (unsigned long) pc, basename (di.dli_fname),
                       (char *) pc - (char *) di.dli_fbase);
            }
          else
            fprintf (pdata->f, "0x%lx ?-?\n", (unsigned long) pc);
        }
      else
        fprintf (pdata->f, "0x%lx ???\n", (unsigned long) pc);
    }
  else
    fprintf (pdata->f, "0x%lx %s\n", (unsigned long) pc, funame);
  if (filename)
    fprintf (pdata->f, "\t%s:%d\n", basename (filename), lineno);
  return 0;
}                               /* end printbt_callback_BM */

/* Print errors to stderr.  */

static void
errorbt_callback_BM (void *data_
                     __attribute__ ((unused)), const char *msg, int errnum)
{
  //  struct print_data_BM *pdata = (struct print_data_BM *) data;

  //if (pdata->state->filename != NULL)
  //  fprintf (stderr, "%s: ", pdata->state->filename);
  fprintf (stderr, "libbacktrace: %s", msg);
  if (errnum > 0)
    fprintf (stderr, ": %s", strerror (errnum));
  fputc ('\n', stderr);
}

/* Print a backtrace.  */

void
backtrace_print_BM (struct backtrace_state *state, int skip, FILE * f)
{
  struct print_data_BM data;

  data.state = state;
  data.f = f;
  backtrace_full (state, skip + 1, printbt_callback_BM, errorbt_callback_BM,
                  (void *) &data);
}                               /* end backtrace_print_BM */
