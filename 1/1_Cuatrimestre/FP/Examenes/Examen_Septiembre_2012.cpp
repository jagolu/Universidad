#include <iostream>

using namespace std;

class ConjuntoOrdenado{
private:
	static const int max=100;
	int vector[max];
	int total;
public:
	ConjuntoOrdenado()
		:total(0)
	{	}
	int total_usados(){
		return total;
	}
	void ordena(){
		int a, b, min, indice;
		bool hay_menor;
		for(int i=0;i<total;i++){
			a=vector[i];
			min=vector[i+1];
			indice=i+1;
			hay_menor=false;
			for(int j=i+1;j<total;j++){
				b=vector[j];
				if(a>=b && min>=b){
					hay_menor=true;
					indice=j;
				}
			}
			if(hay_menor==true){
				vector[i]=vector[indice];
				vector[indice]=a;
			}
		}
	}
	void aniade(int dato){
		bool esta;
		esta=false;
		if(dato!=-1){
			for(int i=0;i<total;i++){
				if(vector[i]==dato){
					esta=true;
				}
			}
		}
		if(esta==false){
			vector[total]=dato;
			total++;
		}
		ordena();
	}
	void mostrar(){
		for(int i=0;i<total;i++){
			cout<<vector[i]<<" ";
		}
		cout<<endl;
	}
	int elemento(int indice){
		return vector[indice];
	}
	void elimina(int indice1){
		int a, b;
		for(int i=indice1;i<total;i++){
			a=vector[i];
			b=vector[i+1];
			vector[i]=a;
			vector[i+1]=b;
		}
		total--;
	}
	void aniade_sin_repetir(int dato){
		vector[total]=dato;
		total++;
	}
	ConjuntoOrdenado unioon(ConjuntoOrdenado lala1, ConjuntoOrdenado lala2){
		ConjuntoOrdenado vector_union;
		for(int i=0;i<lala1.total_usados();i++){
			vector_union.aniade(lala1.elemento(i));
		}
		for(int i=0;i<lala2.total_usados();i++){
			vector_union.aniade(lala2.elemento(i));
		}
		return vector_union;
	}
	ConjuntoOrdenado interseccion(ConjuntoOrdenado lala1, ConjuntoOrdenado lala2){
		ConjuntoOrdenado todos;
		ConjuntoOrdenado vector_interseccion;
		for(int i=0;i<lala1.total_usados();i++){
			todos.aniade_sin_repetir(lala1.elemento(i));
		}
		for(int i=0;i<lala2.total_usados();i++){
			todos.aniade_sin_repetir(lala2.elemento(i));
		}
		todos.ordena();
		todos.ordena();
		for(int i=0;i<todos.total_usados();i++){
			int a, b;
			a=todos.elemento(i);
			b=todos.elemento(i+1);
			if(a==b){
				vector_interseccion.aniade(b);
			}
		}
		return vector_interseccion;
	}

};

int main(){
	int n;
	ConjuntoOrdenado objeto1;
	ConjuntoOrdenado objeto2;
	cout<<"Introduzca los elementos del primero conjunto: \n";
	do{
		cin>>n;
		if(n!=-1){
			objeto1.aniade(n);
		}
	}while(n!=-1);
	cout<<"Introduzca los elementos del segundo conjunto: \n";
	do{
		cin>>n;
		if(n!=-1){
			objeto2.aniade(n);
		}
	}while(n!=-1);
	cout<<"\nVector 1: ";
	objeto1.mostrar();
	cout<<"\nVector 2: ";
	objeto2.mostrar();
	cout<<endl<<endl;
	cout<<"La union es: ";
	objeto1.unioon(objeto1, objeto2).mostrar();
	cout<<endl<<endl;
	cout<<"La interseccion es: ";
	objeto1.interseccion(objeto1, objeto2).mostrar();
	cout<<endl<<endl;

	system("pause");
}
