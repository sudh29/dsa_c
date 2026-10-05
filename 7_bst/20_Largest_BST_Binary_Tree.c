#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

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

static int min(int a, int b) { return a < b ? a : b; }
static int max(int a, int b) { return a > b ? a : b; }

typedef struct {
    int minVal;
    int maxVal;
    int ans;
    int size;
    bool isBST;
} NodeInfo;

NodeInfo largestBSTUtil(Node* root) {
    if (!root) {
        return (NodeInfo){INT_MAX, INT_MIN, 0, 0, true};
    }
    if (!root->left && !root->right) {
        return (NodeInfo){root->data, root->data, 1, 1, true};
    }

    NodeInfo l = largestBSTUtil(root->left);
    NodeInfo r = largestBSTUtil(root->right);

    NodeInfo ret;
    ret.size = 1 + l.size + r.size;

    if (l.isBST && r.isBST && l.maxVal < root->data && r.minVal > root->data) {
        ret.minVal = min(root->data, l.minVal);
        ret.maxVal = max(root->data, r.maxVal);
        ret.ans = ret.size;
        ret.isBST = true;
        return ret;
    }

    ret.ans = max(l.ans, r.ans);
    ret.isBST = false;
    ret.minVal = INT_MIN;
    ret.maxVal = INT_MAX;
    return ret;
}

int largestBst(Node *root) {
    return largestBSTUtil(root).ans;
}

int main(void) {
    Node* root = newNode(6);
    root->left = newNode(6);
    root->right = newNode(3);
    root->right->left = newNode(2);
    root->right->right = newNode(9);

    printf("Largest BST size in Binary Tree: %d\n", largestBst(root));
    freeTree(root);
    return 0;
}
