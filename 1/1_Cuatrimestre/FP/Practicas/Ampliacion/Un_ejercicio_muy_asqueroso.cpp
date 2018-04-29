#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class SecuenciaEnteros{
private:
	static const int max=100;
	int vector_notas[max];
	int total_notas;
public:
	SecuenciaEnteros()
		:total_notas(0)
	{	}
	void aniade_notas(int dato){
		if(0<=dato && dato<=10){
			vector_notas[total_notas]=dato;
			total_notas++;
		}
	}
	int total_enteros(){
		return total_notas;
	}
	void mostrar_notas(){
		for(int i=0;i<total_notas;i++){
			cout<<vector_notas[i];
			if(i<total_notas-1){
				cout<<", ";
			}
		}
	}
	int mostrar_elemento(int indice){
		return vector_notas[indice];
	}
	void intercambiar(int indice1, int indice2){
		int a, b;
		a=vector_notas[indice1];
		b=vector_notas[indice2];
		vector_notas[indice1]=b;
		vector_notas[indice2]=a;
	}
};
class SecuenciaCaracteres{
private:
	static const int max1=100;
	char vector_nombre[max1];
	int total_letras;
public:
	SecuenciaCaracteres()
		:total_letras(0)
	{	}
	void aniade_letra(string letra){
		for(int i=0;i<letra.size();i++){
			vector_nombre[i]=letra[i];
			total_letras=letra.size();
		}
	}
	int total_nombre(){
		return total_letras;
	}
	void mostrar_nombre(){
		for(int i=0;i<total_letras;i++){
			cout<<vector_nombre[i];
		}
	}
	char mostrar_letra(int indice){
		return vector_nombre[indice];
	}
};
class alumnos{
private:
	static const int max2=100;
	SecuenciaCaracteres vector_nombres_alumnos[max2];
	int total_alumnos;
	SecuenciaEnteros vector_notas_alumnos[max2]; 
public:
	alumnos()
		:total_alumnos(0)
	{	}
	void aniade_las_notas(SecuenciaEnteros notas, SecuenciaCaracteres nombre){
		vector_nombres_alumnos[total_alumnos]=nombre;
		vector_notas_alumnos[total_alumnos]=notas;
		total_alumnos++;
	}
	int alumnos_total(){
		return total_alumnos;
	}
	SecuenciaCaracteres mostrar_nombre_de_alumno(int indice){
		if(0<=indice && indice<total_alumnos){
			return vector_nombres_alumnos[indice];
		}
		else{
			cout<<"Indice no valido\n";
		}
	}
	SecuenciaEnteros mostrar_notas_alumno(int indice){
		if(0<=indice && indice<total_alumnos){
			return vector_notas_alumnos[indice];
		}
		else{
			cout<<"Indice no valido";
		}
	}
	SecuenciaEnteros busca_secuencia(SecuenciaCaracteres referencia){
		SecuenciaEnteros nombres_que_coinciden;
		int esta1=-1;
		for(int i=0;i<total_alumnos;i++){
			for(int j=0;j<vector_nombres_alumnos[i].total_nombre();j++){
				char a;
				a=vector_nombres_alumnos[i].mostrar_letra(j);
				if(a==referencia.mostrar_letra(0)){
					bool esta;
					esta=true;
					for(int i2=1;i2<referencia.total_nombre();i2++){
						char b=vector_nombres_alumnos[i].mostrar_letra(j+i2);
						char c=referencia.mostrar_letra(i2);
						if(b!=c){
							esta=false;
						}
					}
					if(esta==true && esta1!=i){
						nombres_que_coinciden.aniade_notas(i);
						esta1=i;
					}
				}
			}
		}
		if(esta1!=-1){
			return nombres_que_coinciden;
		}
		else{
			cout<<"La cadena no aparece en ningun lado\n";
		}
	}
	double media(SecuenciaEnteros numeros){
		double suma=0;
		double contador=numeros.total_enteros();
		for(int i=0;i<numeros.total_enteros();i++){
			suma=suma+numeros.mostrar_elemento(i);
		}
		double media=suma/contador;
		return media;
	}
	SecuenciaEnteros orden(){
		SecuenciaEnteros vector_orden;
		for(int i=0;i<total_alumnos;i++){
			vector_orden.aniade_notas(i);
		}
		int menor;
		for(int i=0;i<total_alumnos;i++){
			double a, b;
			a=media(vector_notas_alumnos[i]);
			b=media(vector_notas_alumnos[i+1]);
			if(a>=b){
				vector_orden.intercambiar(i, i+1);
			}
		}
		return vector_orden;
	}
};
int main(){
	int numero;
	char letra;
	string nombre1;
	alumnos objeto;
	char lala;
	do{
		SecuenciaCaracteres nombre;
		cout<<"Introduca los caracteres del nombre: \n";
		getline(cin, nombre1);
		if(nombre1.size()!=0){
			nombre.aniade_letra(nombre1);
			SecuenciaEnteros notas;
			do{
				
				cout<<"Introduzca las notas del crio---> ";
				cin>>numero;
				
				notas.aniade_notas(numero);
			}while(0<=numero && numero<=10);
			objeto.aniade_las_notas(notas, nombre);
		}
		cout<<"Mas estudiantes? ";
		cin>>lala;
		cin.ignore();
	}while(lala!='n' && lala!='N');
	cout<<"\n\n\nAPARTADO A\n\n";
	cout<<"Hay "<<objeto.alumnos_total()<<" estudiantes"<<endl;
	cout<<"\n\nAPARTADO B\n\n";
	cout<<"Introduce el indice del crio del que desea saber el nombre: ";
	cin>>numero;
	cout<<"El crio se llama ";
	objeto.mostrar_nombre_de_alumno(numero).mostrar_nombre();
	cout<<endl;
	cout<<"\n\nAPARTADO C\n\n";
	cout<<"Introduce el indice del crio del que desea saber las notas: ";
	cin>>numero;
	cout<<"Las notas del crio son: ";
	objeto.mostrar_notas_alumno(numero).mostrar_notas();
	cout<<endl;
	cin.ignore();
	cout<<"\n\nAPARTADO D\n\n";
	SecuenciaCaracteres cadena;
	string cadena_a_buscar;
	cout<<"Introduzca la secuencia a buscar: ";
	getline(cin, cadena_a_buscar);
	cadena.aniade_letra(cadena_a_buscar);
	cout<<"La cadena aparece en los nombres de indice: ";
	objeto.busca_secuencia(cadena).mostrar_notas();
	cout<<endl;
	cout<<"\n\nAPARTADO F\n\nOrdenando...\n";
	objeto.orden();
	objeto.orden().mostrar_notas();
	cout<<endl;
	for(int i=0;i<objeto.alumnos_total();i++){
		objeto.mostrar_nombre_de_alumno(objeto.orden().mostrar_elemento(i)).mostrar_nombre();
		cout<<"    ";
		objeto.mostrar_notas_alumno(objeto.orden().mostrar_elemento(i)).mostrar_notas();
		cout<<endl;
	}
	system("pause");
}
