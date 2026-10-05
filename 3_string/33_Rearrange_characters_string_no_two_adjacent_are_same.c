#include <stdio.h>
#include <string.h>

void rearrangeString(const char *str, char *out, size_t out_sz) {
    int n = (int)strlen(str);
    int count[26] = {0};
    int max_freq = 0;
    char max_char = 'a';

    for (int i = 0; i < n; i++) {
        int idx = str[i] - 'a';
        count[idx]++;
        if (count[idx] > max_freq) {
            max_freq = count[idx];
            max_char = str[i];
        }
    }

    if (max_freq > (n + 1) / 2) {
        out[0] = '\0';
        return;
    }

    out[n] = '\0';
    int ind = 0;

    while (max_freq--) {
        out[ind] = max_char;
        ind += 2;
    }
    count[max_char - 'a'] = 0;

    for (int i = 0; i < 26; i++) {
        while (count[i] > 0) {
            ind = (ind >= n) ? 1 : ind;
            out[ind] = (char)('a' + i);
            ind += 2;
            count[i]--;
        }
    }
    (void)out_sz;
}

int main(void) {
    const char *s = "aaabc";
    char res[32];
    rearrangeString(s, res, sizeof(res));
    printf("Rearranged '%s': %s\n", s, res[0] ? res : "Not possible");
    return 0;
}
