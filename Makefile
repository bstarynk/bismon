## the Makefile
GCC= gcc
GXX= g++
CC= $(GCC)
CXX= $(GXX)
CCACHE= ccache
MARKDOWN= markdown
WARNFLAGS= -Wall -Wextra -Wmissing-prototypes -Wstack-usage=1500 -fdiagnostics-color=auto
## -Wmissing-prototypes dont exist for g++
SKIPCXXWARNFLAGS= -Wmissing-prototypes
OPTIMFLAGS= -O1 -g3
PLUGINFLAGS=
CFLAGS= -std=gnu11 $(PLUGINFLAGS) $(WARNFLAGS) $(PREPROFLAGS) $(OPTIMFLAGS)
CXXFLAGS= -std=gnu++14  $(PLUGINFLAGS) $(filter-out $(SKIPCXXWARNFLAGS), $(WARNFLAGS)) $(PREPROFLAGS) $(OPTIMFLAGS)
GCCPLUGINS_DIR:= $(shell $(CXX) -print-file-name=plugin)
INDENT= indent
ASTYLE= astyle
MD5SUM= md5sum
INDENTFLAGS= --gnu-style --no-tabs --honour-newlines
ASTYLEFLAGS= --style=gnu -s2
PACKAGES= gtk+-3.0
PKGCONFIG= pkg-config
PREPROFLAGS= -I. -I/usr/local/include $(shell $(PKGCONFIG) --cflags $(PACKAGES)) -DGDK_DISABLE_DEPRECATED -DGTK_DISABLE_DEPRECATED

LIBES= -L/usr/local/lib -lbacktrace $(shell $(PKGCONFIG) --libs $(PACKAGES)) -ldl -lm
RM= rm -fv


CSOURCES= $(sort  $(wildcard [a-zA-Z]*.c))
BM_CXXSOURCES= $(sort  $(wildcard [a-zA-Z]*_BM.cc))
BM_HEADERS= $(sort $(wildcard *_BM.h))
BM_COLDSOURCES= $(sort $(wildcard *_BM.c))
GENERATED_HEADERS= $(sort $(wildcard _[a-z0-9]*.h))
GENERATED_CSOURCES= $(filter-out _bm_allconsts.c, $(sort $(wildcard _[a-z0-9]*.c)))
MARKDOWN_SOURCES= $(sort $(wildcard *.md))
MODULES_SOURCES= $(sort $(wildcard modules/modbm*.c))

OBJECTS= $(patsubst %.c,%.o,$(BM_COLDSOURCES) $(GENERATED_CSOURCES)) $(patsubst %.cc,%.o,$(BM_CXXSOURCES))

.PHONY: all clean indent count modules measure measured-bismon doc redump outdump checksum indentsinglemodule singlemodule indenttempmodule tempmodule


bismon: $(OBJECTS) _bm_allconsts.o | modules
	@if [ -f $@ ]; then echo -n backup old executable: ' ' ; mv -v $@ $@~ ; fi
	$(MAKE) __timestamp.c __timestamp.o _bm_allconsts.o
	$(LINK.cc)  $(LINKFLAGS) -rdynamic $(OPTIMFLAGS) $(OBJECTS) __timestamp.o _bm_allconsts.o $(LIBES) -o $@
	ls -l $@
	$(RM) __timestamp.*

all: bismon modules doc

clean:
	$(RM) .*~ *~ *% *.o *.so */*.so *.log */*~ */*.orig *.i *.orig *.gch README.html
	$(RM) core* *.i *.ii *prof.out gmon.out
	$(RM) *_BM.const.h _bm_allconsts.c
	$(RM) modubin/*.so modules/*.i modules/*% modules/*~ modules/*- bismon BM_makeconst
	$(RM) $(patsubst %.md,%.html, $(MARKDOWN_SOURCES))
	$(RM)  doc/generated/* doc/htmldoc/*  doc/*/*~
	$(RM) doc/*.aux doc/*.log doc/*.bbl doc/*.blg doc/*.idx doc/*.ilg doc/*.ind doc/*.log doc/*.out doc/*.toc doc/*.haux doc/*.hind doc/*.html doc/*.htoc

indent: .indent.pro
	@printf "\n *** headers *** \n"
	@for h in $(BM_HEADERS); do \
	  cp -a $$h $$h% ; \
	  $(INDENT) $(INDENTFLAGS) $$h ; \
	  $(INDENT) $(INDENTFLAGS) $$h ; \
	  if cmp -s $$h $$h% ; then echo unchanged $$h ; mv $$h% $$h ; \
          else echo '*indented' $$h ; fi \
	done
	@printf "\n *** C sources *** \n"
	@for c in $(BM_COLDSOURCES); do \
	  cp -a $$c $$c% ; \
	  $(INDENT) $(INDENTFLAGS) $$c ; \
	  $(INDENT) $(INDENTFLAGS) $$c ; \
	  if cmp -s $$c $$c% ; then echo unchanged $$c ; mv $$c% $$c ; \
	  else echo '*indented' $$c ; fi ; \
	done
	@printf "\n *** C modules sources *** \n"
	@for c in $(MODULES_SOURCES); do \
	  cp -a $$c $$c% ; \
	  $(INDENT) $(INDENTFLAGS) $$c ; \
	  $(INDENT) $(INDENTFLAGS) $$c ; \
	  if cmp -s $$c $$c% ; then echo unchanged $$c ; mv $$c% $$c ; \
	  else echo '*indented' $$c ; fi ; \
	done
	@printf "\n *** C++ sources *** \n"
	@for x in $(BM_CXXSOURCES); do \
	  $(ASTYLE) $(ASTYLEFLAGS) $$x ; \
	done
	@printf "\n *** C++ plugin source *** \n"
	@$(ASTYLE) $(ASTYLEFLAGS)  measure_plugcc.cc
	@printf "\n"
	@printf "\n *** C++ tool source *** \n"
	@$(ASTYLE) $(ASTYLEFLAGS)  BM_makeconst.cc
	@printf "\n"

## we could use git rev-parse HEAD for the lastgitcommit, but it does
## not give any log comment... Notice that tr command is interpreting
## some backslash escapes itself

__timestamp.c: Makefile
	@date +'const char bismon_timestamp[]="%c";%n const unsigned long bismon_timelong=%sL;' > __timestamp.tmp
	@(echo -n 'const char bismon_lastgitcommit[]="' ; \
	   git log --format=oneline --abbrev=12 --abbrev-commit -q  \
	     | head -1 | tr -d '\n\r\f\"\\\\' ; \
	   echo '";') >> __timestamp.tmp
	@(echo -n 'const char bismon_lastgittag[]="'; (git describe --abbrev=0 --all || echo '*notag*') | tr -d '\n\r\f\"\\\\'; echo '";') >> __timestamp.tmp
	@(echo -n 'const char bismon_checksum[]="'; cat bismon.h $(BM_HEADERS) $(CSOURCES) | $(MD5SUM) | cut -d' ' -f1 | tr -d '\n\r\f\"\\' ; echo '";') >> __timestamp.tmp
	@(echo -n 'const char bismon_directory[]="'; /bin/pwd | tr -d '\n\\"' ; echo '";') >> __timestamp.tmp
	@(echo -n 'const char bismon_makefile[]="'; echo -n  $(realpath $(lastword $(MAKEFILE_LIST))); echo '";') >> __timestamp.tmp
	@mv __timestamp.tmp __timestamp.c


bismon.h.gch: bismon.h $(GENERATED_HEADERS) $(BM_HEADERS)
	$(COMPILE.c)   $< -o $@


checksum:
	@cat bismon.h $(BM_HEADERS) $(CSOURCES) | $(MD5SUM) | cut -d' ' -f1

%_BM.i: %_BM.c  %_BM.const.h bismon.h  $(GENERATED_HEADERS) $(BM_HEADERS)
	$(CC) $(CFLAGS) -C -E $< | sed s:^#://#: | $(INDENT) -gnu > $@

%_BM.ii: %_BM.cc  $(GENERATED_HEADERS) $(BM_HEADERS)
	$(CCXX) $(CXXFLAGS) -C -E $< | sed s:^#://#: > $@

## to be used from C code as 'make indentsinglemodule MODULEID=<id>'
## in emit_module°plain_module
## for example 'make indentsinglemodule MODULEID=_9oXtCgAbkqv_4y1xhhF5Nhz'
## bismon would have perhaps passed a PREVIOUSMODULESOURCE
## see function emit_module°plain_module _1gME6zn82Kf_8hzWibLFRfz in gencode_BM.c
indentsinglemodule:
	@if [ ! -f modules/modbm$(MODULEID).c ]; then \
	   echo missing modules/modbm$(MODULEID).c; exit 1 ; fi ; \
	ms=modules/modbm$(MODULEID).c ; \
	cp -a $$ms "$$ms%"; \
	$(INDENT) $(INDENTFLAGS) $$ms; \
	$(INDENT) $(INDENTFLAGS) $$ms; \
	if cmp -s $$ms "$$ms%" ; then echo unchanged module $$ms ; mv "$$ms%" $$ms ; \
	  else echo '*indented module ' $$ms ; fi
	@if [ -f "$(PREVIOUSMODULESOURCE)" ] && cmp -s "$(PREVIOUSMODULESOURCE)" modules/modbm$(MODULEID).c ; then \
	  mv "$(PREVIOUSMODULESOURCE)" modules/modbm$(MODULEID).c ; \
	  echo same as previous modules/modbm$(MODULEID).c ; \
	else echo '**previous'  "$(PREVIOUSMODULESOURCE)" different of  modules/modbm$(MODULEID).c ; \
	fi

## to be used from C code as 'make singlemodule MODULEID=<id>'
singlemodule:
	@if [ ! -f modules/modbm$(MODULEID).c ]; then \
	   echo missing modules/modbm$(MODULEID).c; exit 1 ; fi 
	$(MAKE) modubin/modbm$(MODULEID).so

#### for temporary modules
indenttempmodule:
	@if [ ! -f modules/tmpmobm$(MODULEID).c ]; then \
	   echo missing modules/tmpmobm$(MODULEID).c; exit 1 ; fi ; \
	ms=modules/tmpmobm$(MODULEID).c ; \
	cp -a $$ms "$$ms%"; \
	$(INDENT) $(INDENTFLAGS) $$ms; \
	$(INDENT) $(INDENTFLAGS) $$ms; \
	if cmp -s $$ms "$$ms%" ; then echo unchanged module $$ms ; mv "$$ms%" $$ms ; \
	  else echo '*indented module ' $$ms ; fi
	@if [ -f "$(PREVIOUSMODULESOURCE)" ] && cmp -s "$(PREVIOUSMODULESOURCE)" modules/tmpmobm$(MODULEID).c ; then \
	  mv "$(PREVIOUSMODULESOURCE)" modules/tmpmobm$(MODULEID).c ; \
	  echo same as previous modules/tmpmobm$(MODULEID).c ; \
	else echo '**previous'  "$(PREVIOUSMODULESOURCE)" different of  modules/tmpmobm$(MODULEID).c ; \
	fi

## to be used from C code as 'make tempmodule MODULEID=<id>'
tempmodule:
	@if [ ! -f modules/tmpmobm$(MODULEID).c ]; then \
	   echo missing modules/tmpmobm$(MODULEID).c; exit 1 ; fi 
	$(MAKE) modubin/tmpmobm$(MODULEID).so

# cancel implicit rule for C files to force my explicit rules
# https://stackoverflow.com/a/29227455/841108
%.o: %.c

%_BM.o: %_BM.c bismon.h $(GENERATED_HEADERS) $(BM_HEADERS) %_BM.const.h bismon.h.gch
#	echo objcirc is $^ left $<
	$(COMPILE.c) -DBMcomp -c $< -o $@

%_BM.o: %_BM.cc bismon.h $(GENERATED_HEADERS) $(BM_HEADERS)
#	$(CCACHE) $(COMPILE.cc)  $< -o $@
	$(COMPILE.cc)  $< -o $@

%_BM.const.h: %_BM.c BM_makeconst
	./BM_makeconst -H $@ $<

__timestamp.o: __timestamp.c
	$(COMPILE.c)  -DBMtimestamp -c $< -o $@

_bm_allconsts.o: _bm_allconsts.c
	$(COMPILE.c)  -DBMallconsts -c $< -o $@

_bm_allconsts.c: $(BM_COLDSOURCES)  BM_makeconst
	./BM_makeconst -C $@ $(BM_COLDSOURCES)

modubin/modbm_%.so: modules/modbm_%.c bismon.h  $(GENERATED_HEADERS) $(BM_HEADERS)
	$(CCACHE) $(LINK.c) -fPIC -DBISMON_MODID=$(patsubst modules/modbm_%.c,_%,$<)  '-DBISMON_MOMD5="$(shell md5sum $< | cut '-d ' -f1)"' -DBISMON_PERSISTENT_MODULE -shared $< -o $@

modubin/tmpmobm_%.so: modules/tmpmobm_%.c bismon.h  $(GENERATED_HEADERS) $(BM_HEADERS)
	$(CCACHE) $(LINK.c) -fPIC -DBISMON_MODID=$(patsubst modules/tmpmobm_%.c,_%,$<) '-DBISMON_MOMD5="$(shell md5sum $< | cut '-d ' -f1)"' -DBISMON_TEMPORARY_MODULE -shared $< -o $@

modules:
	$(MAKE) -k $(MAKEFLAGS)  $(patsubst modules/%.c,modubin/%.so,$(MODULES_SOURCES)) ; exit 0

measured-bismon: measure_plugcc.so
	$(RM) $(OBJECTS)
	$(MAKE) bismon PLUGINFLAGS=-fplugin=./measure_plugcc.so

measure_plugcc.so: measure_plugcc.cc  Makefile
	$(CXX) -std=gnu++14 -fno-rtti $(OPTIMFLAGS)  -I$(GCCPLUGINS_DIR)/include -fPIC -shared $< -o $@

measure: measure_plugcc.so measured-bismon

doc: $(MARKDOWN_SOURCES) bismon modules
	for f in $(MARKDOWN_SOURCES) ; do  $(MARKDOWN) $$f > $$(basename $$f .md).html ; done
	./build-bismon-doc.sh

count:
	@wc -cl $(wildcard *.c *.h *.cc modules/*.c) | sort -n

redump: bismon modules
	@for f in $(GENERATED_HEADERS) $(GENERATED_CSOURCES) $(MODULES_SOURCES) *.bmon ; \
           do cp -vab $$f $$f%~ ; done
	time ./bismon --dump-after-load . --batch
	printf "\n\n\n **** second redump run ***\n"
	time ./bismon --dump-after-load . --batch
	$(MAKE) indent

outdump: bismon modules
	time ./bismon  --run-command 'rm -rvf /tmp/bd'  --dump-after-load /tmp/bd --batch
	for f in /tmp/bd/* ; do cmp $$f $$(basename $$f); done
