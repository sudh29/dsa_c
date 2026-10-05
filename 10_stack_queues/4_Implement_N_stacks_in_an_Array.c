#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int *top;
    int *next;
    int n, k;
    int freeSlot;
} KStacks;

KStacks* createKStacks(int k1, int n1) {
    KStacks *ks = (KStacks*)malloc(sizeof(KStacks));
    ks->n = n1;
    ks->k = k1;
    ks->freeSlot = 0;
    ks->arr = (int*)malloc(n1 * sizeof(int));
    ks->top = (int*)malloc(k1 * sizeof(int));
    ks->next = (int*)malloc(n1 * sizeof(int));

    for (int i = 0; i < k1; i++) ks->top[i] = -1;
    for (int i = 0; i < n1 - 1; i++) ks->next[i] = i + 1;
    ks->next[n1 - 1] = -1;
    return ks;
}

void freeKStacks(KStacks *ks) {
    if (!ks) return;
    free(ks->arr);
    free(ks->top);
    free(ks->next);
    free(ks);
}

bool isFull(const KStacks *ks) { return ks->freeSlot == -1; }
bool isEmpty(const KStacks *ks, int sn) { return ks->top[sn] == -1; }

void push(KStacks *ks, int item, int sn) {
    if (isFull(ks)) {
        printf("Stack Overflow\n");
        return;
    }
    int i = ks->freeSlot;
    ks->freeSlot = ks->next[i];
    ks->next[i] = ks->top[sn];
    ks->top[sn] = i;
    ks->arr[i] = item;
}

int pop(KStacks *ks, int sn) {
    if (isEmpty(ks, sn)) return -1;
    int i = ks->top[sn];
    ks->top[sn] = ks->next[i];
    ks->next[i] = ks->freeSlot;
    ks->freeSlot = i;
    return ks->arr[i];
}

int main(void) {
    int k = 3, n = 10;
    KStacks *ks = createKStacks(k, n);

    push(ks, 15, 2);
    push(ks, 45, 2);
    push(ks, 17, 1);
    push(ks, 49, 1);
    push(ks, 39, 1);
    push(ks, 11, 0);

    printf("Popped from stack 2: %d\n", pop(ks, 2));
    printf("Popped from stack 1: %d\n", pop(ks, 1));
    printf("Popped from stack 0: %d\n", pop(ks, 0));
    freeKStacks(ks);
    return 0;
}
