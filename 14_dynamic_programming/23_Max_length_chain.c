#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a, b;
} Pair;

static int comparePairs(const void *x, const void *y) {
    const Pair *px = (const Pair *)x;
    const Pair *py = (const Pair *)y;
    return px->b - py->b;
}

int maxChainLen(Pair p[], int n) {
    if (n == 0) return 0;
    qsort(p, n, sizeof(Pair), comparePairs);

    int count = 1;
    int last_end = p[0].b;

    for (int i = 1; i < n; i++) {
        if (p[i].a > last_end) {
            count++;
            last_end = p[i].b;
        }
    }
    return count;
}

int main(void) {
    Pair p[] = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
    int n = sizeof(p) / sizeof(p[0]);
    printf("Max length chain: %d (expected 3)\n", maxChainLen(p, n));
    return 0;
}
