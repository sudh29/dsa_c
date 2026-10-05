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

bool isPalindrome(Node *head) {
    int arr[1000];
    int n = 0;
    Node *cur = head;
    while (cur) {
        arr[n++] = cur->data;
        cur = cur->next;
    }
    for (int i = 0; i < n / 2; i++) {
        if (arr[i] != arr[n - 1 - i]) return false;
    }
    return true;
}

int main(void) {
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(2);
    head->next->next->next = newNode(1);

    printf("Is palindrome: %s\n", isPalindrome(head) ? "Yes" : "No");
    while (head) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
    return 0;
}
