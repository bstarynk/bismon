#!/bin/bash
# file build-bismon-persistent-module.sh
MODULEID=$1
logger --id=$$ -s -t build-bismon-persistent-module -p user.debug starting moduleid $MODULEID in $(pwd) at $(date +%c)
#echo '@*@*@' $0 "$@" '::: in' $(pwd) > /dev/tty
#echo '@*@!!@*@' ls -ls  mod*/*${MODULEID}* > /dev/tty
#ls -ls mod*/*${MODULEID}* > /dev/tty
#(ls -lsd modules modubin; pwd) > /dev/tty
# remove --silent in make
#echo '@*@!!@*@' in $(pwd) should-make "-f $(dirname $0)/Makefile -e "VPATH=$(pwd):$(dirname $0)" modubin/modbm$MODULEID.so" > /dev/tty
make -f $(dirname $0)/Makefile -e "VPATH=$(pwd):$(dirname $0)" modubin/modbm$MODULEID.so
makestatus=$?
#echo '@*@!!@*@' in $(pwd) makestatus $makestatus > /dev/tty
if [ $makestatus -ne 0 ]; then
    logger --id=$$ -s -t build-bismon-persistent-module -p user.debug make for $MODULEID failed with $makestatus
    exit $makestatus
else
    logger --id=$$ -s -t build-bismon-persistent-module -p user.debug make for $MODULEID completed
fi

