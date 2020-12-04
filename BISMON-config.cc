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
#include <cassert>
#include <iostream>
#include <sstream>

extern "C" bool bmc_debug_flag;
extern "C" bool bmc_batch_flag;
extern "C" bool bmc_dryrun_flag;
std::string bmc_start_str_ctime;
time_t bmc_start_time;

std::string bmc_make;
std::string bmc_packages;
std::string bmc_target_gcc;
std::string bmc_target_gxx;
std::string bmc_out_directory;
std::string bmc_ninja_file;
std::string bmc_onion_includedir;
std::string bmc_onion_libdir;

std::vector<std::string> bmc_source_files;
std::vector<std::string> bmc_constdep_files;
// from generated __timestamp.c - see timestamp-emit.sh script
extern "C" const char bismon_timestamp[];
extern "C" const unsigned long bismon_timelong;
extern "C" const char bismon_lastgitcommit[];
extern "C" const char bismon_lastgittag[];
extern "C" const char bismon_checksum[];
extern "C" const char bismon_directory[];
extern "C" const char bismon_gnumakefile[];
extern "C" const char bismon_gitid[];
extern "C" const char bismon_shortgitid[];
extern "C" const char* bismon_make;
extern "C" const char* bismon_packages;
extern "C" const char* bismon_target_gcc;
extern "C" const char* bismon_target_gxx;
extern "C" const char* const bismon_sources[];
extern "C" const int bismon_source_number;
extern "C" const char* bismon_onion_includedir;
extern "C" const char* bismon_onion_libdir;


bool bmc_batch_flag;
bool bmc_debug_flag;
bool bmc_dryrun_flag;
bool bmc_constdepend_flag;
bool bmc_silent_flag;
bool bmc_force_flag;

char bmc_hostname[64];
enum bmc_longopt_en
{
  BMCOPT__longoptstart=1024,
  BMCOPT_batch,
  BMCOPT_ninja,
  BMCOPT_target_gcc,
  BMCOPT_target_gxx,
  BMCOPT_const_depend,
  BMCOPT_dry_run,
  BMCOPT_skip,
  BMCOPT_output_directory,
  BMCOPT_onion_incldir,
  BMCOPT_onion_libdir,
};

//see https://en.wikipedia.org/wiki/ANSI_escape_code
#define BMC_BOLD_ESCAPE "\033[1m"
#define BMC_PLAIN_ESCAPE "\033[0m"
static const struct option
  bmc_long_options[] =
{
  {"version",     	 no_argument,        0,    'V'},
  {"help",        	 no_argument,        0,    'h'},
  {"debug",       	 no_argument,        0,    'D'},
  {"silent",       	 no_argument,        0,    'S'},
  {"force",       	 no_argument,        0,    'f'},
  {"dry-run",    	 no_argument,        0,    BMCOPT_dry_run},
  {"batch",    	         no_argument,        0,    BMCOPT_batch},
  {"const-depend",    	 no_argument,        0,    BMCOPT_const_depend},
  {"ninja",              required_argument,  0,    BMCOPT_ninja},
  {"target-gcc",  	 required_argument,  0,    BMCOPT_target_gcc},
  {"target-gxx",  	 required_argument,  0,    BMCOPT_target_gxx},
  {"skip",  	         required_argument,  0,    BMCOPT_skip},
  {"output-directory",   required_argument,  0,    BMCOPT_output_directory},
  {"onion-incldir",      required_argument,  0,    BMCOPT_onion_incldir},
  {"onion-libdir",       required_argument,  0,    BMCOPT_onion_libdir},
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


static char**bmc_main_argv;
static int bmc_main_argc;

void bmc_show_usage(const char*progname);

void bmc_show_version(const char*progname);

void bmc_failure_at (const char*reason, int lineno);
#define BMC_FAILURE(Reason) bmc_failure_at((Reason),__LINE__)

void bmc_set_readline_buffer(const std::string& str);

void bmc_failure_at(const char*reason, int lineno)
{
  std::cerr << bmc_main_argv[0] << " failure: " << reason << " at " << __FILE__ << ":" << lineno << std::endl;
  std::cerr << "\t invoked as: ";
  for (int ix=0; ix<bmc_main_argc; ix++)
    std::cerr << ' ' << bmc_main_argv[ix];
  std::cerr << std::endl;
  exit(EXIT_FAILURE);
} // end bmc_failure_at



void
bmc_parse_options(int& argc, char**argv)
{
  int constdepix= -1;
  for (;;)
    {
      int optix= -1;
      int optres = getopt_long(argc, argv, "DVSh", bmc_long_options, &optix);
      if (optres < 0)
        break;
      switch (optres)
        {
        case 'h':                     // --help
          bmc_show_usage(argv[0]);
          exit(EXIT_SUCCESS);
          break;
        case 'V':                     // --version
          bmc_show_version(argv[0]);
          exit(EXIT_SUCCESS);
          break;
        case 'D':                     // --debug
          bmc_debug_flag = true;
          break;
        case 'f':		      // --force
          bmc_force_flag = true;
          break;
        case BMCOPT_batch:            // --batch
          bmc_batch_flag = true;
          break;
        case BMCOPT_const_depend:     // --const-depend
          constdepix= optix;
          bmc_constdepend_flag = true;
          break;
        case BMCOPT_dry_run:          // --dry-run
          bmc_dryrun_flag = true;
          BMC_DEBUG("dry run - won't fork compilation commands");
          break;
        case BMCOPT_ninja:       // --ninja=PATH
          bmc_ninja_file = optarg;
          BMC_DEBUG("ninja file:" << bmc_ninja_file);
          break;
        case BMCOPT_target_gcc:       // --target-gcc=PATH
          bmc_target_gcc = optarg;
          BMC_DEBUG("target GCC:" << bmc_target_gcc);
          break;
        case BMCOPT_target_gxx:       // --target-gxx=PATH
          bmc_target_gxx = optarg;
          BMC_DEBUG("target GXX:" << bmc_target_gxx);
          break;
        case BMCOPT_output_directory: // --output-directory=DIR
          bmc_out_directory = optarg;
          BMC_DEBUG("output directory :" << bmc_out_directory);
          break;
        case BMCOPT_skip:             // --skip=XXXX
          BMC_DEBUG("skipping :" << optarg);
          break;
        case BMCOPT_onion_incldir:    // --onion-incldir=XXXX
          BMC_DEBUG("given libonion include directory :" << optarg);
          if (!bmc_dryrun_flag)
            {
              DIR* incldir = opendir(optarg);
              if (!incldir)
                {
                  std::cerr << argv[0] << " failed to opendir libonion include directory " << optarg
                            << " : " << strerror(errno) << std::endl;
                  BMC_FAILURE("failed to open libonion include directory");
                }
              else
                closedir(incldir);
            }
          break;
        case BMCOPT_onion_libdir:     // --onion-libdir=XXXX
          BMC_DEBUG("given libonion library directory :" << optarg);
          if (!bmc_dryrun_flag)
            {
              DIR* libdir = opendir(optarg);
              if (!libdir)
                {
                  std::cerr << argv[0] << " failed to opendir libonion library directory " << optarg
                            << " : " << strerror(errno) << std::endl;
                  BMC_FAILURE("failed to open libonion library directory");
                }
              else
                closedir(libdir);
            }
          break;
        }
    }
  BMC_DEBUG("constdepix=" << constdepix);
  if (constdepix>0 && constdepix<argc)
    {
      for (int kix=constdepix; kix<argc; kix++)
        {
          BMC_DEBUG("constdep kix=" << kix << ": " << argv[kix]);
          bmc_constdep_files.push_back(std::string{argv[kix]});
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
  std::cerr << " --force | -f           # force overwriting of existing generated files." << std::endl;
  std::cerr << " --batch                # dont ask for missing arguments even in terminal" << std::endl;
  std::cerr << " --dry-run              # wont fork target compilation commands" << std::endl;
  std::cerr << " --const-depend *_BM.c  # output the dependencies on #include-s *.const.h files" << std::endl;
  std::cerr << " --skip=IGNORED         # ignored argument, would appear on failure message" << std::endl;
  std::cerr << " --target-gcc=PATH      # set to PATH the target GCC compiler executable for C code" << std::endl;
  std::cerr << " --target-gxx=PATH      # set to PATH the target GCC compiler for C++ code" << std::endl;
  std::cerr << " --ninja=PATH           # generate a PATH for ninja builder - see ninja-build.org # usually --ninja=build.ninja" << std::endl;
  std::cerr << " --output-directory=DIR # set the output directory to DIR - default is " << bismon_directory << std::endl;
  std::cerr << " --onion-incldir=DIR    # set to DIR the include directory for libonion - see  www.coralbits.com/libonion" << std::endl;
  if (bismon_onion_includedir)
    std::cerr << "## known libonion include directory is " << bismon_onion_includedir << std::endl;
  std::cerr << " --onion-libdir=DIR    # set to DIR the shared library directory for libonion" << std::endl;
  if (bismon_onion_libdir)
    std::cerr << "## known libonion library directory is " << bismon_onion_libdir << std::endl;
  std::cerr << std::endl;
  std::cerr << "######## See github.com/bstarynk/bismon/ for more about BISMON." << std::endl << std::endl;
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
      BMC_FAILURE ("bad output directory (unstated)");
    }
  if (!S_ISDIR(st.st_mode))
    {
      std::cerr << progname << " has bad output directory " << bmc_out_directory
                << std::endl;
      BMC_FAILURE ("output directory is not one");
    }
  if ((st.st_mode & S_IRWXU) != S_IRWXU)
    {
      std::cerr << progname << ": output directory "  << bmc_out_directory
                << " is not rwx for user." << std::endl;
      BMC_FAILURE ("bad permission on output directory");
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
      BMC_FAILURE (forcplusplus?"missing C++ cross-compiler":"missing C cross-compiler");
    }
  for (char c: compiler)
    {
      if (!isalnum(c) && c != '_' && c != '+' && c != '-' && c != '.' && c != '/')
        {
          std::cerr << progname << ": invalid " << (forcplusplus?"C++":"C")
                    << " compiler '" << compiler << "'" << std::endl;
          std::cerr << "(only letters, digits, plus, minus, underscore, dot and slash are allowed)" << std::endl;
          BMC_FAILURE ("invalid cross-compiler");
        }
    }
  if (bmc_dryrun_flag)
    {
      std::cout << progname << " should check the target GCC compiler " << compiler << std::endl;
      std::cout << "See also http://gcc.gnu.org/ and notice that a GCC 10 compiler" << std::endl;
      std::cout << "... is required for BISMON, with plugins enabled." << std::endl;
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
          BMC_FAILURE ("popen of cross-compiler failed");
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
              BMC_FAILURE ("fgets failure on cross-compiler");
            }
          cmdstr.append(linbuf);
          if (gccversion_major==0)
            sscanf(linbuf, "gcc version %d.%d", &gccversion_major, &gccversion_minor);
        }
      BMC_DEBUG("bmc_check_target_compiler compcmd: " << compcmd << " got cmdstr " << std::endl
                << "####++++++++++++++++++++++++++++++++++++++++ " << std::endl
                << cmdstr << std::endl
                << "####---------------------------------------- " << compcmd <<std::endl);
      BMC_DEBUG("bmc_check_target_compiler gccversion_major=" << gccversion_major << ", gccversion_minor=" << gccversion_minor);
      if (gccversion_major != 10)
        {
          std::cerr << progname << ": BISMON requires a GCC 10 compiler." << std::endl ;
          if (gccversion_major > 0)
            std::cerr << "But " << compiler << " is a GCC " << gccversion_major << "." << gccversion_minor
                      << " compiler." << std::endl;
          std::cerr << "See http://gcc.gnu.org/ for more about GCC, and github.com/bstarynk/bismon for more about BISMON." << std::endl;
          std::cerr << "However " << compcmd << " gave:" << std::endl
                    << cmdstr << std::endl;
          BMC_FAILURE ("invalid GCC version");
        }
      int clcod = pclose(compilepipe);
      if (clcod != 0)
        {
          std::cerr << progname << ": compiler command " << compcmd << " pclose failure (code " << clcod << ")" << std::endl;
          BMC_FAILURE ("cross-compiler pclose failure");
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
      if (bmc_force_flag)
        {
          std::string backup = headerpath + "~";
          rename (headerpath.c_str(), backup.c_str());
        }
      else
        {
          std::cerr << progname << " has already generated " << headerpath << " (use --force option to overwrite)" << std::endl;
          return;
        }
    }
  std::ofstream headoutf (headerpath);
  if (!headoutf.good())
    {
      std::cerr << progname << " failed to open generated header " << headerpath << " : " << strerror(errno) << std::endl;
      BMC_FAILURE ("failed to open generated header");
    }
  headoutf << "/// GENERATED Bismon HEADER FILE " << headerpath << " - DO NOT EDIT" << std::endl;
  headoutf << "/// See http://github.com/bstarynk/bismon/" << std::endl;
  headoutf << "/// generated at " << bmc_start_str_ctime << " on " << bmc_hostname << std::endl;
  headoutf << "/// ... using " << __FILE__ << " git " << BISMON_SHORTGIT << std::endl
           << std::endl;
  headoutf << "#ifndef BISMON_CONFIG" << std::endl;
  headoutf << std::endl;
  headoutf << "#define BISMON_TIMESTAMP \"" << bismon_timestamp << "\"" << std::endl;
  headoutf << "#define BISMON_BUILDTIME " << bismon_timelong << std::endl;
  headoutf << "#define BISMON_DIRECTORY  \"" << bismon_directory << "\"" << std::endl;
  headoutf << "#define BISMON_CHECKSUM  \"" << bismon_checksum << "\"" << std::endl;
  headoutf << "#define BISMON_GNUMAKEFILE  \"" << bismon_gnumakefile << "\"" << std::endl;
  headoutf << "#define BISMON_GIT_ID  \"" << bismon_gitid << "\"" << std::endl;
  headoutf << "#define BISMON_SHORT_GIT_ID  \"" << bismon_shortgitid << "\"" << std::endl;
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
  if (!bmc_batch_flag && !bmc_silent_flag)
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
      if (bmc_force_flag)
        {
          std::string backup = datapath + "~";
          rename (datapath.c_str(), backup.c_str());
        }
      else
        {
          std::cerr << progname << " has already generated " << datapath << " (use --force option to overwrite)" << std::endl;
          return;
        }
    }
  std::ofstream dataoutf (datapath);
  if (!dataoutf.good())
    {
      std::cerr << progname << " failed to open generated data " << datapath << " : " << strerror(errno) << std::endl;
      BMC_FAILURE ("failed to open generated data");
    }
  dataoutf << "/// *** GENERATED Bismon DATA FILE " << datapath << " - DO NOT EDIT ***" << std::endl;
  dataoutf << "/// see github.com/bstarynk/bismon for more about Bismon." << std::endl << std::endl;
  dataoutf << "const char bismon_confdata_gitid[]=\"" << bismon_gitid << "\";" << std::endl;
  FILE*gitpipe = popen(BMC_GITLS_COMMAND, "r");
  if (!gitpipe)
    {
      std::cerr << progname << " failed to popen " BMC_GITLS_COMMAND << ":" << strerror(errno) << std::endl;
      BMC_FAILURE (BMC_GITLS_COMMAND " failed");
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
      for (int cix=0; cix<linl && gitlinbuf[cix]; cix++)
        if (!isalnum(gitlinbuf[cix]) && gitlinbuf[cix] != '_' && gitlinbuf[cix] != '/'
            && gitlinbuf[cix] != '+' && gitlinbuf[cix] != '-' && gitlinbuf[cix] != '.'
            && !strstr(gitlinbuf, "README"))
          {
            BMC_DEBUG("bmc_print_config_data bad gitlinbuf='" << gitlinbuf << "' cix=" << cix << " linl=" << linl);
            char cwdbuf[256];
            memset(cwdbuf, 0, sizeof(cwdbuf));
            if (!getcwd(cwdbuf, sizeof(cwdbuf)-1))
              cwdbuf[0] = '.';
            std::cerr << progname << " pipe " << BMC_GITLS_COMMAND << " output line#" << linenopip << ":" << gitlinbuf
                      << " - unexpected file name in directory " << cwdbuf << std::endl;
            std::cerr << "Expecting letters, digits, or one of '_/+-.' characters." << std::endl;
            BMC_FAILURE ("bad file name in directory");
          }
      struct stat curgitst;
      memset(&curgitst, 0, sizeof(curgitst));
      if (stat(gitlinbuf, &curgitst))
        {
          std::cerr << progname << " pipe " << BMC_GITLS_COMMAND << " output line#" << linenopip << ":" << gitlinbuf
                    << " - stat(2) failed:" << strerror(errno) << std::endl;
          BMC_FAILURE ("stat failed for " BMC_GITLS_COMMAND);
        }
      switch(curgitst.st_mode & S_IFMT)
        {
        case S_IFREG:
          vecgitfilepath.push_back(std::string{gitlinbuf});
          BMC_DEBUG("bmc_print_config_data git file " << gitlinbuf);
          if (linl>5 && !strcmp(gitlinbuf+linl-4, "BM.c"))
            {
              BMC_DEBUG("bmc_print_config_data git source " << gitlinbuf);
              bmc_source_files.push_back(std::string{gitlinbuf});
            }
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
          BMC_FAILURE ("unexpected git-ed file");
        } // end switch ...
    }
  while (!feof(gitpipe));
  int pclocod = pclose(gitpipe);
  if (pclocod != 0)
    {
      std::cerr << progname << " pipe " << BMC_GITLS_COMMAND << " pclose failed (code " << pclocod << ")" << std::endl;
      BMC_FAILURE (BMC_GITLS_COMMAND " failed to pclose");
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
  dataoutf << "const char*const bismonconf_git_sources[] = {" << std::endl;
  for (auto srcpath: bmc_source_files)
    dataoutf << "  \"" << srcpath << "\"," << std::endl;
  dataoutf << "  (const char*)0 }; // end bismonconf_git_sources" << std::endl;
  //
  dataoutf << std::endl << "/// end of Bismon generated data " << datapath << std::endl;
  if (!bmc_batch_flag && !bmc_silent_flag)
    std::cout << "# generated Bismon configuration data file " << datapath << std::endl;
} // end bmc_print_config_data



void
bmc_print_config_make(const char*progname)
{
  std::string makepath = bmc_out_directory + "/_bismon-config.mk";
  BMC_DEBUG("bmc_print_config_make: makepath=" << makepath);
  if (!access(makepath.c_str(), F_OK))
    {
      if (bmc_force_flag)
        {
          std::string backup = makepath + "~";
          rename (makepath.c_str(), backup.c_str());
        }
      else
        {
          std::cerr << progname << " has already generated " << makepath << " (use --force option to overwrite)" << std::endl;
          return;
        }
    }
  std::ofstream makeoutf (makepath);
  if (!makeoutf.good())
    {
      std::cerr << progname << " failed to open generated file " << makepath << " for GNU make : " << strerror(errno) << std::endl;
      BMC_FAILURE ("failed to output make configuration file");
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
  makeoutf << "BISMONMK_MAKEFILE=" << bismon_gnumakefile << std::endl;
  makeoutf << "BISMONMK_GITID=" << bismon_gitid << std::endl;
  makeoutf << "BISMONMK_SHORTGITID=" << bismon_shortgitid << std::endl;
  makeoutf << "#without BISMONMK_gtk" << std::endl;
  makeoutf << "BISMONMK_OBJECTS= $(BM_OBJECTS)" << std::endl;
  makeoutf << "BISMONMK_PACKAGES= glib-2.0 gobject-2.0 jansson readline" << std::endl;
  if (!bmc_onion_includedir.empty())
    makeoutf << "BISMONMK_ONION_INCLUDEDIR=" << bmc_onion_includedir << std::endl;
  else
    makeoutf << "#without BISMONMK_ONION_INCLUDE" << std::endl;
  if (!bmc_onion_libdir.empty())
    makeoutf << "BISMONMK_ONION_LIBDIR=" << bmc_onion_libdir << std::endl;
  else
    makeoutf << "#without BISMONMK_ONION_LIBDIR" << std::endl;
  makeoutf << "BISMONMK_EXECUTABLE= bismon" << std::endl;
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
  if (!bmc_batch_flag && !bmc_silent_flag)
    std::cout << "# generated Bismon configuration GNU make file " << makepath << std::endl;
} // end bmc_print_config_make


const int bmc_ninja_rules_lineno = __LINE__+2;
const char bmc_ninja_rules[] =
  R"NinjaRules(
# our hardcoded rules for ninja - conventionally ended by _rlBM
# see https://ninja-build.org/manual.html
###########
# compilation of _BM.c files
rule CC_rlBM
  depfile = _$out.mkd - handwritten C code
  description = CC_rlBM $out < $in (handwritten C code)
  command = $NJBM_host_cc -c $NJBM_host_warn_flags $NJBM_host_cwarn_flags $
            $NJBM_host_optim_flags $NJBM_host_debug_flags $
            $NJBM_host_prepro_flags $NJBM_pkgconfig_cflags $
               -MD -MF _$out.mkd $
               $in -o $out

# compilation of _BM.cc files - handwritten C++ code
rule CXX_rlBM
  depfile = _$out.mkd
  description = CXX_rlBM $out < $in (handwritten C++ code)
  command = $NJBM_host_cxx -c $NJBM_host_warn_flags $
            $NJBM_host_optim_flags $NJBM_host_debug_flags $
            $NJBM_host_prepro_flags $NJBM_pkgconfig_cflags $NJBM_onion_cflags $
            -MD -MF  _$out.mkd $
            $in -o $out


# compilation of generated modules/modbm_.c into a modubin/*.so shared object
rule MODCC_rlBM
  depfile = _$out.mkd
  description = MODCC_rlBM  $out < $in (generated C module)
  command = $NJBM_host_cxx -fPIC -shared $NJBM_host_warn_flags $
            $NJBM_host_optim_flags $NJBM_host_debug_flags $
            $NJBM_host_prepro_flags $NJBM_pkgconfig_cflags $NJBM_onion_cflags $
            -MD -MF  _$out.mkd $
            $in -o $out


# linking of all Bismon
rule LINKALLBISMON_rlBM
  description = LINKALLBISMON_rlBM (link everything into $out)
  command = $NJBM_host_cxx  $NJBM_host_warn_flags $
            $NJBM_host_optim_flags $NJBM_host_debug_flags $
            $in $NJBM_pkgconfig_libs $NJBM_onion_linkflags $
            -o $out

################### end of NinjaRules ###################
)NinjaRules";

// see file readline.c near line 250 of GNU readline 8
extern "C" char* rl_line_buffer;
extern "C" int rl_line_buffer_len;

void
bmc_set_readline_buffer(const std::string& str)
{
  if (str.empty())
    return;
  unsigned slen = str.size();
  unsigned roundlen = ((slen + 3) | 0xff) + 1;
  std::string oldrlbuf(rl_line_buffer?:"");
  if (rl_line_buffer)
    free(rl_line_buffer), rl_line_buffer = nullptr;
  rl_line_buffer = (char*) malloc(roundlen);
  if (!rl_line_buffer)
    BMC_FAILURE("failed to malloc rl_line_buffer");
  memset (rl_line_buffer, 0, roundlen);
  memcpy (rl_line_buffer, str.c_str(), slen);
  rl_point = 0;
  rl_line_buffer_len = roundlen;
  add_history(str.c_str());
} // end bmc_set_readline_buffer

void
bmc_print_config_ninja(const char*progname)
{
  std::string ninjapath = bmc_out_directory + "/" + bmc_ninja_file;
  BMC_DEBUG("bmc_print_config_make ninjapath=" << ninjapath);
  if (!access(ninjapath.c_str(), F_OK))
    {
      if (bmc_force_flag)
        {
          std::string backup = ninjapath + "~";
          rename (ninjapath.c_str(), backup.c_str());
        }
      else
        {
          std::cerr << progname << " has already generated " << ninjapath << " (use --force option to overwrite)" << std::endl;
          return;
        }
    }
  std::ofstream ninjaoutf (ninjapath);
  if (!ninjaoutf.good())
    {
      std::cerr << progname << " failed to open generated file " << ninjapath << " for GNU make : " << strerror(errno) << std::endl;
      BMC_FAILURE ("failed to output make configuration file");
    }
  ninjaoutf << "# GENERATED file for ninja-build.org - " << ninjapath << " - DONT EDIT" << std::endl;
  ninjaoutf << "# ... for Bismon, see https://github.com/bstarynk/bismon -*- ninja -*-" << std::endl;
  ninjaoutf << "# ... generated at " <<  bmc_start_str_ctime << " on " << bmc_hostname << std::endl;
  ninjaoutf << "# ... by " __FILE__ " git " << BISMON_SHORTGIT << std::endl << std::endl;
  ninjaoutf << "# ... invoked as:" << std::endl;
  ninjaoutf << "#| " ;
  for (int aix= 0; aix<bmc_main_argc; aix++) {
    ninjaoutf << ' ' << bmc_main_argv[aix];
    if (aix + 2 < bmc_main_argc && (aix+4) % 5 == 0)
      ninjaoutf << " \\" << std::endl << "#|  ";
  }
  ninjaoutf << std::endl << std::endl;
  ////
  ninjaoutf << "ninja_required_version= 1.10" << std::endl;
  ninjaoutf << std::endl
	    << "NJBM_short_gitid= " << bismon_shortgitid << std::endl;
  ninjaoutf << "NJBM_directory= " << bismon_directory << std::endl;
  ninjaoutf << "NJBM_make= " << bismon_make << std::endl;
  ninjaoutf << std::endl
            << "NJBM_target_gcc= " << bmc_target_gcc << std::endl
            << "NJBM_target_gxx= " << bmc_target_gxx << std::endl;
  if (bismon_packages) {
    ninjaoutf << std::endl
	      << "NJBM_pkgconfig_packages= ";
    ninjaoutf << bismon_packages << std::endl;
    BMC_DEBUG("bismon_packages= " << bismon_packages);
    /// run pkg-config --cflags
    {
      ninjaoutf << "NJBM_pkgconfig_cflags=" ;
      std::string cflpkgcmd = std::string("pkg-config --cflags ") + bismon_packages;
      FILE*pipcflpkg = popen(cflpkgcmd.c_str(), "r");
      int lineno=0;
      BMC_DEBUG("popen " << cflpkgcmd);
      if (!pipcflpkg) {
	std::ostringstream outs;
	outs << progname << " failed to popen " << cflpkgcmd << " : " << strerror(errno) << std::flush;
	BMC_FAILURE(outs.str().c_str());
      }
      char*pipcfbuf = nullptr;
      size_t pipcfsiz = 0;
      ssize_t pipcflen = -1;
      while ((pipcflen = getline(&pipcfbuf, &pipcfsiz, pipcflpkg)) >0) {
	if (lineno>0)
	  ninjaoutf << " $" << std::endl;
	lineno++;
	BMC_DEBUG("pipcfbuf='" << pipcfbuf << "', pipcflen=" << pipcflen << ", line#" << lineno);
	if (pipcflen >0 && pipcfbuf[(int)pipcflen-1] == '\n')
	  pipcfbuf[pipcflen-1] = (char)0;
	ninjaoutf << pipcfbuf;
      };
      ninjaoutf << std::endl;
      BMC_DEBUG("pclosing " << cflpkgcmd << " lineno=" << lineno);
      pclose(pipcflpkg), pipcflpkg = nullptr;
      free (pipcfbuf), pipcfbuf = nullptr;
    }
    ninjaoutf << std::endl;
    /// run pkg-config --libs
    {
      ninjaoutf << "NJBM_pkgconfig_libs=" ;
      std::string libpkgcmd = std::string("pkg-config --libs ") + bismon_packages;
      FILE*piplibpkg = popen(libpkgcmd.c_str(), "r");
      int lineno=0;
      BMC_DEBUG("popen " << libpkgcmd);
      if (!piplibpkg) {
	std::ostringstream outs;
	outs << progname << " failed to popen " << libpkgcmd << " : " << strerror(errno) << std::flush;
	BMC_FAILURE(outs.str().c_str());
      };
      char*piplibuf = nullptr;
      ssize_t piplilen = -1;
      size_t piplisiz = 0;
      while (( piplilen = getline(&piplibuf, &piplisiz, piplibpkg))>0) {
	if (lineno>0)
	  ninjaoutf << " $" << std::endl;
	lineno++;
	BMC_DEBUG("piplibuf='" << piplibuf << "', piplilen=" << piplilen);
	if (piplilen>0 && piplibuf[(int)piplilen-1] == '\n')
	  piplibuf[piplilen-1] = (char)0;
	ninjaoutf << piplibuf;
      };
      BMC_DEBUG("pclosing " << libpkgcmd << " lineno=" << lineno);
      pclose(piplibpkg), piplibpkg = nullptr;
      free (piplibuf), piplibuf = nullptr;
      ninjaoutf << std::endl;
    }
  }
  else {
    ninjaoutf << "# no bismon_packages" << std::endl
	      << "NJBM_pkgconfig_packages =" << std::endl
	      << "NJBM_pkgconfig_cflags =" << std::endl << "NJBM_pkgconfig_libs =" << std::endl;    
  };
  ninjaoutf << std::endl;
  BMC_DEBUG("handled bismon_packages= " << bismon_packages);
  if (bismon_onion_includedir && bismon_onion_includedir[0])
    ninjaoutf << "NJBM_onion_cflags= -I " << bismon_onion_includedir << std::endl;
  else
    ninjaoutf << "NJBM_onion_cflags =" << std::endl;
  if (bismon_onion_libdir && bismon_onion_libdir[0]) {
    ninjaoutf << "NJBM_onion_linkflags= -L" << bismon_onion_libdir << " -lonion" << std::endl;
  }
  else
    ninjaoutf << "NJBM_onion_linkflags =" << std::endl;
  ninjaoutf << std::endl;
  ninjaoutf << "NJBM_host_cc= "
	    << (getenv("CC")?:"gcc") << std::endl;
  ninjaoutf << "NJBM_host_cxx= "
	    << (getenv("CXX")?:"g++") << std::endl;
  ninjaoutf << "NJBM_host_optim_flags= -O" << std::endl;
  ninjaoutf << "NJBM_host_prepro_flags= -I/usr/local/include " << std::endl;
  ninjaoutf << "NJBM_host_debug_flags= -g" << std::endl;
  ninjaoutf << "NJBM_host_warn_flags= -Wall -Wextra" << std::endl;
  ninjaoutf << "NJBM_host_cwarn_flags= -Wmissing-prototypes" << std::endl;
  ninjaoutf << std::endl;
  ///////////////////////////////////////////
  ///// output ninja rules
  std::vector<std::string> objectvect;
  ninjaoutf << "# hardcoded rules from " << __FILE__ << ":" << bmc_ninja_rules_lineno << std::endl;
  ninjaoutf << "#+++++++++++++++++++++++++++" << std::endl;
  ninjaoutf << bmc_ninja_rules << std::endl;
  ninjaoutf << "#--------------------------- from "
	    << __FILE__ ":" << __LINE__
	    << std::endl << std::endl << std::endl;

  ninjaoutf << "# build " << bismon_source_number
	    << " object files :::::::::" << std::endl;
  ninjaoutf << "# .... from " << __FILE__ << ":" << __LINE__ << std::endl;
  BMC_DEBUG("bismon_source_number = " << bismon_source_number);
  int nbsrc = 0;
  for (const char*const* pcursrc = bismon_sources; *pcursrc; pcursrc++) {
    std::string cursrc (*pcursrc);
    auto curlen = cursrc.size();
    BMC_DEBUG("cursrc='" << cursrc << "' curlen=" << curlen
	      << " sizeof(\"_BM.c\")=" << sizeof("_BM.c"));
    if (curlen > sizeof("_BM.c")
	&& cursrc.substr(curlen+1-sizeof("_BM.c")) == std::string("_BM.c")) {
      std::string curobp = cursrc;
      curobp[curlen-1] = 'o';
      BMC_DEBUG("_BM source cursrc='" << cursrc
		<< "', curobp='" << curobp << "'");
      ninjaoutf << "build " << curobp << ": CC_rlBM " << cursrc
		<< std::endl << std::endl;
      objectvect.push_back(std::string{curobp});
      nbsrc++;
    }
    if (curlen > sizeof("_BM.cc")
	&& cursrc.substr(curlen+1-sizeof("_BM.cc")) == std::string("_BM.cc")) {
      std::string curobp = cursrc;
      curobp[curlen-2] = 'o';
      curobp.resize(curlen-1);
      BMC_DEBUG("_BM source cursrc='" << cursrc
		<< "', curobp='" << curobp << "'");
      ninjaoutf << "build " << curobp << ": CXX_rlBM " << cursrc
		<< std::endl << std::endl;
      nbsrc++;
      objectvect.push_back(std::string{curobp});
    }
  }
  BMC_DEBUG("has " << nbsrc
	    << " C or C++ source files, with bismon_source_number = "
	    << bismon_source_number);
  ninjaoutf << std::endl << "## building bismon executable - object files:"
	    << std::endl;
  {
    int nbob = 0;
    ninjaoutf << "NJBM_object_files=";
    for (auto curob: objectvect) {
      nbob++;
      if (nbob%4 == 0)
	ninjaoutf << " $" << std::endl << " ";
      ninjaoutf << " " << curob;
    }
    ninjaoutf << std::endl;
  }
  ninjaoutf << std::endl << "## building the bismon executable itself:"
	    << std::endl;
  ninjaoutf << "build bismon: LINKALLBISMON_rlBM $"
	    << std::endl;
  {
    int nbob = 0;
    for (auto curob: objectvect) {
      nbob++;
      if (nbob%4 == 0)
	ninjaoutf << " $" << std::endl << " ";
      ninjaoutf << " " << curob;
    }
    ninjaoutf << std::endl;
  }
  ninjaoutf << "## perhaps incomplete bmc_print_config_ninja " << __FILE__ << ":" << __LINE__ << std::endl;
  std::cerr << progname << " maybe incomplete bmc_print_config_ninja ninjapath=" << ninjapath << std::endl;
  BMC_DEBUG("maybe incomplete bmc_print_config_ninja");
} // end bmc_print_config_ninja



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
      BMC_FAILURE ("readline failure");
    }
  return ans;
} // end bmc_readline

void
bmc_ask_missing_configuration(const char*progname)
{
  BMC_DEBUG("bmc_ask_missing_configuration start progname=" << progname);
  assert (!bmc_batch_flag);
  using_history();
  /// ask about target GCC compilers for C and for C++
  while (bmc_target_gcc.empty())
    {
      std::cout << "Target Bismon GCC [cross-]compiler for C code. Should be at least a GCC 10."
		<< std::endl << "... See gcc.gnu.org for more about GCC...." << std::endl;
      std::cout << "(it is preferable to enter some absolute path, such as /usr/local/bin/gcc-10 ..." << std::endl;
      std::cout << "... but that cross-C-compiler could be some script." << std::endl;
      if (!access("/usr/bin/gcc-10", X_OK) && isatty(STDOUT_FILENO)) {
	std::cout << "... Found some /usr/bin/gcc-10)" << std::endl;
	BMC_DEBUG("defaulting target GCC to /usr/bin/gcc-10");
	bmc_set_readline_buffer("/usr/bin/gcc-10");
      }
      else
	std::cout << ")" << std::endl;
      const char*gcctarget = bmc_readline(progname, "BISMON target GCC? ");
      if (gcctarget)
        {
          if (access(gcctarget, R_OK))
            std::cerr << progname << ": WARNING: target GCC " << gcctarget
                      << " is not accessible: " << strerror(errno) << std::endl;
          bmc_target_gcc.assign(gcctarget);
          add_history(gcctarget);
          free ((void*)gcctarget), gcctarget = nullptr;
        }
    }
  std::cout << ")" << std::endl<< std::endl;
  while (bmc_target_gxx.empty())
    {
      std::cout << "Target Bismon GCC [cross-]compiler for C++ code. Should be at least a GCC 10."
		<< std::endl << "... See gcc.gnu.org for more about GCC...." << std::endl;
      std::cout << "(it is recommended to enter some absolute path, such as /usr/local/bin/g++-10 ..." << std::endl;
          std::cerr << "... but that cross C++ compiler could be some script." << std::endl;
      if (!access("/usr/bin/g++-10", X_OK) && isatty(STDOUT_FILENO)) {
	std::cout << "... Found some /usr/bin/g++-10)" << std::endl;
	BMC_DEBUG("defaulting target GXX to /usr/bin/g++-10");
	bmc_set_readline_buffer("/usr/bin/g++-10");
      }
      else
	std::cout << ")" << std::endl;
      const char*gxxtarget = bmc_readline(progname, "BISMON target GXX? ");
      if (gxxtarget)
        {
          if (access(gxxtarget, R_OK))
            std::cerr << progname << ": WARNING: target GXX " << gxxtarget
                      << " is not accessible: " << strerror(errno) << std::endl;
          bmc_target_gxx.assign(gxxtarget);
          add_history(gxxtarget);
          free ((void*)gxxtarget), gxxtarget = nullptr;
        }
    }
  std::cout << std::endl;
  //////////////////////////////
  /// ask about the libonion - see www.coralbits.com/libonion/ and github.com/davidmoreno/onion
  /// libonion include header - with onion/onion.h
  if (bmc_onion_includedir.empty() || bmc_onion_libdir.empty()) {
    std::cout << std::endl;
    std::cout << "BISMON needs the libonion web server (HTTP+HTTPS) library." << std::endl;
    std::cout << "See www.coralbits.com/libonion and github.com/davidmoreno/onion for more." << std::endl;
  }
  while (bmc_onion_includedir.empty()) {
    std::cout << "Include directory for libonion ; it should contain the <onion/onion.h> header file."
	      << std::endl;
    if (!access("/usr/local/include/onion/onion.h", R_OK) && isatty(STDOUT_FILENO)) {
      std::cout << "... Found /usr/local/include/onion/onion.h" << std::endl;
      BMC_DEBUG("defaulting libonion header directory to /usr/local/include");
      bmc_set_readline_buffer("/usr/local/include");
    }
    else if (!access("/usr/include/onion/onion.h", R_OK) && isatty(STDOUT_FILENO)) {
      std::cout << "... Found /usr/include/onion/onion.h" << std::endl;
      BMC_DEBUG("defaulting libonion header directory to /usr/include");
      bmc_set_readline_buffer("/usr/include");
    }
    const char*onionincl = bmc_readline(progname, "Libonion included-header directory? ");
    if (onionincl && strlen(onionincl)>2) {
      std::string stronionincl(onionincl);
      if (stronionincl[stronionincl.size()-1] != '/')
	stronionincl += "/";
      BMC_DEBUG("stronionincl='" << stronionincl << "'");
      std::string onionh = stronionincl+"onion/onion.h";
      if (!access(onionh.c_str(), R_OK)) {
	bmc_onion_includedir = stronionincl;
	BMC_DEBUG("setting bmc_onion_includedir to " << stronionincl);
      } else
	std::cerr << "Wrong libonion include dir " << stronionincl << " since " << onionh << " cannot be read."
		  << std::endl;
    }
  } // end while bmc_onion_includedir.empty()
#warning  bmc_onion_include should be kept from a previous configuation
  /////////////
  /// libonion library directory, with libonion.so
  while (bmc_onion_libdir.empty()) {
    std::cout << "library directory for libonion ; it should contain the libonion.so shared object."
	      << std::endl;
    if (!access("/usr/local/lib/libonion.so", R_OK) && isatty(STDOUT_FILENO)) {
      std::cout << "... Found /usr/local/lib/libonion.so" << std::endl;
      BMC_DEBUG("defaulting libonion library directory to /usr/local/lib");
      bmc_set_readline_buffer("/usr/local/lib");
    }
    else if (!access("/usr/lib/libonion.so", R_OK) && isatty(STDOUT_FILENO)) {
      std::cout << "... Found /usr/lib/libonion.so" << std::endl;
      BMC_DEBUG("defaulting libonion library directory to /usr/lib");
      bmc_set_readline_buffer("/usr/lib");
    }
    const char*onionlib = bmc_readline(progname, "Libonion shared library directory? ");
    if (onionlib && strlen(onionlib)>2) {
      std::string stronionlib(onionlib);
      if (stronionlib[stronionlib.size()-1] != '/')
	stronionlib += "/";
      BMC_DEBUG("stronionlib='" << stronionlib << "'");
      std::string onionlib = stronionlib+"libonion.so";
      if (!access(onionlib.c_str(), R_OK)) {
	bmc_onion_libdir = stronionlib;
	BMC_DEBUG("setting bmc_onion_libdir to " << stronionlib);
      } else
	std::cerr << "Wrong libonion shared library directory " << stronionlib
		  << " since " << onionlib << " cannot be read."
		  << std::endl;
    }
  } // end while bmc_onion_libdir.empty()
#warning  bmc_onion_libdir should be kept from a previous configuation
  ////////////////////////
  /// ask about the output directory, into which files would be written
  char cwdbuf[256];
  memset (cwdbuf, 0, sizeof(cwdbuf));
  std::cout << std::endl;
  errno = 0;
  if (!getcwd(cwdbuf, sizeof(cwdbuf)-1))
    {
      std::cerr << progname << ": failed to getcwd - " << strerror(errno) << std::endl;
      BMC_FAILURE ("getcwd failure");
    }
  while (bmc_out_directory.empty())
    {
      std::cout << "BISMON output source directory. If none is given, defaults to current directory " << cwdbuf << std::endl;
      std::cout << "This configurator " << progname << " will write some textual files -a header file and a Makefile fragment- in it." << std::endl;
      std::cout << "(it is recommended to enter some absolute path, such as /usr/src/Bismon or /home/foo/bismon ....)" << std::endl;
      const char*outdir = bmc_readline(progname, "BISMON output sourcedir? ");
      if (outdir[0])
        {
          DIR* outdirhdl = opendir(outdir);
          if (outdirhdl)
            closedir(outdirhdl);
          else
            std::cerr << progname << ": WARNING: cannot opendir " << outdir
                      << " : " << strerror(errno) << std::endl;
          bmc_out_directory.assign(outdir);
        }
      else
        bmc_out_directory.assign(cwdbuf);
      free ((void*)outdir), outdir = nullptr;
    }
  std::cout << std::endl;
  clear_history();
} // end bmc_ask_missing_configuration


void
bmc_scan_for_const_dependencies(const char*progname, const std::string&filnam, int rk)
{
  BMC_DEBUG("bmc_scan_for_const_dependencies start " << filnam << " #" << rk);
  int curlineno = 0;
  std::string objfilnam = filnam;
  int filnamlen = filnam.size();
  if (filnamlen > 3 && objfilnam[filnamlen-2] == '.' && objfilnam[filnamlen-1] == 'c')
    objfilnam[filnamlen-1] = 'o';
  FILE* fil = fopen(filnam.c_str(), "r");
  if (!fil)
    {
      std::cerr << progname << ": failed to fopen #" << rk << " " << filnam << ":" << strerror(errno) << std::endl;
      BMC_FAILURE ("source file fopen failure");
    }
  BMC_DEBUG("bmc_scan_for_const_dependencies " << filnam << " #" << rk << " object file:" << objfilnam);
  int nbdep=0;
  std::cout << std::endl << objfilnam << ":";
  do
    {
      char linbuf[80];
      memset(linbuf, 0, sizeof(linbuf));
      if (!fgets(linbuf, sizeof(linbuf), fil))
        break;
      curlineno ++;
      if (curlineno > 128)
        break;
      int eol= -1;
      char pathbuf[64];
      memset(pathbuf, 0, sizeof(pathbuf));
      if (sscanf(linbuf, "# include \"%60[a-zA-Z0-9._]\"%n", pathbuf, &eol)<1 || eol<=0)
        continue;
      BMC_DEBUG("bmc_scan_for_const_dependencies " << filnam << ":" << curlineno << " pathbuf=" << pathbuf);
      if (strstr(pathbuf, "_BM.const.h"))
        {
          nbdep++;
          std::cout << " " << pathbuf << std::flush;
        }
    }
  while (!feof(fil));
  fclose(fil);
  std::cout << std::endl << std::endl;
  BMC_DEBUG("bmc_scan_for_const_dependencies end " << filnam << " #" << rk << " with " << nbdep << " dependencies." << std::endl);
} // end bmc_scan_for_const_dependencies



void
bmc_print_const_dependencies(const char*progname)
{
  BMC_DEBUG("bmc_print_const_dependencies start progname=" << progname << " ESHELL=" << (getenv("ESHELL")?:"**none**")
            << " " << bmc_constdep_files.size() << " files");
  if (!bmc_batch_flag || !bmc_silent_flag)
    std::cout << "# constant dependencies for GNU make by " << progname << std::endl;
  int i=0;
  for (auto cdstr : bmc_constdep_files)
    {
      i++;
      BMC_DEBUG("bmc_print_const_dependencies [" << i << "]:" << cdstr);
      bmc_scan_for_const_dependencies(progname, cdstr, i);
    }
  if (!bmc_batch_flag || !bmc_silent_flag)
    std::cout << "# emitted " << i << " constant dependencies for GNU make." << std::endl;
  BMC_DEBUG("bmc_print_const_dependencies end progname=" << progname << std::endl);
} // end bmc_print_const_dependencies


int
bmc_initialize_global_variables(const char*progname)
{
  int nbinit=0;
  if (bismon_make && bismon_make[0]) {
    bmc_make = std::string(bismon_make);
    BMC_DEBUG("bmc_make initialized to " << bmc_make);
    nbinit++;
  };
  if (bismon_packages && bismon_packages[0]) {
    bmc_packages = std::string(bismon_packages);
    BMC_DEBUG("bmc_packages initialized to " << bmc_packages);
    nbinit++;
  };
  if (bismon_target_gcc && bismon_target_gcc[0]) {
    bmc_target_gcc = std::string(bismon_target_gcc);
    BMC_DEBUG("bmc_target_gcc initialized to " << bmc_target_gcc);
    nbinit++;
  };
  if (bismon_target_gxx && bismon_target_gxx[0]) {
    bmc_target_gxx = std::string(bismon_target_gxx);
    BMC_DEBUG("bmc_target_gxx initialized to " << bmc_target_gcc);
    nbinit++;
  };
  if (bismon_onion_includedir && bismon_onion_includedir[0]) {
    std::string onincdir(bismon_onion_includedir);
    if (onincdir[onincdir.size()-1] != '/')
      onincdir += "/";
    if (!access((onincdir+"onion/onion.h").c_str(), R_OK)) {
      bmc_onion_includedir = std::string(bismon_onion_includedir);
      BMC_DEBUG("bmc_onion_includedir initialized to " << bmc_onion_includedir);
      nbinit++;
    }
  };
  if (bismon_onion_libdir && bismon_onion_libdir[0]) {
    std::string onlibdir(bismon_onion_libdir);
    if (onlibdir[onlibdir.size()-1] != '/')
      onlibdir += "/";
    if (!access((onlibdir+"libonion.so").c_str(), R_OK)) {
      bmc_onion_libdir = std::string(bismon_onion_libdir);
      BMC_DEBUG("bmc_onion_includedir initialized to " << bmc_onion_includedir);
      nbinit++;
    }
  };
  BMC_DEBUG("bmc_initialize_global_variables did " << nbinit << " initializations for " << progname << std::endl);
  return nbinit;
} // end bmc_initialize_global_variables




int
main (int argc, char**argv)
{
  bmc_main_argc = argc;
  bmc_main_argv = argv;
  bmc_start_time = time(nullptr);
  bool earlydebug = false;
  int nbinit= 0;
  if (argc>1 && (!strcmp(argv[1], "-D") || !strcmp(argv[1], "--debug")))
    {
      bmc_debug_flag = true;
      earlydebug = true;
      if (isatty(STDOUT_FILENO))
        {
          std::cout << std::endl << std::endl << "***** " BMC_BOLD_ESCAPE "BISMON Debugged Configurator" BMC_PLAIN_ESCAPE " ****" << std::endl;
        }
      usleep (1024*8);
    }
  gethostname(bmc_hostname, sizeof(bmc_hostname)-1);
  {
    bmc_start_time = time(nullptr);
    char timbuf[64];
    memset (timbuf, 0, sizeof(timbuf));
    struct tm start_tm = {};
    strftime (timbuf, sizeof(timbuf), "%Y %b %d, %H:%M:%S %Z",
	      localtime_r(&bmc_start_time, &start_tm));
    bmc_start_str_ctime = std::string(timbuf);
  }
  if (isatty(STDOUT_FILENO)) {
    rl_initialize();		// initialize GNU readline;
    using_history();
  }
  nbinit = bmc_initialize_global_variables (argv[0]);
  bmc_parse_options(argc, argv);
  const char* makelevel = getenv("MAKELEVEL");
  if (getenv("ESHELL") && isatty(STDOUT_FILENO) && !bmc_silent_flag) {
      if (!earlydebug)
        std::cout << std::endl << std::endl << "***** BISMON Configurator (emacs-ed ESHELL="
		  << getenv("ESHELL")
		  << ", pid " << (int)getpid()
		  << ", ppid " << (int)getppid()
		  << ") ****" << std::endl;
  }
  else if (isatty(STDOUT_FILENO) && !bmc_silent_flag)
    {
      if (!earlydebug && !getenv("ESHELL"))
        std::cout << std::endl << std::endl << "***** " BMC_BOLD_ESCAPE "BISMON Configurator" BMC_PLAIN_ESCAPE " ****" << std::endl;
      std::cout << " pid " << (int)getpid() << ", ppid " << (int)getppid();
      std::cout
          << std::endl << "(this program " << argv[0] << " uses GNU readline, so you could use the <tab> key is for autocompletion," << std::endl;
      std::cout << "... and your input lines are editable.  For more about GNU readline, see www.gnu.org/software/readline ...)" << std::endl;
    };
  if (makelevel != nullptr) {
    int mklev = atoi(makelevel);
    if (mklev>2) {
      std::cerr << argv[0] << " is running with MAKELEVEL at " << mklev << " so exiting quickly." << std::endl;
      exit (EXIT_SUCCESS);
    }
  }
  if (isatty(STDOUT_FILENO) && !bmc_silent_flag) {
    std::cout << "For more about BISMON, see github.com/bstarynk/bismon ...."
	      << std::endl
	      << "... and perhaps the *DRAFT* report on starynkevitch.net/Basile/bismon-chariot-doc.pdf" << std::endl;
    std::cout << "For more about GCC, see gcc.gnu.org ...." << std::endl;
    std::cout << "# running " << __FILE__ " @"  __DATE__ << " on " << bmc_hostname << " pid " << (int)getpid()
	      << " parentpid " << (int)getppid() << std::endl;
    if (nbinit)
      std::cout << "# " << nbinit << " variables initialized from previous __timestamp.c ..." << std::endl;
    std::cout << "# " << argv[0] << " git " << BISMON_SHORTGIT << " started on " << bmc_start_str_ctime << std::endl;
    /// show some information on parent process executable
    {
      char ppidbuf[48];
      memset (ppidbuf, 0, sizeof(ppidbuf));
      snprintf (ppidbuf, sizeof(ppidbuf), "/proc/%d/exe", (int)getppid());
      char parprogbuf[64];
      memset (parprogbuf, 0, sizeof(parprogbuf));
      auto parentrl = readlink(ppidbuf, parprogbuf, sizeof(parprogbuf));
      if (parentrl > 0 && parentrl < (ssize_t) sizeof(parprogbuf)) {
	std::cout << argv[0] << " parent process " << getppid()
		  << " is running " << parprogbuf;
	if (makelevel)
	  std::cout << " with MAKELEVEL=" << makelevel;
	std::cout << std::endl;
      }
    }
    /// show some information on parent process status and about grand parent process executable
    {
      char ppidbuf[48];
      memset (ppidbuf, 0, sizeof(ppidbuf));
      snprintf (ppidbuf, sizeof(ppidbuf), "/proc/%d/stat", (int)getppid());
      FILE *ppf = fopen(ppidbuf, "r");
      if (ppf) {
	char ppidstat[64];
	memset (ppidstat, 0, sizeof(ppidstat));
	char *statlin = fgets(ppidstat, sizeof(ppidstat), ppf);
	if (statlin) {
	  std::cout << argv[0] << " parent process " << getppid() << " stat file has " << statlin << std::endl;
	  char parcmd[64];
	  memset(parcmd, 0, sizeof(parcmd));
	  int curpid= -1;
	  int grandparentpid= -1;
	  char grandparstat=0;
	  if (sscanf(statlin, "%d (%60[a-zA-Z0-9_/.]) %c %d", &curpid, parcmd, &grandparstat, &grandparentpid) > 2 && grandparentpid>0) {
	    char grparprogbuf[64];
	    memset (grparprogbuf, 0, sizeof(grparprogbuf));
	    snprintf (grparprogbuf, sizeof(grparprogbuf), "/proc/%d/exe", grandparentpid);
	    char grparexe[80];
	    memset(grparexe, 0, sizeof(grparexe));
	    auto grparentrl = readlink(grparprogbuf, grparexe, sizeof(grparexe));
	    if (grparentrl >0 && strlen(grparexe)>0) {
	      std::cout << argv[0] << " grand parent process " << grandparentpid << " of status " << grandparstat
			<< " is running " << grparexe
			<< std::endl;
	      char grparcmdbuf[64];
	      memset (grparcmdbuf, 0, sizeof(grparcmdbuf));
	      snprintf (grparcmdbuf, sizeof(grparcmdbuf), "/proc/%d/cmdline", grandparentpid);
	      FILE* fcmd = fopen(grparcmdbuf, "r");
	      if (fcmd) {
		char grparcmdline[256];
		memset(grparcmdline, 0, sizeof(grparcmdline));
		size_t grparcmdlen = fread(grparcmdline, 1, sizeof(grparcmdline)-1, fcmd);
		if (grparcmdline[0] && strlen(grparcmdline) < sizeof(grparcmdline)-1) {
		  for (int i=0; i<(int)grparcmdlen; i++)
		    if (grparcmdline[i]==(char)0)
		      grparcmdline[i]=' ';
		  std::cout << argv[0] << " grand parent process " << grandparentpid << " command is "
			    << grparcmdline << std::endl;
		}
		fclose(fcmd);
	      }
	    }
	  }
	}
	else
	  perror(ppidbuf);
	fclose (ppf);
      }
      else
	perror(ppidbuf);
    }
  }
  if (isatty(STDOUT_FILENO) && !bmc_silent_flag) {
    usleep (1000);
    std::cout << "This " << argv[0] << " program is, like BISMON, GPLv3+ licensed so *WITHOUT ANY WARRANTY*." << std::endl;
    std::cout << "... see www.gnu.org/licenses/gpl-3.0.en.html for details." << std::endl;
  }
  usleep(1024*16);
  if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO)
      && !bmc_batch_flag && !bmc_constdepend_flag)
    bmc_ask_missing_configuration(argv[0]);
  if (bmc_out_directory.empty())
    bmc_out_directory = bismon_directory;
  if (!bmc_constdepend_flag)
    {
      bmc_check_output_directory(argv[0]);
      bmc_check_target_compiler(argv[0], false); // for C
      bmc_check_target_compiler(argv[0], true);  // for C++
    };
  if (!bmc_silent_flag)
    {
      std::cout
	<<  "#| Output generated by " __FILE__ " git " << BISMON_SHORTGIT << " - DONT EDIT" << std::endl
	<<  "#| Generated at " << bmc_start_str_ctime << " on " << bmc_hostname << std::endl
	<<  "#| See github.com/bstarynk/bismon for more.  Invocation was:"
	<< std::endl;
      std::cout << "#|";
      for (int ix=0; ix < argc; ix++)
        {
          if (ix+2 < argc && (ix+1) % 4 == 0)
            std::cout << std::endl << "#|...";
          std::cout << ' ' << argv[ix];
        }
      std::cout << std::endl << std::endl;
    }
  if (!bmc_dryrun_flag)
    {
      bmc_print_config_header(argv[0]);
      bmc_print_config_data(argv[0]);
      /// should be last, since depends upon git directory parsing above
      bmc_print_config_make(argv[0]);
      if (bmc_constdepend_flag)
        bmc_print_const_dependencies(argv[0]);
      if (!bmc_ninja_file.empty())
        bmc_print_config_ninja(argv[0]);
    }
  if (isatty(STDIN_FILENO) && !bmc_batch_flag && !bmc_silent_flag)
    {
      std::cout << "### See also refpersys.org for another free software project."
                << std::endl << std::endl;
    }
  return 0;
} // end function main


// end of file BISMON-config.cc
