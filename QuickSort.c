#include<stdio.h>
int partition(int arr[],int,int);
void quickSort(int arr[],int,int);
int main(){
	int low=0,arr[]={86,76,54,90,4,3,6,8,99,44};
	int i,size=sizeof(arr)/sizeof(arr[0]);
	printf("\nUnsorted array elements are:\t");
	for(i=0;i<size;i++){
		printf("%d\t",arr[i]);
	}
	quickSort(arr,low,size-1);
	printf("\nSorted array elements are:\t");
	for(i=0;i<size;i++){
		printf("%d\t",arr[i]);
	}
	
}
void quickSort(int arr[],int low,int high){
	if(low<high){
		int pi = partition(arr,low,high);
		quickSort(arr,low,pi-1);
		quickSort(arr,pi+1,high);
	}
}
int partition(int arr[],int low,int high){
	int temp,i=(low-1),j,pivot=arr[high];
	for(j=low;j<high;j++){
		if(arr[j]<=pivot){
			i++;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp=arr[i+1];
			arr[i+1]=arr[high];
			arr[high]=temp;
	return (i+1);	
}
