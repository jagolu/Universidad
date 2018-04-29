/*En este ejercicio se plantean varias modificaciones. Debe entregar un fichero cpp por
cada uno de los apartados.
Se desea implementar una clase Recta para representar una recta en el plano. Una
recta viene determinada por tres coeficientes A, B, C, de forma que todos los puntos
(x,y) que pertenecen a la recta verifican lo siguiente (ecuación general de la recta):
Ax + By + C = 0
b) Métodos públicos
En vez de calcular la pendiente en el programa principal, vamos a ponerlo como
un método de la clase y así lo reutilizaremos todas las veces que necesitemos.
Añada un método para el cálculo de la pendiente y modificad el main para tener
en cuenta este cambio.
¿Añadimos pendiente como dato miembro de la recta? La respuesta es que
no ¿Por qué?
Añadir también los siguiente métodos:
 Obtener la ordenada (y) dado un valor de abscisa x, aplicando la fórmula:
(-C -xA) / B
 Obtener la abscisa (x) dado un valor de ordenada y, aplicando la fórmula:
(-C -yB) / A
En la función main leed un valor de abscisa e imprimir la ordenada según la recta
y leed un valor de ordenada e imprimid la abscisa que le corresponde. Hacedlo
sólo con la primera recta.*/
#include <iostream>

using namespace std;

class recta{
public:
	double a, b, c, x, y;
	double pendiente(){
		double pend=-a/b;
		return pend;
	}
	double yy(){
		double variable2=(-c - x*a) / b;
		return variable2;
	}
	double xx(){
		double variable1=(-c - y*b) / a;
		return variable1;
	}
};

int main(){
	recta recta1, recta2;
	double pend1, pend2, variabley, variablex;
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
	
	pend1=recta1.pendiente();
	pend2=recta2.pendiente();
	
	cout<<"Recta 1= "<<recta1.a<<"x + "<<recta1.b<<"y + "<<recta1.c<<" = 0"<<endl;
	cout<<"Recta 2= "<<recta2.a<<"x + "<<recta2.b<<"y + "<<recta2.c<<" = 0"<<endl;
	cout<<"Pendiente de la primera recta: "<<pend1<<endl;
	cout<<"Pendiente de la segunda recta: "<<pend2<<endl;
	cout<<"Introduzca el valor de x para la primera recta: ";
	cin>>dato;
	recta1.x=dato;
	variabley=recta1.yy();
	cout<<"La variable y cuando x="<<recta1.x<<" es: "<<variabley<<endl;
	cout<<"Introduzca el valor de y para la primera recta: ";
	cin>>dato;
	recta1.y=dato;
	variablex=recta1.xx();
	cout<<"La variable x cuando y="<<recta1.y<<" es: "<<variablex<<endl;

	system("pause");
}
