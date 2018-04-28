#include <iostream>
#include <cstdlib> // rand, atoi
#include <ctime> // time

using namespace std;

struct Celda {
  int dato;
  Celda *sig;
};

// Genera un valor del intervalo [minimo,maximo]
int Uniforme(int minimo, int maximo)
{
  double u01= std::rand()/(RAND_MAX+1.0); // Uniforme01
  return minimo+(maximo-minimo+1)*u01;
}
// FIXME 1: Añadir un elemento a una lista. Se añade como primer elemento
void Add(Celda*& l,int n){
	Celda *r;
	r=new Celda;
	r->dato=n;
	r->sig=l;
	l=r;
}
// FIXME 2: Liberar todas las celdas de una lista y dejarla a cero
void Liberar(Celda*& l){
	while(l!=0){
		Celda *r;
		r=l->sig;
		delete l;
		l=r;
	}
		
}
// FIXME 3: Listar los elementos de una lista entre llaves y separados por comas
void Listar(Celda* l){
	cout<<"{";
	while(l!=0){
		cout<<l->dato;
		l=l->sig;
		if(l!=0) cout<<",";
	}
	cout<<"}";
}
// FIXME 4: Crear función Size para calcular el número de elemento de la lista
int Size(Celda* l){
	int total=0;
	while(l!=0){
		l=l->sig;
		total++;
	}
	return total;
}
// FIXME 5: Crear una función Buscar que devuelva la celda donde está un dato. Puntero nulo si no está.
Celda *Buscar(Celda* l, const int& n){
	Celda * p=0;
	while(l!=0){
		if(l->dato==n){
			p=l;
		}
		l=l->sig;
	}
	return p;
}
// FIXME 6: Crear una función BuscarPuntero que devuelve un puntero a puntero.
Celda **BuscarPuntero(Celda* l, const int& n){
	int j=0;
	Celda *p;
	p=l;
	for(int i=0;i<Size(l);i++){
		if(p->dato==n) j=i;
		p=p->sig;
	}
	if(l->dato==n) j=-1;
	for(int i=0;i<j;i++){
		l=l->sig;
	}
	Celda **r=0;
	if(j!=0) r=&l;
	return r;
}

// FIXME 7: Recibe un puntero a celda, la desengancha, y la devuelve como resultado
Celda *Descolgar(Celda*& l, Celda*& eliminar);

// Genera un valor del intervalo [minimo,maximo]



// FIXME 2: Crear funciones BuscarMaximo y OrdenarSeleccion
// FIXME 3: Función Mezcla que mezcla dos listas ordenadas en una nueva, dejando las dos originales vacías
// FIXME 4: Función MergeSort para ordenar una lista


int main(int argc, char *argv[])
{
  if (argc!=3) {
    cerr << "Uso: " << argv[0] << " <número de datos> <máximo dato>" <<endl;
    return 1;
  }
  
  srand(time(0)); // Inicializamos generador de números
  
  int n= atoi(argv[1]);
  if (n<5) {
    cerr << "Debería especificar al menos 5 elementos" << endl;
    return 2;
  }
  else {
    int max= atoi(argv[2]);
    if (max<5) {
      cerr << "Debería especificar un max de al menos 5" << endl;
      return 3;
    }
    
    Celda *lista1=0, *lista2=0; // Listas vacías

    for (int i=0;i<n;++i) {
      // Añadimos un elemento al principio de lista1 y otro a lista2
      Add(lista1,Uniforme(1,max));
      Add(lista2,Uniforme(1,max));
    }
    
    cout << "Lista1: ";
    Listar(lista1);
    cout << "Lista2: ";
    Listar(lista2);
    
    
    // FIXME 2: Llamar a ordenar las dos listas y listarlas ordenadas
    // FIXME 4: Ordenar la primera lista con MergeSort

    // FIXME 3: Llamar a mezclar las dos listas y guardar el resultado en la lista1
    
    
    
    
    
    Liberar(lista1);
    Liberar(lista2);
  }  
}
