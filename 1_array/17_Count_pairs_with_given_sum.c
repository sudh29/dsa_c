#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 10007

typedef struct HashNode {
    int key;
    int count;
    struct HashNode *next;
} HashNode;

static unsigned int hash_key(int key) {
    return (unsigned int)(key < 0 ? -key : key) % HASH_SIZE;
}

static int get_count(HashNode **table, int key) {
    unsigned int h = hash_key(key);
    HashNode *cur = table[h];
    while (cur) {
        if (cur->key == key) return cur->count;
        cur = cur->next;
    }
    return 0;
}

static void add_key(HashNode **table, int key) {
    unsigned int h = hash_key(key);
    HashNode *cur = table[h];
    while (cur) {
        if (cur->key == key) {
            cur->count++;
            return;
        }
        cur = cur->next;
    }
    HashNode *node = (HashNode*)malloc(sizeof(HashNode));
    node->key = key;
    node->count = 1;
    node->next = table[h];
    table[h] = node;
}

static void free_table(HashNode **table) {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode *cur = table[i];
        while (cur) {
            HashNode *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
}

int getPairsCount(const int arr[], int n, int k) {
    HashNode *table[HASH_SIZE] = {NULL};
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += get_count(table, k - arr[i]);
        add_key(table, arr[i]);
    }
    free_table(table);
    return count;
}

int main(void) {
    int arr[] = {1, 5, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;
    printf("Pairs with sum %d: %d\n", k, getPairsCount(arr, n, k));
    return 0;
}
