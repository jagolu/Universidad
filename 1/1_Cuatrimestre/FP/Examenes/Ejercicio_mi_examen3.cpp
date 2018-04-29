#include <iostream>
using namespace std;
class TablaRectangularReales{
private:
	static const int max=100;
	double matriz[max][max];
	int filas;
public:
	TablaRectangularReales(int dimension)
		:filas(dimension)
	{	}
	void aniade(int fila, int columna, double dato){
		matriz[fila][columna]=dato;
	}
	int fila_columna(){
		return filas;
	}
	double elemento(int fila, int columna){
		return matriz[fila][columna];
	}
	TablaRectangularReales PromedioRelativo(){
		TablaRectangularReales nueva_matriz(filas);
		for(int i=0;i<filas;i++){
			for(int j=0;j<filas;j++){
				if(i==j){
					nueva_matriz.aniade(i, j, matriz[i][j]);
				}
				if(j<i){
					nueva_matriz.aniade(i, j, matriz[i][j]);
				}
				if(j>i){
					double suma=0, contador=0;
					for(int i2=j;i2<filas;i2++){
						suma=suma+matriz[i][i2];
						contador++;
					}
					nueva_matriz.aniade(i, j, suma/contador);
				}
			}
		}
		return nueva_matriz;
	}
};
int main(){
	double a;
	int b;
	cout<<"Introduzca la dimension de la matriz: ";
	cin>>b;
	TablaRectangularReales objeto(b);
	for(int i=0;i<b;i++){
		for(int j=0;j<b;j++){
			cout<<"Elemento "<<i+1<<", "<<j+1<<": ";
			cin>>a;
			objeto.aniade(i, j, a);
		}
	}
	for(int i=0;i<b;i++){
		for(int j=0;j<b;j++){
			cout<<objeto.elemento(i, j)<<" ";
		}
		cout<<endl;
	}
	cout<<"Nueva matriz:\n";
	for(int i=0;i<b;i++){
		for(int j=0;j<b;j++){
			cout<<objeto.PromedioRelativo().elemento(i, j)<<" ";
		}
		cout<<endl;
	}
	system("pause");
}
