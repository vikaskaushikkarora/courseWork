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
	
	int n=1000000;
	double x0=0,y0=0,x1=1,y1=0,x2=0.5,y2=(sqrt(3))/2;
	fprintf(fptr1,"%f\t%f\t%f\t%f\n",x0,x1,x2,x0);
	fprintf(fptr2,"%f\t%f\t%f\t%f\n",y0,y1,y2,y0);
	double x,y,a,b,rn;
	x=0.1;
	y=0.1;
	
	for(int i=0;i<n;i++){
		rn=(rand())*pow(RAND_MAX,-1);
		if(rn<pow(3,-1)){
			a=x0;
			b=y0;
			x=0.5*(a+x);
			y=0.5*(b+y);
		} else if(rn>pow(3,-1)&& rn<2*pow(3,-1)){
			a=x1;
			b=y1;
			x=0.5*(a+x);
			y=0.5*(b+y);
		} else{
			a=x2;
			b=y2;
			x=0.5*(a+x);
			y=0.5*(b+y);
		}
		fprintf(fptr,"%f\t%f\n",x,y);
	}
	
	fclose(fptr);
	fclose(fptr1);
	return 0;
}
