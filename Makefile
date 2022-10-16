CFLAGS=-Wall -Wextra -g -lm 
# CFLAGS=-Wall -g -lm -Werror -fsanitize=address
# one should use -ggdb flag when a file is imported

SHELL=/bin/bash

BIN=./bin

CFILES=$(wildcard *.c)
TMPS=$(patsubst %.c,%,$(CFILES))
OBJECTS=$(addprefix $(BIN)/, $(TMPS))

.PHONY: clean status all

all: $(OBJECTS)

$(OBJECTS): $(BIN)/%:%.c
	gcc $(CFLAGS) -o $@ $< 

clean:
	rm -f $(OBJECTS)

status:
	@git status
	@git diff --stat

push:
	git push
#	git push -u DSA main
	

