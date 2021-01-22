#!/usr/bin/gawk -f
# internal script emit-git-sources.gawk - for GNU awk ; invoked by timestamp-emit.sh
## the input is the command git  ls-tree -r --name-only --full-name HEAD
##   BISMON - see github.com/bstarynk/bismon/
##   Copyright © 2021 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
##   contributed by Basile Starynkevitch (working at CEA, LIST, France)
##   <basile@starynkevitch.net> or <basile.starynkevitch@cea.fr>
/^"/ {
    printf "   %s,\n", $1;
    next
}

/\\.[a-z]/ {
    printf "   \"%s\",\n", $1;
    next
}

{
    printf "   \"%s\",\n", $1;
    next
}
# end of executable file  emit-git-sources.gawk of BISMON
