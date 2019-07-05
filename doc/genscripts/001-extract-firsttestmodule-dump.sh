#!/bin/sh
# file doc/genscripts/001-extract-firsttestmodule-dump.sh

# this script is running in doc/ directory and extracts the dump of
# object first_test_module in store2.bmon
echo running genscripts/001-extract-firsttestmodule-dump.sh on $(wc -l ../store2.bmon) 1>&2

sed -e '/«_9oXtCgAbkqv_4y1xhhF5Nhz/,/»_9oXtCgAbkqv_4y1xhhF5Nhz/p' -n ../store2.bmon 
