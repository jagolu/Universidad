/*En el primer apartado del ejercicio 7 de la relación de problemas III se pedía eliminar
los repetidos de un objeto de la clase SecuenciaCaracteres usando como dato
auxiliar local un vector clásico con los elementos que no estuviesen repetidos. Recuperad
la solución vista en clase y resolved este mismo apartado usando como dato
auxiliar local un objeto de la propia clase SecuenciaCaracteres*/
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
	void MostrarVector(){
		for(int i=0;i<total_utilizados;i++){
			cout<<vector_privado[i]<<"   ";
		}
		cout<<endl;
	}
	void elimina_repetidos(){
		SecuenciaCaracteres nuevo;
		nuevo.Aniade(vector_privado[0]);
		for(int i=1;i<total_utilizados;i++){
			char a;
			bool esta=false;
			a=vector_privado[i];
			for(int j=0;j<nuevo.TotalUtilizados();j++){
				char b;
				b=nuevo.Elemento(j);
				if(a==b){
					esta=true;
				}
			}
			if(esta==false){
				nuevo.Aniade(vector_privado[i]);
			}
			esta=false;
		}
		for(int i=0;i<nuevo.TotalUtilizados();i++){
			cout<<nuevo.Elemento(i)<<"  ";
		}
		cout<<endl;
	}
};

int main(){
	SecuenciaCaracteres objeto;
	char a;
	do{
		cout<<"Introduzca un nuevo caracter: ";
		cin>>a;
		objeto.Aniade(a);
	}while(a!='#');
	objeto.elimina_repetidos();	
	system("pause");
}
