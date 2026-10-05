#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VAL 1000

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

void storeNodes(Node* root, bool all_nodes[], int leaf_nodes[], int *leafCount) {
    if (!root) return;
    if (root->data < MAX_VAL) all_nodes[root->data] = true;
    if (!root->left && !root->right) {
        leaf_nodes[(*leafCount)++] = root->data;
    }
    storeNodes(root->left, all_nodes, leaf_nodes, leafCount);
    storeNodes(root->right, all_nodes, leaf_nodes, leafCount);
}

bool isDeadEnd(Node *root) {
    bool all_nodes[MAX_VAL] = {false};
    int leaf_nodes[100];
    int leafCount = 0;
    all_nodes[0] = true;
    storeNodes(root, all_nodes, leaf_nodes, &leafCount);

    for (int i = 0; i < leafCount; i++) {
        int val = leaf_nodes[i];
        if (val > 0 && val + 1 < MAX_VAL) {
            if (all_nodes[val - 1] && all_nodes[val + 1]) {
                return true;
            }
        }
    }
    return false;
}

int main(void) {
    Node* root = newNode(8);
    root->left = newNode(5);
    root->right = newNode(9);
    root->left->left = newNode(2);
    root->left->right = newNode(7);
    root->left->left->left = newNode(1);

    printf("Contains dead end: %s\n", isDeadEnd(root) ? "Yes" : "No");
    freeTree(root);
    return 0;
}
