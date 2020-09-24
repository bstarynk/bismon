#!/bin/bash
## SPDX-License-Identifier: GPL-3.0-or-later
## See https://github.com/bstarynk/bismon/
## file BUILD-BISMON.bash
##
## BISMON 
## Copyright © 2020 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
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
if [ ! -x ./BISMON-config -o  ./BISMON-config -ot BISMON-config.cc ]; then
    if g++ -std=gnu++17 -Wall -Wextra -O -g BISMON-config.cc -lunistring -lreadline -o ./BISMON-config ; then
	@date +"./BISMON-config built ok on %c%n"
    else
	printf "failed to build BISMON-config.\n"
	exit 1
    fi
fi
