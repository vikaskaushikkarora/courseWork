#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define M_PI 3.14159265358979323846

float f(float x,float t){
	return cos(t+x);
}

float correlation(float t1,float t2, float *x, int N){
	float sum=0,float a,float b;
	for(int i=0;i<N;i++){
		a=f(x[i],t1);
		b=f(x[i],t2);
		sum=sum+a*b;
	}
	sum=sum/N;
	return sum;
}

