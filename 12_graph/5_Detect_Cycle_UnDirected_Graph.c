#include <stdio.h>
#include <stdbool.h>

#define MAX_V 10

bool dfs(int u, const int adj[][MAX_V], const int deg[], bool visited[], int parent) {
    visited[u] = true;

    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            if (dfs(v, adj, deg, visited, u)) return true;
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

bool isCycle(int V, const int adj[][MAX_V], const int deg[]) {
    bool visited[MAX_V] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, deg, visited, -1)) return true;
        }
    }
    return false;
}

int main(void) {
    int V = 5;
    int adj[MAX_V][MAX_V] = {0};
    int deg[MAX_V] = {0};

    // Cycle: 0-1-2-0
    adj[0][deg[0]++] = 1; adj[0][deg[0]++] = 2;
    adj[1][deg[1]++] = 0; adj[1][deg[1]++] = 2;
    adj[2][deg[2]++] = 0; adj[2][deg[2]++] = 1; adj[2][deg[2]++] = 3;
    adj[3][deg[3]++] = 2; adj[3][deg[3]++] = 4;
    adj[4][deg[4]++] = 3;

    printf("Undirected graph has cycle: %s\n", isCycle(V, adj, deg) ? "YES" : "NO");

    int treeAdj[MAX_V][MAX_V] = {0};
    int treeDeg[MAX_V] = {0};
    treeAdj[0][treeDeg[0]++] = 1;
    treeAdj[1][treeDeg[1]++] = 0; treeAdj[1][treeDeg[1]++] = 2;
    treeAdj[2][treeDeg[2]++] = 1;

    printf("Undirected tree has cycle: %s\n", isCycle(3, treeAdj, treeDeg) ? "YES" : "NO");
    return 0;
}
