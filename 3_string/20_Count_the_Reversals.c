#include <stdio.h>
#include <string.h>

int countRev(const char *s) {
    int n = (int)strlen(s);
    if (n % 2 != 0) return -1;

    int open = 0, close = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '{') {
            open++;
        } else {
            if (open > 0) open--;
            else close++;
        }
    }
    return (open + 1) / 2 + (close + 1) / 2;
}

int main(void) {
    const char *s = "}{{}}{{{";
    printf("Reversals needed for %s: %d\n", s, countRev(s));
    return 0;
}
