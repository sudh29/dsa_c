#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static int compareChars(const void *a, const void *b) {
    return (*(const char*)a - *(const char*)b);
}

typedef struct {
    char word[32];
    char key[32];
} WordKey;

void printAnagramsTogether(const char *words[], int n) {
    WordKey items[50];
    for (int i = 0; i < n; i++) {
        snprintf(items[i].word, sizeof(items[i].word), "%s", words[i]);
        snprintf(items[i].key, sizeof(items[i].key), "%s", words[i]);
        qsort(items[i].key, strlen(items[i].key), sizeof(char), compareChars);
    }

    bool visited[50] = {false};
    printf("Anagram groups:\n");
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        printf("[ %s ", items[i].word);
        visited[i] = true;
        for (int j = i + 1; j < n; j++) {
            if (!visited[j] && strcmp(items[i].key, items[j].key) == 0) {
                printf("%s ", items[j].word);
                visited[j] = true;
            }
        }
        printf("] ");
    }
    printf("\n");
}

int main(void) {
    const char *words[] = {"act", "god", "cat", "dog", "tac"};
    printAnagramsTogether(words, 5);
    return 0;
}
