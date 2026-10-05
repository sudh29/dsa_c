#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

static Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = temp->prev = NULL;
    return temp;
}

int countTriplets(Node* head, int x) {
    Node *ptr1, *ptr2, *ptr3;
    int count = 0;
    for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next) {
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next) {
            for (ptr3 = ptr2->next; ptr3 != NULL; ptr3 = ptr3->next) {
                if ((ptr1->data + ptr2->data + ptr3->data) == x)
                    count++;
            }
        }
    }
    return count;
}

int main(void) {
    Node* head = newNode(1);
    Node* n2 = newNode(2);
    Node* n3 = newNode(4);
    Node* n4 = newNode(5);
    Node* n5 = newNode(6);
    head->next = n2; n2->prev = head;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;

    printf("Triplets summing to 9 in DLL: %d\n", countTriplets(head, 9));
    while (head) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
    return 0;
}
