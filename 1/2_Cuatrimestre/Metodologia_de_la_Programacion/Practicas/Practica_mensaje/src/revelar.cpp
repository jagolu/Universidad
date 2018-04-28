#include <iostream>
#include "imagenES.h"
#include "codificar.h"
using namespace std;
int main(){
	const int MAXBUFFER= 1000000;
	const int MAXNOMBRE= 100;
	char nombre_imagen[MAXNOMBRE]={'.','/','i','m','a','g','e','n','e','s','/'};
	char aux[100];
	unsigned char buffer[MAXBUFFER];
	int f, c;
	TipoImagen la_imagen;
	cout<<"Introduzca la imagen de entrada: ";
	cin.getline(aux,MAXNOMBRE);
	int i=0;
	while(aux[i]!='\0'){
		i++;
	}
	for(int j=0;j<=i;j++){
		nombre_imagen[11+j]=aux[j];
	}
	la_imagen=LeerTipoImagen(nombre_imagen, f, c);
	if(la_imagen==IMG_DESCONOCIDO){
		cout<<"No se reconoce el formato de la imagen\n";
	}
	else{
		bool leer, revelado;
		if(la_imagen==IMG_PGM){
			leer=LeerImagenPGM (nombre_imagen, f, c, buffer);
			if(leer){
				char frase[100];
				cout<<"Revelando....\n";
				revelado=Revelar(buffer,frase,MAXNOMBRE,MAXBUFFER);
				cout<<endl;
				if(revelado==false){
					cout<<"Error al revelar\n";
				}
			}
		}
		else{
			leer=LeerImagenPPM (nombre_imagen, f, c, buffer);
			if(leer){	
				char frase[100];
				cout<<"Revelando....\n";
				revelado=Revelar(buffer,frase,MAXNOMBRE,MAXBUFFER);		
				cout<<endl;
				if(revelado==false){
					cout<<"Error al revelar\n";
				}
			}
			else{
				cout<<"Fallo en la lectura\n";
			}
		}
	}
}
