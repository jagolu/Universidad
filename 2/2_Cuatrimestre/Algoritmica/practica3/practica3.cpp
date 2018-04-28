#include <iostream>
#include <vector>
using namespace std;

struct Objeto{
	int id;
	int peso, beneficio;
};

int maximo(int a, int b){
	if(a>b) return a;
	else return b;
}

vector<int> Mochila(const vector<Objeto> & objs, int m){
	vector<int> solucion;
	int tabla[objs.size()+1][m+1];
	for(int i=0;i<=m;i++) tabla[0][i]=0;
	for(int i=0;i<=objs.size();i++) tabla[i][0]=0;

	for(int i=1;i<=objs.size();i++){
		for(int j=1;j<m+1;j++){
			if((j-objs[i-1].peso)<0){
				tabla[i][j]=tabla[i-1][j];
			}
			else{
				tabla[i][j]=max(tabla[i-1][j], (objs[i-1].beneficio + tabla[i-1][j-objs[i-1].peso]));
			}
		}
	}

	int j=m;
	for(int i=objs.size();i>=1;i--){
		if(tabla[i][j]==tabla[i-1][j]);//solucion.push_back(0);
		else{
			solucion.push_back(objs[i-1].id);
			j-=objs[i-1].peso;
		}
	}

	cout<<endl<<endl;
	for(int i=0;i<objs.size()+1;i++){
		for(int j=0;j<=m;j++){
			cout<<tabla[i][j]<<" ";
		}
		cout<<endl;
	}
	return solucion;
}
int main(){
	int m;
	int peso, beneficio;
	vector<Objeto> objs;
	
	cout<<"Introduzca el peso de la mochila: ";
	cin>>m;
		
	for(int i=0;i<4;i++){
		cout<<"Introduzca el peso del objeto "<<i<<": ";
		cin>>peso;
		cout<<"Introduzca el beneficio del objeto "<<i<<": ";
		cin>>beneficio;
		Objeto x;
		x.peso=peso;
		x.beneficio=beneficio;
		x.id=i;
		objs.push_back(x);
	}
	int beneficioTotal=0, pesoTotal=0;
	vector<int> solution=Mochila(objs, m);
	for(int i=0;i<solution.size();i++){
		cout<<"El objeto con peso "<<objs[solution[i]].peso<<" y beneficio "<<objs[solution[i]].beneficio<<" ha sido cogido\n";
		beneficioTotal+=objs[solution[i]].beneficio;
		pesoTotal+=objs[solution[i]].peso;
	}
	cout<<"Peso usado: "<<pesoTotal<<endl<<"Beneficio obtenido: "<<beneficioTotal<<endl;
}
