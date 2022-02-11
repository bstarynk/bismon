#!/usr/bin/make -f
## the BISMON libclient GNUmakefile - for GNU make 4
## SPDX-License-Identifier: GPL-3.0-or-later
## GPLv3+ licensed, from http://github.com/bstarynk/bismon
# 
#    BISMON 
#   Copyright ©  2022 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
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
.PHONY: lib clean

# for GNU make only, see https://www.gnu.org/software/make
GXX= g++
INDENT= indent
ASTYLE= astyle
MD5SUM= md5sum

INDENTFLAGS= --gnu-style --no-tabs --honour-newlines
ASTYLEFLAGS= --style=gnu -s2
RM= rm -fv
BMCL_CXX_STANDARD_FLAGS= -std=gnu++11
BMCL_LIBS= 
## internal make variables...
BISMON_SHGIT1:= $(shell  git log --format=oneline -q -1 | cut '-d '  -f1 | tr -d '\n' | head -c16)
BISMON_SHGIT2:= $(shell if git status | grep -q 'nothing to commit'; then echo; else echo +; fi)
BISMON_SHORT_GIT:= $(BISMON_SHGIT1)$(BISMON_SHGIT2)

CXXFLAGS= -O -g -fPIC -Wall -Wextra -std=gnu++11 -DBISMONCL_GITID=\"$(BISMON_SHORT_GIT)\"
CFLAGS= -O -g  -fPIC -Wall -Wextra  -Wmissing-prototypes -std=gnu11 -DBISMONCL_GITID=\"$(BISMON_SHORT_GIT)\"
## The short git id, such as 34ae25e8127fc354 (for a clean source)
## or 3ae25e8127fc354d+ (for some edited source tree)

## CONVENTION: handwritten libbismonclient headers are...
BMCL_HEADERS= $(wildcard [a-z]*BMCL.hh)


## CONVENTION: handwritten C++ files are...
BMCL_CXX_SOURCES= $(wildcard [a-z]*_BMCL.cc)
BMCL_OBJECTS= $(patsubst %.cc,%.o,$(BMCL_CXX_SOURCES)) __timestamp.o

lib:
	@echo target lib in libbismonclient CXXFLAGS= $(CXXFLAGS)
	$(MAKE) libbismonclient.so

libbismonclient.so: $(BMCL_OBJECTS)
	$(CXX) -shared -o $@ $(BMCL_OBJECTS) -ljsoncpp

__timestamp.o: ../__timestamp.c
	$(CC) $(CFLAGS) -c -o $@ $^

../__timestamp.c:
	$(MAKE) -C .. __timestamp.c


