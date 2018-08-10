#!/bin/bash
# file generate-ninja-builder.sh is generating the build.ninja file
# for http://ninja-build.org/ (i.e. Debian ninja-build package)
bm_packages='glib-2.0 gtk+-3.0'
bm_gcc=gcc
bm_gxx=g++
bm_cfiles="$(ls *BM.c)"
bm_cxxfiles="$(ls *BM.cc)"
date +"# DONT EDIT this build.ninja file ; it was generated%n# at %c by $0"
echo 'ninja_required_version = 1.8'
echo '#arguments passed to generate-ninja-builder.sh'
echo "generate_ninja_args = $@"
echo "generate_ninja_script = $0"
echo '#related to pkg-config'
echo "bm_packages = " $bm_packages
echo -n "pkg_cflags = "; pkg-config --cflags $bm_packages
echo -n "pkg_libes = " ; pkg-config --libs $bm_packages
echo '#our compilers and some compiler flags'
echo  "cc = "  $bm_gcc
echo  "cxx = " $bm_gxx
echo "bm_commonwarnflags =  -Wall -Wextra -Wstack-usage=1500 -fdiagnostics-color=auto"
echo 'cwarnflags = $bm_commonwarnflags -Wmissing-prototypes'
echo 'cxxwarnflags = $bm_commonwarnflags'
echo 'defpreproflags = -DBISMONION -DBISMONGK  -DGDK_DISABLE_DEPRECATED -DGTK_DISABLE_DEPRECATED'
echo 'incflags = -I. -I/usr/local/include'
echo 'optimflags = -O1 -g3'
echo 'cflags = $cwarnflags $defpreproflags $incflags $optimflags $pkg_cflags'
echo 'cxxflags = $cxxwarnflags $defpreproflags $incflags $optimflags $pkg_cflags'
#-echo '#our handwritten C files'
#-echo "bm_cfiles = "  $bm_cfiles | fmt | sed -e '2,$s/^/ /' -e 's/$/ \$/' ; echo
#-echo '#our handwritten C++ files'
#-echo "bm_cxxfiles = "  $bm_cxxfiles | fmt | sed -e '2,$s/^/ /' -e 's/$/ \$/' ; echo
echo '#our link flags for bismon'
echo 'bm_ldflags = -L/usr/local/lib -rdynamic -pthread'
echo '#our libraries for bismon'
echo 'bm_libs = -lonion -lbacktrace $pkg_libes -lcrypt -ldl -lm'
echo '#our handwritten C/C++ headers'
echo -n 'bm_headers = bismon.h ' ; ls [a-z]*BM.h | fmt | sed -e '2,$s/^/ /' -e 's/$/ \$/' ; echo

echo '#our handwritten web templates for Onion otemplate'
echo -n 'bm_webtemplates = '; ls *ONIONBM.thtml

echo '#our generated persistent headers'
echo -n 'bm_generatedheaders = ' ; ls _bm*.h | fmt |  sed -e '2,$s/^/ /' -e 's/$/ \$/' ; echo

printf '\n\n######## RULES for ninja\n\n'
echo '# compile a C file into an object file'
echo 'rule CC_r'
echo '  command = $cc -MMD -MT $out -MF $out.mkd $cflags -c $in -o $out'
echo '  description = CC $out'
echo '  depfile = $out.mkd'
echo '  deps = gcc'
echo
echo '# compile a C++ file into an object file'
echo 'rule CXX_r'
echo '  command = $cxx -MMD -MT $out -MF $out.mkd $cxxflags -c $in -o $out'
echo '  description = CXX $out'
echo '  depfile = $out.mkd'
echo '  deps = gcc'
echo
echo '# compile a selfsufficient C++ program'
echo 'rule SOLOCXXPROG_r'
echo '  command = $cxx $cxxwarnflags  $incflags $optimflags $in -o $out'
echo '  description = SOLOCXXPROG $out'
echo
echo  '# make a XXX_BM.const.h header with constants in XXX_BM.c'
echo 'rule BMCONSTH_r'
echo '  command = ./BM_makeconst -H $out $in'
echo '  description = BMCONSTH $out'
echo
echo '# make the _bm_allconsts.c file'
echo 'rule BMALLCONSTSC_r'
echo '  command = ./BM_makeconst -C $out $in'
echo '  description = BMALLCONSTSC $out'
echo
echo '# link the entire bismon program'
echo 'rule LINKALLBISMON_r'
echo '  command = $cxx  $cxxwarnflags  $incflags $optimflags $in $bm_ldflags $bm_libs -o $out ; rm __timestamp.c'
echo '  description = LINKALLBISMON $out'

echo
echo '# timestamp the bismon program'
echo 'rule TIMESTAMP_r'
echo -n '  command = '
sed  -e 's/$/ \$/' << ENDTIMESTAMPING
   date +'const char bismon_timestamp[]="%c";%n'
   (echo -n 'const char bismon_lastgitcommit[]="' ; \
    git log --format=oneline --abbrev=12 --abbrev-commit -q  \
     | head -1 | tr -d '\n\r\f\"\\\\' ; \
       echo '";') >> __timestamp.tmp
	(echo -n 'const char bismon_lastgittag[]="'; (git describe --abbrev=0 --all || echo '*notag*') | tr -d '\n\r\f\"\\\\'; echo '";') >> __timestamp.tmp
	(echo -n 'const char bismon_checksum[]="'; cat bismon.h $bm_headers $bm_cfiles $bm_cxxfiles | cut -d' ' -f1 | tr -d '\n\r\f\"\\' ; echo '";') >> __timestamp.tmp
	(echo -n 'const char bismon_directory[]="'; /bin/pwd | tr -d '\n\\"' ; echo '";') >> __timestamp.tmp
	mv __timestamp.tmp __timestamp.c
ENDTIMESTAMPING
echo '  description = TIMESTAMP $out'
echo

printf '\n\n######## BUILD statements for ninja\n'
echo '#object files for hand-written C sources'
for f in $bm_cfiles ; do
    bf=$(basename $f .c)
    echo -n build $bf.o: CC_r $f 
    grep -q $bf.const.h $f && echo -n ' | ' $bf.const.h
    echo
done

echo '#object files for hand-written C++ sources'
for f in $bm_cxxfiles ; do
    bf=$(basename $f .cc)
    echo build $bf.o: CXX_r $f
done

echo '#object files for Onion templated C generated files'
for t in *ONIONBM.thtml ; do
    bt=$(basename $t .thtml)
    echo build $bt.o: CC_r $t
done
echo

echo '#solo C++ program to deal with BISMON constants'
echo 'build BM_makeconst: SOLOCXXPROG_r BM_makeconst.cc'
echo
echo '#generated constant headers'
for f in $(fgrep -l const.h $bm_cfiles) ; do
    bf=$(basename $f .c)
    echo build $bf.const.h: BMCONSTH_r $f ' | BM_makeconst'
done
echo
echo '#generated all constants summary C file'
echo -n build _bm_allconsts.c: BMALLCONSTSC_r
for f in $(fgrep -l const.h $bm_cfiles) ; do
    bf=$(basename $f .c)
    printf ' %s' $f
done
echo ' | BM_makeconst'
echo
echo
echo '## build the timestamp'
echo -n 'build __timestamp.c: TIMESTAMP_r ' $bm_cfiles $bm_cxxfiles 
echo
echo '## build the bismon program'
echo -n 'build bismon: LINKALLBISMON_r' 
for f in $bm_cfiles ; do
    bf=$(basename $f .c)
    printf " %s" $bf.o
done
printf ' $\n'
for f in $bm_cxxfiles ; do
    bf=$(basename $f .cc)
    printf " %s" $bf.o
done
printf ' $\n'
for t in *ONIONBM.thtml ; do
    bt=$(basename $t .thtml)
    printf " %s" $bt.o
done
printf ' $\n  __timestamp.c'
echo

