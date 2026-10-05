#include <stdio.h>
#include <string.h>

void printDups(const char *str) {
    int count[256] = {0};
    int len = (int)strlen(str);
    for (int i = 0; i < len; i++) {
        count[(unsigned char)str[i]]++;
    }
    printf("Duplicate characters in '%s':\n", str);
    for (int i = 0; i < 256; i++) {
        if (count[i] > 1) {
            printf("  ['%c', count = %d]\n", (char)i, count[i]);
        }
    }
}

int main(void) {
    printDups("test string");
    return 0;
}
