#include <iostream>
#include <cmath>

using namespace std;


double SumaHasta(double a1, double r, double k){
	double ai, sumatorio=0, potencia=r;
	for(int i=1;i<=k;i++){
		for(double j=2;j<=k;j++){
			potencia=potencia*r;
		}
		ai=a1*((potencia-1)/(r-1));
		sumatorio=sumatorio+ai;
		potencia=r;
	}
	return sumatorio;
}

int main(){
	double a1, r, k, sumahasta1;
	
	cout<<"Introduzca a1: ";
	cin>>a1;
	cout<<"Introduzca r: ";
	cin>>r;
	cout<<"Introduzca k: ";
	cin>>k;
	
	sumahasta1=SumaHasta(a1, r, k);
	
	cout<<"El sumatorio es: "<<sumahasta1<<endl;
	system("pause");
}
