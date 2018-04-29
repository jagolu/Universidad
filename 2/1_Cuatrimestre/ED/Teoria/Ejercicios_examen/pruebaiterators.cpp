#include <iostream>
#include <list>

using namespace std;

class Vector{
	private:
		list<int> v;
	public:
		void push_back(int n){
			v.push_back(n);
		}
		void pop_back(){
			v.pop_back();
		}
		
		class iterator{
			private:
				list<int>::iterator i;
				list<int> *v;
			public:
				iterator & operator++(){
					i++;
					return *this;
				}
				iterator operator++(int){
					iterator it2(*this);
					i++;
					return it2;
				}
				int & operator*(){
					return *i;
				}		
				bool & operator==(iterator & it){
					return *this==it;
				}
				bool  operator!=(const iterator & it)const{
					return i!=it.i;
				}
				iterator & operator=(const iterator & it){
					if(this!= &it){
						i=it.i;
						v=it.v;
					}
					return *this;
				}	
				friend class Vector;
		};
		iterator begin(){
			iterator i;
			i.i=v.begin();
			i.v=&v;
			return i;
		}
		iterator end(){
			iterator i;
			i.i=v.end();
			i.v=&v;
			return i;
		}
};
int main(){
	Vector v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	Vector::iterator ii=v.begin();
	Vector::iterator i2=v.end();
	i2++;
	++i2;
	if(ii!=i2) cout<<"chupaala\n";
	cout<<*ii;
	cout<<"aasdfasdf";
	for(Vector::iterator i=v.begin();i!=v.end();i++){
		cout<<*i<<" ";
	}
}
