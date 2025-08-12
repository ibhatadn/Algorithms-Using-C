
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge {
    int u, v, w;
};

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union_set(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal(struct Edge edges[], int n, int e) {
    int i, j, count = 0;
    int cost = 0;
    struct Edge result[MAX];

    for (i = 0; i < n; i++)
        parent[i] = i;

    for (i = 0; count < n - 1 && i < e; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (find(u) != find(v)) {
            result[count++] = edges[i];
            union_set(u, v);
            cost += w;
        }
    }

    printf("\nEdges in the Minimum Spanning Tree:\n");
    for (i = 0; i < count; i++)
        printf("%d -- %d == %d\n", result[i].u, result[i].v, result[i].w);

    printf("Total cost of MST: %d\n", cost);
}

void sort(struct Edge edges[], int e) {
    int i, j;
    struct Edge temp;
    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, e, i;
    struct Edge edges[MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    for (i = 0; i < e; i++) {
        printf("Enter edge %d (u v w): ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    sort(edges, e);
    kruskal(edges, n, e);

    return 0;
}
