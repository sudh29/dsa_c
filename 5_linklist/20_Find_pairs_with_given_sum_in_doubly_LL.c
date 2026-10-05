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

void findPairsWithGivenSum(Node *head, int target) {
    Node *first = head, *second = head;
    while (second->next) second = second->next;

    printf("Pairs with sum %d in DLL: ", target);
    while (first && second && first != second && second->next != first) {
        int sum = first->data + second->data;
        if (sum == target) {
            printf("(%d, %d) ", first->data, second->data);
            first = first->next;
            second = second->prev;
        } else if (sum < target) {
            first = first->next;
        } else {
            second = second->prev;
        }
    }
    printf("\n");
}

int main(void) {
    Node* head = newNode(1);
    Node* n2 = newNode(2);
    Node* n3 = newNode(4);
    Node* n4 = newNode(5);
    head->next = n2; n2->prev = head;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;

    findPairsWithGivenSum(head, 6);
    while (head) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
    return 0;
}
