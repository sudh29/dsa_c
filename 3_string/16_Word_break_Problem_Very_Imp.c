#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool wordBreak(const char *A, const char *B[], int dict_size) {
    int n = (int)strlen(A);
    bool dp[n + 1];
    for (int i = 0; i <= n; i++) dp[i] = false;
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (!dp[j]) continue;
            int word_len = i - j;
            for (int k = 0; k < dict_size; k++) {
                if ((int)strlen(B[k]) == word_len && strncmp(A + j, B[k], word_len) == 0) {
                    dp[i] = true;
                    break;
                }
            }
            if (dp[i]) break;
        }
    }
    return dp[n];
}

int main(void) {
    const char *s = "ilike";
    const char *dict[] = {"i", "like", "sam", "sung"};
    int dict_sz = sizeof(dict) / sizeof(dict[0]);
    printf("Can break '%s': %d\n", s, wordBreak(s, dict, dict_sz));
    return 0;
}
