CC=gcc
FLAGS= -Wall -g

all: libmytrie.a frequency
frequency: libmytrie.a
	$(CC) $(FLAGS) -o frequency libmytrie.a
libmytrie.a: frequency.o
	ar -rcs libmytrie.a frequency.o
frequency.o: frequency.c header.h
	$(CC) $(FLAGS) -c frequency.c


.PHONY: clean all

clean:
	rm -f *.a *.o *.out frequency
