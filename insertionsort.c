#include<stdio.h>
void insertionSort(int arr[],int low,int high);
int main(){
	int i,arr[]={4, 6, 7, 1, 4, 10}, low = 0;
	int n=sizeof(arr)/sizeof(arr[0]);
	printf("The unsorted array elements are:\t");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	insertionSort(arr,low,n-1);
	printf("\nThe sorted array elements are:\t");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}	
}
void insertionSort(int arr[], int low, int high){
	int key,i,j;
	for(i=1;i<high;i++){
		key=arr[i];
		j=i-1;
		while(j>=low && arr[j]>key){
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;	
	}
}
