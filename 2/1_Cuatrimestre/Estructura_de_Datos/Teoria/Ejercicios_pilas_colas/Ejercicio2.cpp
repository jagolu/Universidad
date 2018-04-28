#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool funcion(string s){
	stack<char>p;
	bool bien=true;
	for(int i=0;i<s.size();i++){
		if(s[i]=='(' || s[i]=='<' || s[i]=='{' || s[i]=='['){
			p.push(s[i]);
		}
		else if(!p.empty() && s[i]==')' && p.top()=='('){
			p.pop();
		}
		else if(!p.empty() && s[i]=='>' && p.top()=='<'){
			p.pop();
		}
		else if(!p.empty() && s[i]=='}' && p.top()=='{'){
			p.pop();
		}
		else if(!p.empty() && s[i]==']' && p.top()=='['){
			p.pop();
		}
		else if(s[i]==')' || s[i]=='>' || s[i]=='}' || s[i]==']' && p.empty()){
			bien=false;
		}
	}
	if(bien && p.empty()){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	string a;
	cin>>a;
	cout<<endl<<funcion(a)<<endl;
}
