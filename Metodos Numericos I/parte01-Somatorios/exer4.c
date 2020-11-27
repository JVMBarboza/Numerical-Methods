#include<stdio.h>

FILE *saida;

int main()
{
	float i,value,powed;

	saida = fopen("saida.dat","w");
	for(i=-40;i<=40;i++)
	{
		powed = (i*i)*0.01;
		fprintf(saida,"%.3f \t %.3f\n",i*0.1,powed);
	}

	fclose(saida);
	return 0;
}
