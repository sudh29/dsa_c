#include <stdio.h>
#include <string.h>

static void allCombinationStr(const char *set[], int n, char prefix[], int depth, int k) {
    if (depth == k) {
        prefix[k] = '\0';
        printf("%s ", prefix);
        return;
    }
    for (int i = 0; i < n; i++) {
        prefix[depth] = set[i][0];
        allCombinationStr(set, n, prefix, depth + 1, k);
    }
}

int main(void) {
    printf("First Test:\n");
    const char *set1[] = {"1", "2", "3"};
    char buf1[16];
    allCombinationStr(set1, 3, buf1, 0, 2);
    printf("\n\nSecond Test:\n");

    const char *set2[] = {"a", "b", "c"};
    char buf2[16];
    allCombinationStr(set2, 3, buf2, 0, 2);
    printf("\n");
    return 0;
}
