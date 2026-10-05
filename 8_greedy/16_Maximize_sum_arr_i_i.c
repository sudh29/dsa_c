#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

static int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

int Maximize(int a[], int n) {
    qsort(a, n, sizeof(int), cmp_int);
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
        sum = (sum + (long long)a[i] * i) % MOD;
    }
    return (int)sum;
}

int main(void) {
    int a1[] = {5, 3, 2, 4, 1};
    printf("Max sum: %d (expected 40)\n", Maximize(a1, 5));
    return 0;
}
