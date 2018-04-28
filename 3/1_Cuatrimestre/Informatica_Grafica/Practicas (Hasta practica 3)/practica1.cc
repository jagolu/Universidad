//**************************************************************************
// Práctica 1
//
// Domingo Martin Perandres 2013-2016
//
// GPL
//**************************************************************************

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <math.h>
#include "vertex.h"
#include <vector>
#include <iostream>
#include "OB3D.h"
#include "O3D.h"
#include "cubo.h"
#include "tetraedro.h"
#include "cilindro.h"
#include "vaso.h"
#include "vasoInvertido.h"
#include "cono.h"
#include "tubo.h"
#include "esfera.h"
#include "paloPelota.h"
#include "objeto_ply.h"
#include "base.h"
#include "modeladorWatt.h"
#include "objeto_revolucion.h"
#include "dosPelotasUnidas.h"

using namespace std;
static char tipo='t';
static char forma='p';
static char revol='1';
static char subeBaja='o';
static float subeBajaMW=0.0;
int giro=2;

cubo cube(1);
tetraedro tetrahedron(1);
cilindro cylinder(1, 20);
vaso glass(1, 20);
vasoInvertido investedGlass(1, 20);
cono cone(1, 20);
tubo tube(1, 20);
esfera sphere(0.5, 4);
modeladorWatt mW(1,15);

objeto_ply fp2("./beethoven.ply");

void giracion(){
	giro+=(subeBajaMW*2)+1;
	if(giro<=1)giro++;
	glutPostRedisplay();
}

// tamaño de los ejes
const int AXIS_SIZE=50000;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Window_width,Window_height,Front_plane,Back_plane;

// variables que determninan la posicion y tamaño de la ventana X
int UI_window_pos_x=5,UI_window_pos_y=5,UI_window_width=1000,UI_window_height=1000;

//**************************************************************************
//
//***************************************************************************

void clear_window(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void change_projection(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
// formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
//  Front_plane>0  Back_plane>PlanoDelantero)
	glFrustum(-Window_width,Window_width,-Window_height,Window_height,Front_plane,Back_plane);
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void change_observer(){
// posicion del observador
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0,0,-Observer_distance);
	glRotatef(Observer_angle_x,1,0,0);
	glRotatef(Observer_angle_y,0,1,0);
}

//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void draw_axis(){
	glBegin(GL_LINES);
	// eje X, color rojo
	glColor3f(1,0,0);
	glVertex3f(-AXIS_SIZE,0,0);
	glVertex3f(AXIS_SIZE,0,0);
	// eje Y, color verde
	glColor3f(0,1,0);
	glVertex3f(0,-AXIS_SIZE,0);
	glVertex3f(0,AXIS_SIZE,0);
	// eje Z, color azul
	glColor3f(0,0,1);
	glVertex3f(0,0,-AXIS_SIZE);
	glVertex3f(0,0,AXIS_SIZE);
	glEnd();
}

//**************************************************************************
// Funcion que dibuja los objetos
//***************************************************************************

void draw_objects(){
	GLfloat Vertices[8][3]= {{5,0,0},{4,4,0},{0,5,0},{-4,4,0},{-5,0,0},{-4,-4,0},{0,-5,0},{4,-4,0}};
	int i;

	glColor3f(0,1,0);
	glPointSize(4);

	glBegin(GL_POINTS);
	for (i=0;i<8;i++){
		glVertex3fv((GLfloat *) &Vertices[i]);
		}
	glEnd();
}

void draw_scene(void){
	clear_window();
	change_observer();
	draw_axis();
	glColor3f(0,1,0);
	glPointSize(4);
	if(tipo=='t'){
		if(forma=='p') cube.draw_points();
		if(forma=='a') cube.draw_edges();
		if(forma=='s') cube.draw_solid();
		if(forma=='c') cube.draw_solid_chess();
		if(forma=='t'){
			glColor3f(0,0,0);
			cube.draw_points();
			glColor3f(1,0,0);
			cube.draw_edges();
			glColor3f(0,0,1);
			cube.draw_solid();
		}
	 }
	if(tipo=='c'){
		if(forma=='p') tetrahedron.draw_points();
		else if(forma=='a')tetrahedron.draw_edges();
		else if(forma=='s')tetrahedron.draw_solid();
		else if(forma=='c')tetrahedron.draw_solid_chess();
		if(forma=='t'){
			glColor3f(0,0,0);
			tetrahedron.draw_points();
			glColor3f(1,0,0);
			tetrahedron.draw_edges();
			glColor3f(0,0,1);
			tetrahedron.draw_solid();
		}
	 }
	if(tipo=='f'){
		if(forma=='p') fp2.draw_points();
		else if(forma=='a')fp2.draw_edges();
		else if(forma=='s')fp2.draw_solid();
		else if(forma=='c')fp2.draw_solid_chess();
		if(forma=='t'){
			glColor3f(0,0,0);
			fp2.draw_points();
			glColor3f(1,0,0);
			fp2.draw_edges();
			glColor3f(0,0,1);
			fp2.draw_solid();
		}
	}
	if(tipo=='r'){
		if(revol=='1'){
			if(forma=='p')cylinder.draw_points();
			else if(forma=='a') cylinder.draw_edges();
			else if(forma=='s') cylinder.draw_solid();
			else if(forma=='c') cylinder.draw_solid_chess();
			else if(forma=='t'){
				glColor3f(0,0,0);
				cylinder.draw_points();
				glColor3f(1,0,0);
				cylinder.draw_edges();
				glColor3f(0,0,1);
				cylinder.draw_solid();		
			}
		}
		else if(revol=='2'){
			if(forma=='p')glass.draw_points();
			else if(forma=='a') glass.draw_edges();
			else if(forma=='s') glass.draw_solid();
			else if(forma=='c') glass.draw_solid_chess();
			else if(forma=='t'){
				glColor3f(0,0,0);
				glass.draw_points();
				glColor3f(1,0,0);
				glass.draw_edges();
				glColor3f(0,0,1);
				glass.draw_solid();		
			}
		}
		else if(revol=='3'){
			if(forma=='p')investedGlass.draw_points();
			else if(forma=='a') investedGlass.draw_edges();
			else if(forma=='s') investedGlass.draw_solid();
			else if(forma=='c') investedGlass.draw_solid_chess();
			else if(forma=='t'){
				glColor3f(0,0,0);
				investedGlass.draw_points();
				glColor3f(1,0,0);
				investedGlass.draw_edges();
				glColor3f(0,0,1);
				investedGlass.draw_solid();		
			}
		}
		else if(revol=='4'){
			if(forma=='p')cone.draw_points();
			else if(forma=='a') cone.draw_edges();
			else if(forma=='s') cone.draw_solid();
			else if(forma=='c') cone.draw_solid_chess();
			else if(forma=='t'){
				glColor3f(0,0,0);
				cone.draw_points();
				glColor3f(1,0,0);
				cone.draw_edges();
				glColor3f(0,0,1);
				cone.draw_solid();		
			}
		}
		else if(revol=='5'){
			if(forma=='p')tube.draw_points();
			else if(forma=='a') tube.draw_edges();
			else if(forma=='s') tube.draw_solid();
			else if(forma=='c') tube.draw_solid_chess();
			else if(forma=='t'){
				glColor3f(0,0,0);
				tube.draw_points();
				glColor3f(1,0,0);
				tube.draw_edges();
				glColor3f(0,0,1);
				tube.draw_solid();		
			}
		}
		else if(revol=='6'){
			if(forma=='p')sphere.draw_points();
			else if(forma=='a') sphere.draw_edges();
			else if(forma=='s') sphere.draw_solid();
			else if(forma=='c') sphere.draw_solid_chess();
			else if(forma=='t'){
				glColor3f(0,0,0);
				sphere.draw_points();
				glColor3f(1,0,0);
				sphere.draw_edges();
				glColor3f(0,0,1);
				sphere.draw_solid();		
			}
		}
	}
	else if(tipo=='a'){
		if(forma=='p')mW.draw_points(subeBajaMW, giro);
			else if(forma=='a') mW.draw_edges(subeBajaMW, giro);
			else if(forma=='s') mW.draw_solid(subeBajaMW, giro);
			else if(forma=='c') mW.draw_solid_chess(subeBajaMW, giro);
			else if(forma=='t'){
				glColor3f(0,0,0);
				mW.draw_points(subeBajaMW, giro);
				glColor3f(1,0,0);
				mW.draw_edges(subeBajaMW, giro);
				glColor3f(0,0,1);
				mW.draw_solid(subeBajaMW, giro);		
			}
	}
	glutSwapBuffers();
}



//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
//
// el evento manda a la funcion:
// nuevo ancho
// nuevo alto
//***************************************************************************

void change_window_size(int Ancho1,int Alto1){
	change_projection();
	glViewport(0,0,Ancho1,Alto1);
	glutPostRedisplay();
}


//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla normal
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton
//***************************************************************************
void normal_keys(unsigned char Tecla1,int x,int y){
	if (toupper(Tecla1)=='Q') exit(0);
	else if (toupper(Tecla1)=='P') forma='p';
	else if (toupper(Tecla1)=='A') forma='a';
	else if (toupper(Tecla1)=='S') forma='s';
	else if (toupper(Tecla1)=='C') forma='c';
	else if (toupper(Tecla1)=='T') forma='t';
	else if (toupper(Tecla1)=='L'){
		subeBaja='l';
		if(subeBajaMW<=5.9) subeBajaMW+=0.1;
		subeBaja='o';
	}
	else if (toupper(Tecla1)=='K'){
		subeBaja='k';
		if(subeBajaMW>=0.1) subeBajaMW-=0.1;
		subeBaja='o';
	}
	else if(toupper(Tecla1)=='1') revol='1';
	else if(toupper(Tecla1)=='2') revol='2';
	else if(toupper(Tecla1)=='3') revol='3';
	else if(toupper(Tecla1)=='4') revol='4';
	else if(toupper(Tecla1)=='5') revol='5';
	else if(toupper(Tecla1)=='6') revol='6';
	else if(toupper(Tecla1)=='7') revol='7';
	glutPostRedisplay();
}

//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla especial
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton

//***************************************************************************

void special_keys(int Tecla1,int x,int y){
	switch (Tecla1){
		case GLUT_KEY_LEFT:Observer_angle_y--;break;
		case GLUT_KEY_RIGHT:Observer_angle_y++;break;
		case GLUT_KEY_UP:Observer_angle_x--;break;
		case GLUT_KEY_DOWN:Observer_angle_x++;break;
		case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
		case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
		case GLUT_KEY_F1: tipo='t';break;
		case GLUT_KEY_F2: tipo='c'; break;
		case GLUT_KEY_F3: tipo='f'; break;
		case GLUT_KEY_F4: tipo='r'; break;
		case GLUT_KEY_F5: tipo='a'; break; 
	}
	glutPostRedisplay();
}



//***************************************************************************
// Funcion de incializacion
//***************************************************************************

void initialize(void){
// se inicalizan la ventana y los planos de corte
	Window_width=0.5;
	Window_height=0.5;
	Front_plane=1;
	Back_plane=500;
// se inicia la posicion del observador, en el eje z
	Observer_distance=2*Front_plane;
	Observer_angle_x=0;
	Observer_angle_y=0;
// se indica cual sera el color para limpiar la ventana	(r,v,a,al)
// blanco=(1,1,1,1) rojo=(1,0,0,1), ...
	glClearColor(1,1,1,1);
// se habilita el z-bufer
	glEnable(GL_DEPTH_TEST);
	change_projection();
	glViewport(0,0,UI_window_width,UI_window_height);
}
//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************
int main(int argc, char **argv){
// se llama a la inicialización de glut
	glutInit(&argc, argv);
// se indica las caracteristicas que se desean para la visualización con OpenGL
// Las posibilidades son:
// GLUT_SIMPLE -> memoria de imagen simple
// GLUT_DOUBLE -> memoria de imagen doble
// GLUT_INDEX -> memoria de imagen con color indizado
// GLUT_RGB -> memoria de imagen con componentes rojo, verde y azul para cada pixel
// GLUT_RGBA -> memoria de imagen con componentes rojo, verde, azul y alfa para cada pixel
// GLUT_DEPTH -> memoria de profundidad o z-bufer
// GLUT_STENCIL -> memoria de estarcido
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
// posicion de la esquina inferior izquierdad de la ventana
	glutInitWindowPosition(UI_window_pos_x,UI_window_pos_y);
// tamaño de la ventana (ancho y alto)
	glutInitWindowSize(UI_window_width,UI_window_height);
// llamada para crear la ventana, indicando el titulo (no se visualiza hasta que se llama
// al bucle de eventos)
	glutCreateWindow("Práctica 1");
// asignación de la funcion llamada "dibujar" al evento de dibujo
	glutDisplayFunc(draw_scene);
// asignación de la funcion llamada "cambiar_tamanio_ventana" al evento correspondiente
	glutReshapeFunc(change_window_size);
// asignación de la funcion llamada "tecla_normal" al evento correspondiente
	glutSpecialFunc(special_keys);
	glutKeyboardFunc(normal_keys);
	glutIdleFunc(giracion);
// asignación de la funcion llamada "tecla_Especial" al evento correspondiente
// funcion de inicialización
	initialize();
// inicio del bucle de eventos
	glutMainLoop();
	return 0;
}
