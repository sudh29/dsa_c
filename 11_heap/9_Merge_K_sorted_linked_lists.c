#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

static Node* newNode(int x) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = x;
    n->next = NULL;
    return n;
}

Node* mergeTwo(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    if (a->data <= b->data) {
        a->next = mergeTwo(a->next, b);
        return a;
    } else {
        b->next = mergeTwo(a, b->next);
        return b;
    }
}

Node* mergeKLists(Node *arr[], int K) {
    if (K == 0) return NULL;
    Node* head = arr[0];
    for (int i = 1; i < K; i++) {
        head = mergeTwo(head, arr[i]);
    }
    return head;
}

int main(void) {
    Node* l1 = newNode(1); l1->next = newNode(4);
    Node* l2 = newNode(2); l2->next = newNode(5);
    Node* l3 = newNode(3); l3->next = newNode(6);

    Node* arr[] = {l1, l2, l3};
    Node* merged = mergeKLists(arr, 3);
    printf("Merged K sorted LL: ");
    while (merged) {
        printf("%d ", merged->data);
        Node* tmp = merged;
        merged = merged->next;
        free(tmp);
    }
    printf("\n");
    return 0;
}
