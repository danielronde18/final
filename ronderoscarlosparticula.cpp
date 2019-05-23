#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

double dt = 0.1;
double q= 2.0;
double m = 7294.29;

double valorA(double);
double eq1( double );
double eq4( double, double, double, double, double );

void resolver( double, double&, double&);
void condiciones_iniciales( double&, double&);

int main( ){
	double u1, v1;
	condiciones_iniciales( u1,  v1);

	ofstream info1;
	info1.open("datos.txt");
	for( double t = 0.0; t < 10; t = t + dt ){
		resolver( t, u1, v1 );
		info1 << t << "\t" << u1 << "\t" << v1 << endl;
	}
	info1.close();

	return 0;
}

void condiciones_iniciales(double& u1 double& v1){
	u1 = 1.0;
	v1 = 0.0;

}

double eq1( double v1 ){
	return v1;
}


double valorA(double t){
    if(t<3.0){
        a=0;
        return a;}
    else if(3<t<7){
        a=0;
        return a;}
    else{ 
        a=0;
        return a;}
}


double eq4( double t, double u1, double v1 ){
	return t+(1.0/2.0*0.0*t*t);
}





void resolver( double t, double &u1, double &v1){
    
	double iter00, iter03;
	iter00 = dt*eq1( v1 );
	iter03 = dt*eq4( t, u1, v1 );


	double iter10, iter13 ;
	iter10 = dt*eq1( v1+1/2.0*iter03 );
	iter13 = dt*eq4( t+1/2.0*dt, u1+1/2.0*iter00, v1+1/2.0*iter03);


	double iter20, iter23;
	iter20 = dt*eq1( v1+1/2.0*iter13 );
	iter23 = dt*eq4( t+1/2.0*dt, u1+1/2.0*iter10, v1+1/2.0*iter13);

	double iter30, iter33 ;
	iter30 = dt*eq1( v1+iter23 );
	iter33 = dt*eq4( t+dt, u1+iter20, v1+iter23);


	u1 += iter00/6.0 + 1/3.0*(iter10 + iter20) + iter30/6.0;
	v1 += iter03/6.0 + 1/3.0*(iter13 + iter23) + iter33/6.0;

}
