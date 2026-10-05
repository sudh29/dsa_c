#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

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

static bool areIdentical(Node* r1, Node* r2) {
    if (!r1 && !r2) return true;
    if (!r1 || !r2) return false;
    return (r1->data == r2->data) &&
           areIdentical(r1->left, r2->left) &&
           areIdentical(r1->right, r2->right);
}

static void collectAll(Node* root, Node* list[], int *count) {
    if (!root) return;
    list[(*count)++] = root;
    collectAll(root->left, list, count);
    collectAll(root->right, list, count);
}

int countDuplicateSubtrees(Node* root) {
    Node* list[MAX_NODES];
    int count = 0;
    collectAll(root, list, &count);

    bool reported[MAX_NODES] = {false};
    int dupCount = 0;

    for (int i = 0; i < count; i++) {
        if (reported[i]) continue;
        bool hasDup = false;
        for (int j = i + 1; j < count; j++) {
            if (areIdentical(list[i], list[j])) {
                hasDup = true;
                reported[j] = true;
            }
        }
        if (hasDup) {
            dupCount++;
        }
    }
    return dupCount;
}

int main(void) {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(2);
    root->right->left->left = newNode(4);
    root->right->right = newNode(4);

    int dups = countDuplicateSubtrees(root);
    printf("Duplicate subtrees count: %d\n", dups);
    freeTree(root);
    return 0;
}
