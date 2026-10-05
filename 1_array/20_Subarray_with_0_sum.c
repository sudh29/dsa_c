#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HASH_SIZE 10007

typedef struct HashNode {
    int key;
    struct HashNode *next;
} HashNode;

static unsigned int hash_key(int key) {
    return (unsigned int)(key < 0 ? -key : key) % HASH_SIZE;
}

static bool contains(HashNode **table, int key) {
    unsigned int h = hash_key(key);
    HashNode *cur = table[h];
    while (cur) {
        if (cur->key == key) return true;
        cur = cur->next;
    }
    return false;
}

static void insert(HashNode **table, int key) {
    unsigned int h = hash_key(key);
    HashNode *node = (HashNode*)malloc(sizeof(HashNode));
    node->key = key;
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

bool subArrayExists(const int arr[], int n) {
    HashNode *table[HASH_SIZE] = {NULL};
    int sum = 0;
    bool found = false;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == 0 || contains(table, sum)) {
            found = true;
            break;
        }
        insert(table, sum);
    }
    free_table(table);
    return found;
}

int main(void) {
    int arr[] = {4, 2, -3, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Subarray with 0 sum exists: %s\n", subArrayExists(arr, n) ? "Yes" : "No");
    return 0;
}
