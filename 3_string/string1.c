#include <stdio.h>
#include <string.h>

int naivePatternSearch(const char *text, const char *pattern) {
    int n = (int)strlen(text);
    int m = (int)strlen(pattern);
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) break;
        }
        if (j == m) return i;
    }
    return -1;
}

int main(void) {
    const char *text = "aaaaaabc";
    const char *p1 = "abc", *p2 = "xyz";
    printf("Pattern '%s' in '%s': index %d\n", p1, text, naivePatternSearch(text, p1));
    printf("Pattern '%s' in '%s': index %d\n", p2, text, naivePatternSearch(text, p2));
    return 0;
}
