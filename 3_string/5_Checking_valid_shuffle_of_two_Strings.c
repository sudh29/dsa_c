#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool validShuffle(const char *s1, const char *s2, const char *sh) {
    if (strlen(s1) + strlen(s2) != strlen(sh)) return false;
    int count[256] = {0};
    for (int i = 0; s1[i]; i++) count[(unsigned char)s1[i]]++;
    for (int i = 0; s2[i]; i++) count[(unsigned char)s2[i]]++;
    for (int i = 0; sh[i]; i++) count[(unsigned char)sh[i]]--;
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) return false;
    }
    return true;
}

int main(void) {
    const char *s1 = "XY", *s2 = "12", *sh = "1X2Y";
    printf("Valid shuffle: %s\n", validShuffle(s1, s2, sh) ? "Yes" : "No");
    return 0;
}
