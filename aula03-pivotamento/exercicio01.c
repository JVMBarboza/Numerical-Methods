////////////////////////////////////////////////
//         1.19  2.11   -100   1 1.12         //
//         14.2 -0.122   12.2 -1 3.44         //
//         0     100    -99.9  1 2.15         //
//         15.3  0.110  -13.1 -1 4.16         //
// m = 4 e n=5;                               //
////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define erro 1e-4

double **LeMatrix(int m, int n) 
{
  double **M;
  int i,j;
  
  M = malloc (m*sizeof(double*));
  for (i=0; i<m; i++) M[i] = malloc( n*sizeof(double));
  
  for (i=0; i<m; i++) 
  {
    for (j=0; j<n; j++) 
    {
        scanf("%lf", &M[i][j]);
    }  
  }
  return M;
}

void ImprimeMatriz(double **M, int m, int n) 
{
  int i,j;
  
  for (i=0; i<m; i++) 
  {
    for (j=0; j<n; j++) 
    {
      printf("%.4lf   ",M[i][j]);
    }
    puts("");
  }
  puts("");
}

double **TrocaLinhas(double **M, int m, int n, int i, int j) 
{
  double aux;
  int k;
  
  for (k=0; k<n; k++) 
  {
    aux = M[i][k];
    M[i][k] = M[j][k];
    M[j][k] = aux; 
  }
  return M;
}

double **MultiplicaLinhas(double **M, int m, int n, int i, int j, double lbd) 
{
  for (int k=0; k<n; k++) 
  {
  	M[j][k] -= M[i][k]*lbd;
  }
  
  return M;
}

double **Pivotamento( double **M, int m, int n) 
{
  int i,j,p,k,cont=0;
  double lbd;

  for(i=0; i<m; i++)
  {
  	for(k=i+1; k<m; k++)
    {
      if(fabs(M[i][i])<fabs(M[k][i]))
      {
        M = TrocaLinhas(M,m,n,i,k);
        cont++;
      }
    }
    
    if(M[i][i]!=0)
    {
      for(p=i+1;p<m;p++) /* Zerando os elementos de baixo do pivo */
      { 
        lbd = M[p][i]/M[i][i];
        M = MultiplicaLinhas(M,m,n,i,p,lbd);
      }
    }
  }
  printf("\nOcorreram %d trocas de linhas\n", cont);
  return M;
}
  
double *SubstituicaoReversa(double **M, int m)
{
  int i,j;
  double soma, *raizes;
  
  raizes = (double*)malloc(m*sizeof(double));
  
  raizes[m-1] = M[m-1][m]/M[m-1][m-1];
  
  for(i=m-2; i>=0; i--)
  {	
  	soma=0;
    for(j=i+1;j<=m;j++)
    {
      soma=soma+(M[i][j]*raizes[j]);
    }
    raizes[i]=(M[i][m]-soma)/M[i][i];
  }
  
  return(raizes);
}

int main(int argc, char **argv)
{
  int m,n,i;
  double **M, **N, *raizes;
  
  m = atoi(argv[1]);
  n = atoi(argv[2]);
  M = LeMatrix(m,n);
  ImprimeMatriz(M,m,n);
  M = Pivotamento(M,m,n);
  raizes = SubstituicaoReversa(M,m);
  
  printf("As raízes do sistema são: \n");
  for (i=0; i<m; i++) printf("x%i = %.3g\n",i , raizes[i]);
  puts("");
 
  return 0;
}