/*Este programa detecta un numero del 0 al 9 en caracter y devuelve el mismo caracter, pero en AS-CII
	es decir si el programa detecta el caracter 8, nos devolvera el '8' (AS-CII)
	Necesita
		Una variable entera (entero)
		Una variable en caracter (caracter)*/
#include <iostream>

using namespace std;

int main(){
	int entero;
	char caracter;
	
	cout<<"Escriba un numero entre 0 y 9: ";
	cin>> caracter;
	
	entero=caracter-'0';
	/*Al introducir el numero del 0 al 9, y que lo almacene como AS-CII, y restandole '0' (48 unidades) el valor del (por ejemplo) 9 en caracter lo llevara
	al valor del 9 en AS-CII que es el el tabulador, pero el programa imprimira el tabulador en AS-CII, osea el 9*/
	cout<<entero <<endl;
	system("pause");
	
}
	
