#!/bin/bash -x
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

docmode=$1

mkdir -p doc/generated/
mkdir -p doc/htmldoc/

## backup the old pdf file
mv -vfb doc/bismon-chariot-doc.pdf doc/bismon-chariot-doc.pdf% 

# generate the git tag and date
bmgittag=$(git log --format=oneline -1 --abbrev=16 --abbrev-commit -q|cut -d' ' -f1)
git log --format=oneline -1 --abbrev=16 --abbrev-commit -q | awk '{printf "\\newcommand{\\bmgitcommit}[0]{%s}\n", $1}' > doc/generated/git-commit.tex
git log -1 '--format=tformat:\newcommand{\bmgitdate}[0]{%ad}' --date=format:%Y-%b-%d >> doc/generated/git-commit.tex
# generate the number of commits; should be doable in a more efficient way
nbc=$(git log | grep '^commit' | wc -l)
printf '\\newcommand{\\bmgitnumbercommits}[0]{%d}\n' $nbc >> doc/generated/git-commit.tex

# generate the dates
date +'\newcommand{\bmdoctimestamp}[0]{%c}%n\newcommand{\bmdocdate}[0]{%b %d, %Y}' > doc/generated/timestamp.tex

cd doc


for gscript in genscripts/[0-9]*.sh ; do
    gbase="$(basename $gscript .sh)"
    mv -vf "generated/$gbase.tex" "generated/$gbase.tex~"
    $gscript > "generated/$gbase.tex"
    echo "script-generated" $(wc -l "generated/$gbase.tex")
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

if [ -z "$docmode" -o "$docmode" == "LaTeX" ]; then
    lualatex -halt-on-error bismon-chariot-doc 
    bibtex bismon-chariot-doc < /dev/null
    lualatex -halt-on-error bismon-chariot-doc 
    ## on Debian texindy & xindy is inside indy package
    pwd && ls -lt bismon-chariot-doc.*
    if texindy -v -C utf8 -I latex bismon-chariot-doc.idx ; then
	echo texindy failure in $PWD > /dev/stderr
	exit 1
    fi
    printf '\n\n\n#### second pass latexing bismon chariot doc #####\n'
    lualatex -halt-on-error bismon-chariot-doc 
    bibtex bismon-chariot-doc < /dev/null
    lualatex -halt-on-error bismon-chariot-doc || (echo failed lualatex -halt-on-error bismon-chariot-doc got $? ; exit $? >/dev/stderr)
    [ -d $HOME/tmp/ ] && cp -v bismon-chariot-doc.pdf $HOME/tmp/bismon-chariot-doc-$bmgittag.pdf && (cd $HOME/tmp; ln -svf bismon-chariot-doc-$bmgittag.pdf bismon-chariot-doc.pdf)

    ls -l $PWD/*aux $PWD/*/*aux $PWD/*bbl $PWD/*/*bbl
fi

if [ -z  "$docmode" -o "$docmode" == "HeVeA" ]; then
    hevea -v -o htmldoc/bismon-htmldoc.html -e bismon-latex.tex svg.hva bismon-hevea.hva bismon-chariot-doc
#bibhva bismon-chariot-doc
    bibhva htmldoc/bismon-htmldoc
    ls -l $PWD/*aux $PWD/*/*aux 
    hevea -v -o htmldoc/bismon-htmldoc.html -e bismon-latex.tex -fix svg.hva bismon-hevea.hva bismon-chariot-doc
    #hacha -o htmldoc/index.html  htmldoc/bismon-htmldoc.html
fi

tar -c -f - htmldoc/ | tardy -Remove_Prefix htmldoc -Prefix bismon-html-doc -User_NAme bismon -Group_NAme bismon | gzip -9 > bismon-html-doc.tar.gz
