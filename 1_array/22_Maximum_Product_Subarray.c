#include <stdio.h>

static inline void swap_ll(long long *a, long long *b) {
    long long t = *a;
    *a = *b;
    *b = t;
}

static inline long long max_ll(long long a, long long b) { return a > b ? a : b; }
static inline long long min_ll(long long a, long long b) { return a < b ? a : b; }

long long maxProduct(const int arr[], int n) {
    long long max_prod = arr[0];
    long long cur_max = arr[0], cur_min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < 0) swap_ll(&cur_max, &cur_min);
        cur_max = max_ll((long long)arr[i], cur_max * arr[i]);
        cur_min = min_ll((long long)arr[i], cur_min * arr[i]);
        max_prod = max_ll(max_prod, cur_max);
    }
    return max_prod;
}

int main(void) {
    int arr[] = {6, -3, -10, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Max product subarray: %lld\n", maxProduct(arr, n));
    return 0;
}
