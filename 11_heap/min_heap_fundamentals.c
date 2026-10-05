#include <stdio.h>
#include <stdbool.h>

#define MAX_CAP 100

typedef struct {
    int heap[MAX_CAP];
    int size;
} MinHeap;

static void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

static void heapifyUp(MinHeap *mh, int i) {
    while (i > 0 && mh->heap[(i - 1) / 2] > mh->heap[i]) {
        swap(&mh->heap[(i - 1) / 2], &mh->heap[i]);
        i = (i - 1) / 2;
    }
}

static void heapifyDown(MinHeap *mh, int i) {
    int n = mh->size;
    while (2 * i + 1 < n) {
        int left = 2 * i + 1, right = 2 * i + 2, smallest = i;
        if (left < n && mh->heap[left] < mh->heap[smallest]) smallest = left;
        if (right < n && mh->heap[right] < mh->heap[smallest]) smallest = right;
        if (smallest == i) break;
        swap(&mh->heap[i], &mh->heap[smallest]);
        i = smallest;
    }
}

void insertMin(MinHeap *mh, int val) {
    if (mh->size >= MAX_CAP) return;
    mh->heap[mh->size++] = val;
    heapifyUp(mh, mh->size - 1);
}

int extractMin(MinHeap *mh) {
    if (mh->size == 0) return -1;
    int minVal = mh->heap[0];
    mh->heap[0] = mh->heap[--mh->size];
    heapifyDown(mh, 0);
    return minVal;
}

int getMin(const MinHeap *mh) {
    if (mh->size == 0) return -1;
    return mh->heap[0];
}

int main(void) {
    MinHeap mh = {.size = 0};
    int vals[] = {3, 10, 5, 1, 4, 12};
    for (int i = 0; i < 6; i++) insertMin(&mh, vals[i]);

    printf("Min element: %d\n", getMin(&mh)); // 1
    printf("Extracted: %d\n", extractMin(&mh)); // 1
    printf("New Min: %d\n", getMin(&mh)); // 3
    return 0;
}
