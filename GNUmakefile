#!/usr/bin/make -f
## the Bismon GNUmakefile - for GNU make 4
## SPDX-License-Identifier: GPL-3.0-or-later
## GPLv3+ licensed, from http://github.com/bstarynk/bismon
# 
#    BISMON 
#   Copyright © 2018 - 2021 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
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
MARKDOWN= markdown
INDENT= indent
ASTYLE= astyle
MD5SUM= md5sum
INDENTFLAGS= --gnu-style --no-tabs --honour-newlines
ASTYLEFLAGS= --style=gnu -s2
RM= rm -fv
BM_CXX_STANDARD_FLAGS= -std=gnu++17
## libonion from github.com/davidmoreno/onion is an HTTP/HTTPS server library

## template generator from libonion
ONION_TEMPLATE_GENERATOR= otemplate

## CONVENTION: handwritten markdown files are...
MARKDOWN_SOURCES= $(sort $(wildcard *.md))

## CONVENTION: generated modules C files are
BM_GENMODULES_C_SOURCES= $(sort $(wildcard modules/modbm*.c))

## CONVENTION: generated modules C++ files could be
BM_GENMODULES_CXX_SOURCES= $(sort $(wildcard modules/modbm*.cc))

## CONVENTION: handwritten headers are...
BM_HEADERS= $(wildcard [a-z]*BM.h bismon.h)

## CONVENTION: handwritten C files are...
BM_C_SOURCES= $(wildcard [a-z]*_BM.c)

## CONVENTION: handwritten C++ files are...
BM_CXX_SOURCES= $(wildcard [a-z]*_BM.cc)

## CONVENTION: handwritten C files for web using libonion
BM_C_ONION_SOURCES= $(wildcard [a-z]*_ONIONBM.c)


## CONVENTION: templates for libonion
BM_ONION_TEMPLATES= $(wildcard [a-z]*ONIONBM.thtml)

BM_ONIONTEMPL_HEADERS= $(patsubst %.thtml,_%.h,$(BM_ONION_TEMPLATES))
BM_ONIONTEMPL_C_CODE= $(patsubst %.thtml,_%.c,$(BM_ONION_TEMPLATES))
BM_ONIONTEMPL_OBJECTS= $(patsubst %.c,%.o,$(BM_ONIONTEMPL_C_CODE))

## CONVENTION: packages for pkg-config
BM_PACKAGES=  glib-2.0

## CONVENTION: potential options for BISMON-config configurator. Could
## be overwritten by command line...
BISMON_CONFIG_OPTIONS=

### object files:
BM_OBJECTS= $(patsubst %.c,%.o,$(BM_C_SOURCES))  $(patsubst %.cc,%.o,$(BM_CXX_SOURCES))

BM_ONION_OBJECTS= $(patsubst %.c,%.o,$(BM_C_ONION_SOURCES)) $(BM_ONIONTEMPL_OBJECTS)

## internal make variables...
BISMON_SHGIT1:= $(shell  git log --format=oneline -q -1 | cut '-d '  -f1 | tr -d '\n' | head -c16)
BISMON_SHGIT2:= $(shell if git status | grep -q 'nothing to commit'; then echo; else echo +; fi)

## The short git id, such as 34ae25e8127fc354 (for a clean source)
## or 3ae25e8127fc354d+ (for some edited source tree)
BISMON_SHORT_GIT:= $(BISMON_SHGIT1)$(BISMON_SHGIT2)

.PHONY: all config count executable clean runconfig objects redump

.DEFAULTS: all

config: _bismon-config.mk _bm_config.h  _bm_config.c

include _bismon-config.mk

ifdef BISMONMK_HOST_CC
CC=$(BISMONMK_HOST_CC)
else
CC=gcc
endif

ifdef BISMONMK_HOST_CXX
CXX=$(BISMONMK_HOST_CXX)
else
CXX=g++
endif

ifndef BISMON_CFLAGS
BISMON_CFLAGS= -O -g -Wall -Wextra -std=gnu11
endif

ifndef BISMON_CXXFLAGS
BISMON_CXXFLAGS= -O -g -Wall -Wextra -std=gnu++14
endif

clean:
	$(RM) *.o BISMON-config bismon   modubin/*.so modubin/*.o *~ *% *.cc.orig

_bismon-config.mk:
	@echo you should run the Configure script in $(pwd) for $@ > /dev/stderr
	exit 1

_bm_config.h _bm_config.c:
	@echo you should run the Configure script in $(pwd) for $@ > /dev/stderr
	exit 1


## FIXME: for some reason, near commit 70c004037af4cb4a on 10 june 2021, it
## seems that $(COMPILE.cc) don't work and we need to use $(CXX)
BM_makeconst_dbg: BM_makeconst-g.o id_BM-g.o
	$(CXX) -g -Wall  -DBISMON_MAKING_$@ $^  $(shell pkg-config --libs glib-2.0) -o $@

BM_makeconst: BM_makeconst.o id_BM.o
	@echo building $@ with CXX= $(CXX)
	$(CXX) -g -O -DBISMON_MAKING_$@ -Wall  $^  $(shell pkg-config --libs glib-2.0) -o $@
	@echo did build $@ with CXX= $(CXX)

BM_makeconst-g.o: BM_makeconst.cc id_BM.h
	@echo building $@ with CXX= $(CXX)
	$(CXX) -DBISMON_MAKING_BM_makeconst_g  $(shell pkg-config --cflags glib-2.0) -g -Wall -c $< -o $@
	@echo did build $@ with CXX= $(CXX)

BM_makeconst.o: BM_makeconst.cc id_BM.h
	@echo building $@ with CXX= $(CXX)
	$(CXX)  -DBISMON_MAKING_BM_makeconst $(shell pkg-config --cflags glib-2.0) -g -O -Wall -c $< -o $@
	@echo did build $@ with CXX= $(CXX)

-include _bismon-makedep.mk

id_BM.o: id_BM.c id_BM.h
	$(CC) -DBISMON_MAKING_id_BM $(BISMON_CFLAGS)  $(shell pkg-config --cflags glib-2.0)  -Wall -Wextra -c $< -o $@
id_BM-g.o: id_BM.c id_BM.h
	$(CC)   -DBISMON_MAKING_id_BM_g $(BISMON_CFLAGS) -g $(shell pkg-config --cflags glib-2.0) -g -Wall  -Wextra -c $< -o $@

%_BM.o: %_BM.c bismon.h
	$(CC)  -DBISMON_MAKING_C_$* $(BISMON_CFLAGS) $(shell pkg-config --cflags $(BISMONMK_PACKAGES)) -MD -MF$(patsubst %.o, _%.mkd, $@) -Wall  -Wextra  $< -o $@

%_BM-g.o: %_BM.c bismon.h
	$(CC)  -DBISMON_MAKING_C_$*_g $(BISMON_CFLAGS) -g $(shell pkg-config --cflags $(BISMONMK_PACKAGES)) -MD -MF$(patsubst %.o, _%-g.mkd, $@)  -g -Wall $< -o $@

%_BM.o: %_BM.cc bismon.h
	$(CXX)  -DBISMON_MAKING_CPP_$* $(BISMON_CXXFLAGS) $(shell pkg-config --cflags $(BISMONMK_PACKAGES)) -MD -MF$(patsubst %.o, _%.mkd, $@) -Wall $< -o $@

%_BM-g.o: %_BM.cc bismon.h
	$(CXX)  -DBISMON_MAKING_CPP_$*_g $(BISMON_CXXFLAGS) -g $(shell pkg-config --cflags $(BISMONMK_PACKAGES)) -MD -MF$(patsubst %.o, _%-g.mkd, $@)  -g -Wall  $< -o $@

%_ONIONBM.o: %_ONIONBM.c bismon.h
	@printf "for $@ BISMON_SHORT_GIT is '%s'\n" '$(BISMON_SHORT_GIT)'
	$(CC) -DBISMON_MAKING_ONIONC_$* -DBISMON_GITID=\"$(BISMON_SHORT_GIT)\" $(shell pkg-config --cflags $(BISMONMK_PACKAGES)) -I$(BISMONMK_ONION_INCLUDEDIR) -MD -MF$(patsubst %.o, _%.mkd, $@) -Wall -Wextra  $< -o $@

%_ONIONBM-g.o: %_ONIONBM.c bismon.h
	$(CC) -DBISMON_MAKING_ONIONC_$*_g $(BISMON_CFLAGS) -DBISMON_GITID=\"$(BISMON_SHORT_GIT)\" $-g $(shell pkg-config --cflags $(BISMONMK_PACKAGES)) -I$(BISMONMK_ONION_INCLUDEDIR) -MD -MF$(patsubst %.o, _%-g.mkd, $@)  -g -Wall -Wextra $< -o $@

web_ONIONBM.o: web_ONIONBM.c _login_ONIONBM.h _changepasswd_ONIONBM.h

%BM.const.h: %BM.c BM_makeconst
	./BM_makeconst -H $@ $<

__timestamp.c:  timestamp-emit.sh |  GNUmakefile
	env BISMON_MAKE="$(MAKE)" ./timestamp-emit.sh

all: config executable

executable: _bismon-config.mk
	$(MAKE) $(BISMONMK_EXECUTABLE)


_bismon-constants.c: BM_makeconst $(BISMONMK_OBJECTS)
	./BM_makeconst -C $@ $(BM_C_SOURCES) $(BM_C_ONION_SOURCES) $(BM_CXX_SOURCES)

_bismon-constants.o: _bismon-constants.c

_%_ONIONBM.h _%_ONIONBM.c: %_ONIONBM.thtml
	/bin/cp $^ $^~ $(warning processing $^)
	if [ -f  $(patsubst %.thtml,_%.h,$^) ] ; then \
	   /bin/mv -vf $(patsubst %.thtml,_%.h,$^) $(patsubst %.thtml,_%.h~,$^) ; fi
	if [ -f  $(patsubst %.thtml,_%.c,$^) ] ; then \
	   /bin/mv -vf $(patsubst %.thtml,_%.c,$^) $(patsubst %.thtml,_%.c~,$^) ; fi
	$(ONION_TEMPLATE_GENERATOR) --asset-file $(patsubst %.thtml,_%.h,$^) $^ $(patsubst %.thtml,_%.c,$^)

## a phony target, used in Build script
objects:  $(BISMONMK_OBJECTS)

bismon:  _bismon-config.mk _bm_config.h _bismon-constants.c $(wildcard _genbm_*.h)
	$(MAKE) $(BISMONMK_OBJECTS) _bismon-constants.o __timestamp.o
ifdef BISMONMK_HOST_CXX
	@echo linking $@ with BISMONMK_HOST_CXX= $(BISMONMK_HOST_CXX)
	$(BISMONMK_HOST_CXX)  $(BISMONMK_OBJECTS) _bismon-constants.o  __timestamp.o \
                    -L$(BISMONMK_ONION_LIBDIR) -lonion \
                    $(shell pkg-config --libs $(BISMONMK_PACKAGES)) \
                    -lbacktrace -lcrypt -lpthread -ldl -rdynamic -o $@
else
	@echo linking $@ with CXX= $(CXX)
	$(CXX)  $(BISMONMK_OBJECTS) _bismon-constants.o  __timestamp.o \
                    -L$(BISMONMK_ONION_LIBDIR) -lonion \
                    $(shell pkg-config --libs $(BISMONMK_PACKAGES)) \
                    -lbacktrace -lcrypt -lpthread -ldl -rdynamic -o $@
endif

_bismon-makedep.mk: GNUmakefile emit-make-dependencies.bash
	./emit-make-dependencies.bash $(BM_C_SOURCES) $(BM_CXX_SOURCES) $(BM_C_ONION_SOURCES)

redump: bismon $(wildcard store*.bmon)
	./bismon --batch --dump-after-load=.

modubin/modbm_%.so: modules/modbm_%.c | bismon _bismon-config.mk _bm_config.h
	$(LINK.c) -DBISMON_MODULE_$(notdir $(basename $@)) $(BISMON_CFLAGS) -shared -DBISMON_MODID=\"$(BISMON_MODULE_ID)\" -DBISMON_MODMD5=\"$(BISMON_MODULE_MD5SUM)\" -fPIC -I. $(shell pkg-config --cflags $(BISMONMK_PACKAGES)) -rdynamic -Wall  $< -o $@
## _bm_predef.h is obsolete since renamed _genbm_predef.h

##### end of file bismon/GNUmakefile
