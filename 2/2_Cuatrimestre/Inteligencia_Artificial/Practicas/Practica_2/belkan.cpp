#include "belkan.h"
#include "conexion.h"
#include "environment.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;



// -----------------------------------------------------------
void PasarVectoraMapaCaracteres(int fila, int columna, char m[200][200], char *v, int brujula){
  m[fila][columna]=v[0];

    switch(brujula){
        case 0: // Orientacion Norte

		m[fila-1][columna]=v[1];
		for (int i=0; i<3; i++){
		  m[fila-2][columna+i-1]=v[2+i];
		}
		for (int j=0; j<5; j++){
		  m[fila-3][columna+j-2]=v[5+j];
		}
	        break;
	case 1: // Orientacion Este
		m[fila][columna+1]=v[1];
		for (int i=0; i<3; i++){
		  m[fila+i-1][columna+2]=v[2+i];
		}
		for (int j=0; j<5; j++){
		  m[fila+j-2][columna+3]=v[5+j];
		}
	        break;
        case 2: // Orientacion Sur
		m[fila+1][columna]=v[1];
		for (int i=0; i<3; i++){
		  m[fila+2][columna+1-i]=v[2+i];
		}
		for (int j=0; j<5; j++){
		  m[fila+3][columna+2-j]=v[5+j];
		}
		                break;
        case 3: // Orientacion Oeste
		m[fila][columna-1]=v[1];
		for (int i=0; i<3; i++){
		  m[fila+1-i][columna-2]=v[2+i];
		}
		for (int j=0; j<5; j++){
		  m[fila+2-j][columna-3]=v[5+j];
		}

                break;
    }

}
//MIS COSAS
void PasarVectoraMapaCaracteres2(int fila, int columna, char m[100][100], char *v, int brujula){
  m[fila][columna]=v[0];

    switch(brujula){
        case 0: // Orientacion Norte

		m[fila-1][columna]=v[1];
		for (int i=0; i<3; i++){
		  m[fila-2][columna+i-1]=v[2+i];
		}
		for (int j=0; j<5; j++){
		  m[fila-3][columna+j-2]=v[5+j];
		}
	        break;
	case 1: // Orientacion Este
		m[fila][columna+1]=v[1];
		for (int i=0; i<3; i++){
		  m[fila+i-1][columna+2]=v[2+i];
		}
		for (int j=0; j<5; j++){
		  m[fila+j-2][columna+3]=v[5+j];
		}
	        break;
        case 2: // Orientacion Sur
		m[fila+1][columna]=v[1];
		for (int i=0; i<3; i++){
		  m[fila+2][columna+1-i]=v[2+i];
		}
		for (int j=0; j<5; j++){
		  m[fila+3][columna+2-j]=v[5+j];
		}
		                break;
        case 3: // Orientacion Oeste
		m[fila][columna-1]=v[1];
		for (int i=0; i<3; i++){
		  m[fila+1-i][columna-2]=v[2+i];
		}
		for (int j=0; j<5; j++){
		  m[fila+2-j][columna-3]=v[5+j];
		}

                break;
    }

}
//MISCOSAS

// -----------------------------------------------------------
void Agent::Perceive(Environment &env)
{
	env.SenSorStatus(VISTA_, SURFACE_, MENSAJE_, REINICIADO_, EN_USO_, MOCHILLA_, PUNTUACION_, FIN_JUEGO_, SALUD_, false);

}


bool Agent::Perceive_Remote(conexion_client &Cliente, Environment &env)
{	
	bool actualizado=false;


	actualizado = env.Perceive_Remote(Cliente);
	if (actualizado)
		env.SenSorStatus(VISTA_, SURFACE_, MENSAJE_, REINICIADO_, EN_USO_, MOCHILLA_, PUNTUACION_, FIN_JUEGO_, SALUD_, true);

    return actualizado;
}


// -----------------------------------------------------------
string ActionStr(Agent::ActionType accion)
{
	switch (accion)
	{
	case Agent::actFORWARD: return "FORWARD";
	case Agent::actTURN_L: return "TURN LEFT";
	case Agent::actTURN_R: return "TURN RIGHT";
	case Agent::actIDLE: return "IDLE";
	case Agent::actPICKUP: return "PICK UP";
	case Agent::actPUTDOWN: return "PUT DOWN";
	case Agent::actPUSH: return "PUSH";
	case Agent::actPOP: return "POP";
	case Agent::actGIVE: return "GIVE";
	case Agent::actTHROW: return "THROW";
	default: return "????";
	}
}

// -----------------------------------------------------------
void Agent::ActualizarInformacion(Environment *env){
	// Actualizar mi informacion interna
	if (REINICIADO_){ 
		cout<<"se mete en reiniciar1\n";
		// Lo que tengas que hacer si eres reposicionado en el juego
		for(int i=0;i<100;i++){
			for(int j=0;j<100;j++){
				mapa_entorno_[i][j]='?';
				mapa_objetos_[i][j]='?';
				mapa_pulgarcito[i][j]=0;
			}
		}
		for(int i=0;i<5;i++){
			MOCHILLA_[i]='-';
		}
		x_=99;
		y_=99;
		orientacion_=3;	
		primer_paso=false;
		yaActualizado=false;
		pk1=false;
		pk2=false; 
		primer_paso_vuelta=false;  
		segundo_paso_vuelta=false; 
		segundo_paso=false; 
		cogiendoalgo=false; 
		dandocosas=false;
		yaActualizado=false;
		sacandoObjeto=false;
	}
	if(MENSAJE_!="Has chocado con un obstaculo movil. " && MENSAJE_!="Menudo golpe contra el arbol. " && MENSAJE_!="Este golpe ha sido fatal, quedas reiniciado. " && MENSAJE_!="Intentando atravesar un muro, Copperfield?. " && MENSAJE_!="Intentando atravesar una puerta cerrada, Eres un fantasma?. "){
		switch(last_accion_){
		  case 0: //avanzar
		  switch(orientacion_){
		    case 0: // norte
			    y_--;
			    break;
		    case 1: // este
			    x_++;
			    break;
		    case 2: // sur
			    y_++;
			    break;
		    case 3: // este
			    x_--;
			    break;
		  }
		  break;
		  case 1: // girar izq
			  orientacion_=(orientacion_+3)%4;
			  break;
		  case 2: // girar dch
			  orientacion_=(orientacion_+1)%4;
			  break;
		}

		// Comprobacion para no salirme del rango del mapa
		bool algo_va_mal=false;
		if (y_<0){
			y_=0;
			algo_va_mal=true;
		} 
		else if (y_>199){
			y_=199;
			algo_va_mal=true;
		}
		if (x_<0){
			x_=0;
			algo_va_mal=true;
		} 
		else if (x_>199){
			x_=199;
			algo_va_mal=true;
		}

		if (algo_va_mal){
			cout << "CUIDADO: NO ESTAS CONTROLANDO BIEN LA UBICACION DE TU AGENTE\n";
		}
	

		PasarVectoraMapaCaracteres(y_,x_,mapa_entorno_,VISTA_,orientacion_);
		PasarVectoraMapaCaracteres(y_,x_,mapa_objetos_,SURFACE_,orientacion_);
		env->ActualizarMatrizUsuario(mapa_entorno_);
		if(pk1 && pk2){
			PasarVectoraMapaCaracteres2(y_,x_,mapa_solucion_,VISTA_,orientacion_);
			for(int i=0;i<100;i++){
				for(int j=0;j<100;j++){
					if(mapa_solucion_[i][j]=='?') mapa_solucion_[i][j]='S';
				}
			}
		}
	}
}

// -----------------------------------------------------------

void Agent::ActualizarPulgarcito(){
	mapa_pulgarcito[y_][x_]=cont_pasos;
	cont_pasos++;
}
bool Agent::MochilaLlena(){
	bool llena=true;
	for(int i=0;i<5;i++){
		if(MOCHILLA_[i]=='-') llena=false;
	}
	return llena;
}

int Agent::UltimaAccion(int brujula){
	int solution;
	int ultimaAccionIzquierda=-1, ultimaAccionDerecha=-1, ultimaAccionAdelante=-1;
	switch(brujula){//izquierda
		case 0: //norte
			if(mapa_entorno_[y_][x_-1]!='D' && mapa_entorno_[y_][x_-1]!='B' && mapa_entorno_[y_][x_-1]!='A' && mapa_entorno_[y_][x_-1]!='P' && mapa_entorno_[y_][x_-1]!='M' && !( mapa_objetos_[y_][x_-1]>='a' && mapa_objetos_[y_][x_-1]<='z') ){
				ultimaAccionIzquierda=mapa_pulgarcito[y_][x_-1];
			}
			break;
		case 1: // este
			if(mapa_entorno_[y_-1][x_]!='D' && mapa_entorno_[y_-1][x_]!='B' && mapa_entorno_[y_-1][x_]!='A' && mapa_entorno_[y_-1][x_]!='P' && mapa_entorno_[y_-1][x_]!='M' && !( mapa_objetos_[y_-1][x_]>='a' && mapa_objetos_[y_-1][x_]<='z') ){
				ultimaAccionIzquierda=mapa_pulgarcito[y_-1][x_];
			}
			break;
		case 2: //sur
			if(mapa_entorno_[y_][x_+1]!='D' && mapa_entorno_[y_][x_+1]!='B' && mapa_entorno_[y_][x_+1]!='A' && mapa_entorno_[y_][x_+1]!='P' && mapa_entorno_[y_][x_+1]!='M' && !( mapa_objetos_[y_][x_+1]>='a' && mapa_objetos_[y_][x_+1]<='z') ){
				ultimaAccionIzquierda=mapa_pulgarcito[y_][x_+1];
			}
			break;
		case 3: //oeste
			if(mapa_entorno_[y_+1][x_]!='D' && mapa_entorno_[y_+1][x_]!='B' && mapa_entorno_[y_+1][x_]!='A' && mapa_entorno_[y_+1][x_]!='P' && mapa_entorno_[y_+1][x_]!='M' && !( mapa_objetos_[y_+1][x_]>='a' && mapa_objetos_[y_+1][x_]<='z') ){
				ultimaAccionIzquierda=mapa_pulgarcito[y_+1][x_];
			}
			break;
	}
	

	switch(brujula){//derecha
		case 0: //norte
			if(mapa_entorno_[y_][x_+1]!='D' && mapa_entorno_[y_][x_+1]!='B' && mapa_entorno_[y_][x_+1]!='A' && mapa_entorno_[y_][x_+1]!='P' && mapa_entorno_[y_][x_+1]!='M' && !( mapa_objetos_[y_][x_+1]>='a' && mapa_objetos_[y_][x_+1]<='z') ){
				ultimaAccionDerecha=mapa_pulgarcito[y_][x_+1];
			}
			break;
		case 1: // este
			if(mapa_entorno_[y_+1][x_]!='D' && mapa_entorno_[y_+1][x_]!='B' && mapa_entorno_[y_+1][x_]!='A' && mapa_entorno_[y_+1][x_]!='P' && mapa_entorno_[y_+1][x_]!='M' && !( mapa_objetos_[y_+1][x_]>='a' && mapa_objetos_[y_+1][x_]<='z') ){
				ultimaAccionDerecha=mapa_pulgarcito[y_+1][x_];
			}
			break;
		case 2: //sur
			if(mapa_entorno_[y_][x_-1]!='D' && mapa_entorno_[y_][x_-1]!='B' && mapa_entorno_[y_][x_-1]!='A' && mapa_entorno_[y_][x_-1]!='P' && mapa_entorno_[y_][x_-1]!='M' && !( mapa_objetos_[y_][x_-1]>='a' && mapa_objetos_[y_][x_-1]<='z') ){
				ultimaAccionDerecha=mapa_pulgarcito[y_][x_-1];
			}
			break;
		case 3: //oeste
			if(mapa_entorno_[y_-1][x_]!='D' && mapa_entorno_[y_-1][x_]!='B' && mapa_entorno_[y_-1][x_]!='A' && mapa_entorno_[y_-1][x_]!='P' && mapa_entorno_[y_-1][x_]!='M' && !( mapa_objetos_[y_-1][x_]>='a' && mapa_objetos_[y_-1][x_]<='z') ){
				ultimaAccionDerecha=mapa_pulgarcito[y_-1][x_];
			}
			break;
	}

	switch(brujula){//palante
		case 0: //norte
			if(mapa_entorno_[y_-1][x_]!='D' && mapa_entorno_[y_-1][x_]!='B' && mapa_entorno_[y_-1][x_]!='A' && mapa_entorno_[y_-1][x_]!='P' && mapa_entorno_[y_-1][x_]!='M' && !( mapa_objetos_[y_-1][x_]>='a' && mapa_objetos_[y_-1][x_]<='z') ){
				ultimaAccionAdelante=mapa_pulgarcito[y_-1][x_];
			}
			break;
		case 1: // este
			if(mapa_entorno_[y_][x_+1]!='D' && mapa_entorno_[y_][x_+1]!='B' && mapa_entorno_[y_][x_+1]!='A' && mapa_entorno_[y_][x_+1]!='P' && mapa_entorno_[y_][x_+1]!='M' && !( mapa_objetos_[y_][x_+1]>='a' && mapa_objetos_[y_][x_+1]<='z') ){
				ultimaAccionAdelante=mapa_pulgarcito[y_][x_+1];
			}
			break;
		case 2: //sur
			if(mapa_entorno_[y_+1][x_]!='D' && mapa_entorno_[y_+1][x_]!='B' && mapa_entorno_[y_+1][x_]!='A' && mapa_entorno_[y_+1][x_]!='P' && mapa_entorno_[y_+1][x_]!='M' && !( mapa_objetos_[y_+1][x_]>='a' && mapa_objetos_[y_+1][x_]<='z') ){
				ultimaAccionAdelante=mapa_pulgarcito[y_+1][x_];
			}
			break;
		case 3: //oeste
			if(mapa_entorno_[y_][x_-1]!='D' && mapa_entorno_[y_][x_-1]!='B' && mapa_entorno_[y_][x_-1]!='A' && mapa_entorno_[y_][x_-1]!='P' && mapa_entorno_[y_][x_-1]!='M' && !( mapa_objetos_[y_][x_-1]>='a' && mapa_objetos_[y_][x_-1]<='z') ){
				ultimaAccionAdelante=mapa_pulgarcito[y_+1][x_];
			}
			break;
	}



	if( (ultimaAccionAdelante<=ultimaAccionDerecha || ultimaAccionDerecha<=-1) && (ultimaAccionAdelante<=ultimaAccionIzquierda || ultimaAccionIzquierda<=-1) && ultimaAccionAdelante>-1 && !primer_paso_vuelta && !segundo_paso_vuelta && !primer_paso){
		solution=0;
	}
	else if( (ultimaAccionIzquierda<=ultimaAccionDerecha || ultimaAccionDerecha<=-1) && (ultimaAccionIzquierda<=ultimaAccionAdelante || ultimaAccionAdelante<=-1) && ultimaAccionIzquierda>-1 && !primer_paso_vuelta && !segundo_paso_vuelta && !primer_paso){
		solution=1;
		primer_paso=true;
	}
	else if( (ultimaAccionDerecha<=ultimaAccionIzquierda || ultimaAccionIzquierda<=-1) && (ultimaAccionDerecha<=ultimaAccionAdelante || ultimaAccionAdelante<=-1) && ultimaAccionDerecha>-1 && !primer_paso_vuelta && !segundo_paso_vuelta && !primer_paso){
		solution=2; 
		primer_paso=true;
		
	}
	else if(!primer_paso_vuelta && !segundo_paso_vuelta && !primer_paso && ultimaAccionIzquierda<=-1 && ultimaAccionDerecha<=-1 && ultimaAccionAdelante<=-1){
		solution=-1;
		primer_paso_vuelta=true;
	}
	return solution;
}
void Agent::CapturaFilaColumnaPK(string mensaje, int & fila, int & columna){
	if(mensaje.substr(0,8)=="PK fila:"){
		int pos=mensaje.find('c');
		string valor=mensaje.substr(9,pos-8);
		fila=atoi(valor.c_str());

		int pos2=mensaje.find('.');
		pos=pos+8;
		valor=mensaje.substr(pos,pos-1);
		columna=atoi(valor.c_str());
	}
}

void Agent::PasarMapa(){
	int f1=fila1-fila2;
	int f2=ff1-ff2;
	int c1=columna1-columna2;
	int c2=cc1-cc2;
	char mapaEntorno2[200][200];
	int mapaPulgarcito2[200][200];
	char mapaObjetos2[200][200];
	if(f1==f2){cout<<"bien orientado"<<endl;
		for(int i=0;i<200;i++){
			for(int j=0;j<200;j++){
				mapaEntorno2[i][j]=mapa_entorno_[i][j];
				mapaPulgarcito2[i][j]=mapa_pulgarcito[i][j];
				mapaObjetos2[i][j]=mapa_objetos_[i][j];
			}
		}
		for(int i=0;i<200;i++){
			for(int j=0;j<200;j++){
				mapa_entorno_[i][j]='?';
				mapa_pulgarcito[i][j]=0;
				mapa_objetos_[i][j]='?';
			}
		}
		x_-=cc1-columna1;
		y_-=ff1-fila1;
		for(int i=0;i<100;i++){
			for(int j=0;j<100;j++){
				mapa_entorno_[i][j]=mapaEntorno2[i+ff1-fila1][j+cc1-columna1];
				mapa_objetos_[i][j]=mapaObjetos2[i+ff1-fila1][j+cc1-columna1];
				mapa_pulgarcito[i][j]=mapaPulgarcito2[i+ff1-fila1][j+cc1-columna1];
			}
		}
		for(int i=0;i<100;i++){
			for(int j=0;j<100;j++){
				mapa_solucion_[i][j]=mapa_entorno_[i][j];
			}
		}
	}
	else if(f1==-f2){cout<<"alreves"<<endl;
		for(int i=0;i<200;i++){
			for(int j=0;j<200;j++){
				mapaEntorno2[i][j]=mapa_entorno_[199-i][199-j];
				mapaPulgarcito2[i][j]=mapa_pulgarcito[199-i][199-j];
				mapaObjetos2[i][j]=mapa_objetos_[199-i][199-j];
			}
		}
		for(int i=0;i<200;i++){
			for(int j=0;j<200;j++){
				mapa_entorno_[i][j]='?';
				mapa_pulgarcito[i][j]=0;
				mapa_objetos_[i][j]='?';
			}
		}
		ff2=199-ff2;
		cc2=199-cc2;
		x_=columna2;
		y_=fila2;
		orientacion_=(orientacion_+2)%4;
		for(int i=0;i<100;i++){
			for(int j=0;j<100;j++){
				mapa_entorno_[i][j]=mapaEntorno2[i+ff2-fila2][j+cc2-columna2];
				mapa_objetos_[i][j]=mapaObjetos2[i+ff2-fila2][j+cc2-columna2];
				mapa_pulgarcito[i][j]=mapaPulgarcito2[i+ff2-fila2][j+cc2-columna2];
			}
		}
		for(int i=0;i<100;i++){
			for(int j=0;j<100;j++){
				mapa_solucion_[i][j]=mapa_entorno_[i][j];
			}
		}
	}
	else if(f1==c2){cout<<"oeste\n";
		for(int i=0;i<200;i++){
			for(int j=0;j<200;j++){
				mapaEntorno2[i][j]=mapa_entorno_[199-j][i];
				mapaPulgarcito2[i][j]=mapa_pulgarcito[199-j][i];
				mapaObjetos2[i][j]=mapa_objetos_[199-j][i];
			}
		}
		for(int i=0;i<200;i++){
			for(int j=0;j<200;j++){
				mapa_entorno_[i][j]='?';
				mapa_pulgarcito[i][j]=0;
				mapa_objetos_[i][j]='?';
			}
		}
		swap(cc2,ff2);
		cc2=199-cc2;
		y_=fila2;
		x_=columna2;
		orientacion_=(orientacion_+1)%4;
		for(int i=0;i<100;i++){
			for(int j=0;j<100;j++){
				mapa_entorno_[i][j]=mapaEntorno2[i+ff2-fila2][j+cc2-columna2];
				mapa_objetos_[i][j]=mapaObjetos2[i+ff2-fila2][j+cc2-columna2];
				mapa_pulgarcito[i][j]=mapaPulgarcito2[i+ff2-fila2][j+cc2-columna2];
			}
		}
		for(int i=0;i<100;i++){
			for(int j=0;j<100;j++){
				mapa_solucion_[i][j]=mapa_entorno_[i][j];
			}
		}
	}
	else if(f1==-c2){cout<<"este\n";
		for(int i=0;i<200;i++){
			for(int j=0;j<200;j++){
				mapaEntorno2[i][j]=mapa_entorno_[j][199-i];
				mapaPulgarcito2[i][j]=mapa_pulgarcito[j][199-i];
				mapaObjetos2[i][j]=mapa_objetos_[i][j];
			}
		}
		for(int i=0;i<200;i++){
			for(int j=0;j<200;j++){
				mapa_entorno_[i][j]='?';
				mapa_pulgarcito[i][j]=0;
				mapa_objetos_[i][j]='?';
			}
		}

		swap(ff2,cc2);
		ff2=199-ff2;
		
		y_=fila2;
		x_=columna2;
		orientacion_=(orientacion_+3)%4;
		for(int i=0;i<100;i++){
			for(int j=0;j<100;j++){
				mapa_entorno_[i][j]=mapaEntorno2[i+ff2-fila2][j+cc2-columna2];
				mapa_objetos_[i][j]=mapaObjetos2[i+ff2-fila2][j+cc2-columna2];
				mapa_pulgarcito[i][j]=mapaPulgarcito2[i+ff2-fila2][j+cc2-columna2];
			}
		}
		for(int i=0;i<100;i++){
			for(int j=0;j<100;j++){
				mapa_solucion_[i][j]=mapa_entorno_[i][j];
			}
		}
	}

	else{

		cout << "Ninguna de las anteriores" << endl;

	}


}
//MIS COSAS
bool Agent::MochilaVacia(){
	bool vacia=true;
	for(int i=0;i<5;i++){
		if(MOCHILLA_[i]<='9' && MOCHILLA_[i]>='0'){
			vacia=false;
		}
	}
	return vacia;
}
Agent::ActionType Agent::Think()
{
	int a=UltimaAccion(orientacion_);
	Agent::ActionType accion; // Por defecto avanza
	if(mapa_entorno_[y_][x_]=='K' && !pk1){

		CapturaFilaColumnaPK(MENSAJE_, fila1, columna1);
		pk1=true;
		ff1=y_;
		cc1=x_;
		cout<<fila1<<" "<<columna1<<" "<<y_<<" "<<x_<<endl;
	}
	else if(mapa_entorno_[y_][x_]=='K' && pk1 && !pk2){
		CapturaFilaColumnaPK(MENSAJE_, fila2, columna2);
		if(fila1!=fila2 || columna1!=columna2){
			pk2=true;
			ff2=y_;
			cc2=x_;
			yaActualizado=true;
			cout<<fila2<<" "<<columna2<<" "<<y_<<" "<<x_<<endl;
		}
	}
	if(pk1 && pk2 && yaActualizado){
		actualizado=false;
		yaActualizado=false;
		cout<<"Estamos actualizando el mapa\n";
		PasarMapa();
	}
	
	
	if(cogiendoalgo){
		cogiendoalgo=false;
		segundo_paso_vuelta=false;
		primer_paso=false;
		segundo_paso=false;
		if(!MochilaLlena()){
			accion=actPUSH;
		}
	}	
	else if(  (mapa_objetos_[y_][x_]=='9' || mapa_objetos_[y_][x_]=='8' || mapa_objetos_[y_][x_]=='4' || mapa_objetos_[y_][x_]=='3') && EN_USO_=='-'){
		accion=actPICKUP;
		mapa_objetos_[y_][x_]=='?';
		cogiendoalgo=true;
		segundo_paso_vuelta=false;
		primer_paso=false;
		segundo_paso=false;
	}
	else if(dandocosas){
		accion=actPOP;
		dandocosas=false;
	}
	else if( (SURFACE_[1]=='o' || SURFACE_[1]=='k' || SURFACE_[1]=='m' || SURFACE_[1]=='i' || SURFACE_[1]=='g') && ( (EN_USO_!='-') || (!MochilaVacia()) ) ){
		accion=actGIVE;
		if(MochilaVacia()){
			dandocosas=false;
		}
		else dandocosas=true;
		segundo_paso_vuelta=false;
		primer_paso=false;
		segundo_paso=false;
	
	}
	else if(primer_paso_vuelta && !cogiendoalgo){
		accion=actTURN_L;
		segundo_paso_vuelta=true;
		primer_paso_vuelta=false;
	}
	else if(segundo_paso_vuelta && !cogiendoalgo){
		accion=actTURN_L;
		segundo_paso_vuelta=false;
	}
	else if(segundo_paso && !cogiendoalgo){
		accion=actFORWARD;
		primer_paso=false;
		segundo_paso=false;
	}
	else if(a==0 && !cogiendoalgo){
		accion=actFORWARD;
	}
	else if(a==1 && !cogiendoalgo){
		segundo_paso=true;
		accion=actTURN_L;
	}
	else if(a==2 && !cogiendoalgo){
		segundo_paso=true;
		accion=actTURN_R;
	}
	else{
		accion=actFORWARD;
	}
	last_accion_ = accion;
	ActualizarPulgarcito();
	pasos_dados++;
	cout<<pasos_dados<<endl;

	return accion;

}
