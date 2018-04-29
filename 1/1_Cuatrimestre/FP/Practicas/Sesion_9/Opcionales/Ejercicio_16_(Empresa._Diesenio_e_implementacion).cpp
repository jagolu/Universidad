/*Implementar los métodos de la clase Ventas del ejercicio anterior.*/
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class ventas{
private:
	int ventas1=0, ventas2=0, ventas3=0;
public:
	void setVentas(int sucursal, int ventas){
		if(sucursal==1){
			ventas1=ventas1+ventas;
		}
		else{
			if(sucursal==2){
				ventas2=ventas2+ventas;
			}
			else if(sucursal==3){
				ventas3=ventas3+ventas;
			}
		}
	}
	int getGanador(){
		if(ventas1>=ventas2 && ventas1>=ventas3){
			return 1;
		}
		else{
			if(ventas2>ventas1 && ventas2>=ventas3){
				return 2;
			}
			else{
				return 3;
			}
		}
	}
	int getNumVentas(){
		if(ventas1>=ventas2 && ventas1>=ventas3){
			return ventas1;
		}
		else{
			if(ventas2>ventas1 && ventas2>=ventas3){
				return ventas2;
			}
			else{
				return ventas3;
			}
		}
	}
};
	
int main(){
	ofstream fichero("relacionVentas.txt");
	ventas ventas1;
	int sucursal, ventas;
	
	do{
		cout<<"Introduzca la sucursal: ";
		cin>>sucursal;
		fichero << sucursal;
		if(sucursal!=-1){
			cout<<"Introduzca el numero de ventas de la sucursal: ";
			cin>>ventas;
			ventas1.setVentas(sucursal, ventas);
			fichero << " " <<ventas <<"\n";
		}
	}while(sucursal!=-1);
	
	cout<<"Ha vendido mas unidades la sucursal nº "<<ventas1.getGanador()<<" con "<<ventas1.getNumVentas()<<" unidades vendidas"<<endl;
	system("pause");
}
