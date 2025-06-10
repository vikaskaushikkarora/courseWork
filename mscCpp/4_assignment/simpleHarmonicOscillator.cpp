#include<iostream>
#include<fstream>
#include<cmath>
using namespace std ;

class SHO {
	public:
	float k,m,r,t,h=0.01,tf,x,v,t0=0,x0,v0
	;
	float f(float x,float v , float k, float m, float r ) {
		return (-(k/m)*x-(r/m)*v) ;
	}
	void getdata();
	void calculation();
};

void SHO :: getdata(){
		cout<<"Enter the mass of the object : "<<endl;
		cin>>m;
		cout<<"Enter the spring constant : "<<endl;
		cin>>k;
		cout<<"enter the resistive constant : "<<endl ;
		cin>>r;
		cout<<"Enter the final time : "<<endl;
		cin>>tf;
		cout<<"Enter the initial distance from the equillibrium point i.e. x0 : "<<endl;
		cin>>x0;
		cout<<"Enter the initial speed of the object : "<<endl ;
		cin>>v0;
		
		float a = r*r/(2*m) - (k/m) ;
		if (a>0){
			cout<<"The oscillator is heavily damped ."<<endl;
		}
		else if (a==0) {
			cout<<"The oscillator is critically damped ."<<endl;
		}
		else {
			cout << "The oscillator is lightly damped ."<<endl;
		}
}
	
void SHO :: calculation(){
	ofstream myfile ;
	myfile.open("data.txt") ;
	t=t0;
	x=x0;
	v=v0;
	float n=tf/h;
	for (int j=0;j<=n;j++){
		myfile << t << "\t" << x << "\t" << v << endl ;
		t=t+h;
		v=v+f(x,v,k,m,r)*h;
		x=x+h*v;
	}
	myfile.close();
}


int main (){
		SHO vikas ;
		vikas.getdata();
		vikas.calculation();
		return 0;
}
