///////////////////////////////////////////
// Testes realizado com uso da matriz:   //
//        5   5  1 106.8                 //
//        64  8  1 177.2                 //
//        144 12 1 279.2                 //                  
///////////////////////////////////////////

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


double *resolveLyB(double **L, double **M, int m){
    int i,countSolved=0;
    double *B,*y;

    B = malloc(m*sizeof(double *));
    y = malloc(m*sizeof(double *)); 

    for(i=0;i<m;i++){ 
      B[i] = M[i][m]; 
      printf("B[%i]:%g\n",i,B[i]); 
    }

    do{
        y[countSolved] = B[countSolved];
        if(countSolved != 0){
            for(i=0;i<countSolved;i++){
                y[countSolved] = y[countSolved] - L[countSolved][i]*y[i];
            }
        }
        countSolved++;
    }while(countSolved != m);

    return y;
}

double *resolveUxY( double **U, double *y, int m) {
    int i=m-1,j=m-1,k,coefPAR=m-1,countSolved=0,ans=0;
    double *x;

    x = malloc( m*sizeof(double)); //guardará os valores de x1,x2,...,xm;
    //for(k=0;k<m;k++) x[k] = 0; //apenas para evitar o produto valor*valorNaoAtribuidoAinda

    do{
        if (countSolved==0) //primeiro coef a ser resolvido
            x[coefPAR] = y[i]/U[i][j];
            
        else{

            for(k=countSolved;k>0;k--){
              ans = ans + U[i][j+k]*x[j+k];
            }

            x[coefPAR] = (y[i] - ans)/U[i][j];
        }

        i--;j--;
        countSolved++;
        coefPAR--;
        ans=0;

    }while(countSolved != m);

    return x;
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

void multiplicaMatrizComVetor( double **matriz, double *vetor, int m){
  int i,j,k;
  double sum=0;

  printf("\n");

  for(i=0;i<m;i++){
    for(j=0;j<m;j++){ sum = sum + matriz[i][j]*vetor[j]; }
    printf("%g\n",sum);
    sum = 0;
  }

}


int main(int argc, char **argv)
{
  int m,n,i,j,p;
  double **M, **L, **U, *y, *x;
  
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
  y = resolveLyB(L,M,m);
  x = resolveUxY(U,y,m);
  printf("As raizes do sistema são :\n");
  for (i=0; i<m; i++) printf("x%1d = %6.2g\n",i,fabs(x[i]));
  multiplicaMatrizComVetor(M,x,m);
  
  return 0;
}