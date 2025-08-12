#include <stdio.h>
void fcfs(int bt[], int n){
    int i, wt[n], tat[n];
    wt[0] = 0;
    for(i=1;i<n;i++)
    wt[i] = wt[i-1]+bt[i-1];
    for(i=0;i<n;i++)
    tat[i] = bt[i]+wt[i];
    printf("pid \t bt \t tat \t wt\n");
    for(i=0;i<n;i++)
    printf("\n%d \t %d \t %d \t %d\n",i+1,bt[i],tat[i],wt[i]);
}
int main(){
    int n=4, bt[]={5,7,4,8};
    fcfs(bt, n);
    return 0;
}