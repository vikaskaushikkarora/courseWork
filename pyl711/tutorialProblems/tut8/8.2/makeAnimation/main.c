#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

double f(double x){
	return 4*x*(1-x);
}

int main(){
	FILE *fptr;
	FILE *fptr1;
	fptr=fopen("/home/vikas/Desktop/work/data.txt","w");
	fptr1=fopen("/home/vikas/Desktop/work/data1.txt","w");
	
	int m=100000,n=1000;
	double x,y,temp,e=0;
	fprintf(fptr1,"%d\t%d",n,m);
	
	srand(time(0));
	for(int j=0;j<n;j++){
		e=j*pow(n,-1);
		x=(rand())*pow(RAND_MAX,-1);
		y=(rand())*pow(RAND_MAX,-1);
		for(int i=0;i<100;i++){
			temp=x;
			x=(1-e)*f(x)+e*f(y);
			y=(1-e)*f(y)+e*f(x);
		}
		for(int i=100;i<m;i++){
			temp=x;
			x=(1-e)*f(x)+e*f(y);
			y=(1-e)*f(y)+e*f(x);
			fprintf(fptr,"%f\t%f\n",x,y);
		}
		printf("Process completed %d out of %d\n",j,n);
	}
	
	fclose(fptr);
	fclose(fptr1);
	return 0;
}

