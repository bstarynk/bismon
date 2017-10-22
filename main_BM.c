// file main_BM.c
#include "bismon.h"

struct timespec startrealtimespec_BM;
void *dlprog_BM;
bool gui_is_running_BM;
const char myhostname_BM[80];

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
bool newgui_BM;
char *parseval_bm;

static void add_new_predefined_bm (void);

static bool
run_command_bm (const gchar * optname
                __attribute__ ((unused)), const gchar * val, gpointer data
                __attribute__ ((unused)), GError ** perr)
{
  assert (val != NULL);
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
  assert (val != NULL);
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
}                               /* end run_command_bm */

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
  {.long_name = "new-gui",.short_name = (char) 'N',
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_NONE,
   .arg_data = &newgui_BM,
   .description = "run the new GUI",
   .arg_description = NULL},
  //
  {.long_name = "parse-val",.short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_FILENAME,
   .arg_data = &parseval_bm,
   .description = "parse value from FILE (use - for stdin)",
   .arg_description = "FILE"},
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


static void rungui_BM (bool newgui);
//// see also https://github.com/dtrebbien/GNOME.supp and
//// https://stackoverflow.com/q/16659781/841108 to use valgrind with
//// GTK appplications
int
main (int argc, char **argv)
{
  clock_gettime (CLOCK_MONOTONIC, &startrealtimespec_BM);
  dlprog_BM = dlopen (NULL, RTLD_NOW | RTLD_GLOBAL);
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
  /// should actually use gtk_init_with_args so define some
  /// GOptionEntry array
  GError *err = NULL;
  bool guiok = gtk_init_with_args (&argc, &argv, " - The bismon program",
                                   optab, NULL, &err);
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
      if (newgui_BM)
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
  if (parseval_bm)
    {
      FILE *pfil =
        strcmp (parseval_bm, "-") ? fopen (parseval_bm, "r") : stdin;
      if (!pfil)
        FATAL_BM ("failed to open %s for parsing value (%m)", parseval_bm);
      printf ("parsing value from %s...\n", parseval_bm);
      fflush (NULL);
      struct parser_stBM *parsin = makeparser_of_file_BM (pfil);
      parsin->pars_path = parseval_bm;
      parserskipspaces_BM (parsin);
      bool gotval = false;
      value_tyBM val = parsergetvalue_BM (parsin, NULL, 0, &gotval);
      if (!gotval)
        FATAL_BM ("parsing %s failed", parseval_bm);
      if (val)
        printf ("parsed non-nil value from %s\n", parseval_bm);
      else
        printf ("parsed nil from %s\n", parseval_bm);
      if (pfil != stdin)
        fclose (pfil);
      fflush (NULL);
    }
  if (dump_after_load_dir_bm)
    {
      struct dumpinfo_stBM di = dump_BM (dump_after_load_dir_bm, NULL);
      printf ("dump after load into %s directory", dump_after_load_dir_bm);
      char *rd = realpath (dump_after_load_dir_bm, NULL);
      if (rd)
        {
          printf (" (%s)", rd);
          free (rd);
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
      printf ("no GUI in batch mode\n");
    }
  else
    rungui_BM (newgui_BM);
  fflush (NULL);
}                               /* end main */

void
rungui_BM (bool newgui)
{
  gui_is_running_BM = true;
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
          free (backupath);
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
  gtk_main ();
  gui_is_running_BM = false;
  if (gui_command_log_file_BM)
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
      if (gui_command_log_file_BM != stdout
          && gui_command_log_file_BM != stderr)
        fclose (gui_command_log_file_BM);
      gui_command_log_file_BM = NULL;
      fflush (NULL);
    }
}                               /* end rungui_BM */
