#include <iostream>

using namespace std;

int main(){
	int n, a=0, b=0;
	
	do{
		cout<<"Introduzca el dorsal anotador: ";
		cin>>n;
		
		if(1<=n && n<=6){
			if(n==1 || n==2 || n==3){
				a=a+1;
			}
			else{
				b=b+1;
			}
		}
	}while(n!=-1);
	if(a<b || a>b){
		if(a<b){
			cout<<"El equipo A consiguio: "<<a<<" puntos"<<endl;
			cout<<"El equipo B consiguio: "<<b<<" puntos"<<endl;
			cout<<"Gano el equipo B"<<endl;
		}
		else{
			cout<<"El equipo A consiguio: "<<a<<" puntos"<<endl;
			cout<<"El equipo B consiguio: "<<b<<" puntos"<<endl;
			cout<<"Gano el equipo A"<<endl;
		}
	}
	else{
		cout<<"El equipo A consiguio: "<<a<<" puntos"<<endl;
		cout<<"El equipo B consiguio: "<<b<<" puntos"<<endl;
		cout<<"El equipo A y B han quedado en empate"<<endl;
	}
	system("pause");
}
