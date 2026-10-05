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

void removeLoop(Node* head) {
    if (!head || !head->next) return;
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (slow != fast) return;

    if (slow == head) {
        while (fast->next != slow) fast = fast->next;
        fast->next = NULL;
        return;
    }

    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}

int main(void) {
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = head->next; // loop

    removeLoop(head);
    printf("Loop removed successfully.\n");

    while (head) {
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }
    return 0;
}
