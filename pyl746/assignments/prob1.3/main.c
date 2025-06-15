#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

float rE(float lambda){
	float a;
	a=rand()/(RAND_MAX +1.0);
	return -log(1-a)/lambda;
}

int main(){
	srand(time(0));
	FILE* fptr;
	fptr=fopen("/home/vikas/work/data.txt","w");
	
	int n=10000000;
	float *x1 = malloc(n*sizeof(float));
	float *x2 = malloc(n*sizeof(float));
	float *y = malloc(n*sizeof(float));

	for(int i=0;i<n;i++){
		x1[i]=2*(rand()*pow(RAND_MAX,-1));
		x2[i]=rE(0.5);
		y[i]=x1[i]+x2[i];
		fprintf(fptr,"%f\t%f\t%f\n",x1[i],x2[i],y[i]);
	}
	fclose(fptr);
	return 0;
}
