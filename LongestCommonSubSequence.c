#include<stdio.h>
#include<string.h>

void lcs(char [], char[]);
int main(){
    char A[20], B[20];
    printf("\nEnter the first string: ");
    scanf("%s", A);
    printf("Enter the second string: ");
    scanf("%s", B);
    lcs(A,B);
    return 0;
}
void lcs(char A[], char B[]){
    int  lenA = strlen(A), lenB = strlen(B), i, j, k=0;
    int c[lenA+1][lenB+1];
    char dir[lenA+1][lenB+1], result[20];
    for(i = 0; i <= lenA; i++){
        c[i][0] = 0;
    }
    for(j = 0; j <=lenB; j++){
         c[0][j] = 0;   
        }
    for(i = 1; i <= lenA; i++){
        for(j = 1; j <= lenB; j++){
            if(A[i-1] == B[j-1]){
                c[i][j] = c[i-1][j-1]+1;
                dir[i][j] = 'd'; 
            }
            else if(c[i][j-1] > c[i-1][j]){
                c[i][j] = c[i][j-1];
                dir[i][j] = 'h';
            }
            else{
                c[i][j] = c[i-1][j];
                dir[i][j] = 'v';
            }
        }
    }
    printf("\nContents of the dir matrix are: \n");
        for(i=1;i<=lenA;i++){
        for(j=1;j<=lenB;j++){
        printf("%c\t",dir[i][j]);
        }
        printf("\n");
        }
    printf("\nContents of the c matrix are: \n");
        for(i=1;i<=lenA;i++){
        for(j=1;j<=lenB;j++){
        printf("%d\t",c[i][j]);
        }
        printf("\n");
        }
        i = lenA, j = lenB;
        while(i != 0){
            if(dir[i][j] == 'd'){
                result[k] = A[i-1];
                k++; i--; j--; 
            }
            else if(dir[i][j] == 'h'){
                j--;
            }
            else{
                i--;
            }
        }
        printf("The Longest Common Sub Sequence between two strings is: \t");
        for(i = k-1; i >= 0; i--)
        printf("%c", result[i]);
}