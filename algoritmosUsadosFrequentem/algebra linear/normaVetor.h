#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double norma(double *r, int m){
    int i;
    double ri, norm = 0;

    for(i=0; i<m; i++){
        ri = fabs(r[i]);
        norm = (ri > norm) ? ri:norm;
    }
    return norm;
}