#include <iostream>
#include <fstream>
#include <cstring>
#include "matriz_bit.h"
#include "matriz_operaciones.h"
using namespace std;
int main(int argc, char* argv[]){
	if(argc>=1){
		if(strcmp(argv[1],"NOT")==0){
			MatrizBit m1, res;
			if(argc==3){
				if(Leer(argv[2],m1)){
					Not(res,m1);
					if(Escribir(cout,res));
					else cout<<"Error de escritura\n";
				}
				else{
					cout<<"Error al leer\n";
				}
			}
			else if(argc==2){
				if(Leer(cin,m1)){
					Not(res,m1);
					if(Escribir(cout,res));
					else cout<<"Error de escritura\n";
				}
				else{
					cout<<"Error al leer\n";
				}
			}
			else{
				cout<<"Error de argumentos\n";
			}
		}
		else if(strcmp(argv[1],"TRS")==0 ){	
			MatrizBit m1, res;
			if(argc==3){
				if(Leer(argv[2],m1)){
					Traspuesta(res,m1);
					if(Escribir(cout,res));
					else cout<<"Error de escritura\n";
				}
				else{
					cout<<"Error al leer\n";
				}
			}
			else if(argc==2){
				if(Leer(cin,m1)){
					Traspuesta(res,m1);
					if(Escribir(cout,res));
					else cout<<"Error de escritura\n";
				}
				else{
					cout<<"Error al leer\n";
				}
			}
			else{
				cout<<"Error de argumentos\n";
			}
		}
		else if(strcmp(argv[1],"AND")==0 ){
			MatrizBit m1, m2, res;
			if(argc==4){
				if(Leer(argv[2],m1)){
					if(Leer(argv[3],m2)){
						And(res,m1,m2);
						if(Escribir(cout,res));
						else cout<<"Error de escritura\n";
					}
					else{
						cout<<"Error al leer\n";
					}
				}
				else{
					cout<<"Error al leer\n";
				}
			}
			else if(argc==3){
				if(Leer(argv[2],m1)){
					if(Leer(cin,m2)){
						And(res,m1,m2);
						if(Escribir(cout,res));
						else cout<<"Error de escritura\n";
					}
				}
			}
			else if(argc==2){
				if(Leer(cin,m1)){
					if(Leer(cin,m2)){
						And(res,m1,m2);
						if(Escribir(cout,res));
						else cout<<"Error de escritura\n";
					}
				}
			}
			else{
				cout<<"Error de argumentos\n";
			}
		}
		else if(strcmp(argv[1],"OR")==0){
			MatrizBit m1, m2, res;
			if(argc==4){
				if(Leer(argv[2],m1)){
					if(Leer(argv[3],m2)){
						Or(res,m1,m2);
						if(Escribir(cout,res));
						else cout<<"Error de escritura\n";
					}
					else{
						cout<<"Error al leer\n";
					}
				}
				else{
					cout<<"Error al leer\n";
				}
			}
			else if(argc==3){
				if(Leer(argv[2],m1)){
					if(Leer(cin,m2)){
						Or(res,m1,m2);
						if(Escribir(cout,res));
						else cout<<"Error de escritura\n";
					}
				}
			}
			else if(argc==2){
				if(Leer(cin,m1)){
					if(Leer(cin,m2)){
						Or(res,m1,m2);
						if(Escribir(cout,res));
						else cout<<"Error de escritura\n";
					}
				}
			}
			else{
				cout<<"Error de argumentos\n";
			}
		}
		else {
			cout<<"No se puede realizar la operacion\n";
		}
	}
	else{
		cout<<"Argumentos insuficientes\n";
	}
}

