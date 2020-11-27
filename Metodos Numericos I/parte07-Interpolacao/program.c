#include <stdio.h>
#include <stdlib.h>

FILE *data;

int main()
{
	int i=0,j=0;
	double X=3,x[5],y[5],f=0,prod = 1;

	data = fopen("data.dat","w");

	while(i<5)
	{
		printf("\nInsira x[%i]:",i);
		scanf("%lf", &x[i]);

		printf("\nInsira y[%i]:",i);
                scanf("%lf", &y[i]);
		i++;

		fprintf(data,"%g\t%g\n",x[i],y[i]);
	}

	for(i=0;i<5;i++) //n=5 (tamanho dos dados)
	{
		j=0;
		prod = 1;
		
		while(j<5)
		{
			if(j!=i)
			{
				prod = prod*(X-x[j])/(x[i]-x[j]);
			}
			j++;
		}	
	
		f = f + y[i]*prod;
	}
	
	printf("\n\nRESULTADO:%lf\n", f);

	return 0;
}


