#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int row;
    int col;
} Element;

static void swapElem(Element *a, Element *b) {
    Element t = *a; *a = *b; *b = t;
}

static void minHeapify(Element heap[], int n, int i) {
    int smallest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && heap[l].val < heap[smallest].val) smallest = l;
    if (r < n && heap[r].val < heap[smallest].val) smallest = r;
    if (smallest != i) {
        swapElem(&heap[i], &heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}

void mergeKArrays(const int arr[][3], int K, int N, int res[]) {
    Element heap[10];
    for (int i = 0; i < K; i++) {
        heap[i] = (Element){arr[i][0], i, 0};
    }
    for (int i = K / 2 - 1; i >= 0; i--) {
        minHeapify(heap, K, i);
    }

    int resIdx = 0;
    while (K > 0) {
        Element root = heap[0];
        res[resIdx++] = root.val;

        if (root.col + 1 < N) {
            heap[0] = (Element){arr[root.row][root.col + 1], root.row, root.col + 1};
            minHeapify(heap, K, 0);
        } else {
            heap[0] = heap[K - 1];
            K--;
            if (K > 0) minHeapify(heap, K, 0);
        }
    }
}

int main(void) {
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int res[9];
    mergeKArrays(arr, 3, 3, res);

    printf("Merged K sorted arrays: ");
    for (int i = 0; i < 9; i++) printf("%d ", res[i]);
    printf("\n");
    return 0;
}
