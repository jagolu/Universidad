/*¿Cuántas veces aparece el dígito 9 en todos los números
que hay entre el 1 y el 100? Por ejemplo, el 9 aparece una vez en los números 19 y
92 mientras que aparece dos veces en el 99. Pretendemos diseñar un algoritmo que
responda a esta sencilla pregunta, pero de forma suficientemente generalizada. Para
ello, se pide construir un programa que lea tres enteros cifra (entre 1 y 9), min y
max y calcule el número de apariciones del dígito cifra en los números contenidos
en el intervalo cerrado [min, max].*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int cifra, min, max, i, j, k, resto, contador;
	
	cout<<"Introduzca el minimo: ";
	cin>>min;
	cout<<"Introduzca el maximo: ";
	cin>>max;
	cout<<"Introduzca la cifra que desea examinar: ";
	cin>>cifra;
	
	contador=0;
	
	for(i=min;i<=max;i++){ /*Iniciamos el bucle desde el minimo hasta el maximo introducido*/
		k=i;
		for(j=1;j<=i;j=j*10){ /*Sacamos las cifras del numero por el que vamos*/
			resto=k%10;
			k=k/10;
			if(resto==cifra){ /*Si cualquiera de las cifras es igual a la cifra que examinamos se añadira +1 al contador*/
				contador=contador+1;
			}
		}
	}
	cout<<"Desde "<<min<<" hasta "<<max<<" se repite "<<contador<<" veces la cifra "<<cifra<<endl;
	system("pause");
}
