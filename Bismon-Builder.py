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
global bismon_cc
# https://stackoverflow.com/q/40697845/841108
bismon_cc= os.getenv("BISMON_CC", "gcc")



class Bismon_Builder:
    def __init__(self):
        from pygit2 import Repository
        self.this_repo = Repository(".")
        self.last_commit = self.this_repo.revparse_single('HEAD')
        self.git_id = self.last_commit.oid
    def __str__(self):
        return 'Bismon_Builder<repo:{0}, git-commit:{1}>'.format(self.this_repo.path, self.git_id.__str__()[:12])

builder = Bismon_Builder()

print (builder)
# bismon_cc_version= subprocess.Popen([bismon_cc, "--version"])
# print("Bismon C compiler version is", bismon_cc_version)
