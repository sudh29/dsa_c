#include <stdio.h>

int setAllRangeBits(int N, int L, int R) {
    int mask = ((1 << R) - 1) ^ ((1 << (L - 1)) - 1);
    return N | mask;
}

int main(void) {
    int n = 17, l = 2, r = 3;
    printf("Set range [%d, %d] in %d: %d\n", l, r, n, setAllRangeBits(n, l, r));
    return 0;
}
