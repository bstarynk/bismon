// file main_BM.c
#include "bismon.h"

struct timespec startrealtimespec_BM;
void *dlprog_BM;

void
abort_BM (void)
{
  fflush (NULL);
  abort ();
}                               /* end abort_BM */


////////////////////////////////////////////////////////////////
char *load_dir_bm;
char *dump_dir_bm;
char *dump_after_load_dir_bm;
char *builder_file_bm = "bismon.ui";
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
   .description = "with GTK builer file FILE",
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
  /// just to test the macro LOCALQNODESIZED_BM
  {
    LOCALQNODESIZED_BM (qns, BMP_node, 4);
    assert (qns.__ntree.nodt_conn == BMP_node);
    assert (qns.qsons[2] == NULL);
    assert (treewidth_BM (&qns) == 4);
  }
  // just to test the macro LOCALQNODEFIELDED_BM
  {
    LOCALQNODEFIELDED_BM (qnf, BMP_embed, value_tyBM * v1;
                          value_tyBM * v2, *v3;);
    assert (qnf.__ftree.nodt_conn == BMP_embed);
    assert (qnf.v2 == NULL);
    assert (treewidth_BM (&qnf) == 3);
  }
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
      printf ("\n\n" "/// %d extra predefs\n", count_emit_has_predef_bm);
      printf ("// !@ %.2f\n", clocktime_BM (CLOCK_REALTIME));
      for (int ix = count_emit_has_predef_bm; ix > 0; ix--)
        {
          rawid_tyBM id = randomid_BM ();
          char idbuf[32];
          memset (idbuf, 0, sizeof (idbuf));
          idtocbuf32_BM (id, idbuf);
          printf ("HAS_PREDEF_BM(%s,%lld,%lld,%u)\n",
                  idbuf, (long long) id.id_hi, (long long) id.id_lo,
                  hashid_BM (id));
        }
      printf ("\n\n");
    }
  if (!guiok)
    FATAL_BM ("gtk_init_with_args failed");
  if (!batch_bm)
    initialize_gui_BM (builder_file_bm);
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
    dump_BM (dump_after_load_dir_bm, NULL);
  if (batch_bm)
    {
      printf ("no GUI in batch mode\n");
    }
  else
    {
      gtk_main ();
    }
  fflush (NULL);
}                               /* end main */
