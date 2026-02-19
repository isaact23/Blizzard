CC=gcc
CFLAGS=-ggdb3 -O0
SRC = src/gameState.c src/moveList.c src/moveLister.c src/node.c src/pieces.c src/printHelper.c

interface: bin/interface.o
bin/interface.o: src/interface/*.c bin
	$(CC) -o $@ $^ $(CFLAGS) -I./inc

bin:
	mkdir -p bin

blizzard: $(SRC) src/main.c
	$(CC) -o $@ $^ $(CFLAGS)

test: test_blizzard
test_blizzard: src/engine/*.c test/*.c
	$(CC) -o $@ $^ $(CFLAGS) -I./test -I./inc

clean:
	rm -rf ./bin