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

void reverse(Node **head_ref) {
    if (!*head_ref) return;
    Node *prev = NULL, *current = *head_ref, *next;
    Node *last = *head_ref;
    while (last->next != *head_ref) last = last->next;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != *head_ref);

    (*head_ref)->next = prev;
    *head_ref = prev;
}

int main(void) {
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = head;

    reverse(&head);
    printf("Reversed circular list [0]: %d, [1]: %d\n", head->data, head->next->data);

    head->next->next->next = NULL;
    while (head) {
        Node *t = head;
        head = head->next;
        free(t);
    }
    return 0;
}
