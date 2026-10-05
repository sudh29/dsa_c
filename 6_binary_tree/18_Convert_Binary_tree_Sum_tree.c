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

int toSumTreeUtil(Node* root) {
    if (!root) return 0;
    int oldVal = root->data;
    root->data = toSumTreeUtil(root->left) + toSumTreeUtil(root->right);
    return root->data + oldVal;
}

void toSumTree(Node *node) {
    toSumTreeUtil(node);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(void) {
    Node* root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);

    toSumTree(root);
    printf("Inorder of converted Sum Tree: ");
    inorder(root);
    printf("\n");
    freeTree(root);
    return 0;
}
