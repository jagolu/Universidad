/*Añadid el método EliminaMayusculas para eliminar todas las mayúsculas.
Por ejemplo, después de aplicar dicho método al vector
{'S','o','Y',' ','y','O'}, éste debe quedarse con {'o',' ','y'}.*/
#include <iostream>
#include <locale>

using namespace std;

class SecuenciaCaracteres{
private:
	static const int tamanio=50;
	char vector_privado[tamanio];
	int total_utilizados;
public:
	SecuenciaCaracteres()
		:total_utilizados(0){
	}
	int TotalUtilizados(){
		return total_utilizados;
	}
	int capacidad(){
		return tamanio;
	}
	void aniade(char nuevo){
		if(total_utilizados < tamanio){
			vector_privado[total_utilizados]=nuevo;
			total_utilizados++;
		}
	}
	char elemento(int indice){
		return vector_privado[indice];
	}
	void elimina(int indice){
		int a, b;
		a=indice;
		b=indice+1;
		for(int i=a;i<(total_utilizados-1);i++){
			vector_privado[a]=vector_privado[b];
			a=a+1;
			b=b+1;
		}
		total_utilizados--;
	}
	void eliminamayusculas(){
		int contador=0;
		for(int b=0;b<total_utilizados;b++){
			for(int i=0;i<total_utilizados;i++){
				if(isupper(vector_privado[i])){
					elimina(i);
				}
			}
		}
		for(int i=0;i<total_utilizados;i++){
			if(isupper(vector_privado[i])){
					contador++;
				}
			}
		total_utilizados=total_utilizados-contador;
	}
};

int main(){
	SecuenciaCaracteres objeto;
	char a, S;
	int total, elimina;
	
	do{
		cout<<"Introduzca un caracter: ";
		cin>>a;
		if(a!='#'){
			objeto.aniade(a);
		}
	}while(a!='#');
	total=objeto.TotalUtilizados();
	for(int i=0;i<total;i++){
		cout<<objeto.elemento(i)<<"  ";
	}
	cout<<endl;
	cout<<"Eliminando mayusculas..."<<endl;
	objeto.eliminamayusculas();
	total=objeto.TotalUtilizados();
	for(int i=0;i<total;i++){
		cout<<objeto.elemento(i)<<"  ";
	}
	cout<<endl;
	system("pause");
}
	
