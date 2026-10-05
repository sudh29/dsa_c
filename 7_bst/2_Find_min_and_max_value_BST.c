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

int minValue(Node* root) {
    if (!root) return -1;
    Node* cur = root;
    while (cur->left) cur = cur->left;
    return cur->data;
}

int maxValue(Node* root) {
    if (!root) return -1;
    Node* cur = root;
    while (cur->right) cur = cur->right;
    return cur->data;
}

int main(void) {
    Node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(8);
    root->left->left = newNode(1);
    root->right->right = newNode(12);

    printf("Min value: %d | Max value: %d\n", minValue(root), maxValue(root));
    freeTree(root);
    return 0;
}
