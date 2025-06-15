#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(){
	
	srand(time(0));
	int n=100000,m=1000,count;
	double x[n],y[n],r[n],e;
	x[0]=(rand())*pow(RAND_MAX,-1);
	y[0]=(rand())*pow(RAND_MAX,-1);
	r[0]=0;
	
	FILE *fptr;
	fptr=fopen("/home/vikas/Desktop/work/data.txt","w");
	
	for(int i=1;i<n;i++){
		x[i]=(rand())*pow(RAND_MAX,-1);
		y[i]=(rand())*pow(RAND_MAX,-1);
		r[i]=pow(((x[i]-x[0])*(x[i]-x[0])+(y[i]-y[0])*(y[i]-y[0])),0.5);
	}
	
	for(int i=0;i<m;i++){
		e=0.2*i/m;
		count=0;
		for(int j=0;j<n;j++){
			if(r[j]<e){
				count=count+1;
			}
		}
		fprintf(fptr,"%f\t%d\n",e,count);
	}
	
	fclose(fptr);
	return 0;
	
}

