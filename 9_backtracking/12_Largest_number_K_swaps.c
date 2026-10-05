#include <stdio.h>
#include <string.h>

static void findMaxNum(char *str, int k, char *max_str) {
    if (k == 0) return;
    int n = (int)strlen(str);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] < str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;

                if (strcmp(str, max_str) > 0) {
                    strcpy(max_str, str);
                }

                findMaxNum(str, k - 1, max_str);

                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

void findMaximumNum(const char *s, int k, char *out, size_t out_sz) {
    char str[64];
    strncpy(str, s, sizeof(str) - 1);
    str[sizeof(str) - 1] = '\0';

    strncpy(out, s, out_sz - 1);
    out[out_sz - 1] = '\0';

    findMaxNum(str, k, out);
}

int main(void) {
    char res1[64], res2[64];
    findMaximumNum("1234567", 4, res1, sizeof(res1));
    printf("Max num after 4 swaps: %s (expected 7654321)\n", res1);

    findMaximumNum("3435335", 3, res2, sizeof(res2));
    printf("Max num after 3 swaps: %s (expected 5543333)\n", res2);
    return 0;
}
