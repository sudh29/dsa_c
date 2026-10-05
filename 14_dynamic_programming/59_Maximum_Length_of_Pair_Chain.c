#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int a, b;
} Pair;

static int comparePairs(const void *x, const void *y) {
    const Pair *px = (const Pair *)x;
    const Pair *py = (const Pair *)y;
    return px->b - py->b;
}

int findLongestChain(Pair pairs[], int n) {
    qsort(pairs, n, sizeof(Pair), comparePairs);

    int current_end = INT_MIN;
    int max_chain = 0;

    for (int i = 0; i < n; i++) {
        if (current_end == INT_MIN || pairs[i].a > current_end) {
            current_end = pairs[i].b;
            max_chain++;
        }
    }
    return max_chain;
}

int main(void) {
    Pair pairs[] = {{1, 2}, {2, 3}, {3, 4}};
    printf("Longest pair chain: %d (expected 2)\n", findLongestChain(pairs, 3));
    return 0;
}
