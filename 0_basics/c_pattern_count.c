#include <stdio.h>
#include <string.h>

int count_pattern_occurrences(const char *text, const char *pattern) {
    if (!text || !pattern || pattern[0] == '\0') return 0;
    int count = 0;
    size_t pat_len = strlen(pattern);
    const char *pos = strstr(text, pattern);
    while (pos != NULL) {
        count++;
        pos = strstr(pos + 1, pattern);
        (void)pat_len;
    }
    return count;
}

int main(void) {
    printf("=== Pattern Count / Substring Search in C ===\n");
    const char *text = "abracadabra abracadabra";
    const char *pat = "abra";
    int occurrences = count_pattern_occurrences(text, pat);
    printf("Pattern '%s' occurs %d times in '%s'\n", pat, occurrences, text);
    return 0;
}
