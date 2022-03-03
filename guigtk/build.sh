#!/bin/bash -x
## BISMON file guigtk/build.sh
BISMON_SHGIT1=$(git log --format=oneline -q -1 | cut '-d '  -f1 | tr -d '\n' | head -c16)
BISMON_SHGIT2=$(if git status | grep -q 'nothing to commit'; then echo; else echo +; fi)
export BISMON_SHGIT=$(printf %s%s $BISMON_SHGIT1 $BISMON_SHGIT2)
/bin/mv minilisp-bismongtk minilisp-bismongtk~

if [ -z "$BISMON_OPTIM" ]; then
    BISMON_OPTIM="-O1"
fi

errbase=0
for cfile in minilisp.c gtkbismonlisp.c jsonbismonlisp.c ; do
    gcc -Wall -Wextra -g $BISMON_OPTIM -c $cfile -DBISMON_GIT=\"$BISMON_SHGIT\" \
	-DERROR_BASE_NUM=$errbase \
    -I . \
    -I /usr/local/include $(pkg-config --cflags gtk+-3.0 jansson) \
    $cfile
    if [ $? -gt 0 ]; then
	exit $?
    fi
    errbase=$[errbase+1000]
done

gcc -Wall -Wextra -g $BISMON_OPTIM minilisp.o gtkbismonlisp.o jsonbismonlisp.o \
    -L /usr/local/lib $(pkg-config --libs gtk+-3.0 jansson) \
    -o minilisp-bismongtk
