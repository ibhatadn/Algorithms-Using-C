#include<stdio.h>
void fractionalKnapsack(float [],float [], float, int);
int main(){
    float weight[] = {1, 2, 4, 5, 1, 3, 7};              
    float profit[] = {6, 10, 18, 15, 3, 5, 7};    
    
    // float weight[] = {10, 20, 30};
    // float profit[] = {60, 100, 120};                 //Commented out different inputs to the Fractional knapsack 
                                                        //function so i can understand the working properly
    // float weight[] = {30};                           
    // float profit[] = {500};                                                 
    
    float capacity;
    int items = sizeof(profit)/sizeof(profit[0]);
    printf("\n Capacity: \t");
    scanf("%f", &capacity);
    fractionalKnapsack(weight, profit, capacity, items);
    return 0;
}
void fractionalKnapsack(float weight[], float profit[], float capacity, int items){
    float solution_vector[items], max_profit = 0;
    int i,j;
    for(i = 0; i < items; i++)
        solution_vector[i] = 0.0;
    
    for(i = 0; i < items; i++){
        if(weight[i] < capacity){
            solution_vector[i] = 1.0; 
            max_profit = max_profit + profit[i];
            capacity = capacity - weight[i];
        }
        else{
            solution_vector[i] = (capacity/weight[i]);
            max_profit =  max_profit + profit[i] * (capacity / weight[i]);
            break;
                }
 }
    printf("\n Solution Vector is as follows: \t");
    for(j = 0; j <= i ; j++ )
        printf("%f\t",solution_vector[j]);

    printf("\n The maximum profit is as follows: \t");
    printf("%f", max_profit);
}
