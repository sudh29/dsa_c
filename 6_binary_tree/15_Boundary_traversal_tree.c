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

static bool isLeaf(Node* root) {
    return (!root->left && !root->right);
}

static void addLeftBoundary(Node* root) {
    Node* cur = root->left;
    while (cur) {
        if (!isLeaf(cur)) printf("%d ", cur->data);
        if (cur->left) cur = cur->left;
        else cur = cur->right;
    }
}

static void addLeaves(Node* root) {
    if (isLeaf(root)) {
        printf("%d ", root->data);
        return;
    }
    if (root->left) addLeaves(root->left);
    if (root->right) addLeaves(root->right);
}

static void addRightBoundary(Node* root) {
    Node* cur = root->right;
    int temp[100];
    int count = 0;
    while (cur) {
        if (!isLeaf(cur)) temp[count++] = cur->data;
        if (cur->right) cur = cur->right;
        else cur = cur->left;
    }
    for (int i = count - 1; i >= 0; i--) printf("%d ", temp[i]);
}

void boundary(Node *root) {
    if (!root) return;
    printf("Boundary traversal: ");
    if (!isLeaf(root)) printf("%d ", root->data);
    addLeftBoundary(root);
    addLeaves(root);
    addRightBoundary(root);
    printf("\n");
}

int main(void) {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    boundary(root);
    freeTree(root);
    return 0;
}
