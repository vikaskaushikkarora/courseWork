// Include required libraries ====================================================================
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


// Define parameters =============================================================================
#define XI (double) 0 // Initial x
#define XF (double) 10 // Final x
#define DX (float) 1e-2 // space step-size
#define DT (float) 1e-4// time step-size
#define NX (long) ((XF-XI)/DX) // no. of space-steps
#define NT (long) 1.5e5 // no. of time-steps
#define D (double) 0.1 // Diffusion Coefficient
#define Xi (double) 0.5 // Chemotactic Sensitivity


// Main function =================================================================================
int main(){

	// Memory allocation for arrays =============================================
	double* x = malloc(NX*sizeof(double));
	double* t = malloc(NT*sizeof(double));
	double* S = malloc(NX*sizeof(double));
	double* u = malloc(NT*NX*sizeof(double*));
	
	// Initiallise arrays =======================================================
	for(long j=0;j<NX;j++){
		x[j]=XI+j*DX;
		S[j]=2*(cos(2*M_PI*(x[j]-XI-3)/(XF-XI))+1);
	}
	for(long i=0;i<NT;i++){
		t[i]=i*DT;
	}
	
	// Initital Condition =======================================================
	for(long j=0;j<NX;j++){
		if(x[j]>(XI+3*(XF-XI)/4) && x[j]<XF){
			u[j]=400/(XF-XI);
		}else{
			u[j]=0;
		}
	}
	
	// Time Evolution for Drift-Diffuaion Equation ===============================
	for(long i=0;i<NT-1;i++){
		for(long j=1;j<NX-1;j++){
			u[(i+1)*NX+j]   =   u[i*NX+j]   +   (DT/(DX*DX))*(  D*(u[NX*i+j+1]+u[NX*i+j-1]-2*u[NX*i+j])  -  Xi*( (u[NX*i+j+1]-u[NX*i+j])*(S[j+1]-S[j]) + u[NX*i+j]*(S[j+1]+S[j-1]-2*S[j]) )  );
			// Periodic Boundary Conditions
			u[(i+1)*NX]=0.5*(u[(i+1)*NX+1]+u[(i+2)*NX-2]);
			u[(i+2)*NX-1]=u[(i+1)*NX];
		}
	}
	
	// Wrting into data file =====================================================
	FILE* fpP = fopen("a.dat","w"); // Parameters
	fprintf(fpP,"%lf %lf %ld\n",XI,XF,NX);
	fprintf(fpP,"%lf %lf %ld\n",0.0,NT*DT,NT);
	fclose(fpP);
	
	FILE* fpS = fopen("S.dat","w"); // S array
	for(long j=0;j<NX;j++){
		fprintf(fpS,"%lf ",S[j]);
	}
	fclose(fpS);
	
	FILE* fp = fopen("u.dat","w"); // u array
	for(long i=0;i<NT;i++){
		for(long j=0;j<NX;j++){
			fprintf(fp,"%lf ",u[NX*i+j]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
	
	// Freeing Memory ============================================================
	free(x);
	free(t);
	free(u);
	return 0;
}
