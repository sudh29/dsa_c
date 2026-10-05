#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int val;
    int idx;
} Pair;

static int comparePairs(const void *a, const void *b) {
    const Pair *p1 = (const Pair *)a;
    const Pair *p2 = (const Pair *)b;
    return p1->val - p2->val;
}

static void inorder(const int a[], int n, int index, int ans[], int *ansIdx) {
    if (index >= n) return;
    inorder(a, n, 2 * index + 1, ans, ansIdx);
    ans[(*ansIdx)++] = a[index];
    inorder(a, n, 2 * index + 2, ans, ansIdx);
}

int minSwaps(int n, const int A[]) {
    int *ans = (int *)malloc(n * sizeof(int));
    int ansIdx = 0;
    inorder(A, n, 0, ans, &ansIdx);

    Pair *v = (Pair *)malloc(n * sizeof(Pair));
    for (int i = 0; i < n; i++) {
        v[i].val = ans[i];
        v[i].idx = i;
    }
    qsort(v, n, sizeof(Pair), comparePairs);

    bool *visited = (bool *)calloc(n, sizeof(bool));
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || v[i].idx == i) continue;
        int cycle_size = 0, j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = v[j].idx;
            cycle_size++;
        }
        if (cycle_size > 1) swaps += (cycle_size - 1);
    }

    free(ans);
    free(v);
    free(visited);
    return swaps;
}

int main(void) {
    int a[] = {5, 6, 7, 8, 9, 10, 11};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Min swaps to convert binary tree to BST: %d\n", minSwaps(n, a));
    return 0;
}
