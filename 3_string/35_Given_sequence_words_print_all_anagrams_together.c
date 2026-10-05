#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int cmp_char(const void *a, const void *b) {
    return (*(const char*)a - *(const char*)b);
}

typedef struct {
    char sorted[64];
    char original[64];
} WordPair;

static int cmp_words(const void *a, const void *b) {
    const WordPair *wa = (const WordPair*)a;
    const WordPair *wb = (const WordPair*)b;
    return strcmp(wa->sorted, wb->sorted);
}

void printAnagramsTogether(const char *words[], int n) {
    WordPair *pairs = (WordPair*)malloc(n * sizeof(WordPair));
    if (!pairs) return;

    for (int i = 0; i < n; i++) {
        strncpy(pairs[i].original, words[i], 63);
        strncpy(pairs[i].sorted, words[i], 63);
        qsort(pairs[i].sorted, strlen(pairs[i].sorted), sizeof(char), cmp_char);
    }

    qsort(pairs, n, sizeof(WordPair), cmp_words);

    printf("Anagram groups:\n");
    int i = 0;
    while (i < n) {
        printf("[ ");
        printf("%s ", pairs[i].original);
        int j = i + 1;
        while (j < n && strcmp(pairs[i].sorted, pairs[j].sorted) == 0) {
            printf("%s ", pairs[j].original);
            j++;
        }
        printf("] ");
        i = j;
    }
    printf("\n");
    free(pairs);
}

int main(void) {
    const char *words[] = {"act", "god", "cat", "dog", "tac"};
    int n = sizeof(words) / sizeof(words[0]);
    printAnagramsTogether(words, n);
    return 0;
}
