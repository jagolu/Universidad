/*Este programa tiene 3 funciones:
		Nos dice si una letra es Verdadera (si es minuscula) o si es Falsa (si es mayuscula)
			Necesitara la variable de tipo caracter letra
		Nos dira si una es verdadera (si es menor que 18 o mayor que 65) o falso (si esta entre 18 y 65)
			Necesitara la variable de tipo entera edad
		Nos dira si un año es bisiesto (Sea divisible por 4 y no por 100, y sea divisible por 400) o no(que no se cumpla lo del otro parentesis)
			Necesitara la variable de tipo entera ano*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	char letra;
	int edad, ano;
	cout<<"Introduce una letra mayuscula o minuscula: " ;
	cin>> letra;
	cout<<"Introduce una edad: ";
	cin>>edad;
	cout<<"Introduce un anyo: ";
	cin>>ano;

	if('A'<=letra && letra<='Z')
	cout<<"Letra=Falso" <<endl;
	else if('a'<=letra && letra<='z')
	cout<<"Letra=Verdadero"<<endl;
	/*Si letra es mayor o igual que A (en AS-CII) y menor o igual que Z (en AS-CII) el programa imprimira que es falso
	Si letra esta entre a y z(a,z ambas en AS-CII) el programa imprimira que es falso */
	if(edad<18 || edad>65)
	cout<<"Edad=Verdadero" <<endl;
	else
	cout<<"Edad=Falso" <<endl;
	/*Si edad es menor que 18 o mayor que 65 el programa imprimira que es verdadero
	si en cambio no cumple lo anterior (que este entre 18 y 65) el programa imprimira que es falso*/
	if(((ano%4)==0 && (ano%100)!=0) || ((ano%400)==0))
	cout<<"El anyo es bisiesto" <<endl;
	else 
	cout<<"El anyo no es bisiesto" <<endl;
	/*si el resto de dividir ano entre 4 sea 0 y el resto de dividir ano entre 100 no sea 0, o que el resto de dividir ano entre 400 sea cero tambien, el programa
	imprimira que el año es bisiesto. En cambio si no se cumplen las condiciones anteriores imprimira que no es bisiesto*/
	system("pause");
}
