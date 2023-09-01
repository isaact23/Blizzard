CC=gcc
CFLAGS=-ggdb3 -I.

blizzard: $(FILES)
	$(CC) -o blizzard ./src/* $(CFLAGS)

clean:
	rm -rf *.o
	rm blizzard