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

int getNthFromLast(Node *head, int n) {
    Node *first = head, *second = head;
    for (int i = 0; i < n; i++) {
        if (!first) return -1;
        first = first->next;
    }
    while (first) {
        first = first->next;
        second = second->next;
    }
    return second ? second->data : -1;
}

int main(void) {
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    printf("2nd from last node: %d\n", getNthFromLast(head, 2));
    while (head) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
    return 0;
}
