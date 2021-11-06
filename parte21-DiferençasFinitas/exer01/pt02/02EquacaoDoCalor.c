#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double p(double x){
    return 0;
}

double q(double x, double gamma){
    return gamma;
}

//TA = T infinito(passado por argm. no ./exec)
double r(double x, double gamma, double TA){
    return -gamma*TA;
}


double *DiferencasFinitas(double a, int N, double h, double alpha, double beta, double gamma, double TA){
    int i;
    double t,h2=h*h;
    double *D,*U,*L,*R,*l,*u,*v,*z,*y;

    D = malloc((N+2)*sizeof(double));
    L = malloc((N+2)*sizeof(double));
    R = malloc((N+2)*sizeof(double));
    U = malloc((N+2)*sizeof(double));
    
    l = malloc((N+2)*sizeof(double));
    u = malloc((N+2)*sizeof(double));
    y = malloc((N+2)*sizeof(double));
    z = malloc((N+2)*sizeof(double));

    t = a+h; //t=x
    D[1] = 2 + h2*q(t,gamma); //VALORES INICAIS
    U[1] = -1 + (h/2)*p(t);
    R[1] = -h2*r(t,gamma,TA) + (1+(h/2)*p(t))*alpha;

    for(i=2; i<N; i++){ //VALORES INTERMEDIARIOS
        t += h;
        D[i] = 2 + h2*q(t,gamma);
        U[i] = -1 + (h/2)*p(t);
        L[i] = -1 - (h/2)*p(t);
        R[i] = -h2*r(t,gamma,TA);
    }

    t += h;
    D[N] = 2 + h2*q(t,gamma); //VALORES FINAIS
    L[N] = -1 - (h/2)*p(t);
    R[i] = -h2*r(t,gamma,TA) + (1 - (h/2)*p(t))*beta;

    //ALGORITMO  DE CROUT -> DIVIDIMOS OS CALCULOS EM 3 ETAPAS DE FOMRA ANÁLOGA

    l[1] = D[1];    //VALORES INICAIS
    u[1] = U[1]/D[1];
    z[1] = R[1]/l[1];

    for(i=2; i<=N; i++){ //VALORES INTERMEDIARIOS
        l[i] = D[i] - L[i]*u[i-1];
        u[i] = U[i]/l[i];
        z[i] = (R[i] - L[i]*z[i-1])/l[i];
    }
    
    l[N] = D[N] - L[N]*u[N-1];    
    z[N] = (R[N] - L[N]*z[N-1])/l[N];
    y[N] = z[N];

    y[0] = alpha;
    y[N+1] = beta;
    for(i=N-1;i>0;i--) y[i] = z[i] - u[i]*y[i+1];

    return y;
}

int main(int argc, char **argv){
    int N, i;
    double **M, *x, a, b, h, t, alpha, beta, gamma, TA;

    a = atof(argv[1]); //EXTREMIDADE INICIAL
    b = atof(argv[2]); //EXTREMIDADE FINAL
    N = atoi(argv[3]); //QTDE DE PONTOS
    alpha = atof(argv[4]); //TEMPERATURA NA EXTREMIDADE INICIAL
    beta  = atof(argv[5]); //TEMPERATURA NA EXTREMIDADE FINAL
    gamma = atof(argv[6]); //RAZAO CONDUCAO AMBIENTE/CONDUCAO DO MATERIAL
    TA    = atof(argv[7]); //TEMPERATURA NO INFINITO(DO MODELO)

    h = (b-a)/(N+1);

    x = DiferencasFinitas(a, N, h, alpha, beta, gamma, TA);
    for(i=0;i<=N+1;i++) printf("%lf %lf\n",(a+i*h), x[i]);

    return 0;
}