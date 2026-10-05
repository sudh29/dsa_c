#include <stdio.h>
#include <stdlib.h>

static int compareAsc(const void *a, const void *b) {
    return (*(const int*)a - *(const int*)b);
}

int kthSmallest(int arr[], int l, int r, int k) {
    int len = r - l + 1;
    qsort(arr + l, len, sizeof(int), compareAsc);
    return arr[l + k - 1];
}

int main(void) {
    int arr[] = {7, 10, 4, 3, 20, 15};
    printf("3rd smallest element: %d\n", kthSmallest(arr, 0, 5, 3));
    return 0;
}
