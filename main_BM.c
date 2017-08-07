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
int count_emit_has_predef_bm;

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

const GOptionEntry optab[] = {
  {.long_name = "load",.short_name = 'l',
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_FILENAME,
   .arg_data = &load_dir_bm,
   .description = "load directory DIR (default is .)",
   .arg_description = "DIR"},
  {.long_name = "dump",.short_name = 'd',
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_FILENAME,
   .arg_data = &dump_dir_bm,
   .description = "dump directory DIR",
   .arg_description = "DIR"},
  {.long_name = "dump-after-load",.short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_FILENAME,
   .arg_data = &dump_after_load_dir_bm,
   .description = "dump after load directory DIR",
   .arg_description = "DIR"},
  {.long_name = "emit-has-predef",.short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_INT,
   .arg_data = &count_emit_has_predef_bm,
   .description = "emit NB 'HAS_PREDEF_BM'",
   .arg_description = "NB"},
  {.long_name = "run-command",.short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_CALLBACK,
   .arg_data = &run_command_bm,
   .description = "run the command CMD",
   .arg_description = "CMD"},
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
  load_initial_BM (load_dir_bm);
  if (dump_after_load_dir_bm)
    dump_BM (dump_after_load_dir_bm, NULL);
  fflush (NULL);
}                               /* end main */
