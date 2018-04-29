#include <iostream>
#include <stack>

using namespace std;

class ventana{ //He usado la implementacion para que estas dos pilas se mostrasen como una cola. 
private:					//Lo veia asi mas sencillo de realizar.
	stack<int>a;
	stack<int>b;
public:
	void push(int n){
		a.push(n);
	}
	int front(){
		while(!a.empty()){
			b.push(a.top());
			a.pop();
		}
		int devolver=b.top();
		while(!b.empty()){
			a.push(b.top());
			b.pop();
		}
		return devolver;
	}
	void pop(){
		while(!a.empty()){
			b.push(a.top());
			a.pop();
		}
		b.pop();
		while(!b.empty()){
			a.push(b.top());
			b.pop();
		}
	}
	bool empty(){
		return a.empty();
	}
		
	void moverIzquierda(int indice){
		if(indice!=0 && indice>=0 && indice<a.size()){
			int posicion=a.size()-1-indice;
			int i=0;
			while(!a.empty()){
				if(i!=posicion){
					b.push(a.top());
				}
				else{
					int r=a.top();
					a.pop();
					b.push(a.top());
					b.push(r);
				}
				a.pop();
				i++;
			}
			while(!b.empty()){
				a.push(b.top());
				b.pop();
			}
		}
	}
	void moverDerecha(int indice){
		if(indice!=a.size()-1 && indice>=0 && indice<a.size()){
			int posicion=a.size()-1-indice;
			int i=0;
			while(!a.empty()){
				if(i!=posicion-1){
					b.push(a.top());
				}
				else{
					int r=a.top();
					a.pop();
					b.push(a.top());
					b.push(r);
				}
				a.pop();
				i++;
			}
			while(!b.empty()){
				a.push(b.top());
				b.pop();
			}
		}
	}
	void borrarElemento(int indice){
		if(indice>=0 && indice<a.size()){
			int posicion=a.size()-1-indice;
			int i=0;
			while(!a.empty()){
				if(i!=posicion){
					b.push(a.top());
				}
				a.pop();
				i++;
			}
			while(!b.empty()){
				a.push(b.top());
				b.pop();
			}
		}
	}
		
};
		
				
