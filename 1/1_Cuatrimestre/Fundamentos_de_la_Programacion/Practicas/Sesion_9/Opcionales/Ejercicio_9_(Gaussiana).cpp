/*Recuperad el ejercicio 6 de esta relación de problemas sobre la función gaussiana.
En vez de trabajar con funciones, plantead la solución con una clase.*/
#include <iostream>
#include <cmath>

using namespace std;

class gaussiana{
private:
	double esp, des, x;
public:
	gaussiana(double esp1, double des1, double x1){
		esp=esp1;
		des=des1;
		x=x1;
	}
	double funcion(){
		double e=2.7182, pi=3.1415;
		double lafuncion, e_elevado1, e_elevado2;
		e_elevado1=pow(((x-esp)/des),2);
		e_elevado2=pow(e,(-0.5*e_elevado1));
		lafuncion=((1/(des*(sqrt(2*pi))))*e_elevado2);
		return lafuncion;
	}
	double area(){
		double b0=0.2316419, b1=0.319381530, b2=-0.356563782;
		double b3=1.781477937, b4=-1.821255978, b5=1.330274429;
		double eB=2.7182, piB=3.1415;
		double lafuncionB, e_elevado1B, e_elevado2B;
		e_elevado1B=pow(((x-esp)/des),2);
		e_elevado2B=pow(eB,(-0.5*e_elevado1B));
		lafuncionB=((1/(des*(sqrt(2*piB))))*e_elevado2B);
		double t, area1, parentesis;
		t=(1/(1+(b0*x)));
		parentesis=(b1*t)+(b2*(pow(t,2)))+(b3*(pow(t,3)))+(b4*(pow(t,4)))+(b5*(pow(t,5)));
		area1=1-(lafuncionB*parentesis);
		return area1;
	}
};
int main(){
	double des, esp, x, funcion11, area11;
	
	cout<<"Introduzca la esperanza, desviacion y el valor de x: "<<endl;
	cin>>esp;
	cin>>des;
	cin>>x;
	
	gaussiana funciona(esp, des,x);
	funcion11=funciona.funcion();
	area11=funciona.area();
	
	cout<<"El valor de la funcion gaussiana en el valor de x es: "<<funcion11<<endl;
	cout<<"El valor del area desde menos infinito hasta x es: "<<area11<<endl;
}
	
