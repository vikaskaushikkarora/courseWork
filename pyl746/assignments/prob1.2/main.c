#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
	srand(time(0));
	FILE* fptr; 
	fptr=fopen("/home/vikas/work/data.txt","w"); //create data file for storing information

	int n=10000;
	float *x1 = malloc(n*sizeof(int));
	float *x2 = malloc(n*sizeof(int));
	float *y = malloc(n*sizeof(int));

	for(int i=0;i<n;i++){
		x1[i]=-1+2*(rand()*pow(RAND_MAX,-1)); //random number between -1 and 1
		x2[i]=1+(rand()*pow(RAND_MAX,-1)); //random number between 1 and 2
		y[i]=x1[i]+x2[i]; //random variable as a sum of the two
		fprintf(fptr,"%f\t%f\t%f\n",x1[i],x2[i],y[i]); //write into data file
	}
	
	fclose(fptr);
	return 0;
}
