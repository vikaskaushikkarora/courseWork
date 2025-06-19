// Include required libraries ====================================================================
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


// Define parameters =============================================================================
#define XI (double) 0 // Initial x
#define XF (double) 10 // Final x
#define DX (float) 5e-2 // space step-size
#define DT (float) 1e-4// time step-size
#define NX (long) ((XF-XI)/DX) // no. of space-steps
#define NT (long) 5e4 // no. of time-steps
#define D (double) 0.5 // Diffusion Coefficient
#define Xi (double) 1 // Chemotactic Sensitivity
#define Ds (double) 1 // Diffusion Coefficient for S
#define ALPHA (double) 0.3
#define BETA (double) 1


// Main function =================================================================================
int main(){

	// Memory allocation for arrays =========================================
	double* x = malloc(NX*sizeof(double));
	double* t = malloc(NT*sizeof(double));
	double* u = malloc(NT*NX*sizeof(double));
	double* S = malloc(NT*NX*sizeof(double));
	
	// Initiallise arrays ===================================================
	for(long j=0;j<NX;j++){
		x[j]=XI+j*DX;
	}
	for(long i=0;i<NT;i++){
		t[i]=i*DT;
	}
	
	// Initital Condition ===================================================
	for(long j=0;j<NX;j++){
		S[j]=10;
		if(x[j]>(XI+(XF-XI)/4) && x[j]<(XI+3*(XF-XI)/4)){
			u[j]=200/(XF-XI);
		}else{
			u[j]=0;
		}
	}
	
	// Time Evolution for Drift-Diffusion Equation ===============================
	for(long i=0;i<NT-1;i++){
		for(long j=1;j<NX-1;j++){
			S[(i+1)*NX+j]  =  S[i*NX+j]  +  DT*( Ds*(S[NX*i+j+1]+S[NX*i+j-1]-2*S[NX*i+j])/(DX*DX) + ALPHA*u[NX*i+j] - BETA*S[NX*i+j]);
			u[(i+1)*NX+j]   =   u[i*NX+j]   +   (DT/(DX*DX))*(  D*(u[NX*i+j+1]+u[NX*i+j-1]-2*u[NX*i+j])  -  Xi*( (u[NX*i+j+1]-u[NX*i+j])*(S[NX*i+j+1]-S[NX*i+j]) + u[NX*i+j]*(S[NX*i+j+1]+S[NX*i+j-1]-2*S[NX*i+j]) )  );
			//Periodic Boundary Conditions
			u[(i+1)*NX]=0.5*(u[(i+1)*NX+1]+u[(i+2)*NX-2]);
			u[(i+2)*NX-1]=u[(i+1)*NX];
			S[(i+1)*NX]=0.5*(S[(i+1)*NX+1]+S[(i+2)*NX-2]);
			S[(i+2)*NX-1]=S[(i+1)*NX];
		}
	}
	
	// Writing into data file =====================================================
	FILE* fpP = fopen("a.dat","w"); // Parameters
	fprintf(fpP,"%lf %lf %ld\n",XI,XF,NX);
	fprintf(fpP,"%lf %lf %ld\n",0.0,NT*DT,NT);
	fclose(fpP);
	
	FILE* fp = fopen("u.dat","w"); // u array
	for(long i=0;i<NT;i++){
		for(long j=0;j<NX;j++){
			fprintf(fp,"%lf ",u[NX*i+j]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
	
	FILE* fpS = fopen("S.dat","w"); // S array
	for(long i=0;i<NT;i++){
		for(long j=0;j<NX;j++){
			fprintf(fpS,"%lf ",S[NX*i+j]);
		}
		fprintf(fpS,"\n");
	}
	fclose(fpS);
	
	// Freeing Memory ============================================================
	free(x);
	free(t);
	free(u);
	return 0;
}
