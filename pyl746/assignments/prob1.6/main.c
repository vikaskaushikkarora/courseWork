#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
	srand(time(0));
	FILE* fptr;
	fptr=fopen("/home/vikas/work/data.txt","w");
	int N=1000000,d=50; //N = number of experiments, d = number of dice
	for(int i=0;i<d+1;i++){
		fprintf(fptr,"%d\t",N);
	}
	fprintf(fptr,"\n");
	
	int *a = malloc(N*d*sizeof(int));
	int *sum = malloc(N*sizeof(int));

	for(int i=0;i<N;i++){
		int temp=0;
		for(int j=0;j<d;j++){
			a[d*i+j]=1+rand()%8;
			temp=temp+a[d*i+j];
			fprintf(fptr,"%d\t",a[d*i+j]);
		}
		sum[i]=temp;
		fprintf(fptr,"%d\n",sum[i]);
	}
	fclose(fptr);
	
	return 0;
}
