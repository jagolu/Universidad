#include <iostream>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

class tda{
public:
	bool operator()(const string & b1, const string & b2)const{
		int vocales1=0, vocales2=0;
		for(int i=0;i<b1.size();i++){
			if(b1[i]=='a' || b1[i]=='e' || b1[i]=='i' || b1[i]=='o' || b1[i]=='u'){
				vocales1++;
			}
		}
		for(int i=0;i<b2.size();i++){
			if(b2[i]=='a' || b2[i]=='e' || b2[i]=='i' || b2[i]=='o' || b2[i]=='u'){
				vocales2++;
			}
		}
		return vocales1>vocales2 || (vocales1==vocales2 && b1<b2);
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
	
