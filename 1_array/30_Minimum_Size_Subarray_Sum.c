#include <stdio.h>
#include <limits.h>
#include <assert.h>

static inline int min(int a, int b) { return a < b ? a : b; }

int minSubArrayLen(int target, const int *nums, int n) {
    int left = 0;
    int sum = 0, min_len = INT_MAX;
    for (int right = 0; right < n; right++) {
        sum += nums[right];
        while (sum >= target) {
            min_len = min(min_len, right - left + 1);
            sum -= nums[left++];
        }
    }
    return (min_len == INT_MAX) ? 0 : min_len;
}

int main(void) {
    int nums[] = {2, 3, 1, 2, 4, 3};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 7;
    int ans = minSubArrayLen(target, nums, n);
    printf("Min subarray length for target %d: %d\n", target, ans);
    assert(ans == 2);
    return 0;
}
