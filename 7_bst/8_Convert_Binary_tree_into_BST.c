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

static int compareInts(const void *a, const void *b) {
    return (*(const int*)a - *(const int*)b);
}

void inorderExtract(Node* root, int nodes[], int *count) {
    if (!root) return;
    inorderExtract(root->left, nodes, count);
    nodes[(*count)++] = root->data;
    inorderExtract(root->right, nodes, count);
}

void inorderFill(Node* root, const int nodes[], int *idx) {
    if (!root) return;
    inorderFill(root->left, nodes, idx);
    root->data = nodes[(*idx)++];
    inorderFill(root->right, nodes, idx);
}

Node *binaryTreeToBST(Node *root) {
    int nodes[100];
    int count = 0;
    inorderExtract(root, nodes, &count);
    qsort(nodes, count, sizeof(int), compareInts);
    int idx = 0;
    inorderFill(root, nodes, &idx);
    return root;
}

void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    printf("%d ", root->data);
    inorderPrint(root->right);
}

int main(void) {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    binaryTreeToBST(root);
    printf("Inorder of converted BST: ");
    inorderPrint(root);
    printf("\n");
    freeTree(root);
    return 0;
}
