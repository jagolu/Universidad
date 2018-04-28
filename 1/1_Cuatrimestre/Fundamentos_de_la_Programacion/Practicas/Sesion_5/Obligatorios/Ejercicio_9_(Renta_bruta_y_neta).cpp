/*Cread un programa que lea los datos fiscales da una persona, reajuste su renta bruta
según el criterio que se indica posteriormente e imprima su renta neta final.
	• La renta bruta es la cantidad de dinero íntegra que el trabajador gana.
	• La renta neta es la cantidad que le queda después de quitarle el porcentaje de
retención fiscal, es decir:
			Renta_neta = Renta_bruta - Renta_bruta * Retención / 100*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double renta_netaSAutonomo, renta_netaSPensionista, renta_neta_rentaBaja, renta_neta_casado, renta_neta_soltero;
	double renta_bruta; 
	double retencion_inicial, retencion_SAutonomo, retencion_SPensionista, retencion_NPensionista, retencion_rentaBaja, retencion_casado, retencion_soltero;
	char autonomo, pensionista, estado_civil;
	
	cout<<"¿Es usted autonomo? (s/n) " ;
	cin>>autonomo;
	cout<<"¿Es usted pensionista? (s/n) ";
	cin>>pensionista;
	cout<<"¿Cual es su estado civil? [soltero (s), casado(c)] ";
	cin>>estado_civil;
	cout<<"¿Cual es su renta bruta? ";
	cin>>renta_bruta;
	cout<<"¿Cual es la retencion inicial a aplicar? ";
	cin>>retencion_inicial;
	
	/*La modificiacion se hara de la siguiente forma:
		·Se baja un 3% la retencion fiscal a los autonomos
		·Para los no autonomos:
			-Se sube un 1% la retencion fiscal a todos los pensionistas
			-Al resto de trabajadores se le sube un 2% la retencion fiscal. Una vez hecha esta subida
			lineal del 2%, se le aplica (sobre el resultado anterior) las siguientes subidas
			adicionales, dependiendo de su estado civil y niveles de ingresos:
				*Se sube un 6% la retencion fiscal si la renta bruta es menor de 20.000 euros
				*Se sube un 8% la retencion fiscal a los casados con renta bruta superior a 20.000 euros
				*Se sube un 10% la retencion fiscal a los solteros con renta bruta superior a 20.000 euros*/
		/*
		Renta_neta = Renta_bruta - Renta_bruta * Retención / 100
		Nueva_retención = Antigua_retención + Antigua_retención * x / 100
		*/
	cout.precision(4);
	
	if(autonomo=='s'){ /* En este if damos la condicion de que sea autonomo. Y calcula su respectiva renta neta*/
		retencion_SAutonomo=retencion_inicial-(retencion_inicial*0.03);
		renta_netaSAutonomo=renta_bruta-(renta_bruta*(retencion_SAutonomo/100));
		cout<<"Su renta neta es: " <<renta_netaSAutonomo <<" euros" <<endl;
	}
	else{ /*Con este else damos la condicion contraria (que no sea autonomo)*/
		if(pensionista=='s'){ /*Dentro de la condicion de que no sea autonomo, damos la condicion de que sea pensionista. Y calculamos su renta neta.*/
			retencion_SPensionista=retencion_inicial+(retencion_inicial*0.01);
			renta_netaSPensionista=renta_bruta-(renta_bruta*(retencion_SPensionista/100));
			cout<<"Su renta neta es: " <<renta_netaSPensionista <<" euros" <<endl;
		}
		else{ /*Dentro de la condicion de que no sea autonomo, damos la condicion de que no sea pensionista. Y calculamos su retencion, que servira para las demas subcondiciones.*/
			retencion_NPensionista=retencion_inicial+(retencion_inicial*0.02);
			if(renta_bruta<20000){ /*Dentro de la condicion de que no sea autonomo y no sea pensionista, damos la condicion de que su renta sea inferior 
			a 20.000 euros. Y calculamos su renta neta*/
				retencion_rentaBaja=retencion_NPensionista+(retencion_NPensionista*0.06);
				renta_neta_rentaBaja=renta_bruta-(renta_bruta*(retencion_rentaBaja/100));
				cout<<"Su renta neta es: " <<renta_neta_rentaBaja <<" euros" <<endl;
			}
			else{ /*Dentro de la condicion de que no sea autonomo y no sea pensionista, damos la condicion de que su renta sea superior a 20.000 euros.*/
				if(estado_civil=='c'){ /*Dentro de la condicion de que no sea autonomo, no sea pensionista y su renta sea superior a 20.000 euros, damos la condicion de que 
				este casado. Y calculamos su renta neta.*/
					retencion_casado=retencion_NPensionista+(retencion_NPensionista*0.08);
					renta_neta_casado=renta_bruta-(renta_bruta*(retencion_casado/100));
					cout<<"Su renta neta es: " <<renta_neta_casado <<" euros" <<endl;
				}
				else{ /*Dentro de la condicion de que no sea autonomo, no sea pensionista y su renta sea superior a 20.000 euros, damos la condicion de que 
				este soltero. Y calculamos su renta neta*/
					retencion_soltero=retencion_NPensionista+(retencion_NPensionista*0.1);
					renta_neta_soltero=renta_bruta-(renta_bruta*(retencion_soltero/100));
					cout<<"Su renta es: " <<renta_neta_soltero <<" euros" <<endl;
				}
			}
		}
	}
	
	system("pause");
}
