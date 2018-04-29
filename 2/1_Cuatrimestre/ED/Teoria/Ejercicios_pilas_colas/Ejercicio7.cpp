#include <iostream>
#include <stack>

using namespace std;

void insertar(stack<int> &p, int pos, int x){
	stack<int>p2;
	int i=0;
	while(!p.empty()){
		if(i==pos){
			p2.push(x);
			p2.push(p.top());
		}
		else{
			p2.push(p.top());
		}
		p.pop();
		i++;
	}
	while(!p2.empty()){
		p.push(p2.top());
		p2.pop();
	}
}
	
	
	
	
	
	
	
