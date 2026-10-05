#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int v;
    int w;
} Edge;

static Edge adj[10][10];
static int adj_sz[10];

static bool pathMoreThanKUtil(int src, int k, bool visited[]) {
    if (k <= 0) return true;
    visited[src] = true;

    for (int i = 0; i < adj_sz[src]; i++) {
        int v = adj[src][i].v;
        int w = adj[src][i].w;

        if (visited[v]) continue;
        if (w >= k || pathMoreThanKUtil(v, k - w, visited)) {
            return true;
        }
    }
    visited[src] = false;
    return false;
}

int main(void) {
    int edges[][3] = {
        {0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11},
        {2, 3, 7}, {2, 8, 2}, {2, 5, 4}, {3, 4, 9},
        {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1},
        {6, 8, 6}, {7, 8, 7}
    };
    int num_edges = sizeof(edges) / sizeof(edges[0]);

    for (int i = 0; i < num_edges; i++) {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        adj[u][adj_sz[u]++] = (Edge){v, w};
        adj[v][adj_sz[v]++] = (Edge){u, w};
    }

    bool visited[10] = {false};
    int K = 60;
    printf("Path of weight >= %d exists from 0: %s (1)\n",
           K, pathMoreThanKUtil(0, K, visited) ? "YES" : "NO");
    return 0;
}
