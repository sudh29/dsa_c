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

void printKPathUtil(Node *root, int path[], int pathLen, int k, int *count) {
    if (!root) return;
    path[pathLen] = root->data;
    pathLen++;

    printKPathUtil(root->left, path, pathLen, k, count);
    printKPathUtil(root->right, path, pathLen, k, count);

    int sum = 0;
    for (int j = pathLen - 1; j >= 0; j--) {
        sum += path[j];
        if (sum == k) (*count)++;
    }
}

int sumK(Node *root, int k) {
    int path[100];
    int count = 0;
    printKPathUtil(root, path, 0, k, &count);
    return count;
}

int main(void) {
    Node* root = newNode(1);
    root->left = newNode(3);
    root->right = newNode(-1);
    root->left->left = newNode(2);
    root->left->right = newNode(1);
    root->left->right->left = newNode(1);

    printf("Paths with sum 5: %d\n", sumK(root, 5));
    freeTree(root);
    return 0;
}
