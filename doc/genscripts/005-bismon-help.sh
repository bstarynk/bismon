#!/bin/bash
# see github.com/bstarynk/bismon/

# file doc/genscripts/005-bismon-help.sh this script is running Bismon
# to get help in doc/ directory
if [ ! -x ../bismon ]; then
    printf "%s: missing bismon executable in %s\n" $0 $(realpath ..) > /dev/stderr
    exit 1
fi

exec ../bismon --help
	    
