/*Se pide leer un carácter desde teclado, obligando al usuario a que sea una letra mayúscula.
Para ello, habrá que usar una estructura repetitiva do while, de forma que
si el usuario introduce un carácter que no sea una letra mayúscula, se le volverá a
pedir otro carácter. Calculad la minúscula correspondiente e imprimidla en pantalla.
No pueden usarse las funciones tolower ni toupperde la biblioteca cctype.*/
#include <iostream>

using namespace std;

int main(){
	char letra, letra_minuscula;
	do{
		cout<<"Introduzca una letra mayuscula: ";
		cin>>letra;
	}while('a'<=letra && letra<='z');{ /*Con este do while obligamos al usuario a escribir una letra mayuscula*/
		letra_minuscula=letra+' '; /*Aqui transformamos la letra mayuscula en su respectiva mayuscula*/
		cout<<"Su letra minuscula es: "<<letra_minuscula<<endl;
	}
	system("pause");
}
