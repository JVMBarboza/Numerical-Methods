/*      INTEGRACAO NUMERICA

        METODO DE SIMPSON 1/3 

	* O integrando é aproximado por um polinomio quadrático

        * Divide o intervalo [a,b] em N subintervalos
	
 	* Defina h = (b-a)/N com **N PAR** 
	I = (h/3.0)[f(a)+4*(somatorio par de f(x))+2*(somatorio impar de f(x)+f(b)]   	
	OBS.: Também foi apresentado o método trapezoidal mas ele foi meio meh, dar uma relida no livro. Na aula foi basicamente a mesma integral do primeiro exemplo + [f(a)+f(b)]*(b-a)/2
*/

#include<stdio.h>
#include<math.h>

double func(double x)
{
	return ( (97000*x)/((5*x*x)+570000));
}

int main()
{
   double a=40, b=93, inte, h, x,sum_par=0, sum_impar=0;
   int N,i=1;   

   do{ //Apenas sairá deste laço quando a contidade de interv. for par
   	printf("Informe a quantidade de intervalos:");
   	scanf("%i", &N);

	if(N%2 != 0)
		printf("Este metodo so aceita quant. de intervalos PARES!\n");
   }while(N%2 != 0);
   
   h = (b-a)/N*(1.0); 
   x=a;

   while(i<=N) 
   {
	if(i%2==0)
   		sum_par = sum_par + func(x);
	else
		sum_impar = sum_impar + func(x);

	x=x+h;
	i++;
   } 

   inte = (h/3.0)*( func(a) + 4*sum_par + 2*sum_impar + func(b) );       
   
   printf("O valor da integral é: %lf \n", inte);

   return 0;
}
