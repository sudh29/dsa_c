#include <stdio.h>

static inline int max(int a, int b) { return a > b ? a : b; }

int minJumps(const int arr[], int n) {
    if (n <= 1) return 0;
    if (arr[0] == 0) return -1;

    int maxReach = arr[0];
    int step = arr[0];
    int jump = 1;

    for (int i = 1; i < n; i++) {
        if (i == n - 1) return jump;
        maxReach = max(maxReach, i + arr[i]);
        step--;

        if (step == 0) {
            jump++;
            if (i >= maxReach) return -1;
            step = maxReach - i;
        }
    }
    return -1;
}

int main(void) {
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Min jumps to reach end: %d\n", minJumps(arr, n));
    return 0;
}
