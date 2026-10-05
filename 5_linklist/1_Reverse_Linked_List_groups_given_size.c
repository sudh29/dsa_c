#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

static Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

Node* reverse(Node *head, int k) {
    if (!head) return NULL;
    Node *cur = head, *next = NULL, *prev = NULL;
    int count = 0;
    while (cur && count < k) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        count++;
    }
    if (next) {
        head->next = reverse(next, k);
    }
    return prev;
}

static void printList(Node *node) {
    while (node) {
        printf("%d ", node->data);
        Node* tmp = node;
        node = node->next;
        free(tmp);
    }
    printf("\n");
}

int main(void) {
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    head = reverse(head, 2);
    printf("Reversed in groups of 2: ");
    printList(head);
    return 0;
}
