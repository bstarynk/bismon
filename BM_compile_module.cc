// file BM_compile_module.cc on https://github.com/bstarynk/bismon/
// SPDX-License-Identifier: GPL-3.0-or-later

/***
    BISMON
    Copyright © 2020 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
    contributed by Basile Starynkevitch (working at CEA, LIST, France)
    <basile@starynkevitch.net> or <basile.starynkevitch@cea.fr>

    BM_compile_module: a standalone program to compile a BISMON generated module

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
#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <set>
#include <string>
#include <cassert>
#include <unistd.h>
#include <syslog.h>
#include <getopt.h>
#include <glibmm/checksum.h>
#include "id_BM.h"


// from generated _timestamp.c
extern "C" const char bismon_timestamp[];
extern "C" const unsigned long bismon_timelong;
extern "C" const char bismon_lastgitcommit[];
extern "C" const char bismon_lastgittag[];
extern "C" const char bismon_checksum[];
extern "C" const char bismon_directory[];
extern "C" const char bismon_makefile[];
extern "C" const char bismon_gitid[];
extern "C" const char bismon_shortgitid[];

void bmc_parse_options(int& argc, char**argv);
void bmc_show_usage(const char*progname);
void bmc_show_version(const char*progname);


static char*bmc_module_idstr;
static char*bmc_tempmodule_idstr;
static char*bmc_plugin_idstr;

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

int
main(int argc, char**argv)
{
  openlog(basename(argv[0])?:argv[0], LOG_CONS|LOG_PID|LOG_NDELAY|LOG_PERROR, LOG_USER);
  try
    {
      bmc_parse_options(argc, argv);
#warning incomplete BM_compile_module, see Makefile
      /* we should use syslog and the $BISMON_CXX variable, etc... */
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
      std::clog << "pid " << (long) getpid() << " got exception:" << exc.what() << std::endl;
      syslog(LOG_ERR, "%s: got exception: %s (git id %s)", argv[0], msg.c_str(), bismon_shortgitid);
      abort();
    };
} // end main


enum bmc_longopt_en
{
  BMCOPT__longoptstart=1024,
  BMCOPT_module,
  BMCOPT_tempmodule,
  BMCOPT_plugin,
  BMCOPT_in,
  BMCOPT_oid,
};

static const struct option
  bmc_long_options[] =
{
  {"version",     no_argument,        0, 'V'},
  {"help",        no_argument,        0, 'h'},
  {"module",      required_argument,  0, BMCOPT_module},
  {"tempmodule",  required_argument,  0, BMCOPT_tempmodule},
  {"plugin",      required_argument,  0, BMCOPT_plugin},
  {"in",      required_argument,  0, BMCOPT_in},
  {"oid",      required_argument,  0, BMCOPT_oid},
  {0,0,0,0}
};

void
bmc_parse_options(int& argc, char**argv)
{
  for (;;)
    {
      int optix= -1;
      int optres = getopt_long(argc, argv, "Vh", bmc_long_options, &optix);
      if (optres < 0)
        break;
      switch (optres)
        {
        case 'h':
          bmc_show_usage(argv[0]);
          exit(EXIT_SUCCESS);
          break;
        case 'V':
          bmc_show_version(argv[0]);
          exit(EXIT_SUCCESS);
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
  std::cerr << "# See also https://github.com/bstarynk/bismon" << std::endl;
  std::cerr << "# Funded by https://www.chariotproject.eu/ https://www.decoder-project.eu/" << std::endl;
  std::cerr << "# this is GPLv3+ licensed software, see https://www.gnu.org/licenses/gpl-3.0.en.html ** NO WARRANTY" << std::endl;
} // end bmc_show_usage


void
bmc_show_version(const char*progname)
{
  std::cerr << progname << " version information:" << std::endl;
} // end bmc_show_version

//// end of file  BM_compile_module.cc
