// Persistent Random Walk : Calculations

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define numParticles 100000 // Number of Random Walkers
#define numSteps 1000 // Number of time steps
#define prob 0.01 // the constant 'e' as mentioned in the probelem

int main(int argc,char* argv[]){
	srand(0);
	FILE* fptr = fopen("/home/vikas/work/data.txt","w"); // open file to store data
	
	int *pos = malloc(numParticles*sizeof(int)); // position of each random walker
	int *step = malloc(numParticles*sizeof(int));
	// the previous step taken by each walker, left =-1, right =+1
	
	// First step
	for(int j=0;j<numParticles;j++){
		step[j] = -1+2*(rand()%2); // 1st step is equally left/right probable
		pos[j] += step[j];
		fprintf(fptr,"%d\t",pos[j]); // store the psotions of each walker
	}
	fprintf(fptr,"\n");
	
	// Next Steps
	float temp;
	for(int i=1;i<numSteps;i++){
		for(int j=0;j<numParticles;j++){
			temp=rand()*pow(RAND_MAX,-1);
			if(temp>0 && temp<prob){ // the particle changes the direction of it's motion
				step[j] = (-1)*step[j];
			} // else particle takes another step in the same direction
			pos[j] += step[j];
			fprintf(fptr,"%d\t",pos[j]); // store the psotions of each walker
		}
		fprintf(fptr,"\n");
	}
	
	free(pos); // free the pointer for the position
	free(step); // free the pointer for the step
	fclose(fptr); // close the file pointer
	return 0;
}
