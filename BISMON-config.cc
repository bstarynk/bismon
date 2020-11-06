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
#define _GNU_SOURCE 1
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
#include <iostream>

bool bmc_debug_flag;
bool bmc_gtk_flag;
std::string bmc_target_gcc;
std::string bmc_target_gxx;

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

extern "C" bool bmc_debug_flag;

// typical usage could be BMC_DEBUG("something bad x=" << x)
#define BMC_DEBUG_AT_BIS(Fil,Lin,...) do {			\
  if (bmc_debug_flag) {						\
    std::clog << "¿" /* U+00BF INVERTED QUESTION MARK */	\
	      << (Fil) << ":" << Lin << ":: "			\
	      << __VA_ARGS__ << std::endl; } } while(0)

#define BMC_DEBUG_AT(Fil,Lin,...) BMC_DEBUG_AT_BIS(Fil,Lin,##__VA_ARGS__)

// typical usage would be BMC_DEBUG("annoying x=" << x)
#define BMC_DEBUG(...) BMC_DEBUG_AT(__FILE__,__LINE__,##__VA_ARGS__)



void bmc_show_usage(const char*progname);

void bmc_show_version(const char*progname);

void
bmc_parse_options(int& argc, char**argv)
{
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
	  BMC_DEBUG("target GCC:" << bmc_target_gcc);
          break;
        case BMCOPT_target_gxx:
          bmc_target_gxx = optarg;
	  BMC_DEBUG("target GXX:" << bmc_target_gxx);
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

#warning BISMON-config.cc should be coded


int
main (int argc, char**argv) {
  if (argc>1 && (!strcmp(argv[1], "-D") || !strcmp(argv[1], "--debug")))
    bmc_debug_flag = true;
  bmc_parse_options(argc, argv);
}


// end of file BISMON-config.cc 
