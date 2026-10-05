#include <stdio.h>

int findDuplicate(const int *nums) {
    int slow = nums[0];
    int fast = nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    fast = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main(void) {
    int nums[] = {1, 3, 4, 2, 2};
    printf("Duplicate number: %d\n", findDuplicate(nums));
    return 0;
}
