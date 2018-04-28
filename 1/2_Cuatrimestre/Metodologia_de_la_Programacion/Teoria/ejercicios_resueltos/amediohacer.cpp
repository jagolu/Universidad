#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

class Matriz{
private:
	int nfilas;
	int *ncolumnas;
	double **datos;
public:
	Matriz(){
		nfilas=0;
		ncolumnas=0;
		datos=0;
	}
	~Matriz(){
		for(int i=0;i<nfilas;i++){
			delete [] datos[i];
		}
		delete [] datos;
		delete [] ncolumnas;
	}
	Matriz(const Matriz& m){
		nfilas=m.nfilas;
		ncolumnas=new int[nfilas];
		datos=new double*[nfilas];
		for(int i=0;i<nfilas;i++){
			datos[i]=new double[ncolumnas[i]];
			for(int j=0;j<ncolumnas[i];j++){
				datos[i][j]=m.datos[i][j];
			}
		}	
	}
	Matriz& operator=(const Matriz& m){
		if(&m!=this){
			for(int i=0;i<this->nfilas;i++){
				delete [] this->datos[i];
			}
			delete [] this->datos;
			delete [] this->ncolumnas;
			this->nfilas=m.nfilas;
			this->ncolumnas=new int[this->nfilas];
			this->datos=new double*[this->nfilas];
			for(int i=0;i<this->nfilas;i++){
				this->datos[i]=new double[this->ncolumnas[i]];
				for(int j=0;j<this->ncolumnas[i];j++){
					this->datos[i][j]=m.datos[i][j];
				}
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& os, const Matriz& m);
	friend istream& operator>>(istream& is, Matriz& m);
	double Get(const int& f, const int& c){
		return datos[f][c];
	}
	void Set(const int& f, const int&c, double dato){
		datos[f][c]=dato;
	}
	Matriz Vflip(){
		Matriz m;
		m.nfilas=m.nfilas;
		m.ncolumnas=new int[nfilas];
		m.datos=new double*[nfilas];
		for(int i=0;i<nfilas;i++){
			m.ncolumnas[nfilas-1-i]=ncolumnas[i];
		}
		for(int i=0;i<nfilas;i++){
			m.datos[i]=new double[m.ncolumnas[i]];
			for(int j=0;j<ncolumnas[i];j++){
				m.datos[i][j]=datos[nfilas-1-i][j];
			}
		}	
		return m;
	}
	bool Escribir(const char nombre[]){
		ofstream os(nombre, ios::out|ios::binary);
		os<<"MP\n";
		os<<nfilas<<endl;
		os<<"#Comentario\n";
		for(int i=0;i<nfilas;i++){
			double a[ncolumnas[i]];
			for(int j=0;j<ncolumnas[i];j++){
				a[i]=datos[i][j];
			}
			os.write(reinterpret_cast<char*>(&ncolumnas[i]),sizeof(int));
			os.write(reinterpret_cast<const char*>(a),sizeof(double)*ncolumnas[i]);
		}
		return os;
	}
	bool Leer(const char nombre[]){
		ifstream is(nombre, ios::in|ios::binary);
		char a[100];
		is.getline(a,100);
		if(strcmp(a,"MP")!=0) return false;
		else{
			is>>nlineas;
			is.getline(a,100);
			is.read(reinterpret_cast<char*>(a),sizeof(char));
			
			for(int i=0;i<nfilas;i++){
				
		
		
};
ostream& operator<<(ostream& os, const Matriz& m){
	os<<m.nfilas<<endl;
	for(int i=0;i<nfilas;i++){
		os<<m.ncolumnas[i]<<" ";
	}
	for(int i=0;i<nfilas;i++){
		for(int j=0;j<m.ncolumnas[i];j++){
			os<<m.datos[i][j]<<" ";
		}
		cout<<endl;
	}
	return os;
}		
istream& operator>>(istream& is, Matriz& m){
	is>>m.nfilas;
	for(int i=0;i<m.nfilas;i++){
		is>>m.ncolumnas[i];
	}
	for(int i=0;i<m.nfilas;i++){
		for(int j=0;j<m.ncolumnas[i];j++){
			is>>m.datos[i][j];
		}
	}
	return is;
}		
		
		
		
		
		
		
		
		
		
		
		
	
	
	
	
	
	
	
	
