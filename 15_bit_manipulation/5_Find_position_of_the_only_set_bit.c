#include <stdio.h>

int findPosition(int N) {
    if (N <= 0 || (N & (N - 1)) != 0) return -1;
    int pos = 1;
    while ((1 << (pos - 1)) != N) pos++;
    return pos;
}

int main(void) {
    printf("Position of only set bit in 16: %d\n", findPosition(16));
    printf("Position of only set bit in 12: %d\n", findPosition(12));
    return 0;
}
