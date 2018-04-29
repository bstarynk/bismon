#!/bin/bash
# file build-bismon-module.sh
MODULEID=$1
logger --id=$$ -s -t build-bismon-module -p user.debug starting moduleid $MODULEID in $(pwd) at $(date +%c)
make -f $(dirname $0)/Makefile --silent singlemodule MODULEID=$MODULEID
makestatus=$?
if [ $makestatus -ne 0 ]; then
    logger --id=$$ -s -t build-bismon-module -p user.debug make for $MODULEID failed with $makestatus
    exit $makestatus
else
    logger --id=$$ -s -t build-bismon-module -p user.debug make for $MODULEID completed
fi

