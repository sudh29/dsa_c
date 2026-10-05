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

void inorder(Node* root, int arr[], int *count) {
    if (!root) return;
    inorder(root->left, arr, count);
    arr[(*count)++] = root->data;
    inorder(root->right, arr, count);
}

int countPairs(Node* root1, Node* root2, int x) {
    int arr1[100], arr2[100];
    int n1 = 0, n2 = 0;
    inorder(root1, arr1, &n1);
    inorder(root2, arr2, &n2);

    // Two pointer on sorted arrays
    int i = 0, j = n2 - 1;
    int count = 0;
    while (i < n1 && j >= 0) {
        int sum = arr1[i] + arr2[j];
        if (sum == x) {
            count++;
            i++;
            j--;
        } else if (sum < x) {
            i++;
        } else {
            j--;
        }
    }
    return count;
}

int main(void) {
    Node* r1 = newNode(5); r1->left = newNode(3); r1->right = newNode(7);
    Node* r2 = newNode(10); r2->left = newNode(6); r2->right = newNode(15);

    printf("Pairs summing to 16: %d\n", countPairs(r1, r2, 16));
    freeTree(r1);
    freeTree(r2);
    return 0;
}
