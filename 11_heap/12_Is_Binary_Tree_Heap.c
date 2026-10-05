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

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isComplete(Node* root, int index, int totalNodes) {
    if (!root) return true;
    if (index >= totalNodes) return false;
    return isComplete(root->left, 2 * index + 1, totalNodes) &&
           isComplete(root->right, 2 * index + 2, totalNodes);
}

bool isHeapProperty(Node* root) {
    if (!root->left && !root->right) return true;
    if (!root->right) {
        return root->data >= root->left->data;
    }
    if (root->data >= root->left->data && root->data >= root->right->data) {
        return isHeapProperty(root->left) && isHeapProperty(root->right);
    }
    return false;
}

bool isHeap(Node* root) {
    if (!root) return true;
    int total = countNodes(root);
    return isComplete(root, 0, total) && isHeapProperty(root);
}

int main(void) {
    Node* root = newNode(10);
    root->left = newNode(9);
    root->right = newNode(8);
    root->left->left = newNode(7);
    root->left->right = newNode(6);

    printf("Is tree a valid max-heap: %s\n", isHeap(root) ? "Yes" : "No");
    freeTree(root);
    return 0;
}
