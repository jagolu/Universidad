/*El método RLE (Run Length Encoding) codifica una secuencia de datos formada por
series de valores idénticos consecutivos como una secuencia de parejas de números
(valor de la secuencia y número de veces que se repite). Esta codificación es un
mecanismo de compresión de datos (zip) sin pérdidas. Se aplica, por ejemplo, para
comprimir los ficheros de imágenes en las que hay zonas con los mismos datos (fondo
blanco, por ejemplo). Realizar un programa que lea una secuencia de números
naturales terminada con un número negativo y la codifique mediante el método RLE.*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int uno=0, dos=0, tres=0, cuatro=0, cinco=0, seis=0, siete=0, ocho=0, nueve=0, cero=0, cifra, i, numero;

		cout<<"Introduce un numero entero de una cifra: ";
		cin>>cifra;
		numero=cifra;
		i=10;
		while(cifra>=1){ /*Aqui vamos sacando las cifras  y vamos guardando cada cifra en un contador expecifico para cada cifra*/
			numero=cifra%i;
			if(0<=numero && numero<=9){
				if(numero==0){
					cero=cero+1;
				}
				else{
					if(numero==1){
						uno=uno+1;
					}
					else{
						if(numero==2){
							dos=dos+1;
						}
						else{
							if(numero==3){
								tres=tres+1;
							}
							else{
								if(numero==4){
									cuatro=cuatro+1;
								}
								else{
									if(numero==5){
										cinco=cinco+1;
									}
									else{
										if(numero==6){
											seis=seis+1;
										}
										else{
											if(numero==7){
												siete=siete+1;
											}
											else{
												if(numero==8){
													ocho=ocho+1;
												}
												else{
													nueve=nueve+1;
												}
											}
										}
									}
								}
							}	
						}
					}
				}
			}
			cifra=cifra/10;
		} 
		/*Despues mostraremos solo los contadores en los que haya mas de 0*/
		if(cero>0){
			cout<<"0"<<cero;
		}
		if(uno>0){
			cout<<"1"<<uno;
		}
		if(dos>0){
			cout<<"2"<<dos;
		}
		if(tres>0){
			cout<<"3"<<tres;
		}
		if(cuatro>0){
			cout<<"4"<<cuatro;
		}
		if(cinco>0){
			cout<<"5"<<cinco;
		}
		
		if(seis>0){
			cout<<"6"<<seis;
		}
		if(siete>0){
			cout<<"7"<<siete;
		}
		if(ocho>0){
			cout<<"8"<<ocho;
		}
		if(nueve>0){
			cout<<"9"<<nueve;
		}
		cout<<"\n";
	
	system("pause");
}
			
