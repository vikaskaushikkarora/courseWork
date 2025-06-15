#include"convolution.c"

int main(){
	FILE* fptr;
	fptr=fopen("/home/vikas/work/data.txt","w");
	float t=-5,h=0.01;
	int n=1000;
	float y1,y2,conv;
	for(int i=0;i<n;i++){
		y1=fx1(t);
		y2=fx2(t);
		conv=convolution(fx1,fx2,-5,5,1000,t);
		fprintf(fptr,"%f\t%f\t%f\t%f\n",t,y1,y2,conv);
		t=t+h;
	}
	fclose(fptr);
	return 0;
}
