#include<stdio.h>
#include<stdlib.h>
#include<math.h>


float fx(float x, float y){
	return y;
}

float fy(float x, float y, float gamma){
	return -1*(gamma*y+cos(x));
}

int main(){
	//n=no. of time steps,m=no. of refinement for mu,l=no. of steps for x
	int n=7000,m=30,l=30;
	float t=0,x,y,gamma=0.1,h=0.001;
	
	FILE *fptr;
	FILE *fptr1;
	fptr = fopen("data.txt","w");
	fptr1 = fopen("dataextra.txt","w");
	fprintf(fptr1,"%d\t%d\t%d",n,m,l);
	fclose(fptr1);
	
	for(int j=0;j<m;j++){
		for(int k=0;k<l;k++){
			x=-10+20*j*(pow(m,-1));
			y=-2.5+5*k*(pow(l,-1));
			for(int i=0;i<n;i++){
				t=t+h;
				x=x+h*fx(x,y);
				y=y+h*fy(x,y,gamma);
				fprintf(fptr,"%f\t%f\n",x,y);
			}
		}
	}
	
	fclose(fptr);
	return 0;
}

