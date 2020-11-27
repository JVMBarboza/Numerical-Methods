#include <stdio.h>
#include <stdlib.h>

#define N 3

void prodVetorMatrix( double x[N], double r[], double M[][N]){
    int i,j;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            r[i] = r[i] + x[j]*M[j][i];
        }
    }
}