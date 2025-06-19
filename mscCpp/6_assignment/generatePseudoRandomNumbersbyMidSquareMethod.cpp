// Mid Square Method To Generate Pseudo Random Numbers
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std ;

int main(){
	int n=50,seed0,seedr,i;
	float seed=7657 ; // Enter a four digit number or seed 
	cout<<seed<<endl;
	for (i =0;i<=n;i++){
		// Algorithm to wipe last two and first two digits
		seed0=int(seed*seed/100);
		seedr=seed0 - ( seed0 % 10 );
		seedr=seedr - ( seedr % 100 );
		seedr=seedr - ( seedr % 1000 );
		seedr=seedr - ( seedr % 10000 );
		seed=seed0-seedr;
		cout<<seed<<'\t';
	}
	return 0;
}
