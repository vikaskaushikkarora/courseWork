#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#define M_PI 3.14159265358979323846

float fx1(float x){
	if(x>0 && x<2){
		return 0.5;
	} else{
	return 0;
	}
}

float fx2(float x){
	if(x>0){
		return 0.5*exp(-0.5*x);
	} else{
	return 0;
	}
}

float convolution(float (*func1)(float), float (*func2)(float), float initial, float final, int n, float t){
	float I=0,x=initial;
	float h=(final-initial)/n;
	for(int i=0;i<n;i++){
		I=I+h*func1(x)*func2(t-x);
		x=x+h;
	}
	return I;
}
