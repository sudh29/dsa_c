#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

int doUnion(const int a[], int n, const int b[], int m) {
    int total = n + m;
    int *merged = (int*)malloc(total * sizeof(int));
    if (!merged) return 0;
    for (int i = 0; i < n; i++) merged[i] = a[i];
    for (int i = 0; i < m; i++) merged[n + i] = b[i];

    qsort(merged, total, sizeof(int), cmp_int);

    int unique_count = 0;
    for (int i = 0; i < total; i++) {
        if (i == 0 || merged[i] != merged[i - 1]) unique_count++;
    }
    free(merged);
    return unique_count;
}

int main(void) {
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1, 2, 3};
    printf("Union size: %d\n", doUnion(a, 5, b, 3));
    return 0;
}
