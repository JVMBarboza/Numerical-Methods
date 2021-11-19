/*RAIZES DE EQUACOES NAO-LINEARES - METODO DE BISSECAO
 * Neste caso, não sabemos que o intervalo contem uma raiz e o intervalor deve ser gerado de maneira estocastica
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define eps 1e-4
#define TAM 1000000

double gera_numA(unsigned R, unsigned seed){

    int j;
    double rn, num;

    for(j=0;j<TAM;j++){

		R = R*seed;
		rn = R/4294967295.0;
		num=rn;
	
	}
	
	return num;

}

double gera_numB(unsigned R, unsigned seed){

	int j;
	double rn, num;

	for(j=0;j<TAM;j++){

		R = R*seed;
		rn = R/3192766597.0;
		num=rn;
	}

	return num;

}


double function(double parameter){

	return (8-(4.5)*(parameter-sin(parameter)));
}

int main(){

	int key=0;
	double a,b,xn,i,s,r;

	
	do{
		printf("Insira uma semente e um valor de R:");
		scanf("%le", &s);
		scanf("%le", &r);
		printf("Gerando intervalo...\n");
		a = gera_numA(r,s)*100.0;
		b = gera_numB(r,s)*100.0;
	}while( a > b);//não permite o input de um a<b
	
	i=a+0.5; //0.5 -> deslocamento para não termos um produto entre f(a) e f(a) na primeira iteracao
	
	do{//checa se tem zero no intervalo e seta key = 1
		if( function(a)*function(i) < 0){
			key = 1;//pelo menos um zero tem
		}
		i = i + 1;//esse incremento, quanto menor mais acurado será a verificação
	}while(i < b); 
	
		
	if(key == 1){//tem zero no intervalo

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
