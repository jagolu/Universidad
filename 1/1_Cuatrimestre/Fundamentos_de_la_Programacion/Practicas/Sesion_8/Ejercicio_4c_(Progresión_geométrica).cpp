#include <iostream>
#include <cmath>

using namespace std;

double sumahastainfinito(double a1, double r){
	double ai, sumatorio=0;
	for(int i;i<=999999;i++){
		ai=a1/(1-r);
		sumatorio=sumatorio+ai;
	}
	return sumatorio;
}

int main(){
	double a1, r, funcion;
	
	cout<<"Introduzca a1: ";
	cin>>a1;
	do{
		cout<<"Introduzca r (-1<r<n): ";
		cin>>r;
	}while(-1>r || r>1);
	
	funcion=sumahastainfinito(a1, r);
	
	cout<<"El sumatorio es: "<<funcion<<endl;
	system("pause");
}
