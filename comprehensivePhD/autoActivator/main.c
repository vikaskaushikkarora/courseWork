// Gillepsie Algorithm for the autoactivator system for cooperativity 2

// Include Libraries
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

// Define constants
#define decayConstant 1 // decay constant of the protein
#define alpha 10
#define num 100000 // number of ensembles
#define timeSteps 500 // number of time steps

// Main Function
int main(){
	srand(time(0));
	FILE* fptr = fopen("data.txt","w");
	FILE* fptr1 = fopen("data1.txt","w");
	
	int* P = malloc(num*sizeof(int)); // Number of P molecules for various ensembles
	float* dt = malloc(num*sizeof(float)); // dt array for avarious ensembles
	float* t = malloc(num*sizeof(float)); // time array for various ensembles
	float* Pav = malloc(timeSteps*sizeof(float)); // ensemble average for P at all times
	float* dtAv = malloc(timeSteps*sizeof(float)); // dt average over all ensembles for all times
	float r1,r2,temp; // random numbers and temp variable
	float p1,p2; // propensities for each reaction
	float time=0; // absolute time for average of all ensembles
	
	// Initial Conditions
	// ===============================================================================
	for(int j=0;j<num;j++){
		P[j]=rand()%25; // Initial Number of P Molecules
		t[j]=0;
	}
	
	for(int i=0;i<timeSteps;i++){
		Pav[i]=0;
		dtAv[i]=0;
	}
	
	for(int i=1;i<timeSteps;i++){
		for(int j=0;j<num;j++){
			r1=rand()*pow(RAND_MAX,-1); // first random number
			r2=rand()*pow(RAND_MAX,-1); // second random number
			p1 = ((alpha*P[j]*(P[j]-1))/(2+(P[j]*(P[j]-1))))+0.01;
			p2 = decayConstant*P[j];
			dt[j] = -(log(1-r2))/(p1+p2);
			temp = p1/(p1+p2);
			if(r1>0 && r1<temp){
				if(P[j]>=0){
					P[j] += 1;
				}
			}else{
				if(P[j]>0){
					P[j] -= 1;
				}
			}
			t[j] += dt[j];
			Pav[i] += P[j];
			dtAv[i] += dt[j];
		}
		Pav[i] /= num; // P average for all ensembles
		dtAv[i] /= num; // average time for all ensembles
		time += dtAv[i]; // Absolute time for the average of all ensembles
		fprintf(fptr,"%f %f\n",Pav[i],time);
	}

	for(int i=0;i<num;i++){
		fprintf(fptr1,"%d\n",P[i]);
	}
	
	free(P);
	free(Pav);
	free(dt);
	free(dtAv);
	fclose(fptr);
	fclose(fptr1);
	return 0;
}
