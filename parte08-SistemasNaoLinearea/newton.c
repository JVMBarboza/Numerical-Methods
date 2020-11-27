#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3

double f1(double x[N])
{
  return (3*x[0] - cos(x[1]*x[2]) - 0.5);
}

double f2(double x[N])
{
  return ((x[0]*x[0])+sin(x[2])-81*(x[1]+0.1)*(x[1]+0.1) + 1.06);
}

double f3(double x[N])
{
  return (exp(-x[0]*x[1])+20*x[2]+(10*M_PI-3)/3);
}

void ImprimeMatriz(double M[][N+1], int m, int n) {
  int i,j;
  
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("%5.2lf ",M[i][j]);
    }
    puts("");
  }
  puts("");
}

void Jacobiana(double J[N][N+1], double x[N]){

    J[0][0] = 3; 
    J[0][1] = sin(x[1]*x[2])*x[2]; 
    J[0][2] = sin(x[1]*x[2])*x[1];

    J[1][0] = 2*x[0];
    J[1][1] = -81*2*(x[1]+0.1);
    J[1][2] = cos(x[2]);

    J[2][0] = -exp(-x[0]*x[1])*x[1];
    J[2][1] = -exp(-x[0]*x[1])*x[0];
    J[2][2] = 20;

}

double Gauss(double A[][N+1], int m, int n, double x0[N]){
  int i, j;
  double x1[N], n1=0, n2=0, dx, norma=0;
  
  for(i=0; i<m; i++)
  {
    x1[i] = x0[i];
    for(j=0; j<i; j++)
    {
      n1 += A[i][j]*x0[j];
    }
    for(j=i+1; j<m; j++)
    {
      n2 += A[i][j]*x0[j];
    }
    
    x0[i] = (A[i][m] - n1 - n2) / A[i][i];
    dx = fabs(x0[i]-x1[i]);
    if(dx > norma) norma = dx;
    n1=0;
    n2=0;
  }
  
  return (norma);
}

void TrocaLinhas(double M[][N+1],int i, int j) {
  double tmp;
  int k;
  
  for (k=0; k<N+1; k++) {
    tmp = M[i][k];
    M[i][k] = M[j][k];
    M[j][k] = tmp; 
  }

}

void MultLinha(double M[][N+1], int i, int j, double lbd) {
  
  for (int k=0; k<N; k++) M[j][k] -= M[i][k]*lbd;
}

void Triangulariza( double M[][N+1]) {

  int i,j,p;
  double lbd;

  for(i=0; i<N-1; i++) 
  {
    if (M[i][i] == 0) 
    {
      p = i; 
      do 
      {
        p++; 
      } while ((M[p][i] == 0)&&(p<N));
      TrocaLinhas(M,i,p);
      if (M[i][i]==0) {
        puts("Sistema sem solução");
        exit(1); 
      }  
    }  
    for(j=i+1; j<N; j++) 
    {
      lbd = M[j][i]/M[i][i];
      MultLinha(M,i,j,lbd);
    }
  }
}
  
void SubstituicaoReversa( double M[][N+1], double v[]){
    int nl, nc;
  
    v[N-1] = (M[N-1][N])/M[N-1][N-1];
    
    for(nl= N-2; nl >= 0; nl--)
    {
      v[nl] = M[nl][N];
      
      for(nc=N-1; nc > nl; nc--)
      {
        v[nl] = v[nl] - (v[nc] * M[nl][nc]);
      }
      
      v[nl] = v[nl]/M[nl][nl];
    }
}

int main(){
    double (*f[N])() = {f1,f2,f3}, A[N][N+1];
    double x[N] = {0.1, 0.1, -0.1}, xa[N], norma, tol=1e-8;
    
    int i,itera=0;

    do{
        Jacobiana(A,x);
        for(i=0;i<N;i++){
            A[i][N] = -f[i](x);
            xa[i] = x[i];
        }

        do{
            norma = Gauss(A, N, N+1, x);
        }while (norma>tol);

        //Triangulariza(A);
        //SubstituicaoReversa(A,x);

        itera++;
        printf("\n%d =>", itera);
        norma=0;

        for(i=0;i<N;i++){
            norma = (fabs(x[i])>norma) ? fabs(x[i]):norma;
            x[i] += xa[i];
            printf(" %.6g ", x[i]); 
        }
        printf(" norma=%.3g\n", norma);
    }while( (norma>tol) && (itera<20));

    puts("");
    return 0;
}
