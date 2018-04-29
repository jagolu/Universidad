#include <iostream>
#include <string>

using namespace std;

class login{
private:
	int n;
public:
	void login2(int n2){
		n=n2;
	}
	int longitud(string nombre){
		return nombre.size();
	}
	string login_automatico(string nombre_completo){
		string login;
		int aniadidos=0;
		for(int i=0;i<longitud(nombre_completo);i++){
			if(nombre_completo[i]==' '){
				aniadidos=0;
			}
			else if(aniadidos<n){
				login.push_back(tolower(nombre_completo[i]));
				aniadidos++;
			}
		}
		return login;
	}
		
};

int main(){
	string cadena;
	login login1;
	int n;
	char a;
	cout<<"Introduzca su nombre: ";
	getline(cin, cadena);
	cout<<"Introduzca el numero: ";
	cin>>n;
	login1.login2(n);
	cout<<login1.login_automatico(cadena);
}


	
