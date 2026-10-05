#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_LEVELS 100

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

static int max(int a, int b) { return a > b ? a : b; }

void calculateLevelSums(Node* root, int level, int sums[], int *maxDepth) {
    if (!root) return;
    if (level >= *maxDepth) *maxDepth = level + 1;
    sums[level] += root->data;
    calculateLevelSums(root->left, level + 1, sums, maxDepth);
    calculateLevelSums(root->right, level + 1, sums, maxDepth);
}

int maxLevelSumRec(Node* root) {
    int sums[MAX_LEVELS] = {0};
    int maxDepth = 0;
    calculateLevelSums(root, 0, sums, &maxDepth);
    int maxSum = INT_MIN;
    for (int i = 0; i < maxDepth; i++) {
        maxSum = max(maxSum, sums[i]);
    }
    return maxSum;
}

int main(void) {
    Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(-5);
    root->left->left = newNode(-1);
    root->left->right = newNode(3);

    printf("Max level sum (recursive): %d\n", maxLevelSumRec(root));
    freeTree(root);
    return 0;
}
