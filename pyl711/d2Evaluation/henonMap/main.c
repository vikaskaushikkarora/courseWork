#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

double fx(double x, double y){
	return 1-1.4*x*x+y;
}

double fy(double x, double y){
	return 0.3*x;
}

double distance(double x1,double y1,double x2,double y2){
	return pow(((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)),0.5);
}

int main(){
	srand(time(0));
	int n=500000,m=1000,count=0,randomElement;
	double A[n][2],temp=1,a,c,y=(rand())*pow(RAND_MAX,-1);
	randomElement=y*n;
	
	FILE *fptr;
	FILE *fptr1;
	fptr=fopen("/home/vikas/Desktop/work/data.txt","w");
	fptr1=fopen("/home/vikas/Desktop/work/data1.txt","w");
	
	A[0][0]=1;
	A[0][1]=1;
	
	for(int i=0;i<100;i++){
		temp=A[i][0];
		A[i+1][0]=fx(A[i][0],A[i][1]);
		A[i+1][1]=fy(temp,A[i][1]);
	}
	
	for(int i=100;i<n-1;i++){
		temp=A[i][0];
		A[i+1][0]=fx(A[i][0],A[i][1]);
		A[i+1][1]=fy(temp,A[i][1]);
		fprintf(fptr1,"%f\t%f\n",A[i][0],A[i][1]);
	}
	
	for(int k=0;k<m;k++){
		count=0;
		a=0.1*k/m;
			for(int j=100;j<n;j++){
					if(distance(A[randomElement][0],A[randomElement][1],A[j][0],A[j][1])<a){
						count=count+1;
					}
			}
		fprintf(fptr,"%f\t%d\n",a,count);
		printf("Process Completed %d out of %d\n",k,m);
	}
	fclose(fptr);
	fclose(fptr1);
	return 0;
}

