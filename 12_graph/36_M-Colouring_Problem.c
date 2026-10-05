#include <stdio.h>
#include <stdbool.h>

#define MAX_V 10

bool isValid(int node, const int graph[][MAX_V], const int color[], int c, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[node][i] && color[i] == c) return false;
    }
    return true;
}

bool solve(int node, int m, int color[], const int graph[][MAX_V], int V) {
    if (node == V) return true;

    for (int c = 1; c <= m; c++) {
        if (isValid(node, graph, color, c, V)) {
            color[node] = c;
            if (solve(node + 1, m, color, graph, V)) return true;
            color[node] = 0; // backtrack
        }
    }
    return false;
}

bool graphColoring(const int graph[][MAX_V], int m, int V) {
    int color[MAX_V] = {0};
    return solve(0, m, color, graph, V);
}

int main(void) {
    int V = 4;
    int m = 3;
    int graph[MAX_V][MAX_V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    printf("Can graph be colored with %d colors: %s\n",
           m, graphColoring(graph, m, V) ? "1" : "0");
    return 0;
}
