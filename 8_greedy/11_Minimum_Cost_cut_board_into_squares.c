#include <stdio.h>
#include <stdlib.h>

static int cmp_desc(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ib - ia);
}

int minimumCostOfBreaking(int X[], int Y[], int M, int N) {
    int p = M - 1, q = N - 1;
    qsort(X, p, sizeof(int), cmp_desc);
    qsort(Y, q, sizeof(int), cmp_desc);

    int hzntl = 1, vert = 1;
    int i = 0, j = 0;
    int ans = 0;

    while (i < p && j < q) {
        if (X[i] > Y[j]) {
            ans += X[i++] * vert;
            hzntl++;
        } else {
            ans += Y[j++] * hzntl;
            vert++;
        }
    }
    while (i < p) ans += X[i++] * vert;
    while (j < q) ans += Y[j++] * hzntl;
    return ans;
}

int main(void) {
    int X[] = {2, 1, 3, 1, 4};
    int Y[] = {4, 1, 2};
    printf("Minimum cost of cutting board: %d\n", minimumCostOfBreaking(X, Y, 6, 4));
    return 0;
}
