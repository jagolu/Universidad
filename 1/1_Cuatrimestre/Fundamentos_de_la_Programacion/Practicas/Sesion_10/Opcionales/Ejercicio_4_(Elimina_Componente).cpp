/*Añadid el método Elimina para eliminar el carácter que se encuentre en
una determinada posición.*/
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
		if (total_utilizados < TAMANIO){
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}
	char Elemento(int indice){
		return vector_privado[indice];
	}
	void elimina(int indice){
		int final=TotalUtilizados();
		int i=indice;
		for(i=indice;i<final;i++){
			char a, b;
			a=Elemento(i);
			b=Elemento(i+1);
			a=b;
		}
		total_utilizados=total_utilizados-1;
	}
};

int main(){
	SecuenciaCaracteres objeto;
	char a;
	int b;
	int total;
	
	do{
		cout<<"Introduzca el caracter :";
		cin>>a;
		if(a!='#'){
			objeto.Aniade(a);
		}
	}while(a!='#');
	total=objeto.TotalUtilizados();
	for(int i=0;i<=total;i++){
		cout<<objeto.Elemento(i)<<"  ";
	}
	cout<<endl;
	cout<<"Introduzca el indice del elemento que desea eliminar: ";
	cin>>b;
	objeto.elimina(b);
	for(int i=0;i<=total;i++){
		cout<<objeto.Elemento(i)<<"  ";
	}
	cout<<endl;
	system("pause");
}
