/*Se quiere leer un car�cter letra_original desde teclado, y comprobar con una
estructura condicional si es una letra may�scula. En dicho caso, hay que calcular
la min�scula correspondiente en una variable llamada letra_convertida.
En cualquier otro caso, le asignaremos a letra_convertida el valor que
tenga letra_original. Finalmente, imprimiremos en pantalla el valor de
letra_convertida. No pueden usarse las funciones tolower ni toupper de la
biblioteca cctype.*/
#include <iostream>

using namespace std;

int main(){
	char letra_convertida, letra_original;
	const int DISTANCIA_MAY_MIN = 'a'-'A';
	string tipo_letra;
	bool es_mayuscula;
		
	cout << "\nIntroduzca una letra --> ";
	cin >> letra_original;
if ((letra_original >= 'A') && (letra_original <= 'Z')){
	letra_convertida = letra_original + DISTANCIA_MAY_MIN;
	cout << letra_convertida;
}
else{
	cout << letra_original << " no es una may�scula";
}
if ((letra_original >= 'A') && (letra_original <= 'Z'))
	tipo_letra = "es may�scula";
if (tipo_letra == "es may�scula")
	letra_convertida = letra_original + DISTANCIA_MAY_MIN;
else
	letra_convertida = letra_original;
	cout << "\nEl car�cter " << letra_original<< " una vez convertido es: " << letra_convertida;
if ((letra_original >= 'A') && (letra_original <= 'Z'))
	es_mayuscula = true;
if (es_mayuscula)
	letra_convertida = letra_original + DISTANCIA_MAY_MIN;
	cout << "\nEl car�cter " << letra_original<< " una vez convertido es: " << letra_convertida;
	
	system("pause");
}
