#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3

typedef double (*equacoes)();

double f1(double x, double y[N], double beta, double gamma){
    return (-beta*y[0]*y[1]);
}

double f2(double x, double y[N], double beta, double gamma){
    return (beta*y[0]*y[1] - gamma*y[1]);
}

double f3(double x, double y[N], double beta, double gamma){
    return (gamma*y[1]);
}

void rk4(double x, double y[N], double h){
    int i;
    double k1[N],k2[N],k3[N],k4[N],yp[N],ypp[N];
    double beta  = (1./10.), gamma = (1./15.); 
    equacoes f[] = {f1,f2,f3};

    for(i=0;i<N;i++){
        k1[i] = f[i]( x, y, beta, gamma);
        yp[i] = y[i]+(h/2)*k1[i];
    }

    for(i=0;i<N;i++){
        k2[i] = f[i](x+h/2, yp, beta, gamma);
        ypp[i] = y[i]+(h/2)*k2[i];
    }

    for(i=0;i<N;i++){
        k3[i] = f[i](x+h/2, ypp, beta, gamma);
        yp[i] = y[i]+h*k3[i];
    }

    for(i=0;i<N;i++){
        k4[i] = f[i](x+h, yp, beta, gamma);
        y[i] += (h/6)*(k1[i]+2*k2[i]+2*k3[i]+k4[i]); 
    }
}

int main(int argc, char **argv){
    double a,b,h,x,y[N],beta,gamma;
    int i;

    y[0] = atof(argv[1]);
    y[1] = atof(argv[2]);
    y[2] = atof(argv[3]);

    a=0;
    b=200;
    h=0.1;
    x=a;

    for(x=a;x<b;x+=h){
        printf("%g ", x);
        for(i=0;i<N;i++){
            printf("%g ", y[i]);
        }
        rk4(x,y,h);
        puts("");

    }

    return 0;
}