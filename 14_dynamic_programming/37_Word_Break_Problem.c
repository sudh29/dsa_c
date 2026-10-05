#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool wordBreak(const char *s, const char *dictionary[], int numWords) {
    int n = strlen(s);
    bool dp[100] = {false};
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j]) {
                int len = i - j;
                for (int w = 0; w < numWords; w++) {
                    if ((int)strlen(dictionary[w]) == len && strncmp(s + j, dictionary[w], len) == 0) {
                        dp[i] = true;
                        break;
                    }
                }
                if (dp[i]) break;
            }
        }
    }
    return dp[n];
}

int main(void) {
    const char *dict[] = {"apple", "pen", "applepen", "pine", "pineapple"};
    const char *s = "pineapplepenapple";
    printf("Can break 'pineapplepenapple': %s\n", wordBreak(s, dict, 5) ? "YES" : "NO");
    return 0;
}
