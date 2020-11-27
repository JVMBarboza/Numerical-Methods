#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dotProduct(double *a, int m, double *b){
    int i;
    double dot = 0;

    for(i=0;i<m;i++){ dot += a[i]*b[i]; }

    return dot;
}