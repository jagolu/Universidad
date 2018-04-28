/* Este es un programa que intercambiara el valor de dos variables (La edad de Juan y la de Pedro).
		Necesita:
			La edad de Juan: edad_juan
			La edad de Pedro: edad_pedro
		Intercambiara la edad de Juan por la de Pedro: 	edad_juan1= edad_pedro
		Intercambiara la edad de Pedro por la de Juan: edad_pedro1= edad_juan */
			

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double edad_pedro, edad_juan, edad_pedro1, edad_juan1;
	
		cout<<"Introduzca la edad de Pedro: ";
		cin>> edad_pedro ;
		cout<<"Introduzca la edad de Juan: ";
		cin>> edad_juan;
		
		edad_pedro1= edad_juan ;
		edad_juan1= edad_pedro ;
		
		cout<<"Edad de Pedro: " <<edad_pedro1 <<endl ;
		cout<<"Edad de Juan: " <<edad_juan1 <<endl ;
		system("pause");
		
}
