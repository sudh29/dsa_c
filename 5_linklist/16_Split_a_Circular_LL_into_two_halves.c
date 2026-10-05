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

void splitList(Node *head, Node **head1_ref, Node **head2_ref) {
    Node *slow = head, *fast = head;
    if (!head) return;

    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    if (fast->next->next == head) fast = fast->next;

    *head1_ref = head;
    if (head->next != head) *head2_ref = slow->next;

    fast->next = slow->next;
    slow->next = head;
}

int main(void) {
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = head;

    Node *h1 = NULL, *h2 = NULL;
    splitList(head, &h1, &h2);
    printf("Split circular list into two halves successfully.\n");

    // Break circular references and free
    if (h1) {
        Node *curr = h1;
        while (curr->next != h1) curr = curr->next;
        curr->next = NULL;
    }
    if (h2) {
        Node *curr = h2;
        while (curr->next != h2) curr = curr->next;
        curr->next = NULL;
    }
    while (h1) { Node *t = h1; h1 = h1->next; free(t); }
    while (h2) { Node *t = h2; h2 = h2->next; free(t); }
    return 0;
}
