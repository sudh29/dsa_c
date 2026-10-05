#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int u, v, weight;
} Edge;

static int compareEdges(const void *a, const void *b) {
    const Edge *ea = (const Edge *)a;
    const Edge *eb = (const Edge *)b;
    return ea->weight - eb->weight;
}

typedef struct {
    int parent[20];
    int rank[20];
} DSU;

static void initDSU(DSU *dsu, int n) {
    for (int i = 0; i < n; i++) {
        dsu->parent[i] = i;
        dsu->rank[i] = 0;
    }
}

static int findDSU(DSU *dsu, int i) {
    if (dsu->parent[i] == i) return i;
    return dsu->parent[i] = findDSU(dsu, dsu->parent[i]);
}

static bool uniteDSU(DSU *dsu, int i, int j) {
    int root_i = findDSU(dsu, i);
    int root_j = findDSU(dsu, j);
    if (root_i != root_j) {
        if (dsu->rank[root_i] < dsu->rank[root_j]) {
            int t = root_i; root_i = root_j; root_j = t;
        }
        dsu->parent[root_j] = root_i;
        if (dsu->rank[root_i] == dsu->rank[root_j])
            dsu->rank[root_i]++;
        return true;
    }
    return false;
}

int kruskalMST(int V, Edge edges[], int E) {
    qsort(edges, E, sizeof(Edge), compareEdges);
    DSU dsu;
    initDSU(&dsu, V);
    int mst_weight = 0;
    int edges_count = 0;

    for (int i = 0; i < E; i++) {
        if (uniteDSU(&dsu, edges[i].u, edges[i].v)) {
            mst_weight += edges[i].weight;
            edges_count++;
            if (edges_count == V - 1) break;
        }
    }
    return mst_weight;
}

int main(void) {
    int V = 4;
    Edge edges[5] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    printf("Kruskal's MST weight: %d (expected 19)\n", kruskalMST(V, edges, 5));
    return 0;
}
