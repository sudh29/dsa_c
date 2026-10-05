#include <stdio.h>
#include <stdlib.h>

static int compareDesc(const void *a, const void *b) {
    return (*(const int*)b - *(const int*)a);
}

int kthLargest(int N, int K, const int Arr[]) {
    int totalSums = N * (N + 1) / 2;
    int *sums = (int*)malloc(totalSums * sizeof(int));
    int count = 0;

    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = i; j < N; j++) {
            sum += Arr[j];
            sums[count++] = sum;
        }
    }

    qsort(sums, count, sizeof(int), compareDesc);
    int ans = sums[K - 1];
    free(sums);
    return ans;
}

int main(void) {
    int arr[] = {2, 6, 4, 1};
    printf("3rd largest continuous subarray sum: %d\n", kthLargest(4, 3, arr));
    return 0;
}
