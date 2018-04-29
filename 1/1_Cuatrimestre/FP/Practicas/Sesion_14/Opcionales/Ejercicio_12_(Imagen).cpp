/*Implemente un método para que dada una imagen, devuelva otra imagen corregida.*/
#include <iostream>

using namespace std;

class imagen{
private:
	static const int maximo_filas=100;
	static const int maximo_columnas=100;
	int matriz[maximo_filas][maximo_columnas];
	const int filas;
	const int columnas;
public:
	imagen(int fil, int colum)
		:filas(fil),
		columnas(colum)
	{	}
	int filas_usadas(){
		return filas;
	}
	int columnas_usadas(){
		return columnas;
	}
	void aniade(int dato, int fila, int columna){
		if(dato<=255){
			matriz[fila][columna]=dato;
		}
	}
	void mostrar_matriz(){
		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				cout<<matriz[i][j]<<"    ";
			}
			cout<<endl;
		}
	}
	imagen corregir_imagen(){
		imagen nueva_imagen(filas, columnas);
		for(int i=1;i<filas-1;i++){
			for(int j=1;j<columnas-1;j++){
				int a;
				a=matriz[i][j];
				if(a>=0){
					nueva_imagen.aniade(a, i, j);
				}
				else{
					double contador=0, suma_numeros=0, b;
					double div;
					for(int ii=-1;ii<=1;ii++){
						for(int jj=-1;jj<=1;jj++){
							b=matriz[i+ii][j+jj];
							if(b>0){
								contador++;
								suma_numeros=suma_numeros+b;
								div=contador;
							}
						}
					}
					if(contador=!0){
						nueva_imagen.aniade((suma_numeros/div), i, j);
					}
					else{
						nueva_imagen.aniade(0, i, j);
					}
				}
			}
		}
		for(int i=0;i<columnas;i++){
			nueva_imagen.aniade(matriz[0][i], 0 , i);
		}
		for(int i=0;i<columnas;i++){
			nueva_imagen.aniade(matriz[filas-1][i], (filas-1), i);
		}
		for(int i=0;i<filas;i++){
			nueva_imagen.aniade(matriz[i][0], i, 0);
		}
		for(int i=0;i<filas;i++){
			nueva_imagen.aniade(matriz[i][columnas-1], i, (columnas-1));
		}
		return nueva_imagen;
	}
};
int main(){
	int n1, n2, dato;
	
	cout<<"Introduzca el numero de filas y columnas que tendra la matriz de la imagen: \n";
	cin>>n1;
	cin>>n2;
	imagen objeto(n1, n2);
	for(n1=0;n1<objeto.filas_usadas();n1++){
		for(n2=0;n2<objeto.columnas_usadas();n2++){
			cout<<"Elemento ("<<n1<<", "<<n2<<"): ";
			cin>>dato;
			objeto.aniade(dato, n1, n2);
		}
	}
	cout<<endl<<endl;
	objeto.mostrar_matriz();
	cout<<endl<<endl;
	cout<<"Calculando imagen corregida...\nLa imagen corregida es:\n\n";
	objeto.corregir_imagen().mostrar_matriz();
	system("pause");	
}
