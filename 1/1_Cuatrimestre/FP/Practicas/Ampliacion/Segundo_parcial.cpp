#include <iostream>

using namespace std;

class SecuenciaEnteros{
private:
	static const int max1=100;
	int vector_enteros[max1];
	int total1;
public:
	SecuenciaEnteros()
		:total1(0)
	{	}
	int total1_usados(){
		return total1;
	}
	void aniade_enteros(int dato){
		vector_enteros[total1]=dato;
		total1++;
	}
	int devuelve_entero(int indice){
		return vector_enteros[indice];
	}
	void ordena(){
		int a, min;
		int indice;
		bool hay_menor;
		hay_menor=false;
		for(int i=0;i<total1-1;i++){
			a=vector_enteros[i];
			min=vector_enteros[i+1];
			for(int j=i+1;j<=total1;j++){
				if(vector_enteros[j]<a && vector_enteros[j]<=min){
					hay_menor=true;
					min=vector_enteros[j];
					indice=j;
				}
			}
			if(hay_menor==true){
				vector_enteros[i]=vector_enteros[indice];
				vector_enteros[indice]=a;
			}
			hay_menor=false;
		}
	}
};
class SecuenciaCaracteres{
private:
	static const int max2=100;
	char vector_letras[max2];
	int total2;
public:
	SecuenciaCaracteres()
		:total2(0)
	{	}
	int total2_usados(){
		return total2;
	}
	void aniade_letras(char letra){
		if(letra!='#'){
			vector_letras[total2]=letra;
			total2++;
		}
	}
	void mostrar_secuenciaCaracteres(){
		for(int i=0;i<total2;i++){
			cout<<vector_letras[i]<<" ";
		}
	}
	void elimina_elemento(int indice){
		char a, b;
		for(int i=indice;i<total2-1;i++){
			a=vector_letras[i];
			b=vector_letras[i+1];
			vector_letras[i]=b;
			vector_letras[i+1]=a;
		}
		total2--;
	}
	void elimina(SecuenciaEnteros secuencia){
		secuencia.ordena();
		for(int i=0;i<secuencia.total1_usados();i++){
			elimina_elemento(secuencia.devuelve_entero(i)-i);
		}
	}
};

int main(){
	char letras;
	int numeros;
	
	SecuenciaCaracteres objeto;
	SecuenciaEnteros objeto2;
	
	cout<<"Introduzca la secuencia de caracteres (TERMINADOR=='#'):\n";
	do{
		cin>>letras;
		objeto.aniade_letras(letras);
	}while(letras!='#');
	cout<<"Introduzca los indices a eliminar (TERMINADOR==-1):\n";
	do{
		cin>>numeros;
		if(0<=numeros && numeros<objeto.total2_usados()){
			objeto2.aniade_enteros(numeros);
		}
		if((0>numeros && numeros>objeto.total2_usados()) && numeros!=-1){
			cout<<"Ese indice no esta en la secuencia de caracteres\n";
		}
	}while(numeros!=-1);
	cout<<"\n\nSECUENCIA DE CARACTERES ORIGINAL:\n";
	objeto.mostrar_secuenciaCaracteres();
	cout<<"\n\nNUEVA SECUENCIA DE CARACTERES:\n";
	objeto.elimina(objeto2);
	objeto.mostrar_secuenciaCaracteres();
	cout<<endl<<endl;
	objeto2.ordena();
	for(int i=0; i<objeto2.total1_usados(); i++){
		cout<<objeto2.devuelve_entero(i)<<" ";
	}
	cout<<endl;
	system("pause");
}
