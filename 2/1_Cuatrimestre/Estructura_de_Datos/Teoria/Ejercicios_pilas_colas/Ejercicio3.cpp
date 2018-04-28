#include <iostream>
#include <stack>

using namespace std;

class cola{
private:
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
};
