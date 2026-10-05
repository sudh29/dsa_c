#include <stdio.h>

static inline void swap_ll(long long *a, long long *b) {
    long long t = *a;
    *a = *b;
    *b = t;
}

static int nextGap(int gap) {
    if (gap <= 1) return 0;
    return (gap / 2) + (gap % 2);
}

void merge(long long arr1[], long long arr2[], int n, int m) {
    int gap = nextGap(n + m);
    while (gap > 0) {
        int i = 0, j = gap;
        while (j < (n + m)) {
            if (j < n && arr1[i] > arr1[j]) {
                swap_ll(&arr1[i], &arr1[j]);
            } else if (i < n && j >= n && arr1[i] > arr2[j - n]) {
                swap_ll(&arr1[i], &arr2[j - n]);
            } else if (i >= n && j >= n && arr2[i - n] > arr2[j - n]) {
                swap_ll(&arr2[i - n], &arr2[j - n]);
            }
            i++;
            j++;
        }
        gap = nextGap(gap);
    }
}

int main(void) {
    long long arr1[] = {1, 3, 5, 7};
    long long arr2[] = {0, 2, 6, 8, 9};
    int n = 4, m = 5;
    merge(arr1, arr2, n, m);
    printf("Merged arr1: ");
    for (int i = 0; i < n; i++) printf("%lld ", arr1[i]);
    printf("| arr2: ");
    for (int i = 0; i < m; i++) printf("%lld ", arr2[i]);
    printf("\n");
    return 0;
}
