#include <stdio.h>
#define capacity 5
#define n 4
void Zero1knapsack(int [], int []);
void itemSelection(int [n+1][capacity+1], int []);
int main(){
    int profit[] = {3, 4, 5, 6};
    int weight[] = {2, 3, 4, 5};
    Zero1knapsack(profit, weight);    
}
void Zero1knapsack(int profit[], int weight[]){
    int i, j, T[n+1][capacity+1];
    for(i = 0; i <= n; i++){
            T[i][0] = 0;
    }
    for(j = 0; j <= capacity; j++){
            T[0][j] = 0;
        }
    for(i =  1; i <= n; i++){
        for(j = 1; j <= capacity; j++){
            if(j < weight[i-1]){
                T[i][j] = T[i-1][j];
            }else{
                if(T[i-1][j] <= (profit[i-1]+T[i-1][j-weight[i-1]])){
                    T[i][j] =  (profit[i-1]+T[i-1][j-weight[i-1]]);
                }else{
                    T[i][j] = T[i-1][j];
                }
            }
        }
    }
    for(i = 0; i <= n; i++){
        for(j = 0; j <= capacity; j++){
            printf("%d\t",T[i][j]);
        }
        printf("\n");
    }
    printf("Maximum profit is: %d\n",T[n][capacity]);
       itemSelection(T, weight);
}
void itemSelection(int T[n+1][capacity+1], int weight[]){
    int i = n, j = capacity, solution_vector[n] = {0,0,0,0};
    while(i > 0 && j > 0){
        if(T[i][j] != T[i-1][j]){
            solution_vector[i] = 1;
            printf("item %d selected\n",i);
            i--;
            j = j - weight[i];
        }
        else{
            i--;
        }
    }
    printf("Solution vector is as follows:\t");
    for(i = 0; i < n; i++){
        printf("%d\t",solution_vector[i]);
    }
    
}