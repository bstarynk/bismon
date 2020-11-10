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
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <getopt.h>
#include <dirent.h>
#include <sys/types.h>
#include <readline/readline.h>
#include <readline/history.h>

// C++ headers
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <iostream>

extern "C" bool bmc_debug_flag;
extern "C" bool bmc_gtk_flag;
extern "C" bool bmc_dryrun_flag;
std::string bmc_target_gcc;
std::string bmc_target_gxx;
std::string bmc_out_directory;

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

bool bmc_debug_flag;
bool bmc_gtk_flag;
bool bmc_dryrun_flag;

enum bmc_longopt_en
{
  BMCOPT__longoptstart=1024,
  BMCOPT_with_gtk,
  BMCOPT_target_gcc,
  BMCOPT_target_gxx,
  BMCOPT_dry_run,
  BMCOPT_output_directory,
};

static const struct option
  bmc_long_options[] =
{
  {"version",     	 no_argument,        0, 'V'},
  {"help",        	 no_argument,        0, 'h'},
  {"debug",       	 no_argument,        0, 'D'},
  {"with-gtk",    	 no_argument,  0,       BMCOPT_with_gtk},
  {"dry-run",    	 no_argument,  0,       BMCOPT_dry_run},
  {"target-gcc",  	 required_argument,  0,       BMCOPT_target_gcc},
  {"target-g++",  	 required_argument,  0,       BMCOPT_target_gxx},
  {"output-directory",   required_argument,  0,       BMCOPT_output_directory},
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
          BMC_DEBUG("with GTK");
          break;
        case BMCOPT_dry_run:
          bmc_dryrun_flag = true;
          BMC_DEBUG("dry run - won't fork compilation commands");
          break;
        case BMCOPT_target_gcc:
          bmc_target_gcc = optarg;
          BMC_DEBUG("target GCC:" << bmc_target_gcc);
          break;
        case BMCOPT_target_gxx:
          bmc_target_gxx = optarg;
          BMC_DEBUG("target GXX:" << bmc_target_gxx);
          break;
        case BMCOPT_output_directory:
          bmc_out_directory = optarg;
          BMC_DEBUG("output directory :" << bmc_out_directory);
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
  std::cerr << " --dry-run # wont fork target compilation commands" << std::endl;
  std::cerr << " --target-gcc # set the target GCC compiler for C code" << std::endl;
  std::cerr << " --target-gxx # set the target GCC compiler for C++ code" << std::endl;
  std::cerr << " --output-directory # set the output directory - default is " << bismon_directory << std::endl;
} // end bmc_show_usage

void
bmc_show_version(const char*progname)
{
  std::cout << progname
            << " version "  BISMON_SHORTGIT
            << " built on " << __DATE__ "@" << __TIME__ << " from " << __FILE__
            << std::endl
            << "... for last git commit " << bismon_lastgitcommit
            << std::endl
            << "... in directory " << bismon_directory
            << " timestamp " << bismon_timestamp << std::endl
            << "... checksum " << bismon_checksum
            << std::endl;
} // end bmc_show_version

static void
bmc_check_output_directory(const char*progname)
{
  BMC_DEBUG("bmc_check_output_directory progname=" << progname);
  struct stat st;
  memset (&st, 0, sizeof(st));
  if (stat(bmc_out_directory.c_str(), &st))
    {
      std::cerr << progname << " failed to stat output directory:"
                << strerror(errno) << std::endl;
      exit (EXIT_FAILURE);
    }
  if (!S_ISDIR(st.st_mode))
    {
      std::cerr << progname << " has bad output directory " << bmc_out_directory
                << std::endl;
      exit (EXIT_FAILURE);
    }
  if ((st.st_mode & S_IRWXU) != S_IRWXU)
    {
      std::cerr << progname << ": output directory "  << bmc_out_directory
                << " is not rwx for user." << std::endl;
      exit (EXIT_FAILURE);
    }
}
// end bmc_check_output_directory


static void
bmc_check_target_compiler(const char*progname, bool forcplusplus)
{
  std::string compiler = forcplusplus ? bmc_target_gxx : bmc_target_gcc;
  BMC_DEBUG("bmc_check_target_compiler compiler=" << compiler << " progname=" << progname);
  if (compiler.empty())
    {
      std::cerr << progname << ": no cross-compiler given for " << (forcplusplus?"C++":"C") << std::endl;
      exit (EXIT_FAILURE);
    }
  for (char c: compiler)
    {
      if (!isalnum(c) && c != '_' && c != '+' && c != '-' && c != '.' && c != '/')
        {
          std::cerr << progname << ": invalid " << (forcplusplus?"C++":"C") << " compiler: " << compiler << std::endl;
          std::cerr << "(only letters, digits, plus, minus, underscore, dot and slash are allowed)" << std::endl;
          exit (EXIT_FAILURE);
        }
    }
  if (bmc_dryrun_flag)
    {
      std::cout << progname << " should check the target GCC compiler " << compiler << std::endl;
      std::cout << "See also http://gcc.gnu.org/ and notice that a GCC 10 compiler" << std::endl;
      std::cout << "... is required for Bismon, with plugins enabled." << std::endl;
      std::cout << "Try to run your GCC [cross-]compiler with just the -v program option." << std::endl;
    }
  else
    {
      std::string compcmd = compiler + " -v";
      BMC_DEBUG("bmc_check_target_compiler compcmd: " << compcmd);
      FILE* compilepipe = popen(compcmd.c_str(), "r");
      if (!compilepipe)
        {
          std::cerr << progname << " failed to popen " << compcmd << " : " << strerror(errno) << std::endl;
          exit (EXIT_FAILURE);
        }
      std::string cmdstr;
      int gccversion_major=0, gccversion_minor=0;
      while (cmdstr.size() < 2048)
        {
          char linbuf[128];
          memset (linbuf, 0, sizeof(linbuf));
          if (!fgets(linbuf, sizeof(linbuf), compilepipe))
            {
              std::cerr << progname << ": fgets failed on popen " << compcmd  << " : " << strerror(errno) << std::endl;
              exit(EXIT_FAILURE);
            }
          cmdstr.append(linbuf);
          if (gccversion_major==0)
            sscanf(linbuf, "gcc version %d.%d", &gccversion_major, &gccversion_minor);
        }
      BMC_DEBUG("bmc_check_target_compiler compcmd: " << compcmd << " got cmdstr " << std::endl
                << cmdstr << std::endl);
      BMC_DEBUG("bmc_check_target_compiler gccversion_major=" << gccversion_major << ", gccversion_minor=" << gccversion_minor);
      if (gccversion_major != 10)
        {
          std::cerr << progname << ": Bismon requires a GCC 10 compiler." << std::endl ;
          if (gccversion_major > 0)
            std::cerr << "But " << compiler << " is a GCC " << gccversion_major << "." << gccversion_minor
                      << " compiler." << std::endl;
          std::cerr << "See http://gcc.gnu.org/ for more about GCC, and github.com/bstarynk/bismon for more about Bismon." << std::endl;
          exit(EXIT_FAILURE);
        }
    }
} // end bmc_check_target_compiler

void
bmc_print_config_header(void)
{
  std::string headerpath = bmc_out_directory + "_bm_config.h";
  if (!access(headerpath.c_str(), F_OK))
    {
      std::string backup = headerpath + "~";
      rename (headerpath.c_str(), backup.c_str());
    }
  std::ofstream headoutf (headerpath);
  headoutf << "/// GENERATED Bismon HEADER FILE " << headerpath << " - DO NOT EDIT" << std::endl;
  headoutf << "/// See http://github.com/bstarynk/bismon/" << std::endl;
} // end bmc_print_config_header


void
bmc_print_config_make(void)
{
  std::string makepath = bmc_out_directory + "_bismon-config.mk";
  if (!access(makepath.c_str(), F_OK))
    {
      std::string backup = makepath + "~";
      rename (makepath.c_str(), backup.c_str());
    }
  std::ofstream makeoutf (makepath);
  /// make prologue
  makeoutf << "### GENERATED Bismon GNUMakefile CONFIGURATION FILE " <<
           makepath << " - DO NOT EDIT" << std::endl;
  makeoutf << "/// See http://github.com/bstarynk/bismon/" << std::endl;
} // end bmc_print_config_make

int
main (int argc, char**argv)
{
  if (argc>1 && (!strcmp(argv[1], "-D") || !strcmp(argv[1], "--debug")))
    bmc_debug_flag = true;
  bmc_parse_options(argc, argv);
  if (bmc_out_directory.empty())
    bmc_out_directory = bismon_directory;
  bmc_check_output_directory(argv[0]);
  bmc_check_target_compiler(argv[0], false); // for C
  bmc_check_target_compiler(argv[0], true); // for C++
  std::cerr << __FILE__ << ":" << __LINE__ << " incomplete" << std::endl;
#warning incomplete main
  exit(EXIT_FAILURE);
} // end function main


// end of file BISMON-config.cc
