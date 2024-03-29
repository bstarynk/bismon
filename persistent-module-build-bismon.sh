#!/bin/bash
# file persistent-module-build-bismon.sh
# GPLv3+ licensed, see http://github.com/bstarynk/bismon/
MODULEID=$1
logger --id=$$ -s -t persistent-module-build-bismon -p user.debug starting moduleid $MODULEID in $(pwd) at $(date +%c)
#echo '@*@*@' $0 "$@" '::: in' $(pwd) > /dev/tty
#echo '@*@!!@*@' ls -ls  mod*/*${MODULEID}* > /dev/tty
#ls -ls mod*/*${MODULEID}* > /dev/tty
#(ls -lsd modules modubin; pwd) > /dev/tty
# remove --silent in make
#echo '@*@!!@*@' in $(pwd) should-make "-f $(dirname $0)/Makefile -e "VPATH=$(pwd):$(dirname $0)" modubin/modbm$MODULEID.so" > /dev/tty

if ! [ -f modules/modbm$MODULEID.c ]; then
    logger --id=$$ -s -t persistent-module-build-bismon -p user.notice no source module file  modules/modbm$MODULEID.c in $(pwd)
    exit 10
fi

if ! [ -f $(dirname $0)/GNUmakefile ]; then
    logger --id=$$ -s -t persistent-module-build-bismon -p user.notice missing  $(dirname $0)/GNUmakefile  in $(pwd)
    exit 11
fi

MODULEMD5=$(/usr/bin/md5sum modules/modbm$MODULEID.c | cut -d\   -f1)

logger --id=$$ -s -t persistent-module-build-bismon -p user.debug before make BISMON_MODULE_ID=$MODULEID BISMON_MODULE_MD5SUM=$MODULEMD5 modubin/modbm$MODULEID.so

make -f $(dirname $0)/GNUmakefile -e "VPATH=$(pwd):$(dirname $0)" \
     BISMON_MODULE_ID=$MODULEID \
     BISMON_MODULE_MD5SUM=$MODULEMD5 \
     modubin/modbm$MODULEID.so
makestatus=$?
#echo '@*@!!@*@' in $(pwd) makestatus $makestatus > /dev/tty
if [ $makestatus -ne 0 ]; then
    cp -v modules/modbm${MODULEID}.c modules/badmodbm${MODULEID}.c
    logger --id=$$ -s -t persistent-module-build-bismon -p user.debug make for $MODULEID failed with $makestatus
    exit $makestatus
else
    logger --id=$$ -s -t persistent-module-build-bismon -p user.debug make for $MODULEID completed
fi

