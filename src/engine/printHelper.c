#include "engine/printHelper.h"

// Print header from file
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