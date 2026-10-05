#include <stdio.h>

static inline void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void threeWayPartition(int array[], int n, int a, int b) {
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) {
        if (array[mid] < a) {
            swap(&array[low++], &array[mid++]);
        } else if (array[mid] > b) {
            swap(&array[mid], &array[high--]);
        } else {
            mid++;
        }
    }
}

int main(void) {
    int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
    int n = sizeof(arr) / sizeof(arr[0]);
    threeWayPartition(arr, n, 10, 20);
    printf("Three-way partitioned around [10, 20]: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
