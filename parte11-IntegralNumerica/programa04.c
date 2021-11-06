/*      INTEGRACAO NUMERICA

        METODO DE SIMPSON 3/8 

	* Baseado em um polinomio cubico para aproximar o integrando
	* Dividir o intervalor [a,b] em N subintervalos 
	* N tem que ser divisivel por 3
	
	* I = (3*h/8)*(f(a)+3*somatorio1[(fxi)+f(xi+1)+3*somatorio2[f(xi)]+f(b))
	* somatorio 1 -> 2,5,8 até N-1
	* somatorio 2 -> 4,7,10 até N-2
*/

#include<stdio.h>
#include<math.h>

double func(double x)
{
	return ( (97000*x)/((5*x*x)+570000));
}

int main()
{
   double a=40, b=93, I, h, x,sum1=0, sum2=0;
   int N,i=1;   

   do{ //Apenas sairá deste laço quando a contidade de interv. for divisivel por 3
   	printf("Informe a quantidade de intervalos:");
   	scanf("%i", &N);

	if(N%3 != 0)
		printf("Este metodo so aceita quant. de intervalos DIVISIVEIS POR 3!\n");
   }while(N%3 != 0);
   
   h = (b-a)/N*(1.0); 
   x=a;

   for(i=2;i<=N-1;i=i+3)
   {
	   sum1 = sum1 + func(x)+func(x+h);
	   x=x+3*h;
   }
   x=40+4*h;
   for(i=4;i<=N-2;i=i+3)
   {
	   sum2 = sum2 + func(x);
	   x=x+3*h;
   }

   I =(3*h/8)*(func(a)+3*sum1+2*sum2+func(b));
   
   printf("O valor da integral é: %lf \n", I);

   return 0;
}
