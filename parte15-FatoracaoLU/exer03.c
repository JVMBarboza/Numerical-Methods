
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

double **MultLinha(double **M, int m, int n, int i, int j, double lbd) {
  
  for (int k=0; k<n; k++) M[j][k] -= M[i][k]*lbd;
  return M;
}

void LU( double **M, double **L, double **U, int m, int n) {
  int i,j,p;
  double lbd;

  for(i=0;i<m;i++){
      for(j=0;j<m;j++){
          L[i][j] = (i==j) ? 1:0;
          U[i][j] = M[i][j];
      }
  }

  for(i=0; i<m-1; i++) {
    if (U[i][i] == 0) {
      p = i; 
      do {
        p++; 
      } while ((U[p][i] == 0)&&(p<m));
      U = TrocaLinhas(M,m,n,i,p);
      if (U[i][i]==0) {
        puts("Sistema sem solução");
        exit(1); 
      }  
    }  
    for(j=i+1; j<m; j++) {
      L[j][i] = U[j][i]/U[i][i];
      U = MultLinha(U,m,n,i,j,L[j][i]);
    }
  }

}


double **resolveLyB(double **L, int m){
    int i,j,k;
    double **B,**y,ans=0;

    B = malloc(m*sizeof(double *));
    for(i=0;i<m;i++) B[i] = malloc(m*sizeof(double *));

    y = malloc(m*sizeof(double *)); 
    for(i=0;i<m;i++) y[i] = malloc(m*sizeof(double *));

    for(i=0; i<m; i++){ 
      for(j=0; j<m; j++){
        if(i==j)
          B[i][j] = 1.0;
        else
          B[i][j] = 0.0;         
        
        printf("B[%i][%i]:%g ",i,j,B[i][j]); 
      }
      printf("\n");
    }

    for(i=0; i<m; i++){
      for(j=0; j<m; j++){
        if(i==0){
          y[i][j] = B[i][j]; //y[0][0] = 1, y[0][1] = 0 e y[0][2] = 0
        }
        else{
          y[i][j] = B[i][j];
          
          for(k=0;k<m;k++){
            if(k!=i){
              ans = ans + L[i][k]*y[k][j]; //y -> já possui valor
            }
          }
          y[i][j] = (y[i][j] - ans);//deveria ter um denominador mas o mesmo sempre será 1
        }
        ans = 0.0;
      }
    }
      
    return y;
}

double **resolveUxY( double **U, double **y, int m) {
    int i=m-1,j=m-1,k;
    double **x,ans=0;

    x = malloc( m*sizeof(double *)); //guardará os valores de x1,x2,...,xm;
    for(i=0;i<m;i++) x[i] = malloc(m*sizeof(double *));
    
    for(i=0;i<m;i++){
      for(j=0;j<m;j++){
        x[i][j] = 0.0;
      }
    }

    for(i=m-1;i>=0;i--){
      for(j=m-1;j>=0;j--){
        
        if (i==m-1){ //primeiro coef a ser resolvido
          x[i][j] = y[i][j]/U[i][i];
        }
        else{
          x[i][j] = y[i][j];
          for(k=m-1;k>=0;k--){
            if(k!=i){
              ans = ans + U[i][k]*x[k][j];
            } 
          }
          x[i][j] = (x[i][j] - ans)/U[i][i]; 
        }
        ans=0;
      }
    }

    return x;
}

double **retornarMultplMatriz(double **matrizA, double **matrizB, int m, int n){
  int i,j,k;
  double sum=0, **matrizResult;

  matrizResult = malloc(m*sizeof(double *));
  for(i=0;i<m;i++) matrizResult[i] = malloc(m*sizeof(double *));
  
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){ 
      matrizResult[i][j] = 0.0;
    }
  }

  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      
      for(k=0;k<m;k++){ matrizResult[i][j] = matrizResult[i][j] + matrizA[i][k]*matrizB[k][j]; }
      
      printf("%g ",matrizResult[i][j]);
      sum = 0;
    }
    puts("");
  }

  return matrizResult;
}

void multiplicaMatrizes( double **matrizA, double **matrizB, int m, int n){
  int i,j,k;
  double sum=0;
  
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      
      for(k=0;k<m;k++){ sum = sum + matrizA[i][k]*matrizB[k][j]; }
      
      printf("%g ",sum);
      sum = 0;
    }
    puts("");
  }

}

int main(int argc, char **argv)
{
  int m,n,i,j,p;
  double **M, **L, **U, **y, **x;
  
  m = atoi(argv[1]);
  n = atoi(argv[2]);
  M = LeMatrix(m,n);
  ImprimeMatriz(M,m,n);

  L = malloc(m*sizeof(double *));
  for(i=0;i<m;i++) L[i] = malloc(m*sizeof(double *));

  U = malloc(m*sizeof(double *));
  for(i=0;i<m;i++) U[i] = malloc(m*sizeof(double *));

  LU(M,L,U,m,n);
  ImprimeMatriz(L,m,m);
  ImprimeMatriz(U,m,m);
  
  y = resolveLyB(L,m);
  ImprimeMatriz(y,m,m);

  x = resolveUxY(U,y,m);
  ImprimeMatriz(x,m,m);

  printf("A inversa da matriz é:\n");
  for (i=0; i<m; i++){
    for(j=0; j<m; j++){
      printf("%6.2g ",x[i][j]);
    }
    printf("\n");
  } 

  multiplicaMatrizes(M,x,m,m);
  
  return 0;
}