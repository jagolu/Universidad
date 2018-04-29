#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h> 
#include "Tablero.h"
#include "CampoMinas.h"
using namespace std;
int main(int argc, char* argv[]){
	if(argc==4){
		int f=atoi(argv[1]);
		int c=atoi(argv[2]);
		int n=atoi(argv[3]);
		if(f<=20 && f>=0 && c<=20 && c>=0){
			if(((f*c)/2)>n){
				CampoMinas cm(f,c,n);
				string orden;
				bool Guardar_partida=false;
				do{
					cm.PrettyPrint(cout);
					cout<<"Dime accion y posicion (fil y col): ";
					cin>>orden;
					for(int i=0;i<orden.size();i++){
						orden[i]=tolower(orden[i]);
					}
					if(orden=="a" || orden=="abrir"){
						cin>>f;
						cin>>c;
						if(f>=0 && f<cm.Get_Filas() && c>=0 && c<cm.Get_Columnas()){
							if(cm.Abrir(f,c));
							else cout<<"La orden no ha tenido exito\n";
						}
						else cout<<"La orden no ha tenido exito\n";
					}
					else if(orden=="m" || orden=="marcar"){
						cin>>f;
						cin>>c;
						if(f>=0 && f<cm.Get_Filas() && c>=0 && c<cm.Get_Columnas()){
							if(cm.Marcar(f,c));
							else cout<<"La orden no ha tenido exito\n";
						}
						else cout<<"La orden no ha tenido exito\n";
					}
					else if(orden=="s" || orden=="salvar"){
						ofstream fs("Partida_BuscaMinas.txt");
						if(cm.Escribir(fs,cm)){
							Guardar_partida=true;
						}
						else cout<<"No ha sido posible guardar la partida\n";
					}
					else{
						cout<<"Orden no reconocida.\n   M/m/Marcar Marcar casilla\n   A/a/Marcar Abrir casilla\n   S/s/Salvar Guardar Partida\n";
					}
				}while(cm.Victoria()!=true && cm.Mina_explosionada()!=true && Guardar_partida!=true);
					if(cm.Victoria()){
						cm.Tablero_Final_Partida();
						cout<<endl<<"Has Ganado, Enhorabuena!\n";
				}
				else if(cm.Mina_explosionada()){
					cm.Tablero_Final_Partida();
					cout<<endl<<"Lo siento, has perdido\n";
				}
				else if(Guardar_partida){
					cout<<"Partida guardada con exito\n";
				}
				else{
					cm.Tablero_Final_Partida();
				}	
			}
			else{
				cout<<"El numero de minas debe ser menor que la mitad de las casillas que tiene el mapa.\n";
			}
		}
		else{
			cout<<"Las filas y las columnas deben ser menores que 20\n";
		}
	}
	else if(argc==2){
		ifstream nom(argv[1]);
		CampoMinas cm(0,0,0);
		if(cm.Leer(nom,cm)==false) cout<<"No ha sido posible cargar la partida con exito\n";
		else{
			string orden;
			int f, c;
			bool Guardar_partida=false;
			do{
				cm.PrettyPrint(cout);
				cout<<"Dime accion y posicion (fil y col): ";
				cin>>orden;
				for(int i=0;i<orden.size();i++){
					orden[i]=tolower(orden[i]);
				}
				if(orden=="a" || orden=="abrir"){
					cin>>f;
					cin>>c;
					if(f>=0 && f<cm.Get_Filas() && c>=0 && c<cm.Get_Columnas()){
						if(cm.Abrir(f,c));
						else cout<<"La orden no ha tenido exito\n";
					}
					else cout<<"La orden no ha tenido exito\n";
				}
				else if(orden=="m" || orden=="marcar"){
					cin>>f;
					cin>>c;
					if(f>=0 && f<cm.Get_Filas() && c>=0 && c<cm.Get_Columnas()){
						if(cm.Marcar(f,c));
						else cout<<"La orden no ha tenido exito\n";
					}
					else cout<<"La orden no ha tenido exito\n";
				}
				else if(orden=="s" || orden=="salvar"){
					ofstream fs("Partida_BuscaMinas.txt");
					if(cm.Escribir(fs,cm)){
						Guardar_partida=true;
					}
					else cout<<"No ha sido posible guardar la partida\n";
				}
				else{
					cout<<"Orden no reconocida.\n   M/m/Marcar Marcar casilla\n   A/a/Marcar Abrir casilla\n   S/s/Salvar Guardar Partida\n";
				}
				ofstream fs("nombre.txt");
				cm.Escribir(fs,cm); 
			}while(cm.Victoria()!=true && cm.Mina_explosionada()!=true && Guardar_partida!=true);	
			if(cm.Victoria()){
				cm.Tablero_Final_Partida();
				cout<<endl<<"Has Ganado, Enhorabuena!\n";
			}
			else if(cm.Mina_explosionada()){
				cm.Tablero_Final_Partida();
				cout<<endl<<"Lo siento, has perdido\n";
			}
			else if(Guardar_partida){
				cout<<"Partida guardada con exito\n";
			}
			else{
				cm.Tablero_Final_Partida();
			}	
		}
	}
	else{
		cout<<"Es necesario introducir argumentos.\n     ·3 argumentos: filas columnas numero de minas\n     ·1 argumento que sera un archivo con una partida guardada\n";
	}
}

