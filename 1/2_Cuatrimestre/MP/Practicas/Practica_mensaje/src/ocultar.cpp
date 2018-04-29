#include <iostream>
#include "imagenES.h"
#include "codificar.h"
using namespace std;
int main(){
	const int MAXBUFFER= 1000000;
	const int MAXNOMBRE= 100;
	char nombre_imagen[MAXNOMBRE]={'.','/','i','m','a','g','e','n','e','s','/'};
	char aux[MAXNOMBRE], aux2[MAXNOMBRE];
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
	char imagen_salida[MAXNOMBRE]={'.','/','i','m','a','g','e','n','e','s','/'};
	cout<<"Introduzca la imagen de salida: ";
	cin.getline(aux2,MAXNOMBRE);
	i=0;
	while(aux2[i]!='\0'){
		i++;
	}
	for(int j=0;j<=i;j++){
		imagen_salida[11+j]=aux2[j];
	}
	la_imagen=LeerTipoImagen(nombre_imagen, f, c);
	
	while(imagen_salida[i]!='\0'){
		i++;
	}
	if(la_imagen==IMG_DESCONOCIDO){
		cout<<"No se reconoce el formato de la imagen\n";
	}
	else{
		bool leer, escribir, ocultado;
		if(la_imagen==IMG_PGM){
			imagen_salida[i]='.';
			imagen_salida[i+1]='p';
			imagen_salida[i+2]='g';
			imagen_salida[i+3]='m';
			imagen_salida[i+4]='\0';
			leer=LeerImagenPGM (nombre_imagen, f, c, buffer);
			if(leer){
				char frase[100];
				cout<<"Introduzca la frase:\n";
				cin.getline(frase,100);
				while(frase[i]!='\0'){
					i++;
				}
				ocultado=Ocultar(buffer,frase,f,c);
				if(ocultado){
					cout<<"Ocultado...\n";
					escribir=EscribirImagenPGM (imagen_salida, buffer, f, c);
					if(escribir){
						cout<<"Escrito, leido y ocultado con exito\n";
					}
					else{
						cout<<"Fallo en la escritura\n";
					}
				}
				else{
					cout<<"Error al ocultar\n";
				}
			}		
			else{
				cout<<"Mensaje demasiado grande para ocultar\n";
			}
		}
		else{
			imagen_salida[i]='.';
			imagen_salida[i+1]='p';
			imagen_salida[i+2]='p';
			imagen_salida[i+3]='m';
			imagen_salida[i+4]='\0';
			leer=LeerImagenPPM (nombre_imagen, f, c, buffer);
			if(leer){	
				char frase[100];
				cout<<"Introduzca la frase:\n";
				cin.getline(frase,100);
				while(frase[i]!='\0'){
					i++;
				}
				ocultado=Ocultar(buffer,frase,f,c);
				if(ocultado){
					cout<<"Ocultando...\n";
					escribir=EscribirImagenPPM (imagen_salida, buffer, f, c);
					if(escribir){
						cout<<"Escrito, leido y ocultado con exito\n";
					}
					else{
						cout<<"Fallo en la escritura\n";
					}
				}
				else{
					cout<<"Error al ocultar\n";
				}
			}
			else{
				cout<<"Fallo en la lectura\n";
			}
		}
	}
}
