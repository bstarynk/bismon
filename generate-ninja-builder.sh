#!/bin/bash
# file generate-ninja-builder.sh is generating the build.ninja file
# for http://ninja-build.org/ (i.e. Debian ninja-build package)
bm_packages='glib-2.0 jansson gtk+-3.0'
bm_gcc=gcc
bm_gxx=g++
bm_cfiles="$(ls [a-z]*BM.c)"
bm_cxxfiles="$(ls [a-z]*BM.cc)"
bm_webtemplates="$(ls [a-z]*BM.thtml)"
date +"# DONT EDIT this build.ninja file ; it was generated%n# at %c by $0"
echo 'ninja_required_version = 1.8'
echo '#arguments passed to generate-ninja-builder.sh'
echo "generate_ninja_args = $@"
echo "generate_ninja_script = $0"
echo '#related to pkg-config'
echo "bm_packages = " $bm_packages
for package in $(echo $bm_packages) ; do
    curpack=$(pkg-config --list-all | grep $package)
    if [ -z "$curpack" ]; then
	echo "#missing package " $package > /dev/stderr
	exit 1
    else
	echo "#package: " $curpack
    fi
done
echo -n "pkg_cflags = "; pkg-config --cflags $bm_packages
echo -n "pkg_libes = " ; pkg-config --libs $bm_packages
echo '#our compilers and some compiler flags'
echo  "cc = "  $bm_gcc
echo  "cxx = " $bm_gxx
echo "bm_commonwarnflags =  -Wall -Wextra -Wstack-usage=1500 -fdiagnostics-color=auto"
echo 'cwarnflags = $bm_commonwarnflags -Wmissing-prototypes'
echo 'cxxwarnflags = $bm_commonwarnflags'
echo 'defpreproflags = -DBISMONION -DBISMONGTK  -DGDK_DISABLE_DEPRECATED -DGTK_DISABLE_DEPRECATED'
echo 'incflags = -I. -I/usr/local/include'
echo 'optimflags = -O1 -g3'
echo 'cflags = $cwarnflags $defpreproflags $incflags $optimflags $pkg_cflags'
echo 'cxxflags = $cxxwarnflags $defpreproflags $incflags $optimflags $pkg_cflags'
echo '#for web templates *thtml related to onion otemplate generator'
echo 'otemplate = otemplate'
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
echo -n 'bm_webtemplates = ' $bm_webtemplates  | fmt | sed -e '2,$s/^/ /' -e 's/$/ \$/' ; echo

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
echo '# compile a naked C file into an object file'
echo 'rule NAKEDCC_r'
echo '  command = $cc -Wall -g -O -o $out -c $in'
echo '  description = NAKEDCC $out'
echo
echo '# compile a C++ file into an object file'
echo 'rule CXX_r'
echo '  command = $cxx -MMD -MT $out -MF $out.mkd $cxxflags -c $in -o $out'
echo '  description = CXX $out'
echo '  depfile = $out.mkd'
echo '  deps = gcc'
echo
echo '# compile a selfsufficient C++ program, which uses Glib and id_BM.o'
echo 'rule SOLOCXXPROG_r'
echo '  command = $cxx $cxxwarnflags  $incflags $pkg_cflags $optimflags $in -o $out id_BM.o $pkg_libes'
echo '  description = SOLOCXXPROG $out'
echo
echo  '# make a XXX_BM.const.h header with constants in XXX_BM.c'
echo 'rule BMCONSTH_r'
echo '  command = ./BM_makeconst -H $out $in'
echo '  description = BMCONSTH $out'
echo
echo '# make _XXX_ONIONBM.c & _XXX_ONIONBM.h from web template XXX_ONIONBM.thtml'
echo 'rule OTEMPLATE_r'
echo '  command = $otemplate -a $out_h $in_thtml $out_c'
echo '  description = OTEMPLATE asset $out_h code $out_c template $in_thtml'
echo
echo '# make the _bm_allconsts.c file'
echo 'rule BMALLCONSTSC_r'
echo '  command = ./BM_makeconst -C $out $in'
echo '  description = BMALLCONSTSC $out'
echo
echo '# link the entire bismon program'
echo 'rule LINKALLBISMON_r'
echo '  command = $cxx  $cxxwarnflags  $incflags $optimflags $in $bm_ldflags $bm_libs -o $out && mv -vf __timestamp.c __timestamp.c~ && rm __timestamp.o'
echo '  description = LINKALLBISMON $out'
echo
echo
echo '# timestamp the bismon program'
echo 'rule TIMESTAMP_r'
echo '  command = ./timestamp-emit.sh $in'
echo '  description = TIMESTAMP $out'
echo
echo '# cflags for modules'
echo 'rule CFLAGSMODULE_r'
echo '  command =  (printf "#generated %s file from %s\nBISMONMODULECFLAGS = %s\nBISMONHEADERS = %s\n"  $out $in "$cflags" "$bm_headers $bm_generatedheaders"; date +"#generated %c%n") > $out'
echo '  description = CFLAGSMODULE $out'
echo
echo '# reconfiguration'
echo 'rule CONFIG_r'
echo '  command = ./generate-ninja-builder.sh > $out.tmp ; mv -v --backup $out.tmp $out'
echo '  generator = 1'
echo '  description = CONFIG $out'
echo

printf '\n\n######## BUILD statements for ninja\n'
echo '#object files for hand-written C sources'
for f in $bm_cfiles ; do
    bf=$(basename $f .c)
    echo -n build $bf.o: CC_r $f 
    grep -q $bf.const.h $f && echo -n ' | ' $bf.const.h
    for t in $bm_webtemplates ; do
	bt=$(basename $t .thtml)
	grep -q _$bt.h $f && echo -n ' ' _$bt.h
    done
    echo
done

echo '#object files for hand-written C++ sources'
for f in $bm_cxxfiles ; do
    bf=$(basename $f .cc)
    echo build $bf.o: CXX_r $f
done



echo '#solo C++ program to deal with BISMON constants'
echo 'build BM_makeconst: SOLOCXXPROG_r BM_makeconst.cc | id_BM.o'
echo
echo '#generated constant headers'
for f in $(fgrep -l const.h $bm_cfiles) ; do
    bf=$(basename $f .c)
    echo build $bf.const.h: BMCONSTH_r $f ' | BM_makeconst'
done
echo
echo '#generated all constants summary C file and object'
echo -n build _bm_allconsts.c: BMALLCONSTSC_r
for f in $(fgrep -l const.h $bm_cfiles) ; do
    bf=$(basename $f .c)
    printf ' %s' $f
done
echo ' | BM_makeconst'
echo build _bm_allconsts.o: NAKEDCC_r _bm_allconsts.c
echo
echo
echo '# build from webtemplates'
for f in $bm_webtemplates ; do
    bf=$(basename $f .thtml)
    echo build _$bf.h _$bf.c: OTEMPLATE_r $f
    echo '  in_thtml = ' $f
    echo '  out_h = ' _$bf.h
    echo '  out_c = ' _$bf.c
    echo
    echo build _$bf.o: CC_r _$bf.c
done
echo
echo '## build the timestamp and object file'
echo  'build __timestamp.c: TIMESTAMP_r ' $bm_cfiles $bm_cxxfiles ' | ' timestamp-emit.sh
echo  'build __timestamp.o: NAKEDCC_r __timestamp.c'
echo
echo '## build and link the bismon program'
printf '#? bm_cfiles= %s\n' $bm_cfiles
printf '#? bm_cxxfiles= %s\n' $bm_cxxfiles
printf '#? bm_webtemplates= %s\n' $bm_webtemplates
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
for f in $bm_webtemplates ; do
    bf=$(basename $f .thtml)
    echo -n " _$bf.o"
done
printf ' $\n  __timestamp.o _bm_allconsts.o | '
for s in store*.bmon ; do
    echo -n " $s"
done
echo
echo
echo '## emit the cflags for make-ing modules'
echo 'build _cflagsmodule.mk: CFLAGSMODULE_r build.ninja'
printf '\n\n\n################## default target\n'
echo 'default bismon _cflagsmodule.mk'
echo
echo '## reconfigure'
echo build build.ninja: CONFIG_r $0
