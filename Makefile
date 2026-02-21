CC=gcc
CFLAGS=-ggdb3 -O2 -pthread

all: bin bin/blizzard

bin/blizzard: bin/engine.o bin/interface.o bin/error.o
	$(CC) -o $@ $^

bin/engine.o: src/engine/*.c
	$(CC) -o $@ $^ $(CFLAGS) -r -I./inc

bin/interface.o: src/interface/*.c
	$(CC) -o $@ $^ $(CFLAGS) -r -I./inc

bin/test.o: src/engine/*.c test/*.c
	$(CC) -o $@ $^ $(CFLAGS) -I./test -I./inc

bin/error.o: src/error.c
	$(CC) -o $@ $^ $(CFLAGS) -r -I./inc

bin:
	mkdir -p bin

clean:
	rm -rf ./bin