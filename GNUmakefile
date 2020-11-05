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
BM_CSOURCES= $(wildcard [a-z]*BM.c)

## CONVENTION: handwritten C++ files are...
BM_CXXSOURCES= $(wildcard [a-z]*BM.cc)

## CONVENTION: packages for pkg-config
BM_PACKAGES=  glib-2.0 gtk+-3.0 gtkmm-2.0

### object files:
BM_OBJECTS= $(patsubst %.c,%.o,$(BM_CSOURCES))  $(patsubst %.c,%.o,$(BM_CXXSOURCES))

.PHONY: all config

-include _bismon-config.mk

### the configurator program
BISMON-config: BISMON-config.cc
	$(GXX) $(BM_CXX_STANDARD_FLAGS) -Wall -Wextra -O -g $^ -lreadline  -o $@

_bismon-config.mk: ./BISMON-config