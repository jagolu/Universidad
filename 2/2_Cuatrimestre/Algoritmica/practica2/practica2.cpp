#include <iostream>
#include <vector>

using namespace std;


struct Objeto{
	float peso, beneficio;
};

int seleccionar(const vector<Objeto> & objs, const vector<double> & x){
	int posMax=0;
	double valoracionPosMax;
	while(x[posMax]!=0) posMax++;
	valoracionPosMax=objs[posMax].beneficio/objs[posMax].peso;
	for(int i=posMax+1;i<objs.size();i++){
		double estaValoracion=objs[i].beneficio/objs[i].peso;
		if(x[i]==0 && estaValoracion>valoracionPosMax){
			posMax=i;
		}
	}
	return posMax;
}

void Mochila(int m, const vector<Objeto> & objs, vector<double> & x){
	for(int i=0;i<objs.size();i++){
		x.push_back(0);
	}
	double pesoAct=0;
	while(pesoAct<m){
		int i=seleccionar(objs, x);
		if( pesoAct+objs[i].peso<=m){
			x[i]=1;
			pesoAct+=objs[i].peso;
		}
		else{
			x[i]=(m-pesoAct)/objs[i].peso;
			pesoAct=m;
		}
	}
}

int main(){
	int m;
	double peso, beneficio;
	vector<Objeto> objs;
	
	cout<<"Introduzca el peso de la mochila: ";
	cin>>m;
		
	for(int i=0;i<5;i++){
		cout<<"Introduzca el peso del objeto "<<i<<": ";
		cin>>peso;
		cout<<"Introduzca el beneficio del objeto "<<i<<": ";
		cin>>beneficio;
		Objeto x;
		x.peso=peso;
		x.beneficio=beneficio;
		objs.push_back(x);
	}
	vector<double> x;
	Mochila(m,objs,x);
	double beneficioTotal=0;
	for(int i=0;i<objs.size();i++){
		cout<<"Del objeto "<<i<<" (peso "<<objs[i].peso<<", beneficio "<<objs[i].beneficio<<") se ha cogido un "<<x[i]<<" del objeto\n";
		beneficioTotal+=objs[i].beneficio*x[i];
	}
	cout<<"\nEl beneficio total obtenido es: "<<beneficioTotal<<endl;
	
}

