#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TrieNode {
    struct TrieNode* children[2];
    bool isLeaf;
} TrieNode;

static TrieNode* newTrieNode(void) {
    TrieNode* n = (TrieNode*)malloc(sizeof(TrieNode));
    n->isLeaf = false;
    n->children[0] = n->children[1] = NULL;
    return n;
}

static void freeTrie(TrieNode* root) {
    if (!root) return;
    if (root->children[0]) freeTrie(root->children[0]);
    if (root->children[1]) freeTrie(root->children[1]);
    free(root);
}

bool insertRow(TrieNode* root, const int row[], int col) {
    TrieNode* cur = root;
    for (int i = 0; i < col; i++) {
        int bit = row[i];
        if (!cur->children[bit]) cur->children[bit] = newTrieNode();
        cur = cur->children[bit];
    }
    if (cur->isLeaf) return false;
    cur->isLeaf = true;
    return true;
}

int uniqueRows(int rows, int cols, const int M[][4], int unique[][4]) {
    TrieNode* root = newTrieNode();
    int count = 0;

    for (int i = 0; i < rows; i++) {
        if (insertRow(root, M[i], cols)) {
            for (int j = 0; j < cols; j++) {
                unique[count][j] = M[i][j];
            }
            count++;
        }
    }
    freeTrie(root);
    return count;
}

int main(void) {
    int mat[3][4] = {
        {1, 1, 0, 1},
        {1, 0, 0, 1},
        {1, 1, 0, 1}
    };
    int unique[3][4];
    int count = uniqueRows(3, 4, mat, unique);
    printf("Unique rows count: %d\n", count); // 2
    if (count != 2) return 1;
    return 0;
}
