#include <stdio.h>
#include <string.h>

static void computeLPS(const char *pat, int M, int *lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int minChar(const char *str) {
    int n = (int)strlen(str);
    char concat[2 * n + 2];
    int idx = 0;

    for (int i = 0; i < n; i++) concat[idx++] = str[i];
    concat[idx++] = '$';
    for (int i = n - 1; i >= 0; i--) concat[idx++] = str[i];
    concat[idx] = '\0';

    int lps[2 * n + 2];
    computeLPS(concat, idx, lps);
    return n - lps[idx - 1];
}

int main(void) {
    const char *s = "AACECAAAA";
    printf("Min chars added to front to make palindrome: %d\n", minChar(s));
    return 0;
}
