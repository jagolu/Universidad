#include <iostream>
#include <cassert>
#include <pthread.h>
#include <semaphore.h>

using namespace std ;

// ---------------------------------------------------------------------
// constantes 
const unsigned 
  num_items  = 50 ,
  tam_vector = 10 ;              

// ---------------------------------------------------------------------


int v[tam_vector];
int libre=0;
sem_t leer, escribir, mutex;

unsigned producir_dato(){
   static int contador = 0 ;
   cout << "producido: " << contador << endl << flush ;
   return contador++ ;
}
// ---------------------------------------------------------------------

void consumir_dato( int dato ){
   cout << "dato recibido: " << dato << endl ;
}
// ---------------------------------------------------------------------

void * productor( void * ){   
   for( unsigned i = 0 ; i < num_items ; i++ ){
      sem_wait(&escribir); 
      sem_wait(&mutex); 
      int dato = producir_dato() ;
      sem_post(&mutex);
      v[libre]=dato;
      libre++;
      sem_post(&leer);
  }
  return NULL ;
}
// ---------------------------------------------------------------------

void * consumidor( void * ){   
   for( unsigned i = 0 ; i < num_items ; i++ ){   
      int dato;    
      sem_wait(&leer);
        libre--;
        dato=v[libre];
        sem_wait(&mutex);
        consumir_dato( dato );
        sem_post(&mutex);
      sem_post(&escribir);
   }
  return NULL ;
}
//----------------------------------------------------------------------

int main()
{
   
  // falta: crear y poner en marcha las hebras, esperar que terminen
  // ....
   pthread_t hebra_productor, hebra_consumidor;

   sem_init(&escribir, 0, tam_vector );
   sem_init(&leer, 0, 0 );
   sem_init(&mutex, 0 ,1);

   pthread_create(&hebra_productor,NULL,productor,NULL);
   pthread_create(&hebra_consumidor,NULL,consumidor,NULL);

   pthread_join(hebra_productor,NULL);
   pthread_join(hebra_consumidor,NULL);

   pthread_exit(NULL); 

   return 0 ; 
}
