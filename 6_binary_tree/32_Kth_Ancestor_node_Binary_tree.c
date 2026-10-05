#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

static Node* newNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

static void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

bool findPath(Node* root, int target, int path[], int *pathLen) {
    if (!root) return false;
    path[*pathLen] = root->data;
    (*pathLen)++;
    if (root->data == target) return true;
    if (findPath(root->left, target, path, pathLen) || findPath(root->right, target, path, pathLen)) return true;
    (*pathLen)--;
    return false;
}

int kthAncestor(Node *root, int k, int node) {
    int path[100];
    int pathLen = 0;
    if (!findPath(root, node, path, &pathLen)) return -1;
    int idx = pathLen - 1 - k;
    return (idx >= 0) ? path[idx] : -1;
}

int main(void) {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("2nd ancestor of 4: %d\n", kthAncestor(root, 2, 4));
    freeTree(root);
    return 0;
}
