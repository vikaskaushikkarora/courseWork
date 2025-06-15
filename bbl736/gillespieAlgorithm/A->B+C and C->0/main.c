// Gillespie Algorithm for A->B+C & C->0

// Include Libraries
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<pthread.h>

// Define Parameters
#define numSteps 100
#define rateRXN1 1
#define rateRXN2 0.5
#define numEnsemble 200

// Concentrations of A,B and C for various ensembles
int A[numEnsemble];
int B[numEnsemble];
int C[numEnsemble];

// values of t and dt for various ensembles
float t[numEnsemble];
float dt[numEnsemble];

int main(){
	srand(time(0));
	FILE *fptr = fopen("/home/vikas/work/data.txt","w");
	
	// Initial Number of Molecules for A,B and C
	for(int j=0;j<numEnsemble;j++){
		A[j]=70;
		B[j]=70;
		C[j]=0;
		t[j]=0;
		fprintf(fptr,"%f\t%d\t%d\t%d\t",t[j],A[j],B[j],C[j]);
	}
	fprintf(fptr,"\n");
	
	float r1,r2; // random numbers for selection of the reaction and time
	float temp;
	for(int i=0;i<numSteps;i++){
		for(int j=0;j<numEnsemble;j++){
			r1=rand()*pow(RAND_MAX,-1);
			r2=rand()*pow(RAND_MAX,-1);
			temp=rateRXN1*A[j]*B[j]*pow((rateRXN1*A[j]*B[j]+rateRXN2*C[j]),-1);
			
			// Deciding Reaction
			if(r1>0 && r1<temp){ // reaction A+B->C
				if(A[j]>=0 && B[j]>0){ // does not happen when no reactants
					A[j] -= 1;
					B[j] -= 1;
					C[j] += 1;
				}
			}else{ // reaction C->0
				if(C[j]>=0){ // does not happen when no reactants
					C[j] -= 1;
				}
			}
			
			// Deciding Time
			dt[j]=-(log(1-r2))/(rateRXN1*A[j]*B[j]+rateRXN2*C[j]);
			//dt[j]=pow((rateRXN1*A[j]*B[j]+rateRXN2*C[j]),-1);
			//Vikas Monojit Definition for dt (no seperate random variable for dt)
			t[j] += dt[j];
			fprintf(fptr,"%f\t%d\t%d\t%d\t",t[j],A[j],B[j],C[j]);
		}
		fprintf(fptr,"\n");
	}
	fclose(fptr);
	return 0;
}
