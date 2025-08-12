#include<stdio.h>

void mcm(int [], int);

int main(){
    int p[] = {30, 35, 15, 5, 10, 20, 25};
    int n = sizeof(p)/sizeof(p[0]);
    mcm(p, n);
    return 0;
}

void mcm(int p[],int n){
    int m_table[n][n], k_table[n][n], i, j, k, plen, t;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            m_table[i][j] = 0;
            k_table[i][j] = 0; 
        }
    }    
    for(plen = 2; plen <= n; plen++){
        for(i = 1; i <= n-plen+1; i++){
        j = i+plen-1;
        m_table[i][j] = 9999999;
        for(k = i; k <= j-1; k++){
            t = m_table[i][k] + m_table[k+1][j] + p[i-1] * p[k] *p[j];
            if(t < m_table[i][j]){
                m_table[i][j] = t;
                k_table[i][j] = k;
            } 
        }
        }
    }
    printf("M-table contents are: \n");
    for(i = 1; i < n; i++){
        for(j = 1; j < n; j++){
            printf("%d\t", m_table[i][j]);
        }
        printf("\n");
    }
    printf("K-table contents are: \n");
        for(i = 1; i < n; i++){
            for(j = 1; j < n; j++){
                printf("%d\t", k_table[i][j]);
        }
    printf("\n");
        }
    printf("Minimum number of multiplications is: %d",m_table[1][n-1]);

}
 