#include<stdio.h>
int linearSearch(int [],int,int,int);
int main(){
	
	int low=0,el,arr[]={74,86,36,24,765,345,453,54,78};
	int n=sizeof(arr)/sizeof(arr[0]);
	printf("\nEnter Data:\t");
	scanf("%d",&el);
	int result=linearSearch(arr,low,n-1,el);
	(result==-1)? printf("\nNumber Not found\n")
	:printf("\nNumber found at index \t%d\n",result);
}
int linearSearch(int arr[],int low,int high,int el){
	int i;
	for(i=low;i<high;i++){
		if(arr[i]==el)
		return i;
	}
	return -1;
}

