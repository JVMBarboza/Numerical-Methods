//x = somatorio(a*somatorio b)
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,j,n1,ch,sum1=0,sum2=0,acres;

	printf("Olá! Insira a quantidade de elementos do primeiro somatório:");
	scanf("%i", &n1);

	for(i=0;i<n1;i++)
	{
		printf("\nInsira o número:");
		scanf("%i",&ch);
		sum1 = sum1 + ch;
	}

	
	printf("Insira a quantidade de elementos do segundo somatório:");
        scanf("%i", &n1);

	for(j=0;j<n1;j++)
        {
                printf("\nInsira o número:");
                scanf("%i",&ch);
				acres = ch*sum1;
                sum2 = sum2 + acres;
        }

	printf("\nProduto entre os somatórios:%i\n",sum1*sum2);

}
