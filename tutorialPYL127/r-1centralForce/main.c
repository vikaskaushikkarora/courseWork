#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define m (double) 1 // mass of the particle
#define k (double) 10 // gravitational strength
#define TIMESTEPS (long) 30000
#define STEPSIZE (double) 0.001

double fx(double x, double y){
	return -k*x*pow((x*x+y*y),-1);
}

double fy(double x, double y){
	return -k*y*pow((x*x+y*y),-1);
}

int main(){
	FILE* fp = fopen("a.dat","w");
	double x=1;
	double y=1;
	double vx=-5;
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
