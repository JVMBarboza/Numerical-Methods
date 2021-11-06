////////////////////////////////////////////////
// Testes realizado com uso da mesma matriz   //
// estuda na videoaula:                       //
//           1  1  0  3  4                    //
//           2  1 -1  1  1                    //
//           3 -1 -1  2 -3                    //
//          -1  2  3 -1  4                    //
// m = 4 e n=5;                               //
////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

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

double **Triangulariza( double **M, int m, int n) {
  int i,j,p;
  double lbd;

  for(i=0; i<m-1; i++) {
    if (M[i][i] == 0) {
      p = i; 
      do {
        p++; 
      } while ((M[p][i] == 0)&&(p<m));
      M = TrocaLinhas(M,m,n,i,p);
      if (M[i][i]==0) {
        puts("Sistema sem solução");
        exit(1); 
      }  
    }  
    for(j=i+1; j<m; j++) {
      lbd = M[j][i]/M[i][i];
      M = MultLinha(M,m,n,i,j,lbd);
    }
  }
  return M;   
}

double *SubstituicaoReversa( double **M, int m, int n) {
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

double *VerificaResolucao(double **M, double *VetorRaizes, int m, int n){
  double **MatrizOriginal, *VetorNulo, *VetorTermosIndependentes;
  int i,j;
  
  MatrizOriginal = malloc ( m*sizeof(double *) );
  for ( i = 0; i < m; i++ ) MatrizOriginal[i] = malloc( m*sizeof(double));
  
  VetorNulo = malloc (m*sizeof(double *) );
  VetorTermosIndependentes = malloc (m*sizeof(double *) );
  
  for ( i = 0; i < m; i++ ) {
    for ( j = 0; j < m; j++ ) {
        MatrizOriginal[i][j] = M[i][j];
    }  
  }
  
  j = n-1;
  for ( i = 0; i < m; i++ ) {
    VetorTermosIndependentes[i] = M[i][j];
  }
  
  for(i=0;i<m;i++){
      VetorNulo[i] = 0;
  }

  for(i=0;i<m;i++){
      for(j=0;j<m;j++){
        VetorNulo[i] = VetorNulo[i] + MatrizOriginal[i][j]*VetorRaizes[j];
      }
  }  
  
  for(i=0;i<m;i++){
      VetorNulo[i] = VetorNulo[i] - VetorTermosIndependentes[i];
  }
  
  free(MatrizOriginal);
  return VetorNulo;
}

int main(int argc, char **argv)
{
  int m,n,i,j,p;
  double **M, lbd, *raizes, *vetorNulo;
  
  m = atoi(argv[1]);
  n = atoi(argv[2]);
  M = LeMatrix(m,n);
  ImprimeMatriz(M,m,n);
  M = Triangulariza(M,m,n);
  raizes = SubstituicaoReversa(M,m,n);
  printf("As raizes do sistema são :\n ");
  for (i=0; i<m; i++) printf("x%1d = %6.2g\n",i,raizes[i]);
  vetorNulo = VerificaResolucao(M,raizes,m,n);
  printf("Verificação da solução:\n ");
  for (i=0; i<m; i++) printf("x%1d = %6.2g\n",i,vetorNulo[i]);
  
  return 0;
}