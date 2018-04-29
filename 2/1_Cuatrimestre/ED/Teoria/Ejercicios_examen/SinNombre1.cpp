#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
	int a=10;
	stringstream ss;
	ss<<a;
	string str=ss.str();
	cout<<str<<endl;
}
