/*RAIZES DE EQUACOES NAO-LINEARES - METODO DE BISSECAO
 * Neste caso, NAO sabemos se o intervalo contem uma raiz
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
	int cm=1, key=0;
	double a,b,i,xn;

	while(key!=1)
	{
		printf("Informe o valor do intervalo:\n");
		scanf("%lf", &a);
		scanf("%lf", &b);

		//conta para ver se tem zero no intervalor
		i=a;

		while(i < b)	
		{
			if( (function(a)*function(i)) < 0 )
			{
				//tem raiz, pode sair
				key = 1;
				break;		
			}
			i=i++;
		}	
		
		if(key == 0)//não achou zero no intervalo
		{
			printf("\nNão existe zeros no intervalo informado. Tecle\nInforme outro intervalo:");
		}
	}

	xn = (a+b)/2.0;
	//conta para achar o zero
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
