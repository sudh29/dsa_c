#include <stdio.h>
#include <string.h>

static inline int max(int a, int b) { return a > b ? a : b; }

void boyerMooreSearch(const char *txt, const char *pat) {
    int m = (int)strlen(pat);
    int n = (int)strlen(txt);

    int badchar[256];
    for (int i = 0; i < 256; i++) badchar[i] = -1;
    for (int i = 0; i < m; i++) badchar[(unsigned char)pat[i]] = i;

    int s = 0;
    printf("Boyer-Moore matches at: ");
    while (s <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && pat[j] == txt[s + j]) j--;
        if (j < 0) {
            printf("%d ", s);
            s += (s + m < n) ? m - badchar[(unsigned char)txt[s + m]] : 1;
        } else {
            s += max(1, j - badchar[(unsigned char)txt[s + j]]);
        }
    }
    printf("\n");
}

int main(void) {
    const char *txt = "ABAAABCD";
    const char *pat = "ABC";
    boyerMooreSearch(txt, pat);
    return 0;
}
