#!/bin/bash
# file misc/email-test.sh

## to test sending of email.  See comments after GPLv3+ notice.

# 
#    BISMON 
#    Copyright © 2019 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
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
##### NOTICES
## This script should be run from Bismon source directory
## git cloned from github.com/bstarynk/bismon/


################
bismonflags="$@"

# https://stackoverflow.com/a/9894126/841108
export TOP_PID=$$
# so runbismon below can exit the entire script


if [ ! -f bismon.h ] ; then
   echo Current directory $(pwd) does not contain bismon.h header > /dev/stderr
   exit 1
fi
if [ ! -f store1.bmon ] ; then
   echo Current directory $(pwd) does not contain store1.bmon file > /dev/stderr
   exit 1
fi

make bismon all
htmltempfile=$(tempfile -s .html)

function bmcleanup () {
    rm -vf $htmltempfile
}

trap bmcleanup EXIT INT TERM ERR

cat >$htmltempfile <<-ENDHTML
<!doctype html>
<html>
<head>
<title>bismon email-test to <?bismon-contributor?>: <?bismon-subject?></title>
</head>
<body>
<h1>bismon email-test</h1>
<dl>
<dd><tt>bismon-contributor</tt>: </dd>
<dt><i><?bismon-contributor?></i></dt>

<dd><tt>bismon-subject</tt>: </dd>
<dt><i><?bismon-subject?></i></dt>

<dd><tt>bismon-pid</tt>: </dd>
<dt><i><?bismon-pid?></i></dt>

<dd><tt>bismon-host</tt>: </dd>
<dt><i><?bismon-host?></i></dt>

<dd><tt>bismon-lastgitcommit</tt>: </dd>
<dt><i><?bismon-lastgitcommit?></i></dt>

<dd><tt>bismon-timestamp</tt>: </dd>
<dt><i><?bismon-timestamp?></i></dt>

</dl>
</body>
</html>
ENDHTML
################
echo '********' $htmltempfile is '*******'
cat -n $htmltempfile
echo


./bismon $bismonflags --mailhtml-file=$htmltempfile \
	 --mailhtml-subject='email-test-plain' \
	 --mailhtml-contributor=_6UYrSn7piPM_3eYhLtoXlmL \
	 --batch
################################################################
#### eof email-test.sh
