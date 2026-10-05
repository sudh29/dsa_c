#include <stdio.h>
#include <stdlib.h>

static int cmp_desc(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ib - ia);
}

int minSubset(int Arr[], int N) {
    qsort(Arr, N, sizeof(int), cmp_desc);
    long long total_sum = 0;
    for (int i = 0; i < N; i++) total_sum += Arr[i];

    long long cur_sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        cur_sum += Arr[i];
        count++;
        if (cur_sum > total_sum - cur_sum) {
            return count;
        }
    }
    return count;
}

int main(void) {
    int A[] = {2, 17, 7, 3};
    printf("Min subset size: %d (expected 1)\n", minSubset(A, 4));
    int B[] = {20, 12, 18, 4};
    printf("Min subset size: %d (expected 2)\n", minSubset(B, 4));
    return 0;
}
