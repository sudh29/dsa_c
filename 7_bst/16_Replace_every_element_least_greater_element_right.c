#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
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

Node* insert(Node* node, int data, Node** succ) {
    if (!node) return newNode(data);
    if (data < node->data) {
        *succ = node;
        node->left = insert(node->left, data, succ);
    } else {
        node->right = insert(node->right, data, succ);
    }
    return node;
}

void findLeastGreater(const int arr[], int n, int res[]) {
    Node* root = NULL;
    for (int i = 0; i < n; i++) res[i] = -1;
    for (int i = n - 1; i >= 0; i--) {
        Node* succ = NULL;
        root = insert(root, arr[i], &succ);
        if (succ) res[i] = succ->data;
    }
    freeTree(root);
}

int main(void) {
    int arr[] = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *res = (int*)malloc(n * sizeof(int));
    findLeastGreater(arr, n, res);
    printf("Least greater on right for 8: %d\n", res[0]);
    free(res);
    return 0;
}
