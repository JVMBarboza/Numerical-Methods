/*APROXIMACAO DE RETA POR MMQ COM 11 PARES DE DADOS*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

FILE *data;

float func1(float sumx,float sumy,float sumxy,float sumxqd)
{
	float y;
	
	y = (11*sumxy - sumx*sumy)/(11*sumxqd-pow(sumx,2));
	return y;
}

float func0(float sumx, float sumy, float sumxy,float sumxqd)
{
	float y;

	y = (sumxqd*sumy - sumxy*sumx)/(11*sumxqd - pow(sumx,2));
	return y;
}

int main()
{
	int i;
	float value,a1,a0,Y[11],X[11],sumx=0,sumy=0,sumxy=0,sumxqd=0;

	data = fopen("data.dat","w");

	for(i=0; i<11 ;i++)
	{
		printf("Insira o valor de Y[%i]:", i);
		scanf("%f", &value);
		Y[i] = value;

		printf("Insira o valor de X[%i]:", i);
                scanf("%f", &value);
		X[i] = value;

		fprintf(data,"%.3f %.3f\n",Y[i],X[i]);
	}
	
	for(i=0; i < 11; i++)
	{	
		sumx = sumx + X[i];
		sumy = sumy + Y[i];
		sumxy = sumxy + (X[i]*Y[i]);
		sumxqd = sumxqd + pow(X[i],2);
	}

	a1=func1(sumx,sumy,sumxy,sumxqd);
	a0=func0(sumx,sumy,sumxy,sumxqd);

	printf("\nEQUACAO OBTIDA: p = %.5f T + %.5f\n",a1,a0);

	fclose(data);
	return 0;
}
