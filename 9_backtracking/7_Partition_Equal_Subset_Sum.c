#include <stdio.h>
#include <stdbool.h>

bool equalPartition(int N, const int arr[]) {
    int sum = 0;
    for (int i = 0; i < N; i++) sum += arr[i];
    if (sum % 2 != 0) return false;

    int target = sum / 2;
    bool dp[target + 1];
    for (int i = 0; i <= target; i++) dp[i] = false;
    dp[0] = true;

    for (int i = 0; i < N; i++) {
        for (int j = target; j >= arr[i]; j--) {
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }
    return dp[target];
}

int main(void) {
    int arr1[] = {1, 5, 11, 5};
    printf("Equal partition {1, 5, 11, 5}: %s\n", equalPartition(4, arr1) ? "YES" : "NO");

    int arr2[] = {1, 3, 5};
    printf("Equal partition {1, 3, 5}: %s\n", equalPartition(3, arr2) ? "YES" : "NO");
    return 0;
}
