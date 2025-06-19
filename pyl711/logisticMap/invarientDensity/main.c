#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

double f(double x){
	return 4*x*(1-x);
}

int main(){
	srand(time(0));
	//n = no. of iterations
	int n=10000000;
	double x;
	FILE *fptr;
	fptr=fopen("/home/vikas/Desktop/work/data.txt","w");
	x=(rand())*pow(RAND_MAX,-1);
	for(int i=0;i<n;i++){
		fprintf(fptr,"%f\n",x);
		x=f(x);
	}			
	fclose(fptr);
	return 0;
}
