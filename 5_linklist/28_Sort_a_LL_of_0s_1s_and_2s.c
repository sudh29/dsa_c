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

Node* segregate(Node *head) {
    int count[3] = {0};
    Node *ptr = head;
    while (ptr) {
        count[ptr->data]++;
        ptr = ptr->next;
    }
    int i = 0;
    ptr = head;
    while (ptr) {
        if (count[i] == 0) {
            i++;
        } else {
            ptr->data = i;
            count[i]--;
            ptr = ptr->next;
        }
    }
    return head;
}

int main(void) {
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(2);
    head->next->next->next = newNode(0);

    head = segregate(head);
    printf("Segregated 0s, 1s, 2s LL: ");
    while (head) {
        printf("%d ", head->data);
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
    printf("\n");
    return 0;
}
