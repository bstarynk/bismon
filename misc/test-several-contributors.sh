#! /bin/bash
# file misc/test-several-contributors.sh

# to test having several contributors
# 
#    BISMON 
#    Copyright © 2018, 2019 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
#    contributed by Basile Starynkevitch (working at CEA, LIST, France)
#    <basile@starynkevitch.net> or <basile.starynkevitch@cea.fr>
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
#----
#    Contact me (Basile Starynkevitch) by email
#    basile@starynkevitch.net and/or basile.starynkevitch@cea.fr

### For debugging purposes, a useful way might be to run this script as:
###      env BISMON_WRAPPER='gdb --args' BISMON_OPTIMFLAGS='-O0 -g3' \
###        ./misc/test-several-contributors.sh --debug-after-load

## to use valgrind on every bismon run, set the environment variable
## export BISMON_WRAPPER='valgrind --error-exitcode=99'
## to debug every bismon run, use perhaps:
## export BISMON_WRAPPER='gdb --args' BISMON_OPTIMFLAGS='-O0 -g3'

# https://stackoverflow.com/a/9894126/841108
export TOP_PID=$$
# so runbismon below can exit the entire script

## it could be useful to pass --debug-after-load
bismonflags="$@"

if [ ! -f bismon.h ] ; then
   echo Current directory $(pwd) does not contain bismon.h header > /dev/stderr
   exit 1
fi
if [ ! -f store1.bmon ] ; then
   echo Current directory $(pwd) does not contain store1.bmon file > /dev/stderr
   exit 1
fi

make bismon all

rm -vf /tmp/passwords_BM
rm -vf /tmp/fifopwbismon_BM
mkfifo  /tmp/fifopwbismon_BM
echo '# file /tmp/passwords_BM' > /tmp/passwords_BM
chmod go-rwx /tmp/passwords_BM
cp -v contributors_BM /tmp/contributors_BM
ls -ls /tmp/passwords_BM
tar cvf /tmp/bismonstore.tar.gz store*.bmon
ls -ls /tmp/bismonstore.tar.gz

function restorebismondata () {
    modiflist=$(git status -s | cut -d' ' -f3)
    mkdir /tmp/modified-bismon
    for f in $modiflist ; do
	cp -va $f /tmp/modified-bismon/_new_$f
    done
    tar -cv -C /tmp/modified-bismon -f /tmp/bismonmodified.tar.gz .
    rm -rf /tmp/modified-bismon
    echo 'git status before restore'
    git status
    echo
    if [ -f /tmp/bismonstore.tar.gz ]; then
	echo 'restoring Bismon store'
	tar xvf /tmp/bismonstore.tar.gz
	mv -v  /tmp/bismonstore.tar.gz  /tmp/bismonprevstore.tar.gz
    else
	echo 'no /tmp/bismonstore.tar.gz to restore' > /dev/stderr
    fi
    ls -lt /tmp/bismon*.tar.gz
    # restore default trap handing
    trap - EXIT TERM ERR
}

trap restorebismondata EXIT INT TERM ERR

echo
echo 'making bismon'
echo
make bismon all
echo
echo 'before adding contributors'
ls -ls store1.bmon store2.bmon
md5sum store1.bmon store2.bmon
echo


################################
function runbismon () {
    local title=$1
    shift
    args="$@"
    if [ -z "$BISMON_WRAPPER" ] ; then 
	echo run bismon: $title args: "$args"
	if ./bismon $bismonflags \
		    --contributors-file=/tmp/contributors_BM \
		    --passwords-file=/tmp/passwords_BM \
		    "$@" ; then
	    echo OK bismon: $title
	else
	    failcode=$?
	    printf '\n\n!!!!!!! FAIL plain bismon %s - exitcode %d\n' "$title" $failcode
	    echo FAIL bismon: $title "$args"
	    kill $TOP_PID
	fi
    else
	echo wrap "$BISMON_WRAPPER" bismon: $title args: "$args"
	if $BISMON_WRAPPER ./bismon $bismonflags \
		    --contributors-file=/tmp/contributors_BM \
		    --passwords-file=/tmp/passwords_BM \
		    "$@" ; then
	    echo OK wrap "$BISMON_WRAPPER" bismon: $title
	else
	    failcode=$?
	    printf '\n\n!!!!!! FAIL wrapped %s bismon %s - exitcode %d\n' "$BISMON_WRAPPER" "$title" $failcode
	    echo FAIL wrap "$BISMON_WRAPPER" bismon: $title "$args"
	    kill $TOP_PID
	    exit $failcode
	fi
    fi	
}
## end runbismon
################################


### Alan PseudoTuring
echo Adding Alan PseudoTuring to bismon
runbismon 'add Alan PseudoTuring' \
	  --contributor='Alan PseudoTuring;alanpseudoturing@fake.email;alan-pseudo-turing@localhost' \
	  --batch --dump-after-load=.
echo 'making bismon after Alan PseudoTuring addition'
make
echo 
echo 'Alan PseudoTuring:AlanT-123+45A' >  /tmp/fifopwbismon_BM &
    runbismon 'password Alan PseudoTuring' --passwords-file=/tmp/passwords_BM \
	      --add-passwords /tmp/fifopwbismon_BM --batch
wait
echo
echo after Alan PseudoTuring
ls -ls /tmp/contributors_BM /tmp/passwords_BM store1.bmon store2.bmon
md5sum store1.bmon store2.bmon
head -99 /tmp/contributors_BM /tmp/passwords_BM
echo
echo '@@@@@@@@@@@@@@@@@@@@@@@@@'  after Alan PseudoTuring
echo
echo

### Grace PseudoHopper
echo Adding Grace PseudoHopper to bismon
runbismon 'add Grace PseudoHopper' \
	 --contributor='Grace PseudoHopper;gracepseudohopper@fake.email;grace-pseudohopper@localhost' \
	 --batch --dump-after-load=.
echo 'making bismon after Grace PseudoHopper addition'
make
echo 
echo 'Grace PseudoHopper:GraceHo-456!78B' > /tmp/fifopwbismon_BM &
    runbismon 'password Grace PseudoHopper' \
	      --add-passwords /tmp/fifopwbismon_BM --batch
wait
echo
echo after Grace PseudoHopper
ls -ls /tmp/contributors_BM /tmp/passwords_BM store1.bmon store2.bmon
md5sum store1.bmon store2.bmon
head -99 /tmp/contributors_BM /tmp/passwords_BM
echo
echo '@@@@@@@@@@@@@@@@@@@@@@@@@'  after Grace PseudoHopper
echo
echo

#### Guy SteelePseudo
echo Adding Guy SteelePseudo to bismon
runbismon 'add Guy SteelePseudo' \
	 --contributor='Guy SteelePseudo;guy-steel-pseudo@fake.email;guy-steele-pseudo@localhost' \
	 --batch --dump-after-load=. 
echo 'making bismon after Guy SteelePseudo addition'
make
echo 

echo 'Guy SteelePseudo:GuySteele-987!453B' > /tmp/fifopwbismon_BM &
    runbismon 'password Guy SteelePseudo' \
	      --add-passwords /tmp/fifopwbismon_BM --batch
wait
echo
echo after Guy SteelePseudo
ls -ls /tmp/contributors_BM /tmp/passwords_BM
head -99 /tmp/contributors_BM /tmp/passwords_BM
echo
echo
echo
echo '@@@@@@@@@@@@@@@@@@@@@@@@@'  after Guy SteelePseudo
echo
echo

restorebismondata

echo 'final git status'
git status

