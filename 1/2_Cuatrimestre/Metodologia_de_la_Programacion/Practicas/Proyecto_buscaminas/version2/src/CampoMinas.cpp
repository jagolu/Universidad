#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <fstream>
#include <cstring>
#include "Tablero.h"
#include "CampoMinas.h"
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
CampoMinas::CampoMinas(const int& f, const int& c, const int& num_minas):m(f,c) {
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
	Explosion=false;
}

bool CampoMinas::Mina_explosionada(){
	return Explosion;
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
	else if(m(f,c).Abierta){
		marcado=false;
	}
	else{
		Casilla q=m(f,c);
		if(q.Marcada){
			q.Marcada=false;
		}
		else{
			q.Marcada=true;
		}
		m(m(f,c),q);
		marcado=true;
	}
	return marcado;
}
struct Casillita{
	int f, c;
	Casillita *sig;
};
void Add(Casillita*& l,int fila, int columna){
	Casillita *r;
	r=new Casillita;
	r->f=fila;
	r->c=columna;
	r->sig=l;
	l=r;
}
void Elimina(Casillita*& l){
	Casillita *r;
	r=l->sig;
	delete l;
	l=r;
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
	else if(m.Get_Elemento(f,c).Bomba){
		Casilla q=m.Get_Elemento(f,c);
		q.Abierta=true;
		m.Set_Elemento(f,c,q);
		abierto=true;
		Explosion=true;
	}
	else{
		Casillita *Pend=0;	
		Add(Pend, f, c);
		while(Pend!=0){
			int ff=Pend->f;
			int cc=Pend->c;
			Elimina(Pend);
			if(m.Get_Elemento(ff,cc).Abierta==false && m.Get_Elemento(ff,cc).Marcada==false && ff>=0 && cc>=0 && ff<Get_Filas() && cc<Get_Columnas() && m.Get_Elemento(ff,cc).Bomba==false){
				if(Bombas_Cercanas(ff,cc)==0){
					for(int i=ff-1;i<=ff+1;i++){
						for(int j=cc-1;j<=cc+1;j++){
							if(i>=0 && i<m.Get_Filas() && j>=0 && j<m.Get_Columnas()){
								Add(Pend,i,j);
							}
						}
					}
				}
					Casilla q=m.Get_Elemento(ff,cc);
					q.Abierta=true;
					m.Set_Elemento(ff,cc,q);
					abierto=true;
			}
		}
	}	
	return abierto;
}
void CampoMinas::PrettyPrint(std::ostream& os){
	os<<"   ";
	for(int i=0;i<Get_Columnas();i++){
		if(i<10) os<<"  "<<i;
		else os<<" "<<i;
	}
	os<<endl<<"   ";
	for(int i=0;i<Get_Columnas();i++){
		if(Get_Filas()<10) os<<"---";
		else os<<"---";
	}
	os<<"-"<<endl;
	for(int i=0;i<Get_Filas();i++){
		if(i<10) os<<i<<"  | ";
		else os<<i<<" | ";
		for(int j=0;j<Get_Columnas();j++){
			if(m.Get_Elemento(i,j).Abierta==false){
				if(m.Get_Elemento(i,j).Marcada){
					os<<"?";
				}
				else{
					os<<"*";
				}
			}
			else{
				if(m.Get_Elemento(i,j).Bomba==false){
					if(Bombas_Cercanas(i, j)==0){
						os<<" ";
					}
					else{
						os<<Bombas_Cercanas(i,j);
					}
				}
			}
			os<<"| ";
		}
		os<<endl;
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
bool CampoMinas::Escribir(std::ostream& fs,Tablero& P){
	fs<<"#MP−BUSCAMINAS−V1"<<endl;
	fs<<P.Get_Filas()<<" "<<P.Get_Columnas()<<endl;
	for(int i=0;i<P.Get_Filas();i++){
		for(int j=0;j<P.Get_Columnas();j++){
			P.Escribir(fs,P.Get_Elemento(i,j));
		}
		fs<<endl;
	}
	return fs;
}
bool CampoMinas::Leer(std::istream& fs, Tablero& P){
	int ff, cc;
	char cad[100];
	fs.getline(cad,100);
	bool leido=true;
	if(strcmp(cad,"#MP−BUSCAMINAS−V1")==0){
		fs>>ff;
		fs>>cc;	
		if(ff>=4 && cc>=4 && ff<=20 && cc<=20){
			Tablero a(ff,cc);
			P=a;
			for(int i=0;i<ff;i++){
				for(int j=0;j<cc;j++){	
					if(P.Leer(fs,P.Get_Elemento(i,j)));
					else leido=false;
				}
			}
			if(leido){
				int cuenta=0;
				for(int i=0;i<P.Get_Filas();i++){
					for(int j=0;j<P.Get_Columnas();j++){
						if(P.Get_Elemento(i,j).Bomba) cuenta++;
					}
				}
				if((ff*cc)/2>cuenta) return fs;
				else{
					cout<<"El numero de minas es superior a la mitad de casillas libres\n";
					return false;
				}
			}
			else{
				cout<<"El archivo no es una partida guardada de BuscaMinas o no existe\n";
				return false;
			}
		}
		else{
			cout<<"No se pueden cargar partidas con filas o columnas inferiores a 4 o superiores a 20\n";
			return false;
		}
	}
	else{
		cout<<"El archivo no es una partida guardada de BuscaMinas o no existe\n";
		return false;
	}
}
bool CampoMinas::Escribir(std::ostream& fs,CampoMinas& P){
	if(Escribir(fs,P.m)) return true;
	else return false;
}
bool CampoMinas::Leer(std::istream& fs,CampoMinas& P){
	if(Leer(fs,P.m)){
		P.Explosion=false;
		return fs;
	}
	else return false;
}
