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


## force English locale
export  LANG=en_US.UTF-8
export  LC_IDENTIFICATION=en_US.UTF-8
export  LC_NUMERIC=en_US.UTF-8
export  LC_MEASUREMENT=en_US.UTF-8
export  LC_TIME=en_US.UTF-8
export  LC_PAPER=en_US.UTF-8
export  LC_MONETARY=en_US.UTF-8
export  LC_TELEPHONE=en_US.UTF-8
export  LC_NAME=en_US.UTF-8
export  LC_ADDRESS=en_US.UTF-8

declare -a bm_lualatex_args



if [ "$1" = "-d" -o "$1" = "--debug" ]; then
    bm_lualatex_args=(--debug-format --halt-on-error --file-line-error  --interaction=batchmode  --recorder)
    shift
else
    bm_lualatex_args=(--halt-on-error --file-line-error --interaction=batchmode --recorder)
fi

function bm_run_lualatex () {
    if lualatex $bm_lualatex_args $* ; then
	printf "lualatex good for %s\n" "$@"
    else
	printf "lualatex failed for %s - %s\n" "$@" $(caller())
    fi
}

## the optional program argument could be LaTeX or HeVeA or left empty
docmode=$1

if [ -n "$docmode" ]; then
    case "$docmode" in
	LaTeX) printf "%s will produce a PDF document using LuaLaTeX - see www.latex-project.org and www.luatex.org\n" $0;;
	HeVeA) printf "%s should produce an HTML document using HeVeA - see hevea.inria.fr\n" $0;;
	*)
	    printf "%s: invalid mode %s, expecting LaTeX or HeVeA\n" $0 "$docmode" > /dev/stderr
	    exit 1
    esac
fi

## we cannot pass --jobname to lualatex, since it defines the name of the generated PDF file

### inkscape could be in /usr/local/bin since inkscape 1.0 is needed
inkscape --version
lualatex --version

## old inkscape had --without-gui option, which changed in Inkscape 1.0
## this script requires Inkscape 1.0 ; check with inkscape --version
bismon_inkscape_batch_option="--batch-process"

/bin/mkdir -pv doc/generated/
/bin/mkdir -pv doc/htmldoc/

## backup the old pdf file
/bin/mv -vfb doc/bismon-chariot-doc.pdf doc/bismon-chariot-doc.pdf% 

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
/usr/bin/git log -1 '--format=tformat:\newcommand{\bmgitdate}[0]{%ad}' --date=format:%Y-%b-%d >> doc/generated/git-commit.tex
# generate the number of commits; should be doable in a more efficient way
nbc=$(/usr/bin/git log | /bin/grep '^commit' | /usr/bin/wc -l)
printf '\\newcommand{\\bmgitnumbercommits}[0]{%d}\n' $nbc >> doc/generated/git-commit.tex

# generate the dates
/bin/date +'\newcommand{\bmdoctimestamp}[0]{%c}%n\newcommand{\bmdocdate}[0]{%b %d, %Y}' > doc/generated/timestamp.tex




cd doc

printf "@@@BISMONdoc %s process %d is in %s\n\n" $0 $$ $(pwd) > /dev/stderr

################ run generating shell scripts
for gscript in genscripts/[0-9]*.sh ; do
    gbase="$(basename $gscript .sh)"
    mv -vf "generated/$gbase.tex" "generated/$gbase.tex~"
    $gscript > "generated/$gbase.tex"
    if [ -s "generated/$gbase.tex" ]; then
	printf "%s: script-generated %s with %d lines\n" $0 "generated/$gbase.tex"  $(wc -l "generated/$gbase.tex")
    else
	printf "\n@@@BISMONdoc %s process %d failed in %s to generate %s\n" $0 $$ $(pwd) "generated/$gbase.tex" > /dev/stderr
	exit 1
    fi
done

################# generate vector SVG images
for svgfile in images/*.svg ; do
    sbase="$(basename "$svgfile" .svg)"
    if [ -f "$svgfile" ]; then
	if [ ! -f "generated/$sbase-fig.pdf" -o "$svgfile" -nt "generated/$sbase-fig.pdf"  ]; then
	    inkscape $bismon_inkscape_batch_option --export-filename="generated/$sbase-fig.pdf" "$svgfile" || exit 1
	fi
	if  [ ! -f "generated/$sbase-fig.eps"  -o "$svgfile" -nt  "generated/$sbase-fig.eps" ]; then
	    inkscape $bismon_inkscape_batch_option --export-filename="generated/$sbase-fig.eps" "$svgfile" || exit 1
	fi
	/bin/cp -v "$svgfile" "htmldoc/$sbase-fig.svg"
    fi
done

################# generate JPEG images; the convert command is from
################# https://imagemagick.org/
for jpegfile in images/*.jpeg ; do
    if [ -f "$jpegfile" ]; then
	jbase=$(/usr/bin/basename "$jpegfile" .jpeg)
	if [ ! -f "generated/$jbase-img.pdf" -o "$jpegfile" -nt "generated/$jbase-img.pdf" ]; then
	    /usr/bin/convert "$jpegfile" "generated/$jbase-img.pdf"
	fi
	if [ ! -f "generated/$jbase-img.eps" -o t "$jpegfile" -nt "generated/$jbase-img.eps" ]; then
	    /usr/bin/convert "$jpegfile" "generated/$jbase-img.eps"
	fi
	/bin/cp -v  "$jpegfile" "htmldoc/$jbase-img.jpeg"
    fi
done

# link *.png images
for pngfile in images/*.png ; do
    if [ -f "$pngfile" ]; then
	pbase=$(/usr/bin/basename "$pngfile" .png)
	/bin/cp -v "$pngfile" "generated/$pbase-img.png"
	/bin/cp -v "$pngfile" "htmldoc/$pbase-img.png"
    fi
done

if [ -z "$docmode" -o "$docmode" == "LaTeX" ]; then

    printf "@@@BISMONdoc %s process %d LaTeXing in %s\n\n" $0 $$ $(pwd) > /dev/stderr
    bm_run_lualatex --draftmode bismon-chariot-doc && /bin/true
    bibtex bismon-chariot-doc < /dev/null
    bm_run_lualatex  bismon-chariot-doc && /bin/true
    ## on Debian texindy & xindy is inside xindy package
    pwd && /bin/ls -lt bismon-chariot-doc.*
    texindy -v -C utf8 -I latex bismon-chariot-doc.idx >& /tmp/texindy-bismon.log || true
    if texindy -v -C utf8 -I latex bismon-chariot-doc.idx ; then
	printf '\n### %s - texindy succeeded in %s\n' $0 $(pwd)
    else
	echo error $0: texindy failure in $PWD >& /dev/stderr
	exit 1
    fi
    printf '\n\n\n#### %s second pass latexing bismon chariot doc #####\n' "$0" 
    bm_run_lualatex   bismon-chariot-doc && /bin/true
    bibtex bismon-chariot-doc < /dev/null
    if bm_run_lualatex  bismon-chariot-doc ; then
	printf "@@@BISMONdoc %s succeeded lualatexing-ing bismon-chariot-doc\n" $0 
	/bin/ls -lt bismon-chariot-doc.pdf
    else
	printf "\n\n****\n@@@BISMONdoc %s failed to %s bismon-chariot-doc *****\n\n" $0 "$bm_lualatex" >& /dev/stderr
	exit 1
    fi
    [ -d $HOME/tmp/ ] && cp -v bismon-chariot-doc.pdf $HOME/tmp/bismon-chariot-doc-$bmrawgittag.pdf && (cd $HOME/tmp; ln -svf bismon-chariot-doc-$bmrawgittag.pdf bismon-chariot-doc.pdf)

    /bin/ls -l $PWD/*aux $PWD/*/*aux $PWD/*bbl $PWD/*/*bbl
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
/bin/tar -c -f - htmldoc/ | /usr/bin/tardy -Remove_Prefix htmldoc -Prefix bismon-html-doc -User_NAme bismon -Group_NAme bismon | /bin/gzip -9 > bismon-html-doc.tar.gz

printf "\n@@@BISMONdoc %s generated:\n" $0
/bin/ls -lt bismon-html-doc.tar.gz doc/bismon-chariot-doc.pdf || exit 1
printf "\n\n\n"
