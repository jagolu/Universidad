/* Este programa calculara la media aritmetica y la desviacion tipica entre 3 edades.
		Necesitara:
			La estatura de las 3 personas: persona1, persona2 y persona3.
			Teniendo como constante el numero de personas (que son 3): n=3
		Calculara la media aritmetica: media= (persona1+persona2+persona3)/n
		Calculara tambien la desviacion tipica: desviacion=sqrt((pow((persona1-media),2)+pow((persona2-media),2)+pow((persona3-media),2))/n) */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double persona1, persona2, persona3, media, desviacion ;
	const double n=3 ;
	cout<<"Introduzca la altura de la primera persona: " ;
	cin>> persona1 ;
	cout<<"Introduzca la altura de la segunda persona: " ;
	cin>> persona2 ;
	cout<<"Introduzca la altura de la tercera persona: " ;
	cin>> persona3 ;
	
	media= (persona1+persona2+persona3)/n ;
	desviacion=sqrt((pow((persona1-media),2)+pow((persona2-media),2)+pow((persona3-media),2))/n);
	
	cout<<"El valor de la media aritmetica muestral es: " <<media <<endl ;
	cout<<"El valor de la desviacion tipica muestral el: " <<desviacion <<endl;
	system("pause");
	
}
