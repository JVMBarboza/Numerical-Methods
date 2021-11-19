//somatorio i somatorio j (aibj)
#include <stdio.h>

int main()
{
	int i,j,n1,n2,sum1=0,sum2=0,ch1,ch2,ch;

	printf("Informe o tamanho do somatório que roda com i:");
	scanf("%i", &n1);

	printf("Informe o tamanho do somatório que roda com j:");
	scanf("%i", &n2);

    for(i=0; i<n1 ;i++){

	printf("Insira o valor do a:");
			scanf("%i",&ch1);

	for(j=0; j<n2 ;j++){
		if(i!=j){

			printf("Insira o valor do b:");
			scanf("%i", &ch2);
	
			ch = ch1*ch2;
			sum2 = sum2 + ch;
		}
	}

	sum1 = sum1 + sum2;
	sum2 = 0;
	
	}

	return 0;
}
