#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int r;
    int c;
} HeapNode;

static void min_heapify(HeapNode *heap, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].val < heap[smallest].val)
        smallest = left;
    if (right < n && heap[right].val < heap[smallest].val)
        smallest = right;

    if (smallest != i) {
        HeapNode temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        min_heapify(heap, n, smallest);
    }
}

int kthSmallest(int n, const int mat[n][n], int k) {
    HeapNode *heap = (HeapNode*)malloc(n * sizeof(HeapNode));
    if (!heap) return -1;

    for (int i = 0; i < n; i++) {
        heap[i].val = mat[i][0];
        heap[i].r = i;
        heap[i].c = 0;
    }

    for (int i = (n - 1) / 2; i >= 0; i--) {
        min_heapify(heap, n, i);
    }

    int res = -1;
    for (int count = 0; count < k; count++) {
        HeapNode root = heap[0];
        res = root.val;

        if (root.c + 1 < n) {
            heap[0].val = mat[root.r][root.c + 1];
            heap[0].r = root.r;
            heap[0].c = root.c + 1;
        } else {
            heap[0].val = 2147483647; // INT_MAX
        }
        min_heapify(heap, n, 0);
    }
    free(heap);
    return res;
}

int main(void) {
    int mat[4][4] = {
        {16, 28, 60, 64},
        {22, 41, 63, 91},
        {27, 50, 87, 93},
        {36, 78, 87, 94}
    };
    int k = 3;
    printf("%d-th smallest in matrix: %d\n", k, kthSmallest(4, mat, k));
    return 0;
}
