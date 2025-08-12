#include<stdio.h>
void selectionSort(int arr[], int n);
int main(){
	
	int arr[] = {9,1,2,5,7,5,3,8,10,11, 20, 130, 50, 159, 70, 18, 29, 101},i;
	int n = sizeof(arr)/sizeof(arr[0]);

	printf("Given array elements are :\n");
		for(i = 0; i < n; i++){
			printf("%d\t", arr[i]);
		}
	selectionSort(arr,n);
	printf("\nSorted array elements are :\n ");
	for(i = 0; i < n; i++){
		printf("%d\t", arr[i]);
	}
	
}


void selectionSort(int arr[], int n){
	int i, j, temp, min;
	
	for(i = 0; i < n-1; i++){
		min = i;
		for(j = i+1; j < n; j++){
		if(arr[min] > arr[j]){
		min = j;
		}
	}
		if(min != i){
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}
