#include <stdio.h>
#include <stdlib.h>

static inline int max(int a, int b) { return a > b ? a : b; }

int search(const int arr[], int n, int x, int k) {
    int i = 0;
    while (i < n) {
        if (arr[i] == x) return i;
        i += max(1, abs(arr[i] - x) / k);
    }
    return -1;
}

int main(void) {
    int arr[] = {4, 5, 6, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 6, k = 1;
    printf("Index of %d: %d\n", x, search(arr, n, x, k));
    return 0;
}
