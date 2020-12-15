#!/bin/bash
# script timestamp-emit.sh
printf "// %sGENERATED¤ file __timestamp.c, see http://github.com/bstarynk/bismon\n" "¤" > __timestamp.tmp
printf "// generated with %s %s\n" $0 "$*"  >> __timestamp.tmp
date +'const char bismon_timestamp[]="%c";%n const unsigned long bismon_timelong=%sL;' >> __timestamp.tmp

(echo -n 'const char bismon_lastgitcommit[]="' ; \
 git log --format=oneline --abbrev=12 --abbrev-commit -q  \
     | head -1 | tr -d '\n\r\f\"\\\\' ; \
 echo '";') >> __timestamp.tmp

if git status|grep -q 'nothing to commit' ; then
    endgitid='";'
else
    endgitid='+";'
fi
(echo -n 'const char bismon_gitid[]="'; 
 git log --format=oneline -q -1 | cut '-d '  -f1 | tr -d '\n';
     echo $endgitid)  >> __timestamp.tmp

(printf 'const char bismon_shortgitid[]="%.16s%s\n' \
	$(git log --format=oneline -q -1 | cut '-d '  -f1 | tr -d '\n') \
	$endgitid)  >> __timestamp.tmp


(echo  'const char* const bismon_sources[] = {';
 for src in $* ; do
     printf '  "%s",\n' $src;
 done;
 printf '    (const char*)0 }; // end bismon_sources\n') >> __timestamp.tmp

(printf  'const int bismon_source_number =\n   (sizeof(bismon_sources)/sizeof(bismon_sources[0])) - 1;\n\n') >> __timestamp.tmp

(echo -n 'const char bismon_lastgittag[]="'; (git describe --abbrev=0 --all || echo '*notag*') | tr -d '\n\r\f\"\\\\'; echo '";') >> __timestamp.tmp

(echo -n 'const char bismon_checksum[]="'; cat $* | md5sum | cut -d' ' -f1 | tr -d '\n\r\f\"\\' ; echo '";') >> __timestamp.tmp

(echo -n 'const char bismon_directory[]="'; /bin/pwd | tr -d '\n\\"' ; echo '";') >> __timestamp.tmp

(echo -n 'const char bismon_gnumakefile[]="'; echo -n  $(realpath GNUmakefile); echo '";') >> __timestamp.tmp

if [ -n "$BISMON_MAKE" ] ; then
    (echo -n 'const char* bismon_make ="'; echo -n $BISMON_MAKE;  echo '";') >> __timestamp.tmp
else
    echo 'const char* bismon_make;' >> __timestamp.tmp
fi

if [ -n "$BISMON_PACKAGES" ] ; then
    (echo -n 'const char* bismon_packages = "'; echo -n $BISMON_PACKAGES;  echo '";') >> __timestamp.tmp
else
    echo 'const char* bismon_packages;' >> __timestamp.tmp
fi

### target cross-compilers
echo "//// target cross-compilers:" >> __timestamp.tmp
if [ -n "$BISMONMK_TARGET_GCC" ]; then
    (echo -n 'const char* bismon_target_gcc = "'; echo -n $BISMONMK_TARGET_GCC;  echo '";') >> __timestamp.tmp
else
    echo 'const char* bismon_target_gcc;' >> __timestamp.tmp
fi
    

if [ -n "$BISMONMK_TARGET_GXX" ]; then
    (echo -n 'const char* bismon_target_gxx = "'; echo -n $BISMONMK_TARGET_GXX;  echo '";') >> __timestamp.tmp
else
    echo 'const char* bismon_target_gxx;' >> __timestamp.tmp
fi


### host compilers
echo "//// host compilers:" >> __timestamp.tmp
if [ -n "$BISMONMK_HOST_CC" ]; then
    (echo -n 'const char* bismon_host_cc = "'; echo -n $BISMONMK_HOST_CC;  echo '";') >> __timestamp.tmp
else
    echo 'const char* bismon_host_cc;' >> __timestamp.tmp
fi


if [ -n "$BISMONMK_HOST_CXX" ]; then
    (echo -n 'const char* bismon_host_cxx = "'; echo -n $BISMONMK_HOST_CXX;  echo '";') >> __timestamp.tmp
else
    echo 'const char* bismon_host_cxx;' >> __timestamp.tmp
fi


### libonion
echo "//// libonion for Web service:" >> __timestamp.tmp
if [ -n "$BISMONMK_ONION_INCLUDEDIR" ]; then
    (echo -n 'const char* bismon_onion_includedir = "'; echo -n $BISMONMK_ONION_INCLUDEDIR;  echo '";') >> __timestamp.tmp
else
    echo 'const char* bismon_onion_includedir;' >> __timestamp.tmp
fi


if [ -n "$BISMONMK_ONION_LIBDIR" ]; then
    (echo -n 'const char* bismon_onion_libdir = "'; echo -n $BISMONMK_ONION_LIBDIR;  echo '";') >> __timestamp.tmp
else
    echo 'const char* bismon_onion_libdir;' >> __timestamp.tmp
fi

mv __timestamp.tmp __timestamp.c
