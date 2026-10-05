#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

bool findPair(int arr[], int size, int n) {
    qsort(arr, size, sizeof(int), cmp_int);
    int i = 0, j = 1;
    while (i < size && j < size) {
        if (i != j && arr[j] - arr[i] == n) {
            return true;
        } else if (arr[j] - arr[i] < n) {
            j++;
        } else {
            i++;
        }
    }
    return false;
}

int main(void) {
    int arr[] = {5, 20, 3, 2, 5, 80};
    int size = sizeof(arr) / sizeof(arr[0]);
    int diff = 78;
    printf("Pair with difference %d exists: %s\n", diff, findPair(arr, size, diff) ? "Yes" : "No");
    return 0;
}
