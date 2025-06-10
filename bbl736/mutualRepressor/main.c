#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define ALPHA 4
#define COOP 2 // Cooperativity
#define STEPS 2000 // time-STEPS
#define STEPSIZE 0.001
#define MX 70
#define MY 70

double fx(double x, double y){
	return ALPHA/(1+pow(y,COOP))-x;
}

double fy(double x, double y){
	return ALPHA/(1+pow(x,COOP))-y;
}

int main(){
	double t=0,x,y;
	FILE* fptr = fopen("/home/vikas/Desktop/work/data.txt","w");
	FILE* fptr1 = fopen("/home/vikas/Desktop/work/data1.txt","w");
	fprintf(fptr1,"%d\t%d\t%d",STEPS,MX,MY);
	fclose(fptr1);
	
	for(int j=0;j<MX;j++){
		for(int k=0;k<MY;k++){
			x=0.01+4.5*j*(pow(MX,-1));
			y=0.01+4.5*k*(pow(MY,-1));
			for(int i=0;i<STEPS;i++){
				x=x+STEPSIZE*fx(x,y);
				y=y+STEPSIZE*fy(x,y);
				t += STEPSIZE;
				fprintf(fptr,"%f\t%f\n",x,y);
			}
		}
	}
	fclose(fptr);
	return 0;
}
