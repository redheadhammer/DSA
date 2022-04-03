CFLAGS= -Wall -Wextra -g -lm

SHELL=/bin/bash

CFILES=$(wildcard *.c)
OBJECTS=$(patsubst %.c,%,$(CFILES))

all: $(OBJECTS)

$(OBJECTS): $(CFILES)
	gcc -o $@ $(patsubst %,%.c,$@)

.PHONY: clean status

clean:
	rm -f $(OBJECTS)

status:
	@git status
	@git diff --stat


