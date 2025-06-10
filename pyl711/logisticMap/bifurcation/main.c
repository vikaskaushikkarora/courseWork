#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(double x,double mu){
	return mu*x*(1-x);
}

int main(){
	//l = no. of values of mu
	//n = no. of iterations
	//m = no. of values of x
	int l=8000,n=1000,m=3; 
	double x,mu;
	FILE *fptr;
	FILE *fptr1;
	fptr=fopen("/home/vikas/Desktop/work/data.txt","w");
	fptr1=fopen("/home/vikas/Desktop/work/data1.txt","w");
	for(int k=0;k<l;k++){
		mu=4*k*pow(l,-1);
		fprintf(fptr1,"%f\t",mu);
		for(int j=0;j<m;j++){
			x=0+j*pow(m,-1);
			for(int i=0;i<n;i++){
				x=f(x,mu);
				if((n-i)<500){
					fprintf(fptr,"%f\t",x);
				}
			}
		}			
		fprintf(fptr,"\n");
	}
	fclose(fptr);
	fclose(fptr1);
}
