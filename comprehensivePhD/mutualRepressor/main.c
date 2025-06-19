// Gillepsie Algorithm for the mutualrepressor system for cooperativity 2

// Include Libraries
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

// Define constants
#define decayConstant 0.1 // decay constant of the protein
#define alpha 100
#define num 1 // number of ensembles
#define timeSteps 500 // number of time steps

// Main Function
int main(){
	srand(time(0));
	FILE* fptr = fopen("data.txt","w");
	FILE* fptr1 = fopen("data1.txt","w");
	
	int* x = malloc(num*sizeof(int)); // Number of x molecules for various ensembles
	int* y = malloc(num*sizeof(int)); // Number of y molecules for various ensembles
	float* dt = malloc(num*sizeof(float)); // dt array for avarious ensembles
	float r1,r2,temp1,temp2,temp3; // random numbers and temp variable
	float p1,p2,d1,d2; // propensities for each reaction
	
	// Initial Conditions
	// ===============================================================================
	for(int j=0;j<num;j++){
		x[j]=50; // Initial Number of x Molecules
		y[j]=50; // Initial Number of y Molecules
	}
	
	for(int i=1;i<timeSteps;i++){
		for(int j=0;j<num;j++){
			r1=rand()*pow(RAND_MAX,-1); // first random number
			r2=rand()*pow(RAND_MAX,-1); // second random number
			p1 = alpha/(10*2+(y[j]*(y[j]-1)))+0.01;
			p2 = alpha/(5*2+(x[j]*(x[j]-1)))+0.01;
			d1 = decayConstant*x[j];
			d2 = decayConstant*y[j];
			dt[j] = -(log(1-r2))/(p1+p2+d1+d2);
			temp1 = p1/(p1+p2+d1+d2);
			temp2 = (p1+p2)/(p1+p2+d1+d2);
			temp3 = (p1+p2+d1)/(p1+p2+d1+d2);
			if(r1>0 && r1<=temp1){
				x[j] += 1;
			}else if(r1>temp1 && r1<temp2){
				y[j] += 1;
			}else if(r1>temp2 && r1<temp3){
				if(x[j]>0){
					x[j] -= 1;
				}
			}else{
				if(y[j]>0){
					y[j] -= 1;
				}
			}
			fprintf(fptr,"%d %d\n",x[j],y[j]);
		}
	}

	for(int i=1;i<timeSteps;i++){
		for(int j=0;j<num;j++){
			r1=rand()*pow(RAND_MAX,-1); // first random number
			r2=rand()*pow(RAND_MAX,-1); // second random number
			p1 = alpha/(10*2+(y[j]*(y[j]-1)))+0.01;
			p2 = alpha/(5*2+(x[j]*(x[j]-1)))+0.01;
			d1 = decayConstant*x[j];
			d2 = decayConstant*y[j];
			dt[j] = -(log(1-r2))/(p1+p2+d1+d2);
			temp1 = p1/(p1+p2+d1+d2);
			temp2 = (p1+p2)/(p1+p2+d1+d2);
			temp3 = (p1+p2+d1)/(p1+p2+d1+d2);
			if(r1>0 && r1<=temp1){
				x[j] += 1;
			}else if(r1>temp1 && r1<temp2){
				y[j] += 1;
			}else if(r1>temp2 && r1<temp3){
				if(x[j]>0){
					x[j] -= 1;
				}
			}else{
				if(y[j]>0){
					y[j] -= 1;
				}
			}
			fprintf(fptr1,"%d %d\n",x[j],y[j]);
		}
	}

	free(x);
	free(y);
	free(dt);
	fclose(fptr);
	fclose(fptr1);
	return 0;
}
