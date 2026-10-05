#include <stdio.h>
#include <string.h>

void longestCommonPrefix(const char *strs[], int n, char *out, size_t out_sz) {
    if (n <= 0) {
        out[0] = '\0';
        return;
    }
    strncpy(out, strs[0], out_sz - 1);

    for (int i = 1; i < n; i++) {
        int j = 0;
        while (out[j] && strs[i][j] && out[j] == strs[i][j]) {
            j++;
        }
        out[j] = '\0';
        if (out[0] == '\0') break;
    }
}

int main(void) {
    const char *strs[] = {"flower", "flow", "flight"};
    char lcp[64];
    longestCommonPrefix(strs, 3, lcp, sizeof(lcp));
    printf("Longest common prefix: %s\n", lcp);
    return 0;
}
