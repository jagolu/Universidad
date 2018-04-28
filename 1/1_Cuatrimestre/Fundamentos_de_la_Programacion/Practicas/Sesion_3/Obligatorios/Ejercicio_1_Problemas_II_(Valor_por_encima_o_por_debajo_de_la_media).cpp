/*Este es un programa que a partir de 3 edades (variables de tipo entero) calcula su media y su desviacion tipica
y despues de eso imprimira el resultado de la media y la desviacion. Despues calculara si la altura de cada uno de los
datos esta por encima, por debajo o dentro de su media.
	Necesita la altura de las 3 personas (persona1, persona2, persona3)*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int persona1, persona2, persona3;
	double media, desviacion ;
	const double n=3 ;
	cout<<"Introduzca la altura de la primera persona en centimetros: " ;
	cin>> persona1 ;
	cout<<"Introduzca la altura de la segunda persona en centimetros: " ;
	cin>> persona2 ;
	cout<<"Introduzca la altura de la tercera persona en centimetros: " ;
	cin>> persona3 ;
	
	media= (persona1+persona2+persona3)/n ;
	desviacion=sqrt((pow((persona1-media),2)+pow((persona2-media),2)+pow((persona3-media),2))/n);
	/*La media calcula la suma de los 3 datos y divide dicha suma entre el numero de datos (n=3, que es una constante)
	La desviacion calcula la raiz del sumatorio de cada uno de los datos menos la media elevado al cuadrado y dicho sumatorio dvidido entre
	el numero de datos (n=3)*/
	cout<<"El valor de la media aritmetica muestral es: " <<media <<endl ;
	cout<<"El valor de la desviacion tipica muestral el: " <<desviacion <<endl;
	if(persona1<media)
	cout<<persona1 <<" esta por debajo de su media"<<endl;
	else if(persona1>media)
	cout<<persona1 <<" esta por encima de su media"<<endl;
	else if(media==persona1)
	cout<<persona1<<" esta dentro de su media" <<endl;
	
	if(persona2<media)
	cout<<persona2 <<" esta por debajo de su media"<<endl;
	else if(persona2>media)
	cout<<persona2 <<" esta por encima de su media"<<endl;
	else if(media==persona2)
	cout<<persona2<<" esta dentro de su media" <<endl;
	
	if(persona3<media)
	cout<<persona3 <<" esta por debajo de su media"<<endl;
	else if(persona3>media)
	cout<<persona3 <<" esta por encima de su media"<<endl;
	else if(media==persona3)
	cout<<persona3<<" esta dentro de su media" <<endl;
	/*Para saber si cada una de las alturas esta por encima, por debajo o dentro de su media, hacemos un algoritmo para cada altura
	diciendo que si la altura esta estrictamente por debajo de la media, el programa imprimira que diha altura esta por debajo de la media. Tambien 
	diremos que si la altura es estrictamente mayor que la media el programa imprimira que la altura esta por encima de la media. Por otro lado, si 
	la altura es igual a la media el programa imprimira que la altura esta dentro de la media.*/

	system("pause");
	
	
	
}
