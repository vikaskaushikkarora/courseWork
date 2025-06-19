// Random Walk with Reflective Boundary Conditions : Calculations

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define numParticles 100000 // Number of Random Walkers
#define numSteps 1000 // Number of time steps
#define xStop 25 // the point of reflection

int main(){
	srand(time(0));
	FILE* fptr = fopen("/home/vikas/work/data.txt","w"); // open a file to store data
	
	int *pos = malloc(numParticles*sizeof(int));
	// position of each paru=icle at a given time
		for(int j=0;j<numParticles;j++){
		pos[j]=0; // all particles start from origin
		fprintf(fptr,"%d\t",pos[j]); // store the positions at t=0
	}
	fprintf(fptr,"\n");
	
	for(int i=0;i<numSteps;i++){
		for(int j=0;j<numParticles;j++){
			if(pos[j] == xStop){ // if particle encounters the ppoint of reflection 
				pos[j] -= 1; // subtract one from the position i.e. reflection
			} else{
				pos[j] += -1+2*(rand()%2); // otherwise continue the random walk
			}
			fprintf(fptr,"%d\t",pos[j]); // store the positions at that time
		}
		fprintf(fptr,"\n");
	}
	
	free(pos); // free the pointer/array for position
	fclose(fptr); // free the file pointer
	return 0;
}
