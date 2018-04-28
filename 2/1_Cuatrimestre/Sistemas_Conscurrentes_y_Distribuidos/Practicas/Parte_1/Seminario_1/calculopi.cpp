// *********************************************************************
// SCD. Ejemplos del seminario 1.
//
// Plantilla para el ejercicio de cálculo de PI
// *********************************************************************

#include <iostream>
#include <pthread.h>
#include "fun_tiempo.h"

using namespace std ;

// ---------------------------------------------------------------------
// constante y variables globales (compartidas entre hebras)

const unsigned long m = long(1024)*long(1024) ;  // número de muestras (un millón)
const unsigned n      = 4 ;                      // número de hebras

double resultado_parcial[n] ; // tabla de sumas parciales (una por hebra)

// ---------------------------------------------------------------------
// implementa función $f$

double f( double x )       
{ 
   return 4.0/(1+x*x) ;     // $~~~~f(x)\,=\,4/(1+x^2)$
}
// ---------------------------------------------------------------------
// cálculo secuencial

double calcular_integral_secuencial( )
{  
   struct timespec inicio= ahora();
   double suma = 0.0 ;                      // inicializar suma
   for( unsigned long i = 0 ; i < m ; i++ ) // para cada $i$ entre $0$ y $m-1$
      suma += f( (i+0.5)/m );               // $~~~~~$ añadir $f(x_i)$ a la suma actual   
   struct timespec fin = ahora();
   cout<<"Tiempo transcurrido de forma secuencial == "<<duracion(&inicio, &fin)<<"seg"<<endl;
   return suma/m ;  
                     // devolver valor promedio de $f$
}
// ---------------------------------------------------------------------
// función que ejecuta cada hebra

void * funcion_hebra( void * ih_void ) 
{  
   unsigned long ih = (unsigned long) ih_void ; // número o índice de esta hebra
   double sumap = 0.0 ;
   // calcular suma parcial en "sumap"
   //.....
   int muestras_a_medir=m/n;
   for(unsigned long i=muestras_a_medir*ih;i<muestras_a_medir*(ih+1);i++){
      sumap += f( (i+0.5)/m ); 
   }
   resultado_parcial[ih] = sumap ; // guardar suma parcial en vector.
   return NULL ;
}
// ---------------------------------------------------------------------
// cálculo concurrente

double calcular_integral_concurrente( )
{  
   // crear y lanzar $n$ hebras, cada una ejecuta "funcion\_concurrente"
   //.....
   struct timespec inicio= ahora();
   pthread_t id_hebra[n];
   for(unsigned long i=0; i<n; i++){
      void * arg_ptr = (void *) i;
      pthread_create( &(id_hebra[i]), NULL, funcion_hebra, arg_ptr);
   }
   // esperar (join) a que termine cada hebra, sumar su resultado
   //.....
   double resultado=0.0;
   for( unsigned i = 0 ; i < n ; i++ ){  
      pthread_join( id_hebra[i], NULL );
      resultado=resultado+resultado_parcial[i];
   }
   // devolver resultado completo
   // .....
   struct timespec fin = ahora();
   cout<<"Tiempo transcurrido de forma concurrente == "<<duracion(&inicio, &fin)<<"seg"<<endl;
   return resultado/m ; // (cambiar)
}

// ---------------------------------------------------------------------

int main()
{
   
   cout << "Ejemplo 4 (cálculo de PI)" << endl ;
   double pi_sec = 0.0, pi_conc = 0.0 ;
   
   pi_sec  = calcular_integral_secuencial() ;
   pi_conc = calcular_integral_concurrente() ;
   
   cout << "valor de PI (calculado secuencialmente)  == " << pi_sec  << endl 
        << "valor de PI (calculado concurrentemente) == " << pi_conc << endl ; 
    
   return 0 ;
}
// ---------------------------------------------------------------------



// ----------------------------------------------------------------------------
