#include "main.h"
#include "printHelper.h"

// Print header from file
// Not conveninet to encode directly in C due to escape sequences
void printHeader() {
    FILE* fp = fopen(HEADER_FILENAME, "r");
    if (fp != NULL) {
        char* line = malloc(70 * sizeof(char));
        while (fgets(line, 70, fp) != NULL) {
            printf("%s", line);
        }
        free(line);
    }
    fclose(fp);
}