#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 20
#define WORD_LEN 32

typedef struct TrieNode {
    struct TrieNode* children[26];
    char contacts[MAX_WORDS][WORD_LEN];
    int contactCount;
} TrieNode;

static TrieNode* newTrieNode(void) {
    TrieNode* n = (TrieNode*)malloc(sizeof(TrieNode));
    n->contactCount = 0;
    for (int i = 0; i < 26; i++) n->children[i] = NULL;
    return n;
}

static void freeTrie(TrieNode* root) {
    if (!root) return;
    for (int i = 0; i < 26; i++) {
        if (root->children[i]) freeTrie(root->children[i]);
    }
    free(root);
}

void insert(TrieNode* root, const char *word) {
    TrieNode* cur = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int idx = word[i] - 'a';
        if (!cur->children[idx]) cur->children[idx] = newTrieNode();
        cur = cur->children[idx];

        bool exists = false;
        for (int j = 0; j < cur->contactCount; j++) {
            if (strcmp(cur->contacts[j], word) == 0) {
                exists = true;
                break;
            }
        }
        if (!exists && cur->contactCount < MAX_WORDS) {
            snprintf(cur->contacts[cur->contactCount++], WORD_LEN, "%s", word);
        }
    }
}

int main(void) {
    const char *contacts[] = {"geeikistest", "geeksforgeeks", "geeksfortest"};
    int n = 3;
    TrieNode* root = newTrieNode();
    for (int i = 0; i < n; i++) insert(root, contacts[i]);

    const char *s = "gee";
    TrieNode* cur = root;
    for (int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';
        if (cur && cur->children[idx]) cur = cur->children[idx];
        else { cur = NULL; break; }
    }

    printf("Contacts matching prefix 'gee':\n");
    if (cur) {
        for (int i = 0; i < cur->contactCount; i++) {
            printf("  %s\n", cur->contacts[i]);
        }
    }
    freeTrie(root);
    return 0;
}
