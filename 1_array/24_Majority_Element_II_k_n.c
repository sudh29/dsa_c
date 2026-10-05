#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

void majorityElementK(int nums[], int n, int k) {
    qsort(nums, n, sizeof(int), cmp_int);
    int threshold = n / k;

    printf("Elements appearing > n/%d times: ", k);
    int count = 1;
    for (int i = 1; i <= n; i++) {
        if (i < n && nums[i] == nums[i - 1]) {
            count++;
        } else {
            if (count > threshold) {
                printf("%d ", nums[i - 1]);
            }
            count = 1;
        }
    }
    printf("\n");
}

int main(void) {
    int nums[] = {3, 1, 2, 2, 1, 2, 3, 3};
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = 4;
    majorityElementK(nums, n, k);
    return 0;
}
