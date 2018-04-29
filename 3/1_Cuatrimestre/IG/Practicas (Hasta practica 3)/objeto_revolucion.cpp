#include "objeto_revolucion.h"
#include <cmath>

objeto_revolucion::objeto_revolucion(){}

objeto_revolucion::objeto_revolucion(vector<_vertex3f> datov, int veces){
	generarFigura(datov, veces);
}

void objeto_revolucion::generarFigura(vector<_vertex3f> datov, int veces){
	int k;
	
	bool tapa_inf=false;
	bool tapa_sup=false;
	
	_vertex3f primero;
	_vertex3f segundo;

	if(datov.front().x==0){
		primero=datov.front();
		datov.erase(datov.begin());
		tapa_inf=true;
	}
	
	if(datov.back().x==0){
		segundo=datov.back();
		datov.pop_back();
		tapa_sup=true;
	}

	k=datov.size();
	
	OB3D::edges=datov;

	OB3D::edges.resize(k*(veces+1));
	
	double rotacion=(2*M_PI)/veces;

	for(int j=0;j<veces;j++){
		datov[0]=RotarY(datov[0], rotacion);
		OB3D::edges[k]=datov[0];
		k++;
		for(int t=1;t<datov.size();++t){
			datov[t]=RotarY(datov[t], rotacion);
			OB3D::edges[k]=datov[t];
			k++;
			O3D::triangles.push_back(_vertex3ui(k,k-datov.size(),k-1));
			O3D::triangles.push_back(_vertex3ui(k-datov.size(),k-datov.size()-1,k-1));
		}
	}

	
	
	if(tapa_inf){
		int contador=0;
		OB3D::edges.push_back(primero);
		for(int i=0;i<OB3D::edges.size()-1;i++){
			_vertex3ui v;
			v._0=contador;
			v._1=contador+datov.size();
			v._2=OB3D::edges.size()-1;
			O3D::triangles.push_back(v);
			contador+=datov.size();
		}
	}

	if(tapa_sup){
		int contador=datov.size()-1;
		OB3D::edges.push_back(segundo);
		for(int i=0;i<OB3D::edges.size()-1;i++){
			_vertex3ui v;
			v._0=contador;
			v._1=contador+datov.size();
			v._2=OB3D::edges.size()-1;
			contador+=datov.size();
			O3D::triangles.push_back(v);
		}
	}
}

_vertex3f objeto_revolucion::RotarY(_vertex3f p, double rotacion){
	_vertex3f rotada;
	rotada.x=cos(rotacion)*p.x+sin(rotacion)*p.z;
	rotada.y=p.y;
	rotada.z=-sin(rotacion)*p.x+cos(rotacion)*p.z;
	return rotada;
}
















/*
_vertex3f objeto_revolucion::rotarPunto(_vertex3f punto, float nrotacion){
	_vertex3f nuevo_punto;
	nuevo_punto.x=cos(nrotacion)*punto.x+sin(nrotacion)*punto.z;
	nuevo_punto.y=punto.y;
	nuevo_punto.z=-sin(nrotacion)*punto.x+cos(nrotacion)*punto.z;
	return nuevo_punto;
}
objeto_revolucion::objeto_revolucion(){}
objeto_revolucion::objeto_revolucion(vector<_vertex3f> puntos, int veces):O3D(vector<_vertex3ui> (), vector<_vertex3f>()){
	vector<_vertex3f>Edges2;
	vector<_vertex3ui>Triangles2;
	int mov;
	float rotation=(2*3.14159)/veces;
	bool hayinf=false, haysup=false;
	_vertex3f inf, sup;

    	if(puntos[0].x==0){
		inf=puntos.front();
		puntos.erase(puntos.begin());
		hayinf=true;
	}

	if(puntos[puntos.size()-1].x==0){
		sup=puntos.back();
		puntos.pop_back();
		haysup=true;
	}

	Edges2=puntos;
	mov=puntos.size();
	Edges2.resize((mov*(veces+1))-2);
	for(int i=0;i<veces-1;i++){
		puntos[0]=rotarPunto(puntos[0],rotation);
		Edges2[mov]=puntos[0];
		mov++;
		for(int j=1;j<puntos.size();j++){
			puntos[j]=rotarPunto(puntos[j],rotation);
			Edges2[mov]=puntos[j];
			mov++;
		}
	}
	for(int i=2;i<Edges2.size();i++){
		_vertex3ui tt;
		tt._0=i-2;
		tt._1=i-1;
		tt._2=i;
		Triangles2.push_back(tt); 
	}
	Triangles2.push_back(_vertex3ui(Edges2.size()-1, 0, 1));
	Triangles2.push_back(_vertex3ui(Edges2.size()-2, Edges2.size()-1, 0));


	if(hayinf){
		Edges2.push_back(inf);
		for(int i=1;i<(Edges2.size()-2);i=i+2){
			_vertex3ui vv;
			vv._0=i;
			vv._1=i+2;
			vv._2=Edges2.size()-1;
			Triangles2.push_back(vv);
		}
		Triangles2.push_back(_vertex3ui(Edges2.size()-1, Edges2.size()-2, 1));
	}

	if(haysup){
		Edges2.push_back(sup);
		for(int i=0;i<Edges2.size()-4;i=i+2){
			_vertex3ui vv;
			vv._0=i;
			vv._1=i+2;
			vv._2=Edges2.size()-1;
			Triangles2.push_back(vv);
		}
		int octV;
		if( (Edges2.size()-4)%2==0 && veces%2==1 ) octV=4;
		else if(  (Edges2.size()-4)%2==1 && (veces%2==1)  )octV=3;
		else if(  (Edges2.size()-4)%2==0 && (veces%2==0)  )octV=4;
		else if(  (Edges2.size()-4)%2==1 && (veces%2==0)  )octV=3;
		Triangles2.push_back(_vertex3ui(0, Edges2.size()-octV, Edges2.size()-1));
	}
	OB3D:edges=Edges2;
	O3D:triangles=Triangles2;
}*/
