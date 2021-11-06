/*
	EQUAÇÃO DIFERENCIAL ORDINARIA

 Considere a EDO de 1ª ordem:
 
	f'(x)=f(x,y)

 Com condição inicial y(x1)=y1

 O método de Euler assume que em uma pequena distância h
na vizinhança de (xi,yi), a função y(x) tem inclinação 
constante.
 A solução numérica é dada por(EULER MODIFICADO):
	xi+1 = xi+h
	yi+1 = yi+[f(xi,yi)+f(xi+1,yi+1)]*h/2

 RESOLVAR A EDO:

	y' = -1.2y + 7exp(-0.3x)

 de x=0 até x=2.5 com condicao inicial y=3 em x=0. Plote
os pontos da solucao numerica e compare a solucao analiti
ca 

	SOL. ANALITICA:
	
	y = (70/9)*exp(-0.3x)-(43/9)*exp(-1.2x)

*/

#include <stdio.h>
#include <math.h>

FILE *arq2;

double func(double x,double y)
{
	return( -1.2*y+7*exp(-0.3*x) );
}

int main()
{

	double a=0, b=2.5, n=3000, h,x,y,yo=3,xo=0,fo;
	int i;

	arq2 = fopen("arq2.dat","w");

	h = (b-a)/30.0;
	x=xo;
	y=yo;
	fo = func(xo,yo);
        fprintf(arq2,"%lf  %lf\n",x,y);

	for(i=1;i<=n;i++)
	{
		x=x+h;
		y=y+(fo+func(x,y))*(h/2);
		fo = func(x,y);
	
		fprintf(arq2,"%lf  %lf\n",x,y);
	}
	
	fclose(arq2);
	
	return 0;
}
	
	






