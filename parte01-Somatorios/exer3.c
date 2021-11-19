#include <stdio.h>

int main()
{
	int N,prod=1,i,ch;
	
	printf("Insira o tamanho do produtório:");
	scanf("%i",&N);

	for(i=0;i<N;i++){
		
		printf("Insira o valor do termo [%i] do produtório:",i+1);
		scanf("%i\n",&ch);

		prod = prod*ch;
	}
	printf("Valor do produtório:%i\n",prod);

	return 0;
}
