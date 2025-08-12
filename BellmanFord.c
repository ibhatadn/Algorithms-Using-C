
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 99999

struct Edge {
    int u, v, w;
};

int main() {
    int n, e, i, j;
    struct Edge edges[MAX];
    int dist[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (i = 0; i < e; i++) {
        printf("Enter edge (u v w): ");
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    for (i = 0; i < n; i++) dist[i] = INF;
    dist[src] = 0;

    for (i = 1; i < n; i++) {
        for (j = 0; j < e; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for (j = 0; j < e; j++) {
        if (dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
            printf("Graph contains a negative weight cycle\n");
            return 0;
        }
    }

    printf("Vertex Distance from Source:\n");
    for (i = 0; i < n; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }

    return 0;
}
