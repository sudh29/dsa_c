#include <stdio.h>

#define MAX_V 10

void topoSort(int V, const int adj[][MAX_V], const int deg[], int topo[], int *topoLen) {
    int inDegree[MAX_V] = {0};
    for (int u = 0; u < V; u++) {
        for (int i = 0; i < deg[u]; i++) {
            inDegree[adj[u][i]]++;
        }
    }

    int q[MAX_V];
    int front = 0, rear = 0;
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) q[rear++] = i;
    }

    *topoLen = 0;
    while (front < rear) {
        int u = q[front++];
        topo[(*topoLen)++] = u;

        for (int i = 0; i < deg[u]; i++) {
            int v = adj[u][i];
            inDegree[v]--;
            if (inDegree[v] == 0) q[rear++] = v;
        }
    }
}

int main(void) {
    int V = 6;
    int adj[MAX_V][MAX_V] = {0};
    int deg[MAX_V] = {0};

    adj[5][deg[5]++] = 2;
    adj[5][deg[5]++] = 0;
    adj[4][deg[4]++] = 0;
    adj[4][deg[4]++] = 1;
    adj[2][deg[2]++] = 3;
    adj[3][deg[3]++] = 1;

    int topo[MAX_V];
    int len = 0;
    topoSort(V, adj, deg, topo, &len);

    printf("Topological Sort order: ");
    for (int i = 0; i < len; i++) printf("%d ", topo[i]);
    printf("\n");
    return 0;
}
