#!/bin/bash
# file build-bismon-module.sh
MODULEID=$1
logger --id=$$ -s -t build-bismon-module -p user.debug starting moduleid $MODULEID in $(pwd) at $(date +%c)
exec make -f $(dirname $0)/Makefile --silent singlemodule MODULEID=$MODULEID
