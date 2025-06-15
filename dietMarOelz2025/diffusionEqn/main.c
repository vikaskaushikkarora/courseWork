// Include required libraries ====================================================================
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


// Define parameters =============================================================================
#define XI (double) -20 // Initial x
#define XF (double) 20 // Final x
#define DX (float) 2e-1 // space step-size
#define DT (float) 1e-1// time step-size
#define NX (long) ((XF-XI)/DX) // no. of space-steps
#define NT (long) 1e4 // no. of time-steps
#define D (double) DX*DX/(2*DT) // Diffusion Coefficient

// Main function =================================================================================
int main(){

	// Memory allocation for arrays =========================================
	double* x = malloc(NX*sizeof(double));
	double* t = malloc(NT*sizeof(double));	
	double* u = malloc(NT*NX*sizeof(double*));
	
	// Initiallise arrays ===================================================
	for(long j=0;j<NX;j++){
		x[j]=XI+j*DX;
	}
	for(long i=0;i<NT;i++){
		t[i]=i*DT;
	}
	
	// Initital Condition ===================================================
	for(long j=0;j<NX;j++){
		if(x[j] == 10){
			u[0,j]=1000;
		}
		if(x[j] == -10){
			u[0,j]=500;
		}
	}
	
	// Boundary Condition (Periodic) =======================================
	for(long i=0;i<NT;i++){
		u[i*NX]=0.5*(u[i*NX+1]+u[(i+1)*NX-2]);
		u[(i+1)*NX-1]=u[i*NX];
	}

	// Time Evolution for Fisher KPP Equation ===============================
	for(long i=0;i<NT-1;i++){
		for(long j=1;j<NX-1;j++){
			u[(i+1)*NX+j] = u[i*NX+j]+ D*DT*((u[NX*i+j+1]+u[NX*i+j-1]-2*u[NX*i+j])/DX*DX);
		}
	}
	
	// Wrting into data file ================================================
	FILE* fpP = fopen("a.dat","w"); // Parameters
	fprintf(fpP,"%lf %lf %ld\n",XI,XF,NX);
	fprintf(fpP,"%lf %lf %ld\n",0.0,NT*DT,NT);
	fclose(fpP);
	
	FILE* fp = fopen("u.dat","w"); // Raw Data
	for(long i=0;i<NT;i++){
		for(long j=0;j<NX;j++){
			fprintf(fp,"%lf ",u[NX*i+j]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
	
	// Freeing Memory =======================================================
	free(x);
	free(t);
	free(u);
	return 0;
}
