#include <iostream>
#include <vector>

using namespace std;

void intercalar(vector<int> &v, vector<pair<int,int> > pos){
	int tam=pos.size();	
	for(vector<pair<int,int> >::iterator i=pos.begin();i!=pos.end();i++){
		int n=0;
		vector<int>::iterator j=v.begin();
		for(;n!=(*i).first;j++){
			n++;
		}
		v.insert(j,(*i).second);
	}
}
