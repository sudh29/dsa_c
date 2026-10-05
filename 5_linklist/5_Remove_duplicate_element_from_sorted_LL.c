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

Node* removeDuplicates(Node* head) {
    Node* cur = head;
    while (cur && cur->next) {
        if (cur->data == cur->next->data) {
            Node* dup = cur->next;
            cur->next = cur->next->next;
            free(dup);
        } else {
            cur = cur->next;
        }
    }
    return head;
}

int main(void) {
    Node* head = newNode(2);
    head->next = newNode(2);
    head->next->next = newNode(4);
    head->next->next->next = newNode(5);

    head = removeDuplicates(head);
    printf("Deduplicated sorted list: ");
    while (head) {
        printf("%d ", head->data);
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
    printf("\n");
    return 0;
}
