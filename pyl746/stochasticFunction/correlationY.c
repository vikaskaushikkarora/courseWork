#include"reqd.c"

int main(){
	srand(time(0));
	
	int N=10000;
	float sum=0,t1=5,t2=2;
	float* x = malloc(N*sizeof(float));
	float* y1 = malloc(N*sizeof(float));
	float* y2 = malloc(N*sizeof(float));
	
	for(int i=0;i<N;i++){
		x[i]=2*M_PI*rand()*pow(RAND_MAX,-1);
		y1[i]=f(x[i],t1);
		y2[i]=f(x[i],t2);
		sum=sum+y1[i]*y2[i];
	}
	
	printf("The correlation of y at time t= %f and %f is : %f\n",t1,t2,sum);
	return 0;
}
