#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

double fx(double x,double y,double z){
	return -y-z;
}

double fy(double x,double y,double z){
	return x+0.2*y;
}

double fz(double x,double y,double z){
	return 0.2+z*(x-5.7);
}

double dis(double x1,double x2,double y1,double y2,double z1,double z2){
	return pow((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1),0.5);
}

int main(){
	srand(0);
	int n=110000,m=100,count,random=1000*(rand())*pow(RAND_MAX,-1);
	double t=0,h=0.01,x=5,y=5,z=10,X[1000],Y[1000],Z[1000],r[1000],e;
	
	FILE *fptr;
	fptr=fopen("/home/vikas/Desktop/work/data.txt","w");
	FILE *fptr1;
	fptr1=fopen("/home/vikas/Desktop/work/data1.txt","w");
	
	for(int i=0;i<10000;i++){
		t=t+h;
		x=x+h*fx(x,y,z);
		y=y+h*fy(x,y,z);
		z=z+h*fz(x,y,z);
	}
	
	for(int i=10000;i<n;i++){
		t=t+h;
		x=x+h*fx(x,y,z);
		y=y+h*fy(x,y,z);
		z=z+h*fz(x,y,z);
		if((i%100)==0){
			X[(i-10000)/100]=x;
			Y[(i-10000)/100]=y;
			Z[(i-10000)/100]=z;
			fprintf(fptr1,"%f\t%f\t%f\n",x,y,z);
		}
	}
	
	for(int i=0;i<1000;i++){
		r[i]=dis(X[i],X[random],Y[i],Y[random],Z[i],Z[random]);
	}
	
	for(int i=0;i<m;i++){
		e=20*i*pow(m,-1);
		count=0;
		for(int j=0;j<1000;j++){
			if(r[j]<e){
				count=count+1;
			}
		}
		fprintf(fptr,"%f\t%d\n",e,count);
	}
	
	fclose(fptr);
	fclose(fptr1);
	return 0;
}

