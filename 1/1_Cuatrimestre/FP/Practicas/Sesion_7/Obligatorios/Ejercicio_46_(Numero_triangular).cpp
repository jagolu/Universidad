/*Se dice que un número es triangular si se puede poner como la suma de los primeros
m valores enteros, para algún valor de m. Por ejemplo, 6 es triangular ya que 6 = 1 +
2 + 3. Se pide construir un programa que obtenga todos los números triangulares que
hay menores que un entero k introducido desde teclado. Para ello, debe ir probando
la suma de todas las posibles secuencias de enteros menores que el número dado.
Hay que calcular explícitamente la suma con un bucle, por lo que no puede aplicarse
la fórmula que nos da la sumatoria de los n primeros valores, a saber, n(n + 1)=2*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n, i=1, suma=0, j;
	
	cout<<"Introduzca un valor entero: ";
	cin>>n;

	for(j=1;j<=n;j++){ /*Calcula el sumatorio de las primeras cifras*/
		do{
			suma=suma+i;
			i++;
		}while(suma!=j && suma<j); /*Cuando el sumatorio sea igual o mayor a la cifra introducida, se metera en el while*/
		if(suma<=j){ /*Si se acepta la condicion del if, el numero sera triangular*/
			cout<<"El numero "<<j<<" es un numero triangular"<<endl;
		}
		suma=0;
		i=1;
	}
	system("pause");
}
