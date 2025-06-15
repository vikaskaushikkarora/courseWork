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

double fdx(double x,double y,double z, double dx,double dy,double dz){
	return -dy-dz;
}

double fdy(double x,double y,double z, double dx,double dy,double dz){
	return dx+0.2*dy;
}

double fdz(double x,double y,double z, double dx,double dy,double dz){
	return z*dx+(x-5.7)*dz;
}

double mod(double a,double b,double c){
	return pow((a*a+b*b+c*c),0.5);
}

int main(){
	int n=100000;
	double t=0,h=0.01,x=25,y=15,z=20,dx=1,dy=0,dz=0,le=0,modulus;

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
		dx=dx+h*fdx(x,y,z,dx,dy,dz);
		dy=dy+h*fdy(x,y,z,dx,dy,dz);
		dz=dz+h*fdz(x,y,z,dx,dy,dz);
		modulus=mod(dx,dy,dz);
		le=le+log(modulus);
		dx=dx*pow(modulus,-1);
		dy=dy*pow(modulus,-1);
		dz=dz*pow(modulus,-1);
	}
	le=le*pow(t,-1);
	
	/*
	for(int i=100;i<n;i++){
		t=t+h;
		x=x+h*fx(x,y,z);
		y=y+h*fy(x,y,z);
		z=z+h*fz(x,y,z);
		dx=dx+h*fdx(x,y,z,dx,dy,dz);
		dy=dy+h*fdy(x,y,z,dx,dy,dz);
		dz=dz+h*fdz(x,y,z,dx,dy,dz);
	}
	le=log(mod(dx,dy,dz))*pow(t,-1);
	*/
	
	printf("Lypunov Exponent is : %f\n",le);
	return 0;
}
