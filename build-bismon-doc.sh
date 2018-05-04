#!/bin/bash -vx
# file build-bismon-doc.sh
## requirement: generate PDF (with hyperlinks) and HTML5
# considering following typesetters
# LuaLaTeX https://www.tug.org/texlive/ http://www.luatex.org/
# & HeVeA http://hevea.inria.fr/

## but see also
# Patoline: http://patoline.org/
# SaTySFi: https://github.com/gfngfn/SATySFi
# perhaps SILE: http://sile-typesetter.org/
# perhaps POLLEN: https://docs.racket-lang.org/pollen/
# perhaps LEPTON: http://www.math.univ-paris13.fr/~lithiao/Lepton.html
# perhaps ANT: http://mirror.hmc.edu/ctan/systems/ant/

mkdir -p doc/generated/

git log --format=oneline -1 --abbrev=16 --abbrev-commit -q | awk '{printf "\\newcommand{\\mygitcommit}[0]{%s}\n", $1}' > doc/generated/git-commit.tex

date +'\\newcommand{\\mydocdate[0]{%c}%n' > doc/generated/timestamp.tex

for gscript in doc/genscripts/[0-9]*.sh ; do
    gbase="$(basename $gscript .sh)"
    mv "doc/generated/$gbase.tex" "doc/generated/$gbase.tex~"
    $gscript > "doc/generated/$gbase.tex"
done

for svgfile in doc/images/*.svg ; do
    sbase="$(basename $svgfile .svg)"
    inkscape --without-gui --export-pdf="doc/generated/$sbase-fig.pdf" "$svgfile"
    inkscape --without-gui --export-eps="doc/generated/$sbase-fig.eps" "$svgfile"
done


for jpegfile in doc/images/*.jpeg ; do
    jbase="$(basename $jpegfile .jpeg)"
    convert "$jpegfile" "doc/generated/$jbase-img.pdf"
    convert "$jpegfile" "doc/generated/$jbase-img.eps"
done
