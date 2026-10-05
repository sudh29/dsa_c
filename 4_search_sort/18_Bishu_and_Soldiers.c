#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

static int upper_bound(const int arr[], int n, int val) {
    int low = 0, high = n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= val) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main(void) {
    int n = 7;
    int soldiers[] = {1, 2, 3, 4, 5, 6, 7};
    qsort(soldiers, n, sizeof(int), cmp_int);

    int prefix[n + 1];
    prefix[0] = 0;
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + soldiers[i];

    int queries[] = {3, 10, 2};
    int num_queries = sizeof(queries) / sizeof(queries[0]);

    printf("=== Bishu and Soldiers Query Results ===\n");
    for (int i = 0; i < num_queries; i++) {
        int power = queries[i];
        int idx = upper_bound(soldiers, n, power);
        printf("Power %d -> Defeated: %d, Cumulative Strength: %d\n", power, idx, prefix[idx]);
    }
    return 0;
}
