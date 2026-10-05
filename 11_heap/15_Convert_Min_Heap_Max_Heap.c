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

void convertMinToMaxHeap(int N, int arr[]) {
    for (int i = (N - 2) / 2; i >= 0; i--) {
        maxHeapify(arr, N, i);
    }
}

int main(void) {
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    convertMinToMaxHeap(n, arr);
    printf("Converted Min Heap to Max Heap: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
