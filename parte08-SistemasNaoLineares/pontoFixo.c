#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3

double f1(double x[N]){ return( cos(x[1]*x[2])/3. + (1./6.) ); }
double f2(double x[N]){ return( sqrt( x[0]*x[0] + sin(x[2]) + 1.06)/9. - 0.1 ); }
double f3(double x[N]){ return( -(1./20.)*exp(-x[0]*x[1]) - (10*M_PI-3)/60 ); }

int main(int argc, int **argv){

    int m,n,i,itera=0;
    double norma, tol=1e-8;

    double x[N] = {0},xa;

    double (*equacao[N])() = {f1,f2,f3};

    do{
        norma = 0;
        printf("%d ", itera);

        for(i=0;i<N;i++){
            xa = x[i];
            x[i] = equacao[i](x);
            xa = fabs(xa-x[i]);
            norma = ( norma > xa ) ? xa: norma;
            printf("%lf", x[i]); 
        }
        itera++;
        printf(" e=%.3g\n", norma);

    }while(norma > tol);

    return 0;
}