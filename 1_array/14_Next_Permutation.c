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

void nextPermutation(int *nums, int n) {
    int i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) i--;
    if (i >= 0) {
        int j = n - 1;
        while (nums[j] <= nums[i]) j--;
        swap(&nums[i], &nums[j]);
    }
    reverse(nums, i + 1, n - 1);
}

int main(void) {
    int nums[] = {1, 2, 3};
    int n = sizeof(nums) / sizeof(nums[0]);
    nextPermutation(nums, n);
    printf("Next permutation: ");
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);
    printf("\n");
    return 0;
}
