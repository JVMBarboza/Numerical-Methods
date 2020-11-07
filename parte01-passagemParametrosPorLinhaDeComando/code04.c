#include <stdio.h>
#include <stdlib.h>

typedef double (*sistfunc)();

double f1(double x, double y){ return x+y; }
double f2(double x, double y){ return x*y; }
double f3(double x, double y){ return x/y; }

int main(int argc, int **argv){
	
	sistfunc eq[3] = {f1,f2,f3};

	double x = atof(argv[1]), y = atof(argv[2]);
	int i;

	if (argc < 3) return 1;

	for(i=0; i<3; i++){
		printf("%lf\n",eq[i](x,y));
	}
	return 0;

}
