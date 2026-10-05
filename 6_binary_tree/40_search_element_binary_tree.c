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

bool searchElement(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    return searchElement(root->left, key) || searchElement(root->right, key);
}

int main(void) {
    Node* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);

    printf("Search 20: %s\n", searchElement(root, 20) ? "Found" : "Not Found");
    printf("Search 50: %s\n", searchElement(root, 50) ? "Found" : "Not Found");
    freeTree(root);
    return 0;
}
