#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static bool isValid(const char *s) {
    int count = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') count++;
        else if (s[i] == ')') {
            count--;
            if (count < 0) return false;
        }
    }
    return count == 0;
}

int main(void) {
    const char *s = "()())()";
    printf("Valid expressions for '%s':\n", s);

    // Demonstration of valid balanced substrings with 1 removal
    char buf[32];
    int len = (int)strlen(s);
    char seen[16][32];
    int seen_count = 0;

    for (int i = 0; i < len; i++) {
        if (s[i] != '(' && s[i] != ')') continue;
        int idx = 0;
        for (int j = 0; j < len; j++) {
            if (j == i) continue;
            buf[idx++] = s[j];
        }
        buf[idx] = '\0';
        if (isValid(buf)) {
            int dup = 0;
            for (int k = 0; k < seen_count; k++) {
                if (strcmp(seen[k], buf) == 0) {
                    dup = 1;
                    break;
                }
            }
            if (!dup) {
                snprintf(seen[seen_count++], sizeof(seen[0]), "%s", buf);
                printf("  %s\n", buf);
            }
        }
    }
    return 0;
}
