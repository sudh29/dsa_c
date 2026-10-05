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

void inorder(Node* root, int nodes[], int *count) {
    if (!root) return;
    inorder(root->left, nodes, count);
    nodes[(*count)++] = root->data;
    inorder(root->right, nodes, count);
}

void BSTToMinHeap(Node* root, const int nodes[], int *idx) {
    if (!root) return;
    root->data = nodes[(*idx)++];
    BSTToMinHeap(root->left, nodes, idx);
    BSTToMinHeap(root->right, nodes, idx);
}

void preorder(Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main(void) {
    Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    int nodes[100];
    int count = 0;
    inorder(root, nodes, &count);
    int idx = 0;
    BSTToMinHeap(root, nodes, &idx);

    printf("BST converted to Min Heap (Preorder): ");
    preorder(root);
    printf("\n");
    freeTree(root);
    return 0;
}
