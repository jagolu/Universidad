/*(Examen Septiembre 2012) La criba de Eratóstenes (Cirene, 276 a. C. Alejandría,
194 a. C.) es un algoritmo que permite hallar todos los números primos menores que
un número natural dado n.
El procedimiento consiste en escribir todos los números naturales comprendidos entre
2 y n y tachar los números que no son primos de la siguiente manera: el primero (el 2)
se declara primo y se tachan todos sus múltiplos; se busca el siguiente número entero
Guión de Prácticas. Fundamentos de Programación RP-IV.8
RELACIÓN DE PROBLEMAS IV. Vectores
que no ha sido tachado, se declara primo y se procede a tachar todos sus múltiplos, y
así sucesivamente. El proceso para cuando el cuadrado del número entero es mayor
o igual que el valor de n.
El programa debe definir una clase llamada Eratostenes que tendrá tres métodos:
 void CalculaHasta(int n) para que calcule los primos menores que n.
Este es el método que implementa el algoritmo de Eratóstenes. Cuando se ejecute
el método, se almacenarán en un vector interno del objeto todos los primos
menores que n. Debe implementarse tal y como se ha indicado anteriormente,
por lo que tendrá que decidir, por ejemplo, cómo gestiona el tachado de los números.
 int TotalCalculados() que devuelva cuántos primos hay actualmente almacenados.
 int Elemento(int indice) para que devuelva el indice-ésimo primo.
El programa principal quedaría de la forma:
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
