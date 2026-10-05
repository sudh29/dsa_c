#include <stdio.h>
#include <string.h>

void expand(const char *s, int n, int l, int r, int *start, int *max_len) {
    while (l >= 0 && r < n && s[l] == s[r]) {
        int len = r - l + 1;
        if (len > *max_len) {
            *max_len = len;
            *start = l;
        }
        l--;
        r++;
    }
}

void longestPalindrome(const char *s, char *out) {
    int n = strlen(s);
    if (n <= 1) {
        strcpy(out, s);
        return;
    }

    int start = 0, max_len = 1;
    for (int i = 0; i < n; i++) {
        expand(s, n, i, i, &start, &max_len);
        expand(s, n, i, i + 1, &start, &max_len);
    }

    snprintf(out, max_len + 1, "%.*s", max_len, s + start);
}

int main(void) {
    const char *s = "babad";
    char out[50];
    longestPalindrome(s, out);
    printf("Longest palindromic substring of 'babad': %s\n", out);
    return 0;
}
