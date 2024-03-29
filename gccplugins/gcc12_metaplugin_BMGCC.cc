/**
    BISMON related GCC11 metaplugin gcc11_metaplugin_BMGCC.cc
    See https://github.com/bstarynk/bismon/
    Copyright © 2020 - 2022 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
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

#include "gcc11_metaplugin_BMGCC.hh"

//// include generated GTY support by gengtype
//// See e.g. https://gcc.gnu.org/onlinedocs/gccint/Type-Information.html
#include "_gcc11_metaplugin_BMGCC-gty.h"



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
BMP_gimple_pass::clone()
{
  return new BMP_gimple_pass(m_ctxt);
} // end BMP_gimple_pass::clone

bool
BMP_gimple_pass::gate(BMPCC_gcc_function* func)
{
  if (!func)
    return false;
  if (!func->decl)
    return false;
  if (lookup_attribute("bismon_skip",  DECL_ATTRIBUTES (func->decl)))
    return false;
  return true;
} // end BMP_gimple_pass::gate

unsigned int
BMP_gimple_pass::execute(BMPCC_gcc_function* func)
{
  if (!func)
    return 0;
  if (!func->decl)
    return 0;
  basic_block bb;
#warning BMP_gimple_pass::execute should store the func in some "global"
  FOR_EACH_BB_FN (bb, func)
  {
#warning should do something with the bb in BMP_gimple_pass::execute
  };
  return 0;
} // end BMP_gimple_pass::execute


////////////////////////////////////////////////////////////////
//// GTY user support for class BMP_set_of_functions
//// marking routine
void
gt_ggc_mx (BMP_set_of_functions *setfun)
{
  gcc_assert(setfun);
  setfun->check_magic();
  for (BMPCC_gcc_function* f: setfun->set_funptr)
    {
      gcc_assert(f);
      /// the below gt_ggc_mx_function is probably implemented in the generated _gcc11_metaplugin_BMGCC-gty.h file
      gt_ggc_mx_function (f);
    };
} // end gt_ggc_mx (BMP_set_of_functions *setfun)







#warning disabling precompiled header support for BMP_set_of_functions
#if 0 /* NO precompiled header support */
//// FIXME: GTY user support for class BMP_set_of_functions
//// precompiled header marking routine
void
gt_pch_nx (BMP_set_of_functions* setfun)
{
  warning(UNKNOWN_LOCATION, "BISMON GCC11 METAPLUGIN: precompiled header marking gt_pch_nx for BMP_set_of_functions probably wrong");
#warning precompiled header marking gt_pch_nx for BMP_set_of_functions probably wrong
  gcc_assert(setfun);
  setfun->check_magic();
  for (BMPCC_gcc_function* f: setfun->set_funptr)
    {
      gcc_assert(f);
      gt_pch_nx (f);
    };
} // end gt_pch_nx (BMP_set_of_functions* setfun)

//// FIXME: GTY user support for class BMP_set_of_functions
//// precompiled header pointer walker routine
void
gt_pch_nx(BMP_set_of_functions* setfun, gt_pointer_operator op, void*cookie)
{
  warning(UNKNOWN_LOCATION, "BISMON GCC11 METAPLUGIN: precompiled header walker gt_pch_nx for BMP_set_of_functions probably wrong");
#warning gt_pch_nx precompiled header walker for BMP_set_of_functions probably wrong
  for (BMPCC_gcc_function* f: setfun->set_funptr)
    {
      op(f, cookie);
    }
} // end gt_pch_nx(BMP_set_of_functions* setfun, gt_pointer_operator op, void*cookie)
#endif /*NO precompiled header support */





////////////////////////////////////////////////////////////////
///// the plugin_init name is dlsym-ed by GCC.
int
plugin_init (struct plugin_name_args *plugin_info,
             struct plugin_gcc_version *version)
{
  const char *plugin_name = plugin_info->base_name;
#ifdef PLUGINGITID
  plugin_info->version = PLUGINGITID "@" __DATE__ "/" __TIME__;
#endif /*PLUGINGITID*/
  plugin_info->help = __FILE__ " for Bismon - see starynkevitch.net/Basile/bismon-doc.pdf";
  /// the base version should be compatible
  if (strcmp(version->basever, gcc_version.basever))
    {
      error("BISMON GCC11 METAPLUGIN: fail version check for %s: different base version %s vs %s",
            plugin_name, version->basever, gcc_version.basever);
      return 1;
    }
  else
    inform(UNKNOWN_LOCATION,
           "BISMON GCC11 METAPLUGIN: plugin %s"
           " (built " __DATE__ " on " __TIME__")"
           " for GCC version %s", plugin_name, version->basever);
  /// other version information are tested and reported. In some
  /// cases, that might work.
  if (strcmp(version->datestamp, gcc_version.datestamp))
    warning(UNKNOWN_LOCATION, "BISMON GCC11 METAPLUGIN: datestamp difference for %s:\n"
            " plugin has %s, GCC had %s; this is risky.",
            plugin_name, version->datestamp, gcc_version.datestamp);
  if (strcmp(version->devphase, gcc_version.devphase))
    warning(UNKNOWN_LOCATION, "BISMON GCC11 METAPLUGIN: devphase difference for %s:\n"
            " plugin has %s, GCC had %s; this is risky.",
            plugin_name, version->devphase, gcc_version.devphase);
  if (strcmp(version->configuration_arguments,
             gcc_version.configuration_arguments))
    warning(UNKNOWN_LOCATION, "BISMON GCC11 METAPLUGIN: configuration difference for %s:\n"
            " plugin has %s, GCC had %s; this is risky.",
            plugin_name,
            version->configuration_arguments,
            gcc_version.configuration_arguments);


  curlpp::initialize (CURL_GLOBAL_ALL);

  ///
  inform(UNKNOWN_LOCATION, "started Bismon GCC11 metaplugin built " __DATE__ " on " __TIME__ " process %d for main input %s"
#ifdef PLUGINGITID
         " (gitid " PLUGINGITID ")"
#else
         " without PLUGINGITID"
#endif
         " (%s:%d)",
         (int) getpid(),
         main_input_filename,
         __FILE__, __LINE__);


  return 0;
} // end plugin_init


typedef void plugin_arghandler_sig(const char*);
struct pluginarg_handler_BMPCC
{
  const char*parg_name;
  plugin_arghandler_sig* parg_handler;
  const char*parg_help;
};

std::string bismon_url_prefix_BMPCC;
std::string bismon_project_BMPCC;
std::string bismon_cookie_file_BMPCC;
std::string bismon_line_prefix_BMPCC;

static void handle_bismon_url_arg_BMPCC(const char*);
static void handle_bismon_project_arg_BMPCC(const char*);
static void handle_bismon_cookie_file_BMPCC(const char*);
static void handle_bismon_pid_BMPCC(const char*);
static void handle_bismon_line_prefix_BMPCC(const char*);

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
  /// bismon-pid= <some-pid> # e.g. bismon-pid=1234
  {
    .parg_name="bismon-pid",
    .parg_handler= handle_bismon_pid_BMPCC,
    .parg_help="gives the pid of the process running Bismon"
  },
  /// bismon-line-prefix= <some-string> # e.g. bismon-line-prefix=ANALYZED_LINE
  {
    .parg_name="bismon-line-prefix",
    .parg_handler= handle_bismon_line_prefix_BMPCC,
    .parg_help="if given as some string prefix, display it for PLUGIN_INCLUDE_FILE events of GCC"
  },
  ///
  { .parg_name=nullptr, .parg_handler=nullptr, .parg_help=nullptr }
};

void
handle_bismon_url_arg_BMPCC(const char*argval)
{
  if (!bismon_url_prefix_BMPCC.empty() && argval)
    {
      error("bismon-url plugin argument given twice: %s and %s",
            bismon_url_prefix_BMPCC.c_str(), argval);
    }
  if (argval)
    bismon_url_prefix_BMPCC.assign(argval);
} // end handle_bismon_url_arg_BMPCC

void
handle_bismon_pid_BMPCC(const char*argval)
{
  if (bismon_pid_BMPCC > 0 && argval)
    {
      error("bismon-pid plugin argument given twice: %d and %s",
            (int) bismon_pid_BMPCC, argval);
    }
  if (argval)
    {
      int pi = atoi(argval);
      if (pi>1)
        {
          if (kill((pid_t)pi, 0))
            error("bismon-pid plugin argument %d is not running (%s)", pi, xstrerror(errno));
          bismon_pid_BMPCC = pi;
        }
      else
        error("invalid bismon-pid plugin argument: %s", argval);
    };
} // end handle_bismon_pid_BMPCC

void
handle_bismon_project_arg_BMPCC(const char*argval)
{
  if (!bismon_project_BMPCC.empty() && argval)
    {
      error("bismon-project plugin argument given twice: %s and %s",
            bismon_project_BMPCC.c_str(), argval);
    }
  if (argval)
    bismon_project_BMPCC.assign(argval);
} // end handle_bismon_project_arg_BMPCC

void
handle_bismon_cookie_file_BMPCC(const char*argval)
{
  if (!bismon_cookie_file_BMPCC.empty() && argval)
    {
      error("bismon-cookie-file plugin argument given twice: %s and %s",
            bismon_cookie_file_BMPCC.c_str(), argval);
    }
  if (argval)
    bismon_cookie_file_BMPCC.assign(argval);
} // end handle_bismon_cookie_file_BMPCC

void
handle_bismon_line_prefix_BMPCC(const char*argval)
{
  if (!bismon_line_prefix_BMPCC.empty() && argval)
    {
      error("bismon-line-prefix plugin argument given twice: %s and %s",
            bismon_line_prefix_BMPCC.c_str(), argval);
    }
  if (argval)
    bismon_line_prefix_BMPCC.assign(argval);
} // end handle_bismon_line_prefix_BMPCC

static
void show_help_BMGCC(const char*plugin_name)
{
  std::cout << "Bismon metaplugin arguments to be passed with -fplugin-arg-" << plugin_name << "; e.g. this help given by  -fplugin-arg-" << plugin_name << "-help" << std::endl;
  for (int aix=0;
       aix < (int) (sizeof(pluginargsarr_BMPCC)/sizeof(pluginargsarr_BMPCC[0]));
       aix++)
    {
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
           "Bismon GCC11 metaplugin "
#ifdef PLUGINGITID
           " (gitid " PLUGINGITID ")"
#endif
           " built " __DATE__
           " with JsonCPP " JSONCPP_VERSION_STRING);
  assert (plugin_args->version == nullptr);
  plugin_args->version = versbuf;
  static char thishostname[80];
  memset (thishostname, 0, sizeof(thishostname));
  gethostname(thishostname, sizeof(thishostname)-1);
  int argix=0;
  int cntarg = 0;
  for (struct plugin_argument* plcurarg = plugin_args->argv;
       (argix<plargc)?(plcurarg = plugin_args->argv+argix):nullptr; argix++)
    {
      const char*curkey = plcurarg->key;
      const char*curval = plcurarg->value;
      if (!strcmp(curkey, "help"))
        show_help_BMGCC(plugin_name);
      else
        {
          for (int paix=0;
               paix<(int) (sizeof(pluginargsarr_BMPCC)/sizeof(pluginargsarr_BMPCC[0]));
               paix++)
            {
              const pluginarg_handler_BMPCC* curpa = pluginargsarr_BMPCC+paix;
              if (!curpa->parg_name)
                break;
              if (strcmp(curkey, curpa->parg_name))
                continue;
              if (curpa->parg_handler)
                {
                  cntarg ++;
                  (*(curpa->parg_handler))(curval);
                }
            }
        }
    };
  /// show an informational message
  {
    if (bismon_pid_BMPCC>0)
      inform(UNKNOWN_LOCATION, "Bismon plugin %s (%s:%d) with Bismon pid %d (recognized %d plugin arguments)",
             plugin_name, __FILE__, __LINE__, (int)bismon_pid_BMPCC, cntarg);
  }
  /// register some GCC plugin events
  {
    register_callback (plugin_name, PLUGIN_START_UNIT, BMP_start_unit_handler, NULL);
    register_callback (plugin_name, PLUGIN_ALL_PASSES_END, BMP_all_passes_end_handler, NULL);
    register_callback (plugin_name, PLUGIN_FINISH, BMP_finish_handler, NULL);
    if (!bismon_line_prefix_BMPCC.empty())
      {
        register_callback (plugin_name, PLUGIN_INCLUDE_FILE, BMP_include_file_handler,
                           (void*)(bismon_line_prefix_BMPCC.c_str()));
        inform (UNKNOWN_LOCATION, "Bismon plugin %s  (%s:%d) will handle GCC include-file events with prefix %s",
                plugin_name,  __FILE__, __LINE__, bismon_line_prefix_BMPCC.c_str());
      }
#warning we probably need some PLUGIN_PASS_MANAGER_SETUP & PLUGIN_START_PARSE_FUNCTION event...
    /****
     * TODO: document more events
     ****/
  }
  inform(UNKNOWN_LOCATION,
         "Bismon plugin %s initialized (%s:%d) - version %s pid %d on %s",
         plugin_name, __FILE__, __LINE__,
         versbuf, (int)getpid(), thishostname);
} // end parse_plugin_arguments

void
BMP_start_unit_handler(void*gccdata,void*userdata)
{
#warning BMP_start_unit_handler is uncomplete
  assert(userdata == nullptr);
  ///
  inform(UNKNOWN_LOCATION, "Bismon GCC11 metaplugin start unit handler for main input %s",
         main_input_filename);

  /**NOTICE: GCC warning wants a %qs *****/
  //   warning(UNKNOWN_LOCATION, "incomplete handling of `Plugin_Start_Unit' event in %s:%d", __FILE__, __LINE__);
  warning(UNKNOWN_LOCATION, "incomplete handling of %qs event in %s:%d (%s)",
          "Plugin_Start_Unit", __FILE__, __LINE__,
          __FUNCTION__);
  /// we explicitly need some Bismon URL
  if (bismon_url_prefix_BMPCC.empty())
    fatal_error(UNKNOWN_LOCATION, "no given bismon url prefix in %s:%d (%s)",
                __FILE__, __LINE__, __FUNCTION__);
  /****
   * TODO: code some curlpp request to Bismon
   ****/
} // end  BMP_start_unit_handler


void
BMP_all_passes_end_handler(void*gccdata,void*userdata)
{
#warning BMP_all_passes_end_handler is uncomplete
  assert(userdata == nullptr);
  inform(UNKNOWN_LOCATION, "Bismon GCC11 metaplugin all passes end handler for main input %s",
         main_input_filename);
  /**NOTICE: GCC warning wants a %qs *****/
  //   warning(UNKNOWN_LOCATION, "incomplete handling of `Plugin_Start_Unit' event in %s:%d", __FILE__, __LINE__);
  warning(UNKNOWN_LOCATION, "incomplete handling of %qs event in %s:%d (%s)",
          "Plugin_All_Passes_End", __FILE__, __LINE__,
          __FUNCTION__);
  /// we explicitly need some Bismon URL
  if (bismon_url_prefix_BMPCC.empty())
    fatal_error(UNKNOWN_LOCATION, "no given bismon url prefix in %s:%d (%s)",
                __FILE__, __LINE__, __FUNCTION__);
  /****
   * TODO: code some curlpp request to Bismon
   ****/
  usleep(1000);
} // end  BMP_all_passes_end_handler


void
BMP_finish_handler(void*gccdata,void*userdata)
{
#warning BMP_finish_handler is uncomplete
  assert(userdata == nullptr);
  inform(UNKNOWN_LOCATION, "Bismon GCC11 metaplugin finish handler for main input %s",
         main_input_filename);
} // end  BMP_finish_handler


void
BMP_include_file_handler(void*gccdata,void*userdata)
{
#warning BMP_include_file_handler_handler is uncomplete
  assert(userdata != nullptr); /// the prefix
  const char*prefix = reinterpret_cast<const char*>(userdata);
  assert(gccdata != nullptr);
  const char*gccfilepath = reinterpret_cast<const char*>(gccdata);
  inform (UNKNOWN_LOCATION, "Bismon GCC11 metaplugin include handler prefix %s filepath %qs",
          prefix, gccfilepath);
} // end of BMP_include_file_handler

void
BMP_post_jsoncurl::do_post()
{
#warning BMP_post_jsoncurl::do_post is incomplete
  std::ostringstream os;
  os <<  this->pjs_jsonval << std::flush;
  warning (UNKNOWN_LOCATION, "Bismon GCC11 metaplugin unimplemented %s with %s",
           __func__,
           os.str().c_str());
} // end BMP_post_jsoncurl::do_post

/****************
 **                           for Emacs...
 ** Local Variables: ;;
 ** compile-command: "./build-gcc11-metaplugin.sh" ;;
 ** End: ;;
 ****************/
////// end of file bismon/gccplugins/gcc11_metaplugin_BMGCC.cc
