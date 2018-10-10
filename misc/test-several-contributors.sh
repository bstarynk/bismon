#! /bin/bash
# file misc/test-several-contributors.sh
# to test having several contributors
# 
#    BISMON 
#    Copyright © 2018 Basile Starynkevitch (working at CEA, LIST, France)
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

bismonflags="$@"
if [ ! -f ./bismon -a ! -x ./bismon ] ; then
   echo Current directory $(pwd) does not contain ./bismon executable > /dev/stderr
   exit 1
fi
if [ ! -f store1.bmon ] ; then
   echo Current directory $(pwd) does not contain store1.bmon file > /dev/stderr
   exit 1
fi
rm -vf /tmp/passwords_BM
echo '# file /tmp/passwords_BM' > /tmp/passwords_BM
chmod go-rwx /tmp/passwords_BM
cp -v contributors_BM /tmp/contributors_BM
ls -ls /tmp/passwords_BM
tar cvf /tmp/bismonstore.tar.gz store*.bmon
ls -ls /tmp/bismonstore.tar.gz

echo 'before adding contributors'
ls -ls store1.bmon store2.bmon
md5sum store1.bmon store2.bmon
echo
./bismon  $bismonflags --contributors-file=/tmp/contributors_BM --passwords-file=/tmp/passwords_BM --contributor='Alan PseudoTuring;alanpseudoturing@fake.email;alan-pseudo-turing@localhost' --batch --dump-after-load=.
echo 'Alan PseudoTuring:AlanT-123+45A' |  \
    ./bismon $bismonflags --contributors-file=/tmp/contributors_BM --passwords-file=/tmp/passwords_BM --add-passwords - --batch
echo
echo after Alan PseudoTuring
ls -ls /tmp/contributors_BM /tmp/passwords_BM store1.bmon store2.bmon
md5sum store1.bmon store2.bmon
head -99 /tmp/contributors_BM /tmp/passwords_BM
echo
echo


./bismon $bismonflags --contributors-file=/tmp/contributors_BM --passwords-file=/tmp/passwords_BM --contributor='Grace PseudoHopper;gracepseudohopper@fake.email;grace-pseudohopper@localhost' --batch --dump-after-load=.

echo 'Grace PseudoHopper:GraceHo-456!78B' |  \
    ./bismon $bismonflags --contributors-file=/tmp/contributors_BM --passwords-file=/tmp/passwords_BM --add-passwords - --batch
echo
echo after Grace PseudoHopper
ls -ls /tmp/contributors_BM /tmp/passwords_BM store1.bmon store2.bmon
md5sum store1.bmon store2.bmon
head -99 /tmp/contributors_BM /tmp/passwords_BM
echo
echo

./bismon --contributors-file=/tmp/contributors_BM --passwords-file=/tmp/passwords_BM --contributor='Grace PseudoHopper;gracehopperpseudo@fake.email;grace-hopperpseudo@localhost' --batch --dump-after-load=.

echo 'Grace PseudoHopper:GraceHo-456!78B' |  \
    ./bismon $bismonflags --contributors-file=/tmp/contributors_BM --passwords-file=/tmp/passwords_BM --add-passwords - --batch
echo
echo after Grace PseudoHopper
ls -ls /tmp/contributors_BM /tmp/passwords_BM
head -99 /tmp/contributors_BM /tmp/passwords_BM
echo
echo


./bismon --contributors-file=/tmp/contributors_BM --passwords-file=/tmp/passwords_BM --contributor='Guy SteelePseudo;guy-steel-pseudo@fake.email;guy-steele-pseudo@localhost' --batch --dump-after-load=.

echo 'Guy SteelePseudo:GuySteele-987!453B' |  \
    ./bismon $bismonflags --contributors-file=/tmp/contributors_BM --passwords-file=/tmp/passwords_BM --add-passwords - --batch
echo
echo after Guy SteelePseudo
ls -ls /tmp/contributors_BM /tmp/passwords_BM
head -99 /tmp/contributors_BM /tmp/passwords_BM
echo
echo

git status

echo 'restoring store'
tar xvf /tmp/bismonstore.tar.gz

git status

