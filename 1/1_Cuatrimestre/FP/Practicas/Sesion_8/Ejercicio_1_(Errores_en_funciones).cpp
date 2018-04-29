int ValorAbsoluto (int entero) {
	if (entero < 0)
		entero = -entero;
	else
		return entero;
}
/*El error esta en que no se han puesto las llaves del if y del else
y tampoco se ha asignado un return al if*/

void Imprime(double valor) {
double valor;
cout << valor;
}
/*No se ha asignado un return, y el cout tampoco se imprimira en 
pantalla*/
void Cuadrado (int entero) {
return entero*entero;
}
/*Primero se deveria hacer la operacion en una variable aparte
y asignar el return a esa variable*/
bool EsPositivo(int valor) {
if (valor > 0)
return true;
}
/*Faltan las llaves del if*/
