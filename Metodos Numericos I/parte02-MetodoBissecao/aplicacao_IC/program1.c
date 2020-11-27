/*RAIZES DE EQUACOES NAO-LINEARES - METODO DE BISSECAO
 * Neste caso, sabemos que o intervalo contem uma raiz
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define eps 1e-4

double function(double x)
{
	return (10.3943*pow(x,4)-185.2424*pow(x,3)+1229.238*pow(x,2)-3592.5*x+3891.32); // Substituir a derivada da equacao aqui.
}

int main()
{
	double a,b,xn;

	printf("Informe o valor do intervalo:\ninicio:");
	scanf("%lf", &a);
	//printf("\nfim:");
	scanf("%lf", &b);
	xn = (a+b)/2.0;

	while( fabs(function(xn)) >= eps )
	{
		if(function(a)*function(xn)<0)
		{
			a=a;
			b=xn;
			xn=(a+b)/2.0;
		}
		if(function(b)*function(xn)<0)
		{	
			b=b;
			a=xn;
			xn=(a+b)/2.0;
		}
	}

	printf("\nRaiz em:%lf", xn);
	
	return 0;
}
