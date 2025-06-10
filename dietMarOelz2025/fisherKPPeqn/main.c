// Include required libraries ====================================================================
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


// Define parameters =============================================================================
#define XI (double) -2 // Initial x
#define XF (double) 2 // Final x
#define DX (float) 1e-3 // space step-size
#define DT (float) 0.5e1 // time step-size
#define NX (long) ((XF-XI)/DX) // no. of space-steps
#define NT (long) 1e4 // no. of time-steps
#define D (double) 0.02 // cm*cm/day Diffusion Coefficient
#define K (double) 1 // Carrying Capacity
#define ALPHA (double) 0.1 // per day


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
		if((x[j]>-0.5) && (x[j]<0.5)){
			u[0,j]=0.25;
		}
	}
	
	// Boundary Condition (Absorbing) =======================================
	for(long i=0;i<NT;i++){
		u[i*NX]=0;
		u[(i+1)*NX-1]=0;
	}

	// Time Evolution for Fisher KPP Equation ===============================
	for(long i=0;i<NT-1;i++){
		for(long j=1;j<NX-1;j++){
			u[(i+1)*NX+j] = u[i*NX+j] + D*DT*(ALPHA*u[NX*i+j]*(1-u[NX*i+j]/K)+(u[NX*i+j+1]+u[NX*i+j-1]-2*u[NX*i+j])/DX*DX);
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
