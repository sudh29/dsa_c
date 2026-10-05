#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int cmp_str(const void *a, const void *b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

void printPowerSet(const char *s) {
    int n = (int)strlen(s);
    int total = 1 << n;
    char **res = (char**)malloc((total - 1) * sizeof(char*));
    if (!res) return;

    int count = 0;
    for (int i = 1; i < total; i++) {
        char *sub = (char*)malloc((n + 1) * sizeof(char));
        if (!sub) continue;
        int idx = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sub[idx++] = s[j];
            }
        }
        sub[idx] = '\0';
        res[count++] = sub;
    }

    qsort(res, count, sizeof(char*), cmp_str);

    printf("Power set of '%s': ", s);
    for (int i = 0; i < count; i++) {
        printf("%s ", res[i]);
        free(res[i]);
    }
    printf("\n");
    free(res);
}

int main(void) {
    const char *s = "abc";
    printPowerSet(s);
    return 0;
}
