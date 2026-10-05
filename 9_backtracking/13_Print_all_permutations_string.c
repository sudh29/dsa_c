#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline void swap_char(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}

static void permute(char *s, int l, int r) {
    if (l == r) {
        printf("%s ", s);
        return;
    }
    for (int i = l; i <= r; i++) {
        swap_char(&s[l], &s[i]);
        permute(s, l + 1, r);
        swap_char(&s[l], &s[i]);
    }
}

int main(void) {
    char s[] = "ABC";
    int n = (int)strlen(s);
    printf("Permutations of 'ABC': ");
    permute(s, 0, n - 1);
    printf("\n");
    return 0;
}
