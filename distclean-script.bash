#!/bin/bash
## SPDX-License-Identifier: GPL-3.0-or-later
## See https://github.com/bstarynk/bismon/
## file distclean-script.bash
##
## BISMON 
## Copyright © 2020 - 2022 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
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

echo Running $0 with "$@" as pid $$ for Bismon on github.com/bstarynk/bismon
printf "%s could remove important generated files,\n.... so you can interrupt it with Ctrl-C during the next two seconds.\n" $0
sleep 2.0
echo $0 is cleaning ....

initialkilobytes=$(/usr/bin/du -csk . | /usr/bin/gawk '/total/{print $1}')

# was generated by BISMON-config
/bin/rm -f _[a-zA-Z]*~
/bin/rm -f _bismon-constdep.mk
/bin/rm -f _bismon-config.mk
/bin/rm -f _bismon-constants.c
/bin/rm -f BISMON-config
/bin/rm -f build.ninja
/bin/rm -f BM_makeconst

/bin/rm -f [a-zA-Z]*.o
/bin/rm -f _*.o
/bin/rm -f _bm_config.c
/bin/rm -f _bm_config.h
/bin/rm -f id_BM.o

# generated makefile dependencies
/bin/rm -f *.mkd
/bin/rm -f _*.mk

# generated plugins
/bin/rm -f */*.so

# generated headers and file by BM_makeconst
/bin/rm -f *BM.const.h _bm_*.c

# onion generated files (assets.h is generated for buggy otemplate command in our GNUmakefile)
/bin/rm -f _*ONIONBM.[ch] assets.h

## editor or metaprogram backups
/bin/rm -f *~ *%
/bin/rm -f *.orig

## temporary files
/bin/rm -f *.tmp

# was generated by timestamp-emit.sh
/bin/rm -f  __timestamp.c
/bin/rm -f  __timestampconf.c

# the bismon executable
/bin/rm -f bismon

# was generated by ninja
/bin/rm -f .ninja.log

## plugin related temporary or redundant files
/bin/rm -f gccplugins/_* gccplugins/*~ gccplugins/*.orig

finalkilobytes=$(/usr/bin/du -csk . | /usr/bin/gawk '/total/{print $1}')
################################################################
echo $0 done cleaning gaining $[$initialkilobytes - $finalkilobytes] kilobytes ...
echo ... in '(user+system seconds, self then children):'
times
