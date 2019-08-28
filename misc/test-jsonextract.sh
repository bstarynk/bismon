#!/bin/bash
# file misc/test-jsonextract.sh

## to test json extraction thru HTTP REST requests.  See comments
## after GPLv3+ notice.

# 
#    BISMON 
#    Copyright © 2019 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
#    contributed by Basile Starynkevitch (working at CEA, LIST, France)
#    <basile@starynkevitch.net> or <basile.starynkevitch@cea.fr>
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
#----
#    Contact me (Basile Starynkevitch) by email
#    basile@starynkevitch.net and/or basile.starynkevitch@cea.fr


##### NOTICES
## This script should be run from Bismon source directory
## git cloned from github.com/bstarynk/bismon/

## it could be useful to pass --debug-after-load to this
## misc/test-jsonextract.sh shell script

## TODO near commit a2a88e6e0a50bd1: we need to handle, thru
## webdict_root, the /test-jsonextract

################
bismonflags="$@"

# https://stackoverflow.com/a/9894126/841108
export TOP_PID=$$
# so runbismon below can exit the entire script


if [ ! -f bismon.h ] ; then
   echo Current directory $(pwd) does not contain bismon.h header > /dev/stderr
   exit 1
fi
if [ ! -f store1.bmon ] ; then
   echo Current directory $(pwd) does not contain store1.bmon file > /dev/stderr
   exit 1
fi

make bismon all

rm -f /tmp/bismoncookie

function restorebismondata () {
    modiflist=$(git status -s | cut -d' ' -f3)
    mkdir /tmp/modified-bismon
    for f in $modiflist ; do
	cp -va $f /tmp/modified-bismon/_new_$f
    done
    tar -cv -C /tmp/modified-bismon -f /tmp/bismonmodified.tar.gz .
    rm -rf /tmp/modified-bismon
    echo 'git status before restore'
    git status
    echo
    if [ -f /tmp/bismonstore.tar.gz ]; then
	echo 'restoring Bismon store'
	tar xvf /tmp/bismonstore.tar.gz
	mv -v  /tmp/bismonstore.tar.gz  /tmp/bismonprevstore.tar.gz
    else
	echo 'no /tmp/bismonstore.tar.gz to restore' > /dev/stderr
    fi
    ls -lt /tmp/bismon*.tar.gz
    # restore default trap handing
    trap - EXIT TERM ERR
}

trap restorebismondata EXIT INT TERM ERR


################################
function runbismon () {
    local title=$1
    shift
    args="$@"
    if [ -z "$BISMON_WRAPPER" ] ; then 
	echo run bismon: $title args: "$args"
	if ./bismon $bismonflags \
		    --anon-web-session=/tmp/bismoncookie --web \
		    "$@" ; then
	    echo OK bismon: $title
	else
	    failcode=$?
	    printf '\n\n!!!!!!! FAIL plain bismon %s - exitcode %d\n' "$title" $failcode
	    echo FAIL bismon: $title "$args"
	    kill $TOP_PID
	    exit $failcode
	fi
    else
	echo wrap "$BISMON_WRAPPER" bismon: $title args: "$args"
	if $BISMON_WRAPPER ./bismon $bismonflags \
		    --anon-web-session=/tmp/bismoncookie --web \
		    "$@" ; then
	    echo OK wrap "$BISMON_WRAPPER" bismon: $title
	else
	    failcode=$?
	    printf '\n\n!!!!!! FAIL wrapped %s bismon %s - exitcode %d\n' "$BISMON_WRAPPER" "$title" $failcode
	    echo FAIL wrap "$BISMON_WRAPPER" bismon: $title "$args"
	    kill $TOP_PID
	    exit $failcode
	fi
    fi	
}
## end runbismon
################################


rm -vf /tmp/bismoncookie
( sleep 3; head /tmp/bismoncookie; date +"start wget %c%n" ; source /tmp/bismoncookie; \
  echo bismon cookie is $BISMONCOOKIE; \
  stdbuf --output=L --error=L \
	 wget --post-data='{ "do": "test1json" }' -v -S \
	 --no-cookies --header "Cookie: BISMONCOOKIE=$BISMONCOOKIE" \
	 --header 'Content-Type: application/json' \
	 http://localhost:8086/test-jsonextract -O - ; sleep 0.01 )  &
runbismon TEST1json -i init_testjsonextract
wait
head /tmp/bismoncookie /dev/null

################################

