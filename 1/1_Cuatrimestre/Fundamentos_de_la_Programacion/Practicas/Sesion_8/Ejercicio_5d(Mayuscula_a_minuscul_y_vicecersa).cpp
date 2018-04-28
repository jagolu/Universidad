#include <iostream>

using namespace std;
char capitalizacion(char una_letra){
	char nuevaminus;
	char nuevamayus;
	if('A'<=una_letra && una_letra<='Z'){
		nuevaminus=una_letra+' ';
		return nuevaminus;
	}
	else{
		if('a'<=una_letra && una_letra<='z'){
			nuevamayus=una_letra-' ';
			return nuevamayus;
		}
		else{
			return una_letra;
		}
	}
}
int main(){
	char a;
	char nuevaletra;
	
	cout<<"Introduzca una letra mayuscula: ";
	cin>>a;
	nuevaletra=capitalizacion(a);
	if('A'<=a && a<='Z'){
		cout<<"La minuscula de "<<a<<" es: "<<nuevaletra<<endl;
	}
	else{
		if('a'<=a && a<='z'){
			cout<<"La mayuscula de "<<a<<" es: "<<nuevaletra<<endl;
		}
		else{
			cout<<"No es una letra ( "<<nuevaletra<<" )"<<endl;
		}
	}
	system("pause");
}
