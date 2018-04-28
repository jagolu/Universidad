#include <iostream>
#include <fstream>
#include <cstring>
#include "matriz_operaciones.h"
using namespace std;
bool Leer(std::istream& is, MatrizBit& m){
	bool inic=false;
	int f=0, c=0, r=0;
	char dato, mat[300];
	while (isspace(is.peek()) || is.peek()=='#') {
		if (is.peek()=='#')
			is.ignore(1024,'\n'); 
		else is.ignore();
	}
	dato=is.peek();
	if(dato!='X' && dato!='x' && dato!='.'){
		is>>f>>c;
		int dat;
		inic=Inicializar(m,f,c);
		if(inic){
			for(int i=0;i<f;i++){
				for(int j=0;j<c;j++){
					is>>dat;
					Set(m,i,j,dat);
				}
			}
		}
	}
	else{	
		char cad[100];
		is.getline(cad,100);
                c=strlen(cad);
                strcpy(mat,cad);
		f++;
		while(is.peek()=='X' || is.peek()=='x'|| is.peek()=='.'){
			is.getline(cad,100);
			strcat(mat,cad);
			f++;
		}
		r=1;
	}
	if(r!=0){
		int l=0;
		inic=Inicializar(m,f,c);
		for(int i=0;i<f;i++){
			for(int j=0;j<c;j++){
				bool t;
				if(mat[l]=='X' || mat[l]=='x') {
					t=1;
				}
				else if(mat[l]=='.') {
					t=0;
				}
				Set(m,i,j,t);
				l++;
			}
		}
	}
  return inic;
}
bool Escribir(std::ostream& os, const MatrizBit& m){
	os<<Filas(m)<<" "<<Columnas(m)<<endl;
	for(int i=0;i<Filas(m);i++){
		for(int j=0;j<Columnas(m);j++){
			os<<Get(m,i,j)<<" ";
		}
		os<<endl;
	}
	os<<endl;
  return os;
}
bool Leer(const char nombre[], MatrizBit& m){
	ifstream nom(nombre);
	bool a=Leer(nom,m);
	return a;
}
bool Escribir(const char nombre[], const MatrizBit& m){
	ofstream nom(nombre);
	bool a=Escribir(nom,m);
	return a;
}
void And(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2){
	if(Columnas(m1) == Columnas(m2) && Filas(m1)==Filas(m2)){
		bool inicializ=Inicializar(res,Filas(m1),Columnas(m1));
		if(inicializ){
			for(int i=0;i<Filas(m1);i++){
				for(int j=0;j<Columnas(m1);j++){
					bool v, a, b;
					a=Get(m1,i,j);
					b=Get(m2,i,j);
					v=a & b;
					Set(res,i,j,v);
				}
			}
		}
		else{
			cout<<"ERROR2\n";

		}
	}
	else{
		cout<<"ERROR1\n";
	}
}
void Or(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2){
	if(Columnas(m1) == Columnas(m2) && Filas(m1)==Filas(m2)){
		bool inicializ=Inicializar(res,Filas(m1),Columnas(m1));
		if(inicializ){
			for(int i=0;i<Filas(m1);i++){
				for(int j=0;j<Columnas(m1);j++){
					bool v, a, b;
					a=Get(m1,i,j);
					b=Get(m2,i,j);
					v=a | b;
					Set(res,i,j,v);
				}
			}
		}
		else{
			cout<<"ERROR2\n";

		}
	}
	else{
		cout<<"ERROR1\n";
	}
}
void Not(MatrizBit& res, const MatrizBit& m){
	bool inicia=Inicializar(res,Filas(m),Columnas(m));
	if(inicia){
		for(int i=0;i<Filas(m);i++){
			for(int j=0;j<Columnas(m);j++){
				bool v=Get(m,i,j);
				if(v==0){
					bool v1=1;
					Set(res,i,j,v1);
				}
				else{		
					bool v1=0;
					Set(res,i,j,v1);
				}
			}
		}
	}
	else{
		cout<<"ERROR\n";
	}
}		
void Traspuesta(MatrizBit& res, const MatrizBit& m){
	bool inicia=Inicializar(res,Columnas(m),Filas(m));
	if(inicia){
		for(int i=0;i<Filas(m);i++){
			for(int j=0;j<Columnas(m);j++){
				bool v=Get(m,i,j);
				Set(res,j,i,v);
			}
		}
	}
	else{
		cout<<"ERROR\n";
	}
}
