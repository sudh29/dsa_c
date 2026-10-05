#include <stdio.h>
#include <stdbool.h>

#define MAX_V 10

typedef struct {
    int matrix[MAX_V][MAX_V];
    int size;
} GraphAdjMatrix;

void initGraphAdj(GraphAdjMatrix *g, int n) {
    g->size = n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g->matrix[i][j] = 0;
}

void addEdge(GraphAdjMatrix *g, int u, int v) {
    if (u >= 0 && u < g->size && v >= 0 && v < g->size) {
        g->matrix[u][v] = 1;
        g->matrix[v][u] = 1;
    }
}

void bfs(const GraphAdjMatrix *g, int source) {
    bool visited[MAX_V] = {false};
    int q[MAX_V];
    int front = 0, rear = 0;

    q[rear++] = source;
    visited[source] = true;

    printf("BFS from %d: ", source);
    while (front < rear) {
        int u = q[front++];
        printf("%d ", u);

        for (int v = 0; v < g->size; v++) {
            if (g->matrix[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                q[rear++] = v;
            }
        }
    }
    printf("\n");
}

void printMatrix(const GraphAdjMatrix *g) {
    for (int i = 0; i < g->size; i++) {
        for (int j = 0; j < g->size; j++) {
            printf("%d ", g->matrix[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    GraphAdjMatrix g;
    initGraphAdj(&g, 6);
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 0, 3);
    addEdge(&g, 1, 4);
    addEdge(&g, 1, 5);

    printf("Adjacency Matrix:\n");
    printMatrix(&g);

    printf("\n");
    bfs(&g, 0);
    return 0;
}
