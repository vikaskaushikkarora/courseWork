#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
//map equation
double f(double x,double mu){
	return mu*x*(1-x);
}
//map equation derivative
double g(double x, double mu){
	return mu*(1-2*x);
}

int main(){
	srand(time(0));
	int n=1500,m=4000; 
	double x,mu,lyapunovExponent;
	FILE *fptr;
	FILE *fptr1;
	fptr=fopen("/home/vikas/Desktop/work/data.txt","w");
	fptr1=fopen("/home/vikas/Desktop/work/data1.txt","w");
	for(int j=0;j<m;j++){
		mu=4*j*pow(m,-1);
		fprintf(fptr1,"%f\n",mu);
		x=(rand())*pow(RAND_MAX,-1);
		lyapunovExponent=0;
		for(int i=0;i<n;i++){
			lyapunovExponent = lyapunovExponent + log(fabs(g(x,mu)));
			x=f(x,mu);
		}
		lyapunovExponent = lyapunovExponent*pow(n,-1);
		fprintf(fptr,"%f\n",lyapunovExponent);
	}
	fclose(fptr);
	fclose(fptr1);
	return 0;
}
