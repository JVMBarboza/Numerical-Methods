#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double **LeMatrix(int m, int n) {
  double **M;
  int i,j;
  
  M = malloc ( m*sizeof(double *) );
  for ( i = 0; i < m; i++ ) M[i] = malloc( n*sizeof(double));
  
  for ( i = 0; i < m; i++ ) {
    for ( j = 0; j < n; j++ ) {
        scanf("%lf", &M[i][j]);
    }  
  }
  return M;
}

void ImprimeMatriz(double **M, int m, int n) {
  int i,j;
  
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("%5.2lf ",M[i][j]);
    }
    puts("");
  }
  puts("");
}

double dotProduct(double *a, int m, double *b){
    int i;
    double dot = 0;

    for(i=0;i<m;i++){ dot += a[i]*b[i]; }

    return dot;
}

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

double norma(double *r, int m){
    int i;
    double ri, norm = 0;

    for(i=0; i<m; i++){
        ri = fabs(r[i]);
        norm = (ri > norm) ? ri:norm;
    }
    return norm;
}

double *gradienteConjugado(double **A, int m, double *x, double *r, double *d){
    
    int i;
    double alpha, denominador, numerador;

    numerador = dotProduct(r,m,d);
    denominador = dotProduct(prodMatrixVetor(A,m,d),m,d); 
    alpha = numerador/denominador;

    for(i=0; i<m; i++){
        x[i] = x[i] + (alpha*d[i]);
    }

    return x;
}

double *update(double **A, double *d, int m, double *r){
    int i;
    double beta;

    beta = dotProduct(prodMatrixVetor(A,m,r),m,d)/dotProduct(prodMatrixVetor(A,m,d),m,d);

    for(i=0; i<m; i++){
        d[i] = r[i] - (beta*d[i]);
    }

    return d;
}

int main(int argc, char **argv)
{
    int m,n,i,iterations=0;
    double **M, *x0, *r0, *d0, tolerance=1e-8;

    m = atoi(argv[1]);
    n = atoi(argv[2]);
    M = LeMatrix(m,n);
  
    x0 = (double *) malloc(m*sizeof(double));
    for(i=0;i<m;i++) scanf("%lf", &x0[i]);

    r0 = (double *) malloc(m*sizeof(double));
    d0 = (double *) malloc(m*sizeof(double));
    r0 = prodMatrixVetor(M, m, x0);
    for(i=0; i<m; i++){
        r0[i] = M[i][m] - r0[i];
        d0[i] = r0[i];
    }

    while((norma(r0, m)>tolerance)&&iterations<20) {
        x0 = gradienteConjugado(M,m,x0,r0,d0); 
        
        r0 = prodMatrixVetor(M,m,x0);
        for(i=0; i<m; i++){ r0[i] = M[i][m] - r0[i]; }

        d0 = update(M,d0,m,r0);

        iterations++;
        printf("%d ", iterations);
        for(i=0;i<m;i++){ printf("x[%d]=%.6lf   ",i,x0[i]); }
        puts("");
    }
    
    return 0;
}