#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 2

typedef double (*equacoes)();

double f0(double x, double y[N], double Eo){
    return y[1]-Eo;
}

double f1(double x, double y[N], double Eo){
    return  (-11 + 6*Eo + (13./4.)*y[0] - 6*y[1]); // dE/dt = P-V
}

void rk4(double x, double y[N], double h, double Eo){
    int i;
    double k1[N],k2[N],k3[N],k4[N],yp[N],ypp[N];
    equacoes f[] = {f0,f1};

    for(i=0;i<N;i++){
        k1[i] = f[i](x,y,Eo);
        yp[i] = y[i]+k1[i]*(h/2);
    }

    for(i=0;i<N;i++){
        k2[i] = f[i](x+h/2,yp,Eo);
        ypp[i] = y[i]+k2[i]*(h/2);
    }

    for(i=0;i<N;i++){
        k3[i] = f[i](x+h/2,ypp,Eo);
        yp[i] = y[i]+h*k3[i];
    }

    for(i=0;i<N;i++){
        k4[i] = f[i](x+h,yp,Eo);
        y[i] += (h/6)*(k1[i]+2*k2[i]+2*k3[i]+k4[i]); 
    }
}

int main(int argc, char **argv){
    double a,b,h,x,y[N],Eo;
    int i;

    y[0] = atof(argv[1]);
    y[1] = atof(argv[2]);
    Eo = atof(argv[3]);

    a=0;
    b=10;
    h=0.1;
    x=a;

    for(x=a;x<b;x+=h){
        printf("%g ", x);
        for(i=0;i<N;i++){
            printf("%g ", y[i]);
        }
        rk4(x,y,h,Eo);
        puts("");

    }

    return 0;
}