#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reorganizeString(const char *s, char *res) {
    int n = strlen(s);
    int freq[26] = {0};
    int maxFreq = 0, letter = 0;

    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
        if (freq[s[i] - 'a'] > maxFreq) {
            maxFreq = freq[s[i] - 'a'];
            letter = s[i] - 'a';
        }
    }

    if (maxFreq > (n + 1) / 2) {
        res[0] = '\0';
        return res;
    }

    for (int i = 0; i < n; i++) res[i] = 0;
    res[n] = '\0';

    int idx = 0;
    while (freq[letter] > 0) {
        res[idx] = (char)('a' + letter);
        idx += 2;
        freq[letter]--;
    }

    for (int i = 0; i < 26; i++) {
        while (freq[i] > 0) {
            if (idx >= n) idx = 1;
            res[idx] = (char)('a' + i);
            idx += 2;
            freq[i]--;
        }
    }
    return res;
}

int main(void) {
    char buf1[32], buf2[32];
    printf("Reorganized 'aab': %s\n", reorganizeString("aab", buf1));
    printf("Reorganized 'aaab': '%s'\n", reorganizeString("aaab", buf2));
    return 0;
}
