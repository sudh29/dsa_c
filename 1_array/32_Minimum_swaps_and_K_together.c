#include <stdio.h>

static inline int min(int a, int b) { return a < b ? a : b; }

int minSwap(const int arr[], int n, int k) {
    int good = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= k) good++;
    }

    int bad = 0;
    for (int i = 0; i < good; i++) {
        if (arr[i] > k) bad++;
    }

    int ans = bad;
    for (int i = 0, j = good; j < n; i++, j++) {
        if (arr[i] > k) bad--;
        if (arr[j] > k) bad++;
        ans = min(ans, bad);
    }
    return ans;
}

int main(void) {
    int arr[] = {2, 1, 5, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printf("Min swaps to bring elements <= %d together: %d\n", k, minSwap(arr, n, k));
    return 0;
}
