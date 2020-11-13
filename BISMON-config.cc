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


//// Please use astyle (see http://astyle.sourceforge.net/ ...) to format this C++ file
//// using astyle --style=gnu -s2 BISMON-config.cc  ....

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
#include <vector>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <iostream>

extern "C" bool bmc_debug_flag;
extern "C" bool bmc_batch_flag;
extern "C" bool bmc_gtk_flag;
extern "C" bool bmc_given_gtk_flag;
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

bool bmc_batch_flag;
bool bmc_debug_flag;
bool bmc_gtk_flag;
bool bmc_given_gtk_flag;
bool bmc_dryrun_flag;

enum bmc_longopt_en
{
  BMCOPT__longoptstart=1024,
  BMCOPT_with_gtk,
  BMCOPT_batch,
  BMCOPT_without_gtk,
  BMCOPT_target_gcc,
  BMCOPT_target_gxx,
  BMCOPT_dry_run,
  BMCOPT_output_directory,
};

//see https://en.wikipedia.org/wiki/ANSI_escape_code
#define BMC_BOLD_ESCAPE "\033[1m"
#define BMC_PLAIN_ESCAPE "\033[0m"
static const struct option
  bmc_long_options[] =
{
  {"version",     	 no_argument,        0, 'V'},
  {"help",        	 no_argument,        0, 'h'},
  {"debug",       	 no_argument,        0, 'D'},
  {"with-gtk",    	 no_argument,  0,       BMCOPT_with_gtk},
  {"without-gtk",    	 no_argument,  0,       BMCOPT_without_gtk},
  {"dry-run",    	 no_argument,  0,       BMCOPT_dry_run},
  {"batch",    	         no_argument,  0,       BMCOPT_batch},
  {"target-gcc",  	 required_argument,  0,       BMCOPT_target_gcc},
  {"target-g++",  	 required_argument,  0,       BMCOPT_target_gxx},
  {"output-directory",   required_argument,  0,       BMCOPT_output_directory},
  {0,0,0,0}
};

extern "C" bool bmc_debug_flag;
extern "C" bool bmc_batch_flag;

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
        case BMCOPT_batch:
          bmc_batch_flag = true;
          break;
        case BMCOPT_with_gtk:
          bmc_gtk_flag = true;
          bmc_given_gtk_flag = true;
          BMC_DEBUG("with GTK");
          break;
        case BMCOPT_without_gtk:
          bmc_gtk_flag = false;
          bmc_given_gtk_flag = true;
          BMC_DEBUG("without GTK");
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
  std::cerr << " --version | -V         # give version information" << std::endl;
  std::cerr << " --help | -h            # give this help message" << std::endl;
  std::cerr << " --debug | -D           # debug this configurator program " << progname << std::endl;
  std::cerr << " --batch                # dont ask for missing arguments even in terminal" << std::endl;
  std::cerr << " --with-gtk             # enable GTK3 Graphical User Interface in Bismon" << std::endl;
  std::cerr << " --without-gtk          # disable GTK3 Graphical User Interface in Bismon" << std::endl;
  std::cerr << " --dry-run              # wont fork target compilation commands" << std::endl;
  std::cerr << " --target-gcc=PATH      # set to PATH the target GCC compiler executable for C code" << std::endl;
  std::cerr << " --target-gxx=PATH      # set to PATH the target GCC compiler for C++ code" << std::endl;
  std::cerr << " --output-directory=DIR # set the output directory to DIR - default is " << bismon_directory << std::endl;
  std::cerr << "## See github.com/bstarynk/bismon/ for more about Bismon." << std::endl;
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
          std::cerr << progname << ": invalid " << (forcplusplus?"C++":"C")
                    << " compiler '" << compiler << "'" << std::endl;
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
      std::string compcmd = compiler + " -v 2>&1";
      BMC_DEBUG("bmc_check_target_compiler compcmd: " << compcmd);
      FILE* compilepipe = popen(compcmd.c_str(), "r");
      if (!compilepipe)
        {
          std::cerr << progname << " failed to popen " << compcmd << " : " << strerror(errno) << std::endl;
          exit (EXIT_FAILURE);
        }
      BMC_DEBUG("bmc_check_target_compiler compilepipe fd#" << fileno(compilepipe) << " pid#" << (int)getpid());
      std::string cmdstr;
      int gccversion_major=0, gccversion_minor=0;
      while (cmdstr.size() < 2048)
        {
          char linbuf[128];
          memset (linbuf, 0, sizeof(linbuf));
          errno = 0;
          if (!fgets(linbuf, sizeof(linbuf), compilepipe))
            {
              if (feof(compilepipe))
                break;
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
          std::cerr << "However " << compcmd << " gave:" << std::endl
                    << cmdstr << std::endl;
          exit(EXIT_FAILURE);
        }
      int clcod = pclose(compilepipe);
      if (clcod != 0)
        {
          std::cerr << progname << ": compiler command " << compcmd << " pclose failure (code " << clcod << ")" << std::endl;
          exit(EXIT_FAILURE);
        }
      compilepipe = nullptr;
    }
} // end bmc_check_target_compiler

void
bmc_print_config_header(const char*progname)
{
  std::string headerpath = bmc_out_directory + "/_bm_config.h";
  BMC_DEBUG("bmc_print_config_header: headerpath=" << headerpath);
  if (!access(headerpath.c_str(), F_OK))
    {
      std::string backup = headerpath + "~";
      rename (headerpath.c_str(), backup.c_str());
    }
  std::ofstream headoutf (headerpath);
  if (!headoutf.good())
    {
      std::cerr << progname << " failed to open generated header " << headerpath << " : " << strerror(errno) << std::endl;
      exit(EXIT_FAILURE);
    }
  headoutf << "/// GENERATED Bismon HEADER FILE " << headerpath << " - DO NOT EDIT" << std::endl;
  headoutf << "/// See http://github.com/bstarynk/bismon/" << std::endl;
  headoutf << "#ifndef BISMON_CONFIG" << std::endl;
  headoutf << std::endl;
  headoutf << "#define BISMON_TIMESTAMP \"" << bismon_timestamp << "\"" << std::endl;
  headoutf << "#define BISMON_BUILDTIME " << bismon_timelong << std::endl;
  headoutf << "#define BISMON_DIRECTORY  \"" << bismon_directory << "\"" << std::endl;
  headoutf << "#define BISMON_CHECKSUM  \"" << bismon_checksum << "\"" << std::endl;
  headoutf << "#define BISMON_MAKEFILE  \"" << bismon_makefile << "\"" << std::endl;
  headoutf << "#define BISMON_GIT_ID  \"" << bismon_gitid << "\"" << std::endl;
  headoutf << "#define BISMON_SHORT_GIT_ID  \"" << bismon_shortgitid << "\"" << std::endl;
  if (bmc_gtk_flag)
    headoutf << "#define BISMONGTK 1" << std::endl;
  else
    headoutf << "#undef BISMONGTK" << std::endl;
  if (!bmc_target_gcc.empty())
    headoutf << "#define BISMON_TARGET_GCC \"" << bmc_target_gcc << "\"" << std::endl;
  if (!bmc_target_gxx.empty())
    headoutf << "#define BISMON_TARGET_GXX \"" << bmc_target_gxx << "\"" << std::endl;
  if (!bmc_out_directory.empty())
    headoutf << "#define BISMON_OUT_DIRECTORY \"" << bmc_out_directory << "\"" << std::endl;
  if (bmc_debug_flag)
    headoutf << "#define BISMON_DEBUG 1" << std::endl;
  else
    headoutf << "#undef BISMON_DEBUG" << std::endl;
  headoutf << std::endl;
  headoutf << "#define BISMON_CONFIG \"" << BISMON_SHORTGIT << "\"" << std::endl;
  headoutf << "#endif /*BISMON_CONFIG*/" << std::endl;
  headoutf << "// end of Bismon generated configuration header file " << headerpath << std::endl;
  BMC_DEBUG("bmc_print_config_header ending headerpath=" << headerpath);
  if (!bmc_batch_flag)
    std::cout << "# generated Bismon configuration header file " << headerpath << std::endl;
} // end bmc_print_config_header

void
bmc_print_config_data(const char*progname)
{
#define BMC_GITLS_COMMAND "git ls-files"
  std::string datapath = bmc_out_directory + "/_bm_config.c";
  BMC_DEBUG("bmc_print_config_data: datapath=" << datapath);
  if (!access(datapath.c_str(), F_OK))
    {
      std::string backup = datapath + "~";
      rename (datapath.c_str(), backup.c_str());
    }
  std::ofstream dataoutf (datapath);
  if (!dataoutf.good())
    {
      std::cerr << progname << " failed to open generated data " << datapath << " : " << strerror(errno) << std::endl;
      exit(EXIT_FAILURE);
    }
  dataoutf << "/// *** GENERATED Bismon DATA FILE " << datapath << " - DO NOT EDIT ***" << std::endl;
  dataoutf << "/// see github.com/bstarynk/bismon for more about Bismon." << std::endl << std::endl;
  dataoutf << "const char bismon_confdata_gitid[]=\"" << bismon_gitid << "\";" << std::endl;
  FILE*gitpipe = popen(BMC_GITLS_COMMAND, "r");
  if (!gitpipe)
    {
      std::cerr << progname << " failed to popen " BMC_GITLS_COMMAND << ":" << strerror(errno) << std::endl;
      exit(EXIT_FAILURE);
    }
  std::vector<std::string> vecgitfilepath;
  std::vector<std::string> vecgitlinkpath;
  std::vector<std::string> vecgitdirpath;
  int linenopip = 0;
  do
    {
      char gitlinbuf[128];
      memset (gitlinbuf, 0, sizeof(gitlinbuf));
      if (!fgets(gitlinbuf, sizeof(gitlinbuf), gitpipe))
        break;
      int linl = (int)strlen(gitlinbuf);
      if (linl > 0 && gitlinbuf[linl-1] == '\n')
        gitlinbuf[linl-1] = (char)0;
      linenopip ++;
      BMC_DEBUG("bmc_print_config_data gitls #" << linenopip << ":" << gitlinbuf);
      for (int cix=0; cix<linl; cix++)
        if (!isalnum(gitlinbuf[cix]) && gitlinbuf[cix] != '_' && gitlinbuf[cix] != '/'
            && gitlinbuf[cix] != '+' && gitlinbuf[cix] != '-' && gitlinbuf[cix] != '.')
          {
            char cwdbuf[256];
            memset(cwdbuf, 0, sizeof(cwdbuf));
            if (!getcwd(cwdbuf, sizeof(cwdbuf)-1))
              cwdbuf[0] = '.';
            std::cerr << progname << " pipe " << BMC_GITLS_COMMAND << " output line#" << linenopip << ":" << gitlinbuf
                      << " - unexpected file name in directory " << cwdbuf << std::endl;
            std::cerr << "Expecting letters, digits, or one of '_/+-.' characters." << std::endl;
            exit(EXIT_FAILURE);
          }
      struct stat curgitst;
      memset(&curgitst, 0, sizeof(curgitst));
      if (stat(gitlinbuf, &curgitst))
        {
          std::cerr << progname << " pipe " << BMC_GITLS_COMMAND << " output line#" << linenopip << ":" << gitlinbuf
                    << " - stat(2) failed:" << strerror(errno) << std::endl;
          exit(EXIT_FAILURE);
        }
      switch(curgitst.st_mode & S_IFMT)
        {
        case S_IFREG:
          vecgitfilepath.push_back(std::string{gitlinbuf});
          BMC_DEBUG("bmc_print_config_data git file " << gitlinbuf);
          break;
        case S_IFLNK:
          vecgitlinkpath.push_back(std::string{gitlinbuf});
          BMC_DEBUG("bmc_print_config_data git symlink " << gitlinbuf);
          break;
        case S_IFDIR:
          vecgitdirpath.push_back(std::string{gitlinbuf});
          BMC_DEBUG("bmc_print_config_data git directory " << gitlinbuf);
          break;
        default:
          std::cerr << progname << ": unexpected git-listed file " << gitlinbuf << " (not a plain file, or symlink, or directory)" << std::endl;
          exit(EXIT_FAILURE);
        } // end switch ...
    }
  while (!feof(gitpipe));
  int pclocod = pclose(gitpipe);
  if (pclocod != 0)
    {
      std::cerr << progname << " pipe " << BMC_GITLS_COMMAND << " pclose failed (code " << pclocod << ")" << std::endl;
      exit(EXIT_FAILURE);
    }
  gitpipe = nullptr;
  dataoutf << "const char*const bismonconf_git_files[] = {" << std::endl;
  for (auto filepath: vecgitfilepath)
    dataoutf << "  \"" << filepath << "\"," << std::endl;
  dataoutf << "  (const char*)0 }; // end bismonconf_git_files" << std::endl;
  dataoutf << "const char*const bismonconf_git_symlinks[] = {" << std::endl;
  for (auto linkpath: vecgitlinkpath)
    dataoutf << "  \"" << linkpath << "\"," << std::endl;
  dataoutf << "  (const char*)0 }; // end bismonconf_git_symlinks" << std::endl;
  dataoutf << "const char*const bismonconf_git_dirs[] = {" << std::endl;
  for (auto dirpath: vecgitdirpath)
    dataoutf << "  \"" << dirpath << "/\"," << std::endl;
  dataoutf << "  (const char*)0 }; // end bismonconf_git_dirs" << std::endl;
  //
  dataoutf << std::endl << "/// end of Bismon generated data " << datapath << std::endl;
  if (!bmc_batch_flag)
    std::cout << "# generated Bismon configuration data file " << datapath << std::endl;
} // end bmc_print_config_data

void
bmc_print_config_make(const char*progname)
{
  std::string makepath = bmc_out_directory + "/_bismon-config.mk";
  BMC_DEBUG("bmc_print_config_make: makepath=" << makepath);
  if (!access(makepath.c_str(), F_OK))
    {
      std::string backup = makepath + "~";
      rename (makepath.c_str(), backup.c_str());
    }
  std::ofstream makeoutf (makepath);
  if (!makeoutf.good())
    {
      std::cerr << progname << " failed to open generated file " << makepath << " for GNU make : " << strerror(errno) << std::endl;
      exit(EXIT_FAILURE);
    }
  /// make prologue
  makeoutf << "### GENERATED Bismon CONFIGURATION FILE " <<
           makepath << " - DO NOT EDIT" << std::endl;
  makeoutf << "### this is for inclusion thru GNU make." << std::endl;
  makeoutf << "### See github.com/bstarynk/bismon/ for more about Bismon." << std::endl;
  makeoutf << "BISMONMK_TIMESTAMP=" << bismon_timestamp << std::endl;
  makeoutf << "BISMONMK_BUILDTIME=" << bismon_timelong << std::endl;
  makeoutf << "BISMONMK_DIRECTORY=" << bismon_directory << std::endl;
  makeoutf << "BISMONMK_CHECKSUM=" << bismon_checksum << std::endl;
  makeoutf << "BISMONMK_MAKEFILE=" << bismon_makefile << std::endl;
  makeoutf << "BISMONMK_GITID=" << bismon_gitid << std::endl;
  makeoutf << "BISMONMK_SHORTGITID=" << bismon_shortgitid << std::endl;
  if (bmc_gtk_flag)
    {
      makeoutf << "BISMONMK_GTK=$(shell pkg-config --modversion gtk+-3.0)" << std::endl;
      makeoutf << "BISMONMK_OBJECTS= $(BM_OBJECTS) $(BM_GTKOBJECTS)" << std::endl;
      makeoutf << "BISMONMK_PACKAGES= glib-2.0 gobject-2.0 jansson gtk+-3.0" << std::endl;
      makeoutf << "BISMONMK_EXECUTABLE= bismon-gtk" << std::endl;
    }
  else
    {
      makeoutf << "#no BISMONMK_GTK" << std::endl;
      makeoutf << "BISMONMK_OBJECTS= $(BM_OBJECTS)" << std::endl;
      makeoutf << "BISMONMK_PACKAGES= glib-2.0 gobject-2.0 jansson" << std::endl;
      makeoutf << "BISMONMK_EXECUTABLE= bismon" << std::endl;
    }
  if (!bmc_target_gcc.empty())
    makeoutf << "BISMONMK_TARGET_GCC=" << bmc_target_gcc << std::endl;
  else
    makeoutf << "#no BISMONMK_TARGET_GCC" << std::endl;
  if (!bmc_target_gxx.empty())
    makeoutf << "BISMONMK_TARGET_GXX=" << bmc_target_gxx << std::endl;
  else
    makeoutf << "#no BISMONMK_TARGET_GXX" << std::endl;
  if (!bmc_out_directory.empty())
    makeoutf << "BISMONMK_OUT_DIRECTORY=" << bmc_out_directory << std::endl;
  else
    makeoutf << "#no BISMONMK_OUT_DIRECTORY" << std::endl;
  if (bmc_debug_flag)
    makeoutf << "BISMONMK_DEBUG=1" << std::endl;
  else
    makeoutf << "#no BISMONMK_DEBUG" << std::endl;
  makeoutf << "BISMONMK_CONFIGPATH=" << makepath << std::endl;
  makeoutf << "### end of Bismon generated file for GNU make " << makepath << " (by " << __FILE__ << ")" << std::endl;
  BMC_DEBUG("bmc_print_config_make ending makepath=" << makepath);
  if (!bmc_batch_flag)
    std::cout << "# generated Bismon configuration GNU make file " << makepath << std::endl;
} // end bmc_print_config_make


const char*
bmc_readline(const char*progname, const char*prompt)
{
  char realprompt[64];
  memset (realprompt, 0, sizeof(realprompt));
  /// the prompt is in bold, see https://en.wikipedia.org/wiki/ANSI_escape_code
  snprintf (realprompt, sizeof(realprompt),
            BMC_BOLD_ESCAPE "%s" BMC_PLAIN_ESCAPE, prompt);
  char*ans = readline(realprompt);
  if (!ans)
    {
      std::cerr << progname << " failed to readline for " << prompt << " :: " << strerror(errno) << std::endl;
      exit(EXIT_FAILURE);
    }
  return ans;
} // end bmc_readline

void
bmc_ask_missing_configuration(const char*progname)
{
  BMC_DEBUG("bmc_ask_missing_configuration start progname=" << progname);
  using_history();
  std::cout << std::endl << "***** " BMC_BOLD_ESCAPE "BISMON Configurator" BMC_PLAIN_ESCAPE " ****" << std::endl
            << std::endl << "(this program " << progname << " uses GNU readline, so you could use the <tab> key is for autocompletion," << std::endl;
  std::cout << "... and your input lines are editable.  For more about GNU readline, see www.gnu.org/software/readline ...)" << std::endl;
  std::cout << "For more about Bismon, see github.com/bstarynk/bismon ...." << std::endl << std::endl;
  /// ask about GTK
  while (!bmc_given_gtk_flag)
    {
      std::cout << "Build Bismon with a buggy GTK3 graphical user interface? [y/n]" << std::endl;
      const char*gtkgui = bmc_readline(progname, "BISMON with GTK? ");
      if (gtkgui[0] == 'y' || gtkgui[0] == 'Y' || gtkgui[0] == '1')
        {
          bmc_given_gtk_flag = true;
          bmc_gtk_flag = true;
        }
      else if (gtkgui[0] == 'n' || gtkgui[0] == 'N' || gtkgui[0] == '0')
        {
          bmc_given_gtk_flag = true;
          bmc_gtk_flag = false;
        }
      free ((void*)gtkgui), gtkgui = nullptr;
    }
  std::cout << std::endl;
  /// ask about target GCC compilers for C and for C++
  while (bmc_target_gcc.empty())
    {
      std::cout << "Target Bismon GCC [cross-]compiler for C code. Should be at least a GCC 10. See gcc.gnu.org...." << std::endl;
      std::cout << "(it is preferable to enter some absolute path, such as /usr/local/bin/gcc-10)" << std::endl;
      const char*gcctarget = bmc_readline(progname, "BISMON target GCC? ");
      if (gcctarget)
        {
          bmc_target_gcc.assign(gcctarget);
          add_history(gcctarget);
          free ((void*)gcctarget), gcctarget = nullptr;
        }
    }
  while (bmc_target_gxx.empty())
    {
      std::cout << "Target Bismon GCC [cross-]compiler for C++ code. Should be at least a GCC 10. See gcc.gnu.org...." << std::endl;
      std::cout << "(it is recommended to enter some absolute path, such as /usr/local/bin/g++-10)" << std::endl;
      const char*gxxtarget = bmc_readline(progname, "BISMON target GXX? ");
      if (gxxtarget)
        {
          bmc_target_gxx.assign(gxxtarget);
          add_history(gxxtarget);
          free ((void*)gxxtarget), gxxtarget = nullptr;
        }
    }
  /// ask about the output directory, into which files would be written
  char cwdbuf[256];
  memset (cwdbuf, 0, sizeof(cwdbuf));
  std::cout << std::endl;
  errno = 0;
  if (!getcwd(cwdbuf, sizeof(cwdbuf)-1))
    {
      std::cerr << progname << ": failed to getcwd - " << strerror(errno) << std::endl;
      exit(EXIT_FAILURE);
    }
  while (bmc_out_directory.empty())
    {
      std::cout << "Bismon output source directory. If none is given, defaults to current directory " << cwdbuf << std::endl;
      std::cout << "This configurator " << progname << " will write some textual files -a header file and a Makefile fragment- in it." << std::endl;
      std::cout << "(it is recommended to enter some absolute path, such as /usr/src/Bismon or /home/foo/bismon ....)" << std::endl;
      const char*outdir = bmc_readline(progname, "BISMON output sourcedir? ");
      if (outdir[0])
        bmc_out_directory.assign(outdir);
      else
        bmc_out_directory.assign(cwdbuf);
      free ((void*)outdir), outdir = nullptr;
    }
  std::cout << std::endl;
  clear_history();
} // end bmc_ask_missing_configuration




int
main (int argc, char**argv)
{
  if (argc>1 && (!strcmp(argv[1], "-D") || !strcmp(argv[1], "--debug")))
    bmc_debug_flag = true;
  bmc_parse_options(argc, argv);
  if (isatty(STDIN_FILENO))
    bmc_ask_missing_configuration(argv[0]);
  if (bmc_out_directory.empty())
    bmc_out_directory = bismon_directory;
  bmc_check_output_directory(argv[0]);
  bmc_check_target_compiler(argv[0], false); // for C
  bmc_check_target_compiler(argv[0], true); // for C++
  if (!bmc_dryrun_flag)
    {
      bmc_print_config_header(argv[0]);
      bmc_print_config_make(argv[0]);
      bmc_print_config_data(argv[0]);
    }
  if (isatty(STDIN_FILENO) && !bmc_batch_flag)
    {
      std::cout << "### See also refpersys.org for another free software project."
                << std::endl;
    }
  return 0;
} // end function main


// end of file BISMON-config.cc
