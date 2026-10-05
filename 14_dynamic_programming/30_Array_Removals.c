#include <stdio.h>
#include <stdlib.h>

static int compareAsc(const void *a, const void *b) {
    return (*(const int*)a - *(const int*)b);
}

static int min(int a, int b) { return a < b ? a : b; }

int removals(int arr[], int n, int k) {
    qsort(arr, n, sizeof(int), compareAsc);
    int min_removals = n - 1;
    int j = 0;

    for (int i = 0; i < n; i++) {
        while (j < n && arr[j] - arr[i] <= k) {
            j++;
        }
        min_removals = min(min_removals, n - (j - i));
    }
    return min_removals;
}

int main(void) {
    int arr[] = {1, 3, 4, 9, 10, 11, 12, 17, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    printf("Min removals: %d (expected 5)\n", removals(arr, n, k));
    return 0;
}
