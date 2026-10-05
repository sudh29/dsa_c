#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isCircular(Node *head) {
    if (!head) return true;
    Node *node = head->next;
    while (node && node != head) {
        node = node->next;
    }
    return (node == head);
}

int main(void) {
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = head; // circular

    printf("Is circular: %s\n", isCircular(head) ? "Yes" : "No");
    free(head->next);
    free(head);
    return 0;
}
