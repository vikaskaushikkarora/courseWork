#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

double fx(int j,int m){
	double a;
	for(int i=0;i<j+1;i++){
		a=cos(2*M_PI*i*pow(m,-1));
	}
	return a;
}

double fy(int j,int m){
	double b;
	for(int i=0;i<j+1;i++){
		b=sin(2*M_PI*i*pow(m,-1));
	}
	return b;
}

int main(){
	srand(time(0));
	FILE *fptr;
	FILE *fptr1;
	FILE *fptr2;
	fptr=fopen("/home/vikas/Desktop/work/data.txt","w");
	fptr1=fopen("/home/vikas/Desktop/work/data1.txt","w");
	fptr2=fopen("/home/vikas/Desktop/work/data2.txt","w");
	
	int n=40000000,m=5,val;
	double x0,y0,rn,num,a,b,x=0.1,y=0.1;
	for(int i=0;i<m+1;i++){
		x0=cos(2*M_PI*i*pow(m,-1));
		y0=sin(2*M_PI*i*pow(m,-1));
		fprintf(fptr1,"%f\n",x0);
		fprintf(fptr2,"%f\n",y0);
	}
	fclose(fptr1);
	fclose(fptr2);
	
	for(int i=0;i<n;i++){
		rn=(rand())*pow(RAND_MAX,-1);
		num=pow(m,-1);
		val=0;
		while(rn>num){
			rn=rn-num;
			val=val+1;
		}
		a=fx(val,m);
		b=fy(val,m);
		x=0.5*(a+x);
		y=0.5*(b+y);
		fprintf(fptr,"%f\t%f\n",x,y);
	}
	fclose(fptr);
	return 0;
}
