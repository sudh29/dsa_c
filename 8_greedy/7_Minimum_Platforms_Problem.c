#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

static inline int max(int a, int b) { return a > b ? a : b; }

int findPlatform(int arr[], int dep[], int n) {
    qsort(arr, n, sizeof(int), cmp_int);
    qsort(dep, n, sizeof(int), cmp_int);

    int plat_needed = 1, result = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            plat_needed++;
            i++;
        } else {
            plat_needed--;
            j++;
        }
        result = max(result, plat_needed);
    }
    return result;
}

int main(void) {
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    printf("Min platforms needed: %d\n", findPlatform(arr, dep, 6));
    return 0;
}
