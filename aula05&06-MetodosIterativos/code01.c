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

double *Jacobi(double **A, int m, int n, double *x0){
    int i,j;
    double *x, sum=0;

    x = (double *)malloc(m*sizeof(double));

    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            if(j!=i){ sum = sum + A[i][j]*x0[j]; }
        }
        x[i] = (A[i][m]-sum)/A[i][i];
        sum = 0;
    }

    return x;
}

double normdiff(double *x0, double *x1, int m){

    int i;
    double norm=0, dx;

    for(i=0;i<m;i++){
        dx = fabs(x1[i]-x0[i]);
        if(dx>norm) norm = dx;
    }

    return norm;

    //TESTAR DEPOIS
    //double norm1 = 0, norm2 = 0;
    //int i;
    //for(i=0;i<m;i++){
    //    norm1 = norm1 + x0[i]*x0[i];
    //    norm2 = norm2 + x1[i]*x1[i];
    //}
    //return (sqrt(norm2) - sqrt(norm1));
}

int main(int argc, char **argv)
{
    int m,n,i;
    double **M, *x0, *x1, dx, tolerance=1e-8;

    m = atoi(argv[1]);
    n = atoi(argv[2]);
    M = LeMatrix(m,n);
    ImprimeMatriz(M,m,n);   

    x0 = (double *) malloc(m*sizeof(double));
    for(i=0;i<m;i++) scanf("%lf", &x0[i]);

    do{
        x1 = Jacobi(M,m,n,x0);
        dx = normdiff(x0,x1,m);

        memcpy(x0,x1,m*sizeof(double)); //copia o novo conteudo de x1 para x0;
        printf("%.2g\n",dx);
    }while(dx > tolerance);

    return 0;
}