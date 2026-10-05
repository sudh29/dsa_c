#include <stdio.h>
#include <string.h>
#include <limits.h>

static inline int min(int a, int b) { return a < b ? a : b; }

int findSubString(const char *str) {
    int n = (int)strlen(str);
    int dist_count = 0;
    int visited[256] = {0};
    for (int i = 0; i < n; i++) {
        if (!visited[(unsigned char)str[i]]) {
            visited[(unsigned char)str[i]] = 1;
            dist_count++;
        }
    }

    int start = 0, min_len = INT_MAX, count = 0;
    int curr_count[256] = {0};

    for (int j = 0; j < n; j++) {
        curr_count[(unsigned char)str[j]]++;
        if (curr_count[(unsigned char)str[j]] == 1) count++;

        if (count == dist_count) {
            while (curr_count[(unsigned char)str[start]] > 1) {
                curr_count[(unsigned char)str[start]]--;
                start++;
            }
            min_len = min(min_len, j - start + 1);
        }
    }
    return min_len;
}

int main(void) {
    const char *s = "aabcbcdbca";
    printf("Smallest distinct window length: %d\n", findSubString(s));
    return 0;
}
