////////////////////////////////////////////////
//  Teste realizado com uso das matrizes:     //
//     4  0   0  0       1 1 -1  1            //
//     6  7   0  0       1 2 -4 -2            //
//     9  11  1  0       2 1  1  5            //
//     5  4   1  1      -1 0 -2 -4            //
//   m = 4 e n=4;                             //
////////////////////////////////////////////////

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

double **MultLinha(double **M, int m, int n, int cima, int baixo, double lbd) {
  
  for (int k=0; k<2*n; k++) M[baixo][k] = M[baixo][k] - M[cima][k]*lbd;
  return M;
}

double **Pivotamento(double **M, int m, int n) {
  int i,j,l,key,maiorPos;
  double lbd, maior,**Mext;

  Mext = malloc ( m*sizeof(double *) );
  for ( i = 0; i < m; i++ ) Mext[i] = malloc( 2*n*sizeof(double) );

  for(i=0; i<m ; i++){
    for(j=0; j<n; j++){
      Mext[i][j] = M[i][j];
    }
  }

  for(i=0; i<m ; i++){
    for(j=n; j<2*n; j++){
      if(j == m+i){
        Mext[i][j] = 1;
      }
      else{
        Mext[i][j] = 0;
      }
    }
  }    

  printf("Matriz Extendida antes do Pivotamento:\n");
  for(i=0; i<m ; i++){
    for(j=0; j<2*n; j++){
      printf("%g ",Mext[i][j]);
    }
    puts("\n");
  }

  i=0;
  j=0;

  while(i<m-1 && j<n-1) {

    maior    = fabs(Mext[i][j]);
    maiorPos = i;

    for(l=i+1;l<m;l++){
      if(Mext[l][j] > maior){
        maior    = fabs(Mext[l][j]);
        maiorPos = l;
      }
    }

    Mext = TrocaLinhas(Mext,m,n,maiorPos,i);

    for(l=i+1; l<m; l++) {
      lbd = Mext[l][j]/Mext[i][j];
      Mext = MultLinha(Mext,m,n,i,l,lbd);
    }
    
    i++;
    j++;
  }

  printf("Matriz Extendida depois do Pivotamento:\n");
  for(i=0; i<m ; i++){
    for(j=0; j<2*n; j++){
      printf("%g ",Mext[i][j]);
    }
    puts("\n");
  }

  return Mext;   
}

double *SubstituicaoReversa( double **M, int m, int n){ 
    int i=m-1,j=n-2,k,coefPAR=m-1,countSolved=0,ans=0;
    double *coef;

    coef = (double *) malloc( m*sizeof(double)); //guardará os valores de x1,x2,...,xm;

    do{
        if (countSolved==0) //primeiro coef a ser resolvido
            coef[coefPAR] = M[i][n-1]/M[i][j];
            
        else{
            for(k=countSolved;k!=0;k--){ //prod
                ans = ans + M[i][j+k]*coef[j+k];
            }

            coef[coefPAR] = (M[i][n-1] - ans)/M[i][j];
        }

        i--;j--;
        countSolved++;
        coefPAR--;
        ans=0;

    }while(countSolved != m);

    return coef;
}

void multiplicaMatrizes( double **matrizA, double **matrizB, int m, int n){
  int i,j,k;
  double sum=0;
  
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      
      for(k=0;k<m;k++){ sum = sum + matrizA[i][k]*matrizB[k][j]; }
      
      printf("%g",sum);
      sum = 0;
    }
    puts("");
  }

}

void calculaImprimeInversa(double **M, int m, int n){
  
  int i,j,k,key=0;
  double **tmp, **inv, *raizes;

  inv = malloc ( m*sizeof(double *) );
  for ( i = 0; i < m; i++ ) inv[i] = malloc( n*sizeof(double) );

  tmp = malloc ( m*sizeof(double *) );
  for ( i = 0; i < m; i++ ) tmp[i] = malloc( (n+1)*sizeof(double) ); 
  
  for(k=0;k<m;k++){ 
    
    if(key==0){
      for(i=0;i<m;i++){ // copia o valor da matriz
        for(j=0;j<n;j++){
          tmp[i][j] = M[i][j];
        }
      }
      key = 1; // não precisaremos resolver este bloco novamente  
    }

    for(i=0;i<m;i++){ // copia o valor da coluna extra que gerará o sistema a se resolver
        tmp[i][n] = M[i][n+k];
    } 

    
    raizes = SubstituicaoReversa(tmp,m,n+1);
    for (i=0; i<m; i++) printf("%6.2g ",raizes[i]);
    puts("");

    for(i=0;i<m;i++){
      inv[i][k] = raizes[i];
    }
  
  }

  multiplicaMatrizes(M,inv,m,n);

}

int main(int argc, char **argv)
{
  int m,n,i,j,k;
  double **M, **Mext,lbd;
  
  m = atoi(argv[1]);
  n = atoi(argv[2]);
  M = LeMatrix(m,n);
  ImprimeMatriz(M,m,n);
  M = Pivotamento(M,m,n);
  
  printf("A matriz inversa é dada por:\n");
  calculaImprimeInversa(M,m,n);

  return 0;
}
