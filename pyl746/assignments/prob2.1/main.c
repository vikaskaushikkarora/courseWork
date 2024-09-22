// Random Walk with Absorbing Boundary Condition : Calculations

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define numParticles 100000 //number of random walkers
#define numSteps 1000 // number of steps taken
#define xStop 25 // the point where there is absorption of the particle

int main(){
	srand(time(0));
	FILE* fptr = fopen("/home/vikas/work/data.txt","w"); // open a file to store data
	
	int *pos = malloc(numParticles*sizeof(int));
	// positions of all random walkers at a given time
	for(int j=0;j<numParticles;j++){
		pos[j]=0; // initiallisong positions to zero
		fprintf(fptr,"%d\t",pos[j]); // write into data file
	}
	fprintf(fptr,"\n");
	
	for(int i=0;i<numSteps;i++){
		for(int j=0;j<numParticles;j++){
			if(pos[j] == xStop){ // if particle encounters
				pos[j]=10000;
				// Give a very high number such that it teleports very far away
			} else{
				pos[j] += -1+2*(rand()%2); // update position according to random walk
			}
			fprintf(fptr,"%d\t",pos[j]); // write into data file
		}
		fprintf(fptr,"\n");
	}

	free(pos); // free the pointer/array for position
	fclose(fptr); //close the file pointer
	return 0;
}
