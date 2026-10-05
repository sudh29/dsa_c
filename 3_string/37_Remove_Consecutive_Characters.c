#include <stdio.h>
#include <string.h>

void removeConsecutiveCharacter(const char *S, char *out, size_t out_sz) {
    int idx = 0;
    for (int i = 0; S[i]; i++) {
        if (i == 0 || S[i] != S[i - 1]) {
            if ((size_t)idx + 1 < out_sz) {
                out[idx++] = S[i];
            }
        }
    }
    out[idx] = '\0';
}

int main(void) {
    const char *s = "aabaa";
    char res[32];
    removeConsecutiveCharacter(s, res, sizeof(res));
    printf("Removed consecutive characters from %s: %s\n", s, res);
    return 0;
}
