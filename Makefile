## the Bismon Makefile
## SPDX-License-Identifier: GPL-3.0-or-later
## GPLv3+ licensed, from http://github.com/bstarynk/bismon
# file generate-ninja-builder.sh is generating the build.ninja file
# 
#    BISMON 
#   Copyright © 2018 - 2020 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
#   contributed by Basile Starynkevitch.
#
#   This program is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
#---
#   Contact me (Basile Starynkevitch) by email
#   basile@starynkevitch.net and/or basile.starynkevitch@cea.fr
######
# for GNU make
################################################################
NINJA= ninja
NINJAFLAGS= 
GCC= gcc
GXX= g++
CC= $(GCC)
CXX= $(GXX)
#if you don't have or want ccache, set the below variable to empty
#CCACHE= ccache
CCACHE=
#see https://www.gnu.org/software/guile/manual/html_node/Function-Snarfing.html
GUILE_SNARF= guile-snarf
MARKDOWN= markdown
INDENT= indent
ASTYLE= astyle
MD5SUM= md5sum
INDENTFLAGS= --gnu-style --no-tabs --honour-newlines
ASTYLEFLAGS= --style=gnu -s2
RM= rm -fv
-include _cflagsmodule.mk
MARKDOWN_SOURCES= $(sort $(wildcard *.md))
MODULES_SOURCES= $(sort $(wildcard modules/modbm*.c))
TESTPLUGINS_SOURCES= $(sort $(wildcard drafts/testplugin_*.c))

BM_HEADERS= $(wildcard [a-z]*BM.h bismon.h)
BM_CSOURCES= $(wildcard [a-z]*BM.c)
BM_COMPILE_MODULE_PACKAGES=  glib-2.0 glibmm-2.4 guile-3.0
BM_COMPILE_CFLAGS:= $(shell pkg-config --cflags $(BM_COMPILE_MODULE_PACKAGES))
BM_COMPILE_LIBES:= $(shell pkg-config --libs $(BM_COMPILE_MODULE_PACKAGES))

.PHONY: all programs clean verbose indent count modules measure \
  doc latexdoc latexcleandoc heveadoc redump outdump checksum \
  indentsinglemodule indenttempmodule jstimestamp chariotdemo-bismon \
  bismon-metaplugin




all: | build.ninja
	@printf "\n\n\n******* start making all in %s *********\n\n" $$PWD
	$(MAKE) programs modules jstimestamp bismon-metaplugin
	@printf "\n******* done making all in %s *********\n" $$PWD

BM_compile_module: BM_compile_module.o BM_compmod_guile.o __timestamp.o 
	$(LINK.cc)  -O -g -Wall -Wextra  $^ $(BM_COMPILE_LIBES) -o $@
	@ls -l $@

BM_compile_module.o: BM_compile_module.cc BM_compmod.hh | _BM_compmod_guile.snarf.h
	$(COMPILE.cc)  -O -g -Wall -Wextra $(BM_COMPILE_CFLAGS) $<

BM_compmod_guile.o: BM_compmod_guile.cc BM_compmod.hh
	$(COMPILE.cc)  -O -g -Wall -Wextra $(BM_COMPILE_CFLAGS) $<

_BM_compmod_guile.snarf.h: BM_compmod_guile.cc
	$(GUILE_SNARF) -o $@ $(BM_COMPILE_CFLAGS)  $<

programs: BM_compile_module BM_makeconst bismon modules

verbose: | build.ninja
	$(NINJA) -v

__timestamp.o:  | build.ninja
	$(NINJA) $@

bismon:
	@printf "\n\n\n******* start making bismon in %s *********\n\n" $$PWD
	$(MAKE) build.ninja $(wildcard *BM.c *_BM.cc)  $(wildcard store*bmon)
	$(RM) bismon
	$(NINJA) $(NINJAFLAGS) $@
	@[ -x $@ ] || (echo no bismon > /dev/stderr; exit 1)
	@printf "\n******* done making bismon in %s *********\n" $$PWD

_cflagsmodule.mk: build.ninja 
	$(NINJA) $(NINJAFLAGS) $@

build.ninja: generate-ninja-build.scm
	./$^ > $@.tmp; mv --backup -v $@.tmp $@

#checksum:
#	@cat bismon.h $(BM_HEADERS) $(CSOURCES) | $(MD5SUM) | cut -d' ' -f1
 -C -E $< | sed s:^#://#: > $@


## should use BM_compile_module when it is ready
modubin/modbm_%.so: modules/modbm_%.c $(BISMONHEADERS) $(warning modules should use BM_compile_module) | BM_compile_module _cflagsmodule.mk
	@printf "should build %s with BM_compile_module from %s\n" $@ "$^" > /dev/stderr
	( [ -f "$(wildcard modules/modbm_%.env)" ] &&  source "$(wildcard modules/modbm_%.env)" ) ; \
	$(CCACHE) $(LINK.c) -fPIC  $$$$BISMONMODULE_%_FLAGS $(BISMONMODULECFLAGS) \
	      -DBISMON_MODID=$(patsubst modules/modbm_%.c,_%,$<)  \
              -DBISMON_MOMD5='"$(shell md5sum $< | cut '-d ' -f1)"' \
              -DBISMON_PERSISTENT_MODULE -shared $< -o $@


## the drafts/testplugin_*.c pattern is known in main_BM.c function
## run_testplugins_after_load_BM
drafts/testplugin_%.so: drafts/testplugin_%.c $(BISMONHEADERS) | _cflagsmodule.mk
	$(CCACHE) $(LINK.c) -g -fPIC  $(BISMONMODULECFLAGS) \
	     -DBISMON_MOMD5='"$(shell md5sum $< | cut '-d ' -f1)"' -DBISMON_TTESTPLUGIN='"$(basename $@)"' \
	     -shared $< -o $@

## should use BM_compile_module when it is ready
modubin/tmpmobm_%.so: modules/tmpmobm_%.c $(BISMONHEADERS) $(warning tempmodules should use BM_compile_module) | BM_compile_module _cflagsmodule.mk
	@printf "should build %s with BM_compile_module from %s\n" $@ "$^" > /dev/stderr
	( [ -f "$(wildcard modules/tmpmobm_%.env)" ] &&  source "$(wildcard modules/tmpmobm_%.env)" ) ; \
	$(CCACHE) $(LINK.c) -fPIC  $$$$BISMONTEMPMODULE_%_FLAGS $(BISMONMODULECFLAGS) \
	     -DBISMON_MODID=$(patsubst modules/tmpmobm_%.c,_%,$<) \
	     -DBISMON_MOMD5='"$(shell md5sum $< | cut '-d ' -f1)"' -DBISMON_TEMPORARY_MODULE \
	     -shared $< -o $@
#                                                                                                           
modules: _cflagsmodule.mk  $(patsubst modules/%.c,modubin/%.so,$(MODULES_SOURCES)) 

bismon-metaplugin: bismon | build.ninja
	@printf "\n\n\n******* start making bismon-metaplugin in %s *********\n\n" $$(pwd)
	$(MAKE) build.ninja $(wildcard *BM.c *_BM.cc)  $(wildcard store*bmon)
	$(NINJA) $(NINJAFLAGS) gccplugins/bismon-metaplugin.so
	@[ -x gccplugins/bismon-metaplugin.so ] || (echo no  gccplugins/bismon-metaplugin.so > /dev/stderr; exit 1)
	@printf "\n******* done making bismon-metaplugin in %s *********\n" $$PWD


doc: $(MARKDOWN_SOURCES) bismon modules $(wildcard doc/*.tex doc/images/* doc/*.bib doc/*.hva)
	for f in $(MARKDOWN_SOURCES) ; do  $(MARKDOWN) $$f > $$(basename $$f .md).html ; done
	./build-bismon-doc.sh

latexdoc: bismon  modules $(wildcard doc/*.tex doc/*.bib doc/images/*)
	[ -d $$HOME/tmp/ ] || mkdir -v $$HOME/tmp
	$(RM) $(shell realpath $$HOME/tmp/bismon-chariot-doc.pdf)
	./build-bismon-doc.sh LaTeX
	ls -lt ~/tmp/bismon-chariot-doc*

latexcleandoc: bismon modules $(wildcard doc/*.tex doc/*.bib doc/images/*)
	[ -d $$HOME/tmp/ ] || mkdir -v $$HOME/tmp
	$(RM) $(shell realpath $$HOME/tmp/bismon-chariot-doc.pdf)
	$(RM) doc/bismon-chariot-doc.{aux,bbl,blg,idx,log,log,lot,out,toc,pdf} 
	./build-bismon-doc.sh LaTeX
	echo remaking latexdoc
	-$(MAKE) latexdoc
	ls -lt ~/tmp/bismon-chariot-doc*


heveadoc:  bismon modules $(wildcard doc/*.tex doc/images/* doc/*.bib doc/*.hva)
	./build-bismon-doc.sh HeVeA

count:
	@wc -cl $(wildcard *.c *.h *.cc modules/_*.c) | sort -n

redump: bismon  modules
	@for f in $(GENERATED_HEADERS) $(GENERATED_CSOURCES) $(MODULES_SOURCES) *.bmon ; \
           do cp -vab $$f $$f%~ ; done
	time ./bismon --web --dump-after-load . --batch
	$(MAKE)  bismon
	printf "\n\n\n **** second redump run ***\n"
	time ./bismon --web --dump-after-load . --batch

outdump: bismon   modules
	time ./bismon  --run-command 'rm -rvf /tmp/bd'  --dump-after-load /tmp/bd --batch
	for f in /tmp/bd/* ; do cmp $$f $$(basename $$f); done

BM_makeconst_dbg: BM_makeconst-g.o id_BM-g.o
	$(CXX) -g -Wall  $^  $(shell pkg-config --libs glib-2.0) -o $@

BM_makeconst: BM_makeconst.o id_BM.o
	$(LINK.cc) -g -Wall  $^  $(shell pkg-config --libs glib-2.0) -o $@

BM_makeconst-g.o: BM_makeconst.cc id_BM.h
	$(COMPILE.cc)  $(shell pkg-config --cflags glib-2.0) -g -Wall -c $< -o $@

id_BM.o: id_BM.c id_BM.h
	$(COMPILE.c)  $(shell pkg-config --cflags glib-2.0)  -Wall -c $< -o $@
id_BM-g.o: id_BM.c id_BM.h
	$(COMPILE.c)  $(shell pkg-config --cflags glib-2.0) -g -Wall -c $< -o $@
################################################################


clean:
	@printf "\n\n\n******* start cleaning bismon in %s *********\n\n" $$PWD
	[ -f build.ninja ] && $(NINJA) -t clean
	if ls *.log ; then tar cvzf /tmp/bismon-prev-log.tar.gz _*.log; fi
	$(RM) .*~ *~ *% *.o *.so */*.so *.log */*~ */*.orig *.i *.orig *.gch README.html
	$(RM) .ninja* *mkd  _cflagsmodule.mk
	$(RM) build.ninja _bismon.pid
	$(RM) core* *.i *.ii *prof.out gmon.out
	$(RM) *BM.const.h _bm_allconsts*.c
	$(RM) BM_compile_module
	$(RM) $(wildcard _BM_comp*)
	$(RM) $(patsubst %.thtml, _%.c, $(ONIONBM_WEBTEMPLATES))
	$(RM) $(patsubst %.thtml, _%.h, $(ONIONBM_WEBTEMPLATES))
	$(RM) modubin/*.so modules/*.i modules/*% modules/*~ modules/*- bismon BM_makeconst
	$(RM) modules/badmodbm*
	$(RM) __timestamp.*
	$(RM) modules/tmpmobm*
	$(RM) $(patsubst %.md,%.html, $(MARKDOWN_SOURCES))
	$(RM)  doc/generated/* doc/htmldoc/*  doc/*/*~
	$(RM) doc/*.aux doc/*.log doc/*.bbl doc/*.blg doc/*.idx doc/*.ilg doc/*.ind doc/*.log doc/*.out doc/*.toc doc/*.haux doc/*.hind doc/*.html doc/*.htoc
	$(RM) doc/bismon-html-doc.tar.gz
	@printf "\n******* done cleaning bismon in %s *********\n\n" $$PWD

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
	@for c in $(BM_CSOURCES); do \
	  cp -a $$c $$c% ; \
	  $(INDENT) $(INDENTFLAGS) $$c ; \
	  $(INDENT) $(INDENTFLAGS) $$c ; \
	  if cmp -s $$c $$c% ; then echo unchanged $$c ; mv $$c% $$c ; \
	  else echo '*indented' $$c ; fi ; \
	done
	@printf "\n *** C testplugins *** \n"
	@for c in $(wildcard drafts/testplugin*.c); do \
	  cp -a $$c $$c% ; \
	  $(INDENT) $(INDENTFLAGS) $$c ; \
	  $(INDENT) $(INDENTFLAGS) $$c ; \
	  if cmp -s $$c $$c% ; then echo unchanged $$c ; mv $$c% $$c ; \
	  else echo '*indented' $$c ; fi ; \
	done
#!-      @printf "\n *** C modules sources *** \n"
#!-      @for c in $(MODULES_SOURCES); do \
#!-        cp -a $$c $$c% ; \
#!-        $(INDENT) $(INDENTFLAGS) $$c ; \
#!-        $(INDENT) $(INDENTFLAGS) $$c ; \
#!-        if cmp -s $$c $$c% ; then echo unchanged $$c ; mv $$c% $$c ; \
#!-        else echo '*indented' $$c ; fi ; \
#!-      done
	@printf "\n *** C++ sources *** \n"
	@for x in $(BM_CXXSOURCES) id_BM.h; do \
	  $(ASTYLE) $(ASTYLEFLAGS) $$x ; \
	done
	@sed -i 's/operator  */operator /g' id_BM.h
	@printf "\n *** C++ tool source *** \n"
	@$(ASTYLE) $(ASTYLEFLAGS)  BM_makeconst.cc
	@$(ASTYLE) $(ASTYLEFLAGS)  BM_compile_module.cc
	@printf "\n"

################
jstimestamp: webroot/jscript/_timestamp.mjs

chariotdemo-bismon: bismon programs modules jstimestamp
	@echo For the Chariot 2Q2019 demo, wait for Bismon to start,
	@echo ... then visit http://localhost:8086/ in your browser;
	@echo ... In another terminal, export your BISMONCOOKIE as shown
	@echo ... then, in your Chariot_metadata_example directory ...
	@echo ... do make chariotdemo-verbose-hello
	@echo '*******************************************'
	@echo ; echo ; echo
	@sleep 1
	./bismon --gui --web  -i init_chariotdemo

webroot/jscript/_timestamp.mjs: $(wildcard *.c *.h *.cc *.bmon webroot/jscript/[a-z]*.js webroot/jscript/[a-z]*.mjs) | bismon
	date +'// generated file $@ - DONT EDIT%n export const bismonjs_timestamp = "%c";%n export const bismonjs_timelong=%s.0;' > _timestamp.mjs-tmp
	(echo -n ' export const bismonjs_lastgitcommit="' ; \
           git log --format=oneline --abbrev=12 --abbrev-commit -q  \
         | head -1 | tr -d '\n\r\f\"\\\\' ; \
	 echo '";') >> _timestamp.mjs-tmp
	mv _timestamp.mjs-tmp $@
