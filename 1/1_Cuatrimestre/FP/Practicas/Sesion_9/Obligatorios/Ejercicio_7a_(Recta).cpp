/*En este ejercicio se plantean varias modificaciones. Debe entregar un fichero cpp por
cada uno de los apartados.
Se desea implementar una clase Recta para representar una recta en el plano. Una
recta viene determinada por tres coeficientes A, B, C, de forma que todos los puntos
(x,y) que pertenecen a la recta verifican lo siguiente (ecuación general de la recta):
Ax + By + C = 0
a) Definición de la clase y creación de objetos
Defina la clase Recta. En este apartado utilice únicamente datos miembro públicos.
Cree un programa principal que haga lo siguiente:
 Defina dos objetos de la clase Recta.
 Lea seis reales desde teclado.
 Le asigne los tres primeros a los coeficientes de una recta y los otros tres a
la segunda recta.
 Calcule e imprima la pendiente de cada recta aplicando la fórmula:
pendiente = - A / B*/
#include <iostream>

using namespace std;

class recta{
public:
	double a, b, c;
};

int main(){
	recta recta1, recta2;
	double pend1, pend2;
	double dato;
	cout<<"Primer dato de la primera recta: ";
	cin>>dato;
	recta1.a=dato;
	cout<<"Segundo dato de la primera recta: ";
	cin>>dato;
	recta1.b=dato;
	cout<<"Tercer dato de la primera recta: ";
	cin>>dato;
	recta1.c=dato;
	cout<<"Primer dato de la segunda recta: ";
	cin>>dato;
	recta2.a=dato;
	cout<<"Segundo dato de la segunda recta: ";
	cin>>dato;
	recta2.b=dato;
	cout<<"Tercer dato de la tercera recta: ";
	cin>>dato;
	recta2.c=dato;
	
	pend1=-recta1.a/recta1.b;
	pend2=-recta2.a/recta2.b;
	
	cout<<"Recta 1= "<<recta1.a<<"x + "<<recta1.b<<"y + "<<recta1.c<<" = 0"<<endl;
	cout<<"Recta 2= "<<recta2.a<<"x + "<<recta2.b<<"y + "<<recta2.c<<" = 0"<<endl;
	cout<<"Pendiente de la primera recta: "<<pend1<<endl;
	cout<<"Pendiente de la segunda recta: "<<pend2<<endl;
	system("pause");
}
