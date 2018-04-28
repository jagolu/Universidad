#include <iostream>
#include <stack>

using namespace std;

void Reemplazar(stack<int>& p, const int& nuevo, const int& viejo){
	stack<int> p2;
	while(!p.empty()){
		if(p.top()==viejo){
			p2.push(nuevo);
		}
		else{
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
	stack<int>p;
	p.push(1);
	p.push(4);
	p.push(1);
	p.push(2);
	p.push(6);
	p.push(1);
	p.push(5);
	stack<int>p2;
	p2=p;
	while(!p2.empty()){
		cout<<p2.top()<<" ";
		p2.pop();
	}
	Reemplazar(p,9,1);
	cout<<endl<<endl;
	while(!p.empty()){
		cout<<p.top()<<" ";
		p.pop();
	}
}
