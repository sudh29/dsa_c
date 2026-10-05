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

void inorder(Node* root, int v[], int *count) {
    if (!root) return;
    inorder(root->left, v, count);
    v[(*count)++] = root->data;
    inorder(root->right, v, count);
}

float findMedian(Node *root) {
    int v[100];
    int n = 0;
    inorder(root, v, &n);
    if (n == 0) return 0.0f;
    if (n % 2 != 0) return (float)v[n / 2];
    return (float)(v[(n / 2) - 1] + v[n / 2]) / 2.0f;
}

int main(void) {
    Node* root = newNode(6);
    root->left = newNode(3);
    root->right = newNode(8);
    root->left->left = newNode(1);
    root->left->right = newNode(4);

    printf("Median of BST: %g\n", (double)findMedian(root));
    freeTree(root);
    return 0;
}
