/*En este ejercicio se plantean varias modificaciones. Debe entregar un fichero cpp por
cada uno de los apartados.
Se desea implementar una clase Recta para representar una recta en el plano. Una
recta viene determinada por tres coeficientes A, B, C, de forma que todos los puntos
(x,y) que pertenecen a la recta verifican lo siguiente (ecuación general de la recta):
Ax + By + C = 0
Política de acceso a los datos miembros
En vez de usar un método para asignar un valor a cada dato miembro, defina un
único método SetCoeficientes para asignar los tres a la misma vez.
Observad que los métodos permiten definir la política de acceso a los datos
miembro. Si tengo previsto cambiar por separado los coeficientes de la recta,
usaré métodos de asignación individuales. En caso contrario, usaré un único método
que modifique a la misma vez todos los datos miembro. Incluso pueden
dejarse en la clase ambos tipos de métodos para que así el cliente de la clase
pueda usar los que estime oportunos en cada momento. Por ahora, mantenga
únicamente el método de asignación en bloque SetCoeficientes.*/
#include <iostream>

using namespace std;

class recta{
private:
	double a, b, c, x, y;
public:
	recta(){
	a=0;
	b=0;
	c=0;
	}
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
	cout<<"Recta 1= "<<recta1.getA()<<"x + "<<recta1.getB()<<"y + "<<recta1.getC()<<" = 0"<<endl;
	cout<<"Recta 2= "<<recta2.getA()<<"x + "<<recta2.getB()<<"y + "<<recta2.getC()<<" = 0"<<endl;
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
