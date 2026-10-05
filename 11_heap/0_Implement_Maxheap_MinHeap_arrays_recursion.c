#include <stdio.h>

static void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] < arr[smallest]) smallest = left;
    if (right < n && arr[right] < arr[smallest]) smallest = right;
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) maxHeapify(arr, n, i);
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) minHeapify(arr, n, i);
}

int main(void) {
    int arr1[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    buildMaxHeap(arr1, n);
    printf("Max Heap: ");
    for (int i = 0; i < n; i++) printf("%d ", arr1[i]);
    printf("\n");

    int arr2[] = {4, 10, 3, 5, 1};
    buildMinHeap(arr2, n);
    printf("Min Heap: ");
    for (int i = 0; i < n; i++) printf("%d ", arr2[i]);
    printf("\n");
    return 0;
}
