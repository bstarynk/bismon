#!/bin/bash
# file misc/bisect-redump.sh

## to be used with git bisect to ensure dumpability.
## see https://git-scm.com/docs/git-bisect
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
## This script should be copied into /tmp/ then run from Bismon source
## directory git cloned from github.com/bstarynk/bismon/
##
## the expected invocation could be
## rm -rf /tmp/bismonbi*
## cp misc/bisect-redump.sh $HOME/tmp/bisect-redump.sh
## git bisect start
## git bisect bad  9d78aadbb4b660 # this commit is bad
## git bisect good 14a8a83d79958a # this commit is good
## git bisect run $HOME/tmp/bisect-redump.sh
## git bisect reset
### 6de222b6e329a01a84 is the first bad commit
### 68e469314cb2bf9e72 is the last good commit
################
curcommitid=$(git log -1 | head -24c | cut -d' ' -f2)
bismontmpdir="/tmp/bismonbi-$curcommitid"
mkdir $bismontmpdir || { printf "\n\n*** bismon mkdir failure /tmp/bismon-%s ****\n" $curcommitid  > /dev/stderr ; exit 11 ;}
git log --name-status -1 > $bismontmpdir/_gitlog 2>&1
[ -f  "$bismontmpdir/_gitlog" ] || { printf "\n\n*** bismon missing %s ****\n"  "$bismontmpdir/_gitlog"  > /dev/stderr ; exit 12 ;}
make clean
make all || { printf "\n\n*** make all failure %s ****\n" $curcommitid > /dev/stderr ; exit 100 ;}
sync
./bismon --dump-after-load $bismontmpdir $BISMON_REDUMP_OPTIONS --batch || { printf "\n\n*** bismon dump failure %s ****\n" $curcommitid  > /dev/stderr ; exit 13 ;}
./bismon --load $bismontmpdir $BISMON_REDUMP_OPTIONS --batch || { printf "\n\n*** bismon load failure %s ****\n" $curcommitid  > /dev/stderr ; exit 14 ;}
printf "\n**** bisect-redump ok for %s ****\n\n\n" $curcommitid 

###     make redump worked in commit 9c485536b3cf2dc4b41c 
###     make redump fails in commit 9d78aadbb4b6606da5d76
### eof misc/bisect-redump.sh
