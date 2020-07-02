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
    syslog(LOG_ERR, "%s: got exception: %s (git id %s)", argv[0], msg.c_str(), bismon_shortgitid);
    abort();
  };
} // end main


//// end of file  BM_compile_module.cc
