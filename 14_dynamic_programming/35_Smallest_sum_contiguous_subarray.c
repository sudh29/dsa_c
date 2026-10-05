#include <stdio.h>

static int min(int a, int b) { return a < b ? a : b; }

int smallestSumSubarray(const int arr[], int n) {
    int min_so_far = arr[0];
    int curr = arr[0];

    for (int i = 1; i < n; i++) {
        curr = min(arr[i], curr + arr[i]);
        min_so_far = min(min_so_far, curr);
    }
    return min_so_far;
}

int main(void) {
    int arr[] = {3, -4, 2, -3, -1, 7, -5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Smallest contiguous subarray sum: %d (expected -6)\n", smallestSumSubarray(arr, n));
    return 0;
}
