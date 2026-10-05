#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TrieNode {
    struct TrieNode* children[26];
    int freq;
} TrieNode;

static TrieNode* newTrieNode(void) {
    TrieNode* n = (TrieNode*)malloc(sizeof(TrieNode));
    n->freq = 0;
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
        cur->freq++;
    }
}

void findPrefix(TrieNode* root, const char *word, char *prefix) {
    TrieNode* cur = root;
    int len = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        prefix[len++] = word[i];
        cur = cur->children[word[i] - 'a'];
        if (cur->freq == 1) break;
    }
    prefix[len] = '\0';
}

int main(void) {
    const char *words[] = {"zebra", "dog", "duck", "dove"};
    int n = 4;
    TrieNode* root = newTrieNode();
    for (int i = 0; i < n; i++) insert(root, words[i]);

    printf("Shortest unique prefixes: ");
    char prefix[32];
    for (int i = 0; i < n; i++) {
        findPrefix(root, words[i], prefix);
        printf("%s ", prefix);
    }
    printf("\n");
    freeTrie(root);
    return 0;
}
