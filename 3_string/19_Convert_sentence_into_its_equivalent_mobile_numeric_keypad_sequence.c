#include <stdio.h>
#include <string.h>

void printSequence(const char *S, char *out, size_t out_sz) {
    const char *keypad[] = {
        "2", "22", "222",
        "3", "33", "333",
        "4", "44", "444",
        "5", "55", "555",
        "6", "66", "666",
        "7", "77", "777", "7777",
        "8", "88", "888",
        "9", "99", "999", "9999"
    };

    int idx = 0;
    out[0] = '\0';
    for (int i = 0; S[i]; i++) {
        if (S[i] == ' ') {
            if ((size_t)idx + 1 < out_sz) {
                out[idx++] = '0';
                out[idx] = '\0';
            }
        } else if (S[i] >= 'A' && S[i] <= 'Z') {
            const char *seq = keypad[S[i] - 'A'];
            idx += snprintf(out + idx, out_sz - idx, "%s", seq);
        }
    }
}

int main(void) {
    char res[256];
    printSequence("HELLO WORLD", res, sizeof(res));
    printf("Keypad sequence for 'HELLO WORLD': %s\n", res);
    return 0;
}
