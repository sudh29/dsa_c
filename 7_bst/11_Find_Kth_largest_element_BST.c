#include <stdio.h>
#include <stdlib.h>

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

void reverseInorder(Node* root, int *k, int *ans) {
    if (!root || *k <= 0) return;
    reverseInorder(root->right, k, ans);
    (*k)--;
    if (*k == 0) {
        *ans = root->data;
        return;
    }
    reverseInorder(root->left, k, ans);
}

int kthLargest(Node *root, int K) {
    int ans = -1;
    reverseInorder(root, &K, &ans);
    return ans;
}

int main(void) {
    Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(9);

    printf("2nd largest element: %d\n", kthLargest(root, 2));
    freeTree(root);
    return 0;
}
