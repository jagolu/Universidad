#include <iostream>

using namespace std;
char capitalizacion(char una_letra){
	char nuevamayus;
	if('a'<=una_letra && una_letra<='z'){
		nuevamayus=una_letra-' ';
		return nuevamayus;
	}
	else{
		if('A'<=una_letra && una_letra<='Z'){
			return una_letra;
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
		cout<<"La letra no es minuscula ( "<<nuevaletra<<" )"<<endl;
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
