#include <stdio.h>
#include <string.h>

void firstRepeat(const char *str, char *out, size_t out_sz) {
    char copy[512];
    strncpy(copy, str, sizeof(copy) - 1);
    copy[sizeof(copy) - 1] = '\0';

    char words[64][64];
    int count = 0;

    char *tok = strtok(copy, " ");
    while (tok) {
        for (int i = 0; i < count; i++) {
            if (strcmp(words[i], tok) == 0) {
                strncpy(out, tok, out_sz - 1);
                return;
            }
        }
        strncpy(words[count++], tok, 63);
        tok = strtok(NULL, " ");
    }
    out[0] = '\0';
}

int main(void) {
    const char *str = "Ravi had been saying that he would like to visit the alpine resort but Ravi forgot";
    char repeated[64];
    firstRepeat(str, repeated, sizeof(repeated));
    printf("First repeated word: %s\n", repeated);
    return 0;
}
