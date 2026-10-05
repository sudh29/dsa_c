#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct TrieNode {
    struct TrieNode* children[26];
    bool isLeaf;
} TrieNode;

static TrieNode* newTrieNode(void) {
    TrieNode* n = (TrieNode*)malloc(sizeof(TrieNode));
    n->isLeaf = false;
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
    }
    cur->isLeaf = true;
}

bool search(TrieNode* root, const char *word, int len) {
    TrieNode* cur = root;
    for (int i = 0; i < len; i++) {
        int idx = word[i] - 'a';
        if (!cur->children[idx]) return false;
        cur = cur->children[idx];
    }
    return cur && cur->isLeaf;
}

bool wordBreakHelper(TrieNode* root, const char *s, int start, int sLen, int memo[]) {
    if (start == sLen) return true;
    if (memo[start] != -1) return memo[start];

    for (int end = start + 1; end <= sLen; end++) {
        if (search(root, s + start, end - start) && wordBreakHelper(root, s, end, sLen, memo)) {
            memo[start] = 1;
            return true;
        }
    }
    memo[start] = 0;
    return false;
}

int wordBreak(int n, const char *s, const char *dictionary[]) {
    TrieNode* root = newTrieNode();
    for (int i = 0; i < n; i++) insert(root, dictionary[i]);
    int sLen = strlen(s);
    int memo[100];
    for (int i = 0; i < sLen; i++) memo[i] = -1;
    bool res = wordBreakHelper(root, s, 0, sLen, memo);
    freeTrie(root);
    return res ? 1 : 0;
}

int main(void) {
    const char *dict[] = {"i", "like", "sam", "sung", "samsung", "mobile"};
    int res = wordBreak(6, "ilikesamsung", dict);
    printf("Word break 'ilikesamsung': %d\n", res);
    if (res != 1) return 1;
    return 0;
}
