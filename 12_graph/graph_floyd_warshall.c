#include <stdio.h>

#define INF 1000000000LL
#define MAX_V 10

void floydWarshall(long long dist[][MAX_V], int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main(void) {
    int V = 4;
    long long dist[MAX_V][MAX_V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = (i == j) ? 0 : INF;
        }
    }

    dist[0][1] = 5;
    dist[0][3] = 10;
    dist[1][2] = 3;
    dist[2][3] = 1;

    printf("Original distance matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) printf("INF ");
            else printf("%3lld ", dist[i][j]);
        }
        printf("\n");
    }

    floydWarshall(dist, V);

    printf("\nAll-pairs shortest distances (Floyd-Warshall):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) printf("INF ");
            else printf("%3lld ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
