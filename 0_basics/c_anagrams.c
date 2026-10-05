#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool are_anagrams(const char *s1, const char *s2) {
    if (!s1 || !s2) return false;
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    if (len1 != len2) return false;

    int count[256] = {0};
    for (size_t i = 0; i < len1; i++) {
        count[(unsigned char)s1[i]]++;
    }
    for (size_t i = 0; i < len2; i++) {
        if (--count[(unsigned char)s2[i]] < 0) return false;
    }
    return true;
}

int main(void) {
    printf("=== Anagram Checker in Pure C ===\n");
    const char *s1 = "listen", *s2 = "silent";
    const char *s3 = "hello", *s4 = "world";

    printf("%s & %s: %s\n", s1, s2, are_anagrams(s1, s2) ? "ANAGRAM" : "NOT anagram");
    printf("%s & %s: %s\n", s3, s4, are_anagrams(s3, s4) ? "ANAGRAM" : "NOT anagram");
    return 0;
}
