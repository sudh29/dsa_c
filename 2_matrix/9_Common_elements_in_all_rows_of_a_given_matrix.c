#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 1021

typedef struct HashNode {
    int key;
    int count;
    struct HashNode *next;
} HashNode;

static unsigned int hash_func(int key) {
    return (unsigned int)(key < 0 ? -key : key) % HASH_SIZE;
}

static HashNode* find_node(HashNode **table, int key) {
    unsigned int h = hash_func(key);
    HashNode *cur = table[h];
    while (cur) {
        if (cur->key == key) return cur;
        cur = cur->next;
    }
    return NULL;
}

static void insert_or_update(HashNode **table, int key, int val) {
    HashNode *node = find_node(table, key);
    if (node) {
        node->count = val;
    } else {
        unsigned int h = hash_func(key);
        HashNode *new_node = (HashNode*)malloc(sizeof(HashNode));
        new_node->key = key;
        new_node->count = val;
        new_node->next = table[h];
        table[h] = new_node;
    }
}

void printCommonElements(int n, const int mat[n][n]) {
    HashNode *table[HASH_SIZE] = {NULL};

    // First row
    for (int j = 0; j < n; j++) {
        insert_or_update(table, mat[0][j], 1);
    }

    // Subsequent rows
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            HashNode *node = find_node(table, mat[i][j]);
            if (node && node->count == i) {
                node->count = i + 1;
            }
        }
    }

    printf("Common elements across all rows: ");
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode *cur = table[i];
        while (cur) {
            if (cur->count == n) {
                printf("%d ", cur->key);
            }
            HashNode *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    printf("\n");
}

int main(void) {
    int mat[4][4] = {
        {2, 1, 4, 3},
        {1, 2, 3, 2},
        {3, 6, 2, 3},
        {5, 2, 5, 3}
    };
    printCommonElements(4, mat);
    return 0;
}
