#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

int kthSmallest(const int arr[], int l, int r, int k) {
    int n = r - l + 1;
    int *temp = (int*)malloc(n * sizeof(int));
    if (!temp) return -1;
    for (int i = 0; i < n; i++) temp[i] = arr[l + i];
    qsort(temp, n, sizeof(int), cmp_int);
    int res = temp[k - 1];
    free(temp);
    return res;
}

int main(void) {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printf("%d-th smallest: %d\n", k, kthSmallest(arr, 0, n - 1, k));
    return 0;
}
