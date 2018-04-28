/*En este ejercicio se plantean varias modificaciones. Debe entregar un fichero cpp por
cada uno de los apartados.
Se desea implementar una clase Recta para representar una recta en el plano. Una
recta viene determinada por tres coeficientes A, B, C, de forma que todos los puntos
(x,y) que pertenecen a la recta verifican lo siguiente (ecuación general de la recta):
Ax + By + C = 0

Política de acceso a los datos miembro
Suprima ahora el método SetCoeficientes. De esta forma, una vez creado
el objeto (pasándole los datos apropiados en el constructor) ya no podremos
modificar los datos miembro. Esto es útil en aquellas situaciones en las que no
queremos permitir que el estado del objeto cambie, una vez se ha creado.*/
#include <iostream>

using namespace std;

class recta{
private:
	double a, b, c, x, y;
	double nulo(){
		if(a==0 && b==0){
			a=a+1;
			b=b+1;
		}
	}
public:
	recta(){
	a=0;
	b=0;
	c=0;
	}
	recta(double a1, double b1, double c1, double x1, double y1){
		a=a1;
		b=b1;
		c=c1;
		x=x1;
		y=y1;
		nulo();
	}
	void setTerminos(double a1, double b1, double c1, double x1, double y1){
		a=a1;
		b=b1;
		c=c1;
		x=x1;
		y=y1;
		nulo();
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
	recta rectaA, rectaB;
	double pend1, pend2, variabley, variablex;
	double datoa, datob, datoc, datox, datoy;
	cout<<"Recta 1= "<<rectaA.getA()<<"x + "<<rectaA.getB()<<"y + "<<rectaA.getC()<<" = 0"<<endl;
	cout<<"Recta 2= "<<rectaB.getA()<<"x + "<<rectaB.getB()<<"y + "<<rectaB.getC()<<" = 0"<<endl;
	cout<<"Introduzca A, B, C de la primera recta, ademas de x e y: "<<endl;
	cin>>datoa;
	cin>>datob;
	cin>>datoc;
	cin>>datox;
	cin>>datoy;
	recta recta1(datoa, datob, datoc, datox, datoy);
	recta1.setTerminos(datoa, datob, datoc, datox, datoy);
	cout<<"Introduzca A, B, C de la segunda recta, ademas de x e y: "<<endl;
	cin>>datoa;
	cin>>datob;
	cin>>datoc;
	recta recta2(datoa, datob, datoc, datox, datoy);
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
