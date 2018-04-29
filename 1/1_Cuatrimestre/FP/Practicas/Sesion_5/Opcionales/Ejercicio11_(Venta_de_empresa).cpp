/*Una empresa que tiene tres sucursales decide llevar la contabilidad de las ventas
de sus productos a lo largo de una semana. Para ello registra cada venta con
tres números, el identificador de la sucursal (1,2 ó 3), el código del producto codificado
como un carácter (a, b ó c) y el número de unidades vendidas. Diseñar
un programa que lea desde el teclado una serie de registros compuestos por
sucursal, producto, unidades y diga cuál es la sucursal que más productos
ha vendido. La serie de datos termina cuando la sucursal introducida vale -1.*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int sucursal;
	char producto;
	int ventas, ventas_uno_a=0, ventas_uno_b=0, ventas_uno_c=0, ventas_dos_a=0, ventas_dos_b=0, ventas_dos_c=0, ventas_tres_a=0, ventas_tres_b=0, ventas_tres_c=0;
	int total_uno, total_dos, total_tres;
		
	cout<<"Cuando desee parar de introducir los datos introduzca: sucursal:-1." <<endl;
	do{ /*Con este do creamos el bucle*/
		cout<<"Introduzca el numero de la sucursal (1/2/3): ";
		cin>>sucursal;
		if(sucursal!=-1){ /*Ponemos la condicion para que solo acepte las sucursales distintas de -1*/
			cout<<"Introduzca el codigo del producto (a/b/c): ";
			cin>>producto;
			cout<<"Introduzca el numero de unidades vendidas del producto elegido: ";
			cin>>ventas;
			if(sucursal==1){ /*Este if es para la primera sucursal*/
				if(producto=='a'){ /*Aqui vamos almacenando las ventas del producto a de la sucursal 1*/
						ventas_uno_a=ventas_uno_a+ventas;
				}
				else{
					if(producto=='b'){
						ventas_uno_b=ventas_uno_b+ventas; /*Aqui vamos almacenando las ventas del producto b de la sucursal 1*/
					}
					else{
						ventas_uno_c=ventas_uno_c+ventas; /*Aqui vamos almacenando las ventas del producto c de la sucursal 1*/
					}
				}
				total_uno=ventas_uno_a+ventas_uno_b+ventas_uno_c; /*Aqui sumamos los productos de la sucursal 1*/
			}
			else{ /*Este else es para las sucursales 2 y 3*/
				if(sucursal==2){ /*Aqui damos la condicion de la segunda sucursal*/
					if(producto=='a'){ /*Aqui vamos almacenando las ventas del producto a de la sucursal 2*/
						ventas_dos_a=ventas_dos_a+ventas;
					}
					else{
						if(producto=='b'){ /*Aqui vamos almacenando las ventas del producto b de la sucursal 2*/
							ventas_dos_b=ventas_dos_b+ventas;
						}
						else{
							ventas_dos_c=ventas_dos_c+ventas; /*Aqui vamos almacenando las ventas del producto c de la sucursal 3*/
						}
					}
				}
				else{ /*Aqui damos la condicion de la tercera sucursal*/
					if(producto=='a'){ /*Aqui vamos almacenando las ventas del producto a de la sucursal 3*/
						ventas_tres_a=ventas_tres_a+ventas;
					}
					else{
						if(producto=='b'){ /*Aqui vamos almacenando las ventas del producto b de la sucursal 3*/
							ventas_tres_b=ventas_tres_b+ventas;
						}
						else{ /*Aqui vamos almacenando las ventas del producto c de la sucursal 3*/
							ventas_tres_c=ventas_tres_c+ventas;
						}
					}
				}
			}		
			total_dos=ventas_dos_a+ventas_dos_b+ventas_dos_c; /*Aqui sumamos los productos de la segunda sucursal*/
			total_tres=ventas_tres_a+ventas_tres_b+ventas_tres_c; /*Aqui sumamos los productos de la tercera sucursal*/
		}
	}while(sucursal!=-1);{ /*Con este while hacemos que el bule pare cuando introduzcamos sucursale= -1*/
		cout<<"El total de la primera sucursal es: "<<total_uno<<endl<<"El total de la segunda sucursal es: "<<total_dos<<endl<<"El total de la tercera sucursal es: "<<total_tres<<endl;
		if(total_uno>total_dos && total_uno>total_tres){ /*Este if es para cuando la primera sucursal ha vendido mas productos*/
		cout<<"La primera sucursal ha vendido mas unidades con: "<<total_uno<<" unidades vendidas"<<endl;
		}
		else{ /*Este else seria para cuando la segunda o la tercera sucursal han vendido mas productos*/
			if(total_dos>total_uno && total_dos>total_tres){ /*If para mas productos vendidos de la segunda sucursal*/
			cout<<"La segunda sucursal ha vendido mas unidades con: "<<total_dos<<" unidades vendidas"<<endl;
			}
			else{ /*Else para mas productos vendidos de la tercera sucursal*/
				cout<<"La tercera sucursal ha vendido mas unidades con: "<<total_tres<<" unidades vendidas"<<endl;
			}
		}
	}
	system("pause");
}
