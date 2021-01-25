#!/bin/bash
## SPDX-License-Identifier: GPL-3.0-or-later
## See https://github.com/bstarynk/bismon/
## file emit-make-dependencies.bash
##
## BISMON 
## Copyright © 2021 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
## contributed by Basile Starynkevitch.
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
##-
## Contact me (Basile Starynkevitch) by email
## basile@starynkevitch.net and/or basile.starynkevitch@cea.fr
##

echo running $0 with "$@" as pid $$
tempdepfile=_bismon-makedep.mk-$$.tmp

date +"# File _bismon-makedep.mk generated by $0\n# at %Y, %b, %d on $(hostname)%n" > $tempdepfile
printf "# This file contains dependencies for GNU make\n" >> $tempdepfile
printf "# see github.com/bstarynk/bismon\n" >> $tempdepfile

for srcfil in $* ; do
    printf "\n" >> $tempdepfile
    case $srcfil in
	*.c)
	    srcbase=$(basename $srcfil .c)
	    constfil=$srcbase.const.h
	    if head -100 $srcfil | grep -q $constfil - ; then
		printf '%s.o: %s $(BM_HEADERS) %s\n' $srcbase $srcfil $constfil >> $tempdepfile
		printf '%s: %s ./BM_makeconst\n' $constfil $srcfil >> $tempdepfile
	    else
		printf '%s.o: %s $(BM_HEADERS)\n' $srcbase $srcfil >> $tempdepfile
	    fi
	    ;;
	*.cc)
	    srcbase=$(basename $srcfil .cc)
	    constfil=$srcbase.const.h
	    if head -100 $srcfil | grep -q $constfil - ; then
		printf '%s.o: %s $(BM_HEADERS) %s\n' $srcbase $srcfil $constfil  >> $tempdepfile
		printf '%s: %s ./BM_makeconst\n' $constfil $srcfil >> $tempdepfile
	    else
		printf '%s.o: %s $(BM_HEADERS)\n' $srcbase $srcfil >> $tempdepfile
	    fi
	    ;;
	*)
	    printf "%s: unexpected source file %s\n" $0 $srcfil > /dev/stderr
	    exit 1
    esac
done

printf "\n## end of generated file _bismon-makedep.mk\n" >> $tempdepfile

if [ -f _bismon-makedep.mk ]; then
    /bin/mv  _bismon-makedep.mk  _bismon-makedep.mk~
fi
/bin/mv -f $tempdepfile _bismon-makedep.mk

## end of BISMON script emit-make-dependencies.bash
