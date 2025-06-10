#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Various Constants for Hydrogen
#define a (double) 0.2420
#define b (double) 2.652e-2
#define Tc (double) 33.23 // critical temperature in Kelvin

// Other Constants
#define R (double) 0.08206 // Gas Constant
#define NUM (long) 1e6 // resolution for volume array
#define Vinitial (double) 1.6*b // initial value for volume
#define Vfinal (double) 20*b // final value for volume
#define STEPSIZE (double) (Vfinal-Vinitial)/NUM

// Van der Waals equation of state for pressure
double f(double x, double T){
	return (R*T/(x-b))-a*pow(x,-2);
}

// generate data to plot for one isotherm with temperature T
void generateData(double T){
	system("mkdir -p data");
	char filename[50];
	sprintf(filename,"data/%0.0lf.dat",T);
	FILE* fp = fopen(filename,"w");
	double* V = malloc(NUM*sizeof(double));
	double* P = malloc(NUM*sizeof(double));
	for(long i=0;i<NUM;i++){
		V[i]=Vinitial+STEPSIZE*i;
		P[i]=f(V[i],T);
		fprintf(fp,"%0.10lf %0.10lf\n",V[i],P[i]);
	}
	free(V);
	free(P);
	fclose(fp);
}

int main(){
	long N=7;
	double T[N];
	for(long i=0;i<N;i++){
		T[i]=30+i;
		generateData(T[i]);
	}
}
