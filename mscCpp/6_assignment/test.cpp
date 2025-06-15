#include<iostream>
#include<time.h>
using namespace std ;

int main(){
	int p=10;	
	for (int i=0;i<=20;i++){
		srand(time(0));
		float random = (float)rand()/RAND_MAX;
		cout<<random<<endl;
		if (random<0.2){
			p=p-1;
		}
	}
	cout<<"Final value of p is = "<<p<<endl;
	return 0 ;
}

