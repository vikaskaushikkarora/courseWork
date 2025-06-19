#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define m (double) 1 // mass of the particle
#define k (double) 10 // gravitational strength
#define h (double) 0.05 // r3 strength correction term
#define TIMESTEPS (long) 100000
#define STEPSIZE (double) 0.0001

double fx(double x, double y){
	return -k*x*pow((x*x+y*y),-1.5) + 2*h*x*pow((x*x+y*y),-2);
}

double fy(double x, double y){
	return -k*y*pow((x*x+y*y),-1.5) + 2*h*y*pow((x*x+y*y),-2);
}

int main(){
	FILE* fp = fopen("a.dat","w");
	double x=1;
	double y=1;
	double vx=-0.5;
	double vy=1;

	for(int i=0;i<TIMESTEPS;i++){
		vx += STEPSIZE*fx(x,y)/m;
		vy += STEPSIZE*fy(x,y)/m;
		x += STEPSIZE*vx;
		y += STEPSIZE*vy;
		fprintf(fp,"%lf %lf\n",x,y);
	}
	fclose(fp);
	return 0;
}
