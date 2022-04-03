CFLAGS= -Wall -g -lm

SHELL=/bin/bash
all:
	echo "Nothing"
# clean: SHELL:=/bin/bash
clean:
	rm -i !*.c|Makefile

test:
	rm valocity

