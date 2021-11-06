#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

	double base, altura, area;

	if (argc<3) return 1;

	base = atof(argv[1]);
	altura = atof(argv[2]);
	area = base*altura;

	printf("Dados base %g e altura %g a area calculada é:%g\n",base, altura, area);
	return 0;
}
