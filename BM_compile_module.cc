// file BM_compile_module.cc
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
#include "id_BM.h"

int
main(int argc, char**argv)
{
  try {
#warning incomplete BM_compile_module, see Makefile
  /* we should use syslog and the $BISMON_CXX variable, etc... */
  } catch (std::exception& exc) {
    std::string msg{"FAILURE OF"};
    std::clog << "failure of ";
    for (int i=0; i<argc; i++) {
      std::clog << ' ' << argv[i];
      msg += " ";
      msg += argv[i];
    }
    std::clog << std::endl;
    std::clog << "pid " << (long) getpid() << " got exception:" << exc.what() << std::endl;
    abort();
  };
} // end main


//// end of file  BM_compile_module.cc
