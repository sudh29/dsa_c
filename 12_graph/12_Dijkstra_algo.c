#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_V 10

typedef struct {
    int v;
    int weight;
} Edge;

void dijkstra(int V, const Edge adj[][MAX_V], const int deg[], int S, int dist[]) {
    bool visited[MAX_V] = {false};
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;
    dist[S] = 0;

    for (int count = 0; count < V - 1; count++) {
        int minD = INT_MAX, u = -1;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && dist[v] <= minD) {
                minD = dist[v];
                u = v;
            }
        }
        if (u == -1) break;
        visited[u] = true;

        for (int i = 0; i < deg[u]; i++) {
            int v = adj[u][i].v;
            int w = adj[u][i].weight;
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
}

int main(void) {
    int V = 3;
    Edge adj[MAX_V][MAX_V];
    int deg[MAX_V] = {0};

    adj[0][deg[0]++] = (Edge){1, 1};
    adj[0][deg[0]++] = (Edge){2, 6};
    adj[1][deg[1]++] = (Edge){2, 3};
    adj[1][deg[1]++] = (Edge){0, 1};
    adj[2][deg[2]++] = (Edge){1, 3};
    adj[2][deg[2]++] = (Edge){0, 6};

    int dist[MAX_V];
    dijkstra(V, adj, deg, 2, dist);

    printf("Distances from source 2: ");
    for (int i = 0; i < V; i++) printf("%d ", dist[i]);
    printf("\n");
    return 0;
}
