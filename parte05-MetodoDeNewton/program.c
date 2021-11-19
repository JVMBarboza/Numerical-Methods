/*METODO DE NEWTON: Aplicado na função f(x) = 8-(4.5)*(x-sin(x)) => f(x) =  8 - 4.5x +4.5sin(x) => f'(x) = -4.5+4.5cos(x) = 4.5(cos(x)-1)*/

#include <stdio.h>
#include <math.h>

#define eps 1e-4

double function(double value)
{
	return (8-(4.5)*(value-sin(value)));
}

double deriv_function(double value)
{
	return (4.5*(cos(value)-1));
}

int main()
{
	double x1, x2;
	int p = 0;
	
	do
	{
		printf("Insira o valor estimado para x1:");
		scanf("%lf", &x1);
	}while( deriv_function(x1) == 0 );

	do{
		x2 = x1 - function(x1)/deriv_function(x1);
		x1 = x2;
		p++;
	}while( fabs(function(x2)) >= eps);

	if(p != 1000)
	{
		printf("\nRaiz é: %lf\nNumero de p:%i \n", x2, p);
	}
	else
	{
		printf("\nNão encontrou a raiz. Falha.\n");
	}
	
	return 0;
}


