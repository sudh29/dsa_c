#include <stdio.h>

int setBits(int N) {
    int count = 0;
    while (N > 0) {
        N &= (N - 1);
        count++;
    }
    return count;
}

int main(void) {
    int n = 6;
    printf("Set bits in %d: %d\n", n, setBits(n));
    return 0;
}
