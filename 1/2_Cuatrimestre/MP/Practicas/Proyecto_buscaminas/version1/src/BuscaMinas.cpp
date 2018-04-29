#include <iostream>
#include "Tablero.h"
#include "CampoMinas.h"
using namespace std;
int main(){
	int f, c, n;
	char orden;
	cout<<"Dime el tamanio del tablero (filas y columnas): ";
	do{
		cin>>f;
		cin>>c;
		if(f<0 || c<0 || f>20 || c>20){
			cout<<"El numero maximo de filas o columnas es 20.\nIntroduzca otras dimensiones (filas y columnas): ";
		}
	}while(f<0 || c<0 || f>20 || c>20);
	cout<<"Dime el numero de minas: ";
	do{
		cin>>n;
		if(((f*c)/2)<n){
			cout<<"El numero de minas debe ser menor que la mitad de casillas que tiene el mapa.\nIntroduzca otro numero de minas: ";
		}
	}while(((f*c)/2)<n);
	CampoMinas cm(f, c, n);
	do{
		cm.PrettyPrint();
		cout<<"Dime accion y posicion (fil y col): ";
		cin>>orden;
		cin>>f;
		cin>>c;
		if(orden=='a' || orden=='A'){
			if(f>=0 && c>=0 && f<cm.Get_Filas() && c<cm.Get_Columnas()){
				if(cm.Abrir(f,c));
				else cout<<"La orden no ha tenido exito\n";
			}
			else cout<<"Las filas y columnas introducidas no estan en el tablero\n";
		}
		else if(orden=='m' || orden=='M'){
			if(f>=0 && c>=0 && f<cm.Get_Filas() && c<cm.Get_Columnas()){
				if(cm.Marcar(f,c)) cout<<"marcando...\n";
				else cout<<"La orden no ha tenido exito\n";
			}
			else cout<<"Las filas y columnas introducidas no estan en el tablero\n";
		}
		else{
			cout<<"Orden no reconocida.\n   M/m Marcar casilla\n   A/a Abrir casilla\n";
		}
	}while(cm.Victoria()!=true && cm.Mina_explosionada()!=true);
	if(cm.Victoria()){
		cm.Tablero_Final_Partida();
		cout<<endl<<"Enhorabuena!\n";
	}
	else if(cm.Mina_explosionada()){
		cm.Tablero_Final_Partida();
		cout<<endl<<"Lo siento, has perdido\n";
	}
	else{
		cm.Tablero_Final_Partida();
	}
}

