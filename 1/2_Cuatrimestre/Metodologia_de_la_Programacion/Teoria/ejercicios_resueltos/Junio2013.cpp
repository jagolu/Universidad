#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <fstream>
using namespace std;
class BigInt{
private:
	int *n;
	int longitud;
public:
	BigInt(){
		n=0;
		longitud=0;
	}
	~BigInt(){
		delete [] n;
	}
	BigInt(const char a[]){
		longitud=strlen(a);
		n=new int[longitud];
		for(int i=0;i<longitud;i++){
			if(a[longitud-1-i]=='0') n[i]=0;
			else if(a[longitud-1-i]=='1') n[i]=1;
			else if(a[longitud-1-i]=='2') n[i]=2;
			else if(a[longitud-1-i]=='3') n[i]=3;
			else if(a[longitud-1-i]=='4') n[i]=4;
			else if(a[longitud-1-i]=='5') n[i]=5;
			else if(a[longitud-1-i]=='6') n[i]=6;
			else if(a[longitud-1-i]=='7') n[i]=7;
			else if(a[longitud-1-i]=='8') n[i]=8;
			else if(a[longitud-1-i]=='9') n[i]=9;
		}
	}
	BigInt(unsigned int& a){
		unsigned int b=a;
		longitud=0;
		while(b!=0){
			b=b/10;
			longitud++;
		}
		n=new int[longitud];
		for(int i=0;i<longitud;i++){
			n[i]=a%10;
			a=a/10;
		}
	}
	BigInt(const BigInt& b){
		longitud=b.longitud;
		n=new int[longitud];
		for(int i=0;i<longitud;i++){
			n[i]=b.n[i];
		}
	}
	BigInt& operator=(const BigInt& b){
		if(&b!=this){
			delete [] this->n;
			this->longitud=b.longitud;
			this->n=new int[this->longitud];
			for(int i=0;i<this->longitud;i++){
				this->n[i]=b.n[i];
			}
		}
		return *this;
	}
	BigInt operator+(const BigInt& b){
		BigInt n3;
		if(this->longitud==b.longitud){
			n3.longitud=this->longitud;
			n3.n=new int[this->longitud];
		}
		else if(this->longitud>b.longitud){
			n3.longitud=this->longitud;
			n3.n=new int[this->longitud];
		}
		else{
			n3.longitud=b.longitud;
			n3.n=new int[b.longitud];
		}
		for(int i=0;i<n3.longitud;i++){
			n3.n[i]=0;
		}
		for(int i=0;i<this->longitud;i++){
			n3.n[i]=n3.n[i]+this->n[i];
		}
		for(int i=0;i<b.longitud;i++){
			n3.n[i]=n3.n[i]+b.n[i];
		}
		for(int i=0;i<n3.longitud-1;i++){
			int aa=n3.n[i];
			n3.n[i]=n3.n[i]%10;
			n3.n[i+1]=n3.n[i+1]+(aa/10);
		}
		bool terminado=false;
		while(terminado==false){
			if(n3.n[n3.longitud-1]>9){
				int *r=new int[n3.longitud+1];
				for(int i=0;i<n3.longitud;i++){
					r[i]=n3.n[i];
				}
				r[n3.longitud]=0;
				int rr=r[n3.longitud-1];
				r[n3.longitud-1]=r[n3.longitud-1]%10;
				r[n3.longitud]=r[n3.longitud]+rr/10;
				delete [] n3.n;
				n3.n=r;
				n3.longitud++;
			}
			else terminado=true;
		}	
		return n3;
	}
	friend ostream& operator<<(ostream& os, BigInt& b);
};
ostream& operator<<(ostream& os, BigInt& b){
	for(int i=b.longitud-1;i>=0;i--){
		os<<b.n[i];
	}
	return os;
}
istream& operator>>(istream& is, BigInt& b){
	char a[100];
	is.getline(a,100);
	BigInt b2(a);
	b=b2;
	return is;
}
int main(int argc, char* argv[]){
	if(argc==2){
		ifstream fichero(argv[1]);
		if(fichero){
			BigInt a1;
			fichero>>a1;
			while(!fichero.eof()){
				BigInt a2;
				fichero>>a2;
				a1=a1+a2;
			}
			cout<<a1<<endl;
		}
		else cout<<"Introduzca un fichero existente\n";
	}
	else cout<<"Introduzca como argumento un fichero\n";
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
