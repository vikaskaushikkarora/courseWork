#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(){
	srand(time(0));
	FILE *fptr;
	FILE *fptr1;
	FILE *fptr2;
	fptr=fopen("/home/vikas/Desktop/work/data.txt","w");
	fptr1=fopen("/home/vikas/Desktop/work/data1.txt","w");
	fptr2=fopen("/home/vikas/Desktop/work/data2.txt","w");
	
	int n=40000000;
	double x0=0,y0=0,x1=1,y1=0,x2=1,y2=1,x3=0,y3=1,x4=0.5,y4=0.5;
	fprintf(fptr1,"%f\t%f\t%f\t%f\t%f\n",x0,x1,x2,x3,x4,x1);
	fprintf(fptr2,"%f\t%f\t%f\t%f\t%f\n",y0,y1,y2,y3,y4,y1);
	double x,y,a,b,rn;
	x=0.1;
	y=0.1;
	
	for(int i=0;i<n;i++){
		rn=(rand())*pow(RAND_MAX,-1);
		if(rn<0.20){
			a=x0;
			b=y0;
			x=0.5*(a+x);
			y=0.5*(b+y);
		} else if(rn>0.2 && rn<0.4){
			a=x1;
			b=y1;
			x=0.5*(a+x);
			y=0.5*(b+y);
		} else if(rn>0.4 && rn<0.6){
			a=x2;
			b=y2;
			x=0.5*(a+x);
			y=0.5*(b+y);
		} else if(rn>0.6 && rn<0.8){
			a=x3;
			b=y3;
			x=0.5*(a+x);
			y=0.5*(b+y);
		} else{
			a=x4;
			b=y4;
			x=0.5*(a+x);
			y=0.5*(b+y);
		}
		fprintf(fptr,"%f\t%f\n",x,y);
	}
	
	fclose(fptr);
	fclose(fptr1);
	return 0;
}
