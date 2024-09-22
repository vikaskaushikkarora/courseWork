#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

double map(double x){
	return 4*x*(1-x);
}

int main(){
	FILE *fptr;
	fptr=fopen("/home/vikas/Desktop/work/data.txt","w");
	
	int n=1000000;
	double x,y;
	srand(time(0));
	x=(rand())*pow(RAND_MAX,-1);
	y=(rand())*pow(RAND_MAX,-1);
	
	for(int i=0;i<n;i++){
		x=map(x);
		y=map(y);
		fprintf(fptr,"%f\t%f\n",x,y);
	}
	
	fclose(fptr);
	return 0;
}
