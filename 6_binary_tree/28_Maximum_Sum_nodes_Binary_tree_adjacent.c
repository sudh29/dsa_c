#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct {
    int incl;
    int excl;
} Pair;

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

static int max(int a, int b) { return a > b ? a : b; }

Pair dfs(Node* root) {
    if (!root) return (Pair){0, 0};
    Pair l = dfs(root->left);
    Pair r = dfs(root->right);

    int incl = root->data + l.excl + r.excl;
    int excl = max(l.incl, l.excl) + max(r.incl, r.excl);
    return (Pair){incl, excl};
}

int getMaxSum(Node *root) {
    Pair res = dfs(root);
    return max(res.incl, res.excl);
}

int main(void) {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(1);
    root->right->left = newNode(4);
    root->right->right = newNode(5);

    printf("Max sum without adjacent nodes: %d\n", getMaxSum(root));
    freeTree(root);
    return 0;
}
