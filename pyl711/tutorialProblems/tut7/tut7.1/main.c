#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double fx(double x,double y,double z){
	return -y-z;
}

double fy(double x,double y,double z){
	return x+0.2*y;
}

double fz(double x,double y,double z){
	return 0.2+z*(x-5.7);
}

int main(){
	int n=110000;
	double t=0,h=0.01,x=5,y=5,z=10;
	
	FILE *fptr;
	fptr=fopen("/home/vikas/Desktop/work/data.txt","w");

	for(int i=0;i<100;i++){
		t=t+h;
		x=x+h*fx(x,y,z);
		y=y+h*fy(x,y,z);
		z=z+h*fz(x,y,z);
	}
	
	for(int i=100;i<n;i++){
		t=t+h;
		x=x+h*fx(x,y,z);
		y=y+h*fy(x,y,z);
		z=z+h*fz(x,y,z);
		fprintf(fptr,"%f\t%f\t%f\t%f\n",t,x,y,z);
	}
	
	fclose(fptr);
	return 0;
}
