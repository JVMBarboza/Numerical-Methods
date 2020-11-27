#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double *prodMatrixVetor(double **M, int m, double *vetor){
    int i,j;
    double *ansVector;

    ansVector = (double *)malloc(m*sizeof(double));

    for(i=0;i<m;i++){ ansVector[i] = 0.0; }

    for(i=0; i<m; i++){
        for(j=0; j<m; j++){
            ansVector[i] += M[i][j]*vetor[j];
        }
    }

    return ansVector;
}