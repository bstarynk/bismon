#!/bin/bash
# file doc/genscripts/002-gimple-factinline.sh
# this script is running in doc/ directory and extracts the gimple of examples/factinline12.c
printf "@@@BISMONDOC starting %s %s cwd %s:\n" "$0" "$*" $(pwd) > /dev/stderr

source genscripts/cross-gcc-config.bash
cd generated/
rm -vf factinline12.c.[0-9]*t.[a-z]* 1>&2
rm -vf factinline12-gimple* 1>&2
rm -vf factinline12.s 1>&2
$XGCC -O3 -S -fdump-tree-gimple  -fdump-tree-ssa -fdump-tree-optimized -fverbose-asm ../examples/factinline12.c  1>&2
(ls -ls $PWD/factinline*) 1>&2
if [ ! -f factinline12.c.0*t.gimple ]; then
    echo missing single 'factinline12.c.0*t.gimple' file > /dev/stderr
    exit 1
fi
echo "//" factinline12.c.0*t.gimple "generated by ..." >> factinline12.c.0*t.gimple
echo "//... $XGCC -O3 -S -fverbose-asm \\" >> factinline12.c.0*t.gimple
echo "//...  -fdump-tree-gimple  -fdump-tree-ssa -fdump-tree-optimized factinline12.c" >> factinline12.c.0*t.gimple

ln -svf factinline12.c.0*t.gimple factinline12-gimple.c 1>&2


printf '\\begin{table}[!htbp]\n'
printf '\\caption{\\label{tab:factinlinegimple} recursive inlining with constant folding in \\emph{GCC} (generated early Gimple)}\n'
printf '   \\medskip\n'
printf '  \\begin{center}\n'
printf '    \\begin{relsize}{-1.6}\n'
printf '     \\begin{tabular}{c}\n'
printf '      \\begin{minipage}{0.88\\textwidth}\n'
printf '\\begin{verbatim}\n'
awk  '/^ *$/{next} /^\}$/{printf "}\n\n"; next;} //{print}'  factinline12.c.0*t.gimple
printf '\\end{verbatim}\n'
printf '      \\end{minipage}\n'
printf '      \\\\ \n'
printf '       \\textbf{{\\emph{Gimple code}}} \\\\ \n'
printf '      \\\\ \n'
printf '      \\end{tabular}\n'
printf '    \\end{relsize}\n'
printf '  \\end{center}\n'
printf '\\end{table}\n'

