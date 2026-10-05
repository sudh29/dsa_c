#include <stdio.h>

int minimumNumberOfSwaps(const char *S) {
    int count = 0, p = 0, sum = 0;
    for (int i = 0; S[i]; i++) {
        if (S[i] == '[') {
            count++;
            if (p > 0) {
                sum += p;
                p--;
            }
        } else if (S[i] == ']') {
            count--;
            if (count < 0) {
                p++;
            }
        }
    }
    return sum;
}

int main(void) {
    const char *s = "[]][][";
    printf("Min swaps for bracket balancing: %d\n", minimumNumberOfSwaps(s));
    return 0;
}
