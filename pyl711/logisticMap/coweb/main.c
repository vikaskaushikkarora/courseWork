#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(double x){
	return 3.56*x*(1-x);
}

int main(){
	int n=50,m=1000;
	double x1=0.3263,y1,x,y;
	FILE *fptr1;
	FILE *fptr2;
	fptr1 = fopen("/home/vikas/Desktop/work/datax1.txt","w");
	fptr2 = fopen("/home/vikas/Desktop/work/mapdata.txt","w");
	
	for(int i=0;i<n;i++){
		fprintf(fptr1,"%f\n",x1);
		x1=f(x1);
	}

	for(int i=0;i<m;i++){
		x=-4+(4-(-4))*i*pow(m,-1);
		y=f(x);
		fprintf(fptr2,"%f\t%f\n",x,y);
	}

	fclose(fptr1);
	fclose(fptr2);
	return 0;
}

