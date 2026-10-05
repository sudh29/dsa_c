#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

int find_median(int v[], int n) {
    qsort(v, n, sizeof(int), cmp_int);
    if (n % 2 != 0) return v[n / 2];
    return (v[n / 2 - 1] + v[n / 2]) / 2;
}

int main(void) {
    int v[] = {90, 100, 78, 89, 67};
    int n = sizeof(v) / sizeof(v[0]);
    printf("Median of array: %d\n", find_median(v, n));
    return 0;
}
