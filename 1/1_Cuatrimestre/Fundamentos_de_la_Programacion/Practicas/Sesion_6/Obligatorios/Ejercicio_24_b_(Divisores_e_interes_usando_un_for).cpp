/*Reescribid la solución a los ejercicios 12 (divisores) y 15 (interés) usando un bucle for*/
#include <iostream>

using namespace std;

int main(){
	double capital, interes, anos, i;	
	cout<<"Introduzca su capital: ";
	cin>>capital;
	cout<<"Introduzca su interes: ";
	cin>>interes;
	cout<<"Introduzca el numero de anios: ";
	cin>>anos;
	
	cout<<"Total en el anio numero 1 = "<<capital<<endl; /*Este cout es porque el primer anio siempre tenemos el valor inicial*/
	for(i=2;i<=anos;i=i+1){ /*Aqui va calculando el nuevo capital hasta que la i llegue al numero de anios introducidos*/
		capital=capital+(capital*(interes/100));
		cout<<"Total en el anio numero "<<i<<" = "<<capital<<endl;
	}
	system("pause");
}
