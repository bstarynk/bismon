#!/bin/bash -x
indent  --gnu-style --no-tabs --honour-newlines -T Obj -T json_t minilispbismon.h
indent  --gnu-style --no-tabs --honour-newlines -T Obj -T GHashTable -T GSequence -T json_t gtkbismonlisp.c
indent  --gnu-style --no-tabs --honour-newlines -T Obj -T json_t jsonbismonlisp.c
indent  --gnu-style --no-tabs --honour-newlines -T Obj  gtkbismonlisp.c
indent  --gnu-style --no-tabs --honour-newlines -T Obj -T json_t minilisp.c

