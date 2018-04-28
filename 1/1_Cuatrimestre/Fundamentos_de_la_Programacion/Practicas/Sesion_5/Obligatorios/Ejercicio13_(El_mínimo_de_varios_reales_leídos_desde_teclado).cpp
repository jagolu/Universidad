/*Realizar un programa que lea enteros desde teclado y calcule cuántos se han introducido
y cual es el mínimo de dichos valores (pueden ser positivos o negativos). Se
dejará de leer datos cuando el usuario introduzca el valor 0. Realizad la lectura de
los enteros dentro de un bucle sobre una única variable llamada dato. Es importante
controlar los casos extremos, como por ejemplo, que el primer valor leído fuese ya el
terminador de entrada (en este caso, el cero).*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int dato, contador, dato_menor;
	
	do{
		cout<<"Introduzca un dato, y luego introduzca 0 para parar: "; /*Aqui obligamos a que la primera cifra sea distinta de 0*/
		cin>>dato;
		if(dato<dato_menor && dato!=0){ /*Aqui si el primer dato es distinto de 0 lo guardaria en la variable dato_menor*/
			dato_menor=dato;
		}
	}while(dato==0);{ /*Aqui entramos en el bucle para introducir los datos*/
			if(dato!=0){ /*Aqui entrarian todos los datos distintos de 0, haciendo que al introducir el 0 se pare el programa*/
				for(contador=0;dato!=0;contador=contador+1){ /*Con este for hacemos el contador de los datos introducidos*/
					cout<<"Introduzca otro dato, y luego introduzca 0 para parar: ";
					cin>>dato;
					if(dato<dato_menor && dato!=0){ /*Aqui se va guardando el dato menor*/
						dato_menor=dato;
					}
				}
			}
			cout<<"Ha escrito: "<<contador<<" numeros"<<endl;
			cout<<"El menor numero es: "<<dato_menor<<endl;
		}
	system("pause");
}
