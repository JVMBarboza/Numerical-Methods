/* DIFERENCIACAO NUMERICA
 *
 * Extrapolacao de Richardson:
 * Considere D uma derivada conhecida
 *
 * 	       D = (1/3)*( 4D(h/2) -D(h) )
 *
 * Encontre a derivada da funcao em x=2, usando a formula de diferenca CENTRAL
 * 	       f(x) = (2^x)/x
 * a)h=0.1
 * b)h=0.2
 *
 * Encontre os erros em relacao ao valor analitico.
 * Refaca o item anterios usando a extrapolacao de Richardson
*/

#include <stdio.h>
#include <math.h>

double func(double x)
{
	return (pow(2.0,x)/x);
}

double dev(double x, double h)
{
	return ( (func(x+h)-func(x-h))/( (x+h)-(x-h) ) );
}

double erro(double derivada, double analitico)
{
	return ( (derivada-analitico)*100/analitico );
}

int main()
{
	double h=0.1,x=2.0, der_central, extrap, rich,erro_central, erro_rich, exato = 0.386294361; //variar h para fazer os itens a) e b)

	der_central = dev(x,h);
	rich = ( (4*dev(x,h/2.0) - dev(x,h))/3.0 );

	erro_central = fabs( erro(der_central, exato) );
	erro_rich = fabs( erro(rich, exato) );

	printf("\n\tRESULTADOS\t\tErros\nDerivada Central:%lf \t%lf",der_central, erro_central);
       printf("\nExtrap. de Richardson:%lf \t%lf\n\nAnalitico:%lf\n",rich,erro_rich,exato);

	return 0;
}	







