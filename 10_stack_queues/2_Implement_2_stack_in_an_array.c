#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
    int top1;
    int top2;
} TwoStacks;

TwoStacks* createTwoStacks(int n) {
    TwoStacks *ts = (TwoStacks*)malloc(sizeof(TwoStacks));
    ts->size = n;
    ts->top1 = -1;
    ts->top2 = n;
    ts->arr = (int*)malloc(n * sizeof(int));
    return ts;
}

void freeTwoStacks(TwoStacks *ts) {
    if (!ts) return;
    free(ts->arr);
    free(ts);
}

void push1(TwoStacks *ts, int x) {
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[++ts->top1] = x;
    } else {
        printf("Stack Overflow in Stack 1\n");
    }
}

void push2(TwoStacks *ts, int x) {
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[--ts->top2] = x;
    } else {
        printf("Stack Overflow in Stack 2\n");
    }
}

int pop1(TwoStacks *ts) {
    if (ts->top1 >= 0) return ts->arr[ts->top1--];
    return -1;
}

int pop2(TwoStacks *ts) {
    if (ts->top2 < ts->size) return ts->arr[ts->top2++];
    return -1;
}

int main(void) {
    TwoStacks *ts = createTwoStacks(10);
    push1(ts, 5);
    push2(ts, 10);
    push2(ts, 15);
    push1(ts, 11);
    push2(ts, 7);

    printf("Popped from stack 1: %d\n", pop1(ts));
    printf("Popped from stack 2: %d\n", pop2(ts));
    freeTwoStacks(ts);
    return 0;
}
