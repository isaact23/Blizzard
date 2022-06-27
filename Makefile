CC=gcc
CFLAGS=-ggdb3 -I.
FILES = gameState.c main.c minimax.c moveList.c moveLister.c pieces.c printHelper.c

blizzard: $(FILES)
	$(CC) -o blizzard $(FILES) $(CFLAGS)
