#include <iostream>
#include <time.h>      // incluye "time"
#include <unistd.h>    // incluye "usleep"
#include <stdlib.h>    // incluye "rand" y "srand"
#include <mpi.h>

using namespace std;

void Filosofo( int id, int nprocesos);
void Tenedor ( int id, int nprocesos);
void Camarero();

// ---------------------------------------------------------------------

int main( int argc, char* argv[] )
{
   int rank, size;
   
   srand(time(0));
   MPI_Init( &argc, &argv );
   MPI_Comm_rank( MPI_COMM_WORLD, &rank );
   MPI_Comm_size( MPI_COMM_WORLD, &size );
   
   if( size!=11)
   {
      cout<<"El numero de procesos debe ser 11" << endl << flush ;
      MPI_Finalize( ); 
      return 0; 
   }
   
   if ( ((rank%2) == 0) && rank!=10) {
      Filosofo(rank,10); // Los pares son Filosofos
   } 
   else if( (rank%2)!=0){
      Tenedor( rank,10);  // Los impares son Tenedores 
   }
   else{
      Camarero();
   }	   
   MPI_Finalize( );
   return 0;
}  
// ---------------------------------------------------------------------

void Filosofo( int id, int nprocesos )
{
   int izq = (id+1) % nprocesos;
   int der = ((id+nprocesos)-1) % nprocesos; 

   MPI_Status status;
   
   while(1)
   {
	cout << "Filosofo " << id << " PENSANDO" << endl << flush;
        usleep( 1000U * (100U+(rand()%900U)) );

	MPI_Ssend(&id,1,MPI_INT,nprocesos,id,MPI_COMM_WORLD);
	cout<<"El filosofo "<<id<<" se sienta a la mesa"<<endl<<flush;
	if(id==0){
      		MPI_Ssend( &id, 1, MPI_INT, der, id, MPI_COMM_WORLD );
      		cout << "El filosofo " << id << " coge el tenedor de su derecha (" << der << ")." << endl << flush;
		
		MPI_Ssend( &id, 1, MPI_INT, izq, id, MPI_COMM_WORLD );
            	cout << "El filosofo " << id << " coge el tenedor de su izquierda (" << izq << ")." << endl << flush;
	}
	else{
      		MPI_Ssend( &id, 1, MPI_INT, izq, id, MPI_COMM_WORLD );
            	cout << "El filosofo " << id << " coge el tenedor de su izquierda (" << izq << ")." << endl << flush;

      		MPI_Ssend( &id, 1, MPI_INT, der, id, MPI_COMM_WORLD );
            	cout << "El filosofo " << id << " coge el tenedor de su derecha (" << der << ")." << endl << flush;
	}
  
      cout<<"Filosofo "<<id<< " COMIENDO"<<endl<<flush;
      sleep((rand() % 3)+1); 

      MPI_Ssend( &id, 1, MPI_INT, izq, id, MPI_COMM_WORLD );
      cout <<"Filosofo "<<id<< " suelta tenedor izq ..." << izq << endl << flush;
      
      MPI_Ssend( &id, 1, MPI_INT, der, id, MPI_COMM_WORLD );
      cout <<"Filosofo "<<id<< " suelta tenedor der ..." << der << endl << flush;
      cout << "El filosofo " << id << " se levanta de la mesa." << endl << flush;
      MPI_Ssend(&id, 1, MPI_INT, 10, id, MPI_COMM_WORLD);
      
 }
}
// ---------------------------------------------------------------------

void Tenedor(int id, int nprocesos)
{
  int buf; 
  MPI_Status status; 
  int Filo;
	int flag;
  
  while( true ){
    // Espera un peticion desde cualquier filosofo vecino ...
	MPI_Iprobe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &flag, &status);
    
    // Recibe la peticion del filosofo ...
	MPI_Recv(&buf, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
	Filo=status.MPI_SOURCE;
    
    cout << "Ten. " << id << " recibe petic. de " << Filo << endl << flush;
    
    // Espera a que el filosofo suelte el tenedor...
	MPI_Recv(&buf, 1, MPI_INT, Filo, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
    cout << "Ten. " << id << " recibe liberac. de " << Filo << endl << flush; 
  }
}
// ---------------------------------------------------------------------

void Camarero(){
	int buf;
	MPI_Status status;
	int n_filos=0, filo;
	int flag;
	while(true){
		MPI_Iprobe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &flag, &status);
		if(n_filos<4){
			MPI_Recv(&buf,1,MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
			filo=status.MPI_SOURCE;
			cout<<"El camarero recibe una peticion del filosofo "<<filo<<endl<<flush;
			n_filos++;
			MPI_Recv(&buf, 1, MPI_INT,MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD,&status);
			cout<<"El camarero le da permiso al filosofo "<<filo<<" para levantarse de la mesa"<<endl<<flush;
			n_filos--;
		}
		else{
			filo=status.MPI_SOURCE;
			cout<<"El filosofo "<<filo<<" no puede sentarse a la mesa porque esta llena"<<endl<<flush;
		}
	}
}

