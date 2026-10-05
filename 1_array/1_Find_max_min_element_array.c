#include <stdio.h>
#include <limits.h>

typedef struct {
    long long first;  // min
    long long second; // max
} Pair;

Pair getMinMax(const long long a[], int n) {
    Pair res = {LLONG_MAX, LLONG_MIN};
    for (int i = 0; i < n; i++) {
        if (a[i] < res.first) res.first = a[i];
        if (a[i] > res.second) res.second = a[i];
    }
    return res;
}

int main(void) {
    long long arr[] = {3, 2, 1, 56, 10000, 167};
    int n = sizeof(arr) / sizeof(arr[0]);
    Pair res = getMinMax(arr, n);
    printf("Min: %lld | Max: %lld\n", res.first, res.second);
    return 0;
}
