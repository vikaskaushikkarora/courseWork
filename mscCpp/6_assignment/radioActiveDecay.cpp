#include<iostream>
#include<fstream>
#include<time.h>
using namespace std ;

class radioactive {
	public:
	float t,h,tf,np,nd,ngd,Lp,Ld;
	int i,j,n,k;
	void getdata();
	void calculation();
};

void radioactive :: getdata(){
	cout<<"Enter the initial number of parent nuclie : "<<endl;
	cin>>np;
	cout<<"Enter the initial number of daughter nuclie : "<<endl;
	cin>>nd;
	cout<<"Enter the decay constant for parent nuclie : "<<endl;
	cin>>Lp;
	cout<<"Enter the decay constant for daughter nuclie : "<<endl;
	cin>>Ld;
	cout<<"Enter the final time : "<<endl;
	cin>>tf;
	t=0;
	h=1;
	ngd=0;
	n=int(tf/h);
}

void radioactive :: calculation(){
	float random ;
	ofstream myfile("data.txt") ;
	for (i=0;i<=n;i++){
		myfile<<t<<" "<<np<<" "<<nd<<" "<<ngd<<endl;
		srand(time(0));
		for (j=0;j<=np;j++) {
			random = (float)rand() / RAND_MAX ;
			if (random <= Lp) {
				np=np-1;
				nd=nd+1;
			}
		}
		for (k=0;k<=nd;k++) {
			random = (float)rand() / RAND_MAX ;
			if (random <= Ld) {
				nd=nd-1;
				ngd=ngd+1;
			}
		}
		t=t+h;
	}
	myfile.close();
}

int main () {
	radioactive vikas ;
	vikas.getdata();
	vikas.calculation();
	return 0;
}
