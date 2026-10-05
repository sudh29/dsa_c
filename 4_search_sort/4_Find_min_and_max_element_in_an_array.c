#include <stdio.h>
#include <limits.h>

typedef struct {
    long long first;
    long long second;
} Pair;

Pair getMinMax(const long long a[], int n) {
    long long min_val = LLONG_MAX;
    long long max_val = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] < min_val) min_val = a[i];
        if (a[i] > max_val) max_val = a[i];
    }
    Pair res = {min_val, max_val};
    return res;
}

int main(void) {
    long long arr[] = {3, 2, 1, 56, 10000, 167};
    int n = sizeof(arr) / sizeof(arr[0]);
    Pair res = getMinMax(arr, n);
    printf("Min: %lld | Max: %lld\n", res.first, res.second);
    return 0;
}
