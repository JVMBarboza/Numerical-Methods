/*      INTEGRACAO NUMERICA

        METODO DO PONTO CENTRAL

        * Subdivide o intervalo [a,b] em N intervalos
        * N=1 pontos, X1=a e Xn+1=b 
*/


#include<stdio.h>
#include<math.h>

 //Método do Ponto Central 
 //Integrando I = integral(97000x/5x²+570000) | 40 à 93.  

double func(double x)
{
	return ( (97000*x)/((5*x*x)+570000));
}
int main()
{
   double a, b, x, N, inte, h, i, soma=0;
   
   printf("Informe a quantidade de intervalos: ");
   scanf("%lf", &N);

   printf("Informe o valor a: ");
   scanf("%lf", &a);

   printf("Informe o valor b: ");
   scanf("%lf", &b);
   
   h = (b-a)/(N*(1.0)); 
   x = a;
    
    for(i=1;i<=N;i++)
    {
   	 soma = soma +func((x+(x+h))/2.0); //Chamar a função(a) até função(b);
     x = x+h; //Andar com o intervalo em x, ou seja, 1º(a até x) 2º(x até b)
    } 

     inte = h*soma;
   
   
   printf("O valor da integral é: %lf \n", inte);
}
