#include <stdio.h>
#include <stdlib.h>

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

Node* lca(Node* root, int n1, int n2) {
    if (!root) return NULL;
    if (root->data == n1 || root->data == n2) return root;

    Node* left = lca(root->left, n1, n2);
    Node* right = lca(root->right, n1, n2);

    if (left && right) return root;
    return left ? left : right;
}

int main(void) {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    Node* ans = lca(root, 4, 5);
    printf("LCA of 4 and 5 in Binary Tree: %d\n", ans ? ans->data : -1);
    freeTree(root);
    return 0;
}
