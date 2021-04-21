#!/bin/bash
# file build-bismon-temporary-module.sh
# GPLv3+ licensed, see http://github.com/bstarynk/bismon/
MODULEID=$1
logger --id=$$ -s -t build-bismon-temporary-module -p user.debug starting moduleid $MODULEID in $(pwd) at $(date +%c)
make -f $(dirname $0)/GNUMakefile -e "VPATH=$(pwd):$(dirname $0)" \
     BISMON_MODULE_ID=$MODULEID \
     BISMON_MODULE_MD5SUM=$(/usr/bin/md5sum modules/modbm$MODULEID.c | cut -d\   -f1) modubin/tmpmobm$MODULEID.so
makestatus=$?
if [ $makestatus -ne 0 ]; then
    logger --id=$$ -s -t build-bismon-temporary-module -p user.debug make for $MODULEID failed with $makestatus
    exit $makestatus
else
    logger --id=$$ -s -t build-bismon-temporary-module -p user.debug make for $MODULEID completed
fi

