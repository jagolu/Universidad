#include <iostream>
#include <cassert>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>      // incluye "time(....)"
#include <unistd.h>    // incluye "usleep(...)"
#include <stdlib.h>    // incluye "rand(...)" y "srand"

// ----------------------------------------------------------------------------
// función que simula la acción de fumar  como un retardo aleatorio de la hebra

using namespace std;

sem_t sem_fumadores[3], sem_terminado[3], mutex;

void fumar() 
{ 
   //  inicializa la semilla aleatoria  (solo la primera vez)
   static bool primera_vez = true ;
   if ( primera_vez )
   {   primera_vez = false ;
      srand( time(NULL) );    
   }
   
   // calcular un numero aleatorio de milisegundos (entre 1/10 y 2 segundos)
   const unsigned miliseg = 100U + (rand() % 1900U) ; 

   // retraso bloqueado durante 'miliseg' milisegundos
   usleep( 1000U*miliseg ); 
}
// ----------------------------------------------------------------------------
static int ingrediente;
void * Estanquero( void *){
   while(true){
      ingrediente=rand() % 3;
      sem_wait(&sem_terminado[ingrediente]);
      sem_wait(&mutex);
      cout<<"Producido ingrediente para fumador "<<ingrediente<<endl;
      sem_post(&mutex);
      sem_post(&sem_fumadores[ingrediente]);
   }
   return NULL;
}
void * Fumador (void * num){
   unsigned long num_fumador= (unsigned long)num;
   while(true){
      sem_wait(&sem_fumadores[num_fumador]);
      sem_wait(&mutex);
      cout<<"Fumador "<<num_fumador<<", fumando\n";
      sem_post(&mutex);
      fumar();
      sem_post(&sem_terminado[num_fumador]);
      
   }
   return NULL;
}



int main()
{
   pthread_t fumador[3], estanco;

   for(int i=0;i<3;i++){
      sem_init(&sem_fumadores[i], 0, 0);
      sem_init(&sem_terminado[i],0,1);
   }
   sem_init(&mutex,0,1);
   pthread_create(&estanco,NULL,Estanquero,NULL);
   for(unsigned long i=0;i<3;i++){
      int i2=i;
      void * num =(void *) i;
      pthread_create(&(fumador[i2]),NULL,Fumador,num);
   }
   for(int i=0;i<3;i++){
      pthread_join(fumador[i],NULL);
   }
   pthread_join(estanco,NULL);

   pthread_exit(NULL);
   
  return 0 ;
}
