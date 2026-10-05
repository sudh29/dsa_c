#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

static Node* newNode(int x) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->key = x;
    n->left = n->right = NULL;
    return n;
}

static void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void findPreSuc(Node* root, Node** pre, Node** suc, int key) {
    if (!root) return;

    if (root->key == key) {
        if (root->left) {
            Node* tmp = root->left;
            while (tmp->right) tmp = tmp->right;
            *pre = tmp;
        }
        if (root->right) {
            Node* tmp = root->right;
            while (tmp->left) tmp = tmp->left;
            *suc = tmp;
        }
        return;
    }

    if (root->key > key) {
        *suc = root;
        findPreSuc(root->left, pre, suc, key);
    } else {
        *pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

int main(void) {
    Node* root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);
    root->left->left = newNode(20);
    root->left->right = newNode(40);

    Node *pre = NULL, *suc = NULL;
    findPreSuc(root, &pre, &suc, 30);
    printf("For key 30 -> Predecessor: %d, Successor: %d\n",
           pre ? pre->key : -1, suc ? suc->key : -1);
    freeTree(root);
    return 0;
}
