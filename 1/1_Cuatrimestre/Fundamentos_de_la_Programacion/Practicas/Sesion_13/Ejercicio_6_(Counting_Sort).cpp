/*Sobre la clase SecuenciaCaracteres implemente el
algoritmo Counting Sort para ordenar sus valores. El método no modificará las componentes
del vector privado sino que debe construir una secuencia nueva y devolverla.
El algoritmo funciona de la siguiente forma:
 Calculad los caracteres mínimo y máximo del vector. Por ejemplo, si el vector
contiene
c b b a b c c a g c b g c
el mínimo es 'a' y el máximo 'g'.
 Construid un vector auxiliar de frecuencias con los conteos de todos los caracteres
que hay entre el mínimo y el máximo. Con el ejemplo anterior, el vector de
conteos será
2 4 5 0 0 0 2
que corresponden a las frecuencias de las letras que hay entre 'a' y 'g'.
 Recorrer el vector de frecuencias almacenando cada carácter tantas veces como
indique su frecuencia (2 veces el 'a', cuatro veces el 'b', etc)
a a b b b b c c c c c g g
Haced lo mismo pero parametrizando el método CountingSort para que ordene
sólo los valores de la secuencia que hay entre un carácter izquierda y otro carácter
derecha. Por ejemplo, si izquierda = 'b' y derecha = 'g' el resultado sería:
b b b b c c c c c g g*/
#include <iostream>

using namespace std;

class secuenciacaracteres{
private:
	static const int max=100;
	char vector[max];
	int total;
public:
	secuenciacaracteres()
		:total(0){
	}
	int total_usados(){
		return total;
	}
	int capacidad(){
		return max;
	}
	void aniade(char a){
		if(total<max && a!='#' && ('a'<=a && a<='z')){
			vector[total]=a;
			total++;
		}
		else if(a!='#'){
			cout<<"Caracter no valido\n";
		}
	}
	char elemento(int indice){
		return vector[indice];
	}
	void countingsort(char inicial, char finial){
		int esta_inicio=0, esta_final=0;
		for(int i=0;i<total;i++){
			char a;
			a=vector[i];
			if(a==inicial){
				esta_inicio=1;
			}
			else if(a==finial){
				esta_final=1;
			}
		}
		if(esta_inicio==0 && esta_final==0){
			cout<<"Ninguno de los dos caracteres esta en la secuencia\n";
		}
		else if(esta_inicio==0 && esta_final==1){
			cout<<"La letra inicial no esta en la secuencia\n";
		}
		else if(esta_inicio==1 && esta_final==0){
			cout<<"La letra final no esta en la secuencia\n";
		}
		else if(esta_inicio==1 && esta_final==1){
		orden(inicial, finial);
		}
	}
	void orden(char inicio, char final){
		if(inicio>final){
			cout<<"El orden de la letra final e inicial no es el correcto\n";
		}
		else if(inicio<final){
			ordena(inicio, final);
		}
		else{
			int cont=0;
			for(int i=0;i<total;i++){
				char a;
				if(a==inicio){
					cont++;
				}
			}
			for(int i=0;i<cont;i++){
				cout<<inicio<<"  ";
			}
			cout<<endl;
		}
	}
	void ordena(char letra_izda, char letra_decha){
		const int letras=26;
		int vector_contador[letras];
		int totalito=26;
		for(int i=0;i<totalito;i++){
			vector_contador[i]=0;
		}
		for(int i=0;i<total;i++){
			char a;
			a=vector[i];
			vector_contador[a-'a']=vector_contador[a-'a']+1;
		}
		for(int i=0;i<totalito;i++){
			int a;
			char b;
			b=i+'a';
			a=vector_contador[i];
			if((letra_izda<=b && b<=letra_decha) && a!=0){
				for(int j=0;j<a;j++){
					cout<<" "<<b<<" ";
				}
			}
		}
		cout<<endl;
	}
};

int main(){
	secuenciacaracteres objeto;
	char a;
	char letra_inicial, letra_final;
	do{
		cout<<"Introduzca una letra (solo minusculas): ";
		cin>>a;
		objeto.aniade(a);
	}while(a!='#');
	cout<<"Introduzca la letra donde desea empezar a ordenar: ";
	cin>>letra_inicial;
	cout<<"Introduzca la letra donde desea terminar de ordenar: ";
	cin>>letra_final;
	objeto.countingsort(letra_inicial, letra_final);
	system("pause");
}
