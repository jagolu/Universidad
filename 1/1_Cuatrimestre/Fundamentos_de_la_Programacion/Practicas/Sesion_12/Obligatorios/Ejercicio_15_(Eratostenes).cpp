/*(Examen Septiembre 2012) La criba de Erat�stenes (Cirene, 276 a. C. Alejandr�a,
194 a. C.) es un algoritmo que permite hallar todos los n�meros primos menores que
un n�mero natural dado n.
El procedimiento consiste en escribir todos los n�meros naturales comprendidos entre
2 y n y tachar los n�meros que no son primos de la siguiente manera: el primero (el 2)
se declara primo y se tachan todos sus m�ltiplos; se busca el siguiente n�mero entero
Gui�n de Pr�cticas. Fundamentos de Programaci�n RP-IV.8
RELACI�N DE PROBLEMAS IV. Vectores
que no ha sido tachado, se declara primo y se procede a tachar todos sus m�ltiplos, y
as� sucesivamente. El proceso para cuando el cuadrado del n�mero entero es mayor
o igual que el valor de n.
El programa debe definir una clase llamada Eratostenes que tendr� tres m�todos:
 void CalculaHasta(int n) para que calcule los primos menores que n.
Este es el m�todo que implementa el algoritmo de Erat�stenes. Cuando se ejecute
el m�todo, se almacenar�n en un vector interno del objeto todos los primos
menores que n. Debe implementarse tal y como se ha indicado anteriormente,
por lo que tendr� que decidir, por ejemplo, c�mo gestiona el tachado de los n�meros.
 int TotalCalculados() que devuelva cu�ntos primos hay actualmente almacenados.
 int Elemento(int indice) para que devuelva el indice-�simo primo.
El programa principal quedar�a de la forma:
Eratostenes primos;
int n = 100; int num_primos;
primos.CalculaHasta(n);
num_primos = primos.TotalCalculados();
for (int i=0; i<num_primos; i++)
cout << primos.Elemento(i) << " ";*/
#include <iostream>
#include <cmath>

using namespace std;

class Eratostenes{
private:
	static const int max=1000;
	int vector[max];
	int total;
public:
	Eratostenes(){
		total=0;
	}
	int elemento(int indice){
		return vector[indice];
	}
	void calculahasta(int n){
		int k, b=1, c=0, a, d=1;
		for(int i=0;i<n-1;i++){
			b++;
			vector[i]=b;
			total++;
		}
		for(int i=0;i<total-1;i++){
			a=vector[i];
			for(int j=i+1;j<total;j++){
				d++;
				b=a*d;
				if((vector[j]%a)==0){
					c=1;
				}
				if(c==1){
					elimina(j);
				}
				c=0;
			}
			d=1;
		}
	}
	void elimina(int indice){
		int a, b, a1, b1;
		a1=indice;
		b1=indice+1;
		for(int i=indice;i<total-1;i++){
			a=vector[a1];
			b=vector[b1];
			vector[a1]=b;
			vector[b1]=a;
			a1++;
			b1++;
		}
		total--;
	}
	int totalcalculados(){
		return total;
	}
};
int main(){
	Eratostenes primos;
	int n, num_primos;
	
	cout<<"Introduzca el limite: ";
	cin>>n;
	primos.calculahasta(n);
	num_primos=primos.totalcalculados();
	cout<<"Primos desde 2 hasta "<<n<<" :\n";
	cout<<"1 ";
	for(int i=0;i<num_primos;i++){
		cout<<primos.elemento(i)<<" ";
	}
	cout<<endl;
}
