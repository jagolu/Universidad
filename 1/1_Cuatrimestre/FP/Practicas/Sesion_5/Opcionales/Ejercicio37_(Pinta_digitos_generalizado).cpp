/*En el ejercicio 8 de la Relaci�n de Problemas I se ped�a escribir un programa que leyese
un valor entero de tres d�gitos e imprimiese los d�gitos separados por un espacio
en blanco. Haced lo mismo pero para un n�mero entero arbitrario.*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int numero, contador, cifra, i;
	
	cout<<"Introduce un numero entero: ";
	cin>>numero;
	contador=0; /*Este contador sera el numero de cifras que tenga el numero*/
	while((numero/pow(10,contador))>=10){ /*con este while y este algoritmo se sacaran las cifras que tiene el numero*/
		contador=contador+1; /*Y el bucle se ira repitiendo hasta que el numero siga pudiendo dividirse*/
	}
	for(i=contador;i>=0;i=i-1){ /*Con este bucle sacaremos cada una de las cifras*/
		cifra=(numero/pow(10,i));
		cout<<cifra%10<<"  ";
	}
	cout<<"\n";
}
