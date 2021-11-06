/*		Diferenciacao numerica

	A derivada f'(x) de uma funcao f(x) no ponto
	x=a é definida como:
	
	df(x)/dx (em x=a) = f'(a) = lim (f(x) - f(a))(x-a)) x->a


	APROXIMACAO PROGRESSIVA

	df(x)/dx (em x=xi) = (f(xi+1) - f(xi))/(xi+1-xi)) 

	APROXIMACAO REGRESSIVA

	df(x)/dx (em x=xi) = (f(xi) - f(xi-1))/(xi-xi-1)

	DIFERENÇA CENTRAL

	df(x)/dx (em x=xi) = (f(xi+1) - f(xi-1))/(xi+1-xi-1))

	Considere a funcao f(x)=x³. Calcule numéricamente a 1ª 
	derivada no ponto x=3.
	a) x=2,x=3,x=4
	b) x=2.75,x=3,x=3.25

	Em seguida compare com o resultado analitico: Erro = |(resultado - analitico)/analitico|*100

*/

#include <stdio.h>
#include <math.h>

double func(double var)
{
	return var*var*var;
} 

double func_exata(double var)
{
	return 3*var*var;
}

int main()
{
	double x,xmais,xmenos,exato,progress, regress, central,erro_progress,erro_regress,erro_central;

	printf("Insira xi-1:");
	scanf("%lf", &xmenos);

	printf("Insira x onde se deseja calcular a derivada:");
        scanf("%lf", &x);

	printf("Insira xi+1:");
        scanf("%lf", &xmais);
	

	//calculando as derivadas
	progress = (func(xmais)-func(x))/(xmais-x);
	regress = (func(x)-func(xmenos))/(x-xmenos);
	central = (func(xmais)-func(xmenos))/(xmais-xmenos);

	//calculando os erros
	exato = func_exata(3);
	erro_progress = fabs((progress-exato)/exato)*100;
	erro_regress = fabs((regress-exato)/exato)*100;
	erro_central = fabs((central-exato)/exato)*100;

	printf("Derivadas\t\tErro\n");
	printf("Progressiva:%lf\t%lf\n", progress, erro_progress);
	printf("Regressiva:%lf\t%lf\n", regress, erro_regress);
	printf("Central:%lf\t%lf\n", central, erro_central);

	return 0;
}
