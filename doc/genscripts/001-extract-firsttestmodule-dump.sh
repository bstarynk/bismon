#!/bin/bash
# file doc/genscripts/001-extract-firsttestmodule-dump.sh

printf "@@@BISMONDOC starting %s %s cwd %s:\n" "$0" "$*" $(pwd) > /dev/stderr

# this script is running in doc/ directory and extracts the dump of
# object first_test_module in store2-BISMON.bmon
echo running genscripts/001-extract-firsttestmodule-dump.sh on $(wc -l ../store2-BISMON.bmon) 1>&2

sed -e '/«_9oXtCgAbkqv_4y1xhhF5Nhz/,/»_9oXtCgAbkqv_4y1xhhF5Nhz/p' -n ../store2-BISMON.bmon
## eof  doc/genscripts/001-extract-firsttestmodule-dump.sh
