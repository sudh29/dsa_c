#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int index;
} Element;

static int cmp_bits(const void *a, const void *b) {
    const Element *ea = (const Element*)a;
    const Element *eb = (const Element*)b;
    int bits_a = __builtin_popcount(ea->val);
    int bits_b = __builtin_popcount(eb->val);
    if (bits_a != bits_b) {
        return (bits_b - bits_a); // descending order of bits
    }
    return (ea->index - eb->index); // stable tie-breaker
}

void sortBySetBitCount(int arr[], int n) {
    Element *elems = (Element*)malloc(n * sizeof(Element));
    if (!elems) return;
    for (int i = 0; i < n; i++) {
        elems[i].val = arr[i];
        elems[i].index = i;
    }
    qsort(elems, n, sizeof(Element), cmp_bits);
    for (int i = 0; i < n; i++) {
        arr[i] = elems[i].val;
    }
    free(elems);
}

int main(void) {
    int arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
    int n = sizeof(arr) / sizeof(arr[0]);
    sortBySetBitCount(arr, n);
    printf("Sorted by set bit count: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
