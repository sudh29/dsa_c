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

void zigZagTraversal(Node* root) {
    if (!root) return;
    Node* q[200];
    int front = 0, rear = 0;
    q[rear++] = root;
    bool leftToRight = true;

    printf("ZigZag traversal: ");
    while (front < rear) {
        int sz = rear - front;
        int level[200];
        for (int i = 0; i < sz; i++) {
            Node* cur = q[front++];
            int idx = leftToRight ? i : (sz - 1 - i);
            level[idx] = cur->data;
            if (cur->left) q[rear++] = cur->left;
            if (cur->right) q[rear++] = cur->right;
        }
        for (int i = 0; i < sz; i++) {
            printf("%d ", level[i]);
        }
        leftToRight = !leftToRight;
    }
    printf("\n");
}

int main(void) {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->right = newNode(5);

    zigZagTraversal(root);
    freeTree(root);
    return 0;
}
