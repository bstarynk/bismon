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
mkdir -p doc/htmldoc/
rm -f doc/generated/*

# generate the git tag
git log --format=oneline -1 --abbrev=16 --abbrev-commit -q | awk '{printf "\\newcommand{\\bmgitcommit}[0]{%s}\n", $1}' > doc/generated/git-commit.tex

# generate the dates
date +'\newcommand{\bmdoctimestamp}[0]{%c}%n\newcommand{\bmdocdate}[0]{%b %d, %Y}' > doc/generated/timestamp.tex

cd doc


for gscript in genscripts/[0-9]*.sh ; do
    gbase="$(basename $gscript .sh)"
    mv "generated/$gbase.tex" "generated/$gbase.tex~"
    $gscript > "generated/$gbase.tex"
done

# generate vector SVG images
for svgfile in images/*.svg ; do
    if [ -f "$svgfile" ]; then
	sbase="$(basename "$svgfile" .svg)"
	inkscape --without-gui --export-pdf="generated/$sbase-fig.pdf" "$svgfile"
	inkscape --without-gui --export-eps="generated/$sbase-fig.eps" "$svgfile"
	cp -v "$svgfile" "htmldoc/$sbase-fig.svg"
    fi
done

# generate JPEG images
for jpegfile in images/*.jpeg ; do
    if [ -f "$jpegfile" ]; then
	jbase=$(basename "$jpegfile" .jpeg)
	convert "$jpegfile" "generated/$jbase-img.pdf"
	convert "$jpegfile" "generated/$jbase-img.eps"
	cp -v  "$jpegfile" "htmldoc/$jbase-img.jpeg"
    fi
done

# link *.png images
for pngfile in images/*.png ; do
    if [ -f "$pngfile" ]; then
	pbase=$(basename "$pngfile" .png)
	cp -v "$pngfile" "generated/$pbase-img.png"
	cp -v "$pngfile" "htmldoc/$pbase-img.png"
    fi
done

pdflatex -halt-on-error bismon-doc
bibtex bismon-doc
pdflatex -halt-on-error bismon-doc
makeindex bismon-doc
pdflatex -halt-on-error bismon-doc
pdflatex -halt-on-error bismon-doc
hevea -o htmldoc/bismon-htmldoc.html -e bismon-latex.tex -fix svg.hva bismon-hevea.hva bismon-doc
