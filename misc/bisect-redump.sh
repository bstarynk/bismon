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
## git bisect run /tmp/bisect-redump.sh
################
make clean
make all || (printf "\n\n*** make all failure %s ****\n" $(git log -1 | head -24c) > /dev/stderr ; exit 10)
./bismon --dump-after-load . $BISMON_REDUMP_OPTIONS --batch || (printf "\n\n*** make all failure %s ****\n" $(git log -1 | head -24c)  > /dev/stderr ; exit 11)

### eof misc/bisect-redump.sh
