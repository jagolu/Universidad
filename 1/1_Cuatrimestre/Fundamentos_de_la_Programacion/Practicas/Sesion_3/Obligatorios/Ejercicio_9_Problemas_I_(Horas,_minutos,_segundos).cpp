/*Este es un programa que a partir de unos valores de segundos, minutos y horas, nos lo pone en valores mas simples de dias, horas, minutos y segundos
	El programa necesita:
		El numero de horas (horas)
		El numero de minutos (minutos)
		El numero de segundos (segundos)*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int dias, horas, minutos, segundos, horas1, minutos1, segundos1;
	
	cout<<"Introduzca el numero de horas: " ;
	cin>> horas ;
	cout<<"Introduzca el numero de minutos: " ;
	cin>> minutos ;
	cout<<"Introduzca el numero de segundos: " ;
	cin>> segundos ;
	
	segundos1=segundos%60 ;/*Con esto conseguimos el resto de la division que son los segundos*/
	minutos1=(minutos+(segundos/60))%60;/*Con los minutos que ya teniamos y el cociente entero de la division de segundos entre 60, nos dara los minutos que tenemos*/
	horas1=(horas+(minutos+(segundos/60))/60)%24;/*Si en la division de antes, cogemos el cociente entero y cogemos el resto de divirla por 24 nos dara las horas que tenemos*/
	dias=(horas+(minutos+(segundos/60))/60)/24;/*Si en la division anterior, cogemos el cociente entero nos dara el numero de dias que tenemos*/
	
	cout<<dias <<"  dias  " <<horas1 <<"  horas  " <<minutos1 <<"  minutos  " <<segundos1 <<"  segundos" <<endl ;
	system("pause");
}
