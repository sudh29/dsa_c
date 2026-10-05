#include <stdio.h>
#include <string.h>

static inline int min(int a, int b) { return a < b ? a : b; }

int minFlips(const char *S) {
    int flips0 = 0, flips1 = 0;
    for (int i = 0; S[i]; i++) {
        char exp0 = (i % 2 == 0) ? '0' : '1';
        char exp1 = (i % 2 == 0) ? '1' : '0';
        if (S[i] != exp0) flips0++;
        if (S[i] != exp1) flips1++;
    }
    return min(flips0, flips1);
}

int main(void) {
    const char *s = "0001010111";
    printf("Min flips to alternate: %d\n", minFlips(s));
    return 0;
}
