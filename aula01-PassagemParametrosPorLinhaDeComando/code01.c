#include <stdio.h>

int main(int argc, int **argv){
	int i;

	printf("Nº de argumentos:%d\n",argc);

	for(i=0;i<argc;i++) printf("%s\n",argv[i]);

	return 0;

}
