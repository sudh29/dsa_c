#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 20

typedef struct {
    int adj[MAX_VERTICES][MAX_VERTICES];
    int deg[MAX_VERTICES];
} Graph;

static void addEdge(Graph *g, int u, int v) {
    g->adj[u][g->deg[u]++] = v;
}

bool isCyclic(int u, int parent, bool visited[], const Graph *g) {
    visited[u] = true;
    for (int i = 0; i < g->deg[u]; i++) {
        int v = g->adj[u][i];
        if (!visited[v]) {
            if (isCyclic(v, u, visited, g)) return true;
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

bool isTree(int n, const Graph *g) {
    bool visited[MAX_VERTICES] = {false};
    if (isCyclic(0, -1, visited, g)) return false;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) return false;
    }
    return true;
}

int main(void) {
    int n = 5;
    Graph g;
    for (int i = 0; i < n; i++) g.deg[i] = 0;

    addEdge(&g, 0, 1); addEdge(&g, 0, 2); addEdge(&g, 0, 3);
    addEdge(&g, 1, 0);
    addEdge(&g, 2, 0);
    addEdge(&g, 3, 0); addEdge(&g, 3, 4);
    addEdge(&g, 4, 3);

    printf("Is graph a valid tree: %s\n", isTree(n, &g) ? "Yes" : "No");
    return 0;
}
