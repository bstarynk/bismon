#!/bin/bash -x
## BISMON file guigtk/build.sh
BISMON_SHGIT1=$(git log --format=oneline -q -1 | cut '-d '  -f1 | tr -d '\n' | head -c16)
BISMON_SHGIT2=$(if git status | grep -q 'nothing to commit'; then echo; else echo +; fi)
export BISMON_SHGIT=$(printf %s%s $BISMON_SHGIT1 $BISMON_SHGIT2)
gcc -Wall -Wextra -g minilisp.c gtkbismonlisp.c -DBISMON_GIT=\"$BISMON_SHGIT\" \
    -I . \
    -I /usr/local/include $(pkg-config --cflags gtk+-3.0 jansson) \
    -L /usr/local/lib $(pkg-config --libs gtk+-3.0 jansson) \
    -o minilisp-bismongtk
