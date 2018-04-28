#include <iostream>
#include <time.h>      // incluye "time"
#include <unistd.h>    // incluye "usleep"
#include <stdlib.h>    // incluye "rand" y "srand"
#include <mpi.h>

using namespace std;

void Filosofo( int id, int nprocesos);
void Tenedor ( int id, int nprocesos);

// ---------------------------------------------------------------------

int main( int argc, char* argv[] )
{
   int rank, size;
   
   srand(time(0));
   MPI_Init( &argc, &argv );
   MPI_Comm_rank( MPI_COMM_WORLD, &rank );
   MPI_Comm_size( MPI_COMM_WORLD, &size );
   
   if( size!=10)
   {
      if( rank == 0) 
         cout<<"El numero de procesos debe ser 10" << endl << flush ;
      MPI_Finalize( ); 
      return 0; 
   }
   
   if ((rank%2) == 0)  
      Filosofo(rank,size); // Los pares son Filosofos 
   else 
      Tenedor( rank,size);  // Los impares son Tenedores 
   
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
      
      cout << "Filosofo " << id << " PENSANDO" << endl << flush;
      
      usleep( 1000U * (100U+(rand()%900U)) );
 }
}
// ---------------------------------------------------------------------

void Tenedor(int id, int nprocesos)
{
  int buf; 
  MPI_Status status; 
  int Filo;
	int flag;
  
  while( true )
  {
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
