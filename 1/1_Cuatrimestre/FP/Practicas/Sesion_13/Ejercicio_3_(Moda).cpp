/*Se quiere calcular la moda de una secuencia de caracteres, es decir, el carácter que
más veces se repite. Por ejemplo, si la secuencia fuese
{'l','o','s',' ','d','o','s',' ','c','o','f','r','e','s'}
los caracteres que más se repiten son 'o' y 's' con un total de 3 apariciones. La
moda sería cualquiera de ellos, por ejemplo, el primero encontrado 'o'. Sobre la
clase SecuenciaCaracteres, se pide construir el método Moda que devuelva un
struct del tipo:
struct FrecuenciaCaracter{
char caracter;
int frecuencia;
}
en el que el campo caracter contendrá el carácter en cuestión ('o') y en el campo
frecuencia el conteo de la moda (3).*/
#include <iostream>

using namespace std;

class secuenciacaracteres{
private:
	static const int max=100;
	char vector[max];
	int total;
	struct frecuenciacaracteres{
		char caracter;
		int frecuencia;
	};
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
	}
	char elemento(int indice){
		return vector[indice];
	}
	struct frecuenciacaracteres moda(){
		const int max1=26;
		int vector_contador[max1];
		int totalito=26;
		for(int i=0;i<totalito;i++){
			vector_contador[i]=0;
		}
		for(int i=0;i<total;i++){
			char a;
			a=vector[i];
			vector_contador[a-'a']=vector_contador[a-'a']+1;
		}
		int a, a1;
		a=vector_contador[0];
		a1=0;
		for(int i=1;i<totalito;i++){
			int b;
			b=vector_contador[i];
			if(a<b){
				a=b;
				a1=i;
			}
		}
		char b;
		b=a1+'a';
		struct frecuenciacaracteres lala;
		lala.caracter=b;
		lala.frecuencia=a;
		cout<<"La moda es: "<<lala.caracter<<" con una frecuencia de: "<<lala.frecuencia<<endl;
		return lala;
	}
	void mostrar_vector(){
		for(int i=0;i<total;i++){
			cout<<vector[i]<<"  ";
		}
		cout<<endl;
	}
};

int main(){
	secuenciacaracteres objeto;
	char a;
	
	do{
		cout<<"Introduzca una letra: ";
		cin>>a;
		objeto.aniade(a);
	}while(a!='#');
	objeto.mostrar_vector();
	objeto.moda();
}
