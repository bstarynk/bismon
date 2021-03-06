// file BM_compmod.hh on https://github.com/bstarynk/bismon/
// SPDX-License-Identifier: GPL-3.0-or-later

/***
    BISMON
    Copyright © 2020 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
    contributed by Basile Starynkevitch (working at CEA, LIST, France)
    <basile@starynkevitch.net> or <basile.starynkevitch@cea.fr>

    BM_compile_module: a standalone program to compile a BISMON
    generated module or GCC plugin. This file BM_compmod.hh is the
    common header file.

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

#ifndef BM_COMPMOD_INCLUDED_
#define BM_COMPMOD_INCLUDED_ 1

#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif


extern "C" {
#include <unistd.h>
#include <syslog.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
};

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <set>
#include <map>
#include <string>
#include <functional>
#include <cassert>


#include <libguile.h>
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

extern "C" void bmc_parse_options(int& argc, char**argv);
extern "C" void bmc_show_usage(const char*progname);
extern "C" void bmc_show_version(const char*progname);
extern "C" void* bmc_run_guile(void*);

extern "C" std::vector<std::string> bmc_guile_vec;
extern "C" std::map<std::string,std::string> bmc_param_map;

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


inline
std::ostream&operator << (std::ostream&out, std::function<void(std::ostream&)> f) {
  f(out);
  return out;
}
#define BMC_OUT(Out,...) [&](std::ostream& Out){__VA_ARGS__;}

#endif /*BM_COMPMOD_INCLUDED_*/

// eof BM_compmod.hh
