#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x, double y, double y1){
    return log(x);
}

double f1(double x, double y, double y1){
    return 1/x;
}

double f11(double x, double y, double y1){
    return -1/(x*x) - log(x) + log(y);
}


double *DiferencasFinitas(double a, double b, int N, double h, double alpha, double beta){
    int i, itera;
    double x,t,h2=h*h,y1,norma;
    double *D,*U,*L,*R,*l,*u,*v,*z,*y;

    D = malloc((N+2)*sizeof(double));
    L = malloc((N+2)*sizeof(double));
    R = malloc((N+2)*sizeof(double));
    U = malloc((N+2)*sizeof(double));
    
    l = malloc((N+2)*sizeof(double));
    u = malloc((N+2)*sizeof(double));
    v = malloc((N+2)*sizeof(double));
    y = malloc((N+2)*sizeof(double));
    z = malloc((N+2)*sizeof(double));

    for(i=0; i<=N; i++) y[i] = alpha + i*h*(beta-alpha)/(b-a);
    y[0]   = alpha;
    y[N+1] = beta;

    itera = 0;
    
    do{
        x = a + h;
        y1 = (y[2]-alpha)/(2*h);
        D[1] = 2 + h2*f1(x,y[1],y1); //VALORES INICAIS
        U[1] = -1 + (h/2)*f11(t,y[1],y1);
        R[1] = -(2*y[1] - y[2] - alpha + h2*f(x,y[1],y1));

        for(i=2; i<N; i++){ //VALORES INTERMEDIARIOS
            t = a + i*h;
            y1 = (y[i+1] - y[i-1])/(2*h);
            D[i] = 2 + h2*f1(t,y[i],y1);
            U[i] = -1 + (h/2)*f11(t,y[i],y1);
            L[i] = -1 - (h/2)*f11(t,y[i],y1);
            R[i] = -(-y[i-1] + 2*y[i] - y[i+1] + h2*f(t,y[i],y1));
        }

        x = b - h;
        y1 = (beta-y[N-1])/(2*h);
        D[N] = 2 + h2*f1(x,y[N],y1);//VALORES FINAIS
        L[N] = -1 - (h/2)*f11(t,y[N],y1);
        R[N] = -(2*y[N] - y[N-1] - beta + h2*f(x,y[N],y1));

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

        v[N] = z[N];
        y[N] += v[N];
        norma = 0;

        for(i=N-1;i>0;i--){
            v[i] = z[i] - u[i]*v[i+1];
            if(fabs(v[i])>norma) norma =  fabs(v[i]);
            y[i] += v[i];
        } 
        itera++;
    }while((norma > 1e-8));

    return y;
}

int main(int argc, char **argv){
    int N, i;
    double **M, *x, a, b, h, t, alpha, beta;

    a = atof(argv[1]);
    b = atof(argv[2]);
    N = atoi(argv[3]);
    alpha = atof(argv[4]);
    beta = atof(argv[5]);
    h = (b-a)/(N+1);

    x = DiferencasFinitas(a,b,N,h,alpha,beta);
    printf("%lf %lf\n", a, alpha);
    for(i=0;i<N+1;i++) printf("%lf %lf\n",a+i*h, x[i]);
    printf("%lf %lf\n", b, beta);
    return 0;
}