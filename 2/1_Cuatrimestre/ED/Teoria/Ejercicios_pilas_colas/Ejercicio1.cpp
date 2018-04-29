#include <iostream>
#include <stack>

using namespace std;

void funcion(stack<int> &pila, int x, int y){
	stack<int> pila2;
	stack<int> pila3;
	pila2=pila;
	while(!pila2.empty()){
		if(pila2.top()==x){
			pila3.push(y);
		}
		else{
			pila3.push(pila2.top());
		}
		pila2.pop();
	}
	while(!pila3.empty()){
		pila2.push(pila3.top());
		pila3.pop();
	}
	pila=pila2;
}
