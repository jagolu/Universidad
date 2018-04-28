#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class Menu{
private:
	char *titulo;
	char **opc;
	int nopc;
public:
	Menu(){
		titulo=new char[0];
		opc=new char*[0];
		nopc=0;
	}
	~Menu(){
		delete [] titulo;
		for(int i=0;i<nopc;i++){
			delete [] opc[i];
		}
		delete [] opc;
	}
	Menu(const Menu& m){
		titulo=new char[strlen(m.titulo)];
		for(int i=0;i<strlen(m.titulo);i++){
			titulo[i]=m.titulo[i];
		}
		nopc=m.nopc;
		opc=new char*[nopc];
		for(int i=0;i<nopc;i++){
			opc[i]=new char[strlen(m.opc[i])];
			for(int j=0;j<strlen(m.opc[i]);j++){
				opc[i][j]=m.opc[i][j];
			}
		}
	}
	Menu& operator=(const Menu& m){
		if(&m!=this){
			delete [] this->titulo;
			for(int i=0;i<this->nopc;i++){
				delete [] this->opc[i];
			}
			delete [] this->opc;
			this->titulo=new char[strlen(m.titulo)];
			for(int i=0;i<strlen(m.titulo);i++){
				this->titulo[i]=m.titulo[i];
			}
			this->nopc=m.nopc;
			this->opc=new char*[nopc];
			for(int i=0;i<this->nopc;i++){
				this->opc[i]=new char[strlen(m.opc[i])];
				for(int j=0;j<strlen(m.opc[i]);j++){
					this->opc[i][j]=m.opc[i][j];
				}
			}
		}
		return *this;
	}
	void SetTitulo(const char a[]){
		delete [] titulo;
		titulo=new char[strlen(a)];
		for(int i=0;i<strlen(a);i++){
			titulo[i]=a[i];
		}
	}
	int GetNumeroOpciones()const{
		return nopc;
	}
	void AddOpcion(const char nueva_opcion[]){
		char **op;
		op=new char*[nopc+1];
		for(int i=0;i<nopc;i++){
			op[i]=new char[strlen(opc[i])];
			for(int j=0;j<strlen(opc[i]);j++){
				op[i][j]=opc[i][j];
			}
		}
		for(int i=0;i<nopc;i++){
			delete [] opc[i];
		}
		delete [] opc;
		opc=op;
		opc[nopc]=new char[strlen(nueva_opcion)];
		for(int i=0;i<strlen(nueva_opcion);i++){
			opc[nopc][i]=nueva_opcion[i];
		}
		nopc++;
	}
	char *GetTitulo()const{
		return titulo;
	}
	char **GetOpc()const{
		return opc;
	}
};
ostream& operator<<(ostream& os, const Menu& m){
	for(int i=0;i<strlen(m.GetTitulo());i++){
		os<<m.GetTitulo()[i];
	}
	os<<endl;
	for(int i=0;i<m.GetNumeroOpciones();i++){
		os<<i<<"  ";
		for(int j=0;j<strlen(m.GetOpc()[i]);j++){
			os<<m.GetOpc()[i][j];
		}
		os<<endl;
	}
	return os;
}
Menu& operator>>(Menu& m, int& n){
	cout<<m;
	do{
		cout<<"Seleccione una opcion del menu: ";
		cin>>n;
		if(n<0 || n>=m.GetNumeroOpciones()) cout<<"Introduzca una opcion valida\n";
	}while(n<0 || n>=m.GetNumeroOpciones());
	return m;
}
int main(){
	Menu m;
	char a[100];
	cout<<"Introduzca el titulo: ";		
	cin.getline(a,100);
	m.SetTitulo(a);
	for(int i=0;i<3;i++){
		char b[100];
		cout<<"Introduzca la opcion "<<i<<": ";
		cin.getline(b,100);
		m.AddOpcion(b);
	}
	int aa;
	m>>aa;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
