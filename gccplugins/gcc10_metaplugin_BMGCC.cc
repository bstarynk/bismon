
/**
    BISMON related GCC10 metaplugin gcc10_metaplugin_BMGCC.cc
    See https://github.com/bstarynk/bismon/
    Copyright © 2020 - 2021 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
    contributed by Basile Starynkevitch and Franck Védrine

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

**/


//// the conventional prefix or suffix in names is BMP - for BisMon Plugin

#include "gcc10_metaplugin_BMGCC.hh"

int plugin_is_GPL_compatible;

pid_t bismon_pid_BMPCC;

const pass_data BMP_gimple_pass_data =
{
  GIMPLE_PASS, /* type */
  "BMP_gimple_pass", /* name */
  OPTGROUP_NONE, /* optinfo_flags */
  TV_NONE, /* tv_id */
  ( PROP_ssa | PROP_cfg | PROP_gimple_leh ), /* properties_required */
  0, /* properties_provided */
  0, /* properties_destroyed */
  0, /* todo_flags_start */
  0, /* todo_flags_finish */
};    // end BMP_gimple_pass_data


opt_pass*
BMP_gimple_pass::clone() {
  return new BMP_gimple_pass(m_ctxt);
} // end BMP_gimple_pass::clone

bool
BMP_gimple_pass::gate(function* func) {
  if (!func)
    return false;
  if (!func->decl)
    return false;
  if (lookup_attribute("bismon_skip",  DECL_ATTRIBUTES (func->decl)))
    return false;
  return true;
} // end BMP_gimple_pass::gate

unsigned int
BMP_gimple_pass::execute(function* func) {
  if (!func)
    return 0;
  if (!func->decl)
    return 0;
  basic_block bb;
#warning BMP_gimple_pass::execute should store the func in some "global"
  FOR_EACH_BB_FN (bb, func) {
#warning should do something with the bb in BMP_gimple_pass::execute
  };
  return 0;
} // end BMP_gimple_pass::execute


////////////////////////////////////////////////////////////////
//// Gty user support for class BMP_set_of_functions
void
gt_ggc_mx (BMP_set_of_functions *setfun)
{
  gcc_assert(setfun);
  setfun->check_magic();
  for (function* f: setfun->set_funptr) {
    gcc_assert(f);
    gt_ggc_mx(*f);
  };
} // end gt_ggc_mx (BMP_set_of_functions *setfun)

////////////////////////////////////////////////////////////////
///// the plugin_init name is dlsym-ed by GCC.
int
plugin_init (struct plugin_name_args *plugin_info,
             struct plugin_gcc_version *version)
{
  const char *plugin_name = plugin_info->base_name;
  if (!plugin_default_version_check (version, &gcc_version))
  {
    warning(UNKNOWN_LOCATION, "BISMON GCC10 METAPLUGIN: fail version check for %s:"
            " got %s/%s/%s/%s wanted %s/%s/%s/%s", plugin_name,
            version->basever, version->datestamp, version->devphase, version->revision,
            gcc_version.basever, gcc_version.datestamp, gcc_version.devphase, gcc_version.revision);
    return 1;
  }

  ///
  inform(UNKNOWN_LOCATION, "Bismon GCC10 metaplugin built " __DATE__ " on " __TIME__ " process %d"
#ifdef PLUGINGITID
         " (gitid " PLUGINGITID ")"
#else
	 " without PLUGINGITID"
#endif
         " (%s:%d)",
         (int) getpid(), __FILE__, __LINE__);


  return 0;
} // end plugin_init


typedef void plugin_arghandler_sig(const char*);
struct pluginarg_handler_BMPCC {
  const char*parg_name;
  plugin_arghandler_sig* parg_handler;
  const char*parg_help;
};

std::string bismon_url_prefix_BMPCC;
std::string bismon_project_BMPCC;
std::string bismon_cookie_file_BMPCC;

static void handle_bismon_url_arg_BMPCC(const char*);
static void handle_bismon_project_arg_BMPCC(const char*);
static void handle_bismon_cookie_file_BMPCC(const char*);
static void handle_bismon_pid_BMPCC(const char*);

const pluginarg_handler_BMPCC
pluginargsarr_BMPCC[] =
{
  /// bismon-url= <some-url> # e.g. bismon-url=http://localhost:8088/
  {
    .parg_name="bismon-url",
    .parg_handler= handle_bismon_url_arg_BMPCC,
    .parg_help="gives the URL prefix to contact the Bismon server"
  },
  /// bismon-project= <some-name> # e.g. bismon-project=Your_Project01
  {
    .parg_name="bismon-project",
    .parg_handler= handle_bismon_project_arg_BMPCC,
    .parg_help="gives the mandatory project name - should be the same for every translation unit (i.e. *.c or *.cc file)"
  },
  /// bismon-cookie-file= <some-path> # e.g. bismon-cookie-file=/tmp/bismoncookie
  {
    .parg_name="bismon-cookie-file",
    .parg_handler= handle_bismon_cookie_file_BMPCC,
    .parg_help="gives some HTTP cookie file written by Bismon"
  },
  /// bismon-pid= <some-pid> # e.g. bismon-cookie-file=/tmp/bismoncookie
  {
    .parg_name="bismon-pid",
    .parg_handler= handle_bismon_pid_BMPCC,
    .parg_help="gives the pid of the process running Bismon"
  },
  ///
  { .parg_name=nullptr, .parg_handler=nullptr, .parg_help=nullptr }
};

void
handle_bismon_url_arg_BMPCC(const char*argval) {
  if (!bismon_url_prefix_BMPCC.empty() && argval) {
    error("bismon-url plugin argument given twice: %qs and %qs",
          bismon_url_prefix_BMPCC.c_str(), argval);
  }
  if (argval)
    bismon_url_prefix_BMPCC.assign(argval);
} // end handle_bismon_url_arg_BMPCC

void
handle_bismon_pid_BMPCC(const char*argval) {
  if (bismon_pid_BMPCC > 0 && argval) {
    error("bismon-pid plugin argument given twice: %d and %s",
          (int) bismon_pid_BMPCC, argval);
  }
  if (argval) {
    int pi = atoi(argval);
    if (pi>1) {
      if (kill((pid_t)pi, 0))
	error("bismon-pid plugin argument %d is not running (%s)", pi, xstrerror(errno));
      bismon_pid_BMPCC = pi;
    }
    else
      error("invalid bismon-pid plugin argument: %qs", argval);
  };
} // end handle_bismon_pid_BMPCC

void
handle_bismon_project_arg_BMPCC(const char*argval) {
  if (!bismon_project_BMPCC.empty() && argval) {
    error("bismon-project plugin argument given twice: %qs and %qs",
          bismon_project_BMPCC.c_str(), argval);
  }
  if (argval)
    bismon_project_BMPCC.assign(argval);
} // end handle_bismon_project_arg_BMPCC

void
handle_bismon_cookie_file_BMPCC(const char*argval) {
  if (!bismon_cookie_file_BMPCC.empty() && argval) {
    error("bismon-cookie-file plugin argument given twice: %qs and %qs",
          bismon_cookie_file_BMPCC.c_str(), argval);
  }
  if (argval)
    bismon_cookie_file_BMPCC.assign(argval);
} // end handle_bismon_cookie_file_BMPCC

static
void show_help_BMGCC(const char*plugin_name)
{
  std::cout << "Bismon metaplugin arguments to be passed with -fplugin-arg-" << plugin_name << "; e.g. this help given by  -fplugin-arg-" << plugin_name << "-help" << std::endl;
  for (int aix=0;
       aix < (int) (sizeof(pluginargsarr_BMPCC)/sizeof(pluginargsarr_BMPCC[0]));
       aix++) {
    if (pluginargsarr_BMPCC[aix].parg_name == nullptr)
      break;
    if (pluginargsarr_BMPCC[aix].parg_name != nullptr
        && pluginargsarr_BMPCC[aix].parg_handler
        && pluginargsarr_BMPCC[aix].parg_help)
      std::cout << "\t" << pluginargsarr_BMPCC[aix].parg_name << ":" << pluginargsarr_BMPCC[aix].parg_help << std::endl;
  }
} // end show_help_BMGCC


// the name parse_plugin_arguments is dlsym-ed by GCC!
void
parse_plugin_arguments(const char*plugin_name, struct plugin_name_args*plugin_args)
{
  int plargc = plugin_args->argc;
  static char versbuf[256];
  snprintf(versbuf, sizeof(versbuf),
           "Bismon GCC10 metaplugin "
#ifdef PLUGINGITID
           " (gitid " PLUGINGITID ")"
#endif
           " built " __DATE__
           " with JsonCPP " JSONCPP_VERSION_STRING);
  assert (plugin_args->version == nullptr);
  plugin_args->version = versbuf;
  int argix=0;
  for (struct plugin_argument* plcurarg = plugin_args->argv;
       (argix<plargc)?(plcurarg = plugin_args->argv+argix):nullptr; argix++)
  {
    const char*curkey = plcurarg->key;
    const char*curval = plcurarg->value;
    if (!strcmp(curkey, "help"))
      show_help_BMGCC(plugin_name);
    else {
      for (int paix=0;
           paix<(int) (sizeof(pluginargsarr_BMPCC)/sizeof(pluginargsarr_BMPCC[0]));
           paix++) {
        const pluginarg_handler_BMPCC* curpa = pluginargsarr_BMPCC+paix;
        if (!curpa->parg_name)
          break;
        if (strcmp(curkey, curpa->parg_name))
          continue;
        if (curpa->parg_handler) {
          (*(curpa->parg_handler))(curval);
        }
      }
    }
  };
  /// show an informational message
  {
    char thishostname[80];
    memset (thishostname, 0, sizeof(thishostname));
    gethostname(thishostname, sizeof(thishostname)-1);
    if (bismon_pid_BMPCC>0)
      inform(UNKNOWN_LOCATION, "Bismon plugin %qs (%s:%d) with Bismon pid %d",
	     plugin_name, __FILE__, __LINE__, (int)bismon_pid_BMPCC);
    inform(UNKNOWN_LOCATION,
	   "Bismon plugin %qs initialized (%s:%d) - version %qs pid %d on %s",
	   plugin_name, __FILE__, __LINE__,
	   versbuf, (int)getpid(), thishostname);
  }
  /// register some GCC plugin events
  {
    register_callback (plugin_name, PLUGIN_START_UNIT, BMP_start_unit_handler, NULL);
#warning we probably need some PLUGIN_PASS_MANAGER_SETUP & PLUGIN_START_PARSE_FUNCTION event...
    /****
     * TODO: document more events
     ****/
  }
} // end parse_plugin_arguments

 void
 BMP_start_unit_handler(void*gccdata,void*userdata)
 {
#warning BMP_start_unit_handler is uncomplete
   assert(userdata == nullptr);
   warning(UNKNOWN_LOCATION, "incomplete handling of °Plugin_Start_Unit event in %s:%d", __FILE__, __LINE__);
   /****
    * TODO: code some curlpp request to Bismon
    ****/
 } // end  BMP_start_unit_handler


/****************
 **                           for Emacs...
 ** Local Variables: ;;
 ** compile-command: "./build-gcc10-metaplugin.sh" ;;
 ** End: ;;
 ****************/
////// end of file bismon/gccplugins/gcc10_metaplugin_BMGCC.cc
