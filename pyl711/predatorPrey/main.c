#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

double fx(double x, double y){
	double alpha=2.0/3.0,beta=4.0/3.0;
	return alpha*x-beta*x*y;
}

double fy(double x, double y){
	double gamma=1.0,delta=1.0,epsilon=0;
	return delta*x*y-gamma*y-epsilon*y*y;
}

int main(){
	//n=no. of time steps,mx=no. of steps for x,my=no. of steps for y
	int n=20000,mx=15,my=15;
	double t=0,x,y,h=0.001;
	
	FILE *fptr;
	FILE *fptr1;
	fptr = fopen("/home/vikas/Desktop/work/data.txt","w");
	fptr1 = fopen("/home/vikas/Desktop/work/data1.txt","w");
	fprintf(fptr1,"%d\t%d\t%d",n,mx,my);
	fclose(fptr1);
	
	for(int j=0;j<mx;j++){
		for(int k=0;k<my;k++){
			x=5*j*(pow(mx,-1));
			y=5*k*(pow(my,-1));
			for(int i=0;i<n;i++){
				t=t+h;
				x=x+h*fx(x,y);
				y=y+h*fy(x,y);
				fprintf(fptr,"%f\t%f\n",x,y);
			}
		}
	}
	
	fclose(fptr);
	return 0;
}
