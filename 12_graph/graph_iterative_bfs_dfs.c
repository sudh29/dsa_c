#include <stdio.h>
#include <stdbool.h>

#define MAX_V 10

typedef struct {
    int adj[MAX_V][MAX_V];
    int deg[MAX_V];
    int numV;
} Graph;

void initGraph(Graph *g, int n) {
    g->numV = n;
    for (int i = 0; i < n; i++) g->deg[i] = 0;
}

void addEdge(Graph *g, int u, int v) {
    g->adj[u][g->deg[u]++] = v;
    g->adj[v][g->deg[v]++] = u;
}

void bfs(const Graph *g, int start) {
    bool visited[MAX_V] = {false};
    int q[MAX_V];
    int front = 0, rear = 0;

    visited[start] = true;
    q[rear++] = start;

    printf("Iterative BFS: ");
    while (front < rear) {
        int curr = q[front++];
        printf("%d ", curr);

        for (int i = 0; i < g->deg[curr]; i++) {
            int neighbor = g->adj[curr][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q[rear++] = neighbor;
            }
        }
    }
    printf("\n");
}

void dfs(const Graph *g, int start) {
    bool visited[MAX_V] = {false};
    int s[MAX_V];
    int top = 0;

    s[top++] = start;

    printf("Iterative DFS: ");
    while (top > 0) {
        int curr = s[--top];

        if (!visited[curr]) {
            visited[curr] = true;
            printf("%d ", curr);

            for (int i = g->deg[curr] - 1; i >= 0; i--) {
                int neighbor = g->adj[curr][i];
                if (!visited[neighbor]) {
                    s[top++] = neighbor;
                }
            }
        }
    }
    printf("\n");
}

int main(void) {
    Graph g;
    initGraph(&g, 5);
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 4);
    addEdge(&g, 3, 4);

    bfs(&g, 0);
    dfs(&g, 0);
    return 0;
}
