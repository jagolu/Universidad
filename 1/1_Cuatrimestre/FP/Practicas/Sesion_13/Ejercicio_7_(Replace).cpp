/*Sobre la clase SecuenciaCaracteres construid un método llamado Reemplaza
con la misma funcionalidad que replace (el método no devuelve ningún objeto sino
que modifica los datos de éste).
Restricciones para este ejercicio: No se puede utilizar la clase string en ninguna
parte del programa, debe hacerse lo más eficiente posible y no puede utilizarse un
vector o secuencia auxiliar en el que se vaya almacenando el resultado, es decir, las
modificaciones deben hacerse directamente sobre los datos originales.*/
#include <iostream>

using namespace std;

class secuenciacaracteres{
private:
	static const int max=1000;
	char vector[max];
	int total;
public:
	secuenciacaracteres()
		:total(0)
	{	}
	void aniade(char nuevo){
		if(nuevo!='#'){
			vector[total]=nuevo;
			total++;
		}
	}
	int total_usados(){
		return total;
	}
	char mostrar_elemento(int indice){
		return vector[indice];
	}
	void replace(secuenciacaracteres cad2, int n1, int n2){
		if((total-n2+cad2.total_usados())>=total){
			int distancia;
			distancia=(total-n2+cad2.total_usados())-total;
			for(int i=total-1;i>=n1;i--){
				char a;
				a=vector[i];
				vector[i-distancia]=a;
			}
			total=total-n2+cad2.total_usados();
			for(int i=0;i<cad2.total_usados();i++){
				vector[n1+i]=cad2.mostrar_elemento(i);
			}
		}
		else{
			int distancia;
			distancia=total-(total-n2+cad2.total_usados());
			for(int i=n1+n2;i<total;i++){
				char a;
				a=vector[i];
				vector[i-distancia]=a;
			}
			total=total-n2+cad2.total_usados();
			for(int i=0;i<cad2.total_usados();i++){
				vector[n1+i]=cad2.mostrar_elemento(i);
			}
		}
	}
	void mostrar_vector(){
		for(int i=0;i<total;i++){
			cout<<vector[i];
		}
	}
};
int main(){
	char letra;
	int n1, n2;
	secuenciacaracteres cadena1;
	cout<<"Terminador=='#')\n";
	cout<<"Introduzca la primera cadena...\n";
	do{
		cout<<"Introduzca una letra: ";
		letra=cin.get();
		cin.ignore();
		cadena1.aniade(letra);
	}while(letra!='#');
	cout<<endl<<endl;
	cadena1.mostrar_vector();
	secuenciacaracteres cadena2;
	cout<<endl<<endl;
	cout<<"\nTerminador=='#')\n";
	cout<<"Introduzca la segunda cadena...\n";
	do{
		cout<<"Introduzca una letra: ";
		letra = cin.get();
		cin.ignore();
		cadena2.aniade(letra);
	}while(letra!='#');
	cout<<"Introduzca el numero de comienzo: ";
	cin>>n1;
	cout<<"Introduzca la longitud: ";
	cin>>n2;
	cadena1.replace(cadena2, n1, n2);
	cout<<endl<<endl;
	cadena1.mostrar_vector();
	cout<<endl<<endl;
	system("pause");
}
