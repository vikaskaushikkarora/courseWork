#include <iostream>
#include<cmath>
#include<fstream>
using namespace std;
class LCR {
	 public:
	 float t,h=0.01,tf,q,q0,I,I0,R,L,C,q1,q2,q3,q4,i1,i2,i3,i4,a,b;
	 int j,n;

	 void getdata() ;

	 float p(float t, float I, float q, float L,float C,float R){
		 return (-(R/L)*I-q/(L*C));
	 }

	 float s(float t, float I, float q){
		 return (I);
	 }

	 void calculation() ;
};

void LCR :: getdata(){
	cout<<"enter the value of resistance: ";
	cin>>R;
	cout<<"enter the value of capacitance: ";
	cin>>C;
   	cout<<"enter the value of inductance: ";
   	cin>>L;
   	cout<<"enter the value of initial charge: ";
   	cin>>q0;
   	cout<<"enter the value of initial current: ";
   	cin>>I0;
   	cout<<"enter the final time:";
   	cin>>tf;
   	a=R/2;
   	b=sqrt(L/C);
   	if (a==b){
		cout<<"the circuit is critically damped"<<endl;
	}
	else if (a>b){
		cout<<"the circuit is over damped"<<endl;
	}
	else { 
		cout<<"the circuit is under damped or lightly damped with frequency w = "<<sqrt((1/(L*C)-(R*R/4*L*L))) << endl ;
	}
}

void LCR :: calculation(){
	ofstream myfile;
	myfile.open("data.txt");
	float t0=0;
	t=t0;
	q=q0;
	I=I0;
	n=tf/h;
	// cout<<"No.of iteration:"<<n<<endl;
	//cout<<"solve above differential equation using runga kutta method"<<endl;
	for(j=0;j<=n;j++){
		myfile<<t<<"\t"<<q<<"\t"<<I<<endl;
		q1=h*s(t,I,q);
		i1=h*p(t,I,q,L,C,R);
		q2=h*s(t+(h/2),I+(i1/2),q+(q1/2)) ;
		i2=h*p(t+(h/2),I+(i1/2),q+(q1/2),L,C,R) ;
		q3=h*s(t+(h/2),I+(i2/2),q+(q2/2));
		i3=h*p(t+(h/2),I+(i2/2),q+(q2/2),L,C,R) ;
		q4=h*s(t+h,I+i3,q+q3);
		i4=h*p(t+h,I+i3,q+q3,L,C,R);
		q=q+(q1+(2*q2)+(2*q3)+q4)/6;
		I=I+(i1+(2*i2)+(2*i3)+i4)/6;
		t=t+h;
	}
	myfile.close();
}


int main(){
	LCR vikas ;
	vikas.getdata() ;
	vikas.calculation() ;
	return 0 ;
}
