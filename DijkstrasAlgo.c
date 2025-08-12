#include<stdio.h>
#include<stdlib.h>
#define vertices 5
int  key[vertices], status_queue[vertices], parent[vertices];
void relax(int [vertices][vertices], int, int);
void dijkstrasAlgo(int [vertices][vertices], int);
int extractmin();
void printSpp(int);
int main(){
    int source;
    int graph[vertices][vertices] = 
{
    {-10, 35, 22, -10, -10},
    {-10, -10, -10, 15, -10},
    {-10, 19, -10, 34, 17},
    {-10, -10, -10, -10, -10},
    {31, -10, -10, 26, -10}
};
    printf("From which vertex do you want to start:\t");
    scanf("%d", &source);
    (source > vertices)? printf("Invalid vertex") : dijkstrasAlgo(graph, source);

    return 0;

}
void relax(int graph[vertices][vertices], int u , int v ){
    
    if(key[v] > key[u] + graph[u][v]){
        key[v] = key[u] + graph[u][v];
        parent[v] = u;
    }

}

int extractmin(){
    int min = 999;
    int v, min_index;
    for(v = 0; v < vertices; v++){
        if(status_queue[v] == 1 && key[v] < min){
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
} 
void dijkstrasAlgo(int graph[vertices][vertices],int source){
    int v, u, i = 0;
    for(u = 0; u < vertices; u++){
        key[u] = 999;
        parent[u] = -1;
        status_queue[u] = 1;
    }
    key[source] = 0;
    while(i < vertices){
        u = extractmin();
        status_queue[u] = 0;
        for(v = 0; v < vertices; v++){
            if(graph[u][v] != -10 && status_queue[v] == 1){
                relax(graph, u, v);
            }
        }
        i++;
    }
    printSpp(source);

}
void printSpp(int source){
    int i;
    printf("\nEdge \t\t\t  Weight\n");
    for(i = 0; i < vertices; i++){
        if(i == source){
            printf("Source-vertex: %d \t  %d\n",source,key[i]);
        }
        else if(key[i] == 999){
            printf("%d -> %d \t\t  Infinite (Unreachable)\n", parent[i], i);
        }
        else
        printf("%d -> %d \t\t\t  %d\n",parent[i],i,key[i]);
    }
}