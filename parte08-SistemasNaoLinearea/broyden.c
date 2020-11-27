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

void ImprimeMatriz(double M[][N], int m, int n) {
  int i,j;
  
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("%5.2lf ",M[i][j]);
    }
    puts("");
  }
  puts("");
}

void imprimeVetor(double V[N], int n){
    int i;

    for(i=0;i<n;i++) printf("%g, ",V[i]);

    puts("\n");
}

double dotProduct(double a[], double b[]){
    int i;
    double dot = 0;

    for(i=0;i<N;i++){ dot = dot + a[i]*b[i]; }

    return dot;
}

void prodMatrixVetor(double M[][N], double x[], double r[N]){
    int i,j;
    
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            r[i] += M[i][j]*x[j];
        }
    }

}

void prodVetorMatrix( double x[N], double r[], double M[][N]){
    int i,j;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            r[i] = r[i] + x[j]*M[j][i];
        }
    }
}

void OutProduct(double A[], double B[], double r[N][N]){
    int i,j;

    //printf("\n'---- IMPRIMINDO OUTPRODUCT ----\n");

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
        
        r[i][j] = r[i][j] + A[i]*B[j];
        
        //printf("%g ",r[i][j]);
        }
        //puts("");
    }
    puts("");
}

void Inicializar(double J[N][N]){
    int i,j;
    for(i=0; i<N; i++){
        for(j=0;j<N;j++){
            if(i==j){ 
                J[i][j] = 1.0;
            }
            else{ 
                J[i][j] = 0.0;
            }
        }
    }
}

double normaVetor(double r[], int m){
    int i;
    double ri, norm = 0;

    for(i=0; i<m; i++){
        ri = fabs(r[i]);
        norm = (ri > norm) ? ri:norm;
    }
    return norm;
}

int main(){
    double (*f[N])() = {f1,f2,f3}, J[N][N];
    double x[N] = {0.1, 0.1, -0.1}, xa[N], norma, tol=1e-8;
    double V[N][N], F[N], FA[N], s[N], u[N], y[N], z[N], p;
    
    int i,j,itera=0;

    Inicializar(J); //calcula J⁻¹

    for(i=0; i<N; i++){ F[i] = f[i](x); } //f(x⁰) 

    printf("\nImprimindo F0:");
    imprimeVetor(F,N);

    prodMatrixVetor(J,F,s); //s = J⁻¹(f(x⁰))
    for(i=0; i<N; i++){
        s[i] *= -1; //s = -s = -J⁻¹(f(x⁰))
        x[i] += s[i];
    }
    printf("\nImprimindo s:");
    imprimeVetor(s,N);
    
    printf("\nImprimindo x:");
    imprimeVetor(x,N);


    do{
        for(i=0;i<N;i++){
            FA[i] = F[i];
            F[i] = f[i](x);
            y[i] = F[i] - FA[i];
        }
        printf("\nImprimindo F:");
        imprimeVetor(F,N);

        printf("\nImprimindo y:");
        imprimeVetor(y,N);

        prodMatrixVetor(J,y,z);
        p = dotProduct(s, z);
        printf("\nValor de p:%g",p);

        printf("\nImprimindo z:");
        imprimeVetor(z,N);
        for(i=0;i<N;i++) z[i] = s[i] - z[i]; 

        prodVetorMatrix(s,u,J);
        printf("\nImprimindo u:");
        imprimeVetor(u,N);

        OutProduct(z,u,V);
        printf("\nImprimindo V:");
        ImprimeMatriz(V,N,N);

        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                J[i][j] += (1/p)*V[i][j];
            }
        }
        printf("\nImprimindo J:\n");
        ImprimeMatriz(J,N,N);

        itera++;
        prodMatrixVetor(J, F, s);
        printf("%d ", itera);
        for(i=0; i<N; i++){
            s[i] *= -1; 
            x[i] += s[i]; 
            printf("x[%d] = %g ",i,x[i]);
        }
        puts("");
    }while((normaVetor(s,N)>tol) && (itera<50));


    puts("");
    return 0;
}