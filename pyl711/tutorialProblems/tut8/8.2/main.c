#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

double f(double x){
	return 4*x*(1-x);
}

int main(){
	FILE *fptr;
	fptr=fopen("/home/vikas/Desktop/work/data.txt","w");
	
	int n=100000;
	double x,y,temp,e=0.6;
	srand(time(0));
	x=(rand())*pow(RAND_MAX,-1);
	y=(rand())*pow(RAND_MAX,-1);
	
	for(int i=0;i<n;i++){
		temp=x;
		x=(1-e)*f(x)+e*f(y);
		y=(1-e)*f(y)+e*f(x);
		fprintf(fptr,"%f\t%f\n",x,y);
	}
	
	fclose(fptr);
	return 0;
}
