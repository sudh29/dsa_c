#include <stdio.h>

int inSequence(int A, int B, int C) {
    if (C == 0) return A == B;
    int d = (B - A) / C;
    int r = (B - A) % C;
    return (d >= 0 && r == 0) ? 1 : 0;
}

int main(void) {
    printf("Is 7 in seq (1, step 2): %d\n", inSequence(1, 7, 2));
    printf("Is 8 in seq (1, step 2): %d\n", inSequence(1, 8, 2));
    return 0;
}
