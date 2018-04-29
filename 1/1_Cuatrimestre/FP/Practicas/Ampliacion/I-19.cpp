#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double precio, ganancia, iva, total;
	cout<<"Introduzca el precio de fabrica del vehiculo: ";
	cin>> precio;
	ganancia=precio*0.2;
	iva=precio*0.16;
	total=precio+ganancia+iva;
	cout<<"El precio final del vehiculo es: " <<total <<endl;
	system("pause");
}
