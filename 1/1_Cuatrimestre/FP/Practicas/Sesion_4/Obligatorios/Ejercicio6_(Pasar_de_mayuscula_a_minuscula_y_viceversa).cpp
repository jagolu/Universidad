/*Queremos modificar el ejercicio 5 para leer un carácter letra_original desde teclado
y hacer lo siguiente:
 Si es una letra mayúscula, almacenaremos en la variable letra_convertida
la correspondiente letra minúscula.
 Si es una letra minúscula, almacenaremos en la variable letra_convertida
la correspondiente letra mayúscula.
 Si es un carácter no alfabético, almacenaremos el mismo carácter en la variable
letra_convertida*/
#include <iostream>

using namespace std;

int main(){
	char letra_original, letra_convertida, es_minuscula;
	
	cout<<"Introduce una caracter: ";
	cin>>letra_original;
	
	if(('A'<=letra_original && letra_original<='Z') || ('a'<=letra_original && letra_original<='z')){ /*Aqui escoremos si es una letra o no*/
		if('A'<=letra_original && letra_original<='Z'){ /*Con este if sabremos si es una letra mayuscula*/
			es_minuscula=letra_original+' ';
			cout<<"La letra es mayuscula. La respectiva letra minuscula es: " <<es_minuscula <<endl;
		}
		else{ /*Con este else veremos si es una letra minuscula*/
			letra_convertida=letra_original-' ';
			cout<<"La letra es minuscula. Su respectiva letra mayuscula es: " <<letra_convertida <<endl;
		}
	}
	else{ /*Con este else sabremos si es un caracter*/
		cout<<"Es un caracter" <<endl;
	}
	system("pause");
}
