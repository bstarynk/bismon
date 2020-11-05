// file BISMON-config.cc
// SPDX-License-Identifier: GPL-3.0-or-later
// see https://github.com/bstarynk/bismon/
/***
    BISMON
    Copyright © 2020 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
    contributed by Basile Starynkevitch (working at CEA, LIST, France)
    <basile@starynkevitch.net> or <basile.starynkevitch@cea.fr>
    with help from Franck Védrine.

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
#define _GNU_SOURCE
#endif /*_GNU_SOURCE*/

// Linux headers
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <getopt.h>
#include <readline/readline.h>
#include <readline/history.h>

// C++ headers
#include <map>
#include <set>
#include <fstream>
#include <string>

enum bmc_longopt_en
{
  BMCOPT__longoptstart=1024,
  BMCOPT_with_gtk,
};

bool bmc_debug_flag;
bool bmc_gtk_flag;
std::string bmc_target_gcc;
std::string bmc_target_gxx;
enum bmc_longopt_en
{
  BMCOPT__longoptstart=1024,
  BMCOPT_with_gtk,
  BMCOPT_target_gcc,
  BMCOPT_target_gxx,
};

static const struct option
  bmc_long_options[] =
{
  {"version",     no_argument,        0, 'V'},
  {"help",        no_argument,        0, 'h'},
  {"debug",       no_argument,        0, 'D'},
  {"with-gtk",    no_argument,  0,       BMCOPT_with_gtk},
  {"target-gcc",  required_argument,  0,       BMCOPT_target_gcc},
  {"target-g++",  required_argument,  0,       BMCOPT_target_gxx},
  {0,0,0,0}
};


  for (;;)
    {
      int optix= -1;
      int optres = getopt_long(argc, argv, "DVh", bmc_long_options, &optix);
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
	case BMCOPT_with_gtk:
	  bmc_gtk_flag = true;
	  break;
	case BMCOPT_target_gcc:
	  bmc_target_gcc = optarg;
	  break;
	case BMCOPT_target_gxx:
	  bmc_target_gxx = optarg;
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
  std::cerr << " --debug | -D # debug this program " << progname << std::endl;
  std::cerr << " --with-gtk # enable GTK3 Graphical User Interface in bismon" << std::endl;
  std::cerr << " --target-gcc # set the target GCC compiler for C code" << std::endl;
  std::cerr << " --target-gxx # set the target GCC compiler for C++ code" << std::endl;
}

#error BISMON-config.cc should be coded
