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

Node* LCA(Node* root, int n1, int n2) {
    if (!root) return NULL;
    if (root->data > n1 && root->data > n2) return LCA(root->left, n1, n2);
    if (root->data < n1 && root->data < n2) return LCA(root->right, n1, n2);
    return root;
}

int main(void) {
    Node* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);

    Node* lca = LCA(root, 4, 12);
    printf("LCA of 4 and 12: %d\n", lca ? lca->data : -1);
    freeTree(root);
    return 0;
}
