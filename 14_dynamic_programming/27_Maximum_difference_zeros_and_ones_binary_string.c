#include <stdio.h>

static int max(int a, int b) { return a > b ? a : b; }

int maxSubstring(const char *S) {
    int max_diff = -1;
    int curr = 0;

    for (int i = 0; S[i] != '\0'; i++) {
        int val = (S[i] == '0') ? 1 : -1;
        curr += val;
        max_diff = max(max_diff, curr);
        if (curr < 0) curr = 0;
    }
    return max_diff > 0 ? max_diff : -1;
}

int main(void) {
    const char *s = "11000010001";
    printf("Max difference zeros and ones: %d (expected 6)\n", maxSubstring(s));
    return 0;
}
