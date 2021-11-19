/*      INTEGRACAO NUMERICA

        METODO DO RETANGULO COMPOSTO

        * Divide o intervalo [a,b] em N subintervalos
        * Sao necessarios N+1 pontos para definir N intervalos 
        * x1=a  e   x2=b

        I = h*somatorio(f(xi))  [ h é b-a e f(xi) é a altura, basicamente estamos calculando a area abaxo da funcao(a integral) usando a conhecido formula de area base(h=b-a)*altura(somatorio de f).]

	OBS.: Meu programa não funcionou cuz idk, este código foi inteiramente desenvolvido pela Núbia e funciona.

*/

#include<stdio.h>
#include<math.h>

 //Método do Retangulo 
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
   
    h = (b-a)/N*(1.0); 
    x=a;
    
    for(i=1;i<=N;i++)
    {
        soma = soma+func(x); //Chamar a função(a) até função(b);
        x = x+h; //Andar com o intervalo em x, ou seja, 1º(a até x) 2º(x até b)
    } 

    inte = h*soma;
   
   
    printf("O valor da integral é: %lf \n", inte);

}
