#!/bin/sh
# file doc/genscripts/000-lastgitcommits.sh

# this script is running in doc/ directory and extracts the last 4 commits of the entire bismon system.

printf '\\begin{verbatim}\n'
(cd ..; git log  --name-status -4)
printf '\n\\end{verbatim}\n'
