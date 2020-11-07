#include <stdio.h>
#include <stdlib.h>

double quadrado(double x){
	return x*x;
}

double cubo(double x){
	return x*x*x;
}

double operacao(double f(), double x){
	return f(x);
}

int main(int argc, int **argv){
	
	double x = atof(argv[1]);

	if (argc<2) return 1;

	printf("x = %lf, x² = %lf, x³ = %lf\n", x, operacao(quadrado, x), operacao(cubo, x));
	return 0;

}


