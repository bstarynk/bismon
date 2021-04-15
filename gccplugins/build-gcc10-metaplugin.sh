#!/bin/bash
##
##
## BISMON related GCC10 metaplugin builder
## file gccplugins/build-gcc10-metaplugin.sh
## See https://github.com/bstarynk/bismon/
## Copyright © 2020 - 2021 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
## contributed by Basile Starynkevitch 
##
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <http://www.gnu.org/licenses/>.
##

## C++ compiler used to compile the plugin
PLUGINGXX=/usr/bin/g++-10

## target compiler for the plugin
TARGETGCC=/usr/bin/g++-10

TARGETPLUGINDIR=$($TARGETGCC -print-file-name=plugin)
# run the gengtype utility, see https://gcc.gnu.org/onlinedocs/gccint/Files.html#Files

TARGETGENGTYPE=$TARGETPLUGINDIR/gengtype
$TARGETGENGTYPE --read-state $TARGETPLUGINDIR/gtype.state \
		--plugin _gcc10-metaplugin-gty.h \
		gcc10-metaplugin_BMGCC.cc gcc-10.metaplugin.hh

SHORTGITID=$(git log --format=oneline -q -1 | head -16c)

### TODOs
### get the gitid into PLUGINGITID preprocessor
### declare some GTY-ed set of functions
### declare some GTY-ed set of basic blocks
### declare some GTY-ed set of gimples
### document the GCCplugin events to be used
### C++ code for collecting the set of functions
### C++ code for collecting the set of basic blocks
### C++ code for collecting the gimples
### document the JSONCPP protocols between GCC & Bismon
### finish event to interact with Bismon
$PLUGINGXX -Wall -Wextra -O1 -g3 \
	   -I $($TARGETGCC -print-file-name=plugin)/include/ \
	   -shared -Wl,export-all-symbols -fno-rtti -fPIC \
	   $(pkg-config --cflags --libs jsoncpp) \
	   -DPLUGINGITID=\"$SHORTGITID\" \
	   gcc10-metaplugin_BMGCC.cc -o gcc10-metaplugin_BMGCC.so
