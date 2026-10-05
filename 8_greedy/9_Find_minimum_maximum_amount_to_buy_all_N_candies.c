#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

void candyStore(int candies[], int N, int K, int *out_min, int *out_max) {
    qsort(candies, N, sizeof(int), cmp_int);
    int min_cost = 0, max_cost = 0;

    int i = 0, j = N - 1;
    while (i <= j) {
        min_cost += candies[i++];
        j -= K;
    }

    i = N - 1;
    j = 0;
    while (i >= j) {
        max_cost += candies[i--];
        j += K;
    }
    *out_min = min_cost;
    *out_max = max_cost;
}

int main(void) {
    int candies[] = {3, 2, 1, 4};
    int min_c, max_c;
    candyStore(candies, 4, 2, &min_c, &max_c);
    printf("Min candy amount: %d, Max candy amount: %d\n", min_c, max_c);
    return 0;
}
