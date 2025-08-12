#include<stdio.h>  
  
void countSort(int a[], int n)   
{  
   int output[n+1];  
   int max = a[0],i;  
   for(i = 1; i<n; i++) {  
      if(a[i] > max)  
         max = a[i];  
   } 
   int count[max+1];
  
  
  for (i = 0; i <= max; ++i)   
  {  
    count[i] = 0;   
  }  
    
  for (i = 0; i < n; i++)   
  {  
    count[a[i]]++;  
  }  
  
   for(i = 1; i<=max; i++)   
      count[i] += count[i-1];  
  for (i = n - 1; i >= 0; i--) {  
    output[count[a[i]] - 1] = a[i];  
    count[a[i]]--;   
}  
  
   for(i = 0; i<n; i++) {  
      a[i] = output[i];   
   }  
}  
  
void printArr(int a[], int n)   
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
}  
  
int main() {  
    int a[] = { 11, 30, 24, 7, 31, 16, 01, 06 };  
    int n = sizeof(a)/sizeof(a[0]);  
    printf("Before sorting array elements are - \n");  
    printArr(a, n);  
    countSort(a, n);  
    printf("\nAfter sorting array elements are - \n");    
    printArr(a, n);  
    return 0;  
  
}  
