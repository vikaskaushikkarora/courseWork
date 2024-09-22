#include"reqd.c"

int main(){
	srand(time(0));
	FILE* fptr;
	fptr=fopen("/home/vikas/work/data.txt","w");
	
	int N=100;
	float* x = malloc(N*sizeof(float));
	float* t = malloc(N*sizeof(float));
	float* y = malloc(N*sizeof(float));
	
	float timeAverage=0;
	for(int i=0;i<N;i++){
		t[i]=i*0.01;
		x[i]=2*M_PI*rand()*pow(RAND_MAX,-1);
		y[i]=f(x[i],t[i]);
		fprintf(fptr,"%f\t%f\t%f\n",t[i],x[i],y[i]);
		timeAverage=timeAverage+y[i];
	}
	
	timeAverage=timeAverage/N;
	printf("The time average of y is : %f\n",timeAverage);
	fclose(fptr);
	return 0;
}
