#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TrieNode {
    struct TrieNode* children[26];
    bool isEndOfWord;
} TrieNode;

static TrieNode* newTrieNode(void) {
    TrieNode* n = (TrieNode*)malloc(sizeof(TrieNode));
    n->isEndOfWord = false;
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

void insert(TrieNode* root, const char *key) {
    TrieNode* cur = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int idx = key[i] - 'a';
        if (!cur->children[idx]) cur->children[idx] = newTrieNode();
        cur = cur->children[idx];
    }
    cur->isEndOfWord = true;
}

bool search(TrieNode* root, const char *key) {
    TrieNode* cur = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int idx = key[i] - 'a';
        if (!cur->children[idx]) return false;
        cur = cur->children[idx];
    }
    return (cur != NULL && cur->isEndOfWord);
}

int main(void) {
    TrieNode* trie = newTrieNode();
    insert(trie, "the");
    insert(trie, "there");
    insert(trie, "any");

    printf("Search 'the': %s\n", search(trie, "the") ? "Found" : "Not Found");
    printf("Search 'these': %s\n", search(trie, "these") ? "Found" : "Not Found");
    freeTrie(trie);
    return 0;
}
