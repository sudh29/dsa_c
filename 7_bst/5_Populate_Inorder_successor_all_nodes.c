#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;
} Node;

static Node* newNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = val;
    n->left = n->right = n->next = NULL;
    return n;
}

static void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void populateNextUtil(Node* root, Node** nextPtr) {
    if (!root) return;
    populateNextUtil(root->right, nextPtr);
    root->next = *nextPtr;
    *nextPtr = root;
    populateNextUtil(root->left, nextPtr);
}

void populateNext(Node* root) {
    Node* nextPtr = NULL;
    populateNextUtil(root, &nextPtr);
}

int main(void) {
    Node* root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(12);
    root->left->left = newNode(3);

    populateNext(root);
    printf("Inorder successor of 8: %d\n", root->left->next ? root->left->next->data : -1);
    freeTree(root);
    return 0;
}
