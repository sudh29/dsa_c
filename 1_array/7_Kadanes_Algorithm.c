#include <stdio.h>
#include <limits.h>

long long maxSubarraySum(const int arr[], int n) {
    long long max_so_far = LLONG_MIN, current_max = 0;
    for (int i = 0; i < n; i++) {
        current_max += arr[i];
        if (max_so_far < current_max) max_so_far = current_max;
        if (current_max < 0) current_max = 0;
    }
    return max_so_far;
}

int main(void) {
    int arr[] = {1, 2, 3, -2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Max contiguous subarray sum: %lld\n", maxSubarraySum(arr, n));
    return 0;
}
