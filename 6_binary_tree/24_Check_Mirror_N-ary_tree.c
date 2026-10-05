#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_NODES 100

int checkMirrorTree(int n, int e, const int A[], const int B[]) {
    (void)n;
    // For each node u, store edges from A and B
    int adjA[MAX_NODES][MAX_NODES];
    int degA[MAX_NODES] = {0};
    int adjB[MAX_NODES][MAX_NODES];
    int degB[MAX_NODES] = {0};

    for (int i = 0; i < 2 * e; i += 2) {
        int u = A[i], v = A[i + 1];
        adjA[u][degA[u]++] = v;
    }
    for (int i = 0; i < 2 * e; i += 2) {
        int u = B[i], v = B[i + 1];
        adjB[u][degB[u]++] = v;
    }

    for (int u = 0; u < MAX_NODES; u++) {
        if (degA[u] != degB[u]) return 0;
        int len = degA[u];
        for (int k = 0; k < len; k++) {
            if (adjA[u][k] != adjB[u][len - 1 - k]) return 0;
        }
    }
    return 1;
}

int main(void) {
    int A[] = {1, 2, 1, 3};
    int B[] = {1, 3, 1, 2};
    int res = checkMirrorTree(3, 2, A, B);
    printf("Are N-ary trees mirrors: %s\n", res ? "Yes" : "No");
    assert(res == 1);
    return 0;
}
