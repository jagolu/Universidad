/*El algoritmo del ejercicio 5 es muy ineficiente ya que requiere trasladar muchas veces
muchas posiciones (usa dos bucles anidados).
Para resolver eficientemente este problema se propone utilizar dos variables,
posicion_lectura y posicion_escritura que nos vayan indicando, en cada
momento, la componente que se est� leyendo y el sitio d�nde tiene que escribirse.
Por ejemplo, supongamos que en un determinado momento la variable
posicion_lectura vale 6 y posicion_escritura 3. Si la componente en la
posici�n 6 es una may�scula, simplemente avanzaremos posicion_lectura. Por
el contrario, si fuese una min�scula, la colocaremos en la posici�n 3 y avanzaremos
una posici�n ambas variables.*/
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
	void muestrasecuencia(){
		for(int i=0;i<total_utilizados;i++){
			cout<<vector_privado[i]<<"  ";
		}
		cout<<endl;
	}
	void eliminaMayusculas(){
		int posicion_lectura, posicion_escritura=0;
		char a, b;
		for(posicion_lectura=0;posicion_lectura<total_utilizados;posicion_lectura++){
			a=vector_privado[posicion_lectura];
			b=vector_privado[posicion_escritura];
			if('a'<=a && a<='z'){
				vector_privado[posicion_escritura]=a;
				posicion_escritura++;
			}
		}
		total_utilizados=posicion_escritura;
	}		
};

int main(){
	SecuenciaCaracteres objeto;
	char a;
	
	do{
		cout<<"Introduzca un caracter: ";
		cin>>a;
		objeto.Aniade(a);
	}while(a!='#');
	objeto.muestrasecuencia();
	cout<<"Elimina mayusculas...\n";
	objeto.eliminaMayusculas();
	objeto.muestrasecuencia();
	
	
	system("pause");
}
