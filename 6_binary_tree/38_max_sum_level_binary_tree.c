#include <stdio.h>
#include <stdlib.h>
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

static int max(int a, int b) { return a > b ? a : b; }

int maxLevelSum(Node* root) {
    if (!root) return 0;
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int maxSum = INT_MIN;

    while (front < rear) {
        int sz = rear - front;
        int levelSum = 0;
        for (int i = 0; i < sz; i++) {
            Node* cur = queue[front++];
            levelSum += cur->data;
            if (cur->left) queue[rear++] = cur->left;
            if (cur->right) queue[rear++] = cur->right;
        }
        maxSum = max(maxSum, levelSum);
    }
    return maxSum;
}

int main(void) {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(8);

    printf("Max level sum: %d\n", maxLevelSum(root));
    freeTree(root);
    return 0;
}
