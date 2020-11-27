#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3

//PRODUTO ENTRE DOIS VETORES QUE GERA MATRIZ
void OutProduct(double A[], double B[], double r[N][N]){
    int i,j;

    printf("\n'---- IMPRIMINDO OUTPRODUCT ----\n");

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
        
        r[i][j] = r[i][j] + A[i]*B[j];
        
        printf("%g ",r[i][j]);
        }
        puts("");
    }
    puts("");
}