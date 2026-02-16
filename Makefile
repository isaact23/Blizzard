CC=gcc
CFLAGS=-ggdb3 -I./inc
FILES = src/gameState.c src/main.c src/moveList.c src/moveLister.c src/pieces.c src/printHelper.c

blizzard: $(FILES)
	$(CC) -o blizzard $(FILES) $(CFLAGS)
