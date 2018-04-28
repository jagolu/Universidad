#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

class Matriz{
private:
	int filas;
	int *ncolumnas;
	double **datos;
public:
	Matriz(){
		filas=0;
		ncolumnas=new int[0];
		datos=new double* [0];
	}
	~Matriz(){
		delete [] ncolumnas;
		for(int i=0;i<filas;i++){
			delete [] datos[i];
		}
		delete [] datos;
	}
	Matriz(const Matriz& m){
		filas=m.filas;
		ncolumnas=new int[filas];
		for(int i=0;i<filas;i++){
			ncolumnas[i]=m.ncolumnas[i];
		}
		datos=new double*[filas];
		for(int i=0;i<filas;i++){
			datos[i]=new double[m.ncolumnas[i]];
			for(int j=0;j<m.ncolumnas[i];j++){
				datos[i][j]=m.datos[i][j];
			}
		}
	}
	Matriz& operator=(Matriz& m){
		if(&m!=this){
			delete [] this->ncolumnas;
			for(int i=0;i<this->filas;i++){
				delete [] this->datos[i];
			}
			delete [] this->datos;
			this->filas=m.filas;
			this->ncolumnas=new int[this->filas];
			for(int i=0;i<this->filas;i++){
				this->ncolumnas[i]=m.ncolumnas[i];
			}
			this->datos=new double*[filas];
			for(int i=0;i<this->filas;i++){
				this->datos[i]=new double[m.ncolumnas[i]];
				for(int j=0;j<m.ncolumnas[i];j++){
					this->datos[i][j]=m.datos[i][j];
				}
			}
		}
		return *this;
	}
	ostream& operator<<(ostream& os){
		for(int i=0;i<filas;i++){
			for(int j=0;j<ncolumnas[i];i++){
				os<<datos[i][j];
			}
			cout<<endl;
		}
		return os;
	}
	istream& operator>>(istream& is){
		delete [] this->ncolumnas;
		for(int i=0;i<this->filas;i++){
			delete [] this->datos[i];
		}
		delete [] datos;
		filas=0;
		while(!is.eof()){
			char a[100];
			is.getline(a,100);
			filas++;
			
			
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
};
