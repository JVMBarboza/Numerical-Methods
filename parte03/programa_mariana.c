#include <stdio.h>
#include <math.h>
#define erro 1e-4
#define g 9.8
#define v_0 15.2
#define x 18.2
#define y 2.1
#define h 1.82
#define var_fixa 0.5*((pow(x,2)*g)/(pow(v_0,2)))

float expression (float theta)
{
	return ((x*tan(theta)) - (var_fixa/(pow(cos(theta),2))) + h - y);
}

main()
{
	float a, b, x_n;
	a=0;
	b=(M_PI)/2.0;
	x_n= (a+b)/2.0;
	
	while (fabs(expression(x_n)) > erro)
	{	
		if(expression(x_n) < a || expression(x_n) > b)
			printf("\nNão é solução física\n");
			
		if(expression(a)*expression(x_n) <0)
		{	
			b=x_n;
		}
		
		else if(expression(b)*expression(x_n) <0)
		{	
			a=x_n;
		}
		x_n=(a+b)/2.0;
				
	}
	x_n= (180*x_n)/M_PI; 
	printf("\nValor aproximado da raiz é: %f\n", x_n);
}

