/*Sge�n un etsduio de una uivenrsdiad ignlsea, no ipmotra el odren en el que las ltears
etsan ersciats, la �icna csoa ipormtnate es que la pmrirea y la �tlima ltera ets�n ecsritas
en la psioci�n cocrrtea. El rsteo peuden estar ttaolmntee mal y a�n pord�s lerelo
sin pobrleams. Etso es pquore no lemeos cada ltera por s� msima snio la paalbra cmoo
un tdoo.
Se pide crear la clase Palabra que permita almacenar un conjunto de caracteres
que representar�n una palabra. Definid un m�todo EsIgual al que se le pase como
par�metro otra palabra y determine si son iguales atendiendo al siguiente criterio: La
primera letra de ambas palabras es igual, la �ltima letra de ambas palabras tambi�n
es igual y el resto de las letras son las mismas pero no est�n necesariamente en las
mismas posiciones.*/
#include <iostream>

using namespace std;

class palabra{
private:
	string palabra1;
public:
	palabra(string palabraA)
		:palabra1(palabraA){
	}
	void EsIgual(string palabra2){
		int long1=palabra1.size();
		int long2=palabra2.size();
		char a1, a2, b1, b2;
		int c=0;
		bool interior=true;
		a1=tolower(palabra1[0]);
		a2=tolower(palabra1[long1]);
		b1=tolower(palabra2[0]);
		b2=tolower(palabra2[long2]);
		for(int i=1;i<long1-1;i++){
			char a;
			a=palabra1[i];
			for(int j=1;j<long2-1;j++){
				char b;
				b=palabra2[j];
				if(a==b){
					c=1;
				}
			}
			if(c==0){
				interior=false;
			}
			c=0;
		}
		if((a1==b1) && (a2==b2) && (interior==true) && (long1==long2)){
			cout<<"Se puede leer sin problemas\n";
		}
		else{
			cout<<"La palabra no se entendera\n";
		}
	}
};
int main(){
	string letras;
	cout<<"Introduzca la palabra bien escrita: ";
	cin>>letras;
	palabra palabrita(letras);
	cout<<"Introduzca la palabra, pero mal escrita: ";
	cin>>letras;
	palabrita.EsIgual(letras);
}
	
