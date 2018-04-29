#include <iostream>
#include <stack>

using namespace std;

void ordenar(stack<int> & p){
	stack<int>p2;
	p2.push(p.top());
	p.pop();
	while(!p.empty()){
		if(p.top()!=p2.top()){
			p2.push(p.top());
		}
		p.pop();
	}
	while(!p2.empty()){
		p.push(p2.top());
		p2.pop();
	}
}
int main(){
	stack<int> p;
	p.push(1);
	p.push(1);
	p.push(2);
	p.push(3);
	p.push(3);
	p.push(4);
	p.push(5);
	p.push(5);
	p.push(1);
	p.push(1);
	p.push(9);
	p.push(8);
	p.push(7);
	p.push(7);
	p.push(3);
	stack<int>p2;
	p2=p;
	while(!p2.empty()){
		cout<<p2.top()<<" ";
		p2.pop();
	}
	ordenar(p);
	cout<<endl<<endl;
	while(!p.empty()){
		cout<<p.top()<<" ";
		p.pop();
	}
}
