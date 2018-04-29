#include <iostream>
#include <cmath>

using namespace std;

long double multiA(double a1, double r, double k){
	double cuenta, multiplicatorio=1;
	for(int i=1;i<=k;i++){
		cuenta=a1*pow(r,i);
		multiplicatorio=multiplicatorio*cuenta;				
	}
	return multiplicatorio;
}

long double multiB(double a1, double r, double k){
	double primera, solucion, ultima;
	primera=a1*r;
	ultima=a1*pow(r,k);
	solucion=sqrt(pow((primera*ultima),k));
	return solucion;
}

int main(){
	 double a1, r, k;
	 long double multi1, multi2;
	 
	 cout<<"Introduzca a1: ";
	 cin>>a1;
	 cout<<"Introduzca r: ";
	 cin>>r;
	 cout<<"Introduzca k: ";
	 cin>>k;
	 
	 multi1=multiA(a1, r, k);
	 multi2=multiB(a1, r, k);
	 	 
	 cout<<"La solucion de la primera forma es: "<<multi1<<endl;
	 cout<<"La solucion de la segunda forma es: "<<multi2<<endl;
}
