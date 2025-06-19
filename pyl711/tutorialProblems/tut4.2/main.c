#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

double fx(double x, double vx){
	return vx;
}

double fvx(double x, double vx){
	double mu=1;
	return mu*(1-x*x)*vx-x;
}

int main(){
	//n=no. of time steps,mx=values forx,my=values for y
	int n=10000,mx=10,mvx=10;
	double t=0,x,vx,h=0.001;

	FILE *fptr;
	FILE *fptr1;
	fptr = fopen("/home/vikas/Desktop/work/data.txt","w");
	fptr1 = fopen("/home/vikas/Desktop/work/data1.txt","w");
	fprintf(fptr1,"%d\t%d\t%d",n,mx,mvx);
	fclose(fptr1);
	
	for(int j=0;j<mx;j++){
		for(int k=0;k<mvx;k++){
			x=-5+10*j*(pow(mx,-1));
			vx=-5+10*k*(pow(mvx,-1));
			for(int i=0;i<n;i++){
				t=t+h;
				x=x+h*fx(x,vx);
				vx=vx+h*fvx(x,vx);
				fprintf(fptr,"%f\t%f\n",x,vx);
			}
		}
	}
	fclose(fptr);
	return 0;
}
