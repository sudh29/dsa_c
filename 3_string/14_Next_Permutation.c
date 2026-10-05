#include <stdio.h>

static inline void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

static void reverse(int *arr, int start, int end) {
    while (start < end) {
        swap(&arr[start++], &arr[end--]);
    }
}

void nextPermutation(int N, int arr[]) {
    int i = N - 2;
    while (i >= 0 && arr[i] >= arr[i + 1]) i--;
    if (i >= 0) {
        int j = N - 1;
        while (arr[j] <= arr[i]) j--;
        swap(&arr[i], &arr[j]);
    }
    reverse(arr, i + 1, N - 1);
}

int main(void) {
    int arr[] = {1, 2, 3, 6, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    nextPermutation(n, arr);
    printf("Next permutation: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
