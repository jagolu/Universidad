/*Construid un método que busque la fila de la matriz que
más se parezca a una secuencia de enteros, a la que llamaremos referencia.*/
#include <iostream>
#include <cmath>

using namespace std;

class SecuenciaEnteros{
private:
	static const int max=100;
	int vector[max];
	int total;
public:
	SecuenciaEnteros()
		:total(0){
	}
	int total_usados(){
		return total;
	}
	void aniade(int nuevo){
		if(total<max){
			vector[total]=nuevo;
			total++;
		}
	}
	int mostrar_elemento(int indice){
		return vector[indice];
	}
};
class MatrizRectangularEnteros{
private:
	static const int max_fil=100;
	static const int max_colum=100;
	int matriz[max_fil][max_colum];
	const int columnas;
	int filas;
public:
	int columna=0;
	MatrizRectangularEnteros(int colum)
		:columnas(colum),
		filas(0)
	{	}
	int columnas_utilizadas(){
		return columnas;
	}
	int filas_utilizadas(){
		return filas;
	}
	void aniade(int dato){
		matriz[filas][columna]=dato;
		columna++;
		if(columna==columnas){
			columna=0;
			filas++;
		}
	}
	int mostrar_elemento_matriz(int fila_a_mostrar, int columna_a_mostrar){
		return matriz[fila_a_mostrar][columna_a_mostrar];
	}
	void mostrar_matriz(){
		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				cout<<matriz[i][j]<<"  ";
			}
			cout<<endl;
		}
	}
	void comparar(SecuenciaEnteros filas_a_comparar, SecuenciaEnteros referencia){
		int sumatorio=0;
		int fila_mas_proxima, sumatorio_minimo;
		fila_mas_proxima=filas_a_comparar.mostrar_elemento(0);
		for(int i=0;i<columnas;i++){
			double a, b;
			a=matriz[filas_a_comparar.mostrar_elemento(0)][i];
			b=referencia.mostrar_elemento(i);
			sumatorio=sumatorio+(pow((a-b),2));
		}
		sumatorio=sqrt(sumatorio);
		sumatorio_minimo=sumatorio;
		sumatorio=0;
		for(int i=1;i<(filas_a_comparar.total_usados());i++){	
			int indice_fila;
			indice_fila=filas_a_comparar.mostrar_elemento(i);
			for(int j=0;j<columnas;j++){
				double a, b;
				matriz[indice_fila][j];
				referencia.mostrar_elemento(j);
				sumatorio=sumatorio+(pow((a-b),2));
			}
			sumatorio=sqrt(sumatorio);
			if(sumatorio_minimo>=sumatorio){
				sumatorio_minimo=sumatorio;
				fila_mas_proxima=indice_fila;
			}
			sumatorio=0;
		}
		cout<<"La fila que mas se aproxima es la fila de indice "<<fila_mas_proxima<<endl;
		for(int i=0;i<columnas;i++){
			cout<<matriz[fila_mas_proxima][i]<<" ";
		}
		cout<<endl;
	}
};

int main(){
	int n;
	cout<<"Introduzca el numero de columnas que tendra la matriz: ";
	cin>>n;
	MatrizRectangularEnteros objeto(n);
	
	cout<<"Introduzca la primera fila de la matriz:\n";
	for(int i=0;i<objeto.columnas_utilizadas();i++){
		cin>>n;
		objeto.aniade(n);
	}
	do{
		cout<<"Introduzca otra fila a la matriz (terminador==2000):\n";
		cin>>n;
		if(n!=2000){
			objeto.aniade(n);
			for(int i=1;i<objeto.columnas_utilizadas();i++){
				cin>>n;
				objeto.aniade(n);
			}
		}
	}while(n!=2000);
	objeto.mostrar_matriz();
	SecuenciaEnteros referencia;
	cout<<"Introduzca la cadena de enteros: \n";
	for(int i=0;i<objeto.columnas_utilizadas();i++){
		cin>>n;
		referencia.aniade(n);
	}
	SecuenciaEnteros filas_a_comparar;
	cout<<"Introduzca las filas que quiere comparar (terminador==2000):\n";
	do{
		cin>>n;
		if(0<=n && n<=objeto.filas_utilizadas()){
			filas_a_comparar.aniade(n);
		}
	}while(n!=2000);
	cout<<endl;
	objeto.comparar(filas_a_comparar, referencia);
	system("pause");
}
