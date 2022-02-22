#!/bin/bash -x
indent  --gnu-style --no-tabs --honour-newlines -T Obj minilispbismon.h
indent  --gnu-style --no-tabs --honour-newlines -T Obj -T GHashTable -T GSequence gtkbismonlisp.c
indent  --gnu-style --no-tabs --honour-newlines -T Obj minilisp.c

