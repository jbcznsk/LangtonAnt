CC = gcc
LDLIBS = -lncurses
CFLAGS = -Wall

all : ant

ant: ant.o

ant.o: ant.c

clean: 
	rm *.o *~

purge: clean
	rm ant
