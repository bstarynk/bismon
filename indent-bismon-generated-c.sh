#!/bin/bash -x
# SPDX-License-Identifier: GPL-3.0-or-later
# file indent-bismon-generated-c.sh
# for BISMON - see github.com/bstarynk/bismon/
## requirement: indent properly the generated C code passed as
## argument invoked from the Bismon program (see file emitcode_BM.c in
## its ROUTINEOBJNAME_BM (_1gME6zn82Kf_8hzWibLFRfz)
## emit_module°plain_module and the macro
## INDENT_BISMON_GENERATED_C_SCRIPT there...
/bin/cp -a $1 "$1~"
/usr/bin/astyle --mode=c  --convert-tabs  --style=gnu $1
