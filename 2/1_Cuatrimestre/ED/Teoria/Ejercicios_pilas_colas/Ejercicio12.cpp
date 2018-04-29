#include <iostream>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

class tda{
public:
	bool operator()(const string & b1, const string & b2)const{
		return b1.size()>b2.size() || (b1.size()==b2.size() && b1<b2);
	}	
};
int main(){
	typedef set<string, tda> CadenaSet;
	CadenaSet coll;
	for(int i=0;i<5;i++){
		string b;
		cin>>b;
		coll.insert(b);
	}
	cout<<"set: "<<endl;
	CadenaSet::iterator pos;
	for(pos=coll.begin(); pos!=coll.end();++pos){
		cout<<*pos<<endl;
	}
}
