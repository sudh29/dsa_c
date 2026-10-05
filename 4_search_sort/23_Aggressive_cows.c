#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

static bool canPlace(const int stalls[], int n, int cows, int minDist) {
    int count = 1, last = stalls[0];
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= minDist) {
            count++;
            last = stalls[i];
            if (count >= cows) return true;
        }
    }
    return false;
}

int largestMinDistance(int stalls[], int n, int cows) {
    qsort(stalls, n, sizeof(int), cmp_int);
    int low = 1, high = stalls[n - 1] - stalls[0], ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlace(stalls, n, cows, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main(void) {
    int stalls[] = {1, 2, 8, 4, 9};
    int n = sizeof(stalls) / sizeof(stalls[0]);
    int cows = 3;
    printf("Largest minimum distance for %d cows: %d\n", cows, largestMinDistance(stalls, n, cows));
    return 0;
}
