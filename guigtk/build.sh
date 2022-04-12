#!/bin/bash -x
## BISMON file guigtk/build.sh
BISMON_SHGIT1=$(git log --format=oneline -q -1 | cut '-d '  -f1 | tr -d '\n' | head -c16)
BISMON_SHGIT2=$(if git status | grep -q 'nothing to commit'; then echo; else echo +; fi)
export BISMON_SHGIT=$(printf %s%s $BISMON_SHGIT1 $BISMON_SHGIT2)

if [ -f minilisp-bismongtk ]; then
    /bin/mv -v minilisp-bismongtk minilisp-bismongtk~
    /bin/chmod a-x minilisp-bismongtk~
fi

if [ -z "$BISMON_OPTIM" ]; then
    BISMON_OPTIM="-O1"
fi

if [ -z "$BISMON_DEBUG" ]; then
    BISMON_DEBUG="-g3"
fi

if [ -z "$BISMON_GCC" ]; then
    BISMON_GCC="gcc"
fi

if [ -n "$1" ]; then
    BISMON_OPTIM="$BISMON_OPTIM $1"
fi

errbase=0
for cfile in minilisp.c gtkbismonlisp.c jsonbismonlisp.c ; do
    $BISMON_GCC -Wall -Wextra -Wmissing-prototypes $BISMON_OPTIM $BISMON_DEBUG -c $cfile -DBISMON_GIT=\"$BISMON_SHGIT\" \
	-DERROR_BASE_NUM=$errbase \
    -I . \
    -I /usr/local/include $(pkg-config --cflags gtk+-3.0 jansson) \
    $cfile
    if [ $? -gt 0 ]; then
	exit $?
    fi
    errbase=$[errbase+10000]
done

$BISMON_GCC -Wall -Wextra $BISMON_OPTIM $BISMON_DEBUG  minilisp.o gtkbismonlisp.o jsonbismonlisp.o \
    -L /usr/local/lib $(pkg-config --libs gtk+-3.0 jansson) \
    -o minilisp-bismongtk
