#include<iostream>
#include<fstream>
#include<cmath>
using namespace std ;


class airDrag {
	public:
	// Constants which will remain unchanged during the whole programme
	const float g=10,sigma=1260,c=0.5; // In SI Units
	// rho = density of solid , c = drag coefficient , g = acceleration due to gravity 
	// sigma = density of the fluid , R = radius of the spherical ball
	float t,h=0.01,tf,y,v,y1,y2,y3,y4,v1,v2,v3,v4,t0=0,y0=0,v0,R,a,rho;
	// h = step-size , y = depth of ball from the surface , v = speed of the ball , tf = final time
	
	float f(float t , float y , float v , float R , float rho){
		return (g-(3*sigma*c*v*v/(8*R*rho))); // equation of motion of the ball
	}
	
	void getdata();
	void calculation();
};


void airDrag :: getdata(){
	//Initial Conditions and other data to be inputed by the user
	cout<<"Enter the radius of the ball ( in cm ) : " << endl ;
	cin>> a;
	R=a/100 ;
	cout<<"Enter the density of the ball ( in kg/m^3 ) , recommended is 7860 (steel) : " << endl ;
	cin>>rho;
	cout<<"Enter the initial speed of the ball ( in m/s ) : " << endl ;
	cin>>v0;
	cout<<"Enter the final time ( in seconds ) : " << endl ;
	cin>>tf;
	float b = sqrt((8*g*R*rho)/(3*sigma*c));
	cout << "Terminal Velocity is : " << b << " m/s" << endl ;
}

void airDrag :: calculation(){
	ofstream myfile ;
	myfile.open("data1.txt");
	t=t0;
	y=y0;
	v=v0;
	float n=tf/h;
	for (int j=0;j<=n;j++){
		myfile << t << "\t" << y << "\t" << v << endl ;
		// Runge Kutta Method to solve ODEs
		v1=h*f(t,y,v,R,rho);
		y1=h*v;
		v2=h*f(t+(h/2),y+(y1/2),v+(v1/2),R,rho) ;
		y2=h*(v+v1/2) ;
		v3=h*f(t+(h/2),y+(y2/2),v+(v2/2),R,rho);
		y3=h*(v+v2/2) ;
		v4=h*f(t+h,y+y3,v+v3,R,rho);
		y4=h*(v+v3);
		y=y+(y1+(2*y2)+(2*y3)+y4)/6;
		v=v+(v1+(2*v2)+(2*v3)+v4)/6;
		t=t+h;
	}
	myfile.close();
}


int main(){
	airDrag vikas ;
	vikas.getdata();
	vikas.calculation();
	return 0 ;
}
