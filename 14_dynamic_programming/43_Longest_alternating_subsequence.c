#include <stdio.h>

static int max(int a, int b) { return a > b ? a : b; }

int alternatingMaxLength(const int arr[], int n) {
    if (n == 0) return 0;
    int up = 1, down = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            up = down + 1;
        } else if (arr[i] < arr[i - 1]) {
            down = up + 1;
        }
    }
    return max(up, down);
}

int main(void) {
    int arr[] = {1, 5, 4};
    printf("Max alternating subsequence length: %d (expected 3)\n", alternatingMaxLength(arr, 3));
    return 0;
}
