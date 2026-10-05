#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int val;
    int index;
} Pair;

static int cmp_pair(const void *a, const void *b) {
    const Pair *pa = (const Pair*)a;
    const Pair *pb = (const Pair*)b;
    return (pa->val > pb->val) - (pa->val < pb->val);
}

int minSwaps(const int nums[], int n) {
    Pair *v = (Pair*)malloc(n * sizeof(Pair));
    if (!v) return 0;
    for (int i = 0; i < n; i++) {
        v[i].val = nums[i];
        v[i].index = i;
    }
    qsort(v, n, sizeof(Pair), cmp_pair);

    bool *visited = (bool*)calloc(n, sizeof(bool));
    if (!visited) {
        free(v);
        return 0;
    }
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || v[i].index == i) continue;

        int cycle_size = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = v[j].index;
            cycle_size++;
        }
        if (cycle_size > 1) {
            swaps += (cycle_size - 1);
        }
    }
    free(visited);
    free(v);
    return swaps;
}

int main(void) {
    int nums[] = {2, 8, 5, 4};
    int n = sizeof(nums) / sizeof(nums[0]);
    printf("Min swaps to sort: %d\n", minSwaps(nums, n));
    return 0;
}
