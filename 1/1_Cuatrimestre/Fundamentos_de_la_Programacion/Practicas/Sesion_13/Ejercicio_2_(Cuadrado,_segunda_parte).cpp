/* Implemente un método para determinar si un cuadrado tiene mayor área que otro.
 Implemente un método para determinar si un cuadrado contiene a otro. Un cuadrado
C1 determinado por la esquina (x1; y1) y la longitud l1 contiene a otro cuadrado
C2 dado por (x2; y2) y l2 si se cumple que x2 >= x1 y x2+l2 <= x1+l1
y y2 >= y1 y y2 + l2 <= y1 + l1*/
#include <iostream>
#include <cmath>

using namespace std;

class punto2d{
private:
	double abcisa;
	double ordenada;
public:
	punto2d(double abcisapunto, double ordenadapunto)
		:abcisa(abcisapunto),
		ordenada(ordenadapunto)
	{  }
	void setcoordenadas(double abcisapunto, double ordenadapunto){
		abcisa=abcisapunto;
		ordenada=ordenadapunto;
	}
	double Abcisa(){
		return abcisa;
	}
	double Ordenada(){
		return ordenada;
	}
};
class segmentodirigido{
private:
	double x1, y1, x2, y2;
public:
	segmentodirigido(double origenAbcisa, double origenOrdenada, double finalAbcisa, double finalOrdenada)
		:x1(origenAbcisa),
		y1(origenOrdenada),
		x2(finalAbcisa),
		y2(finalOrdenada)
	{  }
	void setcoordenadas(double origenAbcisa, double origenOrdenada, double finalAbcisa, double finalOrdenada){
		x1=origenAbcisa;
		y1=origenOrdenada;
		x2=finalAbcisa;
		y2=finalOrdenada;	
	}
	double origenAbcisa(){
		return x1;
	}
	double origenOrdenada(){
		return y1;
	}
	double finalAbcisa(){
		return x2;
	}
	double finalOrdenada(){
		return y2;
	}
	double longitud(){
		double resta_abscisas = x2-x1;
		double resta_ordenadas = y2-y1;
		return sqrt(resta_abscisas*resta_abscisas+resta_ordenadas*resta_ordenadas);
	}
	void trasladarHorizontal(double unidades){
		x1=x1+unidades;
		x2=x2+unidades;
	}
	void trasladaVertical(double unidades){
		y1=y1+unidades;
		y2=y2+unidades;
	}
	void traslada(double enHorizontal, double enVertical){
		x1=x1+enHorizontal;
		x2=x2+enHorizontal;
		y1=y1+enVertical;
		y2=y2+enVertical;
	}
};
class circunferencia{
private:
	double centro_x, centro_y, radio;
public:
	static const double PI=3.141592;
	void SetCentro(double abcisa, double ordenada){
		centro_x=abcisa;
		centro_y=ordenada;
	}
	void setradio(double elradio){
		radio=elradio;
	}
	double getAbcisacentro(){
		return centro_x;
	}
	double getOrdenadacentro(){
		return centro_y;
	}
	double getradio(){
		return radio;
	}
	double longitud(){
		return 2*PI*radio;
	}
	double area(){
		return PI*radio*radio;
	}
	void traslada(double enHorizontal, double enVertical){
		centro_x=centro_x+enHorizontal;
		centro_y=centro_y+enVertical;
	}
};
class cuadrado{
private:
	double esquina_abcisa;
	double esquina_ordenada;
	double longitud;
public:
	cuadrado(double abcisita, double ordenadita, double longitudita)
		:esquina_abcisa(abcisita),
		esquina_ordenada(ordenadita),
		longitud(longitudita)
	{  }
segmentodirigido x_1(){
		segmentodirigido X1(esquina_abcisa, esquina_ordenada, esquina_abcisa+longitud, esquina_ordenada);
		return X1;
	}
	segmentodirigido x_2(){
		segmentodirigido X2(esquina_abcisa, esquina_ordenada, esquina_abcisa, esquina_ordenada+longitud);
		return X2;
	}
	segmentodirigido y_1(){
		segmentodirigido Y1(esquina_abcisa+longitud, esquina_ordenada, esquina_abcisa+longitud, esquina_ordenada+longitud);
		return Y1;
	}
	segmentodirigido y_2(){
		segmentodirigido Y2(esquina_abcisa, esquina_ordenada+longitud, esquina_abcisa+longitud, esquina_ordenada+longitud);
		return Y2;
	}
	punto2d centro(){
		punto2d CENTRO((longitud/2)+esquina_abcisa, (longitud/2)+esquina_ordenada);
		return CENTRO;
	}
	circunferencia circunferenciaInscrita(){
		circunferencia circulico;
		circulico.SetCentro((longitud/2)+esquina_abcisa, (longitud/2)+esquina_ordenada);
		circulico.setradio(longitud/2);
		return circulico;
	}
	circunferencia circunscrita(){
		circunferencia circulico;
		segmentodirigido longitud1(esquina_abcisa, esquina_ordenada, esquina_abcisa+(longitud/2), esquina_ordenada+(longitud/2));
		circulico.SetCentro((longitud/2)+esquina_abcisa, (longitud/2)+esquina_ordenada);
		circulico.setradio(longitud1.longitud());
		return circulico;
	}
	double area(){
		return longitud*longitud;
	}
	void mayorarea(double area1, double area2){
		if(area1>area2){
			cout<<"El cuadrado 1 tiene un area mayor\n";
		}
		else if(area2>area1){
			cout<<"El cuadrado 2 tiene un area mayor\n";
		}
		else{
			cout<<"Tienen el mismo area\n";
		}
	}
	void contenido(cuadrado cuadradito){
		double xdos=cuadradito.esquina_abcisa;
		double ydos=cuadradito.esquina_ordenada;
		double ldos=cuadradito.longitud;
		if((xdos>=esquina_abcisa) && (xdos+ldos<=esquina_abcisa+longitud) && (ydos>=esquina_ordenada) && (ydos+ldos<=esquina_ordenada+longitud)){
			cout<<"El cuadrado 1 contiene al cuadrado 2\n";
		}
		else{
			cout<<"El cuadrado 1 no contiene al cuadrado 2\n";
		}
	}
};
int main(){
	double a, b, c;
	cout<<"Introduzca la esquina abcisa (1er cuadrado): ";
	cin>>a;
	cout<<"Introduzca la esquina ordenada (1er cuadrado): ";
	cin>>b;
	cout<<"Introduzca la longitud (1er cuadrado): ";
	cin>>c;
	cuadrado objeto1(a, b, c);
	cout<<"Introduzca la esquina abcisa (2o cuadrado): ";
	cin>>a;
	cout<<"Introduzca la esquina ordenada (2o cuadrado): ";
	cin>>b;
	cout<<"Introduzca la longitud (2o cuadrado): ";
	cin>>c;
	cuadrado objeto2(a, b, c);
	objeto1.mayorarea(objeto1.area(), objeto2.area());
	objeto1.contenido(objeto2);
}
