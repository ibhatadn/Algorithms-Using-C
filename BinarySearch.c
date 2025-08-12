#include<stdio.h>
#include<stdlib.h>

int binarySearch(int arr[],int low,int high,int x);
int main(){
	int arr[]={1,5,6,8,10,15,17,18,35,54,65,76,89,100,190},x,n;
	n=sizeof(arr)/sizeof(arr[0]);
	int result=binarySearch(arr,0,n-1,18);
	if(result==-1)
	printf("\nNumber not found\n");
	else
	printf("\nNumber found at index : %d\n",result);
}
int binarySearch(int arr[],int low,int high,int x){
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]==x)
		return mid;
		if(arr[mid]<x)
		low=mid+1;
		else
		high=mid-1;
	}
	return -1;
}
