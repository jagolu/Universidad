#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

class Barquitos{
private:
	int **m;
	int f, c;
public:
	Barquitos(const int& filas, const int& columnas){
		f=filas;
		c=columnas;
		m=new int*[f];
		for(int i=0;i<f;i++){
			m[i]=new int[c];
		}
		for(int i=0;i<f;i++){
			for(int j=0;j<c;j++){
				m[i][j]=9;
			}
		}
	}
	~Barquitos(){
		for(int i=0;i<f;i++){
			delete [] m[i];
		}
		delete [] m;
	}
	Barquitos(const Barquitos& b){
		f=b.f;
		c=b.c;
		m=new int*[f];
		for(int i=0;i<f;i++){
			m[i]=new int[c];
		}
		for(int i=0;i<f;i++){
			for(int j=0;j<c;j++){
				m[i][j]=b.m[i][j];
			}
		}
	}
	Barquitos& operator=(const Barquitos& b){
		if(&b!=this){
			for(int i=0;i<f;i++){
				delete [] this->m[i];
			}
			delete [] this->m;
			this->f=b.f;
			this->c=b.c;
			this->m=new int*[f];
			for(int i=0;i<f;i++){
				this->m[i]=new int[c];
			}
			for(int i=0;i<f;i++){
				for(int j=0;j<c;j++){
					this->m[i][j]=b.m[i][j];
				}
			}
		}
		return *this;
	}
	int aleatorio(const int& max){
		return rand()%max+1;
	}
	bool SePuedeColocar(const char& fila, const int& columna, const int& dimensiones, const char& direccion){
		if(fila>'a' && 'z'<fila){
			return false;
		}
		else if(columna<1){
			return false;
		}
		else if(dimensiones<=0 || 9<=dimensiones){
			return false;
		}
		else if(direccion!='h' && direccion!='v'){
			return false;
		}
		else{
			int ff=fila-'a';
			if(direccion=='h'){
				if((columna+dimensiones)<c){
					bool se_puede=true;
					for(int i=0;i<dimensiones;i++){
						if(m[ff][columna+i]!=9) se_puede=false;
					}
					return se_puede;
				}
				else return false;
			}
			else{
				if((ff+dimensiones)<f){
					bool se_puede=true;
					for(int i=0;i<dimensiones;i++){
						if(m[ff+i][columna]!=9) se_puede=false;
					}
					return se_puede;
				}
				else return false;
			}
		}
	}
	void Insertar(int tamanio){
		bool insertar=false;
		char fila;
		int columna;
		char direccion;
		while(!insertar){
			fila=aleatorio(f)+'a';
			columna=aleatorio(c);
			if(aleatorio(10)%2==0) direccion='v';
			else direccion='h';
			if(SePuedeColocar(fila, columna,  tamanio, direccion)) insertar=true;
		
		}
		cout<<"salio\n";
		int ff=fila-'a';
		cout<<ff<<" "<<columna<<" "<<direccion<<endl;
		if(direccion=='h'){
			for(int i=0;i<tamanio;i++){
				m[ff][columna+i]=tamanio;
			}
		}
		else{
			for(int i=0;i<tamanio;i++){
				m[ff+i][columna]=tamanio;
			}
		}
	}
	friend ostream& operator<<(ostream& os, const Barquitos& b);
	bool Leer(const char nombre[]){
		ifstream is(nombre,ios::in|ios::binary);
		char a[100];
		is.getline(a,100);
		if(strcmp(a,"MP-BARQ-V1.0")!=0) return false;
		else{
			is>>f>>c;
			int cc[f*c+1];
			char aaa[1];
			is.read(reinterpret_cast<char*>(aaa),sizeof(char));
			is.read(reinterpret_cast<char*>(cc),sizeof(int)*f*c);
			for(int i=0;i<f;i++){
				for(int j=0;j<c;j++){
					m[i][j]=cc[(c*i)+j];
				}
			}
		}
		return is;
	}
	bool Escribir(const char nombre[]){
		ofstream os(nombre, ios::out|ios::binary);
		os<<"MP-BARQ-V1.0\n";
		os<<f<<" "<<c<<endl;
		int datos[f*c];
		int l=0;
		for(int i=0;i<f;i++){
			for(int j=0;j<c;j++){
				datos[l]=m[i][j];
				l++;
			}
		}
		os.write(reinterpret_cast<const char*>(datos),sizeof(int)*l);
		return os;
	}
		
		
		
};
ostream& operator<<(ostream& os, const Barquitos& b){
	for(int i=0;i<b.f;i++){
		for(int j=0;j<b.c;j++){
			os<<b.m[i][j]<<" ";
		}
		cout<<endl;
	}
	return os;
}
int main(){
	int f, c;
	cout<<"Introduzca las filas y columnas: ";
	cin>>f>>c;
	Barquitos b(f,c);
	cout<<b<<endl;
	int t;
	cout<<"Diga el tamanio de dos barcos: ";
	for(int i=0;i<2;i++){
		cin>>t;
		b.Insertar(t);
	}
	cout<<b<<endl;
	cin.ignore();
	cout<<"Introduzca el fichero donde guardarlo: ";
	char cc[100];
	cin.getline(cc,100);
	b.Escribir(cc);
	Barquitos q(5,5);
	cout<<endl;
	if(b.Leer(cc)){
		q=b;
		cout<<q<<endl;
	}
	else cout<<"olala\n";
	
}
		
		
		
		
		
		
		
		
		
		
		
		
	
		
