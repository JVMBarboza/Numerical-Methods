/*RAIZES DE EQUACOES NAO-LINEARES - METODO DE BISSECAO
 * Neste caso, sabemos que o intervalo contem uma raiz
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define eps 1e-4

double function(double parameter)
{
	return (8-(4.5)*(parameter-sin(parameter)));
}

int main()
{

	double a,b,xn;

	printf("Informe o valor do intervalo:\n");
	scanf("%lf", &a);
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
