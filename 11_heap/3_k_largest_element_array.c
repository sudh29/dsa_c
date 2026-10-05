#include <stdio.h>
#include <stdlib.h>

static int compareDesc(const void *a, const void *b) {
    return (*(const int*)b - *(const int*)a);
}

void kLargest(int arr[], int n, int k, int res[]) {
    qsort(arr, n, sizeof(int), compareDesc);
    for (int i = 0; i < k; i++) res[i] = arr[i];
}

int main(void) {
    int arr[] = {12, 5, 787, 1, 23};
    int res[2];
    kLargest(arr, 5, 2, res);
    printf("2 largest elements: %d %d\n", res[0], res[1]);
    return 0;
}
