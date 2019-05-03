#!/bin/bash
# script timestamp-emit.sh
date +'const char bismon_timestamp[]="%c";%n const unsigned long bismon_timelong=%sL;' > __timestamp.tmp
(echo -n 'const char bismon_lastgitcommit[]="' ; \
 git log --format=oneline --abbrev=12 --abbrev-commit -q  \
     | head -1 | tr -d '\n\r\f\"\\\\' ; \
 echo '";') >> __timestamp.tmp
(echo -n 'const char bismon_gitid[]="'; \
 git log --format=oneline -q -1 | cut '-d '  -f1 | tr -d '\n'; \
 echo '";')  >> __timestamp.tmp
(echo -n 'const char bismon_lastgittag[]="'; (git describe --abbrev=0 --all || echo '*notag*') | tr -d '\n\r\f\"\\\\'; echo '";') >> __timestamp.tmp
(echo -n 'const char bismon_checksum[]="'; cat $* | md5sum | cut -d' ' -f1 | tr -d '\n\r\f\"\\' ; echo '";') >> __timestamp.tmp
(echo -n 'const char bismon_directory[]="'; /bin/pwd | tr -d '\n\\"' ; echo '";') >> __timestamp.tmp
(echo -n 'const char bismon_makefile[]="'; echo -n  $(realpath Makefile); echo '";') >> __timestamp.tmp
mv __timestamp.tmp __timestamp.c
