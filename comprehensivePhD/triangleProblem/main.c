#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(){
	srand(time(0));
	FILE *fptr;
	fptr=fopen("data.txt","w"); // data file for the points obtained
	
	int n=100000; // number of steps
	double x0=0,y0=0,x1=1,y1=0,x2=0.5,y2=(sqrt(3))/2;
	double x,y,a,b,rn;
	x=0.1;
	y=0.1;
	
	for(int i=0;i<n;i++){
		rn=(rand())*pow(RAND_MAX,-1);
		if(rn<pow(3,-1)){ // if the random number lies between 0 and 1/3
			a=x0;
			b=y0;
			x=0.5*(a+x);
			y=0.5*(b+y);
		} else if(rn>pow(3,-1)&& rn<2*pow(3,-1)){  // if the random number lies between 1/3 and 2/3
			a=x1;
			b=y1;
			x=0.5*(a+x);
			y=0.5*(b+y);
		} else{ // if the random number lies between 2/3 and 1
			a=x2;
			b=y2;
			x=0.5*(a+x);
			y=0.5*(b+y);
		}
		fprintf(fptr,"%f\t%f\n",x,y);
	}
	
	fclose(fptr);
	return 0;
}
