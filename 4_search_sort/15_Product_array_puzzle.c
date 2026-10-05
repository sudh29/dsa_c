#include <stdio.h>
#include <stdlib.h>

void productExceptSelf(const long long nums[], int n, long long res[]) {
    for (int i = 0; i < n; i++) res[i] = 1;
    long long left = 1;
    for (int i = 0; i < n; i++) {
        res[i] = left;
        left *= nums[i];
    }
    long long right = 1;
    for (int i = n - 1; i >= 0; i--) {
        res[i] *= right;
        right *= nums[i];
    }
}

int main(void) {
    long long nums[] = {10, 3, 5, 6, 2};
    int n = sizeof(nums) / sizeof(nums[0]);
    long long res[n];
    productExceptSelf(nums, n, res);
    printf("Product except self: ");
    for (int i = 0; i < n; i++) printf("%lld ", res[i]);
    printf("\n");
    return 0;
}
