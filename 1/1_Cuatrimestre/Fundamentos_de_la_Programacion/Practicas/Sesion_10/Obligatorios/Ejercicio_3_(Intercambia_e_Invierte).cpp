/*Añadid el método IntercambiaComponentes para intercambiar dos componentes
de la secuencia. Por ejemplo, si la secuencia contiene {'h','o','l','a'}, después
de intercambiar las componentes 1 y 3, se quedaría con {'h','a','l','o'}.
¿Qué debería hacer este método si los índices no son correctos?
Añadid otro método llamado Invierte para invertir la secuencia. Si contenía, por
ejemplo, los caracteres {'m','u','n','d','o'}, después de llamar al método
se quedará con {'o','d','n','u','m'}. Implementad el método Invierte llamando
a IntercambiaComponentes.
Imprimid las componentes de la secuencia desde el main, antes y después de llamar
a dicho método. Observad que se repite el mismo tipo de código cuando se imprimen
las componentes de la secuencia. Ya lo arreglaremos en el tema siguiente.*/
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
	void intercambiacomponentes(int indice1, int indice2){
		char a, b;
		if((indice1<=(total_utilizados-1)) && (indice2<=(total_utilizados-1))){
			a=vector_privado[indice1];
			b=vector_privado[indice2];
			vector_privado[indice1]=b;
			vector_privado[indice2]=a;
		}
	}
	void invierte(){
		int a, b;
		for(int i=0;i<=(total_utilizados/2);i++){
			a=(total_utilizados-1)+i;
			b=(total_utilizados-1)-i;
			intercambiacomponentes(a, b);
		}
	}
};

int main(){
	SecuenciaCaracteres objeto;
	char datoA, modifica;
	int indice, indice1;
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
		cout<<"OK"<<endl;
	}
	cout<<"Desea intercambiar 2 componentes? (s/n): ";
	cin>>modifica;
	if(modifica == 's'){
		cout<<"Introduzca los indices de los dos elementos que desea intercambiar: ";
		cin>>indice;
		cin>>indice1;
		if((indice<=(objeto.TotalUtilizados()-1)) && (indice1<=(objeto.TotalUtilizados()-1))){
			objeto.modifica(indice, indice1);
		}
		else{
			cout<<"Dichos elementos no existen"<<endl;
		}
	}
	else{
		cout<<"OK"<<endl;
	}
	cout<<endl;
	for(int j=0;j<=i;j++){
		cout<<objeto.Elemento(j)<<"  ";
	}
	cout<<"Desea invertir el orden de los componentes? (s/n): ";
	cin>>modifica;
	if(modifica=='s'){
		objeto.invierte();
			for(int j=0;j<=i;j++){
				cout<<objeto.Elemento(j)<<"  ";
			}
			cout<<endl;
	}
	else{
		cout<<"FIN"<<endl;
	}
	system("pause");
}
