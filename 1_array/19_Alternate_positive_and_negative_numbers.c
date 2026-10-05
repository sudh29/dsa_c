#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void rearrange(int arr[], int n) {
    int *pos = (int*)malloc(n * sizeof(int));
    int *neg = (int*)malloc(n * sizeof(int));
    if (!pos || !neg) return;
    int p_count = 0, n_count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) pos[p_count++] = arr[i];
        else neg[n_count++] = arr[i];
    }

    int i = 0, p = 0, q = 0;
    while (p < p_count && q < n_count) {
        arr[i++] = pos[p++];
        arr[i++] = neg[q++];
    }
    while (p < p_count) arr[i++] = pos[p++];
    while (q < n_count) arr[i++] = neg[q++];

    free(pos);
    free(neg);
}

int main(void) {
    int arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrange(arr, n);
    printf("Alternating pos/neg: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    assert(arr[0] == 9 && arr[1] == -2 && arr[2] == 4 && arr[3] == -1);
    return 0;
}
