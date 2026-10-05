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

static int search(const int in[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (in[i] == val) return i;
    }
    return -1;
}

Node* build(const int in[], const int pre[], int inStart, int inEnd, int *preIdx) {
    if (inStart > inEnd) return NULL;
    int rootVal = pre[(*preIdx)++];
    Node* root = newNode(rootVal);
    int inIndex = search(in, inStart, inEnd, rootVal);

    root->left = build(in, pre, inStart, inIndex - 1, preIdx);
    root->right = build(in, pre, inIndex + 1, inEnd, preIdx);
    return root;
}

Node* buildTree(const int in[], const int pre[], int n) {
    int preIdx = 0;
    return build(in, pre, 0, n - 1, &preIdx);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main(void) {
    int in[] = {3, 1, 4, 0, 5, 2};
    int pre[] = {0, 1, 3, 4, 2, 5};
    Node* root = buildTree(in, pre, 6);
    printf("Postorder of built tree: ");
    postorder(root);
    printf("\n");
    freeTree(root);
    return 0;
}
