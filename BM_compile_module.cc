// file BM_compile_module.cc on https://github.com/bstarynk/bismon/
// SPDX-License-Identifier: GPL-3.0-or-later

/***
    BISMON
    Copyright © 2020 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
    contributed by Basile Starynkevitch (working at CEA, LIST, France)
    <basile@starynkevitch.net> or <basile.starynkevitch@cea.fr>

    BM_compile_module: a standalone program to compile a BISMON
    generated module or GCC plugin. This file BM_compile_module.cc is
    the main file.

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

#include "BM_compmod.hh"

static char*bmc_module_idstr;
static char*bmc_tempmodule_idstr;
static char*bmc_plugin_idstr;


std::vector<std::string> bmc_guile_vec;
std::map<std::string,std::string> bmc_param_map;

/*******************
 * In commit 49345835c49e747dd6 a generated Bismon module is compiled thru the following Makefile rule:
 *
 *     modubin/modbm_%.so: modules/modbm_%.c $(BISMONHEADERS) | _cflagsmodule.mk
 *        ( [ -f "$(wildcard modules/modbm_%.env)" ] &&  source "$(wildcard modules/modbm_%.env)" ) ; \
 *        $(CCACHE) $(LINK.c) -fPIC  $$$$BISMONMODULE_%_FLAGS $(BISMONMODULECFLAGS) \
 *              -DBISMON_MODID=$(patsubst modules/modbm_%.c,_%,$<)  \
 *              -DBISMON_MOMD5='"$(shell md5sum $< | cut '-d ' -f1)"' \
 *              -DBISMON_PERSISTENT_MODULE -shared $< -o $@
 *
 *
 * We want to use just:
 *     modubin/modbm_%.so: modules/modbm_%.c $(BISMONHEADERS) | BM_compile_module
 *        ./BM_compile_module --module % --in $$PWD
 * In commit 49345835c49e747dd6 a generated Bismon temporary module is compiled thru the following Makefile rule:
 *
 *  modubin/tmpmobm_%.so: modules/tmpmobm_%.c $(BISMONHEADERS) | _cflagsmodule.mk
 *  	( [ -f "$(wildcard modules/tmpmobm_%.env)" ] &&  source "$(wildcard modules/tmpmobm_%.env)" ) ; \
 *  	$(CCACHE) $(LINK.c) -fPIC  $$$$BISMONTEMPMODULE_%_FLAGS $(BISMONMODULECFLAGS) \
 *  	     -DBISMON_MODID=$(patsubst modules/tmpmobm_%.c,_%,$<) \
 *  	     -DBISMON_MOMD5='"$(shell md5sum $< | cut '-d ' -f1)"' -DBISMON_TEMPORARY_MODULE \
 *  	     -shared $< -o $@
 *  #
 * We want to use just:
 *     modubin/modbm_%.so: modules/modbm_%.c $(BISMONHEADERS) | BM_compile_module
 *        ./BM_compile_module --tempmodule % --in $$PWD
 *******************/



enum bmc_longopt_en
{
  BMCOPT__longoptstart=1024,
  BMCOPT_module,
  BMCOPT_tempmodule,
  BMCOPT_plugin,
  BMCOPT_in,
  BMCOPT_oid,
  BMCOPT_guile,
};


bool bmc_debug_flag;

// typical usage could be BMC_DEBUG("something bad x=" << x)
#define BMC_DEBUG_AT_BIS(Fil,Lin,...) do {			\
  if (bmc_debug_flag) {						\
    std::clog << "¿" /* U+00BF INVERTED QUESTION MARK */	\
	      << (Fil) << ":" << Lin << ":: "			\
	      << __VA_ARGS__ << std::endl; } } while(0)

#define BMC_DEBUG_AT(Fil,Lin,...) BMC_DEBUG_AT_BIS(Fil,Lin,##__VA_ARGS__)

// typical usage would be BMC_DEBUG("annoying x=" << x)
#define BMC_DEBUG(...) BMC_DEBUG_AT(__FILE__,__LINE__,##__VA_ARGS__)


static const struct option
  bmc_long_options[] =
{
  {"version",     no_argument,        0, 'V'},
  {"help",        no_argument,        0, 'h'},
  {"debug",        no_argument,        0, 'D'},
  {"param",        required_argument,        0, 'P'},
  {"module",      required_argument,  0, BMCOPT_module},
  {"tempmodule",  required_argument,  0, BMCOPT_tempmodule},
  {"plugin",      required_argument,  0, BMCOPT_plugin},
  {"in",      required_argument,  0, BMCOPT_in},
  {"oid",      required_argument,  0, BMCOPT_oid},
  {"guile",      required_argument,  0, BMCOPT_guile},
  {0,0,0,0}
};

void
bmc_parse_options(int& argc, char**argv)
{
  bmc_guile_vec.reserve(3+argc/2);
  for (;;)
    {
      int optix= -1;
      int optres = getopt_long(argc, argv, "Vh", bmc_long_options, &optix);
      if (optres < 0)
        break;
      switch (optres)
        {
        case 'h': // --help
          bmc_show_usage(argv[0]);
          exit(EXIT_SUCCESS);
          break;
        case 'V': // --version
          bmc_show_version(argv[0]);
          exit(EXIT_SUCCESS);
          break;
        case 'D': // --debug
          bmc_debug_flag = true;
          break;
        case 'P': // parameter <param-name>:<param-value>
        {
          char paramname[64];
          memset (paramname, 0, sizeof(paramname));
          char*paramvalue = nullptr;
          int parampos = -1;
          if (sscanf(optarg, "%60[A-Za-z0-9_]=%n", paramname, &parampos) < 1 || parampos <2)
            {
              std::cerr << argv[0] << " needs a parameter, e.g. --param FOO=bar or -Pfoo=bar" << std::endl;
              exit(EXIT_FAILURE);
            }
          if (parampos>0)
            paramvalue = optarg+parampos;
          std::string paramstrname{paramname};
          if (bmc_param_map.find(paramstrname) != bmc_param_map.end())
            {
              std::cerr << argv[0] << " has parameter " << paramstrname << " given more than once." << std::endl;
              exit(EXIT_FAILURE);
            };
          if (!paramvalue)
            {
              std::cerr <<  argv[0] << " has parameter " << paramstrname << " without value." << std::endl;
              exit(EXIT_FAILURE);
            };
          bmc_param_map.insert({paramstrname, std::string(paramvalue)});
        }
        break;
        case BMCOPT_module:
          if (bmc_module_idstr)
            {
              std::cerr << argv[0] << " duplicate --module " << bmc_module_idstr << " and " << optarg << std::endl;
              exit(EXIT_FAILURE);
            };
          bmc_module_idstr = optarg;
          break;
        case BMCOPT_tempmodule:
          if (bmc_tempmodule_idstr)
            {
              std::cerr << argv[0] << " duplicate --tempmodule " << bmc_tempmodule_idstr << " and " << optarg << std::endl;
              exit(EXIT_FAILURE);
            };
          bmc_tempmodule_idstr = optarg;
          break;
        case BMCOPT_plugin:
          if (bmc_plugin_idstr)
            {
              std::cerr << argv[0] << " duplicate --plugin " << bmc_plugin_idstr << " and " << optarg << std::endl;
              exit(EXIT_FAILURE);
            };
          bmc_plugin_idstr = optarg;
          break;
        case BMCOPT_guile:
          if (!optarg)
            {
              std::cerr  << argv[0] << " with --guile but no path" << std::endl;
              exit(EXIT_FAILURE);
            };
          if (access(optarg, R_OK))
            {
              std::cerr << argv[0] << " fails to access GUILE script " << optarg << ":" << strerror(errno) << std::endl;
              exit(EXIT_FAILURE);
            }
          bmc_guile_vec.push_back(std::string(optarg));
          break;
        }
    }
} // end of bmc_parse_options

void
bmc_show_usage(const char*progname)
{
  std::cerr << progname << " usage:" << std::endl;
  std::cerr << " --version | -V # give version information" << std::endl;
  std::cerr << " --help | -h # give help message" << std::endl;
  std::cerr << " --in <directory> # set the source directory" << std::endl;
  std::cerr << " --module <binary-module-dir> # compile and build a persistent module (*.so)" << std::endl;
  std::cerr << " --tempmodule <temporary-module-dir> # compile and build a temporary module (*.so)" << std::endl;
  std::cerr << " --plugin <gcc-plugin-dir> # compile and build a GCC plugin (*.so)" << std::endl;
  std::cerr << " --oid <object-id> # for the given Bismon id" << std::endl;
  std::cerr << " --param | -P <param-name>=<param-value> # set additional parameter name; <param-name> should be C-like and less than 60 bytes" << std::endl;
  std::cerr << " --guile <guile> # a script for GNU guile, see https://www.gnu.org/software/guile/" << std::endl;
  std::cerr << "    If <guile> starts with a dot, evaluate string after dot, otherwise it is a file path to be loaded." << std::endl;
  std::cerr << "    Several GUILE scripts or expressions could be given." << std::endl;
  std::cerr << "    Pass --guile '.(bmc:help)' to get help about our primitives." << std::endl;
  std::cerr << "# See also https://github.com/bstarynk/bismon" << std::endl;
  std::cerr << "# Funded by https://www.chariotproject.eu/ https://www.decoder-project.eu/" << std::endl;
  std::cerr << "# this is GPLv3+ licensed software, see https://www.gnu.org/licenses/gpl-3.0.en.html ** NO WARRANTY" << std::endl;
} // end bmc_show_usage


void
bmc_show_version(const char*progname)
{
  std::cerr << progname << " version information:" << std::endl;
  std::cerr << " source file: " << __FILE__ << std::endl;
  std::cerr << " timestamp: " << bismon_timestamp << " (" << bismon_timelong << " since Unix Epoch)" << std::endl;
  std::cerr << " last git commit: " << bismon_lastgitcommit << std::endl;
  std::cerr << " last git tag:" << bismon_lastgittag << std::endl;
  std::cerr << " checksum:" << bismon_checksum << std::endl;
  std::cerr << " source directory:" << bismon_directory << std::endl;
  std::cerr << " our Makefile:" << bismon_makefile << std::endl;
  std::cerr << "################################" << std::endl;
} // end bmc_show_version


int
main(int argc, char**argv)
{
  if (argc>1 && (!strcmp(argv[1], "-D") || !strcmp(argv[1], "--debug")))
    bmc_debug_flag = true;
  openlog(basename(argv[0])?:argv[0], LOG_CONS|LOG_PID|LOG_NDELAY|LOG_PERROR, LOG_USER);
  try
    {
      bmc_parse_options(argc, argv);
      BMC_DEBUG("parsed " << argc << " options");
      if (bmc_guile_vec.empty())
        {
          BMC_DEBUG("no guile");
        }
      else   // some guile scripts
        {
          if (scm_with_guile( bmc_run_guile, &bmc_guile_vec) == nullptr)
            {
              char errmsg[64];
              memset(errmsg, 0, sizeof(errmsg));
              snprintf(errmsg, sizeof(errmsg), "failed to run %d guile scripts or commands", (int)(bmc_guile_vec.size()));
              throw std::runtime_error(errmsg);
            }
        }
#warning incomplete BM_compile_module, see Makefile
      /* we should use syslog and the $BISMON_CXX variable, etc... */
      syslog (LOG_WARNING, "%s (file %s at " __DATE__ "@" __TIME__ ") incomplete"
              " - git %s (directory %s)",
              argv[0], bismon_shortgitid, bismon_directory);
      throw std::runtime_error(std::string("incomplete ")+argv[0]);
    }
  catch (std::exception& exc)
    {
      std::string msg{"FAILURE OF"};
      std::clog << "failure of ";
      for (int i=0; i<argc; i++)
        {
          std::clog << ' ' << argv[i];
          msg += " ";
          msg += argv[i];
        }
      std::clog << std::endl;
      std::clog << "pid " << (long) getpid() << " got exception:" << exc.what() << std::endl
                << " (" << __FILE__ << ":" << __LINE__ << ")" << std::endl;
      syslog(LOG_ERR, "%s: got exception: %s (git id %s)", argv[0], msg.c_str(), bismon_shortgitid);
      abort();
    };
} // end main

//// end of file  BM_compile_module.cc
