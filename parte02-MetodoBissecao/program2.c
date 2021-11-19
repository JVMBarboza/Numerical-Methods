
/*RAIZES DE EQUACOES NAO-LINEARES - METODO DE BISSECAO
 * Neste caso,não sabemos que o intervalo contem uma raiz
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
	int key=0;
	double a,b,xn,i;
	
	do{
		printf("Informe o valor do intervalo:\n");
		scanf("%lf", &a);
		scanf("%lf", &b);
	}while( a > b);//não permite o input de um a<b
	
	i=a+0.5; //0.5 -> deslocamento para não termos um produto entre f(a) e f(a) na primeira iteracao
	
	do{//checa se tem zero no intervalo e seta key = 1
		if( function(a)*function(i) < 0)
		{
			key = 1;//pelo menos um zero tem
		}
		i = i + 1;//esse incremento, quanto menor mais acurado será a verificação
	}while(i < b); 
	
	if(key == 1)//tem zero no intervalo
	{
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
	}
	
	if(key == 1)
		printf("\nRaiz em:%lf\n", xn);
	else
		printf("Não achou raiz no intervalo.\n");
	
	
	return 0;
}
