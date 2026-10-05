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

bool search(Node* root, int x) {
    if (!root) return false;
    if (root->data == x) return true;
    if (x < root->data) return search(root->left, x);
    return search(root->right, x);
}

int main(void) {
    Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    printf("Search 3 in BST: %s\n", search(root, 3) ? "Found" : "Not Found");
    printf("Search 5 in BST: %s\n", search(root, 5) ? "Found" : "Not Found");
    freeTree(root);
    return 0;
}
