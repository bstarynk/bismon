#!/usr/bin/python3
## SPDX-License-Identifier: GPL-3.0-or-later
## See https://github.com/bstarynk/bismon/
## file bismon_builder.py
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
'''
The bismon_builder.py script (for Python 3) is used to generate the build related files
of the Bismon static analyzer (GPLv3+ licensed). See https://github.com/bstarynk/bismon
for more.
'''

import os                       # https://docs.python.org/3/library/os.html
import subprocess               # https://docs.python.org/3/library/subprocess.html
import argparse                 # https://docs.python.org/3/library/argparse.html
import pygit2                   # https://www.pygit2.org/

## we first need a working GCC 10 compiler, which could be overridden
## with the $BISMON_CC environment variable
# https://stackoverflow.com/q/40697845/841108
BISMON_CC = os.getenv("BISMON_CC", "gcc")



class BismonBuilder:
    '''the BismonBuilder class is used to generate build automation files related to
https://github.com/bstarynk/bismon/ open source static analysis software.
    '''
    def __init__(self):
        self.this_repo = pygit2.Repository(".")
        self.last_commit = self.this_repo.revparse_single('HEAD')
        self.git_id = self.last_commit.oid
    def __str__(self):
        return 'BismonBuilder<repo:{0}, git-commit:{1}>'.format(self.this_repo.path,
                                                                self.git_id.__str__()[:12])
    def parse_program_arguments(self):
        argparser = argparse.ArgumentParser(description=
                                            '''the builder of the Bismon static source code analyzer
(GPLv3+ licensed, on github.com/bstarynk/bismon/ ...)''',
                                            epilog='''funded by chariotproject.eu
 & decoder-project.eu, developed at www-list.cea.fr''',
                                            allow_abbrev=True
                                            )
        argparser.add_argument('-V', "--version", help="show script version of %(prog)s",
                               version=('Bismon_builder {0}' % (self.git_id.str())))


builder = BismonBuilder()

builder.parse_program_arguments()

print(builder)
# bismon_cc_version= subprocess.Popen([bismon_cc, "--version"])
# print("Bismon C compiler version is", bismon_cc_version)

##-**************
##-                           for Emacs...
##- Local Variables: ;;
##- compile-command: "pylint bismon_builder.py" ;;
##- End: ;;
##-**************/
