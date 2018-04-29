#include <iostream>
using namespace std;
class SecuenciaEnteros{
private:
	static const int max=100;
	int vector[max];
	int total;
public:
	SecuenciaEnteros()
		:total(0)
	{	}
	void aniade(int dato){
		if(dato!=-1 && total<max){
			vector[total]=dato;
			total++;
		}
	}
	int total_utilizados(){
		return total;
	}
	int elemento(int indice){
		return vector[indice];
	}
	void cambia_total(int nuevo_total){
		total=nuevo_total;
	}
	SecuenciaEnteros Topk(int k){
		SecuenciaEnteros original;
		SecuenciaEnteros ordenado;
		for(int i=0;i<total;i++){
			original.aniade(vector[i]);
		}
		for(int i=0;i<total;i++){
			int a, b, indice=-1;
			a=vector[i];
			b=vector[i+1];
			for(int j=i+1;j<total;j++){
				if(a<=vector[j] && b<=vector[j]){
					b=vector[j];
					indice=j;
				}
			}
			if(indice!=-1){
				a=vector[i];
				b=vector[indice];
				vector[i]=b;
				vector[indice]=a;
			}
		}
		for(int i=0;i<total;i++){
			ordenado.aniade(vector[i]);
		}
		for(int i=0;i<total;i++){
			vector[i]=original.elemento(i);
		}
		if(k>=total){
			ordenado.cambia_total(total);
		}
		else{
			ordenado.cambia_total(k);
		}
		return ordenado;
	}
};
int main(){
	int a;
	SecuenciaEnteros objeto;
	cout<<"Introduzca los elementos del vector:\n";
	do{
		cin>>a;
		objeto.aniade(a);
	}while(a!=-1);
	for(int i=0;i<objeto.total_utilizados();i++){
		cout<<objeto.elemento(i)<<" ";
	}
	cout<<"Introduzca el elemento k: ";
	cin>>a;
	for(int i=0;i<objeto.Topk(a).total_utilizados();i++){
		cout<<objeto.Topk(a).elemento(i)<<" ";
	}
	system("pause");
}
