/*Añadid un método con la cabecera:
void Modifica (int indice_componente, char nuevo)
para que sustituya la componente con índice indice_componente por el valor
nuevo.
Este método está pensado para modificar una componente ya existente, pero no para
añadir componentes nuevas. Por tanto, en el caso de que la componente no esté
dentro del rango correcto, el método no modificará nada.*/
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
	double EsPalindromo(){
		int c=0;
		for(int k=0;k<=((total_utilizados)/2);k=k+1){
			int a, a1, b, b1;
			a=0+k;
			b=((TotalUtilizados()-1)-k);
			a1=Elemento(a);
			b1=Elemento(b);
			if(a1 != b1){
				c=1;
			}
		}
		return c;
	}
	void modifica(int indice_componente, char nuevo){
		if(indice_componente<=total_utilizados-1){
			vector_privado[indice_componente]=nuevo;
		}
	}
};

int main(){
	SecuenciaCaracteres objeto;
	char datoA, modifica;
	int indice;
	int i, c, elementos;
	
	do{
		cout<<"Introduzca un caracter: ";
		cin>>datoA;
		if(datoA != '#'){
			i=objeto.TotalUtilizados();
			objeto.Aniade(datoA);
		}
	}while((i!=50) && (datoA != '#'));
	for(int j=0;j<=i;j++){
		cout<<objeto.Elemento(j)<<"  ";
	}
	cout<<endl;
	c=objeto.EsPalindromo();
	if(c==0){
		cout<<"Es palindromo \n";
	}
	else if(c==1){
		cout<<"No es palindromo \n";
	}
	cout<<"¿Desea modificar algun elemento? (s/n) ";
	cin>>modifica;
	if(modifica=='s'){
		cout<<"Introduzca el indice del elemento que desea cambiar \ny el caracter por el que desea cambiarlo: ";
		cin>>indice;
		cin>>datoA;
		if(indice<=objeto.TotalUtilizados()-1){
			objeto.modifica(indice, datoA);
		}
		else{
			cout<<"Ese elemento no existe"<<endl;
		}
	
	}
	else{
		cout<<"FIN"<<endl;
	}
	system("pause");
}
