#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double a, b, n, k, limite;
	double sumatorio=0;
	double cuentatotal, cuenta1;
	
	/*Siendo f(x)=x^2*/
	
	cout<<"Introduzca a: ";
	cin>>a;
	cout<<"Introduzca b: ";
	cin>>b;
	cout<<"Introduzca el numero de k: ";
	cin>>n;
	limite=n-1;
	
	for(k=1;k<=limite;k++){
		cuenta1=a+k*((b-a)/n);
		sumatorio=sumatorio+cuenta1;
	}
	cuentatotal=((b-a)/n)*((((a*a)+(b*b))/2)+sumatorio);
	cout<<"El resultado es: "<<cuentatotal<<endl;
	system("pause");
}
