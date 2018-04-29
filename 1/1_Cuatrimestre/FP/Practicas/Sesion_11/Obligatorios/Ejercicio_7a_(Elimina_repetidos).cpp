/*Añadid un método EliminaRepetidos que quite los elementos repetidos, de forma
que cada componente sólo aparezca una única vez. Se mantendrá la primera aparición,
de izquierda a derecha. Por ejemplo, si la secuencia contiene
{'b','a','a','h','a','a','a','a','c','a','a','a','g'}
después de quitar los repetidos, se quedaría como sigue:
{'b','a','h','c','g'}
Implementad los siguientes algoritmos para resolver ester problema:
a) Usad un vector local sin_repetidos en el que almacenamos una única aparición
de cada componente:
Recorrer todas las componentes de la secuencia original
Si la componente NO está en "sin_repetidos",
añadirla (al vector "sin_repetidos")
Asignar las componentes de "sin_repetidos" a la secuencia*/
#include <iostream>

using namespace std;

class SecuenciaCaracteres {
private:
	static const int TAMANIO = 50;
	char vector_privado[TAMANIO];
	int total_utilizados;
	static const int max=50;
	char vector[max];
	int total;
public:
	SecuenciaCaracteres()
		:total_utilizados(0){
	}
	int TotalUtilizados(){
		return total_utilizados;
	}
	int Capacidad(){
		return TAMANIO;
	}
	void Aniade(char nuevo){
		if ((total_utilizados < TAMANIO) && (nuevo!='#')){
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}
	char Elemento(int indice){
		return vector_privado[indice];
	}
	void MostrarVector(){
		for(int i=0;i<total_utilizados;i++){
			cout<<vector_privado[i]<<"   ";
		}
		cout<<endl;
	}
	void EliminaRepetidos(){
		char a, b;
		int c=0;
		total=0;
		vector[0]=vector_privado[0];
		for(int i=1;i<total_utilizados;i++){
			a=vector_privado[i];
			for(int j=0;j<=total;j++){
				b=vector[j];
				if(a==b){
					c=1;
				}
			}
			if(c==0){
				total1++;
				vector[total1]=a;
			}
			c=0;
		}
	}
	char muestrasinrepetidos(int indice){
		return vector[indice];
	}	
	int muestratotal(){
		return total;
	}
};

int main(){
	SecuenciaCaracteres objeto;
	char a;
	int max=50;
	char sin_repetidos[max];
	do{
		cout<<"Introduzca un caracter de la secuencia: ";
		cin>>a;
		objeto.Aniade(a);
	}while(a!='#');
	objeto.MostrarVector();
	cout<<"Quitando iguales...\n";
	objeto.EliminaRepetidos();
	for(int i=0;i<=objeto.muestratotal();i++){
		sin_repetidos[i]=objeto.muestrasinrepetidos(i);
	}
	
	for(int i=0;i<=objeto.muestratotal();i++){
		cout<<sin_repetidos[i]<<"  ";
	}
	cout<<endl;
	system("pause");
}

