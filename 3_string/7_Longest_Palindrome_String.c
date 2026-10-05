#include <stdio.h>
#include <string.h>

static void expandAroundCenter(const char *s, int len, int left, int right, int *best_start, int *max_len) {
    while (left >= 0 && right < len && s[left] == s[right]) {
        int cur_len = right - left + 1;
        if (cur_len > *max_len) {
            *max_len = cur_len;
            *best_start = left;
        }
        left--;
        right++;
    }
}

void longestPalin(const char *S, char *out, size_t out_sz) {
    int len = (int)strlen(S);
    if (len == 0) {
        out[0] = '\0';
        return;
    }
    int best_start = 0, max_len = 1;
    for (int i = 0; i < len; i++) {
        expandAroundCenter(S, len, i, i, &best_start, &max_len);
        expandAroundCenter(S, len, i, i + 1, &best_start, &max_len);
    }
    int copy_len = max_len < (int)out_sz - 1 ? max_len : (int)out_sz - 1;
    strncpy(out, S + best_start, copy_len);
    out[copy_len] = '\0';
}

int main(void) {
    const char *s = "aaaabbaa";
    char res[64];
    longestPalin(s, res, sizeof(res));
    printf("Longest palindrome in %s: %s\n", s, res);
    return 0;
}
