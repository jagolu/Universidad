#include <iostream>
#include <queue>

using namespace std;

class pila{
private:
	queue<int>a;
	queue<int>b;
public:
	void push(int n){
		a.push(n);
	}
	int top(){
		return a.back();
	}
	bool empty(){
		return a.empty();
	}
	void pop(){
		while(!b.empty()){
			b.pop();
		}
		int c=a.size()-1;
		for(int i=0;i<c;i++){
			b.push(a.front());
			a.pop();
		}
		a.pop();
		while(!b.empty()){
			a.push(b.front());
			b.pop();
		}
	}
};
