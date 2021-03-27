#include "main.h"
#include "printHelper.h"

// Print the program header, which includes BLIZZARD ascii art
void printHeader() {
    FILE* fp = fopen(HEADER_FILENAME, "r");
    if (fp != NULL) {
        char* line = malloc(70 * sizeof(char));
        while (fgets(line, 70, fp) != NULL) {
            printf("%s", line);
        }
        free(line);
    }
    free(fp);
}