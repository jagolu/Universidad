/*Recuperad la solución del ejercicio 11 de la Relación de Problemas II (Empresa). Reescribid
el programa principal usando una clase Ventas para gestionar los cómputos
de las ventas realizadas. Únicamente se pide que se indiquen las cabeceras de los
métodos públicos de la clase y las llamadas a éstos en el programa principal. No hay
que implementar ninguno de los métodos.*/
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class ventas{
private:
	int ventas1=0, ventas2=0, ventas3=0;
public:
	void setVentas(int sucursal, int ventas){
	//Aqui ira acumulando las ventas de cada sucursal
	int getGanador(){
	//Aqui nos dira mediante if y else cual es la sucursal con mas ventas
	}
	int getNumVentas(){
	//Aqui mostraremos el numero de ventas mas alto
	}
};
	
int main(){
	ofstream fichero("relacionVentas.txt");
	ventas ventas1; //Crearemos el objeto
	int sucursal, ventas;
	
	do{
		cout<<"Introduzca la sucursal: ";
		cin>>sucursal;
		//Identificaremos la sucursal
		fichero << sucursal;
		if(sucursal!=-1){ 
			cout<<"Introduzca el numero de ventas de la sucursal: ";
			cin>>ventas;
			ventas1.setVentas(sucursal, ventas);
			fichero << " " <<ventas <<"\n";
			//Al objeto creado le meteremos las variables sucursal y ventas introducidas
		}
	}while(sucursal!=-1);
	
	cout<<"Ha vendido mas unidades la sucursal nº "<<ventas1.getGanador()<<" con "<<ventas1.getNumVentas()<<" unidades vendidas"<<endl;
	system("pause");
}
