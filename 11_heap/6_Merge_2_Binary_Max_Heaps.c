#include <stdio.h>

static void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void mergeHeaps(const int a[], const int b[], int n, int m, int merged[]) {
    for (int i = 0; i < n; i++) merged[i] = a[i];
    for (int i = 0; i < m; i++) merged[n + i] = b[i];
    int total = n + m;
    for (int i = total / 2 - 1; i >= 0; i--) {
        maxHeapify(merged, total, i);
    }
}

int main(void) {
    int a[] = {10, 5, 6, 2};
    int b[] = {12, 7, 9};
    int merged[7];
    mergeHeaps(a, b, 4, 3, merged);
    printf("Merged Max Heap root: %d\n", merged[0]);
    return 0;
}
