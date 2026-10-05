#include <stdio.h>

#define MAX_V 10

typedef struct {
    int v;
    int weight;
} Edge;

typedef struct {
    Edge edges[MAX_V][MAX_V];
    int deg[MAX_V];
} Graph;

void initGraph(Graph *g) {
    for (int i = 0; i < MAX_V; i++) g->deg[i] = 0;
}

void addEdge(Graph *g, int u, int v, int dist, int bidirectional) {
    g->edges[u][g->deg[u]++] = (Edge){v, dist};
    if (bidirectional) {
        g->edges[v][g->deg[v]++] = (Edge){u, dist};
    }
}

void printAdj(const Graph *g) {
    for (int i = 0; i < MAX_V; i++) {
        if (g->deg[i] > 0) {
            printf("%d : ", i);
            for (int j = 0; j < g->deg[i]; j++) {
                printf("(%d, %d) ", g->edges[i][j].v, g->edges[i][j].weight);
            }
            printf("\n");
        }
    }
}

int main(void) {
    Graph g;
    initGraph(&g);
    addEdge(&g, 0, 1, 4, 0);
    addEdge(&g, 0, 7, 8, 0);
    addEdge(&g, 1, 7, 11, 0);
    addEdge(&g, 1, 2, 8, 0);
    addEdge(&g, 7, 8, 7, 0);

    printf("Graph Adjacency List:\n");
    printAdj(&g);
    return 0;
}
