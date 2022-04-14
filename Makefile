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
