#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

//map equation
double f(double x,double mu,int k){
	return mu*(1-2*pow(fabs(x),k));
}

//map equation derivative
double g(double x, double mu,int k){
	return -2*mu*k*pow(fabs(x),k-1);
}

int main(){
	srand(time(0));
	int n=1500,m=10000,k=2;
	double x,mu,lyapunovExponent;
	FILE *fptr;
	FILE *fptr1;
	FILE *fptr2;
	fptr=fopen("/home/vikas/Desktop/work/data.txt","w");
	fptr1=fopen("/home/vikas/Desktop/work/data1.txt","w");
	fptr2=fopen("/home/vikas/Desktop/work/data2.txt","w");
	for(int j=0;j<m;j++){
		mu=1*j*pow(m,-1);
		fprintf(fptr1,"%f\n",mu);
		x=(rand())*pow(RAND_MAX,-1);
		lyapunovExponent=0;
		for(int i=0;i<n;i++){
			if(i>300){
				lyapunovExponent = lyapunovExponent + log(fabs(g(x,mu,k)));
				fprintf(fptr,"%f\t",x);
			}
			x=f(x,mu,k);
		}
		fprintf(fptr,"\n");
		lyapunovExponent = lyapunovExponent*pow(n,-1);
		fprintf(fptr2,"%f\n",lyapunovExponent);
	}
	fclose(fptr);
	fclose(fptr1);
	fclose(fptr2);
	return 0;
}
