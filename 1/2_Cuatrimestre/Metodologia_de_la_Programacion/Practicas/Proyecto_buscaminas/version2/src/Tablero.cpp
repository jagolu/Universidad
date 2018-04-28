#include <iostream>
#include <assert.h>
#include <fstream>
#include "Tablero.h"
using namespace std;
Tablero::Tablero(const int& f, const int& c){
	filas=f;
	columnas=c;
	m=new Casilla[f*c];
}
Tablero::Tablero(const Tablero& t){
	filas=t.filas;
	columnas=t.columnas;
	m=new Casilla [t.filas*t.columnas+1];
	for(int i=0;i<t.filas;i++){
		for(int j=0;j<t.columnas;j++){
			m[(t.columnas*i)+j]=t.Get_Elemento(i,j);
		}
	}
}
Tablero::~Tablero(){
	delete [] m;
}
Tablero& Tablero::operator=(const Tablero& t){
	if(this!=&t){
		delete [] m;
		this->filas=t.filas;
		this->columnas=t.columnas;
		this->m=new Casilla[this->filas*this->columnas+1];
		for(int i=0;i<t.filas;i++){
			for(int j=0;j<t.columnas;j++){
				this->m[(t.columnas*i)+j]=t.Get_Elemento(i,j);
			}
		}
	}
	return *this;
}
void Tablero::operator()(Casilla& c1, const Casilla& c2){
	c1.Bomba=c2.Bomba;
	c1.Abierta=c2.Abierta;
	c1.Marcada=c2.Marcada;
}
Casilla& Tablero::operator()(const int& f, const int& c)const{
	return m[(f*columnas)+c];
}
int Tablero::Get_Filas()const{
	return filas;
}
int Tablero::Get_Columnas()const{
	return columnas;
}

Casilla& Tablero::Get_Elemento(const int& f, const int& c)const{
	assert(f>=0 && f<filas && c>=0 && c<columnas);
	return m[(f*columnas)+c];	
}
void Tablero::Set_Elemento(const int& f, const int& c, const Casilla& p){
	assert(f>=0 && f<filas && c>=0 && c<columnas);
	m[(f*columnas)+c]=p;
}
bool Tablero::Escribir(std::ostream& fs, const Casilla& C){
	if(C.Bomba==false){
		if(C.Abierta==false){
			if(C.Marcada==false){
				fs<<0<<" ";
			}
			else{
				fs<<1<<" ";
			}
		}
		else{
			if(C.Marcada==false){
				fs<<2<<" ";
			}
			else{
				fs<<3<<" ";
			}
		}
	}
	else {
		if(C.Abierta==false){
			if(C.Marcada==false){
				fs<<4<<" ";
			}
			else{
				fs<<5<<" ";
			}
		}
		else{
			if(C.Marcada==false){
				fs<<6<<" ";
			}
			else{
				fs<<7<<" ";
			}
		}
	}
	return fs;
}
bool Tablero::Leer(std::istream& fs, Casilla& C){
	int a;
	fs>>a;
	bool leido=false;
	if(a==0){
		C.Bomba=false;
		C.Abierta=false;
		C.Marcada=false;
		leido=true;
	}
	else if(a==1){
		C.Bomba=false;
		C.Abierta=false;
		C.Marcada=true;
		leido=true;
	}
	else if(a==2){
		C.Bomba=false;
		C.Abierta=true;
		C.Marcada=false;
		leido=true;
	}
	else if(a==3){
		C.Bomba=false;
		C.Abierta=true;
		C.Marcada=true;
		leido=true;
	}
	else if(a==4){
		C.Bomba=true;
		C.Abierta=false;
		C.Marcada=false;
		leido=true;
	}
	else if(a==5){
		C.Bomba=true;
		C.Abierta=false;
		C.Marcada=true;
		leido=true;
	}
	else if(a==6){
		C.Bomba=true;
		C.Abierta=true;
		C.Marcada=false;
		leido=true;
	}
	else if(a==7){
		C.Bomba=true;
		C.Abierta=true;
		C.Marcada=true;
		leido=true;
	}
	if(leido) return fs;
	else return false;
}
