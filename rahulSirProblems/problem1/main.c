#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(){
	srand(time(0));
	FILE *fptr;
	FILE *fptr1;
	fptr=fopen("/home/vikas/Desktop/work/data.txt","w");
	fptr1=fopen("/home/vikas/Desktop/work/data1.txt","w");
	int n=100,m=500000;
	//n=iteration
	//m=no. of points
	double y,x,lambda=0.5,limit=1+lambda*pow(1-lambda,-1);
	for(int j=0;j<m;j++){
		x=0;
		for(int i=0;i<n;i++){
			y=(rand())*pow(RAND_MAX,-1);
			if(y>0.5){
				x=x+pow(lambda,i);
			}
			else{
				x=x-pow(lambda,i);
			}
			fprintf(fptr,"%f\n",x);
		}
	}
	fprintf(fptr1,"%f\n",limit);
	fprintf(fptr1,"%f\n",lambda);
	fclose(fptr);
	fclose(fptr1);
	return 0;
}
