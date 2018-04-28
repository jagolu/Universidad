#include <iostream>

using namespace std;

double max(double un_valor, double otro_valor, double el_tercero){
	if(un_valor>=otro_valor && un_valor>=el_tercero){
		return un_valor;
	}
	else{
		if(otro_valor>un_valor && otro_valor>=el_tercero){
			return otro_valor;
		}
		else{
			return el_tercero;
		}
	}
}
int main(){
	double a1, b1, c1;
	cout<<"Introduzca el primer valor: ";
	cin>>a1;
	cout<<"Introduzca el segundo valor: ";
	cin>>b1;
	cout<<"Introduzca el tercer valor: ";
	cin>>c1;
	cout<<max(a1, b1, c1)<<" es el valor mayor"<<endl;
	system("pause");
}
