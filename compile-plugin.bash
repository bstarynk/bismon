#!/bin/bash -x
## SPDX-License-Identifier: GPL-3.0-or-later
## See https://github.com/bstarynk/bismon/
## file compile-plugin.bash
PLUGINSOURCE=$1
PLUGINSO=$(dirname $1)/$(basename $1 .c).so
printf "%s: compiling Bismon plugin source %s to %s with compiler %s and flags %s in %s\n" $0 $PLUGINSOURCE $PLUGINSO "$BISMONMK_HOST_CC" "$BISMON_CFLAGS" $(/bin/pwd)
#printenv
$BISMONMK_HOST_CC -fPIC -I$(/bin/pwd)  -DBISMON_SHORTGIT=\"$BISMON_SHORT_GIT\" -shared $BISMON_CFLAGS  $(/usr/bin/pkg-config --cflags $BISMON_PACKAGES)  $PLUGINSOURCE -o $PLUGINSO
