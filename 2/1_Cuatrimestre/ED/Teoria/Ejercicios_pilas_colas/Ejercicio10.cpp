#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

bool funcion(string s){
	stack<char>a;
	queue<char>b;
	for(int i=0;i<s.size();i++){
		a.push(s[i]);
		b.push(s[i]);
	}
	bool bien=true;
	while(!a.empty()){
		if(a.top()!=b.front()){
			bien=false;
		}
		a.pop();
		b.pop();
	}
	return bien;
}
