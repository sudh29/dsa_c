#include <stdio.h>
#include <stdbool.h>

#define MAX_V 10

bool dfs(int u, const int adj[][MAX_V], const int deg[], bool visited[], bool recStack[]) {
    visited[u] = true;
    recStack[u] = true;

    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            if (dfs(v, adj, deg, visited, recStack)) return true;
        } else if (recStack[v]) {
            return true;
        }
    }

    recStack[u] = false;
    return false;
}

bool isCyclic(int V, const int adj[][MAX_V], const int deg[]) {
    bool visited[MAX_V] = {false};
    bool recStack[MAX_V] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, deg, visited, recStack)) return true;
        }
    }
    return false;
}

int main(void) {
    int V = 4;
    int adj[MAX_V][MAX_V] = {0};
    int deg[MAX_V] = {0};

    adj[0][deg[0]++] = 1;
    adj[1][deg[1]++] = 2;
    adj[2][deg[2]++] = 3;
    adj[3][deg[3]++] = 1; // Cycle: 1->2->3->1

    printf("Directed graph contains cycle: %s\n", isCyclic(V, adj, deg) ? "YES" : "NO");

    int acyclicAdj[MAX_V][MAX_V] = {0};
    int acyclicDeg[MAX_V] = {0};
    acyclicAdj[0][acyclicDeg[0]++] = 1;
    acyclicAdj[1][acyclicDeg[1]++] = 2;

    printf("Acyclic graph contains cycle: %s\n", isCyclic(3, acyclicAdj, acyclicDeg) ? "YES" : "NO");
    return 0;
}
