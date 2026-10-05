#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 10007

typedef struct HashNode {
    long long key;
    long long count;
    struct HashNode *next;
} HashNode;

static unsigned int hash_key(long long key) {
    return (unsigned int)(key < 0 ? -key : key) % HASH_SIZE;
}

static long long get_count(HashNode **table, long long key) {
    unsigned int h = hash_key(key);
    HashNode *cur = table[h];
    while (cur) {
        if (cur->key == key) return cur->count;
        cur = cur->next;
    }
    return 0;
}

static void add_count(HashNode **table, long long key) {
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

long long findSubarray(const long long arr[], int n) {
    HashNode *table[HASH_SIZE] = {NULL};
    long long sum = 0, count = 0;
    add_count(table, 0);

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        count += get_count(table, sum);
        add_count(table, sum);
    }
    free_table(table);
    return count;
}

int main(void) {
    long long arr[] = {0, 0, 5, 5, 0, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Zero sum subarrays count: %lld\n", findSubarray(arr, n));
    return 0;
}
