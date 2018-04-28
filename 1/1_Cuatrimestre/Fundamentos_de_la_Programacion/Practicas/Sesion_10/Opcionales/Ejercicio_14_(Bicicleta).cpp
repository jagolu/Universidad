/*Se quiere construir una clase para representar la tracci�n de una bicicleta, es decir, el
conjunto de estrella (engranaje delantero), cadena y pi��n (engranaje trasero). Supondremos
que la estrella tiene tres posiciones (numeradas de 1 a 3, siendo 1 la estrella
m�s peque�a) y el pi��n siete (numeradas de 1 a 7, siendo 1 el pi��n m�s grande).
La posici�n inicial de marcha es estrella = 1 y pi��n = 1.
La clase debe proporcionar m�todos para cambiar la estrella y el pi��n, sabiendo que
la estrella avanza o retrocede de 1 en 1 y los pi�ones cambian a saltos de uno o de
dos. Si ha llegado al l�mite superior (inferior) y se llama al m�todo para subir (bajar) la
estrella, la posici�n de �sta no variar�. Lo mismo se aplica al pi��n.
Cread un programa principal que lea desde un fichero externo los movimientos realizados
e imprima la situaci�n final de la estrella y pi��n. Los datos se leer�n en el
siguiente formato: tipo de plato (pi��n o estrella) seguido del tipo de movimiento. Para
codificar esta informaci�n se usar�n las siguientes letras: E indica una estrella, P un pi��n,
S para subir una posici�n, B para bajar una posici�n, T para subir dos posiciones
y C para bajar dos posiciones. T y C s�lo se aplicar�n sobre los pi�ones.
E S P S P S P S P C E S E B
En este ejemplo los movimientos ser�an: la estrella sube, el pi��n sube en tres ocasiones
sucesivas, el pi��n baja dos posiciones de golpe, la estrella sube y vuelve a
bajar. Supondremos siempre que la posici�n inicial de la estrella es 1 y la del pi��n 1.
As� pues, la posici�n final ser� Estrella=1 y Pi��n=2.
Mejorad la clase para que no permita cambiar la marcha (con la estrella o el pi��n)
cuando haya riesgo de que se rompa la cadena. Este riesgo se produce cuando la
marcha a la que queremos cambiar es de la siguiente forma:
 Estrella igual a 1 y pi��n mayor o igual que 5
 Estrella igual a 2 y pi��n o bien igual a 1 o bien igual a 7
 Estrella igual a 3 y pi��n menor o igual que 3*/
#include <iostream>
#include <cmath>

using namespace std;

class bicicleta{
private:
	static const int max=50;
	char vector[max];
	int total;
	int pinon;
	int estrella;
	int numorden;
public:
	bicicleta(){
		total=0;
		pinon=1;
		estrella=1;
		numorden=0;
	}
	void setpinon(int a){
		pinon=pinon+a;
	}
	void setestrella(int b){
		estrella=estrella+b;
	}
	int getpinon(){
		return pinon;
	}
	int getestrella(){
		return estrella;
	}
	void aa(char a1){
		vector[total]=a1;
		total++;
	}
	char orden(){
		char a1;
		a1=vector[numorden];
		return a1;
	}
	char orden2(){
		char a1A;
		a1A=vector[numorden+1];
		return a1A;
	}
	int bicicleta1(){
		char a2, a2A;
		a2=orden();
		a2A=orden2();
		//estrella
		if((a2=='E') && ((a2A=='S') || (a2A=='B'))){
			if(a2A=='S'){
				if(estrella<=2){
					setestrella(1);
				}
			}
			else if(a2A=='B'){
				if(estrella>=2){
					setestrella(-1);
				}
			}
		}
		//pinon
		else if(((a2=='P') || (a2A=='S')) || ((a2A=='B') || ((a2A=='T') || (a2A=='C')))){
			if(a2A=='S'){
				if(pinon<=6){
					setpinon(1);
				}
			}
			else if(a2A=='B'){
				if(pinon>=2){
					setpinon(-1);
				}
			}
			else if(a2A=='T'){
				if(pinon<=5){
					setpinon(2);
				}
			}
			else if(a2=='C'){
				if(pinon>=3){
					setpinon(-2);
				}
			}
		}
		numorden=numorden+2;
	}
};
int main(){
	char a, b, c;
	char d;
	bicicleta objeto;
	do{
		do{
			cout<<"Introduce la estrella (E) o el pinon (P): \n";
			cin>>a;
		}while(a!='E' && a!='P');
			objeto.aa(a);
		if(a=='E'){
			do{
				cout<<"Introduzca la orden \n    (S subir una posicion) \n    (B bajar una posicion) \n";
				cin>>b;
				if(((objeto.getestrella()==1) && (objeto.getpinon()>=5)) || ((objeto.getestrella()==2) && ((objeto.getpinon()==1) || (objeto.getpinon()==7))) || ((objeto.getestrella()==3) && (objeto.getpinon()<=3))){
					cout<<"Orden no valida. Riesgo de rotura de cadena"<<endl;
				}
			}while(b!='S' && b!='B');
			objeto.aa(b);
		}
		else{
			do{
				cout<<"Introduzca la orden \n    (S subir una posicion) \n    (B bajar una posicion) \n    (T subir dos posiciones) \n    (C bajar dos posiciones) \n";
				cin>>c;
			}while((c!='S' && c!='B') && ( c!='T' && c!='C'));
			objeto.aa(c);
		}
		objeto.bicicleta1();
		cout<<"<<�INTRODUCIR MAS ORDENES? (S/N)>>\n";
		cin>>d;
	}while(d!='N');
	cout<<"POSICION DE LA ESTRELLA----> "<<objeto.getestrella()<<endl;
	cout<<"POSICION DEL PINON---------> "<<objeto.getpinon()<<endl;
	system("pause");
}
	
	
