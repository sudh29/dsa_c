#include <stdio.h>
#include <stdbool.h>

#define MAX_CAP 100

typedef struct {
    int heap[MAX_CAP];
    int size;
} MaxHeap;

static void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

static void heapifyUp(MaxHeap *mh, int i) {
    while (i > 0 && mh->heap[(i - 1) / 2] < mh->heap[i]) {
        swap(&mh->heap[(i - 1) / 2], &mh->heap[i]);
        i = (i - 1) / 2;
    }
}

static void heapifyDown(MaxHeap *mh, int i) {
    int n = mh->size;
    while (2 * i + 1 < n) {
        int left = 2 * i + 1, right = 2 * i + 2, largest = i;
        if (left < n && mh->heap[left] > mh->heap[largest]) largest = left;
        if (right < n && mh->heap[right] > mh->heap[largest]) largest = right;
        if (largest == i) break;
        swap(&mh->heap[i], &mh->heap[largest]);
        i = largest;
    }
}

void insertMax(MaxHeap *mh, int val) {
    if (mh->size >= MAX_CAP) return;
    mh->heap[mh->size++] = val;
    heapifyUp(mh, mh->size - 1);
}

int extractMax(MaxHeap *mh) {
    if (mh->size == 0) return -1;
    int maxVal = mh->heap[0];
    mh->heap[0] = mh->heap[--mh->size];
    heapifyDown(mh, 0);
    return maxVal;
}

int getMax(const MaxHeap *mh) {
    if (mh->size == 0) return -1;
    return mh->heap[0];
}

int main(void) {
    MaxHeap mh = {.size = 0};
    int vals[] = {3, 10, 5, 1, 4, 12};
    for (int i = 0; i < 6; i++) insertMax(&mh, vals[i]);

    printf("Max element: %d\n", getMax(&mh)); // 12
    printf("Extracted: %d\n", extractMax(&mh)); // 12
    printf("New Max: %d\n", getMax(&mh)); // 10
    return 0;
}
