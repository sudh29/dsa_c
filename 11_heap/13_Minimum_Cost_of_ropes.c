#include <stdio.h>

static void swap(long long *a, long long *b) {
    long long t = *a; *a = *b; *b = t;
}

static void minHeapify(long long arr[], int n, int i) {
    int smallest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

long long minCost(long long arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) minHeapify(arr, n, i);

    long long totalCost = 0;
    while (n > 1) {
        long long first = arr[0];
        arr[0] = arr[n - 1];
        n--;
        minHeapify(arr, n, 0);

        long long second = arr[0];
        long long cost = first + second;
        totalCost += cost;

        arr[0] = cost;
        minHeapify(arr, n, 0);
    }
    return totalCost;
}

int main(void) {
    long long ropes[] = {4, 3, 2, 6};
    printf("Min cost of connecting ropes: %lld\n", minCost(ropes, 4));
    return 0;
}
