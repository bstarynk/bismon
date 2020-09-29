#!/usr/bin/python3
## SPDX-License-Identifier: GPL-3.0-or-later
## See https://github.com/bstarynk/bismon/
## file Bismon-Builder.py
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
import os                       # https://docs.python.org/3/library/os.html
import subprocess               # https://docs.python.org/3/library/subprocess.html
import argparse                 # https://docs.python.org/3/library/argparse.html
import pygit2                   # https://www.pygit2.org/

## we first need a working GCC 10 compiler, which could be overridden
## with the $BISMON_CC environment variable
bismon_cc="gcc"
if os.environ["BISMON_CC"]:
    bismon_cc=os.environ["BISMON_CC"]


bismon_cc_version= subprocess.Popen([bismon_cc, "--version"])
print("Bismon C compiler version is", bismon_cc_version)
