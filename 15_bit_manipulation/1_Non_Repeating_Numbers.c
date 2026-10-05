#include <stdio.h>

void singleNumber(const int *nums, int n, int *out_a, int *out_b) {
    int xor_all = 0;
    for (int i = 0; i < n; i++) xor_all ^= nums[i];

    // Find rightmost set bit
    int rightmost = xor_all & (-xor_all);
    int a = 0, b = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] & rightmost) a ^= nums[i];
        else b ^= nums[i];
    }

    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    *out_a = a;
    *out_b = b;
}

int main(void) {
    int nums[] = {1, 2, 3, 2, 1, 4};
    int n = sizeof(nums) / sizeof(nums[0]);
    int a = 0, b = 0;
    singleNumber(nums, n, &a, &b);
    printf("Two non-repeating numbers: %d and %d\n", a, b);
    return 0;
}
