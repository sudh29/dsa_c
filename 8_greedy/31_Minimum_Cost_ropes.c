#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    long long *data;
} MinHeap;

static void min_heapify(MinHeap *h, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < h->size && h->data[left] < h->data[smallest])
        smallest = left;
    if (right < h->size && h->data[right] < h->data[smallest])
        smallest = right;

    if (smallest != i) {
        long long temp = h->data[i];
        h->data[i] = h->data[smallest];
        h->data[smallest] = temp;
        min_heapify(h, smallest);
    }
}

static long long extract_min(MinHeap *h) {
    long long root = h->data[0];
    h->data[0] = h->data[h->size - 1];
    h->size--;
    min_heapify(h, 0);
    return root;
}

static void insert(MinHeap *h, long long val) {
    h->size++;
    int i = h->size - 1;
    h->data[i] = val;
    while (i != 0 && h->data[(i - 1) / 2] > h->data[i]) {
        long long temp = h->data[i];
        h->data[i] = h->data[(i - 1) / 2];
        h->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

long long minCost(const long long arr[], int n) {
    MinHeap h;
    h.size = n;
    h.data = (long long*)malloc(n * sizeof(long long));
    if (!h.data) return 0;
    for (int i = 0; i < n; i++) h.data[i] = arr[i];

    for (int i = (n - 1) / 2; i >= 0; i--) {
        min_heapify(&h, i);
    }

    long long cost = 0;
    while (h.size > 1) {
        long long first = extract_min(&h);
        long long second = extract_min(&h);
        cost += (first + second);
        insert(&h, first + second);
    }
    free(h.data);
    return cost;
}

int main(void) {
    long long arr[] = {4, 3, 2, 6};
    printf("Min cost connecting ropes: %lld (expected 29)\n", minCost(arr, 4));
    return 0;
}
