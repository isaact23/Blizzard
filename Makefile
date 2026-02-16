CC=gcc
CFLAGS=-ggdb3 -O0 -I./inc
SRC = src/gameState.c src/moveList.c src/moveLister.c src/pieces.c src/printHelper.c
TESTS = test/testPieces.c

blizzard: $(SRC) src/main.c
	$(CC) -o blizzard $(SRC) src/main.c $(CFLAGS)

test: $(SRC) $(TESTS) test/test.c
	$(CC) -o test_blizzard $(SRC) $(TESTS) test/test.c -I./test $(CFLAGS)

clean:
	rm -f blizzard test_blizzard