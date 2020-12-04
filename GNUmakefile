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


## tell make to export all variables by default
export

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
BM_NINJA= ninja
BM_NICE= nice
BM_CXX_STANDARD_FLAGS= -std=gnu++17
BM_WARNING_FLAGS= -Wall -Wextra
BM_C_STANDARD_FLAGS= -std=gnu11
BM_OPTIM_FLAGS= -O1
BM_DEBUG_FLAGS= -g
BM_NINJA_FLAGS= --verbose -l 7


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
BM_PACKAGES=  glib-2.0 readline

## CONVENTION: persistent generated header files are
BM_PERSISTENT_HEADERS= $(wildcard genbm_*.h)

## CONVENTION: potential options for BISMON-config configurator. Could
## be overwritten by command line...
BISMON_CONFIG_OPTIONS=


## internal make variables...
BISMON_SHGIT1:= $(shell  git log --format=oneline -q -1 | cut '-d '  -f1 | tr -d '\n' | head -c16)
BISMON_SHGIT2:= $(shell if git status | grep 'nothing to commit' > /dev/null; then echo ; else echo +; fi)

CFLAGS += $(BM_C_STANDARD_FLAGS) $(pkg-config --cflags $(BM_PACKAGES)) \
          $(BM_WARNING_FLAGS) $(BM_OPTIM_FLAGS) $(BM_DEBUG_FLAGS)

CXXFLAGS += $(BM_CXX_STANDARD_FLAGS) $(pkg-config --cflags $(BM_PACKAGES)) \
          $(BM_WARNING_FLAGS) $(BM_OPTIM_FLAGS) $(BM_DEBUG_FLAGS)

## The short git id, such as 34ae25e8127fc354 (for a clean source)
## or 3ae25e8127fc354d+ (for some edited source tree)
BISMON_SHORT_GIT:= $(BISMON_SHGIT1)$(BISMON_SHGIT2)


## see https://www.gnu.org/software/make/manual/html_node/Special-Targets.html
.DEFAULT: all

.PHONY: all config count executable distclean clean runconfig  doc

.EXPORT_ALL_VARIABLES:


################
config: _bismon-config.mk _bm_config.h  _bm_config.c $(warning $(MAKE) config at level $(MAKELEVEL))

## include _bismon-config.mk only if it exists.
ifeq ($(strip $(wildcard _bismon-config.mk)),_bismon-config.mk)
-include _bismon-config.mk
endif

ifdef BISMONMK_TARGET_GCC
BISMON_CONFIG_OPTIONS+= --target-gcc=$(BISMONMK_TARGET_GCC)
endif

ifdef BISMONMK_TARGET_GCC
BISMON_CONFIG_OPTIONS+= --target-gxx=$(BISMONMK_TARGET_GXX)
endif

ifdef BISMONMK_OUT_DIRECTORY
BISMON_CONFIG_OPTIONS+= --output-directory=$(BISMONMK_OUT_DIRECTORY)
endif


ifeq ($(MAKELEVEL),0)
_bismon-config.mk _bm_config.h _bm_config.c: BISMON-config.cc
	sleep 0.05
	bash -x -c 'if [ ! -x ./BISMON-config -a "$(MAKELEVEL)" = 0 ] ; then /bin/sleep 0.1 ; $(MAKE)  ./BISMON-config ; fi'
	sleep 0.1
	$(MAKE) runconfig
	sleep 0.02

### the configurator program
BISMON-config: BISMON-config.cc __timestamp.o $(warning $(MAKE) BISMON-config at level zero)
	@echo Building BISMON-config using BISMON_SHORTGIT=$(BISMON_SHORT_GIT)
	@bash -c "if [ -f $@ ] ; then /bin/mv -v $@ $@~ ; fi"
	$(GXX) $(BM_CXX_STANDARD_FLAGS) '-DBISMON_SHORTGIT="$(BISMON_SHORT_GIT)"' -Wall -Wextra -O -g $^ -lreadline  -o $@
endif


ifeq ($(MAKELEVEL),1)
_bismon-config.mk _bm_config.h _bm_config.c: BISMON-config
	sleep 0.01
	bash -x -c 'if [ ! -x ./BISMON-config -a "$(MAKELEVEL)" = 0 ] ; then /bin/sleep 0.1 ; $(MAKE)  ./BISMON-config ; fi'
	sleep 0.2
	$(MAKE) runconfig
	sleep 0.03

### the configurator program at level one
BISMON-config: BISMON-config.cc __timestamp.o $(warning $(MAKE) BISMON-config at level one)
	@echo Building BISMON-config using BISMON_SHORTGIT=$(BISMON_SHORT_GIT)
	@bash -c "if [ -f $@ ] ; then /bin/mv -v $@ $@~ ; fi"
	$(GXX) $(BM_CXX_STANDARD_FLAGS) '-DBISMON_SHORTGIT="$(BISMON_SHORT_GIT)"' -Wall -Wextra -O -g $^ -lreadline  -o $@
endif


runconfig: BISMON-config $(warning $(MAKE) runconfig at level $(MAKELEVEL))
	./BISMON-config --skip=for_runconfig $(BISMON_CONFIG_OPTIONS)
	$(MAKE) _bismon-constdep.mk

count:
	@wc -cl $(wildcard *.c *.h *.cc modules/_*.c) | sort -n

clean:
	sleep 0.05
	if [ -f build.ninja ] ; then $(BM_NICE) $(BM_NINJA) $(BM_NINJA_FLAGS) -t clean ; fi
	$(RM) *.o BISMON-config BM_makeconst bismon _bm_config.h _bm_config.c  modubin/*.so modubin/*.o *~ *% *.cc.orig
	$(RM) _*.mkd _*conf*.mk
	$(RM) *~ *%
	$(RM) *_BM.const.h
	$(RM) build.ninja

distclean: | distclean-script.bash
	./distclean-script.bash
	$(RM) *~ *%

BM_makeconst_dbg: BM_makeconst-g.o id_BM-g.o
	$(CXX)  -std=gnu++14 -g -Wall -Wextra   BM_makeconst-g.o id_BM-g.o $(shell pkg-config --libs glib-2.0) -o $@

BM_makeconst: BM_makeconst.cc id_BM.o | id_BM.h
	$(LINK.cc) -std=gnu++14 -O -g -Wall  -Wextra '-DBISMON_SHORTGIT="$(BISMON_SHORT_GIT)"'  BM_makeconst.cc id_BM.o  $(shell pkg-config --cflags --libs glib-2.0) -o $@

BM_makeconst-g.o: BM_makeconst.cc id_BM.h
	$(COMPILE.cc) -std=gnu++14   $(shell pkg-config --cflags glib-2.0) -g -Wall  -Wextra '-DBISMON_SHORTGIT="$(BISMON_SHORT_GIT)"' -c $< -o $@

ifeq ($(strip $(wildcard _bismon-constdep.mk)),_bismon-constdep.mk)
-include _bismon-constdep.mk
endif

id_BM.o: id_BM.c id_BM.h
	$(COMPILE.c)  $(shell pkg-config --cflags glib-2.0) -O -g -Wall -Wextra -c $< -o $@
id_BM-g.o: id_BM.c id_BM.h
	$(COMPILE.c)  $(shell pkg-config --cflags glib-2.0) -g -Wall -Wextra -c $< -o $@

#°    %_BM.o: %_BM.c bismon.h | BISMON-config BM_makeconst
#°            @echo building $@ from prerequisites $^ with BISMON_CONFIG_OPTIONS= $(BISMON_CONFIG_OPTIONS)
#°            @echo should $(MAKE) bismon.h $(shell ./BISMON-config --skip=for_bismon_object --batch $(BISMON_CONFIG_OPTIONS) --const-depend $<)
#°            $(MAKE) bismon.h  $(shell ./BISMON-config --skip=for_bismon_object_sh $(BISMON_CONFIG_OPTIONS) --const-depend $<)
#°            $(COMPILE.c) $(shell pkg-config --cflags $(BISMONMK_PACKAGES)) -MM -MF $(patsubst %.o, _%.mkd, $@) -Wall -c $< -o $@
#° 
#°    %_BM-g.o: %_BM.c bismon.h | BISMON-config BM_makeconst
#°            @echo building $@ fromprerequisites  $^ with BISMON_CONFIG_OPTIONS= $(BISMON_CONFIG_OPTIONS)
#°            $(MAKE) bismon.h $(shell ./BISMON-config --skip=for_bismon_object_shdbg  --batch $(BISMON_CONFIG_OPTIONS) ---const-depend $<)
#°            $(COMPILE.c) $(shell pkg-config --cflags $(BISMONMK_PACKAGES)) -MM -MF $(patsubst %.o, _%-g.mkd, $@)  -g -Wall -c $< -o $@

__timestamp.c:  timestamp-emit.sh |  GNUmakefile
	env BISMON_MAKE="$(MAKE)" BISMON_PACKAGES="$(BM_PACKAGES)" ./timestamp-emit.sh $(BM_CSOURCES) $(BM_CXXSOURCES)

%_BM.const.h: %_BM.c | BM_makeconst
	./BM_makeconst -H $@ $^

all: config executable $(warning $(MAKE) all at level $(MAKELEVEL))

executable: _bismon-config.mk build.ninja $(warning $(MAKE) executable at level $(MAKELEVEL))
	$(MAKE) $(BISMONMK_EXECUTABLE)
	$(MAKE) bismon


_bismon-constants.c: BM_makeconst $(BISMONMK_OBJECTS)
	./BM_makeconst -C $@ $(BM_CSOURCES)

bismon:  _bismon-config.mk _bm_config.h _bismon-constants.c _bismon-constdep.mk  $(warning $(MAKE) bismon at level $(MAKELEVEL)) | $(BM_CSOURCES) $(BM_CXXSOURCES) BISMON-config.cc
	$(MAKE) build.ninja
	/bin/ls -l build.ninja
	@echo $(MAKE) will build $@ using $(BM_NICE) $(BM_NINJA) $(BM_NINJA_FLAGS) bismon "_-_" $(warning should build $@)
	$(BM_NICE) $(BM_NINJA) $(BM_NINJA_FLAGS) bismon
	$(RM) __timestamp.o
	mv __timestamp.c __timestamp.c~
	/bin/ls -l $@

-include $(wildcard _*.mkd)


_bismon-constdep.mk: BISMON-config $(BM_CSOURCES)
	@if [ -f $@ ] ; then /bin/mv -v $@ $@~ ; fi
	./BISMON-config --skip=for_constdep $(BISMON_CONFIG_OPTIONS) --emit-const-dep=$@  $(BM_CSOURCES)

ifeq ($(MAKELEVEL),0)
build.ninja: GNUmakefile BISMON-config   _bismon-config.mk _bm_config.h $(warning $(MAKE) build.ninja at zero level) 
	./BISMON-config --skip=for_base_ninja  $(BISMON_CONFIG_OPTIONS) --ninja=$@
else
build.ninja: GNUmakefile BISMON-config $(warning $(MAKE) build.ninja at level $(MAKELEVEL)) 
	./BISMON-config --skip=for_$(strip $(MAKELEVEL))_ninja  $(BISMON_CONFIG_OPTIONS) --ninja=$@
endif


doc: build-bismon-doc.sh $(wildcard doc/*.tex) doc/bismon-biblio.bib
	./build-bismon-doc.sh LaTeX

### end of file GNUmakefile in github.com/bstarynk/bismon
