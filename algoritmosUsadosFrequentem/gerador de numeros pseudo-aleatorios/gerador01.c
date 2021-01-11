#include <stdio.h>

#define TAM 1000000

FILE *arquivo;

int main()
{
	int i;
	float rn,x,y;
	unsigned R=82372837, seed=37633231;

	arquivo = fopen("saida.dat","w");

	for(i=0;i<TAM;i++)
	{
		R = R*seed;
		rn = R/4294967295.0;  //".0" no final para o denominador virar float
		x=rn;
		R=R*seed;
		rn = R/4294967295.0;
		y=rn;
		fprintf(arquivo,"%.10f\t%.10f\n",x,y);
	}

	fclose(arquivo);
	return 0;
}
	
