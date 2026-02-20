CC=gcc
CFLAGS=-ggdb3 -O0

blizzard: bin/blizzard
bin/blizzard: bin $(SRC) src/interface/*.c src/engine/*.c
	$(CC) -o $@ $^ $(CFLAGS) -I./inc

interface: bin/interface.o
bin/interface.o: bin src/interface/*.c
	$(CC) -o $@ $^ $(CFLAGS) -I./inc

test: bin/test.o
bin/test.o: bin src/engine/*.c test/*.c
	$(CC) -o $@ $^ $(CFLAGS) -I./test -I./inc

bin:
	mkdir -p bin

clean:
	rm -rf ./bin