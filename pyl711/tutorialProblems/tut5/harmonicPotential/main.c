#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(double x, double y,double a){
	return x+a*y;
}

int main(){
	double a=13*pow(6,-1);
	int nx=4000,ny=nx/a;
	printf("%d\n",ny);
	double x,y,E;
	
	FILE *fptr;
	fptr = fopen("/home/vikas/Desktop/work/data.txt","w");
	
	for(int i=1;i<nx;i++){
		x=i;
		for(int j=1;j<ny;j++){
			y=j;
			E=f(x,y,a);
			fprintf(fptr,"%f\n",E);
		}
	}
	fclose(fptr);
	return 0;
}

