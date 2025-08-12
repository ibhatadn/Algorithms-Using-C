
#include <stdio.h>
#include <limits.h>

#define V 10

int tsp(int graph[V][V], int v[], int pos, int n, int count, int cost, int *minCost) {
    if (count == n && graph[pos][0]) {
        if (cost + graph[pos][0] < *minCost) {
            *minCost = cost + graph[pos][0];
        }
        return *minCost;
    }

    for (int i = 0; i < n; i++) {
        if (v[i] == 0 && graph[pos][i]) {
            v[i] = 1;
            tsp(graph, v, i, n, count + 1, cost + graph[pos][i], minCost);
            v[i] = 0;
        }
    }
    return *minCost;
}

int main() {
    int n, graph[V][V];
    printf("Enter number of cities: ");
    scanf("%d", &n);
    printf("Enter cost adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int v[V] = {0};
    v[0] = 1;
    int minCost = INT_MAX;

    tsp(graph, v, 0, n, 1, 0, &minCost);
    printf("Minimum cost: %d\n", minCost);
    return 0;
}
