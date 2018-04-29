#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include "player.h"
#include "environment.h"

using namespace std;

const double masinf=9999999999.0, menosinf=-9999999999.0;


// Constructor
Player::Player(int jug){
    jugador_=jug;
}

// Actualiza el estado del juego para el jugador
void Player::Perceive(const Environment & env){
    actual_=env;
}

double Puntuacion(int jugador, const Environment &estado){
    double suma=0;

    for (int i=0; i<7; i++)
      for (int j=0; j<7; j++){
         if (estado.See_Casilla(i,j)==jugador){
            if (j<3)
               suma += j;
            else
               suma += (6-j);
         }
      }

    return suma;
}


// Funcion de valoracion para testear Poda Alfabeta
double ValoracionTest(const Environment &estado, int jugador){
    int ganador = estado.RevisarTablero();

    if (ganador==jugador)
       return 99999999.0; // Gana el jugador que pide la valoracion
    else if (ganador!=0)
            return -99999999.0; // Pierde el jugador que pide la valoracion
    else if (estado.Get_Casillas_Libres()==0)
            return 0;  // Hay un empate global y se ha rellenado completamente el tablero
    else
          return Puntuacion(jugador,estado);
}

void JuegoAleatorio(bool aplicables[], int opciones[], int &j){
    j=0;
    for (int i=0; i<8; i++){
        if (aplicables[i]){
           opciones[j]=i;
           j++;
        }
    }
}

//DE AQUI PA TRAS NO SE TOCA
double miHeuristica(Environment estado,int jug){
	double val=0;
	//PARA VER SI PERDERIAMOS
	for(int i=0; i<7; ++i){
		for(int j=0; j<7; ++j){
			if(estado.See_Casilla(i,j)==jug){
				if(j>0 && j<4 && estado.See_Casilla(i,j)==jug && estado.See_Casilla(i,j+1)==jug && estado.See_Casilla(i,j+2)==jug){
					if(estado.See_Casilla(i,j+3)==jug || estado.See_Casilla(i,j-1)==jug)val=menosinf;
				}
				if(i>1 && i<6 && estado.See_Casilla(i,j)==jug && estado.See_Casilla(i-1,j)==jug && estado.See_Casilla(i-2,j)==jug){
					if(estado.See_Casilla(i+1,j)==jug) val=menosinf;
				}
				if((i>2 && j<4) && estado.See_Casilla(i,j)==jug && estado.See_Casilla(i-1,j+1)==jug && estado.See_Casilla(i-2,j+2)==jug){
					if((i<6 && j>0) && (estado.See_Casilla(i-3,j+3)==jug || estado.See_Casilla(i+1,j-1)==jug)) val=menosinf;
				}
				if((i>2 && j>2) && estado.See_Casilla(i,j)==jug && estado.See_Casilla(i-1,j-1)==jug && estado.See_Casilla(i-2,j-2)==jug){
					if((i<6 && j<6) && (estado.See_Casilla(i+1,j+1)==jug || estado.See_Casilla(i-3,j-3)==jug)) val=menosinf;
				}
			}
		}
	}
	//PARA VER SI GANARIAMOS
	int jugAux;
	if(jug==1) jugAux=2;
	else jugAux=1;
	if(val==0){
		for(int i=0;i<7;++i){
			for(int j=0;j<7;++j){
				if(estado.See_Casilla(i,j)==jugAux){
					if(j>0 && j<4 && estado.See_Casilla(i,j)==jugAux && estado.See_Casilla(i,j+1)==jugAux && estado.See_Casilla(i,j+2)==jugAux){
						if(estado.See_Casilla(i,j+3)==jugAux || estado.See_Casilla(i,j-1)==jugAux)val=masinf;
					}
					if(i>1 && i<6 && estado.See_Casilla(i,j)==jugAux && estado.See_Casilla(i-1,j)==jugAux && estado.See_Casilla(i-2,j)==jugAux){
						if(estado.See_Casilla(i+1,j)==jugAux) val=masinf;
					}
					if((i>2 && j<4) && estado.See_Casilla(i,j)==jugAux && estado.See_Casilla(i-1,j+1)==jugAux && estado.See_Casilla(i-2,j+2)==jugAux){
						if((i<6 && j>0) && (estado.See_Casilla(i-3,j+3)==jugAux || estado.See_Casilla(i+1,j-1)==jugAux)) val=masinf;
					}
					if((i>2 && j>2) && estado.See_Casilla(i,j)==jugAux && estado.See_Casilla(i-1,j-1)==jugAux && estado.See_Casilla(i-2,j-2)==jugAux){
						if((i<6 && j<6) && (estado.See_Casilla(i+1,j+1)==jugAux || estado.See_Casilla(i-3,j-3)==jugAux)) val=masinf;
					}
				}
			}
		}
	}
	//si no, HEURISTICA
	if(val==0){
		for(int i=0;i<7;i++){
			for(int j=0;j<7;j++){
				if(estado.See_Casilla(i,j)==jug){
					if(j<5 && estado.See_Casilla(i,j)==jug && estado.See_Casilla(i,j+1)==jug && estado.See_Casilla(i,j+2)==jug)val-=100;
					if(j>0 && j<4 && estado.See_Casilla(i,j)==jug && estado.See_Casilla(i,j+1)==jug && estado.See_Casilla(i,j+2)==jug){
						val-=200;
						if(estado.See_Casilla(i,j-1)==0 && estado.See_Casilla(i,j+3)==0)val-=500;
					}
					if(i>1 && estado.See_Casilla(i,j)==jug && estado.See_Casilla(i-1,j)==jug && estado.See_Casilla(i-2,j)==jug)val-=50;
					if(i>1 && i<6 && estado.See_Casilla(i,j)==jug && estado.See_Casilla(i-2,j)==jug && estado.See_Casilla(i-1,j)==jug ){
						val-=100;
						if(estado.See_Casilla(i+1,j)==0) val-=50;
					}
					if((i>1 && j<5) && estado.See_Casilla(i,j)==jug && estado.See_Casilla(i-1,j+1)==jug && estado.See_Casilla(i-2,j+2)==jug) val-=300;
					if((i>2 && j<4) && estado.See_Casilla(i,j)==jug && estado.See_Casilla(i-1,j+1)==jug && estado.See_Casilla(i-2,j+2)==jug){
						val-=400;
						if(i<6 && j>0 && estado.See_Casilla(i-3,j+3)==0 && estado.See_Casilla(i+1,j-1)==0) val-=1000;
					}
					if((i>1 && j>1) && estado.See_Casilla(i-1,j-1)==jug && estado.See_Casilla(i,j)==jug && estado.See_Casilla(i-2,j-2)==jug) val-=400;
					if((i>2 && j>2) && estado.See_Casilla(i,j)==jug && estado.See_Casilla(i-1,j-1)==jug && estado.See_Casilla(i-2,j-2)==jug){
						val-=1000;
						if(i<6 && j<6 && estado.See_Casilla(i-3,j-3)==0 && estado.See_Casilla(i+1,j+1)==0) val-=1500;
					}
					if(i>0 && estado.See_Casilla(i,j)==jug && estado.See_Casilla(i-1,j)==jug)val+=300;
					if(i>0 && i<5 && estado.See_Casilla(i,j)==jug && estado.See_Casilla(i-1,j)==jug)val-=150;
					if(j<6 && estado.See_Casilla(i,j)==jug && estado.See_Casilla(i,j+1)==jug)val+=500;
					if(j>1 && j<4 && estado.See_Casilla(i,j)==jug && estado.See_Casilla(i,j+1)==jug)val-=100;
					if((i>0 && j>0) && estado.See_Casilla(i,j)==jug && estado.See_Casilla(i-1,j-1)==jug)val+=200;
					if((i>2 && j>2) && estado.See_Casilla(i,j)==jug && estado.See_Casilla(i-1,j-1)==jug)val-=50;
					if((i>0 && j<6) && estado.See_Casilla(i,j)==jug && estado.See_Casilla(i-1,j+1)==jug)val+=200;
					if((i>2 && j<4) && estado.See_Casilla(i,j)==jug && estado.See_Casilla(i-1,j+1)==jug)val-=50;
					if(i>0 && j==3 && estado.See_Casilla(i,j)==jug && estado.See_Casilla(i-1,j)==jug)val+=200;
				}
			}
		}
	}
	return val;
}
double Valoracion(const Environment &estado, int jugador){
	int ganador = estado.RevisarTablero();
	if (ganador==jugador)
		return 99999999.0;
	else if (ganador!=0)
		return -99999999.0;
	else if (estado.Get_Casillas_Libres()==0)
		return 0; 
	else{
		return miHeuristica(estado,jugador);
	}
}


double Player::minimax_conPodaAB(const Environment &env,int jug, int prof,double a,double b,bool MaxMin){
	if(env.JuegoTerminado() || prof==0){
		return Valoracion(env,jug);
	}
	int num_acciones;
	Environment tab[8];
	num_acciones=env.GenerateAllMoves(tab);
	if(MaxMin){
		for(int i=0;i<num_acciones;++i){
			a = max(a,minimax_conPodaAB(tab[i],jug,prof-1,a,b,!MaxMin));
			if(a>=b) break;
		}
		return a;
	}
	else{
		for(int j=0;j<num_acciones;++j){
			b = min(b,minimax_conPodaAB(tab[j],jug,prof-1,a,b,!MaxMin));
			if(a>=b) break;
		}
		return b;
	}
}
// Invoca el siguiente movimiento del jugador
Environment::ActionType Player::Think(){
    const int PROFUNDIDAD_MINIMAX = 6; 
    const int PROFUNDIDAD_ALFABETA = 8; 

    Environment::ActionType accion;
    bool aplicables[8]; 

    double valor; 
    double alpha, beta; 

    int numAcciones; 

    numAcciones = actual_.possible_actions(aplicables);

    cout << " Acciones aplicables ";
    (jugador_==1) ? cout << "Verde: " : cout << "Azul: ";
    for (int t=0; t<8; t++)
	alpha=menosinf;
	beta=masinf;
	int acc=-1;
	Environment tableros[8];
	numAcciones=actual_.GenerateAllMoves(tableros);
	for(int i=0;i<numAcciones;i++){
		valor=minimax_conPodaAB(tableros[i],jugador_,PROFUNDIDAD_ALFABETA,alpha,beta,false);
		if(valor>alpha){
			alpha=valor;
			accion=static_cast<Environment::ActionType>(tableros[i].Last_Action(jugador_));
		}
	}
	if(alpha==menosinf){
		acc=-1;
		Environment tablero=actual_.GenerateNextMove(acc);
		accion=static_cast<Environment::ActionType>(tablero.Last_Action(jugador_));
	}
	cout<<"Valor: "<<valor<<"Accion: "<<actual_.ActionStr(accion)<<endl;
    return accion;
}

