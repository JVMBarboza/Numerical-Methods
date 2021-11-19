/*QUEREMOS OBTER AS 4 RAIZES DA FUNCAO (NAO ESTA FUNCIONANDO)*/
#include <stdio.h>
#include <math.h>

#define eps 1e-4

double func(double value)
{
	return (pow(value,4.0) - 5.5*pow(value,3.0) - 7.2*pow(value,2.0) + 43*value + 36); 
}

int main()
{
	int q=0,i;
	double raizes[4],xa,xb,xn,xa_original,xb_original,da,db;

	printf("Insira o menor limite:");
	scanf("%lf", &xa);	

	printf("Insira o maior limite:");
        scanf("%lf", &xb);

	xa_original = xa;
	xb_original = xb;
	
	do{
		xn = (xa+xb)/2.0;
		
		while(fabs(func(xn)) >= eps){

			if(func(xa)*func(xn)<0){

					xn=(xa+xb)/2.0;
					xa=xa;
					xb=xn;
			}
			
			if(func(xb)*func(xn)<0){
					xn=(xa+xb)/2.0;
					xb=xb;
					xa=xn;
			}
        }

		raizes[q] = xn;
		q++;
		
		da = xn-xa_original;
		db = xn-xb_original;
		
		if(da < db){	
			xb_original = xn - eps;
			xb = xb_original;
			xa = xa_original;
		}
		else{
			xa_original = xn + eps;
			xa = xa_original;
			xb = xb_original; 
		}

	}while(q<3); //q == 3 --> encontrou as 4 raizes

	printf("As raízes são:\n");
	for(i=0;i<4;i++){
		printf("\t %i:%lf \n", i+1, raizes[i]);
	}

	return 0;
}
