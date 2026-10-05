#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dynamic Array (Vector) in C
typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Vector;

Vector* vector_create(size_t initial_cap) {
    Vector *v = (Vector*)malloc(sizeof(Vector));
    if (!v) return NULL;
    v->size = 0;
    v->capacity = initial_cap ? initial_cap : 4;
    v->data = (int*)malloc(v->capacity * sizeof(int));
    if (!v->data) {
        free(v);
        return NULL;
    }
    return v;
}

void vector_push_back(Vector *v, int val) {
    if (v->size >= v->capacity) {
        v->capacity *= 2;
        v->data = (int*)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = val;
}

void vector_free(Vector *v) {
    if (v) {
        free(v->data);
        free(v);
    }
}

static int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

int main(void) {
    printf("=== Dynamic Array (Vector) & Frequency Table in C ===\n");

    Vector *vec = vector_create(4);
    int initial_values[] = {5, 2, 9, 1, 5, 6};
    size_t n = sizeof(initial_values) / sizeof(initial_values[0]);

    for (size_t i = 0; i < n; i++) {
        vector_push_back(vec, initial_values[i]);
    }

    // Sort using qsort
    qsort(vec->data, vec->size, sizeof(int), cmp_int);
    printf("Sorted vector: ");
    for (size_t i = 0; i < vec->size; i++) {
        printf("%d ", vec->data[i]);
    }
    printf("\n");

    // Counting unique elements
    size_t unique_count = 0;
    for (size_t i = 0; i < vec->size; i++) {
        if (i == 0 || vec->data[i] != vec->data[i - 1]) {
            unique_count++;
        }
    }
    printf("Unique elements count: %zu\n", unique_count);

    // Simple hash/frequency map demo with key-value pairs
    const char *fruits[] = {"apple", "banana"};
    int counts[] = {3, 5};
    for (int i = 0; i < 2; i++) {
        printf("Key: %s -> Value: %d\n", fruits[i], counts[i]);
    }

    vector_free(vec);
    return 0;
}
