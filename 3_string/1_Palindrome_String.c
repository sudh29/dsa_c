#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(const char *S) {
    int i = 0, j = (int)strlen(S) - 1;
    while (i < j) {
        if (S[i++] != S[j--]) return false;
    }
    return true;
}

int main(void) {
    const char *s = "racecar";
    printf("%s is palindrome: %s\n", s, isPalindrome(s) ? "Yes" : "No");
    return 0;
}
