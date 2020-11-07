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

double **TrocaLinhas(double **M,int m, int n, int i, int j) {
  double tmp;
  int k;
  
  for (k=0; k<n; k++) {
    tmp = M[i][k];
    M[i][k] = M[j][k];
    M[j][k] = tmp; 
  }
  return M;
}

void printaNormaDoResiduo(double *resto, int m, int it){
  int i;
  double sum=0;

  for(i=0;i<m;i++) { sum = sum + resto[i]*resto[i]; }

  printf("%i %g\n",it,sqrt(sum));

}

double SOR(double **A, int m, int n, double omega, double *x0, int it){
    int i, j;
    double *x1, *r1, dx=0, norm=0;

    x1 = (double*)malloc(m*sizeof(double));
    r1 = (double *)malloc(m*sizeof(double));

    for(i=0; i<m; i++){ 
      for(j=i+1; j<m; j++){
        if(fabs(A[i][i]) < fabs(A[j][i])){
          A = TrocaLinhas(A,m,m+1,i,j);
        }
      }
    }   

    for(i=0; i<m; i++){
      x1[i] = A[i][m];
    
      for(j=0; j<i; j++){
        x1[i] = x1[i] - A[i][j]*x1[j];
      }
      for(j=i+1; j<m; j++){
        x1[i] = x1[i] - A[i][j]*x0[j];
      }
      r1[i] = x1[i] - A[i][i]*x0[i];
      x1[i] = x1[i]/A[i][i];
    }
    
    printaNormaDoResiduo(r1,m,it);
    
    for(i=0; i<m; i++){
      dx = fabs(x1[i]-x0[i]);
      if (dx > norm) 
      {
        norm = dx;
      }
    }

    for(i=0; i<m; i++){
      x0[i] = (1-omega)*x0[i] + omega*x1[i];
    }
    
    return (norm);
}
    
int main(int argc, char **argv)
{
    FILE *fp;
    
    int m,n,i,t=0;
    double **M, *x0, dx, tolerance=1e-8, omega;

    //fp = fopen("saida.csv","w");

    //fprintf(fp,"it,tolerance\n");

    m = atoi(argv[1]);
    n = atoi(argv[2]);
    omega = atof(argv[3]);
    M = LeMatrix(m,n);
    //ImprimeMatriz(M,m,n);   
  
    x0 = (double *) malloc(m*sizeof(double));
    for(i=0;i<m;i++) scanf("%lf", &x0[i]);

    do{
        dx = SOR(M,m,n,omega,x0,t);
        t++;
        
        //printf("it=%i ",t);
        //for(i=0;i<m;i++) printf(" %lf ",x0[i]);
        //printf("%.2g\n",dx);

        //fprintf(fp,"%i",t);
        //fprintf(fp,",%g\n",dx);
    }while(dx > tolerance);

    //printf("\nSolução:\n");
    //for(i=0;i<m;i++) printf("%lf\t",x0[i]);
    
    return 0;
}