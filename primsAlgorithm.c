#include<stdio.h>
#include<stdlib.h>
#define vertices 6

void primsAlgorithm(int [vertices][vertices], int);

int extractMin(int [],int []);

void printMinSpanTree(int [], int [], int);

int main(){

    int source, graph[vertices][vertices] =
    {
        {-10, 31, 42, -10, -10, -10},
        {31, -10, 23, 73, 42, -10 },
        {42, 23, -10, 51, -10, -10},
        {-10, 73, 51, -10, 23, 12},
        {-10, 42, -10, 23, -10, 65},
        {-10, -10, -10, 12, 65, -10}
    };
    printf("\nEnter the starting vertex: \t");
    scanf("%d", &source);
    printf("\n");
    if(source >= vertices || source < 0)
        printf("Vertex not found\n");
    else
    primsAlgorithm(graph, source);

    return 0;
}
int extractMin(int key[], int queue[]){
    int min = 999;
    int min_index, v;
    for(v = 0; v < 6; v++){
        if(queue[v] == 1 && key[v] < min){
            min = key[v];
            min_index = v;
        } 
    }
    return min_index;
}
void primsAlgorithm(int graph[vertices][vertices], int source){
    int i = 0, u, v, queue[vertices], key[vertices], parent[vertices];
    for(u = 0; u < vertices; u++){
        key[u] = 999;
        queue[u] = 1;
    }
    key[source] = 0;
    parent[source] = -1;
    while(i < (vertices-1)){
        u = extractMin(key, queue);
        queue[u] = 0;
        for(v = 0 ; v < vertices; v++){
            if(graph[u][v] != -10 && queue[v] == 1 && graph[u][v] < key[v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
        i++;
    }
    printMinSpanTree(parent, key, source);    
}
void printMinSpanTree(int parent[], int key[], int source){
    int i;
    printf("Edge \t\t Weight\n");
    for(i = 0; i < vertices; i++){
        if(i == source)
            printf("Source Vertex \t %d\n",key[i]);
        else
        printf("%d -> %d \t\t %d\n",parent[i], i, key[i]);
    }
    printf("\n");


}
