// Include required libraries
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Various Constants for Hydrogen
#define a (double) 0.2420
#define b (double) 2.652e-2
#define Tc (double) 33.23 // critical temperature in Kelvin

// Other Constants
#define R (double) 0.08206 // Gas Constant
#define T (double) 28 // Temperature in Kelvin
#define NUM (long) 1e5 // resolution for volume array
#define Vinitial (double) 1.5*b // initial value for volume
#define Vfinal (double) 20*b // final value for volume
#define STEPSIZE (double) (Vfinal-Vinitial)/NUM

// Van der Waals equation of state for pressure
double f(double x){
	return (R*T/(x-b))-a*pow(x,-2);
}

// Define an integrate function
double integrate(double* ind, double* dep, long initial, long final){ // ind : independent variable, dep : dependent variable
	double value=0;
	double h;
	for(long i=initial;i<final;i++){
		h=dep[i]-dep[i-1];
		value += ind[i]*h;
	}
	return value;
}

int main(){
	system("mkdir -p data");
	FILE* fp = fopen("data/a.dat","w"); // open a file to write into

	// Make the array for the volume and pressure according to Van der Waals eqn
	double* V = malloc(NUM*sizeof(double)); // volume
	double* P = malloc(NUM*sizeof(double)); // pressure
	for(long i=0;i<NUM;i++){
		V[i]=Vinitial+STEPSIZE*i;
		P[i]=f(V[i]);
	}

	//We are calculating the points to define the function piecewise when we integrate it over P where it will be multivalued
	// calculate the point where the curve makes a u-turn
	long numB=1;
	while(P[numB]<P[numB-1]){
		numB += 1;
	}
	// calculate the point where the curve makes the u turn again
	long numC=numB+1000;
	while(P[numC]>P[numC-1]){
		numC += 1;
	}

	// Check wether we get the points right
	printf("%ld %ld %ld\n",NUM,numB,numC);

	// Calculate Mu with integration
	double* mu = malloc(NUM*sizeof(double)); // allot memory for mu
	mu[0]=10; // Initiallise the value of mu
	for(long i=1;i<numB;i++){ 
		mu[i]=mu[0]+integrate(V,P,1,i); // calculate mu
		fprintf(fp,"%0.10lf %0.10lf\n",P[i],mu[i]); // store P and mu value to plot them ahead
	}
	for(long i=numB;i<numC;i++){
		mu[i]=mu[numB-1]+integrate(V,P,numB-1,i);
		fprintf(fp,"%0.10lf %0.10lf\n",P[i],mu[i]);
	}
	for(long i=numC;i<NUM;i++){
		mu[i]=mu[numC-1]+integrate(V,P,numC-1,i);
		fprintf(fp,"%0.10lf %0.10lf\n",P[i],mu[i]);
	}

	// free the pointers and memory while exiting the programme
	free(V);
	free(P);
	free(mu);
	fclose(fp);
	return 0;
}
