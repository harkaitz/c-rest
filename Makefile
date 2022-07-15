## Configuration
DESTDIR     =
PREFIX      =/usr/local
AR          =ar
CC          =gcc
CFLAGS      =-Wall -g
CPPFLAGS    =
LIBS        =
HEADERS     =             \
    curl/crest.h          \
    jansson/extra.h       \
    kcgi/extra-cookies.h  \
    kcgi/extra-redirect.h \
    kcgi/extra-fields.h   \
    str/urlencode.h
PROGRAMS    =             \
    tools/urlencode

## Help string.
all:
help:
	@echo 'all     : Build everything.'
	@echo 'clean   : Clean files.'
	@echo 'install : Install all produced files.'

## Programs.
all: $(PROGRAMS)
tools/%: tools/%.c
	$(CC) -o $@ $<$(CFLAGS_ALL) $(LIBS)

## Install and clean.
install:
	@for h in $(HEADERS);do                         \
	   d=$(DESTDIR)$(PREFIX)/include/`dirname $$h`; \
	   install -v -d $$d;                           \
	   install -v -m644 $$h $$d;                    \
	done
clean:
	rm -f $(PROGRAMS)
## -- manpages --
MAN_3=./doc/crest.3 ./doc/urlencode.3 
install: install-man3
install-man3: $(MAN_3)
	mkdir -p $(DESTDIR)$(PREFIX)/share/man/man3
	cp $(MAN_3) $(DESTDIR)$(PREFIX)/share/man/man3
## -- manpages --
## -- license --
install: install-license
install-license: LICENSE
	mkdir -p $(DESTDIR)$(PREFIX)/share/doc/c-rest
	cp LICENSE $(DESTDIR)$(PREFIX)/share/doc/c-rest
## -- license --
