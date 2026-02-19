CC=gcc
CFLAGS=-ggdb3 -O0
SRC = src/gameState.c src/moveList.c src/moveLister.c src/node.c src/pieces.c src/printHelper.c
TESTS = test/testPieces.c

interface: bin/interface.o
bin/interface.o: src/interface/*.c bin
	$(CC) -o $@ $^ $(CFLAGS) -I./inc/interface

bin:
	mkdir -p bin

blizzard: $(SRC) src/main.c
	$(CC) -o blizzard $(SRC) src/main.c $(CFLAGS)

test: $(SRC) $(TESTS) test/test.c
	$(CC) -o test_blizzard $(SRC) $(TESTS) test/test.c -I./test $(CFLAGS)

clean:
	rm -rf ./bin