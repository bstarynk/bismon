// file main_BM.c
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

    ----
    Contact me (Basile Starynkevitch) by email
    basile@starynkevitch.net and/or basile.starynkevitch@cea.fr
***/
#include "bismon.h"

/* for get_nprocs(3) */
#include <sys/sysinfo.h>


static atomic_int nb_warnings_BM;

struct timespec startrealtimespec_BM;
void *dlprog_BM;
const char *myprogname_BM;
bool gui_is_running_BM;
volatile bool showdebugmsg_BM;
bool parsedebugmsg_BM;
int nbworkjobs_BM;
int randomseed_BM;
bool debug_after_load_BM;
char myhostname_BM[80];
const char *contributors_filepath_BM;
const char *passwords_filepath_BM;
const char *added_passwords_filepath_BM;
const char *contact_filepath_BM;
char *contact_name_BM;
char *contact_email_BM;
double sleepdelay_bm;
const char *project_name_BM;
const char *plugin_before_load_BM;
const char *sigusr1_dump_prefix_BM;
const volatile char *unix_json_socket_BM;
bool dont_indent_generated_code_BM;

void *dlh_before_load_bm;
int sigfd_BM = -1;              /* for signalfd(2) */
atomic_int oniontimerfd_BM = -1;        /* for timerfd_create(2) */
char real_executable_BM[128];

typedef void action_after_load_sigt (const char *);

static gchar **do_after_load_bm;


////////////////////////////////////////////////////////////////
extern void parse_program_options_BM (int argc, char **argv);
extern void show_program_options_BM (FILE * out, int argc, char **argv);

static const char *chdir_after_load_bm;
thread_local struct threadinfo_stBM *curthreadinfo_BM;
thread_local volatile struct failurehandler_stBM *curfailurehandle_BM;

volatile struct backstrace_state *backtracestate_BM;
static void backtracerrorcb_BM (void *data, const char *msg, int errnum);

static void test_make_empty_sigusr1_dump_dir_BM (void);

extern void run_testplugins_after_load_BM (void);

static void add_passwords_from_file_BM (const char *addedpasspath);

static void write_pid_into_file_and_kill_old_BM (const char *pidfilepath);

void cleanup_temporary_dir_after_exit_BM (void);        /* for atexit */
////////////////

extern void weakfailure_BM (void);


const char *
bismon_home_BM (void)
{
  static const char *bh;
  if (UNLIKELY_BM (!bh))
    {
      const char *bismon_home = getenv ("BISMON_HOME");
      const char *home = getenv ("HOME");
      if (bismon_home)
        bh = bismon_home;
      else if (home)
        bh = home;
      if (!bh)
        FATAL_BM ("improbable bismon_home_BM failure (%m)");
    };
  return bh;
}                               /* end bismon_home_BM */


// consider putting a gdb breakpoint here 
void
weakfailure_BM (void)
{
  fflush (NULL);
}                               /* end weakfailure_BM */

void
warning_at_BM (const char *fil, int lin)
{
  ASSERT_BM (fil != NULL && lin > 0);
  int nbw = 1 + atomic_fetch_add (&nb_warnings_BM, 1);
  if (nbw % 10 == 0)
    fputc ('\n', stderr);
  fprintf (stderr, "BISMON WARNING#%03d: %s: %d: ", nbw,
           basename_BM (fil), lin);
  fflush (stderr);
}                               /* end warning_at_BM */

void
weakassertfailureat_BM (const char *condmsg, const char *fil, int lin)
{
  char thnambuf[16];
  memset (thnambuf, 0, sizeof (thnambuf));
  pthread_getname_np (pthread_self (), thnambuf, sizeof (thnambuf));
  fprintf (stderr, "**** weakassertfailureat_BM (%s:%d) %s (tid#%d/%s)\n",
           fil, lin, condmsg, (int) gettid_BM (), thnambuf);
  fflush (stderr);
  if (backtracestate_BM)
    {
      fprintf (stderr, "\n\n\n** full backtrace **\n");
      fflush (stderr);
      backtrace_print_BM ((struct backtrace_state *) backtracestate_BM, 1,
                          stderr);
      fprintf (stderr, "\n----- end full backtrace ------\n\n");
      fflush (stderr);
    }
  else
    {
      WARNPRINTF_BM ("weakassertfailureat_BM <%s:%d> %s - no backtracestate",
                     fil, lin, condmsg);
      void *backbuf[50];
      memset (backbuf, 0, sizeof (backbuf));
      int nb = backtrace (backbuf, sizeof (backbuf) / sizeof (void *));
      backtrace_symbols_fd (backbuf, nb, STDERR_FILENO);
    }
  weakfailure_BM ();
}                               /* end weakassertfailureat_BM */

value_tyBM
objrout_placeholder_BM (struct stackframe_stBM *stkf __attribute__((unused)),   //
                        const value_tyBM arg1 __attribute__((unused)),  //
                        const value_tyBM arg2 __attribute__((unused)),  //
                        const value_tyBM arg3 __attribute__((unused)),  //
                        const value_tyBM arg4 __attribute__((unused)),  //
                        const quasinode_tyBM * restargs
                        __attribute__((unused)))
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
char temporary_dir_BM[256];
char *load_dir_bm;
char *dump_dir_BM;
char *dump_after_load_dir_bm;
char *css_file_bm = "bismon.css";
char *gui_log_name_bm = "_bismon.log";  /* default log file */
char *pid_filepath_bm = "_bismon.pid";  /* default pid file */
char *comment_bm;
char *module_to_emit_bm;
int count_emit_has_predef_bm;
int nb_added_predef_bm;
char *print_contributor_of_oid_bm;
char *mailhtml_file_bm;
char *mailhtml_contributor_bm;
char *mailhtml_subject_bm;
char *mailhtml_attachment_bm;
char *password_file_comment_BM;
static bool want_finalgc_bm;    /* to run a final GC */
static bool want_cleanup_bm;    /* to make valgrind more happy; see http://valgrind.org/ for more */

int count_init_afterload_bm;    /* used count in arr_init_afterload_bm */
int size_init_afterload_bm;     /* allocated size of arr_init_afterload_bm */
char **arr_init_afterload_bm;   // allocated size is size_init_afterload_bm
// and each string is strdup-ed

#define MAXADDEDPREDEF_BM 16
struct
{
  const char *pr_comment;
  const char *pr_name;
} added_predef_bm[MAXADDEDPREDEF_BM];


char **added_contributors_arr_bm;
int count_added_contributors_bm;
int size_added_contributors_bm;

char **removed_contributors_arr_bm;
int count_removed_contributors_bm;
int size_removed_contributors_bm;

#define MAXPARSED_VALUES_AFTER_LOAD_BM 10
char *parsed_values_after_loadarr_bm[MAXPARSED_VALUES_AFTER_LOAD_BM + 1];
int nb_parsed_values_after_load_bm;

#define MAXPARSED_FILES_AFTER_LOAD_BM 30
char *parsed_files_after_loadarr_bm[MAXPARSED_FILES_AFTER_LOAD_BM + 1];
int nb_parsed_files_after_load_bm;

#define MAXTESTPLUGINS_AFTER_LOAD_BM 10
char *testplugins_after_loadarr_bm[MAXTESTPLUGINS_AFTER_LOAD_BM];
int nb_testplugins_after_load_bm;


bool batch_bm;
bool give_version_bm;


void
failure_at_BM (int failcode, const char *fil, int lineno,
               const value_tyBM reasonv, const value_tyBM placev,
               struct stackframe_stBM *stkf)
{
  if (curfailurehandle_BM)
    {
      if (curfailurehandle_BM->failh_magic != FAILUREHANDLEMAGIC_BM)
        FATAL_AT_BM (fil, lineno,
                     "corrupted curfailurehandle_BM@%p for failcode %d",
                     curfailurehandle_BM, failcode);
      curfailurehandle_BM->failh_reason = reasonv;
      curfailurehandle_BM->failh_place = placev;
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
              fprintf (stderr, "\n----- end failure backtrace ------\n");
            }
          fflush (stderr);
          // we need that debug_outstr_value_BM should not fail...
          fprintf (stderr,
                   "*#* failure code#%d from %s:%d\n"
                   "fail reason : %s\n"
                   "fail place : %s\n",
                   failcode, fil ? fil : "???", lineno,
                   debug_outstr_value_BM (reasonv, stkf, 0),
                   debug_outstr_value_BM (placev, stkf, 0));
          fprintf (stderr, "#*#*#*#*#*#*#*#*#*#*\n\n");
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
  failure_at_BM (failcode, "??", 0, reasonv, taggedint_BM (failcode), stkf);
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
static void do_test_mailhtml_bm (void);
static void init_afterload_bm (void);
static void show_net_info_bm (void);

static bool
run_command_bm (const gchar * optname __attribute__((unused)),  //
                const gchar * val,      //
                gpointer data __attribute__((unused)),  //
                GError ** perr)
{
  ASSERT_BM (val != NULL);
  INFOPRINTF_BM ("running command: %s\n", val);
  int ok = system (val);
  if (ok == 0)
    return TRUE;
  g_set_error (perr, 0, ok, "command %s failed with status %d", val, ok);
  return FALSE;
}                               /* end run_command_bm */

static bool
set_project_name_bm (const gchar * optname __attribute__((unused)),     //
                     const gchar * val, //
                     gpointer data __attribute__((unused)),     //
                     GError ** perr)
{
  if (val == NULL)
    FATAL_BM ("missing project name");
  bool goodname = true;
  if (!isalpha (val[0]) && val[0] != '_')
    goodname = false;
  for (const gchar * pc = val; *pc && goodname; pc++)
    if (!isalnum (*pc) && *pc != '_')
      goodname = false;
  if (!goodname)
    {
      WARNPRINTF_BM ("invalid project name %s, should be C-identifier like",
                     (const char *) val);
      g_set_error (perr, 0, 1,
                   "invalid project name %s, should be C-identifier like",
                   (const char *) val);
      return FALSE;
    }
  project_name_BM = g_strdup (val);
  INFOPRINTF_BM ("using Bismon project name %s", project_name_BM);
  return TRUE;
}                               /* end set_project_name_bm */




void
show_net_info_bm (void)
{
  /// show some networking information
  printf ("\n**** Bismon pid %d networking information ***\n",
          (int) getpid ());
  fflush (NULL);
  {
    int cod = system (SHOW_NET_COMMAND_BM);
    if (cod > 0)
      WARNPRINTF_BM ("command '%s' failed with #%d", SHOW_NET_COMMAND_BM,
                     cod);
    fflush (NULL);
  }
  printf ("***** end of bismon pid %d networking information ***\n",
          (int) getpid ());
  fflush (NULL);
}                               /* end show_net_info_bm */


static bool
handle_init_afterload_bm (const gchar * optname __attribute__((unused)),        //
                          const gchar * val,    //
                          gpointer data __attribute__((unused)),        //
                          GError ** perr __attribute__((unused)))
{
  ASSERT_BM (val != NULL);
  DBGPRINTF_BM ("init_afterload #%d: %s (@%p)\n", count_init_afterload_bm,
                val, val);
  if (count_init_afterload_bm + 1 >= size_init_afterload_bm)
    {
      int newsiz = prime_above_BM (4 * count_init_afterload_bm / 3 + 30);
      char **newarr = calloc (newsiz, sizeof (char *));
      if (!newarr)
        FATAL_BM ("failed to calloc for %d init_afterload", newsiz);
      if (count_init_afterload_bm > 0)
        memcpy (newarr, arr_init_afterload_bm,
                count_init_afterload_bm * sizeof (char *));
      free (arr_init_afterload_bm), arr_init_afterload_bm = newarr;
      size_init_afterload_bm = newsiz;
    }
  char *dupval = strdup (val);
  if (!dupval)
    FATAL_BM ("failed to strdup %s for init_afterload#%d", val,
              count_init_afterload_bm);
  arr_init_afterload_bm[count_init_afterload_bm] = dupval;
  count_init_afterload_bm++;
  INFOPRINTF_BM ("should do after load: %s\n", val);
  return true;
}                               /* end handle_init_afterload_bm */




static void
get_parse_value_after_load_bm (const gchar * optname __attribute__((unused)),
                               const gchar * val,
                               gpointer data __attribute__((unused)),
                               GError ** perr __attribute__((unused)))
{
  if (nb_parsed_values_after_load_bm >= MAXPARSED_VALUES_AFTER_LOAD_BM)
    FATAL_BM ("too many %d parsed values after load with --parse-value",
              nb_parsed_values_after_load_bm);
  NONPRINTF_BM ("get_parse_value_after_load #%d.. valen=%d:\n%s",
                nb_parsed_values_after_load_bm, (int) strlen (val), val);
  parsed_values_after_loadarr_bm[nb_parsed_values_after_load_bm++] =
    strdup (val);
}                               /* end get_parse_value_after_load_bm */


static void
get_parse_file_after_load_bm (const gchar * optname __attribute__((unused)),
                              const gchar * val,
                              gpointer data __attribute__((unused)),
                              GError ** perr __attribute__((unused)))
{
  if (nb_parsed_files_after_load_bm >= MAXPARSED_FILES_AFTER_LOAD_BM)
    FATAL_BM ("too many %d parsed values after load with --parse-file",
              nb_parsed_files_after_load_bm);
  if (access ((const char *) val, R_OK))
    FATAL_BM ("cannot access file %s to be parsed (%m)", val);
  NONPRINTF_BM ("get_parse_file_after_load #%d.. valen=%d:\n%s",
                nb_parsed_files_after_load_bm, (int) strlen (val), val);
  parsed_files_after_loadarr_bm[nb_parsed_files_after_load_bm++] =
    (char *) val;
}                               /* end get_parse_file_after_load_bm */



static void
get_testplugin_after_load_bm (const gchar * optname __attribute__((unused)),
                              const gchar * val,
                              gpointer data __attribute__((unused)),
                              GError ** perr __attribute__((unused)))
{
  if (nb_testplugins_after_load_bm >= MAXTESTPLUGINS_AFTER_LOAD_BM)
    FATAL_BM ("too many %d testplugins after load with --test-plugin",
              nb_testplugins_after_load_bm);
  DBGPRINTF_BM ("get_testplugin_after_load_bm #%d.. valen=%d:\n%s",
                nb_testplugins_after_load_bm, (int) strlen (val), val);
  testplugins_after_loadarr_bm[nb_testplugins_after_load_bm++] = strdup (val);
}                               /* end get_testplugin_after_load_bm */


static bool
add_predef_bm (const gchar * optname __attribute__((unused)),
               const gchar * val,
               gpointer data __attribute__((unused)),
               GError ** perr __attribute__((unused)))
{
  ASSERT_BM (val != NULL);
  if (!validname_BM (val))
    FATAL_BM ("invalid predef name %s", val);
  if (nb_added_predef_bm >= MAXADDEDPREDEF_BM)
    FATAL_BM ("too many added predefined %i", nb_added_predef_bm);
  // in principle the strdup-s below should be checked, but in
  // practice this is so rarely used that we don't bother
  if (comment_bm)
    added_predef_bm[nb_added_predef_bm].pr_comment = strdup (comment_bm);
  added_predef_bm[nb_added_predef_bm].pr_name = strdup (val);
  nb_added_predef_bm++;
  comment_bm = NULL;
  return true;
}                               /* end add_predef_bm */

static bool
add_contributor_bm (const gchar * optname __attribute__((unused)),
                    const gchar * contrib,
                    gpointer data __attribute__((unused)),
                    GError ** perr __attribute__((unused)))
{
  if (count_added_contributors_bm >= size_added_contributors_bm)
    {
      int newsiz = prime_above_BM (3 * count_added_contributors_bm / 2 + 16);
      char **newarr = calloc (newsiz, sizeof (char *));
      if (!newarr || newsiz > MAXSIZE_BM / 2)   /*very unlikely to happen in practice */
        FATAL_BM ("cannot grow added contributors array to %d for %s - %m",
                  newsiz, contrib);
      if (count_added_contributors_bm > 0)
        memcpy (newarr, added_contributors_arr_bm,
                count_added_contributors_bm * sizeof (char *));
      free (added_contributors_arr_bm);
      added_contributors_arr_bm = newarr;
      size_added_contributors_bm = newsiz;
    };
  char *newcontrib = strdup (contrib);
  if (!newcontrib)
    FATAL_BM ("failed to strdup added contributor %s - %m", contrib);
  added_contributors_arr_bm[count_added_contributors_bm++] = newcontrib;
  return true;
}                               /* end add_contributor_bm */



static bool
remove_contributor_bm (const gchar * optname __attribute__((unused)),
                       const gchar * contrib,
                       gpointer data __attribute__((unused)),
                       GError ** perr __attribute__((unused)))
{
  if (count_removed_contributors_bm >= size_removed_contributors_bm)
    {
      int newsiz =
        prime_above_BM (3 * count_removed_contributors_bm / 2 + 16);
      char **newarr = calloc (newsiz, sizeof (char *));
      if (!newarr || newsiz > MAXSIZE_BM / 2)   /*very unlikely to happen in practice */
        FATAL_BM ("cannot grow removed contributors array to %d for %s - %m",
                  newsiz, contrib);
      if (count_removed_contributors_bm > 0)
        memcpy (newarr, removed_contributors_arr_bm,
                count_removed_contributors_bm * sizeof (char *));
      free (removed_contributors_arr_bm);
      removed_contributors_arr_bm = newarr;
      size_removed_contributors_bm = newsiz;
    };
  char *newcontrib = strdup (contrib);
  if (!newcontrib)
    FATAL_BM ("failed to strdup removed contributor %s - %m", contrib);
  removed_contributors_arr_bm[count_removed_contributors_bm++] = newcontrib;
  return true;
}                               /* end remove_contributor_bm */



////////////////////////////////////////////////////////////////
const GOptionEntry optionstab_bm[] = {
  //////////////////
  /* for the shorter variant like --debug */
#define BISMONPROG_LONG_OPTION(Lopt) Lopt
#define BISMONPROG_SHORT_OPTION(Shopt) Shopt
#include "progoptions_BM.h"
  /* for the Bismon variant like --bismon-debug: */
#define BISMONPROG_LONG_OPTION(Lopt) "bismon-" Lopt
#define BISMONPROG_SHORT_OPTION(Shopt) (char)0
#include "progoptions_BM.h"
  ///
  /// end of options
  {}                            //// last entry should be all zeros
};                              // end of variable optionstab_bm

///////////////////////////////////////////////////////////////




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
#include "bm_delim.h"
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
          INFOPRINTF_BM ("existing %s becomes predefined %s\n", idpred,
                         predname);
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
        INFOPRINTF_BM ("made predefined %s (%s) - %s\n", predname, idpred,
                       predcomm);
      else
        INFOPRINTF_BM ("made predefined %s (%s)\n", predname, idpred);
    }
}                               /* end add_new_predefined_bm */

static int
idqcmp_BM (const void *p1, const void *p2)
{
  return cmpid_BM (*(rawid_tyBM *) p1, *(rawid_tyBM *) p2);
}                               /* end idqcmp_BM */




static void give_prog_version_BM (const char *progname);

static void do_emit_module_from_main_BM (void);

void
do_emit_module_from_main_BM (void)
{
  LOCALFRAME_BM (NULL, /*descr: */ BMP_emit_module,
                 objectval_tyBM * modulob;      //
                 objectval_tyBM * parsob;       //
                 value_tyBM resultv;    //
                 value_tyBM failres;    //
                 value_tyBM failplace;  //
    );
  WEAKASSERTRET_BM (module_to_emit_bm != NULL);
  _.failres = NULL;
  _.failplace = NULL;
  int failcod = 0;
  struct failurelockset_stBM flockset = { };
  struct failurehandler_stBM *prevfailurehandle =
    (struct failurehandler_stBM *) curfailurehandle_BM;
  initialize_failurelockset_BM (&flockset, sizeof (flockset));
  LOCAL_FAILURE_HANDLE_BM (&flockset, lab_failureemit, failcod, _.failres,
                           _.failplace);
  if (failcod > 0)
  lab_failureemit:{
      destroy_failurelockset_BM (&flockset);
      curfailurehandle_BM = prevfailurehandle;
      {
        WARNPRINTF_BM
          ("Failed to emit module from main %s, with failcode#%d, failres %s\n"
           "failplace %s",
           objectdbg_BM (_.modulob), failcod,
           OUTSTRVALUE_BM (_.failres), OUTSTRVALUE_BM (_.failplace));
        return;
      };
    };
  INFOPRINTF_BM ("begin emit module from main: %s\n", module_to_emit_bm);
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
    INFOPRINTF_BM ("successful emit module from main: %s\n",
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
  INFOPRINTF_BM ("successfully compiled emitted module %s (%s) from main\n",
                 module_to_emit_bm, modulidbuf);
  fflush (NULL);
  return;
}                               /* end do_emit_module_from_main_BM */


static void parse_values_after_load_BM (void);
static void add_contributors_after_load_BM (void);
static void remove_contributors_after_load_BM (void);
static void initialize_contributors_path_BM (void);
static void initialize_passwords_path_BM (void);
static void initialize_contact_path_BM (void);
static void parse_contact_BM (void);
static void emit_has_predef_BM (void);
static void do_dump_after_load_BM (void);
static bool is_nice_locale_BM (const char *);
static void check_locale_BM (void);
static void do_actions_after_load_bm (gchar **);




void
check_locale_BM (void)
{
  bool explainlocale = false;
  char *oldloc = setlocale (LC_ALL, NULL);
  char *oldnumloc = setlocale (LC_NUMERIC, NULL);
  char *oldctypeloc = setlocale (LC_CTYPE, NULL);
  DBGPRINTF_BM ("oldlocale LC_ALL %s LC_NUMERIC %s LC_CTYPE %s", oldloc,
                oldnumloc, oldctypeloc);
  if (oldloc && !is_nice_locale_BM (oldloc))
    {
      WARNPRINTF_BM
        ("your LC_ALL locale '%s' is strange but should be in English, encoded in UTF-8.\n",
         oldloc);
      explainlocale = true;
    }
  if (oldnumloc && !is_nice_locale_BM (oldloc))
    {
      WARNPRINTF_BM
        ("your LC_NUMERIC locale '%s' is strange but should be in English, encoded in UTF-8, such that ...\n"
         " 3.14 (with decimal dot) should be parsed and printable as an approximation of Pi, and\n"
         " 6.022e23 should be parsed and printable as an approximation of the Avogadro constant.\n",
         oldnumloc);
      explainlocale = true;
    }
  if (oldctypeloc && !is_nice_locale_BM (oldctypeloc))
    {
      WARNPRINTF_BM
        ("your LC_CTYPE locale '%s' is strange but should be in English, encoded in UTF-8.\n",
         oldnumloc);
      explainlocale = true;
    }
  if (explainlocale)
    {
      WARNPRINTF_BM
        ("Bismon requires an English UTF-8 locale, in particular for floating point numbers in the persistent store.\n"
         "Read carefully http://man7.org/linux/man-pages/man7/locale.7.html\n"
         "You may use the 'locale' and/or 'localectl' programs to check your current locale.\n"
         "You may want to set your locale thru several environment variables like LC_ALL LC_NUMERIC LC_CTYPE LANG LANGUAGE etc...\n"
         "... using the export or setenv builtin of your shell\n"
         "Please read carefully the %s/README.md file (Localization section)\n",
         bismon_directory);
    }
  //
  // force the LC_NUMERIC locale to English UTF-8
  if (!setlocale (LC_NUMERIC, "C.UTF-8")
      && !setlocale (LC_NUMERIC, "C.utf8")
      && !setlocale (LC_NUMERIC, "POSIX")
      && !setlocale (LC_NUMERIC, "POSIX.utf8")
      && !setlocale (LC_NUMERIC, "POSIX.utf-8")
      && !setlocale (LC_NUMERIC, "en_US.utf8")
      && !setlocale (LC_NUMERIC, "en_US.utf-8")
      && !setlocale (LC_NUMERIC, "en_GB.utf8")
      && !setlocale (LC_NUMERIC, "en_GB.utf-8"))
    FATAL_BM
      ("failed to setlocale LC_NUMERIC appropriately to English UTF-8, previous was %s",
       oldnumloc ? : "*unset*");
  DBGPRINTF_BM ("now LC_NUMERIC locale is %s", setlocale (LC_NUMERIC, NULL));
  //
  // force the LC_ALL locale to English UTF-8
  if (!setlocale (LC_ALL, "C.UTF-8")
      && !setlocale (LC_ALL, "C.utf8")
      && !setlocale (LC_ALL, "POSIX")
      && !setlocale (LC_ALL, "POSIX.utf8")
      && !setlocale (LC_ALL, "POSIX.utf-8")
      && !setlocale (LC_ALL, "en_US.utf8")
      && !setlocale (LC_ALL, "en_US.utf-8")
      && !setlocale (LC_ALL, "en_GB.utf8")
      && !setlocale (LC_ALL, "en_GB.utf-8"))
    FATAL_BM
      ("failed to setlocale LC_ALL appropriately to English UTF-8, previous was %s",
       oldloc ? : "*unset*");
  DBGPRINTF_BM ("now LC_ALL locale is %s", setlocale (LC_ALL, NULL));
  double x = 0;
  int pos = 0;
  if (sscanf ("4.5;", "%lf%n", &x, &pos) < 1 || x != 4.5 || pos != 3)
    FATAL_BM
      ("something wrong (probably your locale setting, which should be C.UTF-8)."
       " Since '4.5;' is scanned as %f at position#%d", x, pos);
  DBGPRINTF_BM ("after sscanf x=%f, pos#%d", x, pos);
  char *end = NULL;
  x = strtod ("4.5/", &end);
  DBGPRINTF_BM ("after strtod x=%f, end=%s", x, end);
  if (x != 4.5 || !end || *end != '/')
    FATAL_BM
      ("something wrong (probably your locale setting, which should be C.UTF-8)."
       " Since '4.5/' is not converted as %f end at %s", x, end);
  x = 0.0;
  if (sscanf ("-6.022e23;", "%lf%n", &x, &pos) < 1 || pos != 9
      || fabs (x + 6.022e+23) > 1e20)
    FATAL_BM
      ("something wrong (probably your locale setting, which should be C.UTF-8)."
       " Since '-6.022e23;' is scanned as %g at position#%d", x, pos);
}                               /* end of check_locale_BM */




void
cleanup_temporary_dir_after_exit_BM (void)
{
  FILE *fat = popen ("/bin/at now + 15 minutes", "w");
  if (!fat)
    FATAL_BM ("popen /bin/at now + 15 minutes failed (%m)");
  fprintf (fat, "/bin/rm -rf %s", temporary_dir_BM);
  fflush (fat);
  fclose (fat);
}                               /* end cleanup_temporary_dir_after_exit_BM */

////////////////////////////////////////////////////////////////
//// see also https://github.com/dtrebbien/GNOME.supp and
//// https://stackoverflow.com/q/16659781/841108 to use valgrind...
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
  myprogname_BM = argv[0];
  if (argc > 1 && (!strcmp (argv[1], "-D") || !strcmp (argv[1], "--debug")))
    showdebugmsg_BM = true;
  if (argc > 1 && !strcmp (argv[1], "--version"))
    give_prog_version_BM (argv[0]);
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
  INFOPRINTF_BM ("BISMON (%s git %s pid %d) starting on host %s (build %s)\n",
                 myprogname_BM, bismon_shortgitid, (int) getpid (),
                 myhostname_BM, bismon_timestamp);
  if (access ("/bin/at", X_OK))
    FATAL_BM ("BISMON (%s pid %d git %s) requires a /bin/at (%m)",
              myprogname_BM, (int) getpid (), bismon_shortgitid);
  if (access ("/usr/bin/indent", X_OK))
    FATAL_BM ("BISMON (%s pid %d git %s) requires a /usr/bin/indent (%m)",
              myprogname_BM, (int) getpid (), bismon_shortgitid);
  if (access ("/usr/bin/astyle", X_OK))
    FATAL_BM ("BISMON (%s pid %d git %s) requires a /usr/bin/astyle (%m)",
              myprogname_BM, (int) getpid (), bismon_shortgitid);
  bool skiplocalcheck = false;
  {
    // check the locale(7), unless using print-contributor-of-oid
    for (int ix = 0; ix < argc && !skiplocalcheck; ix++)
      if (!strncmp
          (argv[ix], "--print-contributor-of-oid",
           strlen ("--print-contributor-of-oid")))
        skiplocalcheck = true;
  }
  ///
  {
    double nwt = clocktime_BM (CLOCK_REALTIME);
    intptr_t y2kwt = timetoY2Kmillisec_BM (nwt);
    ASSERT_BM (fabs (Y2Kmillisectotime_BM (y2kwt) - nwt) < 0.5);
  }
  backtracestate_BM             //
    = (volatile struct backstrace_state *)
    backtrace_create_state ( /*filename: */ NULL,
                            /*threaded: */ true,
                            /*errorcb: */
                            backtracerrorcb_BM,
                            /*data: */ NULL);
  parse_program_options_BM (argc, argv);
  if (randomseed_BM > 0)
    {
      g_random_set_seed (randomseed_BM);
      INFOPRINTF_BM
        ("set -using g_random_set_seed- the Glib PRNG random seed to %d",
         randomseed_BM);
      if (getpid () % 2 == 0)
        WARNPRINTF_BM ("even pid %d for BISMON", (int) getpid ());
      else
        INFOPRINTF_BM ("odd pid %d for BISMON", (int) getpid ());
    }
  if (plugin_before_load_BM)
    {
      char plugbuf[256];
      memset (plugbuf, 0, sizeof (plugbuf));
      if (!access (plugin_before_load_BM, X_OK))
        dlh_before_load_bm = dlopen (plugin_before_load_BM,
                                     RTLD_NOW | RTLD_GLOBAL | RTLD_DEEPBIND);
      else
        if (snprintf
            (plugbuf, sizeof (plugbuf), "%s.so", plugin_before_load_BM) > 0
            && !access (plugbuf, X_OK))
        dlh_before_load_bm =
          dlopen (plugbuf, RTLD_NOW | RTLD_GLOBAL | RTLD_DEEPBIND);
      else
        if (snprintf
            (plugbuf, sizeof (plugbuf), "%s/Plugins/%s.so", bismon_directory,
             plugin_before_load_BM) > 0 && !access (plugbuf, X_OK))
        dlh_before_load_bm =
          dlopen (plugbuf, RTLD_NOW | RTLD_GLOBAL | RTLD_DEEPBIND);
      else
        FATAL_BM
          ("fail to find --plugin-before-load %s in bismon directory %s",
           plugin_before_load_BM, bismon_directory);
      if (!dlh_before_load_bm)
        FATAL_BM ("failed to dlopen plugin before load %s : %s (%m)",
                  plugin_before_load_BM, dlerror ());
    };
  if (!temporary_dir_BM[0])
    {
      time_t nowt = 0;
      time (&nowt);
      snprintf (temporary_dir_BM, sizeof (temporary_dir_BM),
                "/var/tmp/bismon-p%d-t%ld", (int) getpid (), (long) nowt);
      DBGPRINTF_BM ("temporary dir %s", temporary_dir_BM);
      if (mkdir (temporary_dir_BM, 0700))
        FATAL_BM ("failed to make temporary directory %s", temporary_dir_BM);
      INFOPRINTF_BM ("made temporary directory %s", temporary_dir_BM);
      atexit (cleanup_temporary_dir_after_exit_BM);
    };
  {
    char temptestpath[384];
    memset (temptestpath, 0, sizeof (temptestpath));
    snprintf (temptestpath, sizeof (temptestpath),
              "%s/__BISMON_TEMPORARY_DIR", temporary_dir_BM);
    FILE *fw = fopen (temptestpath, "w");
    if (!fw)
      FATAL_BM ("failed to write temporary %s (%m)", temptestpath);
    fprintf (fw, "# Bismon %s pid %d on %s temporary %s\n",
             bismon_gitid, (int) getpid (), myhostname_BM, temptestpath);
    fflush (fw);
    fsync (fileno (fw));
    fclose (fw);
  };
  if (!skiplocalcheck)
    check_locale_BM ();
  {
    const char *glib_mismatch =
      glib_check_version (GLIB_MAJOR_VERSION, GLIB_MINOR_VERSION,
                          GLIB_MICRO_VERSION);
    if (glib_mismatch)
      FATAL_BM ("GLIB version mismatch: %s", glib_mismatch);
  };
  initialize_garbage_collector_BM ();
  check_delims_BM ();
  initialize_globals_BM ();
  initialize_predefined_objects_BM ();
  initialize_predefined_names_BM ();
  initialize_agenda_BM ();
  ////
  ///
  if (showdebugmsg_BM)
    fprintf (stderr,
             "debug messages enabled %s pid %d timestamp %s commit %s\n",
             myprogname_BM, (int) getpid (), bismon_timestamp,
             bismon_lastgitcommit);
  if (give_version_bm)
    give_prog_version_BM (myprogname_BM);
  if (sigusr1_dump_prefix_BM)
    test_make_empty_sigusr1_dump_dir_BM ();
  if (print_contributor_of_oid_bm)
    {
      initialize_contributors_path_BM ();
      tabular_print_contributor_of_objid_BM (print_contributor_of_oid_bm);
    }
  if (nbworkjobs_BM == 0)
    {
      int nbcores = get_nprocs ();
      if (nbcores < 5 * MAXNBWORKJOBS_BM)
        nbworkjobs_BM = nbcores / 5 + 1;
      else
        nbworkjobs_BM = MAXNBWORKJOBS_BM;
    }
  if (nbworkjobs_BM < MINNBWORKJOBS_BM)
    nbworkjobs_BM = MINNBWORKJOBS_BM + 1;
  else if (nbworkjobs_BM > MAXNBWORKJOBS_BM)
    nbworkjobs_BM = MAXNBWORKJOBS_BM;
  if (!batch_bm && !unix_json_socket_BM)
    FATAL_BM
      ("no batch option and no Unix json socket; please run with --batch or with unix-json-socket=JSONSOCKET;\n"
       "... or run: %s --help", argv[0]);
  /// running as root is really unreasonable.
  if (getuid () == 0)
    FATAL_BM ("bismon should not be running as root real user (and euid#%d)",
              (int) geteuid ());
  if (geteuid () == 0)
    FATAL_BM
      ("bismon should not be running as root effective user (and uid#%d)",
       (int) getuid ());
  else if (batch_bm)
    INFOPRINTF_BM ("batch mode requested(%d jobs)", nbworkjobs_BM);
  //
#warning not sure of this....
  initialize_contributors_path_BM ();
  initialize_passwords_path_BM ();
  initialize_contact_path_BM ();
  parse_contact_BM ();
  //
  if (count_emit_has_predef_bm > 0)
    emit_has_predef_BM ();
  if (!load_dir_bm)
    load_dir_bm = ".";
  else if (load_dir_bm[0] == '-')
    FATAL_BM ("--load directory '%s' cannot start with minus,\n"
              "... use '--load ./%s' instead", load_dir_bm, load_dir_bm);
  if (!dump_dir_BM)
    dump_dir_BM = realpath (load_dir_bm, NULL);
  else if (dump_dir_BM[0] == '-')
    FATAL_BM ("--dump directory '%s' cannot start with minus,\n"
              "... use '--dump ./%s' instead", dump_dir_BM, dump_dir_BM);
  if (dump_after_load_dir_bm && dump_after_load_dir_bm[0] == '-')
    FATAL_BM ("--dump-after-load directory '%s' cannot start with minus,\n"
              "... use '--dump-after-load ./%s' instead",
              dump_after_load_dir_bm, dump_after_load_dir_bm);
  if (contributors_filepath_BM && contributors_filepath_BM[0] == '-')
    FATAL_BM ("--contributors-file path '%s' cannot start with minus,\n"
              "... use '--contributors-file ./%s' instead",
              contributors_filepath_BM, contributors_filepath_BM);
  if (passwords_filepath_BM && passwords_filepath_BM[0] == '-')
    FATAL_BM ("--passwords-file path '%s' cannot start with minus,\n"
              "... use '--passwords-file ./%s' instead",
              passwords_filepath_BM, passwords_filepath_BM);
  if (contact_filepath_BM && contact_filepath_BM[0] == '-')
    FATAL_BM ("--contact-file path '%s' cannot start with minus,\n"
              "... use '--contact-file ./%s' instead",
              contact_filepath_BM, contact_filepath_BM);
  if (pid_filepath_bm && pid_filepath_bm[0] == '-')
    FATAL_BM ("--pid-file path '%s' cannot start with minus,\n"
              "... use '--pid-file ./%s' instead",
              pid_filepath_bm, pid_filepath_bm);
  if (chdir_after_load_bm && chdir_after_load_bm[0] == '-')
    FATAL_BM ("--chdir-after-load directory '%s' cannot start with minus,\n"
              "... use '--chdir-after-load ./%s' instead",
              chdir_after_load_bm, chdir_after_load_bm);
  INFOPRINTF_BM ("Bismon should load directory %s - git commit: %s",
                 load_dir_bm, bismon_lastgitcommit);
  load_initial_BM (load_dir_bm);
  INFOPRINTF_BM ("Bismon (pid %d git %s on %s) loaded directory %s\n",
                 (int) getpid (), bismon_shortgitid, myhostname_BM,
                 load_dir_bm);
  if (pid_filepath_bm && pid_filepath_bm[0] && strcmp (pid_filepath_bm, "-"))
    write_pid_into_file_and_kill_old_BM (pid_filepath_bm);
  if (added_passwords_filepath_BM && added_passwords_filepath_BM[0])
    add_passwords_from_file_BM (added_passwords_filepath_BM);
  if (chdir_after_load_bm)
    {
      if (g_mkdir_with_parents (chdir_after_load_bm, 0750))
        FATAL_BM ("failed to mkdir with parents %s for chdir-after-load",
                  chdir_after_load_bm);
      char cwdbuf[128];
      memset (cwdbuf, 0, sizeof (cwdbuf));
      if (chdir (chdir_after_load_bm))
        FATAL_BM ("failed to change directory after load to %s - %m",
                  chdir_after_load_bm);
      char *newd = getcwd (cwdbuf, sizeof (cwdbuf));
      if (newd)
        INFOPRINTF_BM ("changed directory after load to %s given as %s\n",
                       newd, chdir_after_load_bm);
      else
        INFOPRINTF_BM ("changed directory, given as %s, after load\n",
                       chdir_after_load_bm);
      fflush (NULL);
    }
  if (debug_after_load_BM)
    {
      INFOPRINTF_BM ("bismon pid#%d with debug messages after load from %s",
                     (int) getpid (), load_dir_bm);
      showdebugmsg_BM = true;
    }
  else
    INFOPRINTF_BM ("bismon pid#%d silent for debug", (int) getpid ());
  show_net_info_bm ();
  if (nb_added_predef_bm > 0)
    add_new_predefined_bm ();
  if (nb_parsed_values_after_load_bm > 0)
    parse_values_after_load_BM ();
  if (nb_testplugins_after_load_bm > 0)
    run_testplugins_after_load_BM ();
  if (count_added_contributors_bm > 0)
    add_contributors_after_load_BM ();
  if (count_removed_contributors_bm > 0)
    remove_contributors_after_load_BM ();
  fill_the_system_with_bismon_BM (NULL);
  if (module_to_emit_bm != NULL)
    do_emit_module_from_main_BM ();
  if (count_init_afterload_bm > 0)
    init_afterload_bm ();
  if (do_after_load_bm)
    {
      usleep (1000);
      do_actions_after_load_bm (do_after_load_bm);
    };
  if (dump_after_load_dir_bm)
    {
      if (debug_after_load_BM)
        {
          INFOPRINTF_BM
            ("bismon disabling debug before dump after load to %s",
             dump_after_load_dir_bm);
          showdebugmsg_BM = false;
        }
      do_dump_after_load_BM ();
    };
  if (pid_filepath_bm && pid_filepath_bm[0] && strcmp (pid_filepath_bm, "-"))
    {
      FILE *pidfile = fopen (pid_filepath_bm, "w");
      if (!pidfile)
        FATAL_BM ("failed to open pid file %s - %m", pid_filepath_bm);
      fprintf (pidfile, "%d\n", (int) getpid ());
      fclose (pidfile);
      INFOPRINTF_BM ("wrote pid %d in pid-file %s",
                     (int) getpid (), pid_filepath_bm);
    }
  ///
  //
  if (want_finalgc_bm)
    {
      INFOPRINTF_BM ("running final garbage collection.");
      usleep (200);
      full_garbage_collection_BM (NULL);

    }
  if (dlh_before_load_bm)
    {
      if (dlclose (dlh_before_load_bm))
        FATAL_BM ("dlclose of plugin before load %s failed : %s",
                  plugin_before_load_BM, dlerror ());
      INFOPRINTF_BM ("dclosed our plugin before load %s",
                     plugin_before_load_BM);
      dlh_before_load_bm = NULL;
    }
  if (do_after_load_bm)
    g_strfreev (do_after_load_bm), do_after_load_bm = NULL;
  DBGPRINTF_BM ("ending BISMON batch_bm %s", batch_bm ? "true" : "false");
  free ((void *) contributors_filepath_BM), contributors_filepath_BM = NULL;
  free ((void *) passwords_filepath_BM), passwords_filepath_BM = NULL;
  if (dump_dir_BM)
    free ((void *) dump_dir_BM), dump_dir_BM = NULL;
  if (want_cleanup_bm)
    final_cleanup_BM ();
  INFOPRINTF_BM ("end of %s, on %s, pid %d, %.3f elapsed, %.3f cpu time\n"
                 "... timestamp %s\n"
                 "... lastgitcommit %s\n"
                 "... checksum %s\n",
                 myprogname_BM, myhostname_BM, (int) getpid (),
                 elapsedtime_BM (), cputime_BM (), bismon_timestamp,
                 bismon_lastgitcommit, bismon_checksum);
  fflush (NULL);
}                               /* end main */


bool
is_nice_locale_BM (const char *locstr)
{
#define NICE_LOCALE_REGEX_BM "^\\(en_[a-z_]*\\|C\\|POSIX\\)\\.*utf.*8.*"
  static regex_t rx;
  static bool initedrx;
  /// initialize rx only once
  if (!initedrx)
    {
      int errcod =
        regcomp (&rx, NICE_LOCALE_REGEX_BM, REG_EXTENDED | REG_ICASE);
      if (errcod)
        {                       // should never happen
          char errbuf[128];
          memset (errbuf, 0, sizeof (errbuf));
          (void) regerror (errcod, &rx, errbuf, sizeof (errbuf) - 1);
          FATAL_BM ("failed to compile regexp NICE_LOCALE_REGEX_BM '%s' - %s",
                    NICE_LOCALE_REGEX_BM, errbuf);
        }
      initedrx = true;
    }
  regmatch_t rm[2];
  memset (&rm, 0, sizeof (rm));
  if (regexec (&rx, locstr, 1, rm, 0))
    return false;
  else
    return true;
}                               /* end is_nice_locale_BM */


void
do_dump_after_load_BM (void)
{
  {
    char *rd = realpath (dump_after_load_dir_bm, NULL);
    if (rd)
      {
        INFOPRINTF_BM ("dump after load into %s directory (%s)",
                       dump_after_load_dir_bm, rd);
        free (rd), rd = NULL;
      }
    else
      INFOPRINTF_BM ("dump after load into %s directory",
                     dump_after_load_dir_bm);
  }
  struct dumpinfo_stBM di = dump_BM (dump_after_load_dir_bm, NULL);
  INFOPRINTF_BM ("dump after load: scanned %ld, emitted %ld objects\n"
                 "... did %ld todos, wrote %ld files\n"
                 "... in %.3f elapsed, %.4f cpu seconds\n (%.1f elapsed, %.1f cpu µs/obj)\n",
                 di.dumpinfo_scanedobjectcount,
                 di.dumpinfo_emittedobjectcount, di.dumpinfo_todocount,
                 di.dumpinfo_wrotefilecount, di.dumpinfo_elapsedtime,
                 di.dumpinfo_cputime,
                 di.dumpinfo_elapsedtime * 1.0e6 /
                 di.dumpinfo_emittedobjectcount,
                 di.dumpinfo_cputime * 1.0e6 /
                 di.dumpinfo_emittedobjectcount);
}                               /*  end do_dump_after_load_BM */



void
emit_has_predef_BM (void)
{
  rawid_tyBM *idarr = calloc (count_emit_has_predef_bm, sizeof (rawid_tyBM));
  if (!idarr)
    FATAL_BM ("failed to calloc idarr for %d", count_emit_has_predef_bm);
  for (int ix = 0; ix < count_emit_has_predef_bm; ix++)
    idarr[ix] = randomid_BM ();
  qsort (idarr, count_emit_has_predef_bm, sizeof (rawid_tyBM), idqcmp_BM);
  INFOPRINTF_BM ("/// %d extra predefs\n", count_emit_has_predef_bm);
  INFOPRINTF_BM ("// !@ %.3f\n", clocktime_BM (CLOCK_REALTIME));
  // we won't use INFOPRINTF_BM below
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
  INFOPRINTF_BM ("/// emitted %d extra predefs\n", count_emit_has_predef_bm);
}                               /* end emit_has_predef_BM */


void
initialize_contributors_path_BM (void)
{
  if (!contributors_filepath_BM)
    {
      char *path = NULL;
      const char *homepath = NULL;
      if (!access (CONTRIBUTORS_FILE_BM, R_OK))
        contributors_filepath_BM = CONTRIBUTORS_FILE_BM;
      else if ((homepath = bismon_home_BM ()) != NULL
               && asprintf (&path, "%s/" CONTRIBUTORS_FILE_BM, homepath) > 0
               && path != NULL && (!access (path, R_OK)
                                   || (free (path), (path = NULL))))
        contributors_filepath_BM = path;
      if (!contributors_filepath_BM)
        {
          char cwdbuf[128];
          memset (cwdbuf, 0, sizeof (cwdbuf));
          if (!getcwd (cwdbuf, sizeof (cwdbuf)))
            strcpy (cwdbuf, "./");
          FATAL_BM
            ("no %s file found here in %s or in $HOME %s, so pass --contributors-file=... option to give one",
             CONTRIBUTORS_FILE_BM, cwdbuf, homepath);
        }
      if (access (contributors_filepath_BM, R_OK))
        FATAL_BM ("cannot read contributors file %s - %m",
                  contributors_filepath_BM);
      char *rcpath = realpath (contributors_filepath_BM, NULL);
      if (!rcpath)
        FATAL_BM ("cannot get real path of contributors file %s - %m",
                  contributors_filepath_BM);
      if (path && rcpath != path)
        free (path), path = NULL;
      contributors_filepath_BM = rcpath;
    }
  else
    {                           // some given contributors_filepath_bm with --contributors-path= ... argument
      if (access (contributors_filepath_BM, R_OK))
        FATAL_BM ("cannot read contributors file %s - %m",
                  contributors_filepath_BM);
      char *rcpath = realpath (contributors_filepath_BM, NULL);
      if (!rcpath)
        FATAL_BM ("cannot get real path of contributors file %s - %m",
                  contributors_filepath_BM);
      contributors_filepath_BM = rcpath;
    }
  if (access (contributors_filepath_BM, R_OK))
    FATAL_BM ("cannot read real contributors file %s - %m",
              contributors_filepath_BM);
  if (!print_contributor_of_oid_bm)     // otherwise silence
    INFOPRINTF_BM ("using %s as the contributors file",
                   contributors_filepath_BM);
}                               /* end initialize_contributors_path_BM */



////////////////

void
initialize_passwords_path_BM (void)
{
  if (!passwords_filepath_BM)   // no --passwords-file program option
    {
      DBGPRINTF_BM
        ("initialize_passwords_path_BM without passwords_filepath_BM");
      char *path = NULL;
      const char *homepath = NULL;
      if (!access (PASSWORDS_FILE_BM, R_OK))
        passwords_filepath_BM = PASSWORDS_FILE_BM;
      else if ((homepath = bismon_home_BM ()) != NULL
               && asprintf (&path, "%s/" PASSWORDS_FILE_BM, homepath) > 0
               && path != NULL && (!access (path, R_OK)
                                   || (free (path), (path = NULL))))
        passwords_filepath_BM = path;
      if (!passwords_filepath_BM)
        {
          char cwdbuf[128];
          memset (cwdbuf, 0, sizeof (cwdbuf));
          if (!getcwd (cwdbuf, sizeof (cwdbuf)))
            strcpy (cwdbuf, "./");
          FATAL_BM
            ("no %s file found here in %s or in $HOME %s, pass --passwords-file=... option to give one, or make an empty one e.g. with touch(1)",
             PASSWORDS_FILE_BM, cwdbuf, homepath);
        }
      if (access (passwords_filepath_BM, R_OK))
        FATAL_BM ("cannot read passwords file %s - %m",
                  passwords_filepath_BM);
      char *rcpath = realpath (passwords_filepath_BM, NULL);
      if (!rcpath)
        FATAL_BM ("cannot get real path of passwords file %s - %m",
                  passwords_filepath_BM);
      if (path && rcpath != path)
        free (path), path = NULL;
      passwords_filepath_BM = rcpath;
    }
  else
    {
      DBGPRINTF_BM
        ("initialize_passwords_path_BM with passwords_filepath_BM '%s'",
         passwords_filepath_BM);
      // some given passwords_filepath_bm with --passwords-path= ... argument
      if (access (passwords_filepath_BM, R_OK))
        FATAL_BM ("cannot read passwords file %s - %m",
                  passwords_filepath_BM);
      char *rcpath = realpath (passwords_filepath_BM, NULL);
      if (!rcpath)
        FATAL_BM ("cannot get real path of passwords file %s - %m",
                  passwords_filepath_BM);
      passwords_filepath_BM = rcpath;
    }
  if (access (passwords_filepath_BM, R_OK))
    FATAL_BM ("cannot read real passwords file %s - %m",
              passwords_filepath_BM);
  struct stat mystat = { };
  if (stat (passwords_filepath_BM, &mystat))
    FATAL_BM ("cannot stat real passwords file %s - %m",
              passwords_filepath_BM);
  if ((mystat.st_mode & S_IFMT) != S_IFREG)
    FATAL_BM ("real passwords file %s is not a regular file",
              passwords_filepath_BM);
  if ((mystat.st_mode & (S_IRWXG | S_IRWXO)) != 0)
    FATAL_BM
      ("real passwords file %s should not be group or others readable/writable but only by owner; run chmod go-rwx on it",
       passwords_filepath_BM);
  INFOPRINTF_BM ("using %s as the password file", passwords_filepath_BM);
}                               /* end initialize_passwords_path_BM */


void
initialize_contact_path_BM (void)
{
  if (!contact_filepath_BM)     // no --passwords-file program option
    {
      char *path = NULL;
      const char *homepath = NULL;
      if (!access (CONTACT_FILE_BM, R_OK))
        contact_filepath_BM = CONTACT_FILE_BM;
      else if ((homepath = bismon_home_BM ()) != NULL
               && asprintf (&path, "%s/" CONTACT_FILE_BM, homepath) > 0
               && path != NULL && (!access (path, R_OK)
                                   || (free (path), (path = NULL))))
        contact_filepath_BM = path;
      if (!contact_filepath_BM)
        {
          char cwdbuf[128];
          memset (cwdbuf, 0, sizeof (cwdbuf));
          if (!getcwd (cwdbuf, sizeof (cwdbuf)))
            strcpy (cwdbuf, "./");
          FATAL_BM
            ("no %s file found here in %s or in $HOME %s, pass --contact-file=... option to give one",
             CONTACT_FILE_BM, cwdbuf, homepath);
        }
      if (access (contact_filepath_BM, R_OK))
        FATAL_BM ("cannot read contact file %s - %m", contact_filepath_BM);
      char *rcpath = realpath (contact_filepath_BM, NULL);
      if (!rcpath)
        FATAL_BM ("cannot get real path of contact file %s - %m",
                  contact_filepath_BM);
      if (path && rcpath != path)
        free (path), path = NULL;
      contact_filepath_BM = rcpath;
    }
  else
    {                           // some given contact_filepath_bm with --contact-path= ... argument
      if (access (contact_filepath_BM, R_OK))
        FATAL_BM ("cannot read contact file %s - %m", contact_filepath_BM);
      char *rcpath = realpath (contact_filepath_BM, NULL);
      if (!rcpath)
        FATAL_BM ("cannot get real path of contact file %s - %m",
                  contact_filepath_BM);
      contact_filepath_BM = rcpath;
    }
  if (access (contact_filepath_BM, R_OK))
    FATAL_BM ("cannot read real contact file %s - %m", contact_filepath_BM);
  struct stat mystat = { };
  if (stat (contact_filepath_BM, &mystat))
    FATAL_BM ("cannot stat real contact file %s - %m", contact_filepath_BM);
  if ((mystat.st_mode & S_IFMT) != S_IFREG)
    FATAL_BM ("real contact file %s is not a regular file",
              contact_filepath_BM);
  if ((mystat.st_mode & (S_IRWXG | S_IRWXO)) != 0)
    FATAL_BM
      ("real contact file %s should not be group or others readable/writable but only by owner; run chmod go-rwx on it",
       contact_filepath_BM);
  INFOPRINTF_BM ("using %s as the contact file", contact_filepath_BM);
}                               /* end initialize_contact_path_BM */

void
parse_contact_BM (void)
{
#define CONTACT_MAXLEN_BM 256
  FILE *cfil = fopen (contact_filepath_BM, "r");
  if (!cfil)
    FATAL_BM ("failed to open contact file %s - %m", contact_filepath_BM);
  char linbuf[CONTACT_MAXLEN_BM];
  int lineno = 0;
  while (memset (linbuf, 0, sizeof (linbuf)),
         fgets (linbuf, sizeof (linbuf), cfil))
    {
      lineno++;
      if (linbuf[0] == '#' || linbuf[0] == '\n' || !linbuf[0])
        continue;
      int linlen = strlen (linbuf);
      if (linlen > 0 && linbuf[linlen - 1] == '\n')
        linbuf[--linlen] = (char) 0;
      char *lt = strchr (linbuf, '<');
      if (!lt)
        FATAL_BM ("bad line#%d without '<' in contact file %s: %s",
                  lineno, contact_filepath_BM, linbuf);
      char *at = strchr (lt, '@');
      if (!at)
        FATAL_BM ("bad line#%d without '@' in contact file %s: %s",
                  lineno, contact_filepath_BM, linbuf);
      char *gt = strchr (at, '>');
      if (!gt)
        FATAL_BM ("bad line#%d without '>' in contact file %s: %s",
                  lineno, contact_filepath_BM, linbuf);
      if (contact_name_BM)
        FATAL_BM ("bad line#%d in contact file %s (duplicate name): %s",
                  lineno, contact_filepath_BM, linbuf);
      if (contact_email_BM)
        FATAL_BM ("bad line#%d in contact file %s (duplicate email): %s",
                  lineno, contact_filepath_BM, linbuf);
      {
        char *endname = lt - 1;
        while (endname > linbuf && isspace (*endname))
          endname--;
        char *begname = linbuf;
        while (isspace (*begname) && begname < endname)
          begname++;
        int namlen = endname - begname + 1;
        contact_name_BM = calloc (namlen + 2, 1);
        if (!contact_name_BM)
          FATAL_BM ("failed to calloc contact name (%d bytes)", namlen + 2);
        strncpy (contact_name_BM, begname, namlen);
      }
      {
        char *endemail = gt - 1;
        char *startemail = lt + 1;
        if (startemail >= endemail)
          FATAL_BM ("bad email in line#%d in contact file %s: %s",
                    lineno, contact_filepath_BM, linbuf);
        contact_email_BM = calloc (endemail - startemail + 2, 1);
        if (!contact_email_BM)
          FATAL_BM ("failed to calloc contact email (%d bytes)",
                    (int) (endemail - startemail + 2));
        strncpy (contact_email_BM, startemail, endemail - startemail + 1);
      }
    }
  fflush (cfil);
  fsync (fileno (cfil));
  fclose (cfil);
  DBGPRINTF_BM
    ("parse_contact_BM: contact filepath '%s' name '%s' email '%s'",
     contact_filepath_BM, contact_name_BM, contact_email_BM);
#undef CONTACT_MAXLEN_BM
  if (!contact_name_BM)
    FATAL_BM ("missing contact name after parsing %s", contact_filepath_BM);
  if (!contact_email_BM)
    FATAL_BM ("missing contact email after parsing %s", contact_filepath_BM);
  char *errmsg = NULL;
  if (!valid_email_BM (contact_email_BM, CHECKDNS_BM, &errmsg))
    FATAL_BM ("invalid contact email (%s) after parsing %s", errmsg,
              contact_filepath_BM);
#warning the contact should be used in send-bismon-html-email.scm and handled for login_ONIONBM.thtml
}                               /* end parse_contact_BM */


////////////////
void
parse_values_after_load_BM (void)
{
  LOCALFRAME_BM ( /*prev stackf: */ NULL, /*descr: */ NULL,
                 objectval_tyBM * parsob;
                 value_tyBM parsedval;
    );
  _.parsob = makeobj_BM ();
  INFOPRINTF_BM ("parsing %d values after load %s using parsob %s\n",
                 nb_parsed_values_after_load_bm, load_dir_bm,
                 objectdbg_BM (_.parsob));
  for (int ix = 0; ix < nb_parsed_values_after_load_bm; ix++)
    {
      const char *curvalstr = parsed_values_after_loadarr_bm[ix];
      INFOPRINTF_BM ("parsing value#%d:::\n%s\n///----\n", ix, curvalstr);
      struct parser_stBM *pars =
        makeparser_memopen_BM (curvalstr, strlen (curvalstr), _.parsob);
      ASSERT_BM (pars != NULL);
      bool gotval = false;
      _.parsedval = parsergetvalue_BM (pars, CURFRAME_BM, 0, &gotval);
      if (!gotval)
        FATAL_BM ("failed to parse value#%d", ix);
      INFOPRINTF_BM ("parsed value#%d is:\n%s\n", ix,
                     debug_outstr_value_BM (_.parsedval, CURFRAME_BM, 0));
      fflush (NULL);
      objclearpayload_BM (_.parsob);
    }
  for (int ix = 0; ix < nb_parsed_values_after_load_bm; ix++)
    {
      free (parsed_values_after_loadarr_bm[ix]),
        parsed_values_after_loadarr_bm[ix] = NULL;
    }
  INFOPRINTF_BM ("done parsing %d values after load\n",
                 nb_parsed_values_after_load_bm);
}                               /* end parse_values_after_load_BM */

void
run_testplugins_after_load_BM (void)
{
  void *testplugindlharr[MAXTESTPLUGINS_AFTER_LOAD_BM] = { };
  double startelapsedtime = elapsedtime_BM ();
  double startcputime = cputime_BM ();
  LOCALFRAME_BM ( /*prev stackf: */ NULL, /*descr: */ NULL,
                 value_tyBM pluginamv;  //
                 objectval_tyBM * pluginob;
    );
  // check sanity of test plugins
  static char cwdbuf[200];
  if (!getcwd (cwdbuf, sizeof (cwdbuf) - 1))
    FATAL_BM ("run_testplugins_after_load_BM: getcwd failed %m");
#define TESTPLUGIN_MAXNAMELEN_BM 40
  for (int ix = 0; ix < nb_testplugins_after_load_bm; ix++)
    {
      char pluginsrcbuf[2 * TESTPLUGIN_MAXNAMELEN_BM];
      char pluginbinbuf[2 * TESTPLUGIN_MAXNAMELEN_BM];
      memset (pluginsrcbuf, 0, sizeof (pluginsrcbuf));
      memset (pluginbinbuf, 0, sizeof (pluginbinbuf));
      char *curtestplugin = testplugins_after_loadarr_bm[ix];
      if (!curtestplugin)
        FATAL_BM ("NULL testplugin #%d", ix);
      if (strlen (curtestplugin) > TESTPLUGIN_MAXNAMELEN_BM)
        FATAL_BM ("too long testplugin #%d '%s' (maxlen %d)", ix,
                  curtestplugin, TESTPLUGIN_MAXNAMELEN_BM);
      for (const char *pc = curtestplugin; *pc; pc++)
        if (!isalnum (*pc) && *pc != '_')
          FATAL_BM ("bad testplugin #%d '%s'", ix, curtestplugin);
      DBGPRINTF_BM ("run_testplugins_after_load curtestplugin '%s' ix#%d",
                    curtestplugin, ix);
      snprintf (pluginsrcbuf, sizeof (pluginsrcbuf), "drafts/testplugin_%s.c",
                curtestplugin);
      FILE *fsrc = fopen (pluginsrcbuf, "r");
      if (!fsrc)
        FATAL_BM ("testplugin #%d fopen '%s' failed in '%s' - %m",
                  ix, pluginsrcbuf, cwdbuf);
      if (fscanf (fsrc, "// BISMON TESTPLUGIN %40s", pluginbinbuf) < 1
          || strcmp (pluginbinbuf, curtestplugin))
        FATAL_BM
          ("testplugin #%d file '%s' in '%s' should start with '// BISMON TESTPLUGIN %s'",
           ix, pluginsrcbuf, cwdbuf, curtestplugin);
      fclose (fsrc), fsrc = NULL;
      snprintf (pluginbinbuf, sizeof (pluginbinbuf),
                "make drafts/testplugin_%s.so", curtestplugin);
      INFOPRINTF_BM ("testplugin running command %s (#%d)\n", pluginbinbuf,
                     ix);
      fflush (NULL);
      int failmake = system (pluginbinbuf);
      if (failmake)
        FATAL_BM ("testplugin command %s failed with code %d", pluginbinbuf,
                  failmake);
      snprintf (pluginbinbuf, sizeof (pluginbinbuf),
                "drafts/testplugin_%s.so", curtestplugin);
      if (access (pluginbinbuf, R_OK))
        FATAL_BM ("testplugin access %s failed %m", pluginbinbuf);
      fflush (NULL);
      void *testpluginhdl = dlopen (pluginbinbuf, RTLD_NOW | RTLD_GLOBAL);
      if (!testpluginhdl)
        FATAL_BM ("testplugin dlopen %s failed - %s", pluginbinbuf,
                  dlerror ());
      DBGPRINTF_BM ("run_testplugins_after_load dlopen-ed '%s' ix#%d @%p",
                    curtestplugin, ix, testpluginhdl);
      testplugindlharr[ix] = testpluginhdl;
      char initestname[TESTPLUGIN_MAXNAMELEN_BM + sizeof ("FOO_initest_BM")];
      snprintf (initestname, sizeof (initestname), "%s_initest_BM",
                curtestplugin);
      testplugininit_sigBM *inifun =
        (testplugininit_sigBM *) dlsym (testpluginhdl, initestname);
      if (inifun)
        {
          DBGPRINTF_BM
            ("run_testplugins_after_load initestname %s before inifun @%p #%d",
             initestname, inifun, ix);
          (*inifun) (CURFRAME_BM, curtestplugin, ix);
          DBGPRINTF_BM
            ("run_testplugins_after_load initestname %s  after inifun @%p #%d\n",
             initestname, inifun, ix);
        }
      else
        DBGPRINTF_BM
          ("run_testplugins_after_load initestname %s dlsym failure %s",
           initestname, dlerror ());

    }                           /* end for ix, initialization */
  INFOPRINTF_BM ("loaded %d test plugins\n", nb_testplugins_after_load_bm);
  fflush (NULL);
  for (int ix = 0; ix < nb_testplugins_after_load_bm; ix++)
    {
      char *curtestplugin = testplugins_after_loadarr_bm[ix];
      ASSERT_BM (curtestplugin);
      ASSERT_BM (testplugindlharr[ix]);
      char runtestname[TESTPLUGIN_MAXNAMELEN_BM + sizeof ("FOO_runtest_BM")];
      snprintf (runtestname, sizeof (runtestname), "%s_runtest_BM",
                curtestplugin);
      testpluginrun_sigBM *runfun = dlsym (testplugindlharr[ix], runtestname);
      if (!runfun)
        FATAL_BM ("dlsym %s failed for testplugin %s #%d - %s",
                  runtestname, curtestplugin, ix, dlerror ());
      DBGPRINTF_BM
        ("run_testplugins_after_load runtestname %s  before runfun @%p #%d",
         runtestname, runfun, ix);
      int runres = (*runfun) (CURFRAME_BM, curtestplugin, ix);
      DBGPRINTF_BM
        ("run_testplugins_after_load runtestname %s  after runfun @%p #%d runres %d",
         runtestname, runfun, ix, runres);
      if (runres > 0)
        FATAL_BM
          ("testplugin %s runtestname %s failed (ix#%d) with result %d",
           curtestplugin, runtestname, ix, runres);
      else
        INFOPRINTF_BM ("testplugin %s runtestname %s successful (ix#%d)\n",
                       curtestplugin, runtestname, ix);
      fflush (NULL);
    }                           /* end for ix, running */
  double endelapsedtime = elapsedtime_BM ();
  double endcputime = cputime_BM ();
  INFOPRINTF_BM
    ("run_testplugins_after_load_BM done for %d testplugins, %.3f elapsed, %.3f cpu seconds\n",
     nb_testplugins_after_load_bm, endelapsedtime - startelapsedtime,
     endcputime - startcputime);
}                               /* end of run_testplugins_after_load_BM */

////////////////
/// run initializations, if any, after the load
void
init_afterload_bm ()
{
  LOCALFRAME_BM ( /*prev stackf: */ NULL, /*descr: */ NULL,
                 objectval_tyBM * parsob; value_tyBM parsedval;
                 value_tyBM resval;
    );
  _.parsob = makeobj_BM ();
  INFOPRINTF_BM ("doing %d closures after load %s using parsob %s\n",
                 count_init_afterload_bm, load_dir_bm,
                 objectdbg_BM (_.parsob));
  for (int ix = 0; ix < count_init_afterload_bm; ix++)
    {
      const char *curclostr = arr_init_afterload_bm[ix];
      INFOPRINTF_BM ("parsing do-after-load closure#%d:::\n%s\n///----\n", ix,
                     curclostr);
      struct parser_stBM *pars =
        makeparser_memopen_BM (curclostr, strlen (curclostr), _.parsob);
      ASSERT_BM (pars != NULL);
      bool gotval = false;
      _.parsedval = parsergetvalue_BM (pars, CURFRAME_BM, 0, &gotval);
      if (!gotval)
        FATAL_BM ("failed to parse value#%d", ix);
      INFOPRINTF_BM ("parsed do-after-load closure#%d is:\n%s\n", ix,
                     OUTSTRVALUE_BM (_.parsedval));
      fflush (NULL);
      objclearpayload_BM (_.parsob);
      if (isclosure_BM (_.parsedval) || isobject_BM (_.parsedval))
        {
          _.resval = apply0_BM (_.parsedval, CURFRAME_BM);
          DBGPRINTF_BM ("after do-after-load closure#%d, resval=%s\n",
                        ix, OUTSTRVALUE_BM (_.resval));
          if (!_.resval)
            WARNPRINTF_BM ("failed do-after-load closure#%d:\n%s\n\n",
                           ix, OUTSTRVALUE_BM (_.resval));
          else
            INFOPRINTF_BM ("do-after-load closure#%d gave %s\n",
                           ix, OUTSTRVALUE_BM (_.resval));
        }
      else
        WARNPRINTF_BM ("bad do-after-load non-closure#%d:\n%s\n", ix,
                       OUTSTRVALUE_BM (_.parsedval));
      arr_init_afterload_bm[ix] = NULL;
      free ((void *) curclostr);
    }
  free (arr_init_afterload_bm), arr_init_afterload_bm = NULL;
  size_init_afterload_bm = 0;
}                               /* end init_afterload_bm */

void
add_contributors_after_load_BM (void)
{
  LOCALFRAME_BM ( /*prev stackf: */ NULL, /*descr: */ NULL,
                 objectval_tyBM * userob;
    );
  ASSERT_BM (count_added_contributors_bm > 0);
  ASSERT_BM (added_contributors_arr_bm != NULL);
  INFOPRINTF_BM ("adding %d contributors after load",
                 count_added_contributors_bm);
  for (int cix = 0; cix < count_added_contributors_bm; cix++)
    {
      char *errmsg = NULL;
      _.userob =
        add_contributor_user_BM (added_contributors_arr_bm[cix], &errmsg,
                                 CURFRAME_BM);
      if (!_.userob)
        FATAL_BM ("failed to add contributor user#%d %s - %s", cix,
                  added_contributors_arr_bm[cix], errmsg);
      ASSERT_BM (errmsg == NULL);
      INFOPRINTF_BM ("added contributor %s with object %s",
                     added_contributors_arr_bm[cix], objectdbg_BM (_.userob));
    }
  for (int cix = 0; cix < count_added_contributors_bm; cix++)
    free (added_contributors_arr_bm[cix]), added_contributors_arr_bm[cix] =
      NULL;
  INFOPRINTF_BM ("added %d contributors after load",
                 count_added_contributors_bm);
  free (added_contributors_arr_bm);
  count_added_contributors_bm = 0;
  size_added_contributors_bm = 0;
}                               /* end add_contributors_after_load_BM */




void
remove_contributors_after_load_BM (void)
{
  LOCALFRAME_BM ( /*prev stackf: */ NULL, /*descr: */ NULL,
                 objectval_tyBM * oldcontribob;
    );
  ASSERT_BM (count_removed_contributors_bm > 0);
  INFOPRINTF_BM ("removing %d contributors after load",
                 count_removed_contributors_bm);
  ASSERT_BM (removed_contributors_arr_bm != NULL);
  for (int cix = 0; cix < count_removed_contributors_bm; cix++)
    {
      _.oldcontribob =
        remove_contributor_by_name_BM (removed_contributors_arr_bm[cix],
                                       CURFRAME_BM);
      if (!_.oldcontribob)
        FATAL_BM ("failed to remove contributor user#%d %ss",
                  cix, removed_contributors_arr_bm[cix]);
      objputspacenum_BM (_.oldcontribob, TransientSp_BM);
      INFOPRINTF_BM ("removed contributor %s of object %s",
                     removed_contributors_arr_bm[cix],
                     objectdbg_BM (_.oldcontribob));
    }
  for (int cix = 0; cix < count_removed_contributors_bm; cix++)
    free (removed_contributors_arr_bm[cix]),
      removed_contributors_arr_bm[cix] = NULL;
  INFOPRINTF_BM ("removed %d contributors after load",
                 count_removed_contributors_bm);
  free (removed_contributors_arr_bm);
  count_removed_contributors_bm = 0;
  size_removed_contributors_bm = 0;
}                               /* end remove_contributors_after_load_BM */




void
add_passwords_from_file_BM (const char *addedpasspath)
{
  LOCALFRAME_BM ( /*prev stackf: */ NULL, /*descr: */ NULL,
                 objectval_tyBM * contribob;
    );
  ASSERT_BM (addedpasspath != NULL);
  DBGPRINTF_BM ("add_passwords_from_file start addedpasspath %s",
                addedpasspath);
  bool withstdin = (!addedpasspath[0] || !strcmp (addedpasspath, "-"));
  FILE *pasfil = withstdin ? stdin : fopen (addedpasspath, "r");
  if (!pasfil)
    FATAL_BM ("cannot open added passwords file %s : %m", addedpasspath);
  size_t sizpas = 128;
  char *linpas = calloc (1, sizpas);
  int lincnt = 0;
  int nbch = 0;
  if (!linpas)
    FATAL_BM ("calloc failure in add_passwords_from_file - %m");
  do
    {
      ssize_t linlenpas = getline (&linpas, &sizpas, pasfil);
      if (linlenpas < 0)
        break;
      if (linlenpas > 0 && linpas[linlenpas - 1] == '\n')
        linpas[linlenpas - 1] = (char) 0;
      lincnt++;
      DBGPRINTF_BM ("add_passwords_from_file lincnt=%d linpas=%s",
                    lincnt, linpas);
      if (linpas[0] == (char) 0 || linpas[0] == '#')
        continue;
      char *pcol = strchr (linpas, ':');
      if (linlenpas < 10 || !pcol || strlen (pcol + 1) < 8)
        FATAL_BM ("bad or too short line#%d when adding passwords from %s",
                  lincnt, addedpasspath);
      *pcol = (char) 0;
      const char *contributorstr = linpas;
      const char *passwdstr = pcol + 1;
      _.contribob = find_contributor_BM (contributorstr, CURFRAME_BM);
      DBGPRINTF_BM ("add_passwords_from_file  line#%d contributorstr '%s' "
                    " passwdstr '%s' contribob %s",
                    lincnt, contributorstr, passwdstr,
                    objectdbg_BM (_.contribob));
      if (!_.contribob)
        FATAL_BM
          ("add_passwords_from_file line#%d cannot find contributor for '%s'",
           lincnt, contributorstr);
      {
        char *errmsg = NULL;
        if (!valid_password_BM (passwdstr, &errmsg))
          FATAL_BM ("add_passwords_from_file line#%d password is invalid: %s",
                    lincnt, errmsg);
      }
      DBGPRINTF_BM ("add_passwords_from_file  line#%d contributorstr '%s'"
                    "  passwdstr '%s' contribob %s",
                    lincnt, contributorstr, passwdstr,
                    objectdbg_BM (_.contribob));
      if (!put_contributor_password_BM (_.contribob, passwdstr, CURFRAME_BM))
        FATAL_BM
          ("add_passwords_from_file line#%d cannot set password for '%s'",
           lincnt, contributorstr);
      DBGPRINTF_BM ("add_passwords_from_file "
                    "after put_contributor_password line#%d contributorstr '%s'"
                    "  passwdstr '%s' contribob %s",
                    lincnt, contributorstr, passwdstr,
                    objectdbg_BM (_.contribob));
      {
        objlock_BM (_.contribob);
        INFOPRINTF_BM ("changed password for contributor %s named %s",
                       objectdbg_BM (_.contribob),
                       bytstring_BM (objcontributornamepayl_BM (_.contribob))
                       ? : "**??**");
        objunlock_BM (_.contribob);
      }
      nbch++;
    }
  while (!feof (pasfil));
  if (!withstdin)
    fclose (pasfil), pasfil = NULL;
  if (withstdin)
    INFOPRINTF_BM ("Added or changed %d passwords using standard input",
                   nbch);
  else
    INFOPRINTF_BM ("Added or changed %d passwords using file %s", nbch,
                   addedpasspath);
}                               /* end of add_passwords_from_file_BM */




////////////////////////////////////////////////////////////////

extern void do_internal_deferred_apply3_BM (value_tyBM funv,
                                            value_tyBM arg1,
                                            value_tyBM arg2, value_tyBM arg3);
extern void do_internal_deferred_send3_BM (value_tyBM recv,
                                           objectval_tyBM * obsel,
                                           value_tyBM arg1,
                                           value_tyBM arg2, value_tyBM arg3);


////////////////////////////////////////////////////////////////
// called from did_deferred_BM
void
do_internal_deferred_apply3_BM (value_tyBM fun,
                                value_tyBM arg1, value_tyBM arg2,
                                value_tyBM arg3)
{
  LOCALFRAME_BM ( /*prev stackf: */ NULL, /*descr: */ NULL,
                 value_tyBM funv;       //
                 objectval_tyBM * funob;        //
                 value_tyBM arg1v, arg2v, arg3v;
                 value_tyBM resappv;    //
                 value_tyBM failres;    //
                 value_tyBM failplace;  //
    );
  _.funv = fun;
  _.arg1v = arg1;
  _.arg2v = arg2;
  _.arg3v = arg3;
  int failcod = 0;
  _.failres = NULL;
  _.failplace = NULL;
  struct failurelockset_stBM flockset = { };
  initialize_failurelockset_BM (&flockset, sizeof (flockset));
  LOCAL_FAILURE_HANDLE_BM (&flockset, lab_failureapply, failcod, _.failres,
                           _.failplace);
  if (failcod)
  lab_failureapply:
    {
      destroy_failurelockset_BM (&flockset);
      curfailurehandle_BM = NULL;
      WARNPRINTF_BM ("do_internal_deferred_apply3_BM  failure, failcod#%d failreason: %s\n"     //
                     " arg1: %s, arg2: %s, arg3: %s", failcod,  //
                     OUTSTRVALUE_BM (_.failres),        //
                     OUTSTRVALUE_BM (_.arg1v),  //
                     OUTSTRVALUE_BM (_.arg2v),  //
                     OUTSTRVALUE_BM (_.arg3v));
      return;
    }
  DBGBACKTRACEPRINTF_BM ("do_internal_deferred_apply3_BM funv %s arg1: %s, arg2: %s, arg3: %s", //
                         OUTSTRVALUE_BM (_.funv),       //
                         OUTSTRVALUE_BM (_.arg1v),      //
                         OUTSTRVALUE_BM (_.arg2v),      //
                         OUTSTRVALUE_BM (_.arg3v));
  if (isclosure_BM (_.funv))
    {
      _.funob = closureconn_BM (_.funv);
    }
  else if (isobject_BM (_.funv))
    {
      _.funob = objectcast_BM (_.funv);
    }
  else
    {
      _.funob = NULL;
      WARNPRINTF_BM ("do_internal_deferred_apply3_BM bad funv %s arg1 %s arg2 %s arg3 %s",      //
                     OUTSTRVALUE_BM (_.funv),   //
                     OUTSTRVALUE_BM (_.arg1v),  //
                     OUTSTRVALUE_BM (_.arg2v),  //
                     OUTSTRVALUE_BM (_.arg3v));
    }
  _.resappv = NULL;
  if (!isobject_BM (_.funob) || !_.funob->ob_rout)
    WARNPRINTF_BM ("do_internal_deferred_apply3_BM no routine for funv %s arg1 %s arg2 %s arg3 %s",     //
                   OUTSTRVALUE_BM (_.funv),     //
                   OUTSTRVALUE_BM (_.arg1v),    //
                   OUTSTRVALUE_BM (_.arg2v),    //
                   OUTSTRVALUE_BM (_.arg3v));
  else
    {
      objlock_BM (_.funob);
      _.resappv = apply3_BM (_.funv, CURFRAME_BM, _.arg1v, _.arg2v, _.arg3v);
      objunlock_BM (_.funob);
    }
  DBGPRINTF_BM ("do_internal_deferred_apply3_BM applied funv %s arg1 %s arg2 %s arg3 %s => resapp %s",  //
                OUTSTRVALUE_BM (_.funv),        //
                OUTSTRVALUE_BM (_.arg1v),       //
                OUTSTRVALUE_BM (_.arg2v),       //
                OUTSTRVALUE_BM (_.arg3v),       //
                OUTSTRVALUE_BM (_.resappv));
  if (!_.resappv)
    {
      WARNPRINTF_BM ("do_internal_deferred_apply3_BM NULL result of application of funv %s arg1 %s arg2 %s arg3 %s",    //
                     OUTSTRVALUE_BM (_.funv),   //
                     OUTSTRVALUE_BM (_.arg1v),  //
                     OUTSTRVALUE_BM (_.arg2v),  //
                     OUTSTRVALUE_BM (_.arg3v));
    }
  destroy_failurelockset_BM (&flockset);
  curfailurehandle_BM = NULL;
}                               /* end do_internal_defer_apply3_BM */


// called from did_deferred_BM
void
do_internal_deferred_send3_BM (value_tyBM recv, objectval_tyBM * obsel,
                               value_tyBM arg1, value_tyBM arg2,
                               value_tyBM arg3)
{
  LOCALFRAME_BM ( /*prev stackf: */ NULL, /*descr: */ NULL,
                 objectval_tyBM * obsel;
                 value_tyBM recva, arg1v, arg2v, arg3v;
                 value_tyBM failres;    //
                 value_tyBM failplace;  //
    );
  _.recva = recv;
  _.obsel = obsel;
  _.arg1v = arg1;
  _.arg2v = arg2;
  _.arg3v = arg3;
  int failcod = 0;
  _.failres = NULL;
  _.failplace = NULL;
  struct failurelockset_stBM flockset = { };
  initialize_failurelockset_BM (&flockset, sizeof (flockset));
  LOCAL_FAILURE_HANDLE_BM (&flockset, lab_failuresend, failcod, _.failres,
                           _.failplace);
  if (failcod)
  lab_failuresend:
    {
      destroy_failurelockset_BM (&flockset);
      curfailurehandle_BM = NULL;
      WARNPRINTF_BM ("do_internal_deferred_send3_BM failure, failcod#%d\n" "failreason: %s\n" "failplace: %s\n",        //
                     failcod,
                     OUTSTRVALUE_BM (_.failres),
                     OUTSTRVALUE_BM (_.failplace));
      return;
    }
  DBGPRINTF_BM ("do_internal_deferred_send3_BM recv %s obsel %s arg1 %s arg2 %s arg3 %s",       //
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
  DBGPRINTF_BM ("do_internal_deferred_send3_BM  did send recv %s obsel %s",     //
                debug_outstr_value_BM (_.recva, //
                                       CURFRAME_BM, 0), //
                objectdbg_BM (_.obsel));
  destroy_failurelockset_BM (&flockset);
  curfailurehandle_BM = NULL;
}                               /* end do_internal_defer_send3_BM */



////////////////////////////////////////////////////////////////
/// mail testing
void
do_test_mailhtml_bm (void)
{
  LOCALFRAME_BM (NULL, /*descr: */ NULL,
                 objectval_tyBM * contribob;    //
                 value_tyBM contnamev;  //
    );
  DBGPRINTF_BM
    ("do_test_mailhtml_bm start: mailhtml (file='%s' contributor='%s' subject='%s' attachment %s)",
     mailhtml_file_bm, mailhtml_contributor_bm, mailhtml_subject_bm,
     mailhtml_attachment_bm ? : "*none*");
  // find and check the contributor
  {
    rawid_tyBM contid = { 0, 0 };
    char *errmsg = NULL;
    const char *endc = NULL;
    _.contribob = NULL;
    if (mailhtml_contributor_bm[0] == '_'
        &&
        validid_BM ((contid =
                     parse_rawid_BM (mailhtml_contributor_bm, &endc))))
      {
        _.contribob = findobjofid_BM (contid);
      }
    else if (valid_contributor_name_BM (mailhtml_contributor_bm, &errmsg))
      {
        _.contribob =
          find_contributor_BM (mailhtml_contributor_bm, CURFRAME_BM);
      };
    char contidbuf[32] = { };
    idtocbuf32_BM (contid, contidbuf);
    if (!objhascontributorpayl_BM (_.contribob))
      FATAL_BM ("bad mailhtml contributor %s =%s/%s",
                mailhtml_contributor_bm, objectdbg_BM (_.contribob),
                contidbuf);
    DBGPRINTF_BM ("do_test_mailhtml_bm contributor='%s' == %s",
                  mailhtml_contributor_bm, objectdbg_BM (_.contribob));
  }
  _.contnamev = (value_tyBM) objcontributornamepayl_BM (_.contribob);
  bool popenfile = mailhtml_file_bm[0] == '|';
  FILE *infil = popenfile       //
    ? popen (mailhtml_file_bm + 1, "r") //
    : fopen (mailhtml_file_bm, "r");
  if (!infil)
    FATAL_BM ("fail to %s mail input %s - %m",
              popenfile ? "popen" : "fopen", mailhtml_file_bm);
  char *bufzon = NULL;
  size_t bufsiz = 0;
  FILE *bufil = open_memstream (&bufzon, &bufsiz);
  if (!bufil)
    FATAL_BM ("open_memstream failure for %s contributor %s / %s - %m",
              mailhtml_file_bm, mailhtml_contributor_bm,
              objectdbg_BM (_.contribob));
  char *linbuf = NULL;
  char *dyncontrib = NULL;
  asprintf (&dyncontrib, "%s (%s)", bytstring_BM (_.contnamev),
            objectdbg_BM (_.contribob));
  size_t linsiz = 0;
  do
    {
      int linlen = getline (&linbuf, &linsiz, infil);
      if (linlen < 0)
        break;
      /**** 
       *  should handle the following "processing instructions":
       * <?bismon-contributor?>
       * <?bismon-subject?>
       * <?bismon-attachment?>
       * <?bismon-pid?>
       * <?bismon-host?>
       * <?bismon-lastgitcommit?>
       * <?bismon-timestamp?>
       ****/
      char *pc = linbuf;
      char *prevpc = pc;
      char *pi = NULL;
      char *npc = NULL;
      const char *repl = NULL;
      while ((pi = strstr (pc, "<?bismon")) != NULL)
        {
          char smallbuf[64];
          int lnpi = 0;
          npc = NULL;
          memset (smallbuf, 0, sizeof (smallbuf));
#define MAIL_WITH_PI_bm(CurPi)			\
	  ((lnpi=strlen(CurPi))>0		\
	   && !strncmp(pi,CurPi,lnpi)		\
	   && (npc=pi+lnpi))
          if (MAIL_WITH_PI_bm ("<?bismon-contributor?>"))
            repl = dyncontrib;
          else if (MAIL_WITH_PI_bm ("<?bismon-subject?>"))
            repl = mailhtml_subject_bm;
          else if (MAIL_WITH_PI_bm ("<?bismon-attachment?>"))
            repl = mailhtml_attachment_bm;
          else if (MAIL_WITH_PI_bm ("<?bismon-pid?>"))
            {
              snprintf (smallbuf, sizeof (smallbuf),
                        "pid %ld", (long) getpid ());
              repl = smallbuf;
            }
          else if (MAIL_WITH_PI_bm ("<?bismon-host?>"))
            repl = myhostname_BM;
          else if (MAIL_WITH_PI_bm ("<?bismon-lastgitcommit?>"))
            repl = bismon_lastgitcommit;
          else if (MAIL_WITH_PI_bm ("<?bismon-timestamp?>"))
            repl = bismon_timestamp;
          else
            {
              npc = pc + strlen ("<?bismon");
              repl = "<?bismon";
            }
          fwrite (prevpc, pi - prevpc, 1, bufil);
          fputs (repl, bufil);
          prevpc = pi + lnpi;
          pc = npc;
        };
      fwrite (pc, linbuf + linlen - pc, 1, bufil);
#undef MAIL_WITH_PI_bm
      pc = npc;
    }
  while (!feof (infil));
  fflush (bufil);
  long buflen = ftell (bufil);
  DBGPRINTF_BM ("do_test_mailhtml_bm buflen=%ld; bufzon:\n%s\n", buflen,
                bufzon);
  if (!bufzon || buflen < 0 || buflen > (int) bufsiz)
    FATAL_BM
      ("do_test_mailhtml_bm corrupted bufil (bufzon@%p buflen=%ld bufsiz=%ld) %m",
       bufzon, buflen, (long) bufsiz);
  bufzon[buflen] = (char) 0;
  send_html_email_to_contributor_BM (mailhtml_subject_bm, bufzon,
                                     mailhtml_attachment_bm, _.contribob,
                                     CURFRAME_BM);
  fclose (bufil);
  free (bufzon), bufzon = NULL;
  free (linbuf), linbuf = NULL;
  free (dyncontrib), dyncontrib = NULL;
  linsiz = 0;
}                               /* end do_test_mailhtml_bm */



////////////////////////////////////////////////////////////////
void
give_prog_version_BM (const char *progname)
{
  char versionbuf[48];
  memset (versionbuf, 0, sizeof (versionbuf));
  confstr (_CS_GNU_LIBC_VERSION, versionbuf, sizeof (versionbuf) - 1);
  printf ("\n" "*** %s: version information\n", progname);
  printf ("\t timestamp: %s (%ld Epoch)\n", bismon_timestamp,
          bismon_timelong);
  printf ("\t git id: %s\n", bismon_gitid);
  printf ("\t last git commit: %s\n", bismon_lastgitcommit);
  printf ("\t last git tag: %s\n", bismon_lastgittag);
  printf ("\t source checksum: %s\n", bismon_checksum);
  printf ("\t source dir: %s\n", bismon_directory);
  printf ("\t GNUmakefile: %s\n", bismon_gnumakefile);
  printf ("\t libc runtime version: %s\n", versionbuf);
  printf ("\t Glib build version: %d.%d.%d\n",
          GLIB_MAJOR_VERSION, GLIB_MINOR_VERSION, GLIB_MICRO_VERSION);
  printf ("\t Jansson build version: %s, runtime %s\n", JANSSON_VERSION,
          jansson_version_str ());
  printf ("########\n");
  printf ("## to get help, run: %s --help\n\n", progname);
  fflush (NULL);
  exit (EXIT_SUCCESS);
}                               /* end give_prog_version_BM */

void
backtracerrorcb_BM (void *data __attribute__((unused)),
                    const char *msg, int errnum)
{
  backtracestate_BM = NULL;
  FATAL_BM ("backtrace error: %s #%d", msg, errnum);
}                               /* end backtracerrorcb_BM */


////////////////////////////////////////////////////////////////

/// nearly copied from Ian Lance Taylor's libbacktrace/print.c
/// see https://github.com/ianlancetaylor/libbacktrace
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
  if (funame)
    {
      int fnl = strlen (funame);
      objectval_tyBM *fnob = NULL;
      if (!strncmp (funame, ROUTINEOBJPREFIX_BM, strlen (ROUTINEOBJPREFIX_BM))
          && fnl > 5
          && !strcmp (funame + fnl - strlen (ROUTINESUFFIX_BM),
                      ROUTINESUFFIX_BM))
        {
          const char *endid = NULL;
          rawid_tyBM rid =
            parse_rawid_BM (funame + strlen (ROUTINEOBJPREFIX_BM), &endid);
          if (rid.id_hi > 0 && rid.id_lo > 0
              && endid + strlen (ROUTINESUFFIX_BM) == funame + fnl)
            {
              fnob = findobjofid_BM (rid);
            }
          if (fnob != NULL)
            {
              objlock_BM (fnob);
              value_tyBM commentv = NULL;
              const char *fnobnam = findobjectname_BM (fnob);
              if (fnobnam)
                fprintf (pdata->f, "0x%lx %s\n\t~%s\n", (unsigned long) pc,
                         funame, fnobnam);
              else if ((commentv = objgetattr_BM (fnob, BMP_comment)) != NULL
                       && (isstring_BM (commentv)))
                {
                  const char *combytes = bytstring_BM (commentv);
                  int comlen = lenstring_BM (commentv);
                  const char *eol = strchr (combytes, '\n');
                  if (eol && eol > combytes)
                    comlen = eol - combytes - 1;
                  fprintf (pdata->f, "0x%lx %s\n\t"     //
                           "€%.9s |%*s|\n", (unsigned long) pc, funame,
                           objectdbg_BM (fnob), comlen, combytes);
                }
              else
                fprintf (pdata->f, "0x%lx %s\n", (unsigned long) pc, funame);
              objunlock_BM (fnob);
            }
          else
            fprintf (pdata->f, "0x%lx %s !\n", (unsigned long) pc, funame);
        }
      else
        fprintf (pdata->f, "0x%lx %s\n", (unsigned long) pc, funame);
    }
  else                          /* no funame */
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
  if (filename)
    fprintf (pdata->f, "\t%s:%d\n", basename (filename), lineno);
  return 0;
}                               /* end printbt_callback_BM */

/* Print errors to stderr.  */

static void
errorbt_callback_BM (void *data_
                     __attribute__((unused)), const char *msg, int errnum)
{
  //  struct print_data_BM *pdata = (struct print_data_BM *) data;

  //if (pdata->state->filename != NULL)
  //  fprintf (stderr, "%s: ", pdata->state->filename);
  if (errnum > 0)
    WARNPRINTF_BM ("libbacktrace:: %s (%s)", msg, strerror (errnum));
  else
    WARNPRINTF_BM ("libbacktrace: %s", msg);
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

////////////////////////////////////////////////////////////////


void
log_begin_message_BM (void)
{
  FATAL_BM ("log_begin_message_BM obsolete");
}                               /* end log_begin_message_BM */



void
log_end_message_BM (void)
{
  FATAL_BM ("log_end_message_BM obsolete");
}                               /* end log_end_message_BM */



void
log_puts_message_BM (const char *str)
{
  FATAL_BM ("log_puts_message_BM obsolete for: %s", str);
}                               /* end log_puts_message_BM */

void
log_object_message_BM (const objectval_tyBM * obj)
{
  FATAL_BM ("log_object_message_BM obsolete for %s", objectdbg_BM (obj));
}                               /* end log_object_message_BM */

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
  FATAL_BM ("log_printf_message_BM obsolete: %s", buf);
  if (buf != smallbuf)
    free (buf);
}                               /* end log_printf_message_BM */



void
parse_program_options_BM (int argc, char **argv)
{
  int initialargc = argc;
  GOptionContext *gctx =
    g_option_context_new ("* the BISMON static source code analyzer *");
  GError *errp = NULL;
  g_option_context_set_summary (gctx,
                                "BISMON is a static source code analyzer, using GCC.\n"
                                "see github.com/bstarynk/bismon ...\n"
                                "WITHOUT WARRANTY, since GPLv3+ licensed");
  g_option_context_add_main_entries (gctx, optionstab_bm, NULL);
  if (!g_option_context_parse (gctx, &argc, &argv, &errp))
    {
      FATAL_BM
        ("%s failed to parse program options (pid #%d, host %s):\n... %s",
         argv[0], (int) getpid (), myhostname_BM, errp->message);
    }
  g_option_context_free (gctx);
  DBGPRINTF_BM ("end parse_program_options_BM, argc wad %d now %d",
                initialargc, argc);
}                               /* end parse_program_options_BM */


/**
 * This crashing_objrout_BM could be set as the ob_rout function in
 * objects. If called (it never should be called), it is crashing the
 * bismon application.
 **/
value_tyBM
crashing_objrout_BM (struct stackframe_stBM *stkf,
                     const value_tyBM arg1,
                     const value_tyBM arg2,
                     const value_tyBM arg3,
                     const value_tyBM arg4, const quasinode_tyBM * restargs)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM arg1v, arg2v, arg3v, arg4v;
    );
  _.arg1v = arg1;
  _.arg2v = arg2;
  _.arg3v = arg3;
  _.arg4v = arg4;
  FATAL_BM ("crashing_objrout_BM stkf@%p, CURFRAM@%p; arg1: %s, arg2: %s,\n"    //
            "... arg3: %s, arg4: %s, restargs=%p",      //
            (void *) stkf, (void *) &_, //
            debug_outstr_value_BM (_.arg1v, CURFRAME_BM, 0),    //
            debug_outstr_value_BM (_.arg2v, CURFRAME_BM, 0),    //
            debug_outstr_value_BM (_.arg3v, CURFRAME_BM, 0),    //
            debug_outstr_value_BM (_.arg4v, CURFRAME_BM, 0),    //
            (void *) restargs);
  return NULL;
}                               /* end of crashing_objrout_BM */



/**
 * This warning_objrout_BM could be set as the ob_rout function in
 * objects. If called, it emits a warning, and from the main thread
 * prints backtrace details.
 **/
value_tyBM
warning_objrout_BM (struct stackframe_stBM *stkf,
                    const value_tyBM arg1,
                    const value_tyBM arg2,
                    const value_tyBM arg3,
                    const value_tyBM arg4, const quasinode_tyBM * restargs)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM arg1v, arg2v, arg3v, arg4v;
    );
  _.arg1v = arg1;
  _.arg2v = arg2;
  _.arg3v = arg3;
  _.arg4v = arg4;
  WARNPRINTF_BM ("warning_objrout_BM stkf@%p, CURFRAM@%p; arg1: %s, arg2: %s,\n"        //
                 "... arg3: %s, arg4: %s,  restargs=%p",        //
                 (void *) stkf, (void *) &_,    //
                 debug_outstr_value_BM (_.arg1v, CURFRAME_BM, 0),       //
                 debug_outstr_value_BM (_.arg2v, CURFRAME_BM, 0),       //
                 debug_outstr_value_BM (_.arg3v, CURFRAME_BM, 0),       //
                 debug_outstr_value_BM (_.arg4v, CURFRAME_BM, 0),       //
                 (void *) restargs);
  fflush (NULL);
  if (backtracestate_BM && pthread_self () == mainthreadid_BM)
    {
      fprintf (stderr, "\n\n\n**warning_objrout_BM full backtrace **\n");
      fflush (stderr);
      backtrace_print_BM ((struct backtrace_state *) backtracestate_BM, 1,
                          stderr);
      fprintf (stderr,
               "\n----- end warning_objrout_BM full backtrace ------\n\n");
      fflush (stderr);
    }
  return NULL;
}                               /* end of warning_objrout_BM */




const char *
get_real_executable_path_BM (void)
{
  return real_executable_BM;
}                               /* end get_real_executable_path_BM */


void
write_pid_into_file_and_kill_old_BM (const char *pidfilepath)
{
  ASSERT_BM (pidfilepath && pidfilepath[0]);
  int oldpid = -1;
  FILE *oldpidfile = fopen (pidfilepath, "r");
  /// if the pidfile starts with a dot or a percent, dont kill the old process
  bool shouldkillold = pidfilepath[0] != '.' && pidfilepath[0] != '%';
  bool killedold = false;
  if (oldpidfile)
    {
      if (fscanf (oldpidfile, "%d", &oldpid) > 0 && oldpid > 0
          && !kill (oldpid, 0))
        {
          char thisexepath[256];
          char oldexepath[256];
          char oldpidpath[64];
          memset (thisexepath, 0, sizeof (thisexepath));
          memset (oldexepath, 0, sizeof (oldexepath));
          memset (oldpidpath, 0, sizeof (oldpidpath));
          snprintf (oldpidpath, sizeof (oldpidpath), "/proc/%d/exe", oldpid);
          /** WARNING: this is not entirely robust, if the
	      old pid happens to terminate or is killed
	      externally ... But we do check that it is
	      running the same executable than the current
	      one... See proc(5) on Linux */
          if (!readlink
              ("/proc/self/exe", thisexepath,
               sizeof (thisexepath) - 1)
              && !readlink (oldpidpath, oldexepath,
                            sizeof (oldexepath) - 1)
              && !strcmp (thisexepath, oldexepath)
              && strlen (thisexepath) < sizeof (thisexepath) - 2
              && shouldkillold)
            {
              INFOPRINTF_BM
                ("quitting old Bismon process of pid %d running this executable %s",
                 oldpid, thisexepath);
              killedold = (0 == kill (oldpid, SIGQUIT));
              if (killedold)
                {
                  INFOPRINTF_BM
                    ("SIGQUIT-ed old Bismon process of pid %d on %s running this executable %s",
                     oldpid, myhostname_BM, thisexepath);
                  fflush (NULL);
                  sleep (1);    /* to let the other Bismon die gracefully */
                }
              else
                WARNPRINTF_BM
                  ("failed to SIGQUIT-ed old Bismon process of pid %d on %s running this executable %s (%m)",
                   oldpid, myhostname_BM, thisexepath);
            }
        }
      fclose (oldpidfile), oldpidfile = NULL;
      char backuppidpath[256];
      memset (backuppidpath, 0, sizeof (backuppidpath));
      if (strlen (pidfilepath) < sizeof (backuppidpath) - 4)
        {
          if (snprintf (backuppidpath, sizeof (backuppidpath),
                        "%s~", pidfilepath) > 0)
            {
              if (!rename (pid_filepath_bm, backuppidpath))
                INFOPRINTF_BM ("backed up pid file path %s -> %s",
                               pid_filepath_bm, backuppidpath);
            };
        }
    }
  if (killedold)                // probably a previous Bismon process is
    // still running
    {
      /* We sleep for one second, to give the old Bismon
         server enough time to dump its state
         properly. This is a bit messy, but could usually be
         helpful. */
      sleep (1);
    };
  FILE *pidfile = fopen (pid_filepath_bm, "w");
  if (!pidfile)
    FATAL_BM ("failed to open pid file %s - %m", pid_filepath_bm);
  fprintf (pidfile, "%d\n", (int) getpid ());
  fprintf (pidfile, "#pid on host %s\n", myhostname_BM);
  fprintf (pidfile, "#git %s\n", bismon_shortgitid);
  fprintf (pidfile, "#built %s\n", bismon_timestamp);
  fflush (pidfile);
  /// On purpose the pid file is kept open.... this ensures that lsof(1)
  /// might be used...

  INFOPRINTF_BM ("wrote pid %d in pid-file %s",
                 (int) getpid (), pid_filepath_bm);
}                               /* end write_pid_into_file_and_kill_old_BM */

void
test_make_empty_sigusr1_dump_dir_BM (void)
{
  char dirbufname[MAXLEN_SIGUSR1_DUMP_PREFIX_BM + 8];
  ASSERT_BM (sigusr1_dump_prefix_BM != (const char *) 0);
  memset (dirbufname, 0, sizeof (dirbufname));
  if (strlen (sigusr1_dump_prefix_BM) >= MAXLEN_SIGUSR1_DUMP_PREFIX_BM)
    FATAL_BM ("too long sigusr1_dump_prefix_BM: %s (more than %d bytes)",
              sigusr1_dump_prefix_BM, MAXLEN_SIGUSR1_DUMP_PREFIX_BM);
  snprintf (dirbufname, sizeof (dirbufname), "%s--0000",
            sigusr1_dump_prefix_BM);
  ASSERT_BM (strlen (dirbufname) < sizeof (dirbufname) - 1);
  if (mkdir (dirbufname, S_IRWXU /* u+rwx */ ))
    FATAL_BM ("failed to mkdir %s - %m", dirbufname);
  INFOPRINTF_BM ("Successfully made empty SIGUSR1 dump directory %s",
                 dirbufname);
}                               /* end test_make_empty_sigusr1_dump_dir_BM */

void
do_actions_after_load_bm (gchar ** actarr)
{
  int nbact = 0;
  char actname[128];
  ASSERT_BM (actarr != NULL);
  for (int aix = 0; actarr[aix] != NULL; aix++)
    {
      void *actptr = NULL;
      memset (actname, 0, sizeof (actname));
      const char *curact = actarr[aix];
      snprintf (actname, sizeof (actname), "bismonaction_%s", curact);
      char *colon = strchr (actname, ':');
      const char *curarg = NULL;
      if (colon)
        {
          curarg = colon + 1;
          *colon = (char) 0;
        };
      if (curarg)
        INFOPRINTF_BM
          ("do_actions_after_load_bm should do action#%d %s on %s", aix,
           curact, curarg);
      else
        INFOPRINTF_BM ("do_actions_after_load_bm should do action#%d %s", aix,
                       curact);
      actptr = dlsym_in_modules_and_program_BM (actname);
      if (!actptr && dlh_before_load_bm)
        actptr = dlsym (dlh_before_load_bm, curact);
      if (!actptr)
        FATAL_BM ("cannot find action routine %s : %s", curact, dlerror ());
      action_after_load_sigt *actrout = (action_after_load_sigt *) actptr;
      (*actrout) (curarg);
      if (curarg)
        INFOPRINTF_BM ("do_actions_after_load_bm did action#%d %s on %s", aix,
                       curact, curarg);
      else
        INFOPRINTF_BM ("do_actions_after_load_bm did action#%d %s", aix,
                       curact);
      nbact++;
    }
  INFOPRINTF_BM ("do_actions_after_load_bm did %d actions\n", nbact);
}                               /* end do_actions_after_load_bm */

/****************
 **                           for Emacs...
 ** Local Variables: ;;
 ** compile-command: "./Build" ;;
 ** End: ;;
 ****************/
/*** end of file main_BM.c ***/
