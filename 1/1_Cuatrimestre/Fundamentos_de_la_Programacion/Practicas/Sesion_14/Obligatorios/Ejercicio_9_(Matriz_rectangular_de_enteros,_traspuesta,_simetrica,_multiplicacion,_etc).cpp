/*Definid la clase MatrizRectangularEnteros usando una matriz de doble corchete
como dato miembro privado.
int matriz_privada[MAXIMO_FILAS][MAXIMO_COLUMNAS];*/
#include <iostream>

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
	SecuenciaEnteros mostrar_fila(int fila_1){
		SecuenciaEnteros objeto_fila;
		for(int i=0;i<columnas;i++){
			objeto_fila.aniade(matriz[fila_1][i]);
		}
		return objeto_fila;
	}
	bool comparar_matriz(MatrizRectangularEnteros matriz2){
		bool iguales;
		if(filas!=matriz2.filas_utilizadas() || columnas!=matriz2.columnas_utilizadas()){
			cout<<"No tienen la misma dimension\nPor lo tanto no son iguales\n";
			iguales=false;
		}
		else{
			bool terminar;
			terminar=false;
			int i=0, j=0;
			do{
				int a, b;
				a=matriz[i][j];
				b=matriz2.mostrar_elemento_matriz(i, j);
				if(a!=b){
					terminar=true;
					iguales=false;
				}
				if((i+1==filas) && (j+1==columnas)){
					terminar=true;
					iguales=true;
				}
				j++;
				if(j==columnas){
					i++;
					j=0;
				}
			}while(terminar!=true);
		}
		return iguales;
	}
	void Son_iguales(MatrizRectangularEnteros matriz_comparar){
		bool a;
		a=comparar_matriz(matriz_comparar);
		if(a==true){
			cout<<"Son iguales\n";
		}
		else{
			cout<<"No son iguales\n";
		}
	}
	void simetrica(){
		if(filas != columnas){
			cout<<"La matriz no es cuadrada, por lo tanto no puede ser simetrica\n";
		}
		else{
			traspuesta();
			bool a;
			a=comparar_matriz(traspuesta());
			if(a==true){
				cout<<"Si son simetricas\n";
			}
			else{
				cout<<"No son simetricas\n";
			}
		}
	}
	MatrizRectangularEnteros traspuesta(){
		MatrizRectangularEnteros matriz_simetrica(filas);
		for(int i=0;i<columnas;i++){
			for(int j=0;j<filas;j++){
				int a;
				a=matriz[j][i];
				matriz_simetrica.aniade(a);
			}
		}
		return matriz_simetrica;
	}
	MatrizRectangularEnteros multiplicar(MatrizRectangularEnteros matriz2){
		MatrizRectangularEnteros matriz_multiplicada(matriz2.columnas_utilizadas());
		int total=0;	
		for(int i=0;i<filas;i++){
			for(int j=0;j<matriz2.columnas_utilizadas();j++){
				for(int k=0;k<columnas;k++){
					int a, b;
					a=matriz[i][k];
					b=matriz2.mostrar_elemento_matriz(k, j);
					total=total+(a*b);
				}
				matriz_multiplicada.aniade(total);
				total=0;
			}
		}
		return matriz_multiplicada;
	}
	void aniade_nueva_fila(SecuenciaEnteros fila_nueva){
		for(int i=0;i<columnas;i++){
			int a;
			a=fila_nueva.mostrar_elemento(i);
			aniade(a);
		}
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
	cout<<"\n\nAPARTADO A\n";
	/*Obtener el número de filas y columnas utilizadas, así como el dato que haya en una fila y columna.*/
	cout<<"Ha introducido "<<objeto.filas_utilizadas()<<" filas\n";
	cout<<"\n\nAPARTADO B\n";
	/*Devolver una fila completa como un objeto de la clase SecuenciaEnteros.*/
	cout<<"Introduzca el indice de la fila de la matriz que desea mostrar: ";
	cin>>n;
	if(n<objeto.filas_utilizadas()){
		for(int i=0;i<objeto.columnas_utilizadas();i++){
			cout<<objeto.mostrar_fila(n).mostrar_elemento(i)<<" ";
		}
	}
	else{
		cout<<"Dicha fila no existe\n";
	}
	cout<<"\n\n\nAPARTADO C\n";
	/*Añadir una fila entera. La fila será un objeto de la clase SecuenciaEnteros.*/
	cout<<"Introduzca los elementos de una fila que se insertara abajo de la matriz:\n";
	SecuenciaEnteros nueva_fila;
	for(int i=0;i<objeto.columnas_utilizadas();i++){
		cin>>n;
		nueva_fila.aniade(n);
	}
	objeto.aniade_nueva_fila(nueva_fila);
	cout<<"La matriz ahora es: \n";
	objeto.mostrar_matriz();
	cout<<"\n\nAPARTADO D\n";
	/*Comprobar si es igual a otra matriz.*/
	cout<<"Vamos a crear otra matriz, para compararla con la primera...\n";
	cout<<"Introduzca el numero de columnas que tendra la matriz: ";
	cin>>n;
	MatrizRectangularEnteros objeto2(n);
	
	cout<<"Introduzca la primera fila de la matriz:\n";
	for(int i=0;i<objeto2.columnas_utilizadas();i++){
		cin>>n;
		objeto2.aniade(n);
	}
	do{
		cout<<"Introduzca otra fila a la matriz (terminador==2000):\n";
		cin>>n;
		if(n!=2000){
			objeto2.aniade(n);
			for(int i=1;i<objeto2.columnas_utilizadas();i++){
				cin>>n;
				objeto2.aniade(n);
			}
		}
	}while(n!=2000);
	objeto2.mostrar_matriz();
	objeto.Son_iguales(objeto2);
	cout<<"\n\nAPARTADO E\n";
	/*Obtener la traspuesta.*/
	do{
		cout<<"Introduzca la matriz a la que desea calcular la traspuesta: ";
		cin>>n;	
	}while(n!=1 && n!=2);
	if(n==1){
		objeto.traspuesta().mostrar_matriz();
	}
	else if(n==2){
		objeto2.traspuesta().mostrar_matriz();
	}
	cout<<"\n\nAPARTADO F\n";
	/*Comprobar si es simétrica. Hacedlo primero calculando la traspuesta de la matriz
	y viendo si es igual a su simétrica, usando los métodos anteriores.
	Hacedlo también comprobando directamente si cada componente es igual a su
	simétrica y parando el recorrido en cuanto encuentre una componente que no lo
	verifique.*/
	do{
		cout<<"Introduzca la matriz a la que quiera comprobar si es simetrica: ";
		cin>>n;
	}while(n!=1 && n!=2);
	if(n==1){
		objeto.simetrica();
	}
	else if(n==2){
		objeto2.simetrica();
	}
	cout<<"\n\nAPARTADO G\n";
	/*Multiplicar dos matrices.*/
	cout<<"1) Las dos matrices originales\n";
	cout<<"2) La primera matriz por la traspuesta de la segunda\n";
	cout<<"3) La traspuesta de la primera por la segunda\n";
	cout<<"4) La traspuesta de la primera por la traspuesta de la segunda\n";
	do{
		cout<<"Introduzca las dos matrices que desea multiplicar (1/2/3/4): ";
		cin>>n;
	}while(n<1 || 4<n);
	if(n==1){
		if(objeto.columnas_utilizadas()!=objeto2.filas_utilizadas()){
			cout<<"Esas dos matrices no se pueden multiplicar\n";
		}
		else{
			objeto.multiplicar(objeto2).mostrar_matriz();
		}
	}
	else if(n==2){
		if(objeto.columnas_utilizadas()!=objeto2.traspuesta().filas_utilizadas()){
			cout<<"Esas dos matrices no se pueden multiplicar\n";
		}
		else{
			objeto.multiplicar(objeto2.traspuesta()).mostrar_matriz();
		}
	}
	else if(n==3){
		if(objeto.traspuesta().columnas_utilizadas()!=objeto2.filas_utilizadas()){
			cout<<"Esas dos matrices no se pueden multiplicar\n";
		}
		else{
			objeto.traspuesta().multiplicar(objeto2).mostrar_matriz();
		}
	}
	else if(n==4){
		if(objeto.traspuesta().columnas_utilizadas()!=objeto2.traspuesta().filas_utilizadas()){
			cout<<"Esas dos matrices no se pueden multiplicar\n";
		}
		else{
			objeto.traspuesta().multiplicar(objeto2.traspuesta()).mostrar_matriz();
		}
	}
	cout<<"FIN\n";
	system("pause");
}
