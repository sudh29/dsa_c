#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("=== C File I/O Demonstration ===\n");
    const char *filename = "temp_demo.txt";

    // Writing
    FILE *outfile = fopen(filename, "w");
    if (!outfile) {
        perror("Error opening file for write");
        return 1;
    }
    fputs("Line 1: DSA in Pure C (C11)\n", outfile);
    fputs("Line 2: Fast, Robust, Efficient\n", outfile);
    fclose(outfile);

    // Reading
    FILE *infile = fopen(filename, "r");
    if (!infile) {
        perror("Error opening file for read");
        return 1;
    }
    char buffer[256];
    printf("Read contents:\n");
    while (fgets(buffer, sizeof(buffer), infile) != NULL) {
        printf("  %s", buffer);
    }
    fclose(infile);

    // Clean up temporary file
    remove(filename);
    return 0;
}
