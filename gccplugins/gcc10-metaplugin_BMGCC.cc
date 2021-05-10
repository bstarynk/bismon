
/**
    BISMON related GCC10 metaplugin gcc10-metaplugin_BMGCC.cc
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

#include "gcc10-metaplugin.hh"

int plugin_is_GPL_compatible;


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
#endif
         " (l@%d)",
         (int) getpid(), __LINE__);

  
  return 0;
} // end plugin_init


typedef void plugin_arghandler_sig(const char*);
struct pluginarg_handler_BMCC {
  const char*parg_name;
  plugin_arghandler_sig* parg_handler;
  const char*parg_help;
};

std::string bismon_url_prefix_BMCC;
std::string bismon_project_BMCC;

static void handle_bismon_url_arg_BMCC(const char*);
static void handle_bismon_project_arg_BMCC(const char*);

const pluginarg_handler_BMCC
pluginargsarr_BMCC[] =
  {
   /// bismon-url= <some-url> # e.g. bismon-url=http://localhost:8088/
   {
    .parg_name="bismon-url",
    .parg_handler= handle_bismon_url_arg_BMCC,
    .parg_help="gives the URL prefix to contact the Bismon server"
   },
   /// bismon-url= <some-url> # e.g. bismon-url=http://localhost:8088/
   {
    .parg_name="bismon-project",
    .parg_handler= handle_bismon_project_arg_BMCC,
    .parg_help="gives the mandatory project name - should be the same for every translation unit"
   },
   ///
   { .parg_name=nullptr, .parg_handler=nullptr, .parg_help=nullptr }
  };

void
handle_bismon_url_arg_BMCC(const char*argval) {
  if (argval)
    bismon_url_prefix_BMCC.assign(argval);
} // end handle_bismon_url_arg_BMCC

void
handle_bismon_project_arg_BMCC(const char*argval) {
  if (argval)
    bismon_project_BMCC.assign(argval);
}

static
void show_help_BMGCC(const char*plugin_name)
{
  std::cout << "Bismon metaplugin arguments to be passed with -fplugin-arg-" << plugin_name << "; e.g. this help given by  -fplugin-arg-" << plugin_name << "-help" << std::endl;
  for (int aix=0; aix < sizeof(pluginargsarr_BMCC)/sizeof(pluginargsarr_BMCC[0]); aix++) {
    if (pluginargsarr_BMCC[aix].parg_name == nullptr)
      break;
    if (pluginargsarr_BMCC[aix].parg_name != nullptr
	&& pluginargsarr_BMCC[aix].parg_handler
	&& pluginargsarr_BMCC[aix].parg_help)
      std::cout << "\t" << pluginargsarr_BMCC[aix].parg_name << ":" << pluginargsarr_BMCC[aix].parg_help << std::endl;
  }
} // end show_help_BMGCC

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
      }
    };
} // end parse_plugin_arguments

/****************
 **                           for Emacs...
 ** Local Variables: ;;
 ** compile-command: "./build-gcc10-metaplugin.sh" ;;
 ** End: ;;
 ****************/
////// end of file bismon/gccplugins/gcc10-metaplugin_BMGCC.cc
