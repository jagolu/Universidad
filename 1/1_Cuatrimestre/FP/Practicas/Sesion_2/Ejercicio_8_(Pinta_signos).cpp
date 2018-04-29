/* Este programa a partir de un numero de 3 cifras, cogera cada una de las cifras y las pondra separadas por un espacio.
		Necesita: el numero de 3 cifras: valor
		Extraera la primera cifra: 
				numero1= valor/100 
				cifra1=int(numero1)
		Despues la segunda:
				numero2=(numero1-cifra1)*10
				cifra2=int(numero2)
		Y por ultimo la tercera:
				numero3=(numero2-cifra2)*10
				cifra3=numero3
		Y pondra las 3 cifras separadas por un espacio. */
#include <iostream>
#include <cmath>

using namespace std;

int main () {
	double valor, numero1, cifra1, numero2, cifra2, numero3, cifra3;
	cout<<"Introduce el numero de 3 digitos: " ;
	cin>> valor;
	
	numero1= valor/100 ;
	cifra1=int(numero1);
	numero2=(numero1-cifra1)*10;
	cifra2=int(numero2);
	numero3=(numero2-cifra2)*10;
	cifra3=numero3;
	cout<< cifra1 <<"   " <<cifra2 <<"   " <<cifra3 <<endl ;

	system("pause");
	
}
