#include <stdio.h>

#define MAX_V 20

void minimumTime(int n, const int edges[][2], int m, int time[]) {
    (void)m;
    int adj[MAX_V][MAX_V] = {0};
    int deg[MAX_V] = {0};
    int inDegree[MAX_V] = {0};

    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][deg[u]++] = v;
        inDegree[v]++;
    }

    int q[MAX_V];
    int front = 0, rear = 0;
    for (int i = 1; i <= n; i++) {
        time[i] = 0;
        if (inDegree[i] == 0) {
            q[rear++] = i;
            time[i] = 1;
        }
    }

    while (front < rear) {
        int u = q[front++];
        for (int i = 0; i < deg[u]; i++) {
            int v = adj[u][i];
            inDegree[v]--;
            if (inDegree[v] == 0) {
                time[v] = time[u] + 1;
                q[rear++] = v;
            }
        }
    }
}

int main(void) {
    int n = 10, m = 13;
    int edges[13][2] = {
        {1, 3}, {1, 4}, {1, 5}, {2, 3}, {2, 8}, {2, 9},
        {3, 6}, {4, 6}, {4, 8}, {5, 8}, {6, 7}, {7, 8}, {8, 10}
    };

    int time[MAX_V];
    minimumTime(n, edges, m, time);

    printf("Minimum time taken by jobs 1..%d:\n", n);
    for (int i = 1; i <= n; i++) {
        printf("Job %d: %d unit(s)\n", i, time[i]);
    }
    return 0;
}
