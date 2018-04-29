/*Definid sobre la clase Cuadrado los siguientes métodos:
 Cuatro métodos para devolver cada uno de los lados del cuadrado como objetos
de la clase SegmentoDirigido.
 Obtener el punto central interior al cuadrado:
Punto2D Centro()
Para calcular las coordenadas basta sumar la mitad de la longitud del cuadrado
a las coordenadas de la esquina inferior izquierda.
 Obtener la circunferencia inscrita al cuadrado (la que está por dentro):
Circunferencia CircunferenciaInscrita()
Esta circunferencia es la que tiene como centro el centro del cuadrado y como
radio la mitad de la longitud del cuadrado.
 Obtener la circunferencia circunscrita al cuadrado (la que está por fuera):
Circunferencia CircunferenciaCircunscrita()
Esta circunferencia es la que tiene como centro el centro del cuadrado y como
radio, la longitud del segmento que une el centro con la esquina inferior izquierda.
Obtened la longitud creando el objeto de la clase SegmentoDirigido y a
continuación llamad al método Longitud.
Cread un programa principal que llame a dichos métodos.*/
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
};
int main(){
	double a, b, c;
	cout<<"Introduzca la esquina abcisa: ";
	cin>>a;
	cout<<"Introduzca la esquina ordenada: ";
	cin>>b;
	cout<<"Introduzca la longitud: ";
	cin>>c;
	cuadrado objeto(a, b, c);
	cout<<"El punto central del interior del cuadrado es: "<<objeto.centro().Abcisa()<<", "<<objeto.centro().Ordenada()<<endl;
	cout<<"La circunferencia inscrita es: "<<objeto.circunferenciaInscrita().getAbcisacentro()<<", "<<objeto.circunferenciaInscrita().getOrdenadacentro()<<"\n    Radio: "<<objeto.circunferenciaInscrita().getradio()<<endl;
	cout<<"La circunferencia circunscrita es: "<<objeto.circunscrita().getAbcisacentro()<<", "<<objeto.circunferenciaInscrita().getOrdenadacentro()<<"\n      Radio: "<<objeto.circunscrita().getradio()<<endl;
	system("pause");
}
