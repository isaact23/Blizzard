CC=gcc
CFLAGS=-ggdb3 -O0 -I./inc -I./inc/interface
SRC = src/gameState.c src/moveList.c src/moveLister.c src/node.c src/pieces.c src/printHelper.c
TESTS = test/testPieces.c

interface: src/interface/interface.c src/interface/split.c
	$(CC) -o $@ $^ $(CFLAGS)

blizzard: $(SRC) src/main.c
	$(CC) -o blizzard $(SRC) src/main.c $(CFLAGS)

test: $(SRC) $(TESTS) test/test.c
	$(CC) -o test_blizzard $(SRC) $(TESTS) test/test.c -I./test $(CFLAGS)

clean:
	rm -f blizzard test_blizzard