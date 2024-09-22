#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


int main(){
	srand(time(0));
	FILE* fptr;
	fptr=fopen("/home/vikas/work/data.txt","w");
	
	float L=1,pi=3.1415,temp;
	int N=1000,M=10000;
	float* X = malloc(N*sizeof(float));
	float* Y = malloc(N*sizeof(float));
	for(int j=0;j<M;j++){
		X[0]=0;
		Y[0]=0;
		for(int i=1;i<N;i++){
			temp=2*pi*rand()*pow(RAND_MAX,-1);
			X[i]=X[i-1]+cos(temp);
			Y[i]=Y[i-1]+sin(temp);
			
		}
		fprintf(fptr,"%f\t%f\n",X[N-1],Y[N-1]);
	}
	fclose(fptr);
	return 0;
}
