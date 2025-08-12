#include<stdio.h>
#define n 3
void floydwarshells(int [n][n]);
int main(){
    int cost[n][n] = {
        {0, 4, 11},
        {6, 0, 2},
        {3, 999999, 0}
    };
    floydwarshells(cost);
    return 0;
}
void floydwarshells(int cost[n][n]){
    int i, j, k, p=1;
    int A[n][n];
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            A[i][j] = cost[i][j];
        }
    }
    
    for(k = 0; k < n; k++){
        printf("\nPath taken:\n");
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if((A[i][k] + A[k][j]) >= A[i][j]){
                    printf("%d ---> %d\t\t", i, j);
                    A[i][j] = A[i][j];
                }
                else{
                    printf("%d ---> %d ---> %d\t\t", i, k, j);
                    A[i][j] = (A[i][k] + A[k][j]);
                }
            }
            printf("\n");
        }
        printf("\nCorresponding values of A^%d are:\n",p);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d\t\t\t",A[i][j]);
        }
        printf("\n");
    }
    p++;
}
}