#!/bin/bash -x
##// SPDX-License-Identifier: GPL-3.0-or-later
##### this shell script could be invoked from Msh-Analyze
##
## BISMON related GCC12 metaplugin builder
## file gccplugins/build-gcc12_metaplugin.sh
## See https://github.com/bstarynk/bismon/
## Copyright © 2020 - 2022 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
################################################################
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
################################################################

## C++ compiler used to compile the GCC meta plugin
if [ -z "$BISMON_PLUGIN_GXX" ]; then
    export BISMON_PLUGIN_GXX=/usr/bin/g++-12
fi

## target compiler which dlopen-s the GCC meta plugin
if [ -z "$BISMON_TARGET_GCC" ]; then
    export BISMON_TARGET_GCC=/usr/bin/g++-12
fi

TARGETPLUGINDIR=$($BISMON_TARGET_GCC -print-file-name=plugin)
# run the gengtype utility, see https://gcc.gnu.org/onlinedocs/gccint/Files.html#Files

if [ -z "$TARGETPLUGINDIR" ]; then
    printf "%s: failed to get TARGETPLUGINDIR with BISMON_TARGET_GCC=%s\n" "$0" "$BISMON_TARGET_GCC" > /dev/stderr
    exit 1
fi

/bin/ls -ld $TARGETPLUGINDIR || exit 1

TARGETGENGTYPE=$TARGETPLUGINDIR/gengtype
$TARGETGENGTYPE --read-state $TARGETPLUGINDIR/gtype.state \
		--plugin _gcc12_metaplugin_BMGCC-gty.h \
		gcc12_metaplugin_BMGCC.cc gcc12_metaplugin_BMGCC.hh

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


#### see also Debian bug #983436

### in rare cases, we also want the assembler file of the plugin
### (e.g. to debug some dlerror in it).  Assembler output is obtained
### by setting the environment variable BISMON_PLUGIN_ASMOUT
if [ -n "$BISMON_PLUGIN_ASMOUT" ]; then
    if [ -f "$BISMON_PLUGIN_ASMOUT" ]; then
	/bin/mv  "$BISMON_PLUGIN_ASMOUT"  "$BISMON_PLUGIN_ASMOUT"~
    fi
    $BISMON_PLUGIN_GXX -Wall -Wextra -O1 -g3 \
	       -I $TARGETPLUGINDIR/include/ \
	       -shared -fno-rtti -fPIC -rdynamic \
	       -DPLUGINGITID=\"$SHORTGITID\" \
	       gcc12_metaplugin_BMGCC.cc \
               $(pkg-config --cflags --libs jsoncpp curlpp) \
	       -S -fverbose-asm -o "$BISMON_PLUGIN_ASMOUT"
fi

### we need to exec, so that failure of plugin compilation fails this script
exec $BISMON_PLUGIN_GXX -Wall -Wextra -O1 -g3 \
	   -I $TARGETPLUGINDIR/include/ \
	   -shared -fno-rtti -fPIC -rdynamic \
	   -DPLUGINGITID=\"$SHORTGITID\" \
	   gcc12_metaplugin_BMGCC.cc \
           $(pkg-config --cflags --libs jsoncpp curlpp) \
	   -o gcc12_metaplugin_BMGCC.so

##FIXME: GCC documentation suggests linking with -shared
## -Wl,export-all-symbols which seems to not work above...
