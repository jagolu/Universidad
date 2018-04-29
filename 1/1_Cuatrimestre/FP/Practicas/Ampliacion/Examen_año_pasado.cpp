#include <iostream>

using namespace std;

int main(){
	char ab, ac, ba, bc, ca, cb;
	int a, b, c;
	
	a=0;
	b=0;
	c=0;
	
	cout<<"¿Quien gano en a vs b? (a/b/e): ";
	cin>>ab;
	cout<<"¿Quien gano en a vs c? (a/c/e): ";
	cin>>ac;
	cout<<"¿Quien gano en b vs a? (b/a/e): ";
	cin>>ba;
	cout<<"¿Quien gano en b vs c? (b/c/e): ";
	cin>>bc;
	cout<<"¿Quien gano en c vs a? (c/a/e): ";
	cin>>ca;
	cout<<"¿Quien gano en c vs b? (c/b/e): ";
	cin>>cb;
	
	if(ab=='a'){
		a=a+3;
	}
	else{
		if(ab=='b'){
			b=b+3;
		}
		else{
			a=a+1;
			b=b+1;
		}
	}
	if(ac=='a'){
		a=a+3;
	}
	else{
		if(ac=='c'){
			c=c+3;
		}
		else{
			a=a+1;
			c=c+1;
		}
	}
	if(ba=='b'){
		b=b+3;
	}
	else{
		if(ba=='c'){
			c=c+3;
		}
		else{
			b=b+1;
			c=c+1;
		}
	}
	if(bc=='b'){
		b=b+3;
	}
	else{
		if(bc=='c'){
			c=c+3;
		}
		else{
			b=b+1;
			c=c+1;
		}
	}
	if(ca=='c'){
		c=c+3;
	}
	else{
		if(ca=='a'){
			a=a+3;
		}
		else{
			c=c+1;
			a=a+1;
		}
	}
	if(cb=='c'){
		c=c+3;
	}
	else{
		if(cb=='b'){
			b=b+3;
		}
		else{
			c=c+1;
			b=b+1;
		}
	}
	if(a>=b && a>=c){
		if(b>=c){
			cout<<"1º a= "<<a<<" puntos"<<endl<<"2º b= "<<b<<" puntos"<<endl<<"3º c= "<<c<<" puntos"<<endl;
		}
		else{
			cout<<"1º a= "<<a<<" puntos"<<endl<<"2º c= "<<c<<" puntos"<<endl<<"3º b= "<<b<<" puntos"<<endl;
		}
	}
	if(b>a && b>=c){
		if(a>=c){
			cout<<"1º b= "<<b<<" puntos"<<endl<<"2º a= "<<a<<" puntos"<<endl<<"3º c= "<<c<<" puntos"<<endl;
		}
		else{
			cout<<"1º b= "<<b<<" puntos"<<endl<<"2º c= "<<c<<" puntos"<<endl<<"3º a= "<<a<<" puntos"<<endl;
		}
	}
	if(c>a && c>b){
		if(a>=b){
			cout<<"1º c= "<<c<<" puntos"<<endl<<"2º a= "<<a<<" puntos"<<endl<<"3º b= "<<b<<" puntos"<<endl;
		}
		else{
			cout<<"1º c= "<<c<<" puntos"<<endl<<"2º b= "<<b<<" puntos"<<endl<<"3º a= "<<a<<" puntos"<<endl;
		}
	}
	
	system("pause");
}
