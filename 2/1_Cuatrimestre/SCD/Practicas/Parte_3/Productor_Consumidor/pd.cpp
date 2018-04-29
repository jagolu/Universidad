#include <mpi.h>
#include <iostream>
#include <math.h>
#include <time.h>     
#include <unistd.h>    
#include <stdlib.h>   

#define TAM 5
using namespace std;

// ---------------------------------------------------------------------

void productor(int rank){
   int value ;  
   
   for ( unsigned int i=0; i < 20 ; i++ ){ 
      value = i ;
      cout << "Productor "<<rank<<" produce valor " << value << endl << flush ;

      usleep( 1000U * (100U+(rand()%900U)) );

      MPI_Ssend( &value, 1, MPI_INT, 5, 0, MPI_COMM_WORLD );
   }
}
// ---------------------------------------------------------------------

void buffer(){
   int value[TAM], peticion, pos=0, rama;
   MPI_Status status;
   
   for( unsigned int i=0 ; i < 80 ; i++ ){  
      if ( pos==0 ){
         rama=0;
      }        
      else if(pos==TAM){
         rama=1;
      }           
      else{
         MPI_Probe( MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status );

         if ( status.MPI_SOURCE <= 4 ){
            rama=0;
	 } 
         else{ 
            rama=1;
	 }
      }
      switch(rama){
         case 0:
            MPI_Recv( &value[pos], 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status );
            cout << "Buffer recibe " << value[pos] << " de Productor "<<status.MPI_SOURCE << endl << flush;  
            pos++;
            break;
         case 1:
            MPI_Recv( &peticion, 1, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &status );
            MPI_Ssend( &value[pos-1], 1, MPI_INT, status.MPI_SOURCE, 0, MPI_COMM_WORLD);
            cout << "Buffer envía " << value[pos-1] << " a Consumidor "<<status.MPI_TAG << endl << flush;  
            pos--;
            break;
      }     
   }
}   
   
// ---------------------------------------------------------------------

void consumidor(int rank){
   int value, peticion=1; 
   float raiz ;
   MPI_Status status ;
 
   for (unsigned int i=0;i<20;i++){
      MPI_Ssend( &peticion, 1, MPI_INT, 5, 1, MPI_COMM_WORLD ); 
      MPI_Recv ( &value, 1,    MPI_INT, 5, 0, MPI_COMM_WORLD,&status );
      cout << "Consumidor "<<rank <<"recibe valor " << value << " de Buffer " << endl << flush ;

      usleep( 1000U * (100U+(rand()%900U)) );
      
      raiz = sqrt(value) ;
   }
}
// ---------------------------------------------------------------------

int main(int argc, char *argv[]) 
{
   int rank,size; 

   MPI_Init( &argc, &argv );
   MPI_Comm_rank( MPI_COMM_WORLD, &rank );
   MPI_Comm_size( MPI_COMM_WORLD, &size );

   srand ( time(NULL) );

   if ( size != 10 ){
      cout<< "El numero de procesos debe ser 10 "<<endl;
      return 0;
   } 

   if ( rank == 0 || rank==1 || rank==2 || rank==3 || rank==4 ) 
      productor(rank);
   else if ( rank == 5 ) 
      buffer();
   else 
      consumidor(rank);

   MPI_Finalize( );
   return 0;
}

