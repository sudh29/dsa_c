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

Node* removeDuplicates(Node *head) {
    if (!head) return NULL;
    // O(n^2) in-place deduplication for small demonstration without hash map
    Node *ptr1 = head, *ptr2, *dup;
    while (ptr1 && ptr1->next) {
        ptr2 = ptr1;
        while (ptr2->next) {
            if (ptr1->data == ptr2->next->data) {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            } else {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
    return head;
}

int main(void) {
    Node* head = newNode(5);
    head->next = newNode(2);
    head->next->next = newNode(2);
    head->next->next->next = newNode(4);

    head = removeDuplicates(head);
    printf("Deduplicated unsorted list: ");
    while (head) {
        printf("%d ", head->data);
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
    printf("\n");
    return 0;
}
