#include <stdio.h>
#include <stdbool.h>

static bool isSafe(int v, int V, const int graph[V][V], const int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i])
            return false;
    }
    return true;
}

static bool graphColoringUtil(int V, const int graph[V][V], int m, int color[], int v) {
    if (v == V) return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, V, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(V, graph, m, color, v + 1))
                return true;
            color[v] = 0;
        }
    }
    return false;
}

bool graphColoring(int V, const int graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++) color[i] = 0;
    return graphColoringUtil(V, graph, m, color, 0);
}

int main(void) {
    int V = 4, m = 3;
    int graph[4][4] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    printf("Can graph be colored with %d colors? %s (1)\n",
           m, graphColoring(V, graph, m) ? "Yes" : "No");
    return 0;
}
