/*En este ejercicio se plantean varias modificaciones. Debe entregar un fichero cpp por
cada uno de los apartados.
Se desea implementar una clase Recta para representar una recta en el plano. Una
recta viene determinada por tres coeficientes A, B, C, de forma que todos los puntos
(x,y) que pertenecen a la recta verifican lo siguiente (ecuación general de la recta):
Ax + By + C = 0
c) Datos miembro privados
Cambie ahora los datos miembro públicos y póngalos privados. Tendrá que añadir
métodos para asignar y ver los valores de los datos miembro. Añada métodos para asignar un valor a cada uno de los tres datos miembro. Modifique el main
para tener en cuenta estos cambios.*/
#include <iostream>

using namespace std;

class recta{
private:
	double a, b, c, x, y;
public:
	void setTerminos(double a1, double b1, double c1, double x1, double y1){
		a=a1;
		b=b1;
		c=c1;
		x=x1;
		y=y1;
	}
	double getA(){
		return a;
	}
	double getB(){
		return b;
	}
	double getC(){
		return c;
	}
	double getX(){
		return x;
	}
	double getY(){
		return y;
	}
	double pendiente(){
		return -a/b;
	}
	double yy(){
		return (-c - x*a)/b;
	}
	double xx(){
		return (-c - y*b)/a;
	}
};

int main(){
	recta recta1, recta2;
	double pend1, pend2, variabley, variablex;
	double datoa, datob, datoc, datox, datoy;
	cout<<"Introduzca A, B, C de la primera recta, ademas de x e y: ";
	cin>>datoa;
	cin>>datob;
	cin>>datoc;
	cin>>datox;
	cin>>datoy;
	recta1.setTerminos(datoa, datob, datoc, datox, datoy);
	cout<<"Introduzca A, B, C de la segunda recta, ademas de x e y: ";
	cin>>datoa;
	cin>>datob;
	cin>>datoc;
	recta2.setTerminos(datoa, datob, datoc, datox, datoy);
	
	pend1=recta1.pendiente();
	pend2=recta2.pendiente();
	
	cout<<"Recta 1= "<<recta1.getA()<<"x + "<<recta1.getB()<<"y + "<<recta1.getC()<<" = 0"<<endl;
	cout<<"Recta 2= "<<recta2.getA()<<"x + "<<recta2.getB()<<"y + "<<recta2.getC()<<" = 0"<<endl;
	cout<<"Pendiente de la primera recta: "<<pend1<<endl;
	cout<<"Pendiente de la segunda recta: "<<pend2<<endl;
	variabley=recta1.yy();
	cout<<"La variable y cuando x="<<recta1.getX()<<" es: "<<variabley<<endl;
	cout<<"Introduzca el valor de y para la primera recta: ";
	variablex=recta1.xx();
	cout<<"La variable y cuando y="<<recta1.getY()<<" es: "<<variablex<<endl;

	system("pause");
}
