#include <stdio.h>

static long long maxLL(long long a, long long b) { return a > b ? a : b; }

long long maxSubArraySum(const int arr[], int n) {
    long long max_so_far = arr[0];
    long long curr = arr[0];

    for (int i = 1; i < n; i++) {
        curr = maxLL(1LL * arr[i], curr + arr[i]);
        max_so_far = maxLL(max_so_far, curr);
    }
    return max_so_far;
}

int main(void) {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Max contiguous subarray sum: %lld (expected 6)\n", maxSubArraySum(arr, n));
    return 0;
}
