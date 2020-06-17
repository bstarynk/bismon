#!/bin/bash

# file doc/genscripts/003-ssaopt-factinline.sh this script is running
# in doc/ directory and extracts the SSA & optimized forms of
# examples/factinline12.c

printf "@@@BISMONDOC starting %s %s cwd %s:\n" "$0" "$@" $(pwd) > /dev/stderr

/bin/ls -lst generated/factinline12.c*  > /dev/stderr

cd generated/
if [ ! -f factinline12.c.[0-9]*t.ssa ]; then
    echo missing single 'factinline12.c.[0-9]*t.ssa' file > /dev/stderr
    exit 1
fi

if [ ! -f factinline12.c.[0-9]*t.optimized ]; then
    echo missing single 'factinline12.c.[0-9]*t.optimized' file > /dev/stderr
    exit 1
fi

if [ ! -f factinline12.s ]; then
    echo missing factinline12.s file > /dev/stderr
    exit 1
fi

ln -svf factinline12.c.[0-9]*t.ssa factinline12.ssa 1>&2

ln -svf factinline12.c.[0-9]*t.optimized factinline12.optimized 1>&2

printf '\\begin{table}[h]\n'
printf '\\caption{\\label{tab:factinlinessa} recursive inlining with constant folding in \\emph{GCC} (generated SSA form)}\n'
printf '   \\medskip\n'
printf '  \\begin{center}\n'
printf '    \\begin{relsize}{-1.6}\n'
printf '     \\begin{tabular}{c}\n'
printf '      \\begin{minipage}{0.88\\textwidth}\n'
printf '\\begin{verbatim}\n'
awk  '/^ *$/{next} /^\}$/{printf "}\n\n"; next;} //{print}'  factinline12.ssa
printf '\\end{verbatim}\n'
printf '      \\end{minipage}\n'
printf '      \\\\ \n'
printf '       \\textbf{{\\emph{Static Single Assignment (SSA) code}}} \\\\ \n'
printf '      \\\\ \n'
printf '      \\end{tabular}\n'
printf '    \\end{relsize}\n'
printf '  \\end{center}\n'
printf '\\end{table}\n'

printf '\n\n%%%%%%\n\n'


printf '\\begin{table}[t]\n'
printf '\\caption{\\label{tab:factinlineoptim} recursive inlining with constant folding in \\emph{GCC} (generated optimized)}\n'
printf '   \\medskip\n'
printf '  \\begin{center}\n'
printf '    \\begin{relsize}{-1.6}\n'
printf '     \\begin{tabular}{c}\n'
printf '      \\begin{minipage}{0.88\\textwidth}\n'
printf '\\begin{verbatim}\n'
awk  '/^ *$/{next} /^\}$/{printf "}\n\n"; next;} //{print}'  factinline12.optimized
printf '\\end{verbatim}\n'
printf '      \\end{minipage}\n'
printf '      \\\\ \n'
printf '       \\textbf{{\\emph{optimized form}}} \\\\ \n'
printf '      \\\\ \n'
printf '      \\end{tabular}\n'
printf '    \\end{relsize}\n'
printf '  \\end{center}\n'
printf '\\end{table}\n'

printf '\n\n%%%%%%\n\n'

printf '\\begin{table}[t]\n'
printf '\\caption{\\label{tab:factinlineasm} recursive inlining with constant folding in \\emph{GCC} (generated MIPS assembler)}\n'
printf '   \\medskip\n'
printf '  \\begin{center}\n'
printf '    \\begin{relsize}{-1.5}\n'
printf '     \\begin{tabular}{c}\n'
printf '      \\begin{minipage}{0.88\\textwidth}\n'
printf '\\begin{verbatim}\n'
nbskip=$(fgrep -n .text factinline12.s|cut -d: -f1)
printf '### skipped %d lines in factinline12.s\n' $nbskip
echo
tail -n +$nbskip factinline12.s | sed s:../examples/::g
printf '\\end{verbatim}\n'
printf '      \\end{minipage}\n'
printf '      \\\\ \n'
printf '       \\textbf{{\\emph{MIPS assembler}}} \\\\ \n'
printf '      \\\\ \n'
printf '      \\end{tabular}\n'
printf '    \\end{relsize}\n'
printf '  \\end{center}\n'
printf '\\end{table}\n'

printf '\n\n%%%%%%\n\n'
