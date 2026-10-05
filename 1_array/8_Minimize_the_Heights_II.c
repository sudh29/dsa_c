#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

static inline int min(int a, int b) { return a < b ? a : b; }
static inline int max(int a, int b) { return a > b ? a : b; }

int getMinDiff(int arr[], int n, int k) {
    qsort(arr, n, sizeof(int), cmp_int);
    int ans = arr[n - 1] - arr[0];
    int smallest = arr[0] + k;
    int largest = arr[n - 1] - k;

    for (int i = 0; i < n - 1; i++) {
        int mi = min(smallest, arr[i + 1] - k);
        int ma = max(largest, arr[i] + k);
        if (mi < 0) continue;
        ans = min(ans, ma - mi);
    }
    return ans;
}

int main(void) {
    int arr[] = {1, 5, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    printf("Minimized max height diff: %d\n", getMinDiff(arr, n, k));
    return 0;
}
