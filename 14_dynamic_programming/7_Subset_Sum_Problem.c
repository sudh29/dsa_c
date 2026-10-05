#include <stdio.h>
#include <stdbool.h>

bool equalPartition(int N, const int arr[]) {
    long long total = 0;
    for (int i = 0; i < N; i++) total += arr[i];
    if (total % 2 != 0) return false;

    int target = total / 2;
    bool dp[500] = {false};
    dp[0] = true;

    for (int i = 0; i < N; i++) {
        int num = arr[i];
        for (int j = target; j >= num; j--) {
            if (dp[j - num]) dp[j] = true;
        }
    }
    return dp[target];
}

int main(void) {
    int arr[] = {1, 5, 11, 5};
    printf("Can partition {1, 5, 11, 5}: %s\n", equalPartition(4, arr) ? "YES" : "NO");
    return 0;
}
