#include<iostream>
#include<fstream>
#include<cmath>
using namespace std ;


class EMField {
	public:
	float t,h=0.01,tf,t0=0,x,y,vx,vy,ax,ay,x0,y0,vx0,vy0,Ex,Ey,Bz,m,q;
	void getdata();
	void calculation();
	float fx(float q,float m,float Ex,float Ey,float Bz,float vx,float vy) {
		return (q*Ex/m + q*vy*Bz/m);
	}
	float fy(float q,float m,float Ex,float Ey,float Bz,float vx,float vy) {
		return (q*Ey/m - q*vx*Bz/m);
	} 
};

void EMField :: getdata(){
	cout<<"Define the properties of charged paticle : "<<endl;
	cout<<"Charge and mass of the particle : "<<endl;
	cin>>q>>m;
	cout<<"Initial position of the charged particle , x0 and y0 : "<<endl;
	cin>>x0>>y0;
	cout<<"Initial velocity of the charged particle , vx0 and vy0 : "<<endl;
	cin>>vx0>>vy0;
	cout<<"Enter the electric field , Ex and Ey : "<<endl;
	cin>>Ex>>Ey;
	cout<<"Enter the magnetic field ( in z direction only ) : "<<endl;
	cin>>Bz;
	cout<<"Enter the final time : "<<endl;
	cin>>tf;
}

void EMField :: calculation(){
	ofstream myfile ;
	myfile.open("data.txt");
	t=t0;
	x=x0;
	y=y0;
	vx=vx0;
	vy=vy0;
	float n=tf/h;
	for (int j=0;j<=n;j++){
		myfile<<t<<" "<<x<<" "<<y<<" "<<vx<<" "<<vy<<" "<<Ex<<" "<<Ey<<" "<<Bz<<endl ;
		t=t+h;
		ax=h*fx(q,m,Ex,Ey,Bz,vx,vy);
		ay=h*fy(q,m,Ex,Ey,Bz,vx,vy);
		vx=vx+h*ax;
		vy=vy+h*ay;
		x=x+h*vx;
		y=y+h*vy;
	}
	myfile.close();
}

int main(){
	EMField vikas;
	vikas.getdata();
	vikas.calculation();
	return 0;
}

