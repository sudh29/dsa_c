#include <stdio.h>
#include <string.h>

void rearrangeString(const char *str, char *res) {
    int n = strlen(str);
    int freq[26] = {0};
    int maxFreq = 0, letter = 0;

    for (int i = 0; i < n; i++) {
        freq[str[i] - 'a']++;
        if (freq[str[i] - 'a'] > maxFreq) {
            maxFreq = freq[str[i] - 'a'];
            letter = str[i] - 'a';
        }
    }

    if (maxFreq > (n + 1) / 2) {
        strcpy(res, "-1");
        return;
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
}

int main(void) {
    char buf[64];
    rearrangeString("geeksforgeeks", buf);
    printf("Rearrange 'geeksforgeeks': %s\n", buf);
    return 0;
}
