#include <stdio.h>
#include <stdbool.h>

#define MAX_V 10

void bfsOfGraph(int V, const int adj[][MAX_V], const int deg[]) {
    (void)V;
    bool visited[MAX_V] = {false};
    int q[MAX_V];
    int front = 0, rear = 0;

    q[rear++] = 0;
    visited[0] = true;

    printf("BFS Traversal: ");
    while (front < rear) {
        int u = q[front++];
        printf("%d ", u);

        for (int i = 0; i < deg[u]; i++) {
            int v = adj[u][i];
            if (!visited[v]) {
                visited[v] = true;
                q[rear++] = v;
            }
        }
    }
    printf("\n");
}

int main(void) {
    int V = 5;
    int adj[MAX_V][MAX_V] = {0};
    int deg[MAX_V] = {0};

    adj[0][deg[0]++] = 1;
    adj[0][deg[0]++] = 2;
    adj[0][deg[0]++] = 3;
    adj[2][deg[2]++] = 4;

    bfsOfGraph(V, adj, deg);
    return 0;
}
