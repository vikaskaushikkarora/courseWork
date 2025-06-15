// Required Structure
struct reqd{
	int index;
	int *A;
	int *B;
	int *C;
	float *t;
	float *dt;
};

//Routine Function
void *routine(void *x){
	float r1,r2; // random numbers for selection of the reaction and time
	float temp;
	char *string0="/home/vikas/work/dataFiles/data";
	
	for(int j=0;j<numEnsemble;j++){
		// Open data file for current thread and write data for all the ensembles for the thread
		char string[50];
		sprintf(string,"%s%d.txt",string0,(((struct reqd *)x)->index));
		FILE *fptr=fopen(string,"a");
		fprintf(fptr,"%f\t%d\t%d\t%d\t",(((struct reqd*)x)->t[j]),(((struct reqd*)x)->A[j]),(((struct reqd*)x)->B[j]),(((struct reqd*)x)->C[j])); // print initial conditions for the ensemble
		
		for(int i=0;i<numSteps;i++){
			r1=rand()*pow(RAND_MAX,-1);
			r2=rand()*pow(RAND_MAX,-1);
			temp=rateRXN1*(((struct reqd*)x)->A[j])*(((struct reqd*)x)->B[j])*pow((rateRXN1*(((struct reqd*)x)->A[j])*(((struct reqd*)x)->B[j]))+rateRXN2*(((struct reqd*)x)->C[j]),-1);
			
			// Deciding Reaction
			if(r1>0 && r1<temp){ // reaction A+B->C
				if((((struct reqd*)x)->A[j])>0 && (((struct reqd*)x)->B[j])>0){ // does not happen when no reactants are there
					(((struct reqd*)x)->A[j]) -= 1;
					(((struct reqd*)x)->B[j]) -= 1;
					(((struct reqd*)x)->C[j]) += 1;
				}
			}else{ // reaction C->0
				if((((struct reqd*)x)->C[j])>=0){ // does not happen when no reactants are there
					(((struct reqd*)x)->C[j]) -= 1;
				}
			}
			
			// Deciding Time
			(((struct reqd*)x)->dt[j]) = -(log(1-r2))/(rateRXN1*(((struct reqd*)x)->A[j])*(((struct reqd*)x)->B[j])+rateRXN2*(((struct reqd*)x)->C[j]));
			(((struct reqd*)x)->t[j]) += (((struct reqd*)x)->dt[j]);
			
			// Print data after the reaction has occured
			fprintf(fptr,"%f\t%d\t%d\t%d\t",(((struct reqd*)x)->t[j]),(((struct reqd*)x)->A[j]),(((struct reqd*)x)->B[j]),(((struct reqd*)x)->C[j]));
		}
		
		fprintf(fptr,"\n");
		fclose(fptr);
	}
	
	return NULL;
}

