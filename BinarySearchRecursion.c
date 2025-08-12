#include<stdio.h>
int binarySearch(int arr[],int low,int high,int el);
int main(){
	int low=0,el,arr[]={1,5,6,8,10,15,17,18,35,54,65,76,89};
	int size=sizeof(arr)/sizeof(arr[0]);
	printf("Enter data:\t");
	scanf("%d",&el);
	int result = binarySearch(arr,low,size,el);
	if(arr[result] == el){
		printf("\nData found at index:\t%d\n",result);
	}
	else{
		printf("\nData not found\n");
	}
	return 0;
}
int binarySearch(int arr[],int low,int high,int el){
	if(low<high){
	int mid = (low + high)/2;
	if(arr[mid] == el)
		return mid;
	if(arr[mid] > el)
		binarySearch(arr,low,mid,el);
	else
		binarySearch(arr,mid+1,high,el);
}
}
