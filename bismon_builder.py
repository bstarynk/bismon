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
of the Bismon static analyzer (GPLv3+ licensed).
See https://github.com/bstarynk/bismon for more.
Debugging of this script might be done with the help of pdb.
See https://docs.python.org/3/library/pdb.html for more.
Or try running the command: python3 -m pdb ./bismon_builder.py
'''

import os                       # https://docs.python.org/3/library/os.html
#import subprocess               # https://docs.python.org/3/library/subprocess.html
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
        self.git_id = self.last_commit.hex
        self.args = None
    #
    def __str__(self):
        return 'BismonBuilder<repo:{0}, git-commit:{1}>'.format(self.this_repo.path,
                                                                self.git_id[:12])
    #
    def parse_program_arguments(self):
        '''Parse the program arguments, i.e. to execve(2) of this script.'''
        argparser = argparse.ArgumentParser(description=
                                            '''the builder of the Bismon static source code analyzer
(GPLv3+ licensed, on github.com/bstarynk/bismon/ ...)''',
                                            epilog='''funded by chariotproject.eu
 & decoder-project.eu, developed at www-list.cea.fr''',
                                            allow_abbrev=True
                                            )
        argparser.add_argument('-V', "--version", help="show script version of %(prog)s",
                               action='version',
                               version=('Bismon_builder {0}'.format(self.git_id)))
        argparser.add_argument('-M', '--module', metavar='MODULE_DIR',
                               required=True,
                               help='''compile a persistent module  of given --oid
(whose C++ code is in directory <MODULE_DIR>/ as file modbm_<OID>.cc)''')
        argparser.add_argument('-n', '--dry-run',
                               metavar='DRY_RUN',
                               action='store_true',
                               help='''just show the compilation command but do not run it''')
        argparser.add_argument('-D', '--debug',
                               metavar='DEBUG',
                               action='store_true',
                               help='''debug output of this script''')
        argparser.add_argument('-T', '--tempmodule',
                               metavar='TEMP_MODULE_DIR',
                               required=True,
                               help='''compile a temporary module  of given --oid
(whose C++ code is in directory <TEMP_MODULE_DIR>/ as file tmpmobm_<OID>.cc)''')
        argparser.add_argument('-O', '--oid', metavar='OID',
                               required=True,
                               help='''gives the object-id of a temporary or persistent module
(see also --module <MODULE_DIR> and -- tempmodule <TEMP_MODULE_DIR> options''')
        argparser.add_argument('-N', '--ninja',
                               help='''Generates a ninja.build file for ninja
(see www.ninja-build.org)''',
                               metavar='NINJA',
                               action='store_true')
        argparser.add_argument('-C', '--cflags', metavar='CFLAGS',
                               required=True,
                               help='''give the compilation flags for GCC''')
        self.args = argparser.parse_args()
    #
    def run(self):
        '''run appropriate processes'''
        if self.args.DEBUG:
            print("BismonBuilder debugging:", self)
            print("BismonBuilder args:", self.args)
            print("BismonBuilder CFLAGS:", self.args.CFLAGS)
            print("BismonBuilder DRY_RUN:", self.args.DRY_RUN)
            print("BismonBuilder MODULE_DIR:", self.args.MODULE_DIR)
            print("BismonBuilder NINJA:", self.args.NINJA)
            print("BismonBuilder OID:", self.args.OID)
            print("BismonBuilder TEMP_MODULE_DIR:", self.args.TEMP_MODULE_DIR)
        raise RuntimeError("BismonBuilder.run unimplemented")

    # other methods of BismonBuilder should go here...
## end class BismonBuilder

################
BUILDER = BismonBuilder()

BUILDER.parse_program_arguments()

print(BUILDER)

BUILDER.run()

# bismon_cc_version= subprocess.Popen([bismon_cc, "--version"])
# print("Bismon C compiler version is", bismon_cc_version)

##-**************
##-                           for Emacs...
##- Local Variables: ;;
##- compile-command: "pylint bismon_builder.py" ;;
##- End: ;;
##-**************/
