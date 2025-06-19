#include<iostream>
#include<fstream>
#include<cmath>
using namespace std ;

class CPD {
	public:
	float k,k12,m,t,h=0.001,tf,x1,x2,v1,v2,t0=0,x10,x20,v10,v20;
	
	float f1(float x1,float x2,float k,float k12 ,float m) {
		return (-(k/m)*x1+(k12/m)*(x2-x1)) ;
	}
	float f2(float x1,float x2,float k,float k12 ,float m) {
		return (-(k/m)*x2-(k12/m)*(x2-x1)) ;
	}
	void getdata();
	void calculation();
};

void CPD :: getdata(){
		cout<<"Enter the mass of both objects (they both are taken to be same) : "<<endl;
		cin>>m;
		cout<<"Enter the spring constant for the side springs : "<<endl;
		cin>>k;
		cout<<"Enter the spring constant for the middle spring : "<<endl;
		cin>>k12;
		cout<<"Enter the final time : "<<endl;
		cin>>tf;
		cout<<"Enter the initial conditions : "<<endl;
		cout<<"Enter the initial perturbation of the first object from its equillibrium position i.e. x10 : "<<endl;
		cin>>x10;
		cout<<"Enter the initial perturbation of the second object from its equillibrium position i.e. x20 : "<<endl;
		cin>>x20;
		cout<<"Enter the initial speed of the first object : "<<endl ;
		cin>>v10;
		cout<<"Enter the initial speed of the second object : "<<endl ;
		cin>>v20;
}
	
void CPD :: calculation(){
	ofstream myfile ;
	myfile.open("data1.txt") ;
	t=t0;
	x1=x10;
	v1=v10;
	x2=x20;
	v2=v20;
	float n=tf/h;
	for (int j=0;j<=n;j++){
		myfile << t << "\t" << x1 << "\t" << x2 << "\t" << v1 << "\t" << v2 << "\t" << k <<"\t"<< k12 << "\t" << m <<endl ;
		t=t+h;
		v2=v2+h*f2(x1,x2,k,k12,m);
		v1=v1+h*f1(x1,x2,k,k12,m);
		x2=x2+h*v2;
		x1=x1+h*v1;
	}
	myfile.close();
}


int main (){
		CPD vikas ;
		vikas.getdata();
		vikas.calculation();
		return 0;
}
