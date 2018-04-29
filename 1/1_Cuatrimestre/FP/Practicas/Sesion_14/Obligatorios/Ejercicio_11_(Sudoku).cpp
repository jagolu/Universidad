/*Realizar un programa que lea todos los elementos de un sudoku y determine si está
resuelto o no.
Implemente la solución con una clase Sudoku con un dato miembro matriz de doble
corchete y añada un programa principal de prueba.*/
#include <iostream>

using namespace std;

class sudoku{
private:
	static const int filas=9;
	static const int columnas=9;
	int matriz[filas][columnas];
public:
	void aniade(int dato, int fila, int columna){
		if(1<=dato && dato<=9){
			matriz[fila][columna]=dato;
		}
		else{
			cout<<"En un sudoku los numero van de 1 a 9\n";
		}
	}
	void mostrar_sudoku(){
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout<<matriz[i][j]<<" ";
				if(((j+1)%3)==0){
					cout<<" ";
				}
			}
			cout<<endl;
			if(((i+1)%3)==0){
				cout<<endl;
			}
		}
	}
	bool comprobacion_filas(){
		bool comprobacion;
		comprobacion=true;
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				int a;
				a=matriz[i][j];
				for(int k=j+1;k<9;k++){
					int b;
					b=matriz[i][k];
					if(a==b){
						comprobacion=false;
					}
				}
			}
		}
		return comprobacion;
	}
	bool comprobacion_columnas(){
		bool comprobacion;
		comprobacion=true;
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				int a;
				a=matriz[j][i];
				for(int k=j+1;k<9;k++){
					int b;
					b=matriz[k][i];
					if(a==b){
						comprobacion=false;
					}
				}
			}
		}
		return comprobacion;
	}
	bool comprobacion_region(){
		bool comprobacion=true;
		for(int i=0;i<6;i=i+3){
			for(int j=0;j<6;j=j+3){
				int a, b;
				for(int i2=i;i2<(i+3);i2++){
					for(int j2=j;j2<(j+3);j2++){
						a=matriz[i2][j2];
						for(int i3=i2;i3<(i+3);i3++){
							for(int j3=j2+1;j3<(j+3);j3++){
								b=matriz[i3][j3];
								if(a==b){
									comprobacion=false;
								}
							}
						}
					}
				}
			}
		}
		return comprobacion;
	}
	void esta_bien(){
		bool filas, columnas, region;
		filas=comprobacion_filas();
		columnas=comprobacion_columnas();
		region=comprobacion_region();
		if(filas==false || columnas==false || region==false){
			cout<<"El sudoku no esta bien\n";
		}
		else{
			cout<<"El sudoku esta bien\n";
		}
	}
};
int main(){
	int n;
	sudoku objeto;
	cout<<"Introduzca los elementos del sudoku..\n";
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<"Fila "<<i<<" columna "<<j<<" : ";
			cin>>n;
			objeto.aniade(n, i, j);
		}
	}
	cout<<endl<<endl;
	objeto.mostrar_sudoku();
	cout<<endl<<endl;
	objeto.esta_bien();
	system("pause");
}
	
