CFLAGS=-Wall -Wextra -Werror -g -lm 
# CFLAGS=-Wall -g -lm -fsanitize=address
# one should use -ggdb flag when a file is imported

SHELL=/bin/bash

CFILES=$(wildcard *.c)
OBJECTS=$(patsubst %.c,%,$(CFILES))

.PHONY: clean status all

all: $(OBJECTS)

$(OBJECTS): %:%.c
	gcc $(CFLAGS) -o $@ $< 

clean:
	rm -f $(OBJECTS)

status:
	@git status
	@git diff --stat

push: clean
	git push
#	git push -u DSA main
	

