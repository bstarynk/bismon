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

## the optional program argument could be LaTeX or HeVeA or left empty
docmode=$1

if [ -n "$docmode" ]; then
    case "$docmode" in
	LaTeX) break;;
	HeVeA) break;;
	*)
	    printf "%s: invalid mode %s, expecting LaTeX or HeVeA\n" $0 "$docmode" > /dev/stderr
	    exit 1
    esac
fi

## old inkscape had --without-gui option, which changed in Inkscape 1.0
bismon_inkscape_batch_option="--batch-process"

mkdir -pv doc/generated/
mkdir -pv doc/htmldoc/

## backup the old pdf file
mv -vfb doc/bismon-chariot-doc.pdf doc/bismon-chariot-doc.pdf% 

# generate the git tag and date
bmrawgittag="$(git log --format=oneline -1 --abbrev=16 --abbrev-commit -q|cut -d' ' -f1)"
export BISMON_GIT_TAG=$bmrawgittag
if git status -s | grep -q '^.M' > /dev/null ; then
    [ -f doc/generated/git-commit.tex ] && mv -vf doc/generated/git-commit.tex doc/generated/git-commit.tex+dirty%
    bmgittag=$(printf "%s++" "$bmrawgittag")
else
    [ -f doc/generated/git-commit.tex ] && mv -vf doc/generated/git-commit.tex doc/generated/git-commit.tex+clean~
    bmgittag=$(printf "%s..." "$bmrawgittag")
fi
printf "\\\\newcommand{\\\\bmgitcommit}[0]{%s}\n" "$bmgittag" > doc/generated/git-commit.tex
git log -1 '--format=tformat:\newcommand{\bmgitdate}[0]{%ad}' --date=format:%Y-%b-%d >> doc/generated/git-commit.tex
# generate the number of commits; should be doable in a more efficient way
nbc=$(git log | grep '^commit' | wc -l)
printf '\\newcommand{\\bmgitnumbercommits}[0]{%d}\n' $nbc >> doc/generated/git-commit.tex

# generate the dates
date +'\newcommand{\bmdoctimestamp}[0]{%c}%n\newcommand{\bmdocdate}[0]{%b %d, %Y}' > doc/generated/timestamp.tex




cd doc

printf "@@@BISMONdoc %s process %d is in %s\n\n" $0 $$ $(pwd) > /dev/stderr


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
	    inkscape $bismon_inkscape_batch_option --export-filename="generated/$sbase-fig.pdf" "$svgfile" || exit 1
	fi
	if  [ ! -f "generated/$sbase-fig.eps"  -o "$svgfile" -nt  "generated/$sbase-fig.eps" ]; then
	    inkscape $bismon_inkscape_batch_option --export-filename="generated/$sbase-fig.eps" "$svgfile" || exit 1
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

    printf "@@@BISMONdoc %s process %d LaTeXing in %s\n\n" $0 $$ $(pwd) > /dev/stderr
    lualatex -halt-on-error bismon-chariot-doc 
    bibtex bismon-chariot-doc < /dev/null
    lualatex -halt-on-error bismon-chariot-doc 
    ## on Debian texindy & xindy is inside indy package
    pwd && ls -lt bismon-chariot-doc.*
    texindy -v -C utf8 -I latex bismon-chariot-doc.idx >& /tmp/texindy-bismon.log || true
    if texindy -v -C utf8 -I latex bismon-chariot-doc.idx ; then
	echo error texindy failure in $PWD >& /dev/stderr
    fi
    printf '\n\n\n#### second pass latexing bismon chariot doc #####\n'
    lualatex -halt-on-error bismon-chariot-doc 
    bibtex bismon-chariot-doc < /dev/null
    lualatex -halt-on-error bismon-chariot-doc || (echo failed lualatex -halt-on-error bismon-chariot-doc got $? ; exit $? >/dev/stderr)
    [ -d $HOME/tmp/ ] && cp -v bismon-chariot-doc.pdf $HOME/tmp/bismon-chariot-doc-$bmrawgittag.pdf && (cd $HOME/tmp; ln -svf bismon-chariot-doc-$bmrawgittag.pdf bismon-chariot-doc.pdf)

    ls -l $PWD/*aux $PWD/*/*aux $PWD/*bbl $PWD/*/*bbl
fi

if [ -z  "$docmode" -o "$docmode" == "HeVeA" ]; then
    printf "@@@BISMONdoc %s process %d HeVeA-ing in %s\n\n" $0 $$ $(pwd) > /dev/stderr
    hevea -v -o htmldoc/bismon-htmldoc.html -e bismon-latex.tex svg.hva bismon-hevea.hva bismon-chariot-doc
#bibhva bismon-chariot-doc
    bibhva htmldoc/bismon-htmldoc
    ls -l $PWD/*aux $PWD/*/*aux 
    hevea -v -o htmldoc/bismon-htmldoc.html -e bismon-latex.tex -fix svg.hva bismon-hevea.hva bismon-chariot-doc
    #hacha -o htmldoc/index.html  htmldoc/bismon-htmldoc.html
fi

printf "\n@@@BISMONdoc %s process %d making final tarball in %s\n" $0 $$ $(pwd)
tar -c -f - htmldoc/ | tardy -Remove_Prefix htmldoc -Prefix bismon-html-doc -User_NAme bismon -Group_NAme bismon | gzip -9 > bismon-html-doc.tar.gz

printf "\n@@@BISMONdoc %s generated:\n" $0
/bin/ls -lt bismon-html-doc.tar.gz doc/bismon-chariot-doc.pdf || exit 1
printf "\n\n\n"
