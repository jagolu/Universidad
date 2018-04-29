
#ifndef AGENT__
#define AGENT__

#include <string>
#include <iostream>
#include <cstdlib>
#include "conexion.h"
using namespace std;

// -----------------------------------------------------------
//				class Agent
// -----------------------------------------------------------
class Environment;
class Agent
{
public:
	Agent(){
		x_= 99;
		y_= 99;
		orientacion_=3;
		role_="PlYR";
		last_accion_=3;
		REINICIADO_=false;
		size_=200;
		//mis cosas
		primer_paso=false; 
		primer_paso_vuelta=false;  
		segundo_paso_vuelta=false; 
		segundo_paso=false; 
		cogiendoalgo=false; 
		pk1=false;
		pk2=false;
		yaActualizado=false;
		cont_pasos=1;
		dandocosas=false;
		pasos_dados=0;
		sacandoObjeto=false;
		for(int i=0;i<5;i++){
			MOCHILLA_[i]='-';
		}
		//mis cosas
		for (int i=0;i<200;i++)
		    for(int j=0;j<200;j++){
		      mapa_entorno_[i][j]='?';
		      mapa_objetos_[i][j]='?';
			//MIS COSAS
		      mapa_pulgarcito[i][j]=0;
			//MIS COSAS
		    }

		for (int i=0;i<100;i++)
		    for(int j=0;j<100;j++)
		      mapa_solucion_[i][j]='?';

	}

	enum ActionType
	{
	    actFORWARD, // avanzar
	    actTURN_L,  // Girar Izquierda
	    actTURN_R,  // Girar Derecha
	    actIDLE,    // No hacer nada
	    actPICKUP,  // Recoger un objeto
	    actPUTDOWN, // Soltar un objeto
	    actPUSH,    // Meter en la mochila
	    actPOP,     // Sacar de la mochila
	    actGIVE,	// Dar un objeto a un personaje
	    actTHROW	// Lanzar un objeto

	};

	void Perceive(Environment &env);
	bool Perceive_Remote(conexion_client &Cliente, Environment &env);
	void ActualizarInformacion(Environment *env);
	//mis cosas
	void ActualizarPulgarcito();
	int UltimaAccion(int brujula);
	bool MochilaLlena();
	void CapturaFilaColumnaPK(string mensaje, int & fila, int & columna);
	void PasarMapa();
	//mis cosas
	ActionType Think();
	bool MochilaVacia();
	void FixLastAction(Agent::ActionType x){last_accion_=x;};

	char mapa_entorno_[200][200]; // mapa que muestra el tipo de terreno
	char mapa_objetos_[200][200]; // mapa que muestra los objetos que estan encima del terreno
	char mapa_solucion_[100][100]; // Mapa que almacena la solucion que el alumno propone
	//mis cosas
	int mapa_pulgarcito[200][200];
	//mis cosas
	// Funciones de acceso a los datos
	void GetCoord(int &fila, int &columna, int &brujula){fila=y_;columna=x_;brujula=orientacion_;};


private:
	//Variables de interaccion con el entorno grafico
	int size_;	

	//mis cosas
	int pulgarcito[10];
	int cont_pasos;
	bool primer_paso, primer_paso_vuelta, segundo_paso_vuelta, segundo_paso, cogiendoalgo;
	int fila1,fila2,columna1,columna2,ff1,cc1,ff2,cc2;
	bool pk1, pk2, yaActualizado;
	bool sacandoObjeto;
	//MIS COSICAS
	//SENSORES
	char VISTA_[10];
	char SURFACE_[10];
	bool REINICIADO_;
	string MENSAJE_;
	char EN_USO_;
	char MOCHILLA_[5];
	char PUNTUACION_[9];
	bool FIN_JUEGO_;
	char SALUD_;
	bool actualizado=false;
	int pasos_dados;
	bool dandocosas;

	//Variables de estado
	int x_,y_, orientacion_;
	int last_accion_;
	string role_;

};

string ActionStr(Agent::ActionType);

#endif
