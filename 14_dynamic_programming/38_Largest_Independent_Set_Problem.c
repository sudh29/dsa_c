#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int liss;
} Node;

static Node* newNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = val;
    n->liss = 0;
    n->left = n->right = NULL;
    return n;
}

static void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

static int max(int a, int b) { return a > b ? a : b; }

int LISS(Node* root) {
    if (!root) return 0;
    if (root->liss != 0) return root->liss;

    int size_excl = LISS(root->left) + LISS(root->right);

    int size_incl = 1;
    if (root->left) {
        size_incl += LISS(root->left->left) + LISS(root->left->right);
    }
    if (root->right) {
        size_incl += LISS(root->right->left) + LISS(root->right->right);
    }

    root->liss = max(size_incl, size_excl);
    return root->liss;
}

int main(void) {
    Node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);

    printf("Size of Largest Independent Set: %d (expected 5)\n", LISS(root));
    freeTree(root);
    return 0;
}
