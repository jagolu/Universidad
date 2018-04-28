#include <iostream>
using namespace std;
struct Celda{
	int dato;
	Celda *sig;
};

void Insertar(Celda* &c, int nuevo_dato){
		int pos=0;
		Celda* c2;
		c2=c;
		bool llego=false;
		while(c2!=0 && llego==false){
		
			c2=c2->sig;
			cout<<pos<<endl;
			pos++;
			if(c2->dato==nuevo_dato) llego=true;
			if(c2->dato>nuevo_dato) llego=true;
		}
		Celda *q, *t;
		int i;
		q=new Celda;
		q->dato=nuevo_dato;
		if(pos==1 || c==0){
			q->sig=c;
			c=q;
		}
		else{
			t=c;
			for(i=1;t!=0;i++){
				if(i==pos){
					q->sig=t->sig;
					t->sig=q;
				}
				t=t->sig;
			}
		}
}
void add(Celda* &c, int dd){
	Celda *c2;
	c2=new Celda;
	c2->dato=dd;
	c2->sig=c;
	c=c2;
}
void Eliminar(Celda* &c){
	if(c!=0){
		Celda *c2;
		c2=c->sig;
		delete c;
		c=c2;
	}
}
void mostrar(Celda* l){
	while(l!=0){
		cout<<l->dato<<" ";
		l=l->sig;
	}
}
int main(){
	int n;
	Celda *l=0;
	for(int i=0;i<5;i++){
		cin>>n;
		add(l,n);
	}
	mostrar(l);
	for(int i=0;i<3;i++){
	cout<<"Posicion a mostrar: ";
	cin>>n;
	Insertar(l,n);
	while(l!=0){
		cout<<l->dato<<" ";
		l=l->sig;
	}
}
}
	
	
