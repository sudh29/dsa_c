#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

static int max(int a, int b) { return a > b ? a : b; }

int findMax(Node* root) {
    if (!root) return INT_MIN;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    return max(root->data, max(leftMax, rightMax));
}

int main(void) {
    Node* root = newNode(2);
    root->left = newNode(7);
    root->right = newNode(5);
    root->left->right = newNode(6);
    root->left->right->left = newNode(11);

    printf("Max element in binary tree: %d\n", findMax(root));
    freeTree(root);
    return 0;
}
