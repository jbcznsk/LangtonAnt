CC = gcc
LDLIBS = -lncurses

all : ant

ant: ant.o

ant.o: ant.c

clean: 
	rm *.o *~

purge: clean
	rm ant
