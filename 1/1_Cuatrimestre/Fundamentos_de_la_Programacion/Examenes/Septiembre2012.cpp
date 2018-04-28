#include <iostream>
#include <string>

using namespace std;

class Examen{
private:
	static const int maximo=100;
	string VectorEnunciados[maximo];
	char VectorRespuestas[maximo];
	string Asignatura;
	int total;
public:
	Examen(string nombre_asignatura){
		total=0;
		Asignatura=nombre_asignatura;
	}
	void NuevaPregunta(string el_enunciado, char la_respuesta){
		VectorEnunciados[total]=el_enunciado;
		VectorRespuestas[total]=la_respuesta;
		total++;
	}
	int total_preguntas(){
		return total;
	}
	string Enunciado(int indice){
		return VectorEnunciados[indice];
	}
	char Respuesta(int indice){
		return VectorRespuestas[indice];
	}
	string DevuelveAsignatura(){
		return Asignatura;
	}
	void RespuestaAlumno(char respuesta){
		VectorRespuestas[total]=respuesta;
		total++;
	}
	double calcula_nota(Examen res){
		char a, b;
		double nota=0;
		for(int i=0;i<total;i++){
			a=VectorRespuestas[i];
			b=res.Respuesta(i);
			if(a==b){
				nota=nota+1;
			}
			if(a!=b && b!='n'){
				nota=nota-1;
			}
			if(b=='n'){
				nota=nota+0;
			}
		}
		if(nota<0){
			nota=0;
		}
		nota=(nota/total)*10;
		return nota;
	}
};
int main(){
	string frases;
	char a;
	int n;
	
	cout<<"Introduzca el nombre de la asignatura: ";
	getline(cin, frases);
	Examen objeto(frases);
	do{
		cout<<"Introduzca el enunciado de la pregunta: \n";
		getline(cin, frases);
		do{
			cout<<"Introduzca la respuesta correcta (a/b/c/d): ";
			cin>>a;
			if(a=='a' || a=='b' || a=='c' || a=='d'){
				objeto.NuevaPregunta(frases, a);
			}
		}while(a!='a' && a!='b' && a!='c' && a!='d');
		do{
			cout<<"Mas preguntas? ";
			cin>>a;
		}while(a!='s' && a!='S' && a!='n' && a!='N');
		cin.ignore();
	}while(a!='n' && a!='N');
	cout<<"En el examen hay: "<<objeto.total_preguntas()<<" preguntas\n";
	cout<<"Diga el numero de alumnos: ";
	cin>>n;
	for(int i2=0;i2<n;i2++){
		cout<<"Las respuestas del alumno son:\n";
		Examen respuestas_alumno(objeto.DevuelveAsignatura());
		for(int i=0;i<objeto.total_preguntas();i++){
			cout<<objeto.Enunciado(i)<<endl;
			do{
				cin>>a;
				if(a=='a' || a=='b' || a=='c' || a=='d' || a=='n'){
					respuestas_alumno.RespuestaAlumno(a);
				}
			}while(a!='a' && a!='b' && a!='c' && a!='d' && a!='n');
		}
		cout<<"La nota de este alumno es: "<<objeto.calcula_nota(respuestas_alumno)<<endl;;
	}
	system("pause");
}
