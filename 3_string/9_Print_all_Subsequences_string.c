#include <stdio.h>
#include <string.h>

void generateSubsequences(const char *s, int idx, char *current, int cur_len) {
    if (s[idx] == '\0') {
        current[cur_len] = '\0';
        printf("%s ", current);
        return;
    }
    // Include
    current[cur_len] = s[idx];
    generateSubsequences(s, idx + 1, current, cur_len + 1);
    // Exclude
    generateSubsequences(s, idx + 1, current, cur_len);
}

int main(void) {
    const char *s = "abc";
    char current[32];
    printf("Subsequences of '%s': ", s);
    generateSubsequences(s, 0, current, 0);
    printf("\n");
    return 0;
}
