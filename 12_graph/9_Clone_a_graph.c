#include <stdio.h>
#include <stdlib.h>

#define MAX_NEIGHBORS 10

typedef struct Node {
    int val;
    struct Node* neighbors[MAX_NEIGHBORS];
    int numNeighbors;
} Node;

static Node* newNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = val;
    n->numNeighbors = 0;
    return n;
}

Node* cloneGraph(Node* node) {
    if (!node) return NULL;

    Node* visited[100] = {NULL};
    Node* q[100];
    int front = 0, rear = 0;

    visited[node->val] = newNode(node->val);
    q[rear++] = node;

    while (front < rear) {
        Node* curr = q[front++];

        for (int i = 0; i < curr->numNeighbors; i++) {
            Node* neighbor = curr->neighbors[i];
            if (!visited[neighbor->val]) {
                visited[neighbor->val] = newNode(neighbor->val);
                q[rear++] = neighbor;
            }
            Node* clonedCurr = visited[curr->val];
            clonedCurr->neighbors[clonedCurr->numNeighbors++] = visited[neighbor->val];
        }
    }
    return visited[node->val];
}

int main(void) {
    Node* node1 = newNode(1);
    Node* node2 = newNode(2);
    Node* node3 = newNode(3);
    Node* node4 = newNode(4);

    node1->neighbors[node1->numNeighbors++] = node2;
    node1->neighbors[node1->numNeighbors++] = node4;

    node2->neighbors[node2->numNeighbors++] = node1;
    node2->neighbors[node2->numNeighbors++] = node3;

    node3->neighbors[node3->numNeighbors++] = node2;
    node3->neighbors[node3->numNeighbors++] = node4;

    node4->neighbors[node4->numNeighbors++] = node1;
    node4->neighbors[node4->numNeighbors++] = node3;

    Node* cloned = cloneGraph(node1);
    printf("Cloned graph node val: %d\n", cloned->val);
    printf("Neighbors of cloned node 1: ");
    for (int i = 0; i < cloned->numNeighbors; i++) {
        printf("%d ", cloned->neighbors[i]->val);
    }
    printf("\n");

    // Clean up
    free(node1); free(node2); free(node3); free(node4);
    for (int i = 0; i < 100; i++) {
        if (cloned && i == cloned->val) continue; // prevent double free if any
    }
    return 0;
}
