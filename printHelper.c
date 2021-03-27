#include "main.h"
#include "printHelper.h"

// Print the program header, which includes BLIZZARD ascii art
void printHeader() {
    printf("\n");
    // Load BLIZZARD ASCII art
    FILE* fp = fopen("blizzard_ascii.txt", 'r');
    printf("\n");
    printf("Blizzard chess engine, written by Isaac Thompson in C. Version 1.0.\n");
}