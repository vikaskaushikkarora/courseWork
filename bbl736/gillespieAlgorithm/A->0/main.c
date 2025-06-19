// Gillespie Algorithm for A -> 0

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<pthread.h>

#define numSteps 500
#define rateRXN 1
#define numEnsemble 500

int A[numEnsemble];
float t[numEnsemble];
float dt[numEnsemble];

int main(){
	srand(time(0));
	FILE *fptr = fopen("/home/vikas/work/data.txt","w");
	FILE *fptr1 = fopen("/home/vikas/work/data1.txt","w");
	
	for(int j=0;j<numEnsemble;j++){
		A[j]=numSteps;
		t[j]=0;
		fprintf(fptr,"%f\t%d\t",t[j],A[j]);
	}
	fprintf(fptr,"\n");
	
	float r;
	for(int i=0;i<numSteps;i++){
		for(int j=0;j<numEnsemble;j++){
			r=rand()*pow(RAND_MAX,-1);
			dt[j]=-(log(1-r)/(rateRXN*A[j]));
			//dt[j]=pow(rateRXN*A[j],-1);
			fprintf(fptr1,"%f\t",dt);
			A[j] -= 1;
			t[j] += dt[j];
			fprintf(fptr,"%f\t%d\t",t[j],A[j]);
		}
		fprintf(fptr,"\n");
		fprintf(fptr1,"\n");
	}
	fclose(fptr);
	fclose(fptr1);
	return 0;
}
