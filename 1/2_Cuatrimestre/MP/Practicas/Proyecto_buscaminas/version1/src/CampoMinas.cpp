#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "CampoMinas.h"
#include "Tablero.h"
using namespace std;
int CampoMinas::Bombas_Cercanas(const int& f, const int& c){
	int bombas=0;
	for(int i=f-1;i<=f+1;i++){
		for(int j=c-1;j<=c+1;j++){
			if(i>=0 && j>=0 && i<Get_Filas() && j<Get_Columnas()){
				if(m.Get_Elemento(i,j).Bomba){
					bombas++;
				}
			}
		}
	}
	return bombas;
}
CampoMinas::CampoMinas(const int& f, const int& c, const int& num_minas):m(f,c){
	Casilla p;
	p.Abierta=0;
	p.Bomba=0;
	p.Marcada=0;
	for(int i=0;i<f;i++){
		for(int j=0;j<c;j++){
			m.Set_Elemento(i,j,p);
		}
	}
	int bombas_puestas=0;
	p.Bomba=1;
	while(bombas_puestas<num_minas){
		int ff=rand()%f;
		int cc=rand()%c;
		if(m.Get_Elemento(ff,cc).Bomba==false){
			m.Set_Elemento(ff,cc,p);
			bombas_puestas++;
		}
	}
}

bool CampoMinas::Mina_explosionada(){
	bool explosion=false;
	for(int i=0;i<Get_Filas();i++){
		for(int j=0;j<Get_Columnas();j++){
			if(m.Get_Elemento(i,j).Bomba && m.Get_Elemento(i,j).Abierta){
				explosion=true;
			}
		}
	}
	return explosion;
}
bool CampoMinas::Victoria(){
	bool juego_ganado;
	if(Mina_explosionada()){
		juego_ganado=false;
	}
	else{
		int contador_bombas=0;
		int bombas_marcadas=0;
		int casillas_abiertas=0;
		int resto_casillas;
		for(int i=0;i<Get_Filas();i++){
			for(int j=0;j<Get_Columnas();j++){
				if(m.Get_Elemento(i,j).Bomba){
					contador_bombas++;
				}
				if(m.Get_Elemento(i,j).Bomba && m.Get_Elemento(i,j).Marcada){
					bombas_marcadas++;
				}
				if(m.Get_Elemento(i,j).Abierta && m.Get_Elemento(i,j).Bomba==false){
					casillas_abiertas++;
				}
			}
		}
		resto_casillas=(Get_Filas()*Get_Columnas())-contador_bombas;
		if(bombas_marcadas==contador_bombas && resto_casillas==casillas_abiertas){
			juego_ganado=true;
		}
		else{
			juego_ganado=false;
		}
	}
	return juego_ganado;
}
bool CampoMinas::Marcar(const int& f, const int& c){
	bool marcado;
	if(f>Get_Filas() || c>Get_Columnas()){
		marcado=false;
	}
	else if(m.Get_Elemento(f,c).Abierta){
		marcado=false;
	}
	else{
		Casilla q=m.Get_Elemento(f,c);
		if(q.Marcada){
			q.Marcada=false;
		}
		else{
			q.Marcada=true;
		}
		m.Set_Elemento(f,c,q);
		marcado=true;
	}
	return marcado;
}
bool CampoMinas::Abrir(const int& f, const int& c){
	bool abierto;
	if(f>=Get_Filas() || c>=Get_Columnas() || f<0 || c<0){
		abierto=false;
	}
	else if(m.Get_Elemento(f,c).Abierta){
		abierto=false;
	}
	else if(m.Get_Elemento(f,c).Marcada){
		abierto=false;
	}
	else{
		Casilla q=m.Get_Elemento(f,c);
		q.Abierta=true;
		m.Set_Elemento(f,c,q);
		abierto=true;
	}
	if(Bombas_Cercanas(f,c)==0){
		for(int i=f-1;i<=f+1;i++){
			for(int j=c-1;j<=c+1;j++){
				if(i>=0 && j>=0 && i<Get_Filas() && j<Get_Columnas()){
					if(m.Get_Elemento(i,j).Bomba==false && m.Get_Elemento(i,j).Marcada==false && m.Get_Elemento(i,j).Abierta==false){
						Abrir(i,j);
					}
				}
			}
		}				
	}
	return abierto;
}
void CampoMinas::PrettyPrint(){
	cout<<"   ";
	for(int i=0;i<Get_Columnas();i++){
		if(i<10) cout<<"  "<<i;
		else cout<<" "<<i;
	}
	cout<<endl<<"   ";
	for(int i=0;i<Get_Columnas();i++){
		cout<<"---";
	}
	cout<<"-"<<endl;
	for(int i=0;i<Get_Filas();i++){
		if(i<10) cout<<i<<"  | ";
		else cout<<i<<" | ";
		for(int j=0;j<Get_Columnas();j++){
			if(m.Get_Elemento(i,j).Abierta==false){
				if(m.Get_Elemento(i,j).Marcada){
					cout<<"?";
				}
				else{
					cout<<"*";
				}
			}
			else{
				if(m.Get_Elemento(i,j).Bomba==false){
					if(Bombas_Cercanas(i, j)==0){
						cout<<" ";
					}
					else{
						cout<<Bombas_Cercanas(i,j);
					}
				}
			}
			cout<<"| ";
		}
		cout<<endl;
	}
}
void CampoMinas::Tablero_Final_Partida(){
	if(Victoria() || Mina_explosionada()){
		cout<<"   ";
		for(int i=0;i<Get_Columnas();i++){
			if(i<10) cout<<"  "<<i;
			else cout<<" "<<i;
		}
		cout<<endl<<"   ";
		for(int i=0;i<Get_Columnas();i++){
			cout<<"---";
			
		}
		cout<<"-"<<endl;
		for(int i=0;i<Get_Filas();i++){
			if(i<10) cout<<i<<"  | ";
			else cout<<i<<" | ";
			for(int j=0;j<Get_Columnas();j++){
				if(m.Get_Elemento(i,j).Bomba){
					cout<<"X";
				}
				else{
					if(Bombas_Cercanas(i,j)==0){
						cout<<" ";
					}
					else{
						cout<<Bombas_Cercanas(i,j);
					}
				}
				cout<<"| ";
			}
			cout<<endl;
		}
	}
	else{
		cout<<"No hagas trampa.\n";
	}
}
