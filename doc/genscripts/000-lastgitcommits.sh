#!/bin/sh
# file doc/genscripts/000-lastgitcommits.sh

printf "@@@BISMONDOC starting %s %s cwd %s:\n" "$0" "$@" $(pwd) > /dev/stderr

# this script is running in doc/ directory and extracts the last 3 git
# commits of the entire bismon system.

printf '\\begin{Verbatim}\n'
(cd ..; git log  --name-status -3)
printf '\n\\end{Verbatim}\n'
