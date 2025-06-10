// Newton's Law of Cooling Versus Normal Cooling

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define STEPS (long) 3e6
#define STEPSIZE (double) 0.01
#define T0 (double) 273
#define EMISSIVITY (double) 1
#define STEFANBOLTZMANNCONSTANT (double) 5.67037442e-8
#define AREAOFTHEBLACKBODY (double) 1e-4
#define MASS (double) 7.874e-3
#define HEATCAPACITY (double) 460.548
#define K (double) EMISSIVITY*STEFANBOLTZMANNCONSTANT*AREAOFTHEBLACKBODY/(MASS*HEATCAPACITY)
#define KNEWTON (double) 4*K*pow(T0,3)

int main(){
	FILE* fp = fopen("a.dat","w");

	double T=300;
	double TNewton=T;
	for(long i=0;i<STEPS;i++){
		T -= STEPSIZE*K*(pow(T,4)-pow(T0,4));
		TNewton -= STEPSIZE*KNEWTON*(TNewton-T0);
		fprintf(fp,"%lf %lf %lf\n",i*STEPSIZE,T,TNewton);
	}
	
	fclose(fp);
	return 0;
}
