#include<stdio.h>
#include<stdlib.h>
int main(){
	int *p,n,i,j,temp;
	printf("\nHow many elements do you want to store:\t");
	scanf("%d",&n);
	p=(int *)malloc(sizeof(n));
	printf("\nInsert elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",(p+i));
	}
	printf("\n Elements in the unsorted array are:\t");
	for(i=0;i<n;i++){
		printf("%d\t",*(p+i));
}
for(i=0;i<n;i++){
	for(j=0;j<n-i-1;j++){
		if(*(p+j)<*(p+j+1)){
			temp=*(p+j);
			*(p+j)=*(p+j+1);
			*(p+j+1)=temp;
		}
	}
}
printf("\n Elements in the sorted array are:\t");
	for(i=0;i<n;i++){
		printf("%d\t",*(p+i));
}
}
