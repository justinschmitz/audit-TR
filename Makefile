CC=gcc
CPP=g++
CFLAGS=-Wall -I
DBUG=-g
INC=./include/
RSRC=./rsrc/
BIN=./bin/
TARGET=attr
OBJ=./obj

build:
	$(CC) $(CFLAGS) ./include/ -c ./src/*.c
	$(CC) $(CFLAGS) ./include/ -o ./bin/autr *.o

clean:
	rm -fv *.o

test:
	valgrind ./bin/autr


