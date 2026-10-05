#include <stdio.h>

#define MAX_V 10

typedef struct {
    int adj[MAX_V][MAX_V];
    int deg[MAX_V];
} Graph;

void printGraph(int V, const int edges[][2], int E) {
    Graph g;
    for (int i = 0; i < V; i++) g.deg[i] = 0;

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        g.adj[u][g.deg[u]++] = v;
        g.adj[v][g.deg[v]++] = u;
    }

    printf("Adjacency List Representation:\n");
    for (int i = 0; i < V; i++) {
        printf("%d: ", i);
        for (int j = 0; j < g.deg[i]; j++) {
            printf("%d ", g.adj[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int V = 5;
    int edges[7][2] = {
        {0, 1}, {0, 4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {3, 4}
    };
    printGraph(V, edges, 7);
    return 0;
}
