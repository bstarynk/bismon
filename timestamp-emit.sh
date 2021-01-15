#!/bin/bash
# script timestamp-emit.sh
##   BISMON - see github.com/bstarynk/bismon/
output_timestamp=$1
if [ -z "$output_timestamp" ]; then
    output_timestamp=__timestamp.c
fi
tempoutput="$output_timestamp-tmp$$"

##   Copyright © 2018 - 2021 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
##   contributed by Basile Starynkevitch (working at CEA, LIST, France)
##   <basile@starynkevitch.net> or <basile.starynkevitch@cea.fr>
printf "// %sGENERATED¤ file __timestamp.c, see http://github.com/bstarynk/bismon\n" "¤" > $tempoutput
printf "// generated with %s %s\n" $0 "$*"  >> $tempoutput
date +'const char bismon_timestamp[]="%c";%n const unsigned long bismon_timelong=%sL;' >> $tempoutput

(echo -n 'const char bismon_lastgitcommit[]="' ; \
 git log --format=oneline --abbrev=12 --abbrev-commit -q  \
     | head -1 | tr -d '\n\r\f\"\\\\' ; \
 echo '";') >> $tempoutput

if git status|grep -q 'nothing to commit' ; then
    endgitid='";'
else
    endgitid='+";'
fi
(echo -n 'const char bismon_gitid[]="'; 
 git log --format=oneline -q -1 | cut '-d '  -f1 | tr -d '\n';
     echo $endgitid)  >> $tempoutput

(printf 'const char bismon_shortgitid[]="%.16s%s\n' \
	$(git log --format=oneline -q -1 | cut '-d '  -f1 | tr -d '\n') \
	$endgitid)  >> $tempoutput


(echo  'const char* const bismon_sources[] = {';
 for src in $* ; do
     printf '  "%s",\n' $src;
 done;
 printf '    (const char*)0 }; // end bismon_sources\n') >> $tempoutput

(printf  'const int bismon_source_number =\n   (sizeof(bismon_sources)/sizeof(bismon_sources[0])) - 1;\n\n') >> $tempoutput

(echo -n 'const char bismon_lastgittag[]="'; (git describe --abbrev=0 --all || echo '*notag*') | tr -d '\n\r\f\"\\\\'; echo '";') >> $tempoutput

(echo -n 'const char bismon_checksum[]="'; cat $* | md5sum | cut -d' ' -f1 | tr -d '\n\r\f\"\\' ; echo '";') >> $tempoutput

(echo -n 'const char bismon_directory[]="'; /bin/pwd | tr -d '\n\\"' ; echo '";') >> $tempoutput

(echo -n 'const char bismon_gnumakefile[]="'; echo -n  $(realpath GNUmakefile); echo '";') >> $tempoutput

if [ -n "$BISMON_MAKE" ] ; then
    (echo -n 'const char* bismon_make ="'; echo -n $BISMON_MAKE;  echo '";') >> $tempoutput
else
    echo 'const char* bismon_make;' >> $tempoutput
fi

if [ -n "$BISMON_PACKAGES" ] ; then
    (echo -n 'const char* bismon_packages = "'; echo -n $BISMON_PACKAGES;  echo '";') >> $tempoutput
else
    echo 'const char* bismon_packages;' >> $tempoutput
fi

### target cross-compilers
echo "//// target cross-compilers:" >> $tempoutput
if [ -n "$BISMONMK_TARGET_GCC" ]; then
    (echo -n 'const char* bismon_target_gcc = "'; echo -n $BISMONMK_TARGET_GCC;  echo '";') >> $tempoutput
else
    echo 'const char* bismon_target_gcc;' >> $tempoutput
fi
    

if [ -n "$BISMONMK_TARGET_GXX" ]; then
    (echo -n 'const char* bismon_target_gxx = "'; echo -n $BISMONMK_TARGET_GXX;  echo '";') >> $tempoutput
else
    echo 'const char* bismon_target_gxx;' >> $tempoutput
fi


### host compilers
echo "//// host compilers:" >> $tempoutput
if [ -n "$BISMONMK_HOST_CC" ]; then
    (echo -n 'const char* bismon_host_cc = "'; echo -n $BISMONMK_HOST_CC;  echo '";') >> $tempoutput
else
    echo 'const char* bismon_host_cc;' >> $tempoutput
fi


if [ -n "$BISMONMK_HOST_CXX" ]; then
    (echo -n 'const char* bismon_host_cxx = "'; echo -n $BISMONMK_HOST_CXX;  echo '";') >> $tempoutput
else
    echo 'const char* bismon_host_cxx;' >> $tempoutput
fi


### libonion
echo "//// libonion for Web service:" >> $tempoutput
if [ -n "$BISMONMK_ONION_INCLUDEDIR" ]; then
    (echo -n 'const char* bismon_onion_includedir = "'; echo -n $BISMONMK_ONION_INCLUDEDIR;  echo '";') >> $tempoutput
else
    echo 'const char* bismon_onion_includedir;' >> $tempoutput
fi


if [ -n "$BISMONMK_ONION_LIBDIR" ]; then
    (echo -n 'const char* bismon_onion_libdir = "'; echo -n $BISMONMK_ONION_LIBDIR;  echo '";') >> $tempoutput
else
    echo 'const char* bismon_onion_libdir;' >> $tempoutput
fi

mv $tempoutput $output_timestamp
### eof timestamp-emit.sh
