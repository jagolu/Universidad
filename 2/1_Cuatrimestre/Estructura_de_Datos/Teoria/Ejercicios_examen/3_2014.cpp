#include <iostream>
#include <map>
#include <list>
#include <string>

using namespace std;

class Traductor{
	private:
		map<string, list<string> >dicc;
	public:
		void insertar(string palabra_origen, list<string> trad){
			dicc[palabra_origen]=trad;
		}
		list<string> consultar(string palabra){
			list<string> res;
			for(list<string>::iterator i=dicc[palabra].begin();i!=dicc[palabra].end();i++){
				res.push_back(*i);
			}
			return res;
		}
		class iterador{
			private:
				map<string, list<string> >::iterator im;
				list<string>::iterator il;
				Traductor *t;
			public:
				iterador & operator++(){
					il++;
					if(il==im->second.end()){
						im++;
						if(im==t->dicc.end()){
							im=t->dicc.end();
							il=im->second.end();
						}
						else{
							il=im->second.begin();
						}
					}
				}
				pair<string, string> operator*(){
					pair<string, string> p;
					p.first=im->first;
					p.second=*il;
					return p;
				}
				bool & operator =(iterador & it){
					im=it.im;
					il=it.il;
					t=it.t;
				}
				bool operator ==(const iterador & it)const{
					if(im==it.im && il==it.il){
						return true;
					}
					else return false;
				}
				bool operator !=(const iterador & it)const{
					if(im==it.im && il==it.il) return false;
					else return true;
				}
					
				friend class Traductor;
		};
		iterador begin(){
			iterador sal;
			sal.im=dicc.begin();
			sal.il=dicc.begin()->second.begin();
			sal.t=this;
			return sal;
		}
		iterador end(){
			iterador sal;
			sal.im=dicc.end();
			sal.il=sal.im->second.end();
			sal.t=this;
			return sal;
		}
		friend class iterador;
};
int main(){
	Traductor t;
	string o;
	list<string> l;
	o="mierda";
	l.push_back("a");
	l.push_back("b");
	l.push_back("c");
	l.push_back("d");
	l.push_back("e");
	t.insertar(o,l);
	o="olala";
	l.clear();
	l.push_back("0");
	l.push_back("1");
	l.push_back("2");
	l.push_back("3");
	l.push_back("4");
	t.insertar(o,l);
	for(Traductor::iterador i=t.begin(); i!=t.end();++i){
		cout<<(*i).first<<" "<<(*i).second<<endl;
	}
}
