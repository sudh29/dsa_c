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

Node* lca(Node* root, int a, int b) {
    if (!root || root->data == a || root->data == b) return root;
    Node* left = lca(root->left, a, b);
    Node* right = lca(root->right, a, b);
    if (left && right) return root;
    return left ? left : right;
}

int distFromLCA(Node* root, int val, int d) {
    if (!root) return -1;
    if (root->data == val) return d;
    int left = distFromLCA(root->left, val, d + 1);
    if (left != -1) return left;
    return distFromLCA(root->right, val, d + 1);
}

int findDist(Node* root, int a, int b) {
    Node* lcaNode = lca(root, a, b);
    return distFromLCA(lcaNode, a, 0) + distFromLCA(lcaNode, b, 0);
}

int main(void) {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Distance between 4 and 5: %d\n", findDist(root, 4, 5));
    freeTree(root);
    return 0;
}
