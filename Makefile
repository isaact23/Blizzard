CC=gcc
CFLAGS=-ggdb3 -O0

blizzard: bin/blizzard
bin/blizzard: bin/engine.o bin/interface.o
	$(CC) -o $@ $^

engine: bin bin/engine.o
bin/engine.o: src/engine/*.c
	$(CC) -o $@ $^ $(CFLAGS) -r -I./inc

interface: bin bin/interface.o
bin/interface.o: src/interface/*.c
	$(CC) -o $@ $^ $(CFLAGS) -r -I./inc

test: bin bin/test.o
bin/test.o: src/engine/*.c test/*.c
	$(CC) -o $@ $^ $(CFLAGS) -I./test -I./inc

bin:
	mkdir -p bin

clean:
	rm -rf ./bin