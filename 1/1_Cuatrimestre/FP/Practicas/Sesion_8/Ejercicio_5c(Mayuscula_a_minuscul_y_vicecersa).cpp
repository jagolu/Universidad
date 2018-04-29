#include <iostream>

using namespace std;
char capitalizacion(char una_letra){
	char nuevaminus;
	int amplitud='a'-'A';
	if('A'<=una_letra && una_letra<='Z'){
		nuevaminus=una_letra+amplitud;
		return nuevaminus;
	}
	else{
		if('a'<=una_letra && una_letra<='z'){
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
		cout<<"La minuscula de "<<a<<" es: "<<nuevaletra<<endl;
	}
	else{
		if('a'<=a && a<='z'){
			cout<<"La letra "<<a<<" no es mayuscula ( "<<nuevaletra<<" )"<<endl;
		}
		else{
			cout<<"No es una letra ( "<<nuevaletra<<" )"<<endl;
		}
	}
	system("pause");
}
