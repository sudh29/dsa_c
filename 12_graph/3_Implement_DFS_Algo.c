#include <stdio.h>
#include <stdbool.h>

#define MAX_V 10

void dfsUtil(int u, bool visited[], const int adj[][MAX_V], const int deg[]) {
    visited[u] = true;
    printf("%d ", u);

    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            dfsUtil(v, visited, adj, deg);
        }
    }
}

void dfsOfGraph(int V, const int adj[][MAX_V], const int deg[]) {
    (void)V;
    bool visited[MAX_V] = {false};
    printf("DFS Traversal: ");
    dfsUtil(0, visited, adj, deg);
    printf("\n");
}

int main(void) {
    int V = 5;
    int adj[MAX_V][MAX_V] = {0};
    int deg[MAX_V] = {0};

    adj[0][deg[0]++] = 1;
    adj[0][deg[0]++] = 2;
    adj[0][deg[0]++] = 4;
    adj[1][deg[1]++] = 0;
    adj[2][deg[2]++] = 0;
    adj[3][deg[3]++] = 4;
    adj[4][deg[4]++] = 0;
    adj[4][deg[4]++] = 3;

    dfsOfGraph(V, adj, deg);
    return 0;
}
