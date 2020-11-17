## the Bismon GNUmakefile
## SPDX-License-Identifier: GPL-3.0-or-later
## GPLv3+ licensed, from http://github.com/bstarynk/bismon
# 
#    BISMON 
#   Copyright © 2018 - 2020 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
#   contributed by Basile Starynkevitch.
#
#   This program is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
#---
#   Contact me (Basile Starynkevitch) by email
#   basile@starynkevitch.net and/or basile.starynkevitch@cea.fr
######
# for GNU make only, see https://www.gnu.org/software/make

GCC= gcc
GXX= g++
CC= $(GCC)
MARKDOWN= markdown
INDENT= indent
ASTYLE= astyle
MD5SUM= md5sum
INDENTFLAGS= --gnu-style --no-tabs --honour-newlines
ASTYLEFLAGS= --style=gnu -s2
RM= rm -fv
BM_CXX_STANDARD_FLAGS= -std=gnu++17

## CONVENTION: handwritten markdown files are...
MARKDOWN_SOURCES= $(sort $(wildcard *.md))

## CONVENTION: generated C files are
BM_GENMODULES_CSOURCES= $(sort $(wildcard modules/modbm*.c))

## CONVENTION: generated C++ files are
BM_GENMODULES_CXXSOURCES= $(sort $(wildcard modules/modbm*.cc))

## CONVENTION: handwritten headers are...
BM_HEADERS= $(wildcard [a-z]*BM.h bismon.h)

## CONVENTION: handwritten C files are...
BM_CSOURCES= $(wildcard [a-z]*_BM.c)

## CONVENTION: handwritten C++ files are...
BM_CXXSOURCES= $(wildcard [a-z]*_BM.cc)

## CONVENTION: packages for pkg-config
BM_PACKAGES=  glib-2.0 gtk+-3.0 gtkmm-2.0

## CONVENTION: potential options for BISMON-config configurator. Could
## be overwritten by command line...
BISMON_CONFIG_OPTIONS=

### object files:
BM_OBJECTS= $(patsubst %.c,%.o,$(BM_CSOURCES))  $(patsubst %.c,%.o,$(BM_CXXSOURCES))

## internal make variables...
BISMON_SHGIT1:= $(shell  git log --format=oneline -q -1 | cut '-d '  -f1 | tr -d '\n' | head -c16)
BISMON_SHGIT2:= $(shell if git status | grep 'nothing to commit' > /dev/null; then echo ; else echo +; fi)

## The short git id, such as 34ae25e8127fc354 (for a clean source)
## or 3ae25e8127fc354d+ (for some edited source tree)
BISMON_SHORT_GIT:= $(BISMON_SHGIT1)$(BISMON_SHGIT2)

.PHONY: all config count executable clean runconfig

.DEFAULTS: all

config: _bismon-config.mk _bm_config.h  _bm_config.c

## include _bismon-config.mk only if it exists.
ifeq ($(strip $(wildcard _bismon-config.mk)),_bismon-config.mk)
-include _bismon-config.mk
endif


### the configurator program
BISMON-config: BISMON-config.cc __timestamp.o
	@echo Building BISMON-config using BISMON_SHORTGIT=$(BISMON_SHORT_GIT)
	@bash -c "if [ -f $@ ] ; then mv -v $@ $@~ ; fi"
	$(GXX) $(BM_CXX_STANDARD_FLAGS) '-DBISMON_SHORTGIT="$(BISMON_SHORT_GIT)"' -Wall -Wextra -O -g $^ -lreadline  -o $@


ifeq ($(MAKELEVEL),0)
_bismon-config.mk _bm_config.h _bm_config.c: BISMON-config.cc
	sleep 0.05
	if [ ! -x ./BISMON-config ]; then bash -x -c '$(MAKE)  ./BISMON-config' ; fi
	sleep 0.1
	$(MAKE) runconfig
else
_bismon-config.mk _bm_config.h _bm_config.c:
	sleep 0.3
	$(MAKE) runconfig
endif

runconfig: BISMON-config
	./BISMON-config $(BISMON_CONFIG_OPTIONS)

count:
	@wc -cl $(wildcard *.c *.h *.cc modules/_*.c) | sort -n

clean:
	$(RM) *.o BISMON-config BM_makeconst bismon _bm_config.h _bm_config.c  modubin/*.so modubin/*.o *~ *% *.cc.orig
	$(RM) _*.mkd _*conf*.mk

BM_makeconst_dbg: BM_makeconst-g.o id_BM-g.o
	$(CXX)  -std=gnu++14 -g -Wall -Wextra   BM_makeconst-g.o id_BM-g.o $(shell pkg-config --libs glib-2.0) -o $@

BM_makeconst: BM_makeconst.cc id_BM.o | id_BM.h
	$(LINK.cc) -std=gnu++14 -O -g -Wall  -Wextra BM_makeconst.cc id_BM.o  $(shell pkg-config --cflags --libs glib-2.0) -o $@

BM_makeconst-g.o: BM_makeconst.cc id_BM.h
	$(COMPILE.cc) -std=gnu++14   $(shell pkg-config --cflags glib-2.0) -g -Wall -c $< -o $@

id_BM.o: id_BM.c id_BM.h
	$(COMPILE.c)  $(shell pkg-config --cflags glib-2.0) -O -g -Wall -Wextra -c $< -o $@
id_BM-g.o: id_BM.c id_BM.h
	$(COMPILE.c)  $(shell pkg-config --cflags glib-2.0) -g -Wall -Wextra -c $< -o $@

%_BM.o: %_BM.c bismon.h | BISMON-config BM_makeconst
	@echo building $@ from $^
	@echo should $(MAKE) bismon.h $(shell ./BISMON-config --const-depend $^)
	$(MAKE) bismon.h  $(shell ./BISMON-config --const-depend $^)
	$(COMPILE.c) $(shell pkg-config --cflags $(BISMONMK_PACKAGES)) -MM -MF $(patsubst %.o, _%.mkd, $@) -Wall -c $< -o $@

%_BM-g.o: %_BM.c bismon.h | BISMON-config BM_makeconst
	$(MAKE) bismon.h $(shell ./BISMON-config --const-depend $^)
	$(COMPILE.c) $(shell pkg-config --cflags $(BISMONMK_PACKAGES)) -MM -MF $(patsubst %.o, _%-g.mkd, $@)  -g -Wall -c $< -o $@

__timestamp.c:  timestamp-emit.sh |  GNUmakefile
	env BISMON_MAKE="$(MAKE)" ./timestamp-emit.sh $(BM_CSOURCES) $(BM_CXXSOURCES)

%_BM.const.h: %_BM.c | BM_makeconst
	./BM_makeconst

all: config executable

executable: _bismon-config.mk
	$(MAKE) $(BISMONMK_EXECUTABLE)

bismon:  _bismon-config.mk _bm_config.h
	$(MAKE) $(BISMONMK_OBJECTS)

-include $(wildcard _*.mkd)
