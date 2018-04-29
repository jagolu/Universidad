/*La posición de aquel elemento que sea el mayor de
entre los mínimos de cada fila.*/
#include <iostream>

using namespace std;

int main(){
	int totalfilas, totalcolumnas, n, a;
	int fila=0, columna=0;
	
	cout<<"Introduzca el total de filas: ";
	cin>>totalfilas;
	cout<<"Introduzca el total de columnas: ";
	cin>>totalcolumnas;
	
	int matriz[totalfilas][totalcolumnas];
	
	do{
		cout<<"Fila "<<fila<<" y columna "<<columna<<" : ";
		cin>>n;
		matriz[fila][columna]=n;
		columna++;
		if(columna==totalcolumnas){
			fila++;
			columna=0;
		}
	}while((columna>=totalcolumnas-1) || (fila!=totalfilas));
	for(int i=0;i<totalfilas;i++){
		for(int j=0;j<totalcolumnas;j++){
			cout<<matriz[i][j]<<"  ";
		}
		cout<<endl;
	}
	fila=0, columna=0;
	const int max=50;
	int vector[max];
	int filamax=0;
	do{
		a=matriz[fila][0];
		for(int i=0;i<totalcolumnas;i++){
			int b;
			b=matriz[fila][i];
			if(a>=b){
				a=b;
				vector[fila]=b;
			}
		}
		fila++;
	}while(fila<totalfilas);
	a=vector[0];
	for(int i=0;i<totalcolumnas-1;i++){
		int b;
		b=vector[i];
		if(a<=b){
			filamax=i;
		}
	}
	int columnamax;
	a=vector[filamax];
	for(int i=0;i<totalcolumnas;i++){
		int b;
		b=matriz[filamax][i];
		if(a==b){
			columnamax=i;
		}
	}
	cout<<"El maximo entre ";
	for(int i=0;i<totalfilas;i++){
		cout<<vector[i]<<"  ";
	}
	cout<<"(los minimos de cada fila) es "<<a<<" \ny se encuentra en la posicion ("<<columnamax<<", "<<filamax<<")\n";
}
