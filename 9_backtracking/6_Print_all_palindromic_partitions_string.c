#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static bool isPalindrome(const char *str, int l, int r) {
    while (l < r) {
        if (str[l++] != str[r--]) return false;
    }
    return true;
}

static void allPalindromicPerms(const char *s, int start, int len, char current[][32], int cur_sz) {
    if (start >= len) {
        printf("[ ");
        for (int i = 0; i < cur_sz; i++) {
            printf("%s ", current[i]);
        }
        printf("]\n");
        return;
    }

    for (int i = start; i < len; i++) {
        if (isPalindrome(s, start, i)) {
            int sub_len = i - start + 1;
            strncpy(current[cur_sz], s + start, sub_len);
            current[cur_sz][sub_len] = '\0';
            allPalindromicPerms(s, i + 1, len, current, cur_sz + 1);
        }
    }
}

int main(void) {
    const char *s = "geeks";
    char current[32][32];
    printf("Palindromic partitions of '%s':\n", s);
    allPalindromicPerms(s, 0, (int)strlen(s), current, 0);
    return 0;
}
