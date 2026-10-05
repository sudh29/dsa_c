#include <stdio.h>
#include <stdlib.h>

static int max(int a, int b) { return a > b ? a : b; }

int longestSubseq(int n, const int a[]) {
    int dp[100];
    for (int i = 0; i < n; i++) dp[i] = 1;
    int max_len = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (abs(a[i] - a[j]) == 1) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_len = max(max_len, dp[i]);
    }
    return max_len;
}

int main(void) {
    int a[] = {10, 9, 4, 5, 4, 8, 6};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Longest subsequence diff 1: %d (expected 3)\n", longestSubseq(n, a));
    return 0;
}
