## the Makefile
CC=gcc
CCACHE= ccache
WARNFLAGS= -Wall -Wextra -Wmissing-prototypes -fdiagnostics-color=auto
OPTIMFLAGS= -O1 -g3
CFLAGS= -std=gnu11 $(WARNFLAGS) $(PREPROFLAGS) $(OPTIMFLAGS)
INDENT= indent
ASTYLE= astyle
MD5SUM= md5sum
INDENTFLAGS= --gnu-style --no-tabs --honour-newlines
ASTYLEFLAGS= --style=gnu -s2
PACKAGES= gtk+-3.0
PKGCONFIG= pkg-config
PREPROFLAGS= -I. -I/usr/local/include $(shell $(PKGCONFIG) --cflags $(PACKAGES))

LIBES= -L/usr/local/lib $(shell $(PKGCONFIG) --libs $(PACKAGES)) -ldl -lm
RM= rm -fv


CSOURCES= $(sort  $(wildcard [a-zA-Z]*.c))
BM_HEADERS= $(sort $(wildcard *_BM.h))
BM_COLDSOURCES= $(sort $(wildcard *_BM.c))
GENERATED_HEADERS= $(sort $(wildcard _[a-z0-9]*.h))
GENERATED_CSOURCES= $(sort $(wildcard _[a-z0-9]*.c))

OBJECTS= $(patsubst %.c,%.o,$(BM_COLDSOURCES) $(GENERATED_CSOURCES))

.PHONY: all clean indent count
all: bismon
clean:
	$(RM) .*~ *~ *% *.o *.so */*.so *.log */*~ */*.orig *.i *.orig *.gch README.html


indent: .indent.pro
	@for h in $(BM_HEADERS); do \
	  cp -a $$h $$h% ; \
	  $(INDENT) $(INDENTFLAGS) $$h ; \
	  $(INDENT) $(INDENTFLAGS) $$h ; \
	  if cmp -s $$h $$h% ; then echo unchanged $$h ; mv $$h% $$h ; \
          else echo indented $$h ; fi \
	done
	@for c in $(BM_COLDSOURCES); do \
	  cp -a $$c $$c% ; \
	  $(INDENT) $(INDENTFLAGS) $$c ; \
	  $(INDENT) $(INDENTFLAGS) $$c ; \
	  if cmp -s $$c $$c% ; then echo unchanged $$c ; mv $$c% $$c ; \
	  else echo indented $$c ; fi ; \
	done

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
	$(COMPILE.c) $(CFLAGS) -c $< -o $@

$(OBJECTS): bismon.h.gch

%_BM.o: %_BM.c bismon.h.gch
	$(CCACHE) $(COMPILE.c) $(CFLAGS) -c $< -o $@

bismon: $(OBJECTS)
	@if [ -f $@ ]; then echo -n backup old executable: ' ' ; mv -v $@ $@~ ; fi
	$(MAKE) __timestamp.c __timestamp.o
	$(LINK.c)  $(LINKFLAGS) -rdynamic $(OBJECTS) $(LIBES) -o $@  __timestamp.o
	$(RM) __timestamp.*

count:
	wc -cl *.c *.h | sort -n
