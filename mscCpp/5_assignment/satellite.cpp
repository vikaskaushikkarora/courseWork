#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

class satellite{
	public:
	const float GM=3.988e14,R=6371000; //In SI Units
	float t=0,h=0.01,tf,x=0,y=R,vx,vy;
	void getdata();
	void calculation();
};

void satellite::getdata(){
	float v0,theta0;
	cout<<"Enter initial velocity (in km/s) and angle of projection (in degrees) : "<<endl;
	cin>>v0>>theta0;
	v0=v0*1000;
	float pi=4.0*atan(1);
	vx=v0*sin(pi*theta0/180);
	vy=v0*cos(pi*theta0/180);
	cout<<"Enter the final time : "<<endl;
	cin>>tf;
}

void satellite::calculation(){
	ofstream myfile ;
	myfile.open("data.txt") ;
	int n=tf/h;
	float r,rnew,maxHeight,orbitalVelocity;
	float ax,ay;
	for(int i=1;i<=n;i++){
		myfile<<t<<" "<<x<<" "<<y<<endl;
		r=sqrt(x*x+y*y);
		ax=-GM*x/(r*r*r);
		ay=-GM*y/(r*r*r);
		vx=vx+(ax*h);
		vy=vy+(ay*h);
		x=x+(vx*h);
		y=y+(vy*h);
		t=t+h;
		rnew=sqrt(x*x+y*y);
		if(rnew<r){
			cout<<"Maximum height = "<<(rnew-R)/1000<<"km"<<endl;
			maxHeight=r-R;
			orbitalVelocity=sqrt(GM/rnew);
			cout<<"The orbital velocity is = "<<orbitalVelocity/1000<<" km/s"<<endl;
			break;
		}
	}
	myfile<<rnew<<" "<<rnew<<" "<<rnew<<endl;
	myfile.close();
}


int main(){
	satellite vikas;
	vikas.getdata();
	vikas.calculation();
	return 0;
}
