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
make -f $(dirname $0)/GNUmakefile -e "VPATH=$(pwd):$(dirname $0)" modubin/modbm$MODULEID.so
makestatus=$?
#echo '@*@!!@*@' in $(pwd) makestatus $makestatus > /dev/tty
if [ $makestatus -ne 0 ]; then
    cp -v modules/modbm${MODULEID}.c modules/badmodbm${MODULEID}.c
    logger --id=$$ -s -t persistent-module-build-bismon -p user.debug make for $MODULEID failed with $makestatus
    exit $makestatus
else
    logger --id=$$ -s -t persistent-module-build-bismon -p user.debug make for $MODULEID completed
fi

