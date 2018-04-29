/*10. Una compa��a a�rea establece el precio del billete como sigue: en primer lugar se fija
una tarifa base de 150 euros, la misma para todos los destinos. Si el destino est� a
menos de 200 kil�metros, el precio final es la tarifa inicial. Para destinos a m�s de 200
Km, se suman 10 c�ntimos por cada kil�metro de distancia al destino (a partir del Km
200).
	En una campa�a de promoci�n se va a realizar una rebaja lineal de 15 euros a todos
los viajes. Adem�s, se pretenden a�adir otras rebajas y se barajan las siguientes
alternativas de pol�ticas de descuento:
		a) Una rebaja del 3% en el precio final, para destinos a m�s de 600Km.
		b) Una rebaja del 4% en el precio final, para destinos a m�s de 1100Km. En este
caso, no se aplica el anterior descuento.
		c) Una rebaja del 5% si el comprador es cliente previo de la empresa.
	Cread un programa para que lea el n�mero de kil�metros al destino y si el billete
corresponde a un cliente previo de la empresa. Calcular el precio final del billete con
las siguientes pol�ticas de descuento:
		 Aplicando c) de forma adicional a los descuentos a) y b)
		 Aplicando c) de forma exclusiva con los anteriores, es decir, que si se aplica c),
no se aplicar�a ni a) ni b)*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int tarifa=150-15, distancia, extradistancia;
	double extraprecio,precio1, precio11, precio12, preciocliente, preciocliente1;
	char cliente;
	
	cout<<"Introduzca la distancia de su viaje: ";
	cin>>distancia;
	cout<<"�Es usted cliente previo? (s/n) ";
	cin>>cliente;

	extradistancia=distancia-200;
	extraprecio=extradistancia*0.1;
	precio1=tarifa+extraprecio;
	
	if(cliente=='n'){ /*Aqui damos la opcion de que no sea cliente previo*/
		if(200<distancia){ /*Aqui damos la segunda opcion (que la distancia del que no es cliente previo sea superior a 200 km)*/
				if(200<distancia && distancia<=1100){ /*Para aplicar las dos tarifas las dividiremos en dos distancias (esta primera, entre 200 y 1100 km)*/
					if(200<distancia && distancia<=600){ /*Aqui la distancia estara entre 200 y 600 km (donde no aplicamos ninguna tarifa)*/
						cout<<"Su precio es: " <<precio1 <<" euros" <<endl;
					}
					else{ /*Aqui la distancia estara entre 600 y 1100 km, donde aplicaremos la primera tarifa*/ 
						precio11=precio1-(precio1*0.03);
						cout<<"Su precio es: " <<precio11 <<" euros" <<endl;
					}
				}
				else{ /*Para aplicar las dos tarifas las dividiremos en dos distancias (esta segunda, superior a 1100 km [donde aplicaremos la segunda tarifa])*/
					precio12=precio1-(precio1*0.04);
					cout<<"Su precio es: " <<precio12 <<" euros" <<endl;
				}
			}
		else{ /*Aqui es para cuando la distancia es inferior a 200 km*/
			cout<<"Su precio es: " <<tarifa <<" euros" <<endl;
		}
	}
	else{/*Aqui damos la opcion contraria al primer if (aqui decimos que si es cliente previo)*/
		if(200<distancia){ /*Aqui es para cuando el viaje del cliente previo es superior a 200 km*/
		preciocliente=precio1-(precio1*0.05);
		cout<<"Su precio por se cliente es: " <<preciocliente <<" euros" <<endl;
		}
		else{ /*Aqui se da la condicion de que la distancia del cliente previo sea menor que 200 km*/
		preciocliente1=tarifa-(tarifa*0.05);
		cout<<"Su precio es: " <<preciocliente1 <<" euros" <<endl;
		}
	}	
	
	system("pause");
}
