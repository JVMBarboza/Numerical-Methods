#include <stdio.h>
#include <math.h>

#define grav 9.8

double func( double theta, double x, double vel_init, double h)
{
	return( h + x*tan(theta) - (x*x*grav)/( 2*(vel_init*vel_init)*(cos(theta)*cos(theta))));
}

int main()
{	
	double y1, y2, T, theta, x, vel_init = 15.2, height = 1.82;
	int chave=0;

	for(theta = 0; theta <= M_PI/2; theta=theta+0.1)
	{
		y1 = func(theta, 0, vel_init, height);
		if ( y1 == 1.82)
			chave++;
			
		y2 = func(theta, 18.2, vel_init, height);	
		if ( y2 == 2.1 )
			chave++; 			
	
		if(chave == 2)
			T = theta;
		else
			chave = 0;
	}
	
	if (chave == 0)
		printf("\nNão encontrou.");
	else
		printf("\n Theta = %lf", &T);
	
	
	return 0;
}
