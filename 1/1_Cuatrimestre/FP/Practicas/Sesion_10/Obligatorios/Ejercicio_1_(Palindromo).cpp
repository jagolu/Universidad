/*A�adid un m�todo EsPalindromo a la clase SecuenciaCaracteres que nos diga
si la secuencia es un pal�ndromo, es decir, que se lee igual de izquierda a derecha
que de derecha a izquierda. Por ejemplo, {'a','b','b','a'} ser�a un pal�ndromo,
pero {'a','c','b','a'} no lo ser�a. Si la secuencia tiene un n�mero
impar de componentes, la que ocupa la posici�n central es descartada, por lo que
{'a','b','j','b','a'} ser�a un pal�ndromo. Incluya un progama principal que
lea una serie de caracteres hasta llegar al terminador '#' y diga si es un pal�ndromo.
Tenga en cuenta la observaci�n de la p�gina anterior sobre la lectura de los caracteres
con cin.get().*/
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
};

int main(){
	SecuenciaCaracteres objeto;
	char datoA;
	int i, c;
	
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
	system("pause");
}
