#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int low ,int high);
void mergesort(int arr[],int low ,int mid ,int high);
int main(){
	int arr[]={7,2,4,1,3,6,3,25,65,8},low,high,i,n;
	n=sizeof(arr)/sizeof(arr[0]);
	low=0; 
	high=n-1;
	printf("\nUnsorted array elements are: \n");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	merge(arr,low,high);
	printf("\nSorted array elements are: \n");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}	
}
void merge(int arr[],int low ,int high){
	
	if(low<high){
		int mid=(low+high)/2;
		merge(arr,low,mid);
		merge(arr,mid+1,high);
		mergesort(arr,low,mid,high);
	}
}
void mergesort(int arr[],int low ,int mid ,int high){
	int i=low,j=mid+1,k=low;
	int aux[100];
	while(i<=mid && j<=high){
	if(arr[i]<arr[j]){
		aux[k]=arr[i];
		i++;
		k++;
	}
	else{
		aux[k]=arr[j];
		j++;
		k++;
	}
}
	while(i<=mid){
		aux[k]=arr[i];
		i++;
		k++;
	}
	while(j<=high){
		aux[k]=arr[j];
		j++;
		k++;
	}
for(i=low;i<=high;i++){
		arr[i]=aux[i];
	}
}
