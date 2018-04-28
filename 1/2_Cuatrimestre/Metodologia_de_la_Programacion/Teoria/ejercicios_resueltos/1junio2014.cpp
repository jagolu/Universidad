#include <iostream>
using namespace std;
struct Lista{
	int n;
	Lista *sig;
};

Lista** Dividir(Lista* &l, const int& n){
	Lista **l2=new Lista*[0];
	Lista *aux;
	aux=l;
	int total=0;
	while(aux!=0){
		Lista **l3;
		l3=new Lista*[total+1];
		for(int i=0;i<total;i++){
			l3[i]=l2[i];
		}
		delete [] l2;
		l2=l3;
		for(int i=0;i<n && aux!=0;i++){
			l2[total]=aux;
			aux=aux->sig;
		}
		total++;
	}
	for(int i=0;i<3;i++){
		if(i==0 || i==1){
			for(int j=0;j<2;j++){
				cout<<l2[i].n;
				l2[i]=l2[i]->sig;
			}
		}
		else cout<<l2[i].n;
	}
	return l2;
}
void Add(Lista* &l, int dato){
	Lista *r;
	r=new Lista;
	r->n=dato;
	r->sig=l;
	l=r;
}
void Liberar(Lista* &l){
	while(l!=0){
		l=l->sig;
	}
}
void mostrar(Lista* l){
	while(l!=0){
		cout<<l->n<<" ";
		l=l->sig;
	}
}
int main(){
	int a;
	Lista *l=0;
	for(int i=0;i<5;i++){
		cin>>a;
		Add(l,a);
	}
	cout<<endl<<endl;
	mostrar(l);
	cout<<endl<<"Liberando..\n\n";
	Lista **p;
	p=Dividir(l,2);
/*	for(int i=0;i<3;i++){
		if(i==0 || i==1){
			for(int j=0;j<2;j++){
				cout<<p[i].n;
				p[i]=p[i]->sig;
			}
		}
		else cout<<p[i].n;
	}
	Liberar(l);
	mostrar(l);
	cout<<endl<<endl;*/
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
