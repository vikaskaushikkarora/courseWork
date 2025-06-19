// Gillespie Algorithm for A->B+C & C->0

#include"required.c"
#include"structRoutine.c"

int main(){
	srand(time(0));
	system("rm -rf /home/vikas/work/dataFiles");
	system("mkdir /home/vikas/work/dataFiles");
	
	struct reqd r[NTHREADS];
	
	// Initial Number of Molecules for A,B and C
	for(int th=0;th<NTHREADS;th++){
		r[th].index=th;
		r[th].A=malloc(numEnsemble*sizeof(int));
		r[th].B=malloc(numEnsemble*sizeof(int));
		r[th].C=malloc(numEnsemble*sizeof(int));
		r[th].t=malloc(numEnsemble*sizeof(float));
		r[th].dt=malloc(numEnsemble*sizeof(float));
		for(int j=0;j<numEnsemble;j++){
			r[th].A[j]=70;
			r[th].B[j]=70;
			r[th].C[j]=0;
			r[th].t[j]=0;
		}
	}
	
	// Parallel Processing
	pthread_t threads[NTHREADS];
	for(int i=0;i<NTHREADS;i++){
		pthread_create(threads+i,NULL,routine,&r[i]);
	}
	for(int i=0;i<NTHREADS;i++){
		pthread_join(threads[i],NULL);
	}
	
	// Freeing allocated memory spaces
	for(int th=0;th<NTHREADS;th++){
		free(r[th].A);
		free(r[th].B);
		free(r[th].C);
		free(r[th].t);
		free(r[th].dt);
	}
	
	// Writing the number of threads and ensembles per thread
	FILE* fptr = fopen("/home/vikas/work/data.txt","w");
	fprintf(fptr,"%d\t%d\n",NTHREADS,numEnsemble);
	fclose(fptr);
	return 0;
}
