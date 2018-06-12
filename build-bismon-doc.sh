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
    sbase="$(basename "$svgfile" .svg)"
    if [ -f "$svgfile" ]; then
	if [ ! -f "generated/$sbase-fig.pdf" -o "$svgfile" -nt "generated/$sbase-fig.pdf"  ]; then
	    inkscape --without-gui --export-pdf="generated/$sbase-fig.pdf" "$svgfile"
	fi
	if  [ ! -f "generated/$sbase-fig.eps"  -o "$svgfile" -nt  "generated/$sbase-fig.eps" ]; then
	    inkscape --without-gui --export-eps="generated/$sbase-fig.eps" "$svgfile"
	fi
	cp -v "$svgfile" "htmldoc/$sbase-fig.svg"
    fi
done

# generate JPEG images
for jpegfile in images/*.jpeg ; do
    if [ -f "$jpegfile" ]; then
	jbase=$(basename "$jpegfile" .jpeg)
	if [ ! -f "generated/$jbase-img.pdf" -o "$jpegfile" -nt "generated/$jbase-img.pdf" ]; then
	    convert "$jpegfile" "generated/$jbase-img.pdf"
	fi
	if [ ! -f "generated/$jbase-img.eps" -o t "$jpegfile" -nt "generated/$jbase-img.eps" ]; then
	    convert "$jpegfile" "generated/$jbase-img.eps"
	fi
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
bibtex bismon-doc
pdflatex -halt-on-error bismon-doc
ls -l $PWD/*aux $PWD/*/*aux $PWD/*bbl $PWD/*/*bbl
hevea -v -o htmldoc/bismon-htmldoc.html -e bismon-latex.tex svg.hva bismon-hevea.hva bismon-doc
#bibhva bismon-doc
bibhva htmldoc/bismon-htmldoc
ls -l $PWD/*aux $PWD/*/*aux 
hevea -v -o htmldoc/bismon-htmldoc.html -e bismon-latex.tex -fix svg.hva bismon-hevea.hva bismon-doc
#hacha -o htmldoc/index.html  htmldoc/bismon-htmldoc.html
tar -cz -f bismondoc-html.tar.gz  htmldoc 
