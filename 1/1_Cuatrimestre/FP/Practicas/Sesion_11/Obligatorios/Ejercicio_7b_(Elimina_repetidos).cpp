/*Añadid un método EliminaRepetidos que quite los elementos repetidos, de forma
que cada componente sólo aparezca una única vez. Se mantendrá la primera aparición,
de izquierda a derecha. Por ejemplo, si la secuencia contiene
{'b','a','a','h','a','a','a','a','c','a','a','a','g'}
después de quitar los repetidos, se quedaría como sigue:
{'b','a','h','c','g'}
b) El problema del algoritmo anterior es que usa un vector local, lo que podría suponer
una carga importante de memoria si trabajásemos con vectores grandes.
Por lo tanto, vamos a resolver el problema sin usar vectores locales.
Si una componente está repetida, se borrará de la secuencia. Para borrar una
componente, podríamos desplazar una posición a la izquierda, todas las componentes
que estén a su derecha. Implementad el siguiente algoritmo:
Recorrer todas las componentes de la secuencia original
Si la componente se encuentra en alguna posición
anterior, la eliminamos desplazando hacia la
izquierda todas las componentes que hay a su derecha.*/
#include <iostream>

using namespace std;

class SecuenciaCaracteres {
private:
	static const int TAMANIO = 50;
	char vector_privado[TAMANIO];
	int total_utilizados;
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
	void muestra_secuencia(){
		for(int i=0;i<total_utilizados;i++){
			cout<<vector_privado[i]<<"  ";
		}
		cout<<endl;
	}
	void elimina(int indice){
		int a1, b1;
		a1=indice;
		b1=indice+1;
		for(int i=0;i<=total_utilizados;i++){
			char a=vector_privado[a1];
			char b=vector_privado[b1];
			vector_privado[a1]=b;
			vector_privado[b1]=a;
			a1++;
			b1++;
		}
		total_utilizados--;
	}
	void elimina_iguales(){
		char a, b;
		for(int i=0;i<total_utilizados;i++){
			for(int i=0;i<total_utilizados;i++){
				a=vector_privado[i];
				for(int k=i+1;k<total_utilizados;k++){
					b=vector_privado[k];
					if(a==b){
						elimina(k);
					}
				}
			}
		}
	}
};
int main(){
	SecuenciaCaracteres objeto;
	char letra;
	
	do{
		cout<<"Introduzca un caracter: ";
		cin>>letra;
		objeto.Aniade(letra);
	}while(letra!='#');
	objeto.muestra_secuencia();
	cout<<"Eliminando repetidos...\n";
	objeto.elimina_iguales();
	objeto.muestra_secuencia();
}
	
	
	
	
	
	
	
	
	
	
