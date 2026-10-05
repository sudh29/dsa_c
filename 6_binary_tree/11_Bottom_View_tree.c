#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define OFFSET 500
#define MAP_SIZE 1001

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct QItem {
    Node* node;
    int hd;
} QItem;

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

void bottomView(Node *root) {
    if (!root) return;
    int botNode[MAP_SIZE];
    bool hasVal[MAP_SIZE] = {false};
    int min_hd = 0, max_hd = 0;

    QItem q[200];
    int front = 0, rear = 0;
    q[rear++] = (QItem){root, 0};

    while (front < rear) {
        QItem cur = q[front++];
        int idx = cur.hd + OFFSET;
        hasVal[idx] = true;
        botNode[idx] = cur.node->data;
        if (cur.hd < min_hd) min_hd = cur.hd;
        if (cur.hd > max_hd) max_hd = cur.hd;

        if (cur.node->left) q[rear++] = (QItem){cur.node->left, cur.hd - 1};
        if (cur.node->right) q[rear++] = (QItem){cur.node->right, cur.hd + 1};
    }

    printf("Bottom view: ");
    for (int hd = min_hd; hd <= max_hd; hd++) {
        if (hasVal[hd + OFFSET]) {
            printf("%d ", botNode[hd + OFFSET]);
        }
    }
    printf("\n");
}

int main(void) {
    Node* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(5);
    root->left->right = newNode(3);
    root->right->right = newNode(25);

    bottomView(root);
    freeTree(root);
    return 0;
}
