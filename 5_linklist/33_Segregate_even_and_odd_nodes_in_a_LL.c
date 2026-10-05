#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

Node* divide(int N, Node *head) {
    (void)N;
    Node *evenStart = NULL, *evenEnd = NULL;
    Node *oddStart = NULL, *oddEnd = NULL;
    Node *cur = head;

    while (cur) {
        int val = cur->data;
        if (val % 2 == 0) {
            if (!evenStart) {
                evenStart = evenEnd = cur;
            } else {
                evenEnd->next = cur;
                evenEnd = evenEnd->next;
            }
        } else {
            if (!oddStart) {
                oddStart = oddEnd = cur;
            } else {
                oddEnd->next = cur;
                oddEnd = oddEnd->next;
            }
        }
        cur = cur->next;
    }

    if (!evenStart || !oddStart) return head;
    evenEnd->next = oddStart;
    oddEnd->next = NULL;
    return evenStart;
}

int main(void) {
    Node* head = newNode(17);
    head->next = newNode(15);
    head->next->next = newNode(8);
    head->next->next->next = newNode(9);
    head->next->next->next->next = newNode(2);

    head = divide(5, head);
    printf("Segregated even and odd: ");
    Node* cur = head;
    while (cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
    assert(head->data == 8 && head->next->data == 2);

    while (head) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
    return 0;
}
