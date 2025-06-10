// Deterministic Version Of Autoactivator Genetic Circuit

// Include Libraries
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

// Define constants
#define coop 2 // Cooperativity
#define decayConstant 1
#define alpha 5
#define timeSteps 10000
#define stepSize 0.001

// Define the function
double f(double x){
	return (alpha*pow(x,2)/(1+pow(x,2)))-decayConstant*x;
}

// Main function
int main(int argc,char* argv[]){
	FILE* fptr = fopen("/home/vikas/work/data.txt","w");
	double P = 2; //initial value of P
	double t = 0,k1,k2,k3,k4;
	
	// Time evolution
	for(int i=0;i<timeSteps;i++){
		//Runge Kutta 4th order
		k1=f(P);
		k2=f(P+0.5*stepSize*k1);
		k3=f(P+0.5*stepSize*k2);
		k4=f(P+stepSize*k3);
		P += stepSize*(k1+2*k2+2*k3+k4)/6;
		t += stepSize;
		fprintf(fptr,"%lf\t%lf\n",t,P);
	}
	
	fclose(fptr);
	return 0;
}
