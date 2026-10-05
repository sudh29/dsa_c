#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

static void findCombinations(const int arr[], int n, int target, int idx, int current[], int cur_sz) {
    if (target == 0) {
        printf("[ ");
        for (int i = 0; i < cur_sz; i++) printf("%d ", current[i]);
        printf("]\n");
        return;
    }

    for (int i = idx; i < n; i++) {
        if (i > idx && arr[i] == arr[i - 1]) continue;
        if (arr[i] > target) break;

        current[cur_sz] = arr[i];
        findCombinations(arr, n, target - arr[i], i, current, cur_sz + 1);
    }
}

int main(void) {
    int arr[] = {2, 4, 6, 8};
    int n = 4, target = 8;
    qsort(arr, n, sizeof(int), cmp_int);
    int current[32];

    printf("Combinations summing to %d:\n", target);
    findCombinations(arr, n, target, 0, current, 0);
    return 0;
}
