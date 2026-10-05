#include <stdio.h>
#include <stdbool.h>

#define MAX_V 20

void dfs(int u, const int adj[][MAX_V], const int deg[], bool visited[]) {
    visited[u] = true;
    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            dfs(v, adj, deg, visited);
        }
    }
}

int makeConnected(int n, const int connections[][2], int numConnections) {
    if (numConnections < n - 1) return -1;

    int adj[MAX_V][MAX_V] = {0};
    int deg[MAX_V] = {0};

    for (int i = 0; i < numConnections; i++) {
        int u = connections[i][0];
        int v = connections[i][1];
        adj[u][deg[u]++] = v;
        adj[v][deg[v]++] = u;
    }

    bool visited[MAX_V] = {false};
    int components = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            components++;
            dfs(i, adj, deg, visited);
        }
    }
    return components - 1;
}

int main(void) {
    int conn1[3][2] = {{0, 1}, {0, 2}, {1, 2}};
    printf("Minimum operations to make connected (n=4): %d (expected 1)\n",
           makeConnected(4, conn1, 3));

    int conn2[5][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
    printf("Minimum operations (n=6): %d (expected 2)\n",
           makeConnected(6, conn2, 5));
    return 0;
}
